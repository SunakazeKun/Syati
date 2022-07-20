#ifndef __REVOLUTION_OS_H
#define __REVOLUTION_OS_H

#include "revolution/types.h"
#include "c_stdlib.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
* Debug API
*/
void OSPanic(const char *file, int line, const char *msg, ...);
void OSReport(const char *msg, ...);
void OSVReport(const char *msg, va_list list);
void OSFatal(u32 *fg, u32 *bg, const char *msg, ...);

/*
* Application info API
*/
#define OS_APP_TYPE_WC24 0x20
#define OS_APP_TYPE_IPL 0x40
#define OS_APP_TYPE_DVD 0x80
#define OS_APP_TYPE_NAND 0x81

const char* OSGetAppGamename();
const u8 OSGetAppType();

/*
* Arena API
*/
void* OSGetMEM1ArenaHi();
void* OSGetMEM1ArenaLo();
void OSSetMEM1ArenaHi(void *newHi);
void OSSetMEM1ArenaLo(void *newLo);

void* OSGetMEM2ArenaHi();
void* OSGetMEM2ArenaLo();
void OSSetMEM2ArenaHi(void *newHi);
void OSSetMEM2ArenaLo(void *newLo);

void* OSAllocFromMEM1ArenaLo(u32 size, u32 align);
void* OSAllocFromMEM1ArenaHi(u32 size, u32 align);
void* OSAllocFromMEM2ArenaLo(u32 size, u32 align);
void* OSAllocFromMEM2ArenaHi(u32 size, u32 align);

void* OSGetArenaHi();
void* OSGetArenaLo();
void OSSetArenaHi(void *newHi);
void OSSetArenaLo(void *newLo);

/*
* Basic OS API
*/
void OSInit();
u32 OSGetConsoleType();
void OSRegisterVersion(const char *id);

/*
* Interrupt API
*/
bool OSDisableInterrupts();
bool OSEnableInterrupts();
bool OSRestoreInterrupts(bool level);
bool OSIsEnableInterrupts();

/*
* Real-time clock API
*/
u32 OSGetTick();
s64 OSGetTime();

#ifdef __cplusplus
}
#endif

#endif // __REVOLUTION_OS_H
