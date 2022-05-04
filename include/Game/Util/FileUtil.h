#pragma once

#include "revolution.h"
#include "JSystem.h"

namespace MR {
    bool isFileExist(const char *, bool);

    // int should be JKRDvdRipper::EAllocDirection but whatever
    JKRArchive* loadToMainRAM(const char *, u8 *, JKRHeap *, int);
    JKRArchive* mountArchive(const char *, JKRHeap *, bool);

    void* recieveFile(const char *);
    JKRArchive* mountAsyncArchive(const char *);
};
