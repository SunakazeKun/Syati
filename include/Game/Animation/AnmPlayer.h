#pragma once

#include "revolution.h"
#include "JSystem.h"
#include "Game/System/ResourceHolder.h"
#include "Game/System/ResourceInfo.h"

class AnmPlayerBase {
public:
    AnmPlayerBase(const ResTable *);

    virtual void changeAnimation(J3DAnmBase *);
    virtual void stopAnimation();

    void update();
    void reflectFrame();
    void start(const char *pAnimName);
    void stop();
    bool isPlaying(const char *pAnimName) const;
    bool isStop() const;

    J3DAnmBase* mJ3DAnmBase;        // _4
    const ResTable* mResourceTable; // _8
    J3DFrameCtrl mFrameCtrl;        // _C
};

class MaterialAnmPlayerBase : public AnmPlayerBase {
public:
    MaterialAnmPlayerBase(const ResTable *, J3DModelData *);

    void beginDiff();
    void endDiff();

    J3DModelData* mModelData; // _20
};

class BpkPlayer : public MaterialAnmPlayerBase {
public:
    BpkPlayer(const ResourceHolder *, J3DModelData *);

    virtual void attach(J3DAnmBase *, J3DModelData *);
    virtual void detach(J3DAnmBase *, J3DModelData *);
};

class BrkPlayer : public MaterialAnmPlayerBase {
public:
    BrkPlayer(const ResourceHolder *, J3DModelData *);

    virtual void attach(J3DAnmBase *, J3DModelData *);
    virtual void detach(J3DAnmBase *, J3DModelData *);
};

class BtkPlayer : public MaterialAnmPlayerBase {
public:
    BtkPlayer(const ResourceHolder *, J3DModelData *);

    virtual void attach(J3DAnmBase *, J3DModelData *);
    virtual void detach(J3DAnmBase *, J3DModelData *);
};

class BtpPlayer : public MaterialAnmPlayerBase {
public:
    BtpPlayer(const ResourceHolder *, J3DModelData *);

    virtual void attach(J3DAnmBase *, J3DModelData *);
    virtual void detach(J3DAnmBase *, J3DModelData *);
};

class BvaPlayer : public AnmPlayerBase {
public:
    BvaPlayer(const ResTable *, J3DModel *);

    void calc();
    bool getAnmVisibility();

    J3DModel* mModel; // _20
};
