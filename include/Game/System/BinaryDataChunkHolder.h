#pragma once

#include "revolution.h"

class BinaryDataChunkBase {
public:
	inline BinaryDataChunkBase();

	virtual u32 makeHeaderHashCode() const = 0;
	virtual u32 getSignature() const = 0;
	virtual void serialize(u8 *, u32) const = 0;
	virtual void deserialize(const u8 *, u32) const = 0;
	virtual void initializeData() = 0;
};
