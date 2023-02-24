#pragma once

#include "revolution.h"
#include "JSystem.h"

class HeapMemoryWatcherFunction {
public:
    static JKRHeap* createExpHeap(u32, JKRHeap *, bool);
    static JKRHeap* createSolidHeap(u32, JKRHeap *);
    static JKRHeap* destroyHeapAndSetNULL(u32, JKRHeap **);
};

class HeapMemoryWatcher {
public:
    HeapMemoryWatcher();

    JKRHeap* getHeapNapa(const JKRHeap *);
    JKRHeap* getHeapGDDR3(const JKRHeap *);
    void createWorldMapHeap();
    void createFileCacheHeapOnGameHeap(u32 size);
    void createSceneHeapOnGameHeap();
    void adjustStationedHeapNapa();
    void adjustStationedHeapGDDR3();
    void setCurrentHeapToStationedHeap();
    void setCurrentHeapToGameHeap();
    void setCurrentHeapToSceneHeap();
    void resetHeapNapaAndGDDR3();
    void resetHeapNapa();
    void resetHeapGDDR3();
    void destroyWorldMapHeap();
    void destroyFileCache();
    void destroySceneHeap();
    void createRootHeap();
    HeapMemoryWatcher* createHeaps();
    void createGameHeap();

    void memoryErrorCallback(void *, u32, int);
    void checkRestMemory();

    static JKRHeap* sRootHeapGDDR3;

    JKRHeap *mStationedHeapNapa;
    JKRHeap *mStationedHeapGDDR3;
    JKRHeap *mHeapNapa;
    JKRHeap *mHeapGDDR3;
    JKRHeap *mWorldMapHeap;
    JKRHeap *mFileCacheHeap;
    JKRHeap *_18;
    JKRHeap *mSceneHeapNapa;
    JKRHeap *mSceneHeapGDDR3;
    JKRHeap *mWPadHeap;
    JKRHeap *mHomeButtonLayoutHeap;
    JKRHeap *_2C;
};
