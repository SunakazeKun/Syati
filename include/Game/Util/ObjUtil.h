#pragma once

#include "revolution.h"
#include "JSystem.h"
#include "Game/Util/Functor.h"

class NameObj;
class LayoutActor;
class LiveActor;
class ResourceHolder;
class StageSwitchCtrl;
class JMapInfo;
class JMapInfoIter;

namespace MR {
    bool isJudgedToClipFrustum(const TVec3f &, f32);

    bool isJudgedToClipFrustum300m(const TVec3f &, f32);
    bool isJudgedToNearClip(const TVec3f &, f32);

    bool isInWater(const TVec3f &);
    bool isInDeath(const TVec3f &);
    bool isInDarkMatter(const TVec3f &);

    void connectToScene(NameObj *, int movementType, int calcAnimType, int drawBufferType, int drawType);
    void connectToSceneCollisionMapObj(LiveActor *);
    void connectToSceneCollisionMapObjWeakLight(LiveActor *);
    void connectToSceneCollisionMapObjStrongLight(LiveActor *);
    void connectToSceneCollisionEnemy(LiveActor *);
    void connectToSceneCollisionEnemyStrongLight(LiveActor *);
    void connectToSceneCollisionEnemyNoShadowedMapObjStrongLight(LiveActor *);
    void connectToSceneNpc(LiveActor *);
    void connectToSceneNpcMovement(LiveActor *);
    void connectToSceneRide(LiveActor *);
    void connectToSceneEnemy(LiveActor *);
    void connectToSceneEnemyMovement(NameObj *);
    void connectToSceneMapObj(LiveActor *);
    void connectToSceneMapObjMovement(NameObj *);
    void connectToSceneMapObjMovementCalcAnim(NameObj *);
    void connectToSceneMapObjNoMovement(LiveActor *);
    void connectToSceneMapObjNoCalcAnim(LiveActor *);
    void connectToSceneMapObjNoCalcAnimStrongLight(LiveActor *);
    void connectToSceneMapObjDecoration(LiveActor *);
    void connectToSceneMapObjDecorationStrongLight(LiveActor *);
    void connectToSceneMapObjDecorationMovement(NameObj *);
    void connectToSceneMapObjStrongLight(LiveActor *);
    void connectToScenePlanet(LiveActor *);
    void connectToSceneEnvironment(LiveActor *);
    void connectToSceneEnvironmentStrongLight(LiveActor *);
    void connectToClippedMapParts(LiveActor *);
    void connectToSceneEnemyDecoration(LiveActor *);
    void connectToSceneEnemyDecorationMovement(NameObj *);
    void connectToSceneEnemyDecorationMovementCalcAnim(NameObj *);
    void connectToSceneItem(LiveActor *);
    void connectToSceneItemStrongLight(LiveActor *);
    void connectToSceneIndirectEnemy(LiveActor *);
    void connectToSceneIndirectNpc(LiveActor *);
    void connectToSceneIndirectMapObj(LiveActor *);
    void connectToSceneIndirectMapObjStrongLight(LiveActor *);
    void connectToSceneScreenEffectMovement(NameObj *);
    void connectToSceneAreaObj(NameObj *);
    void connectToScene3DModelFor2D(LiveActor *);
    void connectToSceneLayout(NameObj *);

    void connectToSceneLayoutMovementCalcAnim(NameObj *);
    void connectToSceneLayoutDecoration(NameObj *);
    void connectToSceneLayoutFileSelect(NameObj *);
    void connectToSceneTalkLayout(NameObj *);
    void connectToSceneWipeLayout(NameObj *);
    void connectToSceneLayoutOnPause(NameObj *);
    void connectToSceneLayoutMovement(NameObj *);
    void connectToSceneMirrorMapObj(LiveActor *);
    void connectToSceneMirrorMapObjDecoration(LiveActor *);
    void connectToSceneCamera(NameObj *);
    void connectToSceneNoShadowedMapObj(LiveActor *);
    void connectToSceneNoShadowedMapObjStrongLight(LiveActor *);
    void connectToSceneNoSilhouettedMapObj(LiveActor *);
    void connectToSceneNoSilhouettedMapObjStrongLight(LiveActor *);
    void connectToSceneNoSilhouettedMapObjStrongLightCalcAnim(LiveActor *);
    void connectToSceneNoSilhouettedMapObjWeakLightCalcAnim(LiveActor *);
    void connectToSceneSwitchingScreenEffect(LiveActor *);
    void connectToSceneSky(LiveActor *);
    void connectToSceneAir(LiveActor *);
    void connectToSceneSun(LiveActor *);
    void connectToSceneWorldMapMiniObj(LiveActor *);
    void connectToSceneWorldMapIcon(LiveActor *);
    void connectToSceneSuperDreamer(LiveActor *);
    void requestMovementOn(NameObj *);
    void requestMovementOn(LiveActor *);
    void requestMovementOn(LayoutActor *);
    void requestMovementOff(NameObj *);
    void requestMovementOff(LiveActor *);
    void requestMovementOff(LayoutActor *);
    void joinToNameObjGroup(NameObj *, const char *);
    void registerPreDrawFunction(const MR::FunctorBase &, int);

    void listenNameObjStageSwitchOnAppear(const NameObj *, const StageSwitchCtrl *, const MR::FunctorBase &);
    void listenNameObjStageSwitchOnOffAppear(const NameObj *, const StageSwitchCtrl *, const MR::FunctorBase &, const MR::FunctorBase &);
    void listenNameObjStageSwitchOnA(const NameObj *, const StageSwitchCtrl *, const MR::FunctorBase &);
    void listenNameObjStageSwitchOnOffA(const NameObj *, const StageSwitchCtrl *, const MR::FunctorBase &, const MR::FunctorBase &);
    void listenNameObjStageSwitchOnB(const NameObj *, const StageSwitchCtrl *, const MR::FunctorBase &);
    void listenNameObjStageSwitchOffB(const NameObj *, const StageSwitchCtrl *, const MR::FunctorBase &);
    void listenNameObjStageSwitchOnOffB(const NameObj *, const StageSwitchCtrl *, const MR::FunctorBase &, const MR::FunctorBase &);

    // ResourceHolder stuff is found here
    JMapInfo* createCsvParser(const ResourceHolder *, const char *, ...);
    JMapInfo* createCsvParser(const char *, const char *, ...);
    JMapInfo* tryCreateCsvParser(const ResourceHolder *, const char *, ...);
    JMapInfo* tryCreateCsvParser(const LiveActor *, const char *, ...);

    s32 getCsvDataElementNum(const JMapInfo *);
    bool getCsvDataStr(const char **, const JMapInfo *, const char *, s32);
    void getCsvDataStrOrNULL(const char **, const JMapInfo *, const char *, s32);
    bool getCsvDataS32(s32 *, const JMapInfo *, const char *, s32);
    bool getCsvDataU32(s32 *, const JMapInfo *, const char *, s32);
    bool getCsvDataS16(s16 *, const JMapInfo *, const char *, s32);
    void getCsvDataU8(u8 *, const JMapInfo *, const char *, s32);
    void getCsvDataF32(f32 *, const JMapInfo *, const char *, s32);
    void getCsvDataBool(bool *, const JMapInfo *, const char *, s32);
    void getCsvDataVec(Vec *, const JMapInfo *, const char *, s32);

    void declarePowerStar(const NameObj *);
    void declarePowerStar(const NameObj *, s32);
    void declarePowerStarCoin100();
    void appearPowerStarContinueCurrentDemo(const NameObj *, const TVec3f &);
    void appearPowerStarWithoutDemo(const NameObj *);

    void requestAppearPowerStar(const NameObj *, const TVec3f &);
    void requestAppearPowerStar(const NameObj *, s32, const TVec3f &);
    void requestAppearPowerStar(const NameObj *, const LiveActor *, f32);

    void requestAppearPowerStarCoin100();
    bool isEndPowerStarAppearDemo(const NameObj *);
    NameObj* createPowerStarDemoModel(const NameObj *, const char *, MtxPtr);
    void declareCoin(const NameObj *, s32);
    s32 getDeclareRemnantCoinCount(const NameObj *);

    bool hopCoin(const NameObj *, const TVec3f &, const TVec3f &);
    bool appearCoinPop(const NameObj *, const TVec3f &, s32);
    bool appearCoinPopToDirection(const NameObj *, const TVec3f &, const TVec3f &, s32);

    bool appearCoinToVelocity(const NameObj *, const TVec3f &, const TVec3f &, s32);
    bool appearCoinCircle(const NameObj *, const TVec3f &, const TVec3f &, s32);
    void declareStarPiece(const NameObj *, s32);
    s32 getDeclareRemnantStarPieceCount(const NameObj *);
    s32 getDeclareRemnantStarPieceCountNotExist(const NameObj *);
    void declareStarPieceReceiver(const NameObj *, s32);
    void clearGotCountStarPieceReceiver(const NameObj *);
    bool hopStarPiece(const NameObj *, const TVec3f &, const TVec3f &);
    bool appearStarPiece(const NameObj * pHost, const TVec3f & rPosition, s32 numItems, f32 radius, f32 height, bool);
    bool appearStarPieceToDirection(const NameObj *, const TVec3f &, const TVec3f &, s32, f32, f32, bool);

    void initStarPieceGetCSSound();

    void stopScene(s32);
    void stopSceneForDefaultHit(s32);
    bool tryRumblePad(const void *, const char *, s32);
    bool tryRumblePadVeryStrong(const void *, s32);
    bool tryRumblePadStrong(const void *, s32);
    bool tryRumblePadMiddle(const void *, s32);
    bool tryRumblePadWeak(const void *, s32);
    bool tryRumblePadVeryWeak(const void *, s32);

    bool tryRumbleDefaultHit(const void *, s32);
    void shakeCameraVeryStrong();
    void shakeCameraStrong();
    void shakeCameraNormalStrong();
    void shakeCameraNormal();
    void shakeCameraNormalWeak();
    void shakeCameraWeak();
    void shakeCameraVeryWeak();
    void shakeCameraInfinity(NameObj *, f32, f32);
    void stopShakingCamera(NameObj *);
    bool isName(const NameObj *, const char *);
    bool isSame(const NameObj *, const NameObj *);
    bool tryRegisterNamePosLinkObj(const NameObj *, const JMapInfoIter &, const char *);

    bool tryFindLinkNamePos(const NameObj *, const char *, MtxPtr);
    bool findNamePos(const char *, TVec3f *, TVec3f *);
    bool findNamePosOnGround(const char *, MtxPtr);

    bool tryFindNamePos(const char *, TVec3f *, TVec3f *);
    
    bool tryFindLinkNamePos(const NameObj *, const char *, TVec3f *, TVec3f *);
    bool tryFindLinkNamePos(const NameObj *, const char *, MtxPtr);
};
