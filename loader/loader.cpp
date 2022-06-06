#include "loader.h"


/**********************************************************************************************************************/
/* Entry point and crash debugger patches                                                                             */
/**********************************************************************************************************************/
#if defined(TWN) || defined(KOR)
	kmWrite32(0x804B7E00, 0x60000000);
	kmWrite32(0x804B7EC4, 0x60000000);
	kmWrite32(0x805B64A8, 0x60000000); // thanks Hackio
	kmWrite32(0x805B67B4, 0x60000000);

	// Entry point
	kmBranch(0x804B7DA8, init);
#else
	kmWrite32(0x804B7D90, 0x60000000);
	kmWrite32(0x804B7E54, 0x60000000);
	kmWrite32(0x805B63A8, 0x60000000); // thanks Hackio
	kmWrite32(0x805B66B4, 0x60000000);

	// Entry point
	kmBranch(0x804B7D38, init);
#endif


/**********************************************************************************************************************/
/* Initialization                                                                                                     */
/**********************************************************************************************************************/
void init() {
	OSReport("SYATI -- Initializing binary '%s'\n", KAMEK_BINARY_NAME);

	u32 fg = 0xFFFFFFFF;
	u32 bg = 0x00000000;
	DVDFileInfo fileHandle;


	// 1 -- Verify that file exists and create file handle
	int pathID = DVDConvertPathToEntrynum(KAMEK_BINARY_NAME);

	if (pathID < 0) {
		OSFatal(&fg, &bg, "SYATI -- ERROR\n\nFailed to locate binary file '%s'\n", KAMEK_BINARY_NAME);
	}

	if (!DVDFastOpen(pathID, &fileHandle)) {
		OSFatal(&fg, &bg, "SYATI -- ERROR\n\nFailed to create file handle for '%s'\n", KAMEK_BINARY_NAME);
	}

	OSReport("SYATI -- Binary located: faddr = %p, fsize = %d\n", fileHandle.mStartAddr, fileHandle.mLength);


	// 2 -- Read entire binary
	JKRHeap* heap = JKRHeap::sSystemHeap;
	u32 alignedBinarySize = (fileHandle.mLength + 0x1F) & ~0x1F;
	u8* binary = new (JKRHeap::sSystemHeap, 32) u8[alignedBinarySize];

	if (!binary) {
		OSFatal(&fg, &bg, "SYATI -- ERROR\n\nOut of memory for binary.");
	}

	DVDReadPrio(&fileHandle, binary, alignedBinarySize, 0, 2);
	DVDClose(&fileHandle);


	// 3 -- Verify header
	KamekHeader* kamekHeader = (KamekHeader*)binary;

	if (kamekHeader->magic1 != 'Kame' || kamekHeader->magic2 != 'k\0') {
		OSFatal(&fg, &bg, "SYATI -- ERROR\n\nBinary appears to be corrupted!\n");
	}
	if (kamekHeader->version != 1) {
		OSFatal(&fg, &bg, "SYATI -- ERROR\n\nIncompatible version %d!", kamekHeader->version);
	}

	OSReport("SYATI -- Kamek header: codeSize = %d, bssSize = %d\n", kamekHeader->codeSize, kamekHeader->bssSize);


	u32 codeSize = kamekHeader->codeSize;
	u32 bssSize = kamekHeader->bssSize;
	u32 linkedSize = codeSize + bssSize;
	u32 kamekSize = fileHandle.mLength - sizeof(KamekHeader) - codeSize;

	u8 *linkedBuffer = new (JKRHeap::sSystemHeap, 32) u8[linkedSize];
	u8 *kamekBuffer = binary + sizeof(KamekHeader) + codeSize;

	if (!linkedBuffer) {
		OSFatal(&fg, &bg, "SYATI -- ERROR\n\nOut of memory for code.");
	}


	// 4 -- Copy code from binary and clear BSS section
	u8 *codeStart = linkedBuffer;
	u8 *codeEnd = linkedBuffer + codeSize;
	u8 *codeSrc = binary + sizeof(KamekHeader);

	while (codeStart < codeEnd) {
		*codeStart++ = *codeSrc++;
	}

	u8 *bssStart = linkedBuffer + codeSize;
	u8 *bssEnd = linkedBuffer + linkedSize;

	while (bssStart < bssEnd) {
		*bssStart++ = 0;
	}


	// 5 -- Link everything and delete binary buffer
	link(linkedBuffer, linkedSize, kamekBuffer, kamekSize);
	JKRHeap::free(binary, heap);

	OSReport("SYATI -- Initialization done!\n");
}


/**********************************************************************************************************************/
/* Runtime linking                                                                                                    */
/**********************************************************************************************************************/
static inline u32 resolveAddress(u32 text, u32 address) {
	return address & 0x80000000 ? address : (text + address);
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
		} else {
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
				OSReport("SYATI -- Unknown command: %d\n", cmd);
		}
		
		register u32 cacheAddr = address;
		asm {
			dcbst r0, cacheAddr
			sync
			icbi r0, cacheAddr
		}
	}

	__sync();
	__isync();
}
