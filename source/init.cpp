#include "syati.h"


/*********************************************************************************************************************/
/* Call static constructors                                                                                          */
/*********************************************************************************************************************/
typedef void (*Func)();
extern Func __ctor_loc;
extern Func __ctor_end;

void init() {
    for (Func* f = &__ctor_loc; f < &__ctor_end; f++)
        (*f)();

    MR::getRandom(0, (s32)sizeof(J3DGXColor));
}

#if defined(TWN) || defined(KOR)
    kmBranch(0x804B6758, init);
#else
    kmBranch(0x804B66E8, init);
#endif
