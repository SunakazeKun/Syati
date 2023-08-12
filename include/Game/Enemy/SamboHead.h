#pragma once

#include "syati.h"
#include "pt/MapObj/BlueCoinSystem/BlueCoin.h"


class SamboHead : public LiveActor {
public:
    SamboHead(const char*);
    virtual void init(const JMapInfoIter&);
    virtual void appear();
    virtual void kill();
    virtual void control();
    void exeWaitUnderGround();
    void exeHide();
    void exeAppear();
    void exeWait();
    void exePrePursue();
    void exePursue();
    void exePursueEnd();
    void exeHitToPlayer();
    void exeStarPieceHit();
    void exeStampFall();
    void exeStampDeath();
    void exeHitBlow();
    void exeBuryDeath();
    void exeBindStarPointer();
    void exeBindStarPointerEnd();
    virtual void attackSensor(HitSensor*, HitSensor*);
    virtual bool receiveMsgPlayerAttack(u32, HitSensor*, HitSensor*);
    virtual bool receiveMsgPush(HitSensor*, HitSensor*);
    virtual bool receiveOtherMsg(u32, HitSensor*, HitSensor*);
    void calcAndSetBaseMtx();
    void isNerveTypeDead() const;
    void isStarPointerBindable() const;
    virtual ~SamboHead();

    s32 _90;
    s32 _94;
    s32 _98;
    s32 _9C;
    s32 _A0;
    s32 _A4;
    s32 _A8;
    s32 _AC;
    s32 _B0;
    s32 _B4;
    s32 _B8;

    #if defined USEBLUECOIN && !defined SM64BLUECOIN
    BlueCoin* mBlueCoin;
    s32 mBlueCoinArg;
    #endif
};