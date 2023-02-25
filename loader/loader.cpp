#include "loader.h"

/*
* Custom code will be loaded into SystemHeap. However, the space that it provides is very limited, so the heaps need to
* be expanded early on during the game's initialization process. By default, SystemHeap has enough space to fit more
* than 80 KB of custom code (including .text and .bss from the CustomCode binaries). If our code requires more space,
* the loader will expand SystemHeap's memory by taking away some from HeapNapa/SceneHeapNapa.
*/
#define CUSTOM_CODE_EXPANSION_KB 80

namespace {
	/*****************************************************************************************************************/
	/* Enable crash debugger                                                                                         */
	/*****************************************************************************************************************/
#if defined(TWN) || defined(KOR)
	kmWrite32(0x804B7E00, 0x60000000);
	kmWrite32(0x804B7EC4, 0x60000000);
	kmWrite32(0x805B64A8, 0x60000000);
	kmWrite32(0x805B67B4, 0x60000000);
#else
	kmWrite32(0x804B7D90, 0x60000000);
	kmWrite32(0x804B7E54, 0x60000000);
	kmWrite32(0x805B63A8, 0x60000000);
	kmWrite32(0x805B66B4, 0x60000000);
#endif


	/*****************************************************************************************************************/
	/* Adjust heaps to fit more custom code                                                                          */
	/*****************************************************************************************************************/
	u32 getSystemHeapSize() {
		u32 expandKB = CUSTOM_CODE_EXPANSION_KB;

		if (expandKB < 80) {
			return 0x40000;
		}
		else {
			return 0x40000 + (expandKB - 80) * 1000;
		}
	}

#if defined(TWN) || defined(KOR)
	kmCall(0x804BCED8, getSystemHeapSize);
#else
	kmCall(0x804BCE68, getSystemHeapSize);
#endif

	u32 getStationedHeapNapaSize(JKRHeap *pHeap, int allocArg) {
		u32 allocatableSize = pHeap->getMaxAllocatableSize(allocArg);
		u32 expandKB = CUSTOM_CODE_EXPANSION_KB;

		if (expandKB < 80) {
			allocatableSize -= 5242880;
		}
		else {
			allocatableSize -= (5242880 - (expandKB - 80) * 1000);
		}

		return allocatableSize;
	}

#if defined(TWN) || defined(KOR)
	kmCall(0x804BCF40, getStationedHeapNapaSize);
	kmWrite32(0x804BCF44, 0x7C7F1B78);
#else
	kmCall(0x804BCED0, getStationedHeapNapaSize);
	kmWrite32(0x804BCED4, 0x7C7F1B78);
#endif


	/*****************************************************************************************************************/
	/* Load and link code from CustomCode binary                                                                     */
	/*****************************************************************************************************************/
#if defined(TWN) || defined(KOR)
	kmBranch(0x804B7DA8, syati_LoadCustomCode);
#else
	kmBranch(0x804B7D38, syati_LoadCustomCode);
#endif

	void syati_LoadCustomCode() {
		OSReport("SYATI_INIT\n");

		u32 fg = 0xFFFFFFFF;
		u32 bg = 0x00000000;


		// ------------------------------------------------------------------------------------------------------------
		// Create handle & check file

		DVDFileInfo fileHandle;
		int pathID = DVDConvertPathToEntrynum(KAMEK_BINARY_NAME);

		if (pathID < 0) {
			OSFatal(&fg, &bg, "SYA_ERR\n\nCan't locate CustomCode binary\n");
		}

		if (!DVDFastOpen(pathID, &fileHandle)) {
			OSFatal(&fg, &bg, "SYA_ERR\n\nCan't create file handle\n");
		}

		if (fileHandle.mLength < sizeof(KamekHeader)) {
			OSFatal(&fg, &bg, "SYA_ERR\n\nBinary too small\n");
		}


		// ------------------------------------------------------------------------------------------------------------
		// Read temporary binary file and close handle

		// This is... questionable. Allocating memory on a heap and freeing it later on doesn't seem to work on console
		u8* binary = (u8*)(((u32)SingletonHolder<HeapMemoryWatcher>::sInstance->mHeapNapa + 0x200 + 31) & ~31);
		u32 binarySize = fileHandle.mLength;
		KamekHeader* kamekHeader = (KamekHeader*)binary;

		DVDReadPrio(&fileHandle, binary, binarySize, 0, 2);
		DVDClose(&fileHandle);


		// ------------------------------------------------------------------------------------------------------------
		// Verify Kamek format & get info from header

		if (kamekHeader->magic1 != 'Kame' || kamekHeader->magic2 != 'k\0') {
			OSFatal(&fg, &bg, "SYA_ERR\n\nInvalid header\n");
		}
		if (kamekHeader->version != 1) {
			OSFatal(&fg, &bg, "SYA_ERR\n\nIncompatible version\n");
		}

		u32 codeSize = kamekHeader->codeSize;
		u32 bssSize = kamekHeader->bssSize;


		// ------------------------------------------------------------------------------------------------------------
		// Allocate text & BSS memory

		u32 customCodeSize = codeSize + bssSize;
		u8* customCodeLinked = new (JKRHeap::sSystemHeap, 4) u8[customCodeSize];


		// ------------------------------------------------------------------------------------------------------------
		// Copy text and clear BSS

		u8* codeStart = customCodeLinked;
		u8* codeEnd = customCodeLinked + codeSize;
		u8* bssStart = codeEnd;
		u8* bssEnd = bssStart + bssSize;

		u8* srcPtr = binary + sizeof(KamekHeader);

		while (codeStart < codeEnd) {
			*codeStart++ = *srcPtr++;
		}

		while (bssStart < bssEnd) {
			*bssStart++ = 0;
		}

		OSReport("Patch addr = %p, size = %d\n", customCodeLinked, customCodeSize);


		// ------------------------------------------------------------------------------------------------------------
		// Linking

		u32 linkingSize = binarySize - sizeof(KamekHeader) - codeSize;
		syati_RuntimeLink(customCodeLinked, customCodeSize, srcPtr, linkingSize);


		// ------------------------------------------------------------------------------------------------------------
		// Clear temporary binary

		u8* srcEnd = binary + binarySize;

		while (binary < srcEnd) {
			*binary++ = 0;
		}
	}


	/*****************************************************************************************************************/
	/* Runtime linking                                                                                               */
	/*****************************************************************************************************************/
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


	void syati_RuntimeLink(u8 *linkedBuffer, u32 linkedSize, u8 *kamekBuffer, u32 kamekSize) {
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
				OSReport("SYATI -- Unknown command: %d\n", cmd);
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
}
