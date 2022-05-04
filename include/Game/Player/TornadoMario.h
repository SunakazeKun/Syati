#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class TornadoMario : public LiveActor {
public:
	TornadoMario(const char *);

	virtual ~TornadoMario();
	virtual void init(const JMapInfoIter &);
	virtual void calcAnim();
	virtual void control();
	virtual void calcAndSetBaseMtx();

	void show();
	void hide();
	void hideForce();
	void setTrHeight(const TVec3f &, const TVec3f &, const TVec3f &, const TVec3f &);

	bool _90; // unused
	bool mIsShown; // _91
	bool _92; // unused
	u8 _94[12]; // unused
	TVec3f _A0;
	TVec3f _AC;
};
