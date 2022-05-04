#pragma once

#include "revolution.h"
#include "JSystem.h"

class HitSensor;
class LayoutActor;
class LiveActor;
class MultiEmitterCallBackBase;
class MultiEmitterParticleCallBack;
class Triangle;

namespace MR {
	bool isExistEffect(const LiveActor *, const char *);

	void requestEffectStopSceneStart();
	void requestEffectStopSceneEnd();
	void addEffect(LiveActor *, const char *);
	void getEffect(const LiveActor *, const char *);
	void getEffect(const LayoutActor *, const char *);
	bool isExistEffectKeeper(const LiveActor *);
	bool isExistEffectKeeper(const LayoutActor *);
	void emitEffect(LiveActor *, const char *);
	void emitEffectWithScale(LiveActor *, const char *, f32, s32);
	void emitEffectWithEmitterCallBack(LiveActor *, const char *, MultiEmitterCallBackBase *);
	void emitEffectWithParticleCallBack(LiveActor *, const char *, MultiEmitterParticleCallBack *);
	bool tryEmitEffect(LiveActor *, const char *);
	bool tryDeleteEffect(LiveActor *, const char *);

	void deleteEffect(LiveActor *, const char *);
	void forceDeleteEffect(LiveActor *, const char *);
	void deleteEffectAll(LiveActor *);
	void forceDeleteEffectAll(LiveActor *);
	bool isRegisteredEffect(const LiveActor *, const char *);
	bool isEffectValid(const LiveActor *, const char *);
	void onDrawEffect(LiveActor *);
	void offDrawEffect(LiveActor *);
	void onCalcEmitter(LiveActor *);
	void offCalcEmitter(LiveActor *);
	void pauseOffEffectAll(LiveActor *);
	void setAllEffectDrawOrder(LiveActor *, s32);
	void onEmitEffectSyncClipping(LiveActor *, const char *);
	void onForceDeleteEffectSyncClipping(LiveActor *, const char *);
	void setEffectName(LiveActor *, const char *, const char *);
	void setEffectHostSRT(LiveActor *, const char *, const TVec3f *, const TVec3f *, const TVec3f *);
	void setEffectHostMtx(LiveActor *, const char *, MtxPtr);
	void setAllEffectHostMtx(LiveActor *, MtxPtr);
	void setEffectBaseScale(LiveActor *, const char *, f32);
	void setEffectColor(LiveActor *, const char *, u8, u8, u8, u8, u8, u8);
	void setEffectPrmColor(LiveActor *, const char *, u8, u8, u8);
	void setEffectEnvColor(LiveActor *, const char *, u8, u8, u8);
	void setEffectLocalScale(LiveActor *, const char *, const TVec3f &);
	void addEffectHitNormal(LiveActor *, const char *);
	void emitEffectHit(LiveActor *, const TVec3f &, const char *);
	void emitEffectHit(LiveActor *, const TVec3f &, const TVec3f &, const char *);
	void emitEffectHit(LiveActor *, MtxPtr, const char *);
	void emitEffectHitBetweenSensors(LiveActor *, const HitSensor *, const HitSensor *, f32, const char *);
	void initEffectAfterPlacement(LiveActor *, bool);
	void updateEffectFloorCode(LiveActor *, const Triangle *);
	void updateEffectFloorCodeLineToMap(LiveActor *, const TVec3f &, const TVec3f &);
	void updateEffectFloorCodeLineToMap(LiveActor *, f32, f32);
};
