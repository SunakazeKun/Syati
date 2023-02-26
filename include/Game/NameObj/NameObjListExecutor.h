#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObj.h"
#include "Game/Util/Functor.h"

/* FINISHED */

class DrawBufferHolder;
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
	s16 registerDrawBuffer(LiveActor *pActor, int drawType);
	void allocateDrawBufferActorList();
	void registerPreDrawFunction(const MR::FunctorBase &rPreDrawFunc, int drawType);
	bool isRegisteredDrawFunction(int drawType) const;
	void findLightInfo(LiveActor *pActor, int drawBufferType, int drawBufferIndex) const;
	void incrementCheckMovement(NameObj *pObj, int movementType);
	void incrementCheckCalcAnim(NameObj *pObj, int calcAnimType);
	void incrementCheckDraw(NameObj *pObj, int drawType);
	void addToMovement(NameObj *pObj, int movementType);
	void addToCalcAnim(NameObj *pObj, int calcAnimType);
	void addToDrawBuffer(LiveActor *pObj, int drawBufferType, int drawBufferIndex);
	void addToDraw(NameObj *pObj, int drawType);
	void removeToMovement(NameObj *pObj, int movementType);
	void removeToCalcAnim(NameObj *pObj, int calcAnimType);
	void removeToDrawBuffer(LiveActor *pObj, int drawBufferType, int drawBufferIndex);
	void removeToDraw(NameObj *pObj, int drawType);
	void executeMovement(int movementType);
	void executeCalcAnim(int calcAnimType);
	void entryDrawBuffer2D();
	void entryDrawBuffer3D();
	void entryDrawBufferMirror();
	void entryDrawBufferWorldMapBig();
	void entryDrawBufferWorldMapSmall();
	void drawOpa(int drawBufferType);
	void drawXlu(int drawBufferType);
	void executeDraw(int drawType);

	DrawBufferHolder* mBufferHolder;    // _4
	NameObjCategoryList* mMovementList; // _8
	NameObjCategoryList* mCalcAnimList; // _C
	NameObjCategoryList* mDrawList;     // _10
};
