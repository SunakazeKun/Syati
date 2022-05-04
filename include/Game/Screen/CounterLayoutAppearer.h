#pragma once

#include "revolution.h"
#include "Game/Screen/LayoutActor.h"
#include "Game/System/NerveExecutor.h"

class CounterLayoutAppearer : public NerveExecutor {
public:
	CounterLayoutAppearer(LayoutActor *pHost, const TVec2f &);

	virtual ~CounterLayoutAppearer();

	void appear(const TVec2f &);
	void disappear();
	bool isAppeared() const;
	bool isDisappeared() const;
	void reset();
	void updateLayoutOffset(f32);
	void exeAppear();
	void exeDisappear();

	LayoutActor* mHost; // _8
	TVec2f _C;
	TVec2f _14;
	TVec2f _1C;
};

namespace NrvCounterLayoutAppearer {
	NERVE(CounterLayoutAppearerNrvHide);
	NERVE(CounterLayoutAppearerNrvAppear);
	NERVE(CounterLayoutAppearerNrvShow);
	NERVE(CounterLayoutAppearerNrvDisappear);
};
