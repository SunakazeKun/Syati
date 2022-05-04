#pragma once

#include "JSystem/JKernel/JKRThread.h"

class JKRDecompCommand;

class JKRDecomp
{
public:
    JKRDecomp(s32);

    virtual ~JKRDecomp();
    virtual s32 run();

    static JKRDecomp* create(s32);

    static void decode(u8 *, u8 *, u32, u32);
    static void decodeSZP(u8 *, u8 *, u32, u32);
    static void decodeSZS(u8 *, u8 *, u32, u32);
    static s32 checkCompressed(u8 *);

    //static OSMessage sMessageBuffer;
    //static OSMessageQueue sMessageQueue;
};