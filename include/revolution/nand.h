#ifndef __REVOLUTION_NAND_H
#define __REVOLUTION_NAND_H

#include "revolution/types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define NAND_MAX_PATH          64
#define NAND_PERM_READ 0x10
#define NAND_PERM_WRITE 0x20
#define NAND_PERM_READ_WRITE (NAND_PERM_READ | NAND_PERM_WRITE)

#define NAND_MODE_READ 1
#define NAND_MODE_WRITE 2
#define NAND_MODE_RW (NAND_MODE_READ | NAND_MODE_WRITE)

typedef struct NANDFileInfo
{
    // Do not access below members.
    s32  fileDescriptor;
    s32  origFd;
    char origPath[NAND_MAX_PATH];
    char tmpPath[NAND_MAX_PATH];
    u8   accType;
    u8   stage;
    u8   mark;
    // 2 bytes padding
} NANDFileInfo;

s32 NANDOpen(char const*, NANDFileInfo*, u8);
s32 NANDGetLength(NANDFileInfo*, u32*);
s32 NANDCreate(const char*, u8, u8);
s32 NANDRead(NANDFileInfo*, void*, u32);
s32 NANDWrite(NANDFileInfo*, const void*, u32);
s32 NANDClose(NANDFileInfo*);
s32 NANDSeek(NANDFileInfo*, s32, s32);

#ifdef __cplusplus
}
#endif

#endif