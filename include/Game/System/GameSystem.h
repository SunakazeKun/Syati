#pragma once

#include "revolution.h"
#include "Game/System/NerveExecutor.h"
#include "Game/System/GameSystemDataHolder.h"
#include "Game/System/GameSystemDimmingWatcher.h"

class GameSequenceDirector;
class GameSystemErrorWatcher;
class GameSystemFontHolder;
class GameSystemFrameControl;
class GameSystemObjHolder;
class GameSystemSceneController;
class GameSystemStationedArchiveLoader;
class HomeButtonLayout;
class SystemWipeHolder;

class GameSystem : public NerveExecutor {
public:
	GameSystem();

	virtual ~GameSystem();
	
	void init();
	bool isExecuteLoadSystemArchive() const;
	void startToLoadSystemArchive();
	void exeInitializeAudio();
	void exeInitializeLogoScene();
	void exeLoadStationedArchive();
	void initGX();
	void initAfterStationedResourceLoaded();
	void prepareReset();
	bool isPreparedReset() const;
	void frameLoop();
	void draw();
	void update();
	void updateSceneController();
	void calcAnim();

	u32* _8;
	GameSequenceDirector* mSequenceDirector;                   // _C
	GameSystemDimmingWatcher* mDimmingWatcher;				   // _10
	GameSystemErrorWatcher* mErrorWatcher;					   // _14
	GameSystemFontHolder* mFontHolder;						   // _18
	GameSystemFrameControl* mFrameControl;					   // _1C
	GameSystemObjHolder* mObjHolder;						   // _20
	GameSystemSceneController* mSceneController;			   // _24
	GameSystemStationedArchiveLoader* mStationedArchiveLoader; // _28
	HomeButtonLayout* mHomeButtonLayout;					   // _2C
	SystemWipeHolder* mSystemWipeHolder;					   // _30
	GameSystemDataHolder* mDataHolder;						   // _34
	bool mIsExecuteLoadSystemArchive;                          // _38
};

namespace NrvGameSystem {
	NERVE(GameSystemInitializeAudio);
	NERVE(GameSystemInitializeLogoScene);
	NERVE(GameSystemLoadStationedArchive);
	NERVE(GameSystemWaitForReboot);
	NERVE(GameSystemNormal);
};
