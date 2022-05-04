#pragma once

#include "syati.h"


#if defined(PAL)
#define KAMEK_BINARY_NAME "CustomCode/CustomCode_PAL.bin"
#elif defined(USA)
#define KAMEK_BINARY_NAME "CustomCode/CustomCode_USA.bin"
#elif defined(JAP)
#define KAMEK_BINARY_NAME "CustomCode/CustomCode_JAP.bin"
#elif defined(TWN)
#define KAMEK_BINARY_NAME "CustomCode/CustomCode_TWN.bin"
#elif defined(KOR)
#define KAMEK_BINARY_NAME "CustomCode/CustomCode_KOR.bin"
#endif

namespace syati {
	void init();
	void link(u8 *linkedBuffer, u32 linkedSize, u8 *kamekBuffer, u32 kamekSize);
};


struct KamekHeader {
    u32 magic1;
    u16 magic2;
    u16 version;
    u32 bssSize;
    u32 codeSize;
};

#define kAddr32 1
#define kAddr16Lo 4
#define kAddr16Hi 5
#define kAddr16Ha 6
#define kRel24 10
#define kWrite32 32
#define kWrite16 33
#define kWrite8 34
#define kCondWritePointer 35
#define kCondWrite32 36
#define kCondWrite16 37
#define kCondWrite8 38
#define kBranch 64
#define kBranchLink 65


static inline u32 resolveAddress(u32 text, u32 address) {
	return address & 0x80000000 ? address : text + address;
}


#define kCommandHandler(name) \
	static inline const u8 *kHandle##name(const u8 *input, u32 text, u32 address)
#define kDispatchCommand(name) \
	case k##name: input = kHandle##name(input, text, address); break

kCommandHandler(Addr32) {
	u32 target = resolveAddress(text, *(const u32 *)input);
	*(u32 *)address = target;
	return input + 4;
}
kCommandHandler(Addr16Lo) {
	u32 target = resolveAddress(text, *(const u32 *)input);
	*(u16 *)address = target & 0xFFFF;
	return input + 4;
}
kCommandHandler(Addr16Hi) {
	u32 target = resolveAddress(text, *(const u32 *)input);
	*(u16 *)address = target >> 16;
	return input + 4;
}
kCommandHandler(Addr16Ha) {
	u32 target = resolveAddress(text, *(const u32 *)input);
	*(u16 *)address = target >> 16;
	if (target & 0x8000)
		*(u16 *)address += 1;
	return input + 4;
}
kCommandHandler(Rel24) {
	u32 target = resolveAddress(text, *(const u32 *)input);
	u32 delta = target - address;
	*(u32 *)address &= 0xFC000003;
	*(u32 *)address |= (delta & 0x3FFFFFC);
	return input + 4;
}
kCommandHandler(Write32) {
	u32 value = *(const u32 *)input;
	*(u32 *)address = value;
	return input + 4;
}
kCommandHandler(Write16) {
	u32 value = *(const u32 *)input;
	*(u16 *)address = value & 0xFFFF;
	return input + 4;
}
kCommandHandler(Write8) {
	u32 value = *(const u32 *)input;
	*(u8 *)address = value & 0xFF;
	return input + 4;
}
kCommandHandler(CondWritePointer) {
	u32 target = resolveAddress(text, *(const u32 *)input);
	u32 original = ((const u32 *)input)[1];
	if (*(u32 *)address == original)
		*(u32 *)address = target;
	return input + 8;
}
kCommandHandler(CondWrite32) {
	u32 value = *(const u32 *)input;
	u32 original = ((const u32 *)input)[1];
	if (*(u32 *)address == original)
		*(u32 *)address = value;
	return input + 8;
}
kCommandHandler(CondWrite16) {
	u32 value = *(const u32 *)input;
	u32 original = ((const u32 *)input)[1];
	if (*(u16 *)address == (original & 0xFFFF))
		*(u16 *)address = value & 0xFFFF;
	return input + 8;
}
kCommandHandler(CondWrite8) {
	u32 value = *(const u32 *)input;
	u32 original = ((const u32 *)input)[1];
	if (*(u8 *)address == (original & 0xFF))
		*(u8 *)address = value & 0xFF;
	return input + 8;
}
kCommandHandler(Branch) {
	*(u32 *)address = 0x48000000;
	return kHandleRel24(input, text, address);
}
kCommandHandler(BranchLink) {
	*(u32 *)address = 0x48000001;
	return kHandleRel24(input, text, address);
}
