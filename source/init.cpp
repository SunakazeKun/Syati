#include "revolution.h"
#include "kamek/hooks.h"


/*
* Calls all linked static initializers. This is necessary to initialize static variables and constants in the BSS
* segment. Custom Nerve instances will be stored there, for example.
*/

typedef void (*Func)();
extern Func __ctor_loc;
extern Func __ctor_end;

namespace {
    void init() {
        for (Func* f = &__ctor_loc; f < &__ctor_end; f++) {
            (*f)();
        }
    }

    // Called after initAcosTable
    kmBranch(0x8003B344, init);
}
