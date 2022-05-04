#pragma once

#include "revolution.h"
#include "JSystem.h"
#include "Game/Animation/AnmPlayer.h"
#include "Game/LiveActor/DisplayListMaker.h"
#include "Game/System/ResourceHolder.h"

class XanimeResourceTable;
class XanimePlayer;
class BckCtrl;
class BrkCtrl;
class BtpCtrl;
class BpkCtrl;
class BvaCtrl;

class ModelManager {
public:
    ModelManager();

    void init(const char *, const char *, bool);

    void update();
    void calcAnim();
    void calcView();
    void entry();
    void newDifferedDLBuffer();
    void updateDL(bool);
    void startBck(const char *, const char *);
    void startBckWithInterpole(const char *pAnimName, s32);
    void startBtk(const char *);
    void startBrk(const char *);
    void startBtp(const char *);
    void startBpk(const char *);
    void startBva(const char *);
    void stopBtk();
    void stopBrk();
    void stopBtp();
    void stopBpk();
    void stopBva();

    BckCtrl* getBckCtrl() const;
    BrkCtrl* getBrkCtrl() const;
    BtpCtrl* getBtpCtrl() const;
    BpkCtrl* getBpkCtrl() const;
    BvaCtrl* getBvaCtrl() const;
    bool isBckStopped() const;
    bool isBtkStopped() const;
    bool isBrkStopped() const;
    bool isBtpStopped() const;
    bool isBpkStopped() const;
    bool isBvaStopped() const;
    bool isBtkPlaying(const char *pAnimName) const;
    bool isBrkPlaying(const char *pAnimName) const;
    bool isBpkPlaying(const char *pAnimName) const;
    bool isBtpPlaying(const char *pAnimName) const;
    bool isBvaPlaying(const char *pAnimName) const;
    void initJointTransform();
    //jointTransform
    ResourceHolder* getResourceHolder() const;
    ResourceHolder* getModelResourceHolder() const;
    J3DModel* getJ3DModel() const;
    J3DModelData* getJ3DModelData() const;
    const char* getPlayingBckName() const;
    //void initModelAndAnimation(ResourceHolder *, const char *, ResourceHolder *, J3DMdlFlag);
    void initMaterialAnm();
    void initVisibilityAnim();
    void calc();
    void changeBckSetting(const char *, const char *, XanimePlayer *);

    BtkPlayer* mBtkPlayer;               // _0
    BrkPlayer* mBrkPlayer;               // _4
    BtpPlayer* mBtpPlayer;               // _8
    BpkPlayer* mBpkPlayer;               // _C
    BvaPlayer* mBvaPlayer;               // _10
    XanimeResourceTable* mResourceTable; // _14
    XanimePlayer* mXanimePlayer;         // _18
    J3DModel* mModel;                    // _1C
    ResourceHolder* mResourceHolder;     // _20
    DisplayListMaker* mDisplayListMaker; // _24
};
