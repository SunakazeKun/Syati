#include "sample/PadRecord.h"

/*
* Please refer to the respective header file for more information about how to use this!!!
*/

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
        return GameSequenceFunction::isPadMode2() || pad::getPadRecorderMode() != pad::PadRecorderMode_Waiting;
    }

    // ----------------------------------------------------------------------------------------------------------------

    PadRecorderMode getPadRecorderMode() {
        return PadRecorderInfo::sInstance.mRecorderMode;
    }

    void setPadRecorderMode(PadRecorderMode recorderMode) {
        PadRecorderInfo::sInstance.mRecorderMode = recorderMode;
    }

    void resetPadRecorderNotPrepared() {
        if (PadRecorderInfo::sInstance.mRecorderMode != PadRecorderMode_Preparing) {
            PadRecorderInfo::sInstance.mRecorderMode = PadRecorderMode_Waiting;
        }
    }

    void startPadRecorderPrepared() {
        if (PadRecorderInfo::sInstance.mRecorderMode == PadRecorderMode_Preparing) {
            PadRecorderInfo::sInstance.mRecorderMode = PadRecorderMode_Recording;
        }
    }

    // ----------------------------------------------------------------------------------------------------------------

    JMapIdInfo& getCurrentRestartId() {
        return PadRecorderInfo::sInstance.mCurrentRestartId;
    }

    void updateFrame() {
        PadRecorderInfo::sInstance.mUpdateFrame++;
    }

    void supplyCurrentGameData() {
        register u8* backupGameData;
        u32 backupGameDataSize = SaveDataHandler::getEnoughtTempBufferSize();
        register SaveDataHandleSequence* saveSequence = GameSequenceFunction::getSaveDataHandleSequence();

        saveSequence->backupCurrentGameData();
        __asm {
            lwz backupGameData, 0x3C(saveSequence);
        }

        PadRecorderInfo::sInstance.mBackupGameData = backupGameData;
        PadRecorderInfo::sInstance.mBackupGameDataSize = backupGameDataSize;
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
        PadRecorderMode recorderMode = getPadRecorderMode();

        if (recorderMode == PadRecorderMode_Preparing && getCurrentRestartId() == mRestartId) {
            setNerve(NrvPadRecordHelperRecording);
            makeActorAppeared();
        }
        else if (recorderMode == PadRecorderMode_Waiting) {
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

            PadRecorderInfo::sInstance.mCurrentStageName = MR::getCurrentStageName();
            PadRecorderInfo::sInstance.mCurrentRestartId = mRestartId;
            supplyCurrentGameData();
            setPadRecorderMode(PadRecorderMode_Preparing);
        }

        if (MR::isStep(this, 2)) {
            GameSequenceFunction::getGameSequenceInGame()->getPlayResultInStageHolder()->_74 = false;
            GameSequenceFunction::closeWipeCircleAndPrepareDreamer(this, mRestartId.mId);
        }
    }

    void PadRecordHelper::exeRecording() {
        if (MR::testCorePadTrigger2(0)) {
            setPadRecorderMode(PadRecorderMode_Stopped);
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

    // Dreamer and SuperDreamer shouldn't appear while recording
    kmCall(0x80348E80, pad::isDisableDreamerByPadRecord); // check by Dreamer
    kmCall(0x803618B0, pad::isDisableDreamerByPadRecord); // check by SuperDreamer

    // Attempt to start recorder at the end of GameScene::start
    kmBranch(0x80451888, pad::startPadRecorderPrepared);

#if defined(TWN) || defined(KOR)
    // Registers WPadReadDataInfo after WPadHolder::ctor
    kmBranch(0x804CF8C0, registerWPadReadDataInfo);

    // Updates frame after calling WPadHolder::update
    kmBranch(0x804CFB3C, pad::updateFrame);

    // Reset recorder when destroying scene
    kmBranch(0x804BABA0, pad::resetPadRecorderNotPrepared);
#else
    // Registers WPadReadDataInfo after WPadHolder::ctor
    kmBranch(0x804CF830, registerWPadReadDataInfo);

    // Updates frame after calling WPadHolder::update
    kmBranch(0x804CFAAC, pad::updateFrame);

    // Reset recorder when destroying scene
    kmBranch(0x804BAB30, pad::resetPadRecorderNotPrepared);
#endif
}
