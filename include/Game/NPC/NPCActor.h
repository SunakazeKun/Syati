#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class NPCActorItem;
class NPCActorCaps;
class JointControllerInfo;

class NPCActor : public LiveActor {
public:
    NPCActor(const char *pName);
    
    virtual ~NPCActor();
    virtual void init(const JMapInfoIter &rIter);
    virtual void initAfterPlacement();
    virtual void makeActorAppeared();
    virtual void kill();
    virtual void makeActorDead();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void attackSensor(HitSensor *, HitSensor *);
    virtual bool receiveMsgPlayerAttack(u32, HitSensor *, HitSensor *);
    virtual bool receiveMsgEnemyAttack(u32, HitSensor *, HitSensor *);
    virtual bool receiveOtherMsg(u32, HitSensor *, HitSensor *);
    virtual bool isReactionNerve() const;
    virtual bool isSensorSpinCloudBlock(const HitSensor *) const;

    void setBaseMtx(const TMtx34f &);
    void setInitPose();
    void initialize(const JMapInfoIter &, const NPCActorCaps &, const char *, const char *, bool);
    void equipment(const NPCActorItem &, bool);
    void initTalkCtrl(const JMapInfoIter &, const char *, const TVec3f &, MtxPtr);
    void initTalkCtrlDirect(const JMapInfoIter &, const char *, const TVec3f &, MtxPtr);
    void calcJointScale(TMtx34f *, const JointControllerInfo &);
    void turnToPlayer();
    void turnToPlayer(f32);
    void turnToPlayer(f32, f32, f32);
    void turnToDefault(f32);
    void setToDefault();

    void pushNerve(const Nerve *);
    void popAndPushNerve(const Nerve *);
    void popNerve();
    void tryPushNullNerve();
    bool isEmptyNerve() const;
    bool isScaleAnim() const;
    bool isPointingSe() const;
    void updateReaction();
    void updateScaleCtrl();
    void exeWait();
    void exeTalk();

    u32 _90;
    u32 _94;
    LiveActor* mGoods0; // _98
    LiveActor* mGoods1; // _9C
    u32 _A0;
    TVec3f _A4;
    u32 _B0;
    TVec3f _B4;
    u32 _C0;
    TVec3f _C4;
    TVec3f _D0;
    u8 _DC;
    u8 _DD;
    u8 _DE;
    u8 _DF;
    u8 _E0;
    u8 _E1;
    u8 _E2;
    u8 _E3;
    u8 _E4;
    u8 _E5;
    u8 _E6;
    u8 _E7;
    u8 _E8;
    u8 _E9;
    u8 _EA;
    u8 _EB;
    u8 _EC;
    u8 _ED;
    f32 _F0;
    f32 _F4;
    f32 _F8;
    f32 _FC;
    u32 _100;
    u32 _104;
    u32 _108;
    u32 _10C;
    f32 _110;
    f32 _114;
    f32 _118;
    f32 _11C;
    u32 _120;
    u32 _124;
    u8 _128;
    u8 _129;
    u8 _12A;
    u8 _12B;
    u8 _12C;
    f32 _130;
    u32 _134;
    u32 _138;
    u32 _13C;
    u32 _140;
    u32 _144;
    u32 _148;
    u32 _14C;
    u32 _150;
    Nerve* _154;
    Nerve* _158;
    Nerve* _15C;
    u32 _160;
};

namespace NrvNPCActor {
	NERVE(NPCActorNrvReaction);
	NERVE(NPCActorNrvWait);
	NERVE(NPCActorNrvTalk);
	NERVE(NPCActorNrvNull);
};

class NPCActorItem {
public:
    inline NPCActorItem(const char *pName, u32* __4, u32* __8, const char *__C, u32 *__10) {
        mName = pName;
        _4 = __4;
        _8 = __8;
        _C = __C;
        _10 = __10;
    }

    const char* mName;  // _0
    u32* _4;
    u32* _8;
    const char* _C;
    u32* _10;
};

class NPCActorCaps {
public:
    NPCActorCaps(const char *);

    void setDefault();

    const char* _0;
    u8 _4;
    const char* _8;
    u8 _C;
    u8 _D;
    u8 _E;
    u8 _F;
    const char* _10;
    f32 _14;
    f32 _18;
    f32 _1C;
    u32 _20;
    u32 _24;
    u8 _28;
    u8 _29;
    u8 _2A;
    u8 _2B;
    u8 _2C;
    u32 _30;
    u32 _34;
    u8 _38;
    u8 _39;
    u8 _3A;
    u8 _3B;
    u32 _3C;
    u8 _40;
    f32 _44;
    u8 _48;
    u32 _4C;
    f32 _50;
    TVec3f _54;
    u32 _60;
    u8 _64;
    u8 _65;
    f32 _68;
    u8 _6C;
    u8 _6D;
    u8 _6E;
    u8 _6F;
    u8 _70;
    u32 _74;
    u32 _78;
    u8 _7C;
    f32 _80;
    f32 _84;
    f32 _88;
    f32 _8C;
    u32 _90;
    u8 _94;
    u8 _95;
    Nerve* _98;
    Nerve* _9C;
    Nerve* _A0;
};
