#pragma once

#include "revolution.h"
#include "JSystem.h"

class LiveActor;
class HitSensor;

namespace MR {
	void setSensorFollowPos(LiveActor *, const char *, const TVec3f &);
	void setSensorFollowMtx(LiveActor *, const char *, MtxPtr);
	HitSensor* addHitSensor(LiveActor *, const char *, u32, u16, f32, const TVec3f &);
	HitSensor* addHitSensorBinder(LiveActor *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorPriorBinder(LiveActor *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorRide(LiveActor *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorMapObj(LiveActor *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorMapObjSimple(LiveActor *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorMapObjMoveCollision(LiveActor *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorEnemy(LiveActor *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorEnemyAttack(LiveActor *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorNpc(LiveActor *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorEye(LiveActor *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorPush(LiveActor *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorPosRide(LiveActor *, const char *, u16, f32, const TVec3f *, const TVec3f &);
	HitSensor* addHitSensorPosMapObj(LiveActor *, const char *, u16, f32, const TVec3f *, const TVec3f &);
	HitSensor* addHitSensorPosEnemyAttack(LiveActor *, const char *, u16, f32, const TVec3f *, const TVec3f &);
	HitSensor* addHitSensorMtx(LiveActor *, const char *, u32, u16, f32, MtxPtr, const TVec3f &);
	HitSensor* addHitSensorMtxRide(LiveActor *, const char *, u16, f32, MtxPtr, const TVec3f &);
	HitSensor* addHitSensorMtxEnemy(LiveActor *, const char *, u16, f32, MtxPtr, const TVec3f &);
	HitSensor* addHitSensorMtxEnemyAttack(LiveActor *, const char *, u16, f32, MtxPtr, const TVec3f &);
	HitSensor* addHitSensorMtxAnimal(LiveActor *, const char *, u16, f32, MtxPtr, const TVec3f &);
	HitSensor* addHitSensorAtJoint(LiveActor *, const char *, const char *, u32, u16, f32, const TVec3f &);
	HitSensor* addHitSensorAtJointMapObj(LiveActor *, const char *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorAtJointMapObjSimple(LiveActor *, const char *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorAtJointEnemy(LiveActor *, const char *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorAtJointEnemyAttack(LiveActor *, const char *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorAtJointNpc(LiveActor *, const char *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorCallback(LiveActor *, const char *, u32, u16, f32);
	HitSensor* addHitSensorCallbackBinder(LiveActor *, const char *, u16, f32);
	HitSensor* addHitSensorCallbackPriorBinder(LiveActor *, const char *, u16, f32);
	HitSensor* addHitSensorCallbackRide(LiveActor *, const char *, u16, f32);
	HitSensor* addHitSensorCallbackMapObj(LiveActor *, const char *, u16, f32);
	HitSensor* addHitSensorCallbackEnemyAttack(LiveActor *, const char *, u16, f32);
	HitSensor* addHitSensorCallbackEye(LiveActor *, const char *, u16, f32);
	HitSensor* addBodyMessageSensor(LiveActor *, u32);
	HitSensor* addBodyMessageSensorReceiver(LiveActor *);
	HitSensor* addBodyMessageSensorMapObj(LiveActor *);
	HitSensor* addBodyMessageSensorMapObjPress(LiveActor *);
	HitSensor* addBodyMessageSensorEnemy(LiveActor *);
	HitSensor* addMessageSensorReceiver(LiveActor *, const char *);
	HitSensor* addHitSensorMapObj(LiveActor *, const char *);
	bool tryUpdateHitSensorsAll(LiveActor *);
	void updateHitSensorsAll(LiveActor *);
	bool isSensorType(const HitSensor *, u32);
	void setSensorType(LiveActor *, const char *, u32);
	bool isSensorValid(const HitSensor *);
	HitSensor* getSensorWithIndex(LiveActor *, int);
	HitSensor* getTaken(const LiveActor *);
	void setSensorPos(HitSensor *, const TVec3f &);
	void setSensorPos(LiveActor *, const char *, const TVec3f &);
	void setSensorOffset(LiveActor *, const char *, const TVec3f &);
	f32 getSensorRadius(HitSensor *);
	f32 getSensorRadius(LiveActor *, const char *);
	void setSensorRadius(HitSensor *, f32);
	void setSensorRadius(LiveActor *, const char *, f32);
	void scaleAllSensorRadius(LiveActor *, f32);
	TVec3f* getSensorHostPos(const HitSensor *);
	TVec3f* getSensorHostGravity(const HitSensor *);
	void validateHitSensors(LiveActor *);
	void invalidateHitSensors(LiveActor *);
	void validateHitSensor(HitSensor *);
	void invalidateHitSensor(HitSensor *);
	void validateHitSensor(LiveActor *, const char *);
	void invalidateHitSensor(LiveActor *, const char *);
	bool tryValidateHitSensor(LiveActor *, const char *);
	bool tryInvalidateHitSensor(LiveActor *, const char *);
	void clearHitSensors(LiveActor *pActor);
	s32 getSensorNum(const LiveActor *pActor);
	HitSensor* getSensor(LiveActor *pActor, int index);
	LiveActor* getSensorHost(const HitSensor *pSensor);
	bool isEqualSensor(const HitSensor *pOtherSensor, const LiveActor *pActor, const char *pSensorName);
	bool isSensorPlayer(const HitSensor *);
	bool isSensorYoshi(const HitSensor *);
	bool isSensorBinder(const HitSensor *);
	bool isSensorReceiver(const HitSensor *);
	bool isSensorRide(const HitSensor *);
	bool isSensorPlayerOrRide(const HitSensor *);
	bool isSensorPlayerOrYoshi(const HitSensor *);
	bool isSensorPlayerOrYoshiOrRide(const HitSensor *);
	bool isSensorEnemy(const HitSensor *);
	bool isSensorEnemyAttack(const HitSensor *);
	bool isSensorNpc(const HitSensor *);
	bool isSensorMapObj(const HitSensor *);
	bool isSensorAutoRush(const HitSensor *);
	bool isSensorRush(const HitSensor *);
	bool isSensorPressObj(const HitSensor *);
	bool isSensorEye(const HitSensor *);
	bool isSensorPush(const HitSensor *);
	bool isSensorItem(const HitSensor *);
	bool isSensorGhost(const HitSensor *);
	bool tryGetItem(HitSensor *, HitSensor *);
	TVec3f* getSensorPos(const HitSensor *);
	TVec3f* getSensorPos(const LiveActor *, const char *);
	// Two functions that are identical to the above two functions

	void calcSensorDirection(TVec3f *, const HitSensor *, const HitSensor *);
	void calcSensorDirectionNormalize(TVec3f *, const HitSensor *, const HitSensor *);

	f32 calcSensorDistance(const HitSensor *, const HitSensor *);
	void calcSensorHorizonNormalize(TVec3f *, const TVec3f &, const HitSensor *, const HitSensor *);
	HitSensor* getMessageSensor();
	bool sendArbitraryMsg(u32, HitSensor *, HitSensor *);
	bool sendMsgPush(HitSensor *, HitSensor *);
	bool sendMsgReflect(HitSensor *, HitSensor *);
	bool sendMsgReflectV(HitSensor *, HitSensor *);

	bool sendMsgPlayerTrample(HitSensor *, HitSensor *);
	bool sendMsgPlayerPunch(HitSensor *, HitSensor *);
	bool sendMsgInvincibleAttack(HitSensor *, HitSensor *);
	bool sendMsgDrillAttack(HitSensor *, HitSensor *);
	bool sendMsgRockAttack(HitSensor *, HitSensor *);
	bool sendMsgJump(HitSensor *, HitSensor *);
	bool sendMsgTouchJump(HitSensor *, HitSensor *);
	bool sendMsgTaken(HitSensor *, HitSensor *);
	bool sendMsgAwayJump(HitSensor *, HitSensor *);
	
	bool sendMsgRushEnd(HitSensor *, HitSensor *);
	bool sendMsgIsRushEnable(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackMsgToDir(u32, HitSensor *, HitSensor *, const TVec3f &);
	bool sendMsgEnemyAttackFlipVeryWeak(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackFlipWeak(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackFlipWeakJump(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackFlip(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackFlipToDir(HitSensor *, HitSensor *, const TVec3f &);
	bool sendMsgEnemyAttackFlipJump(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackFlipRot(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackFlipMaximumToDir(HitSensor *, HitSensor *, const TVec3f &);
	bool sendMsgEnemyAttack(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackOrPush(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackStrong(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackStrongOrPush(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackStrongToDir(HitSensor *, HitSensor *, const TVec3f &);
	bool sendMsgEnemyAttackFire(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackFireStrong(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackElectric(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackFreeze(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackExplosion(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackCounterSpin(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackCounterHipDrop(HitSensor *, HitSensor *);
	bool sendMsgLockOnStarPieceShoot(HitSensor *, HitSensor *);
	bool sendMsgStarPieceAttack(HitSensor *, HitSensor *);
	bool sendMsgStarPieceGift(HitSensor *, HitSensor *, u32);
	bool sendMsgEnemyAttackMaximum(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackMaximumToDir(HitSensor *, HitSensor *, const TVec3f &);
	bool sendMsgEnemyAttackToBindedSensor(LiveActor *, HitSensor *);
	bool sendMsgEnemyAttackExplosionToBindedSensor(LiveActor *, HitSensor *);
	bool sendMsgEnemyAttackRollToBindedSensor(LiveActor *, HitSensor *);

	bool sendSimpleMsgToActor(u32, LiveActor *);
	bool sendMsgToBindedSensor(u32, LiveActor *, HitSensor *);
	bool sendMsgToBindedSensor(u32, HitSensor *);
	bool sendMsgToGroundSensor(u32, HitSensor *);
	bool sendMsgToWallSensor(u32, HitSensor *);
	bool sendMsgToRoofSensor(u32, HitSensor *);

	bool sendMsgToEnemyAttackBlow(HitSensor *, HitSensor *);

	bool sendMsgToEnemyAttackTrample(HitSensor *, HitSensor *);

	bool sendMsgToEnemyAttackBlowOrTrample(HitSensor *, HitSensor *, f32);
	bool sendMsgToEnemyAttackShockWave(HitSensor *, HitSensor *);
	bool sendMsgToAllLiveActor(u32, LiveActor *);
	bool sendMsgToGroupMember(u32 msg, LiveActor *pGroupActor, HitSensor *pSender, const char *pSensorName);
	bool sendMsgGroupMoveStartToMember(LiveActor *pGroupActor, HitSensor *pSender, const char *pSensorName);
	bool sendMsgGroupMoveStopToMember(LiveActor *pGroupActor, HitSensor *pSender, const char *pSensorName);
	bool sendMsgGroupShowToMember(LiveActor *pGroupActor, HitSensor *pSender, const char *pSensorName);
	bool sendMsgGroupHideToMember(LiveActor *pGroupActor, HitSensor *pSender, const char *pSensorName);
	bool sendMsgExplosionToNearActor(HitSensor *pSender, f32 range);
	bool isInSpinStormRange(u32 msg, HitSensor *, HitSensor *, f32 range);
	void receiveItemShowMsg(u32 msg, HitSensor *, HitSensor *);
	void receiveItemHideMsg(u32 msg, HitSensor *, HitSensor *);
	void getGroundSensor(const LiveActor *pActor);
	void getRoofSensor(const LiveActor *pActor);
	void getWallSensor(const LiveActor *pActor);

	bool isMsgPlayerHitAll(u32 msg);

	bool isMsgPlayerSpinAttack(u32);
	bool isMsgPlayerSpinAttackOrSupportTico(u32);
	bool isMsgPlayerTrample(u32);
	bool isMsgPlayerHipDrop(u32);
	bool isMsgPlayerHipDropFloor(u32);
	bool isMsgPlayerUpperPunch(u32);
	bool isMsgPlayerKick(u32);

	bool isMsgThrow(u32 msg);
	bool isMsgDamageOrRushDrop(u32 msg);

	bool isMsgJetTurtleAttack(u32);
	bool isMsgYoshiProjectile(u32);
	bool isMsgYoshiEat(u32);
	bool isMsgYoshiProjectileOrEat(u32);
	bool isMsgFireBallAttack(u32);
	bool isMsgSearchlightAttack(u32);
	bool isMsgFreezeAttack(u32);
	bool isMsgInvincibleAttack(u32);
	bool isMsgDrillAttack(u32);
	bool isMsgRockAttack(u32);
	bool isMsgSnowBallAttack(u32);
	bool isMsgSupportTicoSpin(u32);
	bool isMsgAutoRushBegin(u32);
	bool isMsgRushBegin(u32);

	bool isMsgUpdateBaseMtx(u32);
	bool isMsgRushForceCancel(u32);
	bool isMsgRushCancel(u32);
	bool isMsgRushEnd(u32);
	bool isMsgIsRushTakeOver(u32);
	bool isMsgFloorTouch(u32);
	bool isMsgWallTouch(u32);
	bool isMsgCeilTouch(u32);
	bool isMsgItemGet(u32);
	bool isMsgItemPull(u32);
	bool isMsgItemShow(u32);
	bool isMsgItemHide(u32);
	
	bool isMsgItemStartMove(u32 msg);

	bool isMsgItemEndMove(u32 msg);

	bool isMsgInhaleBlackHole(u32 msg);

	bool isMsgEnemyAttack(u32);
	bool isMsgEnemyAttackFire(u32);
	bool isMsgEnemyAttackFireStrong(u32);
	bool isMsgEnemyAttackElectric(u32);
	bool isMsgExplosionAttack(u32);
	bool isMsgToEnemyAttackBlow(u32);
	bool isMsgToEnemyAttackRoll(u32);
	bool isMsgToEnemyAttackTrample(u32);

	bool isMsgToEnemyAttackShockWave(u32);
	bool isMsgSpinStormRange(u32);
	bool isMsgSuccess(u32);
	bool isMsgRaceReady(u32);
	bool isMsgRaceStart(u32);
	bool isMsgRaceReset(u32);
	bool isMsgLockOnStarPieceShoot(u32);
	bool isMsgBallDashWall(u32);
	bool isMsgBallDashGround(u32);
	bool isMsgStartPowerStarGet(u32);

	bool isMsgHitmarkEmit(u32);
	bool isMsgStarPieceAttack(u32);
	bool isMsgStarPieceReflect(u32);
	bool isMsgStarPieceGift(u32);
	bool isMsgStarLightGrow(u32 msg);
	bool isMsgStarLightShrink(u32 msg);
	bool isMsgReflect(u32);
	bool isMsgReflectV(u32);
	bool isMsgGroupMoveStart(u32);
	bool isMsgGroupMoveStop(u32);
	bool isMsgGroupShow(u32);
	bool isMsgGroupHide(u32);

	void calcPosBetweenSensors(TVec3f *, const HitSensor *, const HitSensor *, f32);
	bool tryForceKillIfMsgStartPowerStarGet(LiveActor *, u32);
};
