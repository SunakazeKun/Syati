#pragma once

#include "revolution.h"
#include "JSystem.h"

namespace MR {
    class CurrentHeapRestorer {
    public:
        CurrentHeapRestorer(JKRHeap *pHeap);

        ~CurrentHeapRestorer();

        JKRHeap* mCurrentHeap; // _0
    };

    JKRHeap* getCurrentHeap();
    JKRHeap* getStationedHeapNapa();
    JKRHeap* getStationedHeapGDDR3();
    JKRHeap* getSceneHeapNapa();
    JKRHeap* getSceneHeapGDDR3();
    JKRHeap* getWorldMapHeap();
    JKRHeap* getFileCacheHeap();

    JKRHeap* getHeapNapa();
    JKRHeap* getHeapGDDR3();
    JKRHeap* becomeCurrentHeap(JKRHeap *);
    bool isEqualCurrentHeap(JKRHeap *);
    //void adjustHeapSize(JKRExpHeap *);
    u32 getFileCacheSizeForGalaxy(const char *pSceneName, const char *pStageName, s32 scenarioNum);
    bool tryGetHeapSizeExceptForGalaxy(u32 *pDest, const char *pFieldName, const char *pSceneName, const char *pStageName, s32 scenarioNum);
    bool isUseWorldMapHeapForGalaxy(const char *pSceneName, const char *pStageName, s32 scenarioNum);
    void copyMemory(void *pDest, const void *pSrc, u32 length);
    void fillMemory(void *pDest, u8 fill, u32 length);
    void zeroMemory(void *pDest, u32 length);
    void calcCheckSum(const void *pSrc, u32 length);
    void* allocFromWPadHeap(u32 length);
    void freeFromWPadHeap(void *pAllocated);
};
