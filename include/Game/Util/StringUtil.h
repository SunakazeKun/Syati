#pragma once

#include "revolution.h"

/* FINISHED */

namespace MR {
    void addFilePrefix(char *pDest, u32 size, const char *pFileName, const char *pPrefix);

    void makeDateString(wchar_t *pDest, s32 size, s32, s32, s32);
    void makeTimeString(wchar_t *pDest, s32 size, s32, s32, s32);
    void makePlayTimeString(wchar_t *pDest, s32 size, u32 playTime);
    void makeClearTimeString(wchar_t *pDest, u32 clearTime);
    void makeRaceBestTimeString(wchar_t *pDest, int raceIndex);
    void makeRaceCurrentTimeString(wchar_t *pDest);
    void makeHoursMinuteSecondString(wchar_t *pDest, u32 time);
    void makeMinuteAndSecondString(wchar_t *pDest, u32 time);

    void copyString(char *pDest, const char *pSrc, u32 length);
    void copyString(wchar_t *pDest, const wchar_t *pSrc, u32 length);

    wchar_t* addPictureFontCode(wchar_t *pDest, int pictureId);
    wchar_t* addNewLine(wchar_t *pDest);

    const char* getBaseName(const char *pString);
    void removeExtensionString(char *pDest, u32 length, const char *pSrc);
    void extractString(char *pDest, const char *pSrc, u32, u32);
    void convertUTF16ToASCII(char *pDest, const wchar_t *pSrc, s32 length);
    int strcasecmp(const char *pStringA, const char *pStringB);

    bool isEqualString(const char *pStringA, const char *pStringB);
    bool isEqualStringCase(const char *pStringA, const char *pStringB);
    bool isEqualSubString(const char *pStringA, const char *pStringB);
    bool hasStringSpace(const char *pString);
    bool isDigitStringTail(const char *pString, int);
    bool isExistString(const char *pFindString, const char* const *pStrings, u32 count);
    bool isNullOrEmptyString(const char *pString);

    bool isMessageEditorNextTag(const wchar_t *pString);
    s32 getStringLengthWithMessageTag(const wchar_t *pString);

    void scan32(const char *pString, const char *pField, s32 *pDest);
    void scanf32(const char *pString, const char *pField, f32 *pDest);
    void scanu8x4(const char *pString, const char *pField, u8 *pDest);
    void scanf32x4(const char *pString, const char *pField, f32 *pDest);
};
