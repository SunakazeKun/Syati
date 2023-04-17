#include "revolution.h"
#include "kamek/hooks.h"
#include "sample/PadRecord.h"

typedef void (*Func)();
extern Func __ctor_loc;
extern Func __ctor_end;

namespace {
    // ----------------------------------------------------------------------------------------------------------------
    // Calls all static initializers after MR::initAcosTable. This is necessary to initialize static variables and 
    // constants in the BSS segment. Custom Nerve instances will be stored there, for example.

    void init() {
        for (Func* f = &__ctor_loc; f < &__ctor_end; f++) {
            (*f)();
        }
    }

    // Called after initAcosTable
    kmBranch(0x8003B344, init);


    // ----------------------------------------------------------------------------------------------------------------
    // Events to be handled after GameScene::start

    void handleGameSceneStart() {
        pad::startPadRecorderPrepared();
    }

    kmBranch(0x80451888, handleGameSceneStart);


    // ----------------------------------------------------------------------------------------------------------------
    // Events to be handled after GameScene::~GameScene

    void handleGameSceneDestroy() {
        pad::resetPadRecorderNotPrepared();
    }

    kmBranch(0x80451478, handleGameSceneDestroy);
}
