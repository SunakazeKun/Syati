#pragma once

#include "revolution.h"

class Color8 {
public:
	Color8(u8 r, u8 g, u8 b, u8 a);

	void set(GXColor color);

	u8 r; // _0
	u8 g; // _1
	u8 b; // _2
	u8 a; // _3
};
