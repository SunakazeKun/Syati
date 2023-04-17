#pragma once

#include "Game/Player/GhostPacketData.h"

/* FINISHED */

class GhostPacketReader {
public:
    GhostPacketReader();

    void setSource(const void *pData, size_t size);
    void read(GhostPacketData *pGhostPacketData);

    const u8* mDataStart;
    const u8* mCurDataPtr;
    size_t mDataSize;
};

namespace MR {
    GhostPacketReader* createGhostPacketReader(const char *pFileName);
};
