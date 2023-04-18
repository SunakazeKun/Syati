#include "sample/PadRecord.h"
#include "Game/System/GameSequenceInGame.h"
#include "Game/System/PlayResultInStageHolder.h"
#include "Game/System/AllData/GameSequenceFunction.h"
#include "Game/System/AllData/SaveDataHandler.h"
#include "Game/System/AllData/SaveDataHandleSequence.h"
#include "Game/Util.h"
#include "kamek/hooks.h"

/*
* Please refer to the respective header file for more information about how to use this!!!
*/

// This is the address from which galaxypad retrieves the pointer to PadRecorderInfo
#define ADDR_PAD_RECORDER_INFO_PTR (0x80003FFC)

namespace pad {
    static PadRecorderInfo** sPtrForScript = (PadRecorderInfo**)ADDR_PAD_RECORDER_INFO_PTR;

    PadRecorderInfo::PadRecorderInfo() {
        *sPtrForScript = this;
        mUpdateFrame = 0;
        mReadDataInfo = NULL;
        mRecorderMode = PadRecorderMode_Waiting;
        mCurrentStageName = NULL;
        mCurrentRestartId.mId = 0;
        mCurrentRestartId.mZoneId = 0;
        mBackupGameData = NULL;
        mBackupGameDataSize = 0;
    }

    PadRecorderInfo(PadRecorderInfo::sInstance);

    // ----------------------------------------------------------------------------------------------------------------

    bool isEnableDebugPadRecorder() {
        return true;
    }

    bool isDisableDreamerByPadRecord() {
        return GameSequenceFunction::isPadMode2() || PadRecorderInfo::sInstance.mRecorderMode != PadRecorderMode_Waiting;
    }

    bool isEnablePadRecorderAnytime() {
        return PadRecorderInfo::sInstance.mRecorderMode == PadRecorderMode_Waiting;
    }

    bool isEnablePadRecorderForSpawn(const JMapIdInfo &spawnId) {
        return PadRecorderInfo::sInstance.mRecorderMode == PadRecorderMode_Preparing
            && PadRecorderInfo::sInstance.mCurrentRestartId == spawnId;
    }

    void waitPadRecorderNotPrepared() {
        if (PadRecorderInfo::sInstance.mRecorderMode != PadRecorderMode_Preparing) {
            PadRecorderInfo::sInstance.mRecorderMode = PadRecorderMode_Waiting;
        }
    }

    void preparePadRecorder(const char *stageName, const JMapIdInfo &spawnId) {
        PadRecorderInfo::sInstance.mCurrentStageName = stageName;
        PadRecorderInfo::sInstance.mCurrentRestartId = spawnId;

        register u8* backupGameData;
        u32 backupGameDataSize = SaveDataHandler::getEnoughtTempBufferSize();
        register SaveDataHandleSequence* saveSequence = GameSequenceFunction::getSaveDataHandleSequence();

        saveSequence->backupCurrentGameData();
        __asm {
            lwz backupGameData, 0x3C(saveSequence);
        }

        PadRecorderInfo::sInstance.mBackupGameData = backupGameData;
        PadRecorderInfo::sInstance.mBackupGameDataSize = backupGameDataSize;

        PadRecorderInfo::sInstance.mRecorderMode = PadRecorderMode_Preparing;
    }

    void startPadRecorderPrepared() {
        if (PadRecorderInfo::sInstance.mRecorderMode == PadRecorderMode_Preparing) {
            PadRecorderInfo::sInstance.mRecorderMode = PadRecorderMode_Recording;
        }
    }

    void stopPadRecorder() {
        PadRecorderInfo::sInstance.mRecorderMode = PadRecorderMode_Stopped;
    }

    void updateFrame() {
        PadRecorderInfo::sInstance.mUpdateFrame++;
    }

    // ----------------------------------------------------------------------------------------------------------------

    PadRecordHelper::PadRecordHelper(const char *pName) : LiveActor(pName) {
        mRestartId.mId = 0;
        mRestartId.mZoneId = 0;
        mIconAButton = NULL;
        mShowIconAButton = false;
    }

    void PadRecordHelper::init(const JMapInfoIter &rIter) {
        MR::initDefaultPos(this, rIter);
        MR::connectToSceneNpcMovement(this);
        MR::invalidateClipping(this);
        initNerve(NrvPadRecordHelperWait, 0);

        // Sensor used to activate IconAButton
        initHitSensor(1);
        MR::addHitSensorMapObjSimple(this, "Body", 8, 150.0f, TVec3f(0.0f, 0.0f, 0.0f));

        mIconAButton = new IconAButton(true, false);
        mIconAButton->initWithoutIter();

        // Obj_arg0 specifies the spawn point for the playback sequence
        MR::getJMapInfoArg0NoInit(rIter, &mRestartId.mId);
        mRestartId.mZoneId = mLinkedInfo.mZoneId;

        // Initialize state and appearance
        if (isEnablePadRecorderForSpawn(mRestartId)) {
            setNerve(NrvPadRecordHelperRecording);
            makeActorAppeared();
        }
        else if (isEnablePadRecorderAnytime()) {
            makeActorAppeared();
        }
        else {
            makeActorDead();
        }
    }

    void PadRecordHelper::makeActorAppeared() {
        if (isEnableDebugPadRecorder() && !GameSequenceFunction::isPadMode()) {
            LiveActor::makeActorAppeared();
        }
        else {
            LiveActor::makeActorDead();
        }
    }

    void PadRecordHelper::control() {
        mShowIconAButton = false;
    }

    void PadRecordHelper::attackSensor(HitSensor *pSender, HitSensor *pReceiver) {
        if (MR::isSensorPlayer(pReceiver) && MR::isOnGroundPlayer()) {
            mShowIconAButton = true;
        }
    }

    void PadRecordHelper::exeWait() {
        if (mShowIconAButton) {
            if (!mIconAButton->isOpen()) {
                mIconAButton->openWithRead();
            }
        }
        else if (mIconAButton->isOpen()) {
            mIconAButton->term();
        }

        if (mShowIconAButton && mIconAButton->isOpen() && MR::testCorePadTriggerA(0)) {
            setNerve(NrvPadRecordHelperPreparing);
        }
    }

    void PadRecordHelper::exePreparing() {
        if (MR::isFirstStep(this)) {
            mIconAButton->term();

            MR::offPlayerControl();

            preparePadRecorder(MR::getCurrentStageName(), mRestartId);
        }

        if (MR::isStep(this, 2)) {
            GameSequenceFunction::getGameSequenceInGame()->getPlayResultInStageHolder()->_74 = false;
            GameSequenceFunction::closeWipeCircleAndPrepareDreamer(this, mRestartId.mId);
        }
    }

    void PadRecordHelper::exeRecording() {
        if (MR::testCorePadTrigger2(0)) {
            stopPadRecorder();
            makeActorDead();
        }
    }

    namespace NrvPadRecordHelper {
        void NrvWait::execute(Spine *pSpine) const {
            PadRecordHelper* pHost = (PadRecordHelper*)pSpine->mExecutor;
            pHost->exeWait();
        }

        void NrvPreparing::execute(Spine *pSpine) const {
            PadRecordHelper* pHost = (PadRecordHelper*)pSpine->mExecutor;
            pHost->exePreparing();
        }

        void NrvRecording::execute(Spine *pSpine) const {
            PadRecordHelper* pHost = (PadRecordHelper*)pSpine->mExecutor;
            pHost->exeRecording();
        }

        NrvWait(NrvWait::sInstance);
        NrvPreparing(NrvPreparing::sInstance);
        NrvRecording(NrvRecording::sInstance);
    }
}

namespace {
    WPadHolder* registerWPadReadDataInfo(register WPadHolder *wpadHolder) {
        register WPadReadDataInfo* readDataInfo;
        __asm {
            lwz readDataInfo, 0xC(wpadHolder);
        }

        pad::PadRecorderInfo::sInstance.mReadDataInfo = readDataInfo;
        return wpadHolder;
    }

    // Dreamer, SuperDreamer and GhostAttackGhost shouldn't appear while recording
    kmCall(0x80348E80, pad::isDisableDreamerByPadRecord); // check by Dreamer
    kmCall(0x803618B0, pad::isDisableDreamerByPadRecord); // check by SuperDreamer

#if defined(PAL) || defined(USA) || defined(JPN)
    kmCall(0x804D805C, pad::isDisableDreamerByPadRecord); // check by GhostAttackGhost
#elif defined(TWN) || defined(KOR)
    kmCall(0x804D80EC, pad::isDisableDreamerByPadRecord);
#endif

#if defined(PAL) || defined(USA) || defined(JPN)
    // Registers WPadReadDataInfo after WPadHolder::ctor
    kmBranch(0x804CF830, registerWPadReadDataInfo);

    // Updates frame after calling WPadHolder::update
    kmBranch(0x804CFAAC, pad::updateFrame);
#elif defined(TWN) || defined(KOR)
    kmBranch(0x804CF8C0, registerWPadReadDataInfo);

    kmBranch(0x804CFB3C, pad::updateFrame);
#endif
}
