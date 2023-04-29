#include "loader.h"

/*
* Custom code will be loaded into SystemHeap. However, the space that it provides is very limited, so the heaps need to
* be expanded early on during the game's initialization process. By default, SystemHeap has enough space to fit more
* than 80 KB of custom code (including .text and .bss from the CustomCode binaries). If our code requires more space,
* the loader will expand SystemHeap's memory by taking away some from HeapNapa/SceneHeapNapa.
*/

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
	/* Get size of CustomCode and expand SystemHeap if necessary                                                     */
	/*****************************************************************************************************************/
	static u32 sCustomCodeSize;

	void initCustomCodeSize() {
		DVDFileInfo fileHandle;
		int pathID = DVDConvertPathToEntrynum(KAMEK_BINARY_NAME);

		if (pathID < 0) {
			sCustomCodeSize = 0;
			return;
		}

		if (!DVDFastOpen(pathID, &fileHandle)) {
			SyatiError("SYA_ERR\n\nCan't create file handle\n");
		}

		if (fileHandle.mLength < 32) {
			SyatiError("SYA_ERR\n\nBinary too small\n");
		}

		u8 tempBuffer[ALIGN_32(sizeof(KamekHeader)) * 2];
		KamekHeader *header = (KamekHeader*)ALIGN_32((u32)tempBuffer);

		DVDReadPrio(&fileHandle, header, 32, 0, 2);
		DVDClose(&fileHandle);

		sCustomCodeSize = ALIGN_32(header->codeSize + header->bssSize);
	}

	void getCustomCodeSizeAndCreateHeaps(HeapMemoryWatcher *heapWatcher) {
		initCustomCodeSize();
		heapWatcher->createHeaps();
	}

#if defined(TWN) || defined(KOR)
	kmCall(0x804BD058, getCustomCodeSizeAndCreateHeaps);
#else
	kmCall(0x804BCFE8, getCustomCodeSizeAndCreateHeaps);
#endif


	// ----------------------------------------------------------------------------------------------------------------
	// Create SystemHeap with adjusted size

	JKRHeap* createSystemHeap(u32 size, JKRHeap *root, bool allocArg) {
		if (sCustomCodeSize > 81920) {
			size += (sCustomCodeSize - 81920);
		}

		return HeapMemoryWatcherFunction::createExpHeap(size, root, allocArg);
	}

#if defined(TWN) || defined(KOR)
	kmCall(0x804BCEE0, createSystemHeap);
#else
	kmCall(0x804BCE70, createSystemHeap);
#endif


	// ----------------------------------------------------------------------------------------------------------------
	// Get proper size for StationedHeapNapa

	u32 getStationedHeapNapaSize(JKRHeap *pHeap, int allocArg) {
		u32 allocatableSize = pHeap->getMaxAllocatableSize(allocArg);

		if (sCustomCodeSize < 81920) {
			allocatableSize -= 5242880;
		}
		else {
			allocatableSize -= (5242880 - (sCustomCodeSize - 81920));
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
	kmBranch(0x804B7DA8, SyatiInit);
#else
	kmBranch(0x804B7D38, SyatiInit);
#endif

	void SyatiInit() {
		if (sCustomCodeSize == 0) {
			return;
		}

		OSReport("SYATI_INIT\n");


		// ------------------------------------------------------------------------------------------------------------
		// Create handle & check file

		DVDFileInfo fileHandle;
		int pathID = DVDConvertPathToEntrynum(KAMEK_BINARY_NAME);

		if (!DVDFastOpen(pathID, &fileHandle)) {
			SyatiError("SYA_ERR\n\nCan't create file handle\n");
		}


		// ------------------------------------------------------------------------------------------------------------
		// Read temporary binary file and close handle

		// This is... questionable. Allocating memory on a heap and freeing it later on doesn't seem to work properly
		// on console. However, GameHeapNapa gets destroyed very often, so this is actually very reliable.
		u8* binary = (u8*)ALIGN_32((u32)SingletonHolder<HeapMemoryWatcher>::sInstance->mHeapNapa + 0x200);
		u32 binarySize = fileHandle.mLength;
		KamekHeader* kamekHeader = (KamekHeader*)binary;

		DVDReadPrio(&fileHandle, binary, binarySize, 0, 2);
		DVDClose(&fileHandle);


		// ------------------------------------------------------------------------------------------------------------
		// Verify Kamek format & get info from header

		if (kamekHeader->magic1 != 'Kame' || kamekHeader->magic2 != 'k\0') {
			SyatiError("SYA_ERR\n\nInvalid header\n");
		}
		if (kamekHeader->version != 1) {
			SyatiError("SYA_ERR\n\nIncompatible version\n");
		}

		u32 codeSize = kamekHeader->codeSize;
		u32 bssSize = kamekHeader->bssSize;


		// ------------------------------------------------------------------------------------------------------------
		// Allocate text & BSS memory

		u8* customCodeLinked = new (JKRHeap::sSystemHeap, 4) u8[sCustomCodeSize];


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

		OSReport("Patch addr = %p, size = %d\n", customCodeLinked, sCustomCodeSize);


		// ------------------------------------------------------------------------------------------------------------
		// Linking

		u32 linkingSize = binarySize - sizeof(KamekHeader) - codeSize;
		SyatiLink(customCodeLinked, sCustomCodeSize, srcPtr, linkingSize);


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

	void SyatiLink(u8 *linkedBuffer, u32 linkedSize, u8 *kamekBuffer, u32 kamekSize) {
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


	/*****************************************************************************************************************/
	/*Helper functions                                                                                               */
	/*****************************************************************************************************************/
	void SyatiError(const char *msg) {
		u32 fg = 0xFFFFFFFF;
		u32 bg = 0x00000000;
		OSFatal(&fg, &bg, msg);
	}
}
