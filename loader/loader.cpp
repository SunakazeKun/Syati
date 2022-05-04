#include "loader.h"

namespace syati {
    // Crash debugger patch
    kmWrite32(0x804B7D90, 0x60000000);
    kmWrite32(0x804B7E54, 0x60000000);
    kmWrite32(0x805B66B4, 0x60000000);

    void init() {
        OSReport("SYATI -- Initializing binary '%s'\n", KAMEK_BINARY_NAME);

        u32 fg = 0xFFFFFFFF;
        u32 bg = 0x00000000;
        u8 headerBuffer[32];
        KamekHeader* kamekHeader = (KamekHeader*)&headerBuffer;
        DVDFileInfo fileHandle;


        // 1 -- Verify that file exists and create file handle
        s32 pathID = DVDConvertPathToEntrynum(KAMEK_BINARY_NAME);

        if (pathID < 0) {
            OSFatal(&fg, &bg, "SYATI -- ERROR\n\nFailed to locate binary file '%s'\n", KAMEK_BINARY_NAME);
        }

        if (!DVDFastOpen(pathID, &fileHandle)) {
            OSFatal(&fg, &bg, "SYATI -- ERROR\n\nFailed to create file handle for '%s'\n", KAMEK_BINARY_NAME);
        }

        OSReport("SYATI -- Binary located: faddr = %p, fsize = %d\n", fileHandle.mStartAddr, fileHandle.mLength);


        // 2 -- Verify Kamek header is correct
        DVDReadPrio(&fileHandle, headerBuffer, 32, 0, 2);

        if (kamekHeader->magic1 != 'Kame' || kamekHeader->magic2 != 'k\0') {
            OSFatal(&fg, &bg, "SYATI -- ERROR\n\nBinary appears to be corrupted!\n");
        }
        if (kamekHeader->version != 1) {
            OSFatal(&fg, &bg, "SYATI -- ERROR\n\nIncompatible version %d!", kamekHeader->version);
        }

        OSReport("SYATI -- Kamek header: codeSize = %d, bssSize = %d\n", kamekHeader->codeSize, kamekHeader->bssSize);


        // 3 -- Preload contents
        JKRHeap *heap = MR::getStationedHeapNapa();
        u32 linkedSize = kamekHeader->codeSize + kamekHeader->bssSize;
        u32 kamekSize = fileHandle.mLength - sizeof(KamekHeader) - kamekHeader->codeSize;
        u8 *linkedBuffer = new (heap, 32) u8[linkedSize];
        u8 *kamekBuffer = new (heap, 32) u8[kamekSize];

        DVDReadPrio(&fileHandle, linkedBuffer, kamekHeader->codeSize, sizeof(KamekHeader), 2);
        DVDReadPrio(&fileHandle, kamekBuffer, kamekSize, sizeof(KamekHeader) + kamekHeader->codeSize, 2);
        DVDClose(&fileHandle);


        // 4 -- Clear BSS section
        u8* bssStart = linkedBuffer + kamekHeader->codeSize;
        u8* bssEnd = linkedBuffer + linkedSize;

        while (bssStart < bssEnd) {
            *bssStart++ = 0;
        }


        // 5 -- Link everything and delete linking information buffer
        link(linkedBuffer, linkedSize, kamekBuffer, kamekSize);
        delete kamekBuffer;


        OSReport("SYATI -- Initialization done!\n");
    }

    void link(u8 *linkedBuffer, u32 linkedSize, u8 *kamekBuffer, u32 kamekSize) {
        OSReport("SYATI -- Linked binary: addr = %p, size = %d\n", linkedBuffer, linkedSize);
        OSReport("SYATI -- Linking info (tmp): addr = %p, size = %d\n", kamekBuffer, kamekSize);

        u32 text = (u32)linkedBuffer;
        const u8* input = kamekBuffer;
        const u8* end = input + kamekSize;

        while (input < end) {
            u32 cmdHeader = *((u32 *)input);
            input += 4;

            u8 cmd = cmdHeader >> 24;
            u32 address = cmdHeader & 0xFFFFFF;
            if (address == 0xFFFFFE) {
                // Absolute address
                address = *((u32 *)input);
                input += 4;
            }
            else {
                // Relative address
                address += text;
            }

            switch (cmd) {
                kDispatchCommand(Addr32);
                kDispatchCommand(Addr16Lo);
                kDispatchCommand(Addr16Hi);
                kDispatchCommand(Addr16Ha);
                kDispatchCommand(Rel24);
                kDispatchCommand(Write32);
                kDispatchCommand(Write16);
                kDispatchCommand(Write8);
                kDispatchCommand(CondWritePointer);
                kDispatchCommand(CondWrite32);
                kDispatchCommand(CondWrite16);
                kDispatchCommand(CondWrite8);
                kDispatchCommand(Branch);
                kDispatchCommand(BranchLink);
            default:
                OSReport("Unknown command: %d\n", cmd);
            }

            register u32 cacheAddr = address;
            asm{
                dcbst r0, cacheAddr
                sync
                icbi r0, cacheAddr
            }
        }

        __sync();
        __isync();
    }

    kmBranch(0x80474E50, init);
}
