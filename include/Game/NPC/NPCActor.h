#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/LodCtrl.h"
#include "Game/LiveActor/PartsModel.h"
#include "Game/Enemy/AnimScaleController.h"
#include "Game/Player/YoshiLockOnTarget.h"
#include "Game/NPC/TalkMessageCtrl.h"

class NPCActorItem;
class NPCActorCaps;
class JointController;
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
    virtual void attackSensor(HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveMsgEnemyAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveOtherMsg(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool isReactionNerve() const;
    virtual bool isSensorSpinCloudBlock(const HitSensor *pSensor) const;

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

    LodCtrl* mLodCtrl;               // _90
    TalkMessageCtrl* mTalkCtrl;      // _94
    PartsModel* mGoodsModel0;        // _98
    PartsModel* mGoodsModel1;        // _9C
    s32 mTrampleAttackDelay;         // _A0
    TQuat4f mTurnDir;                // _A4
    TQuat4f _B4;
    TVec3f _C4;
    TVec3f _D0;
    bool mReactTrampleAttack;        // _DC
    bool mReactSpinAttack;           // _DD
    bool mReact2PPointerAttached;    // _DE
    bool mReactStarPieceAttack;      // _DF
    bool mReactJetTurtleAttack;      // _E0
    bool mConsumedTrampleAttack;     // _E1
    bool mConsumedSpinAttack;        // _E2
    bool mConsumed2PPointerAttached; // _E3
    bool mConsumedStarPieceAttack;   // _E4
    bool mConsumedJetTurtleAttack;   // _E5
    bool mRequestTrampleAttack;      // _E6
    bool mRequestSpinAttack;         // _E7
    bool mRequest2PPointerAttached;  // _E8
    bool mRequestStarPieceAttack;    // _E9
    bool mRequestJetTurtleAttack;    // _EA
    bool mRequestSupportTicoSpin;    // _EB
    bool _EC;
    bool _ED;
    f32 _F0;
    f32 _F4; // turning-related
    f32 _F8; // turning-related
    f32 _FC; // turning-related
    const char* mActionWait;         // _100
    const char* mActionWaitTurn;     // _104
    const char* mActionTalk;         // _108
    const char* mActionTalkTurn;     // _10C
    f32 _110;
    f32 _114;
    f32 _118;
    f32 _11C;
    const char* _120;
    const char* _124;
    bool _128;
    bool _129; // unused
    bool _12A; // unused
    bool _12B; // unused
    bool _12C;
    f32 _130;
    const char* mActionSpinName;           // _134
    const char* mActionTrampledName;       // _138
    const char* mActionPointingName;       // _13C
    const char* mActionReactionName;       // _140
    AnimScaleController* mAnimScaleCtrl;   // _144
    JointController* mJointCtrlParam;      // _148
    YoshiLockOnTarget* mYoshiLockOnTarget; // _14C
    const Nerve* mPushedNerve;             // _150
    const Nerve* mWaitNerve;               // _154
    const Nerve* mTalkNerve;               // _158
    const Nerve* mReactionNerve;           // _15C
    s32 mReact2PPointerAttachedDelay;      // _160
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
    bool mInitModel;                     // _4
    const char* mModelName;              // _8
    bool mInitAppear;                    // _C
    bool _D;
    bool mInitTalkCtrl;                  // _E
    bool mUseDirectTalk;                 // _F
    const char* mTalkMsgLabel;           // _10
    TVec3f mTalkOffset;                  // _14
    MtxPtr mTalkMtx;                     // _20
    const char* mTalkJoint;              // _24
    bool _28;
    bool mInitScene;                     // _29
    bool mInitLightCtrl;                 // _2A
    bool mInitEffectKeeper;              // _2B
    bool mInitSound;                     // _2C
    const char* mSoundObjName;           // _30
    s32 mSoundObjsCount;                 // _34
    bool mInitSearchTurtle;              // _38
    bool mInitDefaultPos;                // _39
    bool mInitLodCtrlNPC;                // _3A
    bool mInitSpine;                     // _3B
    s32 mSpineStateCount;                // _3C
    bool mInitBinder;                    // _40
    f32 mBinderRadius;                   // _44
    bool mInitHitSensor;                 // _48
    const char* mBodySensorJoint;        // _4C
    f32 mBodySensorRadius;               // _50
    TVec3f mBodySensorOffset;            // _54
    s32 mHitSensorCount;                 // _60
    bool mInitSphereShadow;              // _64
    bool mInitBcsvShadow;                // _65
    f32 mSphereShadowRadius;             // _68
    bool mInitRailRider;                 // _6C
    bool mUseSwitchWriteDead;            // _6D
    bool mUseStageSwitchSyncAppear;      // _6E
    bool mInitDead;                      // _6F
    bool mInitStarPointerTarget;         // _70
    const char* mStarPointerTargetJoint; // _74
    const char* mJointCtrlName;          // _78
    bool _7C;
    TVec3f mStarPointerTargetOffset;     // _80
    f32 mStarPointerTargetRadius;        // _8C
    s32 mSceneType;                      // _90
    bool mReactSupportTicoSpin;          // _94
    bool mInitYoshiLockOnTarget;         // _95
    Nerve* mWaitNerve;                   // _98
    Nerve* mTalkNerve;                   // _9C
    Nerve* mReactionNerve;               // _A0
};
