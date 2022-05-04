#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObj.h"
#include "Game/Util/Functor.h"

class LiveActor;
class NameObjCategoryList;

class NameObjListExecutor {
public:
	NameObjListExecutor();

	virtual ~NameObjListExecutor();
	virtual void initMovementList();
	virtual void initCalcAnimList();
	virtual void initCalcViewAndEntryList();
	virtual void initDrawList();

	void init();
	s16 registerDrawBuffer(LiveActor *, int);
	void allocateDrawBufferActorList();
	void registerPreDrawFunction(const MR::FunctorBase &, int);

	void findLightInfo(LiveActor *, int, int) const;
	void incrementCheckMovement(NameObj *, int);
	void incrementCheckCalcAnim(NameObj *, int);
	void incrementCheckDraw(NameObj *, int);
	void addToMovement(NameObj *, int);
	void addToCalcAnim(NameObj *, int);
	void addToDrawBuffer(LiveActor *, int, int);
	void addToDraw(NameObj *, int);
	void removeToMovement(NameObj *, int);
	void removeToCalcAnim(NameObj *, int);
	void removeToDrawBuffer(LiveActor *, int, int);
	void removeToDraw(NameObj *, int);
	void executeMovement(int);
	void executeCalcAnim(int);
	void entryDrawBuffer2D();
	void entryDrawBuffer3D();
	void entryDrawBufferMirror();

	void drawOpa(int);
	void drawXlu(int);
	void executeDraw(int);

	u32* mDrawBuffer; // _4; MR::Vector<AssignableArray<DrawBufferGroup>>
	NameObjCategoryList* mMovementList; // _8
	NameObjCategoryList* mCalcAnimList; // _C
	NameObjCategoryList* mDrawList; // _10
};
