#pragma once

#include "revolution.h"

namespace MR {
	u8 getDecidedLanguageFromIPL();
	int getLanguage();
	u8 getLanguageFromIPL();
	const char* getCurrentLanguagePrefix();
	const char* getCurrentRegionPrefix();
	u32 getLanguageNum();
	const char* getLanguagePrefixByIndex(u32);
};
