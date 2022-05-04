#pragma once

#include "revolution.h"
#include "Game/Map/HitInfo.h"

class FloorCode {
public:
	FloorCode();

	s32 getCode(const Triangle *);
};
