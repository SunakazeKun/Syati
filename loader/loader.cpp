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
kmBranch(0x804B7DA8, syati::LoaderMain);
#else
kmWrite32(0x804B7D90, 0x60000000);
kmWrite32(0x804B7E54, 0x60000000);
kmWrite32(0x805B63A8, 0x60000000); // thanks Hackio
kmWrite32(0x805B66B4, 0x60000000);

// Entry point
kmBranch(0x804B7D38, syati::LoaderMain);
#endif


/**********************************************************************************************************************/
/* Initialization                                                                                                     */
/**********************************************************************************************************************/
namespace syati {
	void LoaderMain() {
		OSReport("SYATI -- Initializing binary\n");

		// 1 -- Load the binary and load it into memory
		void *binary;
		u32 size;

		LoaderOpenBinary(&binary, &size, KAMEK_BINARY_NAME);
		LoaderVerifyHeader((KamekHeader*)binary);

		// 2 -- Allocate patch block and link custom code into the game
		u8 *patchBuffer, *linkingInfo;
		u32 patchSize, linkingSize;
		LoaderAllocatePatch(binary, size, &patchBuffer, &patchSize, &linkingInfo, &linkingSize);
		LoaderRuntimeLink(patchBuffer, patchSize, linkingInfo, linkingSize);

		// 3 -- Clear the temporary binary data
		LoaderCloseBinary(binary, size);

		OSReport("SYATI -- Initialization done!\n");
	}

	void LoaderOpenBinary(void **binaryPtr, u32 *sizePtr, const char *binaryName) {
		DVDFileInfo fileHandle;

		// Setup OSFatal colors
		u32 fg = 0xFFFFFFFF;
		u32 bg = 0x00000000;

		// Verify that file exists and create file handle
		int pathID = DVDConvertPathToEntrynum(binaryName);

		if (pathID < 0) {
			OSFatal(&fg, &bg, "SYATI -- ERROR\n\nFailed to locate %s\n", binaryName);
		}

		if (!DVDFastOpen(pathID, &fileHandle)) {
			OSFatal(&fg, &bg, "SYATI -- ERROR\n\nFailed to create file handle for %s\n", binaryName);
		}

		OSReport("SYATI -- File handle: faddr = %p, fsize = %d\n", fileHandle.mStartAddr, fileHandle.mLength);

		// Read entire binary into MEM2
		u32 size = fileHandle.mLength;
		void* rawBinary = (void*)(RAW_BINARY_ADDRESS_END - ((size + 31) & ~31));

		DVDReadPrio(&fileHandle, rawBinary, fileHandle.mLength, 0, 2);
		DVDClose(&fileHandle);

		OSReport("SYATI -- Raw binary at %p (MEM2 arena)\n", rawBinary);

		// Return data
		*binaryPtr = rawBinary;
		*sizePtr = size;
	}

	void LoaderCloseBinary(void *binary, u32 size) {
		u32 *start = (u32*)binary;

		while (start < (u32*)RAW_BINARY_ADDRESS_END) {
			*start++ = 0;
		}
	}

	void LoaderVerifyHeader(KamekHeader *header) {
		// Setup OSFatal colors
		u32 fg = 0xFFFFFFFF;
		u32 bg = 0x00000000;


		// Verify magic and version
		if (header->magic1 != 'Kame' || header->magic2 != 'k\0') {
			OSFatal(&fg, &bg, "SYATI -- ERROR\n\nBinary appears to be corrupted!\n");
		}
		if (header->version != 1) {
			OSFatal(&fg, &bg, "SYATI -- ERROR\n\nIncompatible version %d!", header->version);
		}

		OSReport("SYATI -- Patch details: codeSize = %d, bssSize = %d\n", header->codeSize, header->bssSize);
	}

	void LoaderAllocatePatch(void *binary, u32 size, u8 **patchBufferPtr, u32 *patchSizePtr, u8 **linkingInfoPtr, u32 *linkingSizePtr) {
		KamekHeader *header = (KamekHeader*)binary;

		// Setup OSFatal colors
		u32 fg = 0xFFFFFFFF;
		u32 bg = 0x00000000;

		// Precalculations and allocation of patch memory
		u32 patchSize = header->codeSize + header->bssSize;
		u32 linkingSize = size - sizeof(KamekHeader) - header->codeSize;

		u8 *patchBuffer = new (JKRHeap::sSystemHeap, 32) u8[patchSize];
		u8 *linkingInfo = (u8*)binary + sizeof(KamekHeader) + header->codeSize;

		if (!patchBuffer) {
			OSFatal(&fg, &bg, "SYATI -- ERROR\n\nOut of memory for patch.");
		}

		// Copy code from binary and clear BSS section
		u8 *codeStart = patchBuffer;
		u8 *codeEnd = patchBuffer + header->codeSize;
		u8 *codeSrc = (u8*)binary + sizeof(KamekHeader);

		while (codeStart < codeEnd) {
			*codeStart++ = *codeSrc++;
		}

		u8 *bssStart = patchBuffer + header->codeSize;
		u8 *bssEnd = patchBuffer + patchSize;

		while (bssStart < bssEnd) {
			*bssStart++ = 0;
		}

		// Return data
		*patchBufferPtr = patchBuffer;
		*patchSizePtr = patchSize;
		*linkingInfoPtr = linkingInfo;
		*linkingSizePtr = linkingSize;
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


	void LoaderRuntimeLink(u8 *linkedBuffer, u32 linkedSize, u8 *kamekBuffer, u32 kamekSize) {
		OSReport("SYATI -- Patch block: addr = %p, size = %d\n", linkedBuffer, linkedSize);
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
