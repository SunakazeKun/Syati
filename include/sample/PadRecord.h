#pragma once

/*
* Author: Aurum
* 
* Helper code to assist with recording input playback data (PAD). The Python 3 tool "galaxypad" can record playback
* data supplied by this code while playing on the Dolphin Emulator. To start the recording, you need to add the
* following things in your galaxy first:
* - A spawn point from which the playback should start.
* - A "PadRecordHelper" object in the same zone as the previously added spawn point.
* 
* The PadRecordHelper's Obj_arg0 has to be set to the desired spawn point's MarioNo!
* 
* Now, do the following to record playback:
* 
* 1st: Start the game if you haven't already.
* 2nd: Start the galaxypad tool if you haven't already.
* 3rd: Once you are in the desired galaxy, go to where you placed PadRecordHelper. It doesn't use a model, but an A
*      button icon will be displayed on the screen when you are close to it. Once you press A, the scene will reset
*      and the recording will start.
* 4th: Once you are done, press 2 on the Wiimote to stop recording.
*/

#include "Game/LiveActor/LiveActor.h"
#include "Game/Screen/IconAButton.h"

class WPadReadDataInfo;
class WPadHolder;

namespace pad {
    enum PadRecorderMode {
        PadRecorderMode_Waiting = 0,
        PadRecorderMode_Preparing = 1,
        PadRecorderMode_Recording = 2,
        PadRecorderMode_Stopped = 3
    };

    struct PadRecorderInfo {
        PadRecorderInfo();

        u32 mUpdateFrame;
        WPadReadDataInfo* mReadDataInfo;
        PadRecorderMode mRecorderMode;
        const char* mCurrentStageName;
        JMapIdInfo mCurrentRestartId;
        u8* mBackupGameData;
        u32 mBackupGameDataSize;

        static PadRecorderInfo sInstance;
    };

    bool isEnableDebugPadRecorder();
    bool isDisableDreamerByPadRecord();
    bool isEnablePadRecorderAnytime();
    bool isEnablePadRecorderForSpawn(const JMapIdInfo &spawnId);

    void waitPadRecorderNotPrepared();
    void preparePadRecorder(const char *stageName, const JMapIdInfo &spawnId);
    void startPadRecorderPrepared();
    void stopPadRecorder();

    void updateFrame();

    // ----------------------------------------------------------------------------------------------------------------

    class PadRecordHelper : public LiveActor {
    public:
        PadRecordHelper(const char *pName);

        virtual void init(const JMapInfoIter &rIter);
        virtual void makeActorAppeared();
        virtual void control();
        virtual void attackSensor(HitSensor *pSender, HitSensor *pReceiver);

        void exeWait();
        void exePreparing();
        void exeRecording();

        JMapIdInfo mRestartId;
        IconAButton* mIconAButton;
        bool mShowIconAButton;
    };

    namespace NrvPadRecordHelper {
        NERVE(NrvWait);
        NERVE(NrvPreparing);
        NERVE(NrvRecording);
    };
};

#define NrvPadRecordHelperWait &pad::NrvPadRecordHelper::NrvWait::sInstance
#define NrvPadRecordHelperPreparing &pad::NrvPadRecordHelper::NrvPreparing::sInstance
#define NrvPadRecordHelperRecording &pad::NrvPadRecordHelper::NrvRecording::sInstance
