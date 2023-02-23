#pragma once

#include "revolution.h"

struct JMapItem {
    u32 mHash;       // _0
    u32 mMask;       // _4
    u16 mOffsetData; // _8
    u8 mShift;       // _A
    u8 mType;        // _B
};

struct JMapData {
    s32 _0;
    s32 mNumData;      // _4
    s32 mDataOffset;   // _8
    u32 _C;
    JMapItem* mItems;  // _10
};

class JMapInfoIter;

class JMapInfo {
public:
    JMapInfo();
    ~JMapInfo();

    bool attach(const void *pData);
    s32 searchItemInfo(const char *) const;
    s32 getValueType(const char *pField) const;

    void setName(const char *pName);
    const char* getName() const;

    template<typename T>
    void getValue(s32 index, const char *pField, T *pDest) const;

    s32 getValueFast(s32, s32, const char **pDest) const;
    s32 getValueFast(s32, s32, u32 *pDest) const;
    s32 getValueFast(s32, s32, s32 *pDest) const;

    template<typename T>
    JMapInfoIter findElement(const char *, s32, int) const;
    JMapInfoIter end() const;

    const JMapData* mData; // _0
    const char* mName;     // _4
};

class JMapInfoIter {
public:
    inline JMapInfoIter(const JMapInfo* pInfo, int index) : mInfo(pInfo), mIndex(index) { }

    bool isValid() const;

    template<typename T>
    bool getValue(const char *pField, T *pDest) const;

    bool operator==(const JMapInfoIter &rOtherIter) const;
    bool operator!=(const JMapInfoIter &rOtherIter) const;

    const JMapInfo* mInfo; // _0
    s32 mIndex;            // _4
};
