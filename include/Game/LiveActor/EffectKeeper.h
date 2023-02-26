#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/Binder.h"
#include "Game/System/ResourceHolder.h"

class EffectKeeper {
public:
    EffectKeeper(const char *, ResourceHolder *, s32, const char *);

    void init(LiveActor *);
    void initAfterPlacementForAttributeEffect(Mtx *);
    void setBinder(Binder *);
    void addEffect(const char *, LiveActor *);
    void createEmitter(const char*);
    void registerEffect(const char *, Mtx *, const char *, const char *);

    void updateAttributeEffect();
    void stopEmitterOnClipped();
    void playEmitterOffClipped();
    void clear();
    void changeBck();
    void onDraw();
    void offDraw();
    void enableSort();
    void finalizeSort();

    void update();

    u8 _0[0x18];
    u32* _18; // HashSortTable*
    u32 _1C;
    u32* _20; // SyncBckEffectCHecker*
    Binder* mBinder; // _24
    u32 _28;
    u32 _2C;
    u32 _30;
};
