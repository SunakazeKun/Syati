#include "sample/GstRecord.h"
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
        mUpdateFrame = 0;
        mRecorderMode = GstRecorderMode_Waiting;
        mCurrentStageName = NULL;
        mGhostDataIndex = -1;
        mGhostDataType = GhostType_Invalid;
        GhostPacketSyncData(mGhostDataStruct);
    }

    GstRecorderInfo(GstRecorderInfo::sInstance);

    // ----------------------------------------------------------------------------------------------------------------

    bool isEnableDebugGstRecorder() {
        return true;
    }

    // ----------------------------------------------------------------------------------------------------------------

    GstRecorderMode getGstRecorderMode() {
        return GstRecorderInfo::sInstance.mRecorderMode;
    }

    void setGstRecorderMode(GstRecorderMode recorderMode) {
        GstRecorderInfo::sInstance.mRecorderMode = recorderMode;
    }

    void resetGstRecorder() {
        GstRecorderInfo::sInstance.mRecorderMode = GstRecorderMode_Waiting;
    }

    // ----------------------------------------------------------------------------------------------------------------

    void resetGhostDataFrame() {
        GstRecorderInfo::sInstance.mUpdateFrame = 0;
        GhostPacketSyncData(GstRecorderInfo::sInstance.mGhostDataStruct);
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

        initNerve(NrvGstRecordHelperWait, 0);
        makeActorAppeared();
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

            GstRecorderInfo::sInstance.mCurrentStageName = MR::getCurrentStageName();
            GstRecorderInfo::sInstance.mGhostDataIndex = MR::getCurrentSelectedScenarioNo();
            GstRecorderInfo::sInstance.mGhostDataType = getGhostType();
            resetGhostDataFrame();
            setGstRecorderMode(GstRecorderMode_Preparing);
        }

        if (MR::isStep(this, 60)) {
            setNerve(NrvGstRecordHelperRecording);
        }
    }

    void GstRecordHelper::exeRecording() {
        if (MR::isFirstStep(this)) {
            MR::onPlayerControl(true);
            setGstRecorderMode(GstRecorderMode_Recording);
        }

        supplyGstFrame();
        GstRecorderInfo::sInstance.mUpdateFrame++;

        if (MR::testCorePadTrigger2(0)) {
            setGstRecorderMode(GstRecorderMode_Stopped);
            handleStopped();
            makeActorDead();
        }
    }

    void GstRecordHelper::handlePrepare() {

    }

    void GstRecordHelper::handleStopped() {

    }

    void GstRecordHelper::supplyGstFrame() const {
        GstRecorderInfo::sInstance.mGhostDataStruct.syncWithActor(this, true);
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
        GstRecorderInfo::sInstance.mGhostDataStruct.syncWithPlayer();
    }

    void GhostLuigiRecordHelper::initModelAndScene(const JMapInfoIter &rIter) {
        initModelManagerWithAnm("GhostAttackGhost", NULL, NULL, false);
        MR::connectToSceneIndirectNpc(this);
    }

    void GhostLuigiRecordHelper::handlePrepare() {
        MarioAccess::setBaseMtx(*getBaseMtx());
        MarioAccess::setStateWait();
        MR::startBckPlayer("Wait", NULL);

        MR::hideModel(this);
    }
}
