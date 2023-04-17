#pragma once

/*
* Author: Aurum
*/

#include "Game/LiveActor/LiveActor.h"
#include "Game/Screen/IconAButton.h"
#include "Game/Player/GhostPacketSyncData.h"

namespace gst {
    enum GstRecorderMode {
        GstRecorderMode_Waiting = 0,
        GstRecorderMode_Preparing = 1,
        GstRecorderMode_Recording = 2,
        GstRecorderMode_Stopped = 3
    };

    enum GhostType {
        GhostType_GhostAttackGhost = 0,
        GhostType_PichanRacer = 1,
        GhostType_GhostPlayerMario = 2,
        GhostType_GhostPlayerLuigi = 3,

        GhostType_Invalid = -1
    };

    struct GstRecorderInfo {
        GstRecorderInfo();

        u32 mUpdateFrame;
        GstRecorderMode mRecorderMode;
        const char* mCurrentStageName;
        s32 mCurrentStageScenario;
        bool mIsSMG2;
        GhostType mGhostDataType;
        GhostPacketSyncData mGhostDataStruct;

        static GstRecorderInfo sInstance;
    };

    bool isEnableDebugGstRecorder();

    void waitGstRecorder(); 
    void prepareGstRecorder(const char *stageName, s32 scenarioId, GhostType ghostType);
    void startGstRecorder();
    void stopGstRecorder();
    void supplyGstFrameSyncWithActor(const LiveActor *actor, bool syncAnims);
    void supplyGstFrameSyncWithPlayer();

    // ----------------------------------------------------------------------------------------------------------------

    class GstRecordHelper : public LiveActor {
    public:
        GstRecordHelper(const char *pName);

        virtual void init(const JMapInfoIter &rIter);
        virtual void makeActorAppeared();
        virtual void control();
        virtual void attackSensor(HitSensor *pSender, HitSensor *pReceiver);

        virtual GhostType getGhostType() const = 0;
        virtual s32 getStateCount() const;
        virtual void initModelAndScene(const JMapInfoIter &rIter);
        virtual void handlePrepare();
        virtual void handleStopped();
        virtual void supplyGstFrame() const;

        void exeWait();
        void exePreparing();
        void exeRecording();

        IconAButton* mIconAButton;
        bool mShowIconAButton;
    };

    namespace NrvGstRecordHelper {
        NERVE(NrvWait);
        NERVE(NrvPreparing);
        NERVE(NrvRecording);
    };
};

#define NrvGstRecordHelperWait &gst::NrvGstRecordHelper::NrvWait::sInstance
#define NrvGstRecordHelperPreparing &gst::NrvGstRecordHelper::NrvPreparing::sInstance
#define NrvGstRecordHelperRecording &gst::NrvGstRecordHelper::NrvRecording::sInstance

namespace gst {
    class GhostLuigiRecordHelper : public GstRecordHelper {
    public:
        GhostLuigiRecordHelper(const char *pName);

        virtual GhostType getGhostType() const;
        virtual void initModelAndScene(const JMapInfoIter &rIter);
        virtual void handlePrepare();
        virtual void supplyGstFrame() const;
    };
};
