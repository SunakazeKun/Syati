#pragma once

#include "revolution.h"

namespace MR {
    // More functions before this
    void copyString(char *pDest, const char *pSrc, u32 length);
    void copyString(wchar_t *pDest, const wchar_t *pSrc, u32 length);
    wchar_t* addPictureFontCode(wchar_t *pDest, int pictureId);
    wchar_t* addNewLine(wchar_t *pDest);
    const char * getBaseName(const char *pString);
    void removeExtensionString(char *pDest, u32 length, const char *pSrc);
    void extractString(char *pDest, const char *pSrc, u32, u32);
    void convertUTF16ToASCII(char *pDest, const wchar_t *pSrc, s32 length);
    int strcasecmp(const char *pStringA, const char *pStringB);
    bool isEqualString(const char *pStringA, const char *pStringB);
    bool isEqualStringCase(const char *pStringA, const char *pStringB);
    bool isEqualSubString(const char *pStringA, const char *pStringB);
    bool hasStringSpace(const char *pString);
    bool isDigitStringTail(const char *pString, int);
    // isExistString
    bool isNullOrEmptyString(const char *pString);
    bool isMessageEditorNextTag(const wchar_t *pString);
    s32 getStringLengthWithMessageTag(const wchar_t *pString);
    void scan32(const char *pString, const char *pField, s32 *pDest);
    void scanf32(const char *pString, const char *pField, f32 *pDest);
    void scanu8x4(const char *pString, const char *pField, u8 *pDest);
    void scanf32x4(const char *pString, const char *pField, f32 *pDest);
};
