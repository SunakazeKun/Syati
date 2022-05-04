#pragma once

#include "revolution.h"

namespace nw4r {
	namespace ut {
		class CharStrmReader {
		public:
			typedef u16(CharStrmReader::*CharStrmReaderFunc)();

			u16 ReadNextCharUTF8();
			u16 ReadNextCharUTF16();
			u16 ReadNextCharCP1252();
			u16 ReadNextCharSJIS();

			const void* mCharStream;            // _0
			const CharStrmReaderFunc mReadFunc; // _4
		};
	};
};
