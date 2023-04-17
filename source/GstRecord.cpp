#include "sample/GstRecord.h"
#include "Game/NameObj/NameObjCategories.h"
#include "Game/System/AllData/GameSequenceFunction.h"
#include "Game/Player/MarioAccess.h"
#include "Game/Util.h"
#include "kamek/hooks.h"

/*
* Please refer to the respective header file for more information about how to use this!!!
*/

// This is the address from which galaxygst retrieves the pointer to GstRecorderInfo
#define ADDR_GST_RECORDER_INFO_PTR (0x80003FF8)

namespace gst {
    static GstRecorderInfo** sPtrForScript = (GstRecorderInfo**)ADDR_GST_RECORDER_INFO_PTR;

    GstRecorderInfo::GstRecorderInfo() {
        *sPtrForScript = this;
        mIsSMG2 = true;
        mRecorderMode = GstRecorderMode_Waiting;
        mCurrentStageName = NULL;
        mCurrentStageScenario = -1;
        mGhostDataType = GhostType_Invalid;
        mUpdateFrame = 0;
        GhostPacketSyncData(mGhostDataStruct);
    }

    GstRecorderInfo(GstRecorderInfo::sInstance);

    // ----------------------------------------------------------------------------------------------------------------

    bool isEnableDebugGstRecorder() {
        return true;
    }

    void waitGstRecorder() {
        GstRecorderInfo::sInstance.mRecorderMode = GstRecorderMode_Waiting;
    }

    void prepareGstRecorder(const char *stageName, s32 scenarioId, GhostType ghostType) {
        GstRecorderInfo::sInstance.mCurrentStageName = stageName;
        GstRecorderInfo::sInstance.mCurrentStageScenario = scenarioId;
        GstRecorderInfo::sInstance.mGhostDataType = ghostType;
        GstRecorderInfo::sInstance.mUpdateFrame = 0;
        GhostPacketSyncData(mGhostDataStruct);

        GstRecorderInfo::sInstance.mRecorderMode = GstRecorderMode_Preparing;
    }

    void startGstRecorder() {
        GstRecorderInfo::sInstance.mRecorderMode = GstRecorderMode_Recording;
    }

    void stopGstRecorder() {
        GstRecorderInfo::sInstance.mRecorderMode = GstRecorderMode_Stopped;
    }

    void supplyGstFrameSyncWithActor(const LiveActor *actor, bool syncAnims) {
        GstRecorderInfo::sInstance.mGhostDataStruct.syncWithActor(actor, syncAnims);
        GstRecorderInfo::sInstance.mUpdateFrame++;
    }

    void supplyGstFrameSyncWithPlayer() {
        GstRecorderInfo::sInstance.mGhostDataStruct.syncWithPlayer();
        GstRecorderInfo::sInstance.mUpdateFrame++;
    }

    // ----------------------------------------------------------------------------------------------------------------

    GstRecordHelper::GstRecordHelper(const char *pName) : LiveActor(pName) {
        mIconAButton = NULL;
        mShowIconAButton = false;
    }

    void GstRecordHelper::init(const JMapInfoIter &rIter) {
        MR::initDefaultPos(this, rIter);
        initModelAndScene(rIter);

        // Sensor used to activate IconAButton
        initHitSensor(1);
        MR::addHitSensorMapObjSimple(this, "Body", 8, 150.0f, TVec3f(0.0f, 0.0f, 0.0f));

        mIconAButton = new IconAButton(true, false);
        mIconAButton->initWithoutIter();

        initNerve(NrvGstRecordHelperWait, getStateCount());
        makeActorAppeared();
    }

    void GstRecordHelper::initModelAndScene(const JMapInfoIter &rIter) {
        MR::connectToSceneNpcMovement(this);
    }

    s32 GstRecordHelper::getStateCount() const {
        return 0;
    }

    void GstRecordHelper::makeActorAppeared() {
        if (isEnableDebugGstRecorder() && !GameSequenceFunction::isPadMode()) {
            LiveActor::makeActorAppeared();
        }
        else {
            LiveActor::makeActorDead();
        }
    }

    void GstRecordHelper::control() {
        mShowIconAButton = false;
    }

    void GstRecordHelper::attackSensor(HitSensor *pSender, HitSensor *pReceiver) {
        if (MR::isSensorPlayer(pReceiver) && MR::isOnGroundPlayer()) {
            mShowIconAButton = true;
        }
    }

    void GstRecordHelper::exeWait() {
        if (mShowIconAButton) {
            if (!mIconAButton->isOpen()) {
                mIconAButton->openWithRead();
            }
        }
        else if (mIconAButton->isOpen()) {
            mIconAButton->term();
        }

        if (mShowIconAButton && mIconAButton->isOpen() && MR::testCorePadTriggerA(0)) {
            setNerve(NrvGstRecordHelperPreparing);
        }
    }

    void GstRecordHelper::exePreparing() {
        if (MR::isFirstStep(this)) {
            mIconAButton->term();

            MR::invalidateHitSensors(this);
            MR::invalidateClipping(this);
            MR::offPlayerControl();
            handlePrepare();

            prepareGstRecorder(MR::getCurrentStageName(), MR::getCurrentSelectedScenarioNo(), getGhostType());
        }

        if (MR::isStep(this, 60)) {
            setNerve(NrvGstRecordHelperRecording);
        }
    }

    void GstRecordHelper::exeRecording() {
        if (MR::isFirstStep(this)) {
            MR::onPlayerControl(true);
            startGstRecorder();
        }

        supplyGstFrame();

        if (MR::testCorePadTrigger2(0)) {
            stopGstRecorder();
            handleStopped();
            makeActorDead();
        }
    }

    void GstRecordHelper::handlePrepare() {

    }

    void GstRecordHelper::handleStopped() {

    }

    void GstRecordHelper::supplyGstFrame() const {
        supplyGstFrameSyncWithActor(this, true);
    }

    namespace NrvGstRecordHelper {
        void NrvWait::execute(Spine *pSpine) const {
            GstRecordHelper* pHost = (GstRecordHelper*)pSpine->mExecutor;
            pHost->exeWait();
        }

        void NrvPreparing::execute(Spine *pSpine) const {
            GstRecordHelper* pHost = (GstRecordHelper*)pSpine->mExecutor;
            pHost->exePreparing();
        }

        void NrvRecording::execute(Spine *pSpine) const {
            GstRecordHelper* pHost = (GstRecordHelper*)pSpine->mExecutor;
            pHost->exeRecording();
        }

        NrvWait(NrvWait::sInstance);
        NrvPreparing(NrvPreparing::sInstance);
        NrvRecording(NrvRecording::sInstance);
    }

    // ----------------------------------------------------------------------------------------------------------------

    GhostLuigiRecordHelper::GhostLuigiRecordHelper(const char *pName) : GstRecordHelper(pName) {

    }

    GhostType GhostLuigiRecordHelper::getGhostType() const {
        return GhostType_GhostAttackGhost;
    }

    void GhostLuigiRecordHelper::supplyGstFrame() const {
        supplyGstFrameSyncWithPlayer();
    }

    void GhostLuigiRecordHelper::initModelAndScene(const JMapInfoIter &rIter) {
        initModelManagerWithAnm("GhostAttackGhost", NULL, NULL, false);
        MR::connectToScene(this, MR::MovementType_Npc, MR::CategoryList_Null, MR::DrawBufferType_IndirectNpc, MR::CategoryList_Null);
    }

    void GhostLuigiRecordHelper::handlePrepare() {
        MarioAccess::setBaseMtx(*getBaseMtx());
        MarioAccess::setStateWait();
        MR::startBckPlayer("Wait", NULL);
        MR::hideModel(this);
    }
}
