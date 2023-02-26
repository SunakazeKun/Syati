#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObj.h"
#include "Game/Util/Functor.h"

/* FINISHED */

class NameObjAdaptor : public NameObj {
public:
	NameObjAdaptor(const char *pName);

	virtual ~NameObjAdaptor();
	virtual void movement();
	virtual void draw();
	virtual void calcAnim();
	virtual void calcViewAndEntry();

	void connectToMovement(const MR::FunctorBase &rFunc);
	void connectToCalcAnim(const MR::FunctorBase &rFunc);
	void connectToDraw(const MR::FunctorBase &rFunc);
	
	MR::FunctorBase* mMovementFunctor;         // _14
	MR::FunctorBase* mCalcAnimFunctor;         // _18
	MR::FunctorBase* mCalcViewAndEntryFunctor; // _1C
	MR::FunctorBase* mDrawFunctor;             // _20
};
