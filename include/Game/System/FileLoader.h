#pragma once

#include "revolution.h"
#include "JSystem.h"
#include "JSystem/JKernel/JKRDvdRipper.h"

class FileHolder {
public:
    bool isExist(const char *) const;
};

class FileLoader {
public:
    JKRArchive* receiveArchive(const char *);

    void getMountedArchiveAndHeap(const char *, JKRArchive **, JKRHeap **);

    void requestMountArchive(const char *, JKRHeap *, bool);

    JKRArchive* createAndAddArchive(void *, JKRHeap *, const char *);
    void* receiveFile(const char*);
    void* requestLoadToMainRAM(const char*, unsigned char*, JKRHeap *, JKRDvdRipper::EAllocDirection, bool);

    u8 _0[0x24];
    FileHolder* mHolder; // _24
    ArchiveHolder* mArchiveHolder; // _28
};
