#pragma once

#include "revolution.h"
#include "JSystem.h"

class ActorLightCtrl;
class BreakModel;
class CollisionParts;
class CollisionPartsFilterBase;
class LiveActor;
class LiveActorGroup;
class LodCtrl;
class MirrorActor;
class ModelObj;
class Nerve;
class HitSensor;
class PartsModel;
class RailObj;
class TriangleFilterBase;

namespace MR {
    enum CollisionScaleType {
        CollisionScaleType_0,
        CollisionScaleType_1,
        CollisionScaleType_2
    };

    void setPosition(LiveActor *, const TVec3f &);
    void setPosition(LiveActor *, f32, f32, f32);
    void setRotation(LiveActor *, const TVec3f &);
    void setRotation(LiveActor *, f32, f32, f32);
    void setRotation(LiveActor *, f32);

    void setScale(LiveActor *, const TVec3f &);
    void setScale(LiveActor *, f32, f32, f32);
    void setScale(LiveActor *, f32);
    void copyTransRotateScale(const LiveActor *, LiveActor *);
    void copyTransRotate(const LiveActor *, LiveActor *);

    bool isValidMovement(const LiveActor *);
    bool isValidCalcAnim(const LiveActor *);
    bool isValidCalcViewAndEntry(const LiveActor *);
    bool isValidDraw(const LiveActor *);
    void calcAnimDirect(LiveActor *);
    void setClippingTypeSphere(LiveActor *, f32);
    void setClippingTypeSphere(LiveActor *, f32, const TVec3f *);
    void setClippingTypeSphereContainsModelBoundingBox(LiveActor *, f32);
    void setClippingFar50m(LiveActor *);
    void setClippingFar100m(LiveActor *);
    void setClippingFar200m(LiveActor *);
    void setClippingFar300m(LiveActor *);
    void setClippingFarMax(LiveActor *);
    void setClippingFar(LiveActor *, f32);
    void setGroupClipping(LiveActor *, const JMapInfoIter &, int);
    void validateClipping(LiveActor *);
    void invalidateClipping(LiveActor *);
    bool changeShowModelFlagSyncNearClipping(LiveActor *, f32);
    bool isClipped(const LiveActor *);
    bool isInvalidClipping(const LiveActor *);
    void setBaseTRMtx(LiveActor *, MtxPtr);
    void setBaseTRMtx(LiveActor *, const TMtx34f &);
    void setBaseTRMtx(LiveActor *, const TQuat4f &);
    void setBaseScale(LiveActor *, const TVec3f &);

    // ResourceHolder stuff is found here
    void initDLMakerFog(LiveActor *, bool);
    
    void initDLMakerChangText(LiveActor *, const char *);
    void initDLMakerTexMtx(LiveActor *, const char *);
    void initDLMakerProjmapEffectMtxSetter(LiveActor *);

    void initMirrorReflection(LiveActor *);
    void setMirrorReflectionInfoFromMtxYUp(const TMtx34f &);
    void setMirrorReflectionInfoFromModel(LiveActor *);
    
    void initJointTransform(const LiveActor *);

    f32 getBckFrame(const LiveActor *);
    f32 getBtkFrame(const LiveActor *);
    f32 getBrkFrame(const LiveActor *);
    f32 getBtpFrame(const LiveActor *);
    f32 getBvaFrame(const LiveActor *);
    f32 getBckRate(const LiveActor *);
    f32 getBtkRate(const LiveActor *);
    f32 getBrkRate(const LiveActor *);
    f32 getBtpRate(const LiveActor *);
    f32 getBpkRate(const LiveActor *);
    f32 getBvaRate(const LiveActor *);
    f32 getBckFrameMax(const LiveActor *);
    f32 getBtkFrameMax(const LiveActor *);
    f32 getBrkFrameMax(const LiveActor *);
    f32 getBtpFrameMax(const LiveActor *);
    f32 getBvaFrameMax(const LiveActor *);

    void initLightCtrl(LiveActor *);
    void initLightCtrlForPlayer(LiveActor *);
    void updateLightCtrl(LiveActor *);
    void updateLightCtrlDirect(LiveActor *);
    void loadActorLight(const LiveActor *);

    ActorLightCtrl* getLightCtrl(const LiveActor *);

    bool isStep(const LiveActor *, s32);
    bool isFirstStep(const LiveActor *);
    bool isLessStep(const LiveActor *, s32);
    bool isLessEqualStep(const LiveActor *, s32);
    bool isGreaterStep(const LiveActor *, s32);
    bool isGreaterEqualStep(const LiveActor *, s32);
    bool isIntervalStep(const LiveActor *, s32);
    bool isNewNerve(const LiveActor *, s32);
    f32 calcNerveRate(const LiveActor *, s32);
    f32 calcNerveRate(const LiveActor *, s32, s32);
    f32 calcNerveEaseInRate(const LiveActor *, s32);
    f32 calcNerveEaseOutRate(const LiveActor *, s32);
    f32 calcNerveEaseOutRate(const LiveActor *, s32, s32);
    f32 calcNerveEaseInOutRate(const LiveActor *, s32);
    f32 calcNerveEaseInOutRate(const LiveActor *, s32, s32);
    f32 calcNerveValue(const LiveActor *, s32, f32, f32);
    f32 calcNerveValue(const LiveActor *, s32, s32, f32, f32);
    f32 calcNerveEaseInValue(const LiveActor *, s32, f32, f32);
    f32 calcNerveEaseInValue(const LiveActor *, s32, s32, f32, f32);
    f32 calcNerveEaseOutValue(const LiveActor *, s32, f32, f32);
    f32 calcNerveEaseOutValue(const LiveActor *, s32, s32, f32, f32);
    f32 calcNerveEaseInOutValue(const LiveActor *, s32, f32, f32);
    f32 calcNerveEaseInOutValue(const LiveActor *, s32, s32, f32, f32);
    f32 calcNerveParabolaValue(const LiveActor *, s32);

    void setNerveAtStep(LiveActor *, const Nerve *, s32);
    void setNerveAtBckStopped(LiveActor *, const Nerve *);
    bool trySetNerve(LiveActor *, const Nerve *);
    bool isOnGround(const LiveActor *);
    bool isOnGroundCos(const LiveActor *, f32);
    bool isBindedGround(const LiveActor *);
    bool isBindedWall(const LiveActor *);
    bool isBindedWallOfMap(const LiveActor *);
    bool isBindedWallOfMoveLimit(const LiveActor *);
    bool isBindedRoof(const LiveActor *);
    bool isBinded(const LiveActor *);
    bool isPressedRoofAndGround(const LiveActor *);

    TVec3f* getGroundNormal(const LiveActor *);
    TVec3f* getWallNormal(const LiveActor *);
    TVec3f* getRoofNormal(const LiveActor *);
    TVec3f* getBindedNormal(const LiveActor *);
    TVec3f* getBindedHitPos(const LiveActor *);
    TVec3f* getGroundHitPos(const LiveActor *);
    TVec3f* getWallHitPos(const LiveActor *);
    TVec3f* getRoofHitPos(const LiveActor *);
    f32 calcHitPowerToWall(const LiveActor *);
    u32 getBindedPlaneNum(const LiveActor *);
    TVec3f* getBindedPlaneNormal(const LiveActor *);
    HitSensor* getBindedPlaneSensor(const LiveActor *, int);
    TVec3f* getBindedFixReactionVector(const LiveActor *);
    void setBinderOffsetVec(LiveActor *, const TVec3f *, bool);
    void setBinderRadius(LiveActor *, f32);

    f32 getBinderRadius(const LiveActor *);
    void setBinderIgnoreMovingCollision(LiveActor *);
    void validateExCollisionParts(LiveActor *);
    void invalidateExCollisionParts(LiveActor *);
    void setBinderCollisionPartsFilter(LiveActor *, CollisionPartsFilterBase *);

    void setBinderExceptActor(LiveActor *, const LiveActor *);
    void setBindTriangleFilter(LiveActor *, TriangleFilterBase *);
    bool isExistBinder(const LiveActor *);
    void onEntryDrawBuffer(LiveActor *);
    void offEntryDrawBuffer(LiveActor *);
    bool isDead(const LiveActor *);
    bool isHiddenModel(const LiveActor *);
    void showModel(LiveActor *);
    void showModelAndEffects(LiveActor *);
    void hideModel(LiveActor *);
    void hideModelAndEffects(LiveActor *);
    void hideModelAndOnCalcAnim(LiveActor *);
    void showModelIfHidden(LiveActor *);
    void hideModelIfShown(LiveActor *);
    void hideModelAndOnCalcAnimIfShown(LiveActor *);
    bool isStopAnimFrame(LiveActor *);
    void stopAnimFrame(LiveActor *);
    void releaseAnimFrame(LiveActor *);
    bool isNoCalcAnim(const LiveActor *);
    void onCalcAnim(LiveActor *);
    void offCalcAnim(LiveActor *);
    bool isNoCalcView(const LiveActor *);
    bool isNoEntryDrawBuffer(const LiveActor *);
    bool isNoBind(const LiveActor *);
    void onBind(LiveActor *);
    void offBind(LiveActor *);
    bool isCalcGravity(const LiveActor *);
    void onCalcGravity(LiveActor *);
    void offCalcGravity(LiveActor *);

    void joinToGroup(LiveActor *, const char *);
    LiveActorGroup* joinToGroupArray(LiveActor *, const JMapInfoIter &, const char *, s32);
    LiveActorGroup* getGroupFromArray(const LiveActor *);

    void callMakeActorDeadAllGroupMember(const LiveActor *);
    void callKillAllGroupMember(const LiveActor *);
    void callMakeActorAppearedAllGroupMember(const LiveActor *);
    void callAppearAllGroupMember(const LiveActor *);
    void callRequestMovementOnAllGroupMember(const LiveActor *);
    void callInvalidateClippingAllGroupMember(const LiveActor *);
    void callValidateClippingAllGroupMember(const LiveActor *);
    void addToAttributeGroupSearchTurtle(const LiveActor *);
    bool isExistInAttributeGroupSearchTurtle(const LiveActor *);
    void calcGravity(LiveActor *);
    void calcGravity(LiveActor *, const TVec3f &);
    void calcGravityOrZero(LiveActor *);
    void initFur(LiveActor *);
    void initFurEnemy(LiveActor *);
    void initFurPlanet(LiveActor *);
    void initFurPlayer(LiveActor *);
    void initCollisionParts(LiveActor *, const char *, HitSensor *, MtxPtr);
    void initCollisionPartsAutoEqualScale(LiveActor *, const char *, HitSensor *, MtxPtr);
    void initCollisionPartsAutoEqualScaleOne(LiveActor *, const char *, HitSensor *, MtxPtr);

    CollisionParts* createCollisionPartsFromLiveActor(LiveActor *, const char *, HitSensor *, MR::CollisionScaleType);
    CollisionParts* createCollisionPartsFromLiveActor(LiveActor *, const char *, HitSensor *, MtxPtr, MR::CollisionScaleType);

    CollisionParts* tryCreateCollisionMoveLimit(LiveActor *, HitSensor *);
    CollisionParts* tryCreateCollisionWaterSurface(LiveActor *, HitSensor *);
    f32 getCollisionBoundingSphereRange(const LiveActor *);
    bool isValidCollisionParts(LiveActor *);
    void validateCollisionParts(LiveActor *);
    void validateCollisionParts(CollisionParts *);
    void invalidateCollisionParts(LiveActor *);
    void invalidateCollisionParts(CollisionParts *);
    void onUpdateCollisionParts(LiveActor *);
    void onUpdateCollisionPartsOneTimeImmediately(LiveActor *);
    void offUpdateCollisionParts(LiveActor *);

    void resetAllCollisionMtx(LiveActor *);
    void setCollisionMtx(LiveActor *);
    void setCollisionMtx(LiveActor *, CollisionParts *);
    CollisionParts* getCollisionParts(LiveActor *);
    bool isExistCollisionParts(const LiveActor *);
    u32 getCollisionSensortType(const CollisionParts *);

    ModelObj* createModelObjMapObj(const char *, const char *, MtxPtr);
    ModelObj* createModelObjMapObjStrongLight(const char *, const char *, MtxPtr);
    ModelObj* createModelObjNoSilhouettedMapObj(const char *, const char *, MtxPtr);
    ModelObj* createModelObjNoSilhouettedMapObjStrongLight(const char *, const char *, MtxPtr);
    ModelObj* createModelObjIndirectMapObj(const char *, const char *, MtxPtr);
    ModelObj* createModelObjPlayerDecoration(const char *, const char *, MtxPtr);
    ModelObj* createModelObjEnemy(const char *, const char *, MtxPtr);
    ModelObj* createModelObjNPC(const char *, const char *, MtxPtr);
    ModelObj* createModelObjBloomModel(const char *, const char *, MtxPtr);

    BreakModel* createBreakModel(LiveActor *, MtxPtr);
    ModelObj* createBloomModel(LiveActor *, MtxPtr);
    ModelObj* createWaterModel(LiveActor *, MtxPtr);
    ModelObj* createIceModel(LiveActor *, MtxPtr);
    ModelObj* createIndirectPlanetModel(LiveActor *, MtxPtr);
    ModelObj* createIndirectModel(LiveActor *, MtxPtr);

    PartsModel* createPartsModelMapObj(LiveActor *, const char *, const char *, MtxPtr);
    PartsModel* createPartsModelMapObjStrongLight(LiveActor *, const char *, const char *, MtxPtr);
    PartsModel* createPartsModelNoSilhouettedMapObj(LiveActor *, const char *, const char *, MtxPtr);
    PartsModel* createPartsModelEnemy(LiveActor *, const char *, const char *, MtxPtr);
    PartsModel* createPartsModelNpc(LiveActor *, const char *, const char *, MtxPtr);
    PartsModel* createPartsModelIndirectNpc(LiveActor *, const char *, const char *, MtxPtr);
    PartsModel* createPartsModelEnemyAndFix(LiveActor *, const char *, const char *, MtxPtr);
    PartsModel* createPartsModelNpcAndFix(LiveActor *, const char *, const char *, MtxPtr);
    RailObj* createRailObj(const char *, LiveActor *, const JMapInfoIter &);
    const char* createLowModelObjName(const LiveActor *);
    const char* createMiddelModelObjName(const LiveActor *);
    LodCtrl* createLodCtrlNPC(LiveActor *, const JMapInfoIter &);
    LodCtrl* createLodCtrlPlanet(LiveActor *, const JMapInfoIter &, f32, s32);
    MirrorActor* tryCreateMirrorActor(LiveActor *, const char *);
    void stopSceneAtStep(const LiveActor *, s32, s32);
    void tryRumblePadAndCameraDistanceStrong(const LiveActor *, f32, f32, f32);
    void tryRumblePadAndCameraDistanceMiddle(const LiveActor *, f32, f32, f32);

    HitSensor* getBodySensor(LiveActor *);
    void setBodySensorType(LiveActor *, u32);
};
