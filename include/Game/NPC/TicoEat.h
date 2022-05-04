#pragma once

#include "Game/NPC/Tico.h"

class TicoEat : public Tico {
public:
	TicoEat(const char *pName);

	virtual ~TicoEat();
	virtual void control();
	virtual bool receiveMsgPlayerAttack(u32, HitSensor *, HitSensor *);
	virtual void startReactionSound();

	void initStarPiece(s32);
	bool tryEat();
	bool hasEnoughStarPiece() const;
	bool eventFunc(u32);
	void exeReaction();
	void exeEatPre();
	void exeEatNow();
	void exeEatPst();

	u32 _1AC;
	u32 _1B0;
	u32 _1B4;
};

namespace NrvTicoEat {
	NERVE(TicoEatNrvEatPre);
	NERVE(TicoEatNrvEatNow);
	NERVE(TicoEatNrvEatPst);
	NERVE(TicoEatNrvEatEnd);
	NERVE(TicoEatNrvEatReaction);
};
