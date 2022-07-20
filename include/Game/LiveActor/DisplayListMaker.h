#pragma once

#include "JSystem.h"
#include "Game/System/ResourceHolder.h"

class MaterialCtrl;
class FogCtrl;
class MatColorCtrl;
class ProjmapEffectMtxSetter;
class MirrorReflectionMtxSetter;
class TexMtxCtrl;

class DisplayListMaker {
public:
    DisplayListMaker(J3DModel *, const ResourceHolder *);

    void update();
    void diff();
    void newDifferedDisplayList();
    bool isValidDiff();
    void onPrgFlag(u16, u32);
    void onCurFlag(u16, u32);
    s32 getDiffFlag(s32) const;
    FogCtrl* addFogCtrl(bool);
    MatColorCtrl* addMatColorCtrl(const char *, u32, const J3DGXColor *);
    ProjmapEffectMtxSetter* addProjmapEffectMtxSetter();
    MirrorReflectionMtxSetter* addMirrorReflectionMtxSetter();
    TexMtxCtrl* addTexMtxCtrl(const char *);
    void onCurFlagBpk(const J3DAnmBase *, const char *);
    void offCurFlagBpk(const J3DAnmBase *, const char *);
    void onCurFlagBtp(const J3DAnmBase *, const char *);
    void offCurFlagBtp(const J3DAnmBase *);
    void onCurFlagBtk(const J3DAnmBase *, const char *);
    void offCurFlagBtk(const J3DAnmBase *);
    void onCurFlagBrk(const J3DAnmBase *, const char *);
    void offCurFlagBrk(const J3DAnmBase *);
    void push(MaterialCtrl *);
    void onBothFlag(u16, u32);
    void onBothFlagAll(u32);
    void checkMaterial();

    void checkTexture();
    void checkViewProjmapEffectMtx();
    //void* addViewProjmapEffectMtxSetter();
    //void* addMarioShadowProjmapMtxSetter();
    bool isExistDiffMaterial(J3DModelData const *);
};
