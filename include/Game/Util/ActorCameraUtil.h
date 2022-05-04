#pragma once

#include "revolution.h"
#include "JSystem.h"

class ActorCameraInfo;
class CameraTargetArg;
class LiveActor;
class ResourceHolder;

void createActorCameraName(char *, u32, const LiveActor *, const ActorCameraInfo *);
void createMultiActorCameraName(char *, u32, const LiveActor *, const ActorCameraInfo *, const char *);

namespace MR {
	void createActorCameraInfo(JMapInfoIter const &);
	void createActorCameraInfoIfExist(JMapInfoIter const &, ActorCameraInfo **);
	void initActorCamera(const LiveActor *, JMapInfoIter const &, ActorCameraInfo **);
	void initMultiActorCameraNoInit(const LiveActor *, ActorCameraInfo *, const char *);
	void initActorCameraProgrammable(const LiveActor *);
	bool startActorCameraNoTarget(const LiveActor *, const ActorCameraInfo *, s32);
	bool startActorCameraTargetPlayer(const LiveActor *, const ActorCameraInfo *, s32);
	bool startActorCameraTargetSelf(const LiveActor *, const ActorCameraInfo *, s32);

	bool startActorCameraTargetOther(const LiveActor *, const ActorCameraInfo *, const CameraTargetArg &, s32);
	bool startMultiActorCameraNoTarget(const LiveActor *, const ActorCameraInfo *, const char *, s32);
	bool startMultiActorCameraTargetPlayer(const LiveActor *, const ActorCameraInfo *, const char *, s32);
	bool startMultiActorCameraTargetSelf(const LiveActor *, const ActorCameraInfo *, const char *, s32);

	bool startMultiActorCameraTargetOther(const LiveActor *, const ActorCameraInfo *, const char *, const CameraTargetArg &, s32);
	void startAnimCameraTargetPlayer(const LiveActor *, const ActorCameraInfo *, const char *, s32, bool, f32);
	void startAnimCameraTargetSelf(const LiveActor *, const ActorCameraInfo *, const char *, s32, bool, f32);
	void startAnimCameraTargetOther(const LiveActor *, const ActorCameraInfo *, const char *, const CameraTargetArg &, s32, s32, f32);
	void startActorCameraProgrammable(const LiveActor *, s32);
	bool endActorCamera(const LiveActor *, const ActorCameraInfo *, bool, s32);
	bool endMultiActorCamera(const LiveActor *, const ActorCameraInfo *, const char *, bool, s32);
	bool endActorCameraAtLanding(const LiveActor *, const ActorCameraInfo *, s32);
	bool endActorCameraProgrammable(const LiveActor *, s32, bool);
	bool isActiveActorCamera(const LiveActor *, const ActorCameraInfo *);
	bool isActiveMultiActorCamera(const LiveActor *, const ActorCameraInfo *, const char *);
	void setProgrammableCameraParam(const LiveActor *, const TVec3f &, const TVec3f &, const TVec3f &);
	void setProgrammableCameraParamFovy(const LiveActor *, f32);
	void initAnimCamera(const LiveActor *, const ActorCameraInfo *, const char *);
	void initAnimCamera(const LiveActor *, const ActorCameraInfo *, const char *, ResourceHolder *);
	void endAnimCamera(const LiveActor *, const ActorCameraInfo *, const char *, s32, bool);

	bool isAnimCameraEnd(const LiveActor *, const ActorCameraInfo *, const char *);
	u32* getActorCameraFrames(const LiveActor *, const ActorCameraInfo *);
	u32* getMultiActorCameraFrames(const LiveActor *, const ActorCameraInfo *, const char *);
	bool isExistActorCamera(const ActorCameraInfo *);
	void startRumbleWithShakeCameraWeak(const LiveActor *, const char *, const char *, f32, f32);
	void startRumbleWithShakeCameraNormalWeak(const LiveActor *, const char *, const char *, f32, f32);
	void startRumbleWithShakeCameraStrong(const LiveActor *, const char *, const char *, f32, f32);
};
