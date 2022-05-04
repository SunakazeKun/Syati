#pragma once

#include "revolution.h"
#include "Game/System/NerveExecutor.h"
#include "Game/Scene/SceneNameObjListExecutor.h"
#include "Game/Scene/SceneObjHolder.h"

class Scene : public NerveExecutor {
public:
	Scene(const char *pName);

	virtual ~Scene();
	virtual void init();
	virtual void start();
	virtual void update() const;
	virtual void calcAnim();

	void initNameObjListExecutor();
	void initSceneObjHolder();

	SceneNameObjListExecutor* mNameObjListExecutor; // _8
	s32 _C; // unused?
	SceneObjHolder* mSceneObjHolder; // _10
};
