#include "revolution.h"
#include "kamek/hooks.h"
#include "Game/Util/StringUtil.h"
#include "sample/ExtNameObjFactory.h"

/*
* Extends the existing NameObjFactory by taking into account our table of new objects. The custom creation table is
* defined in the header file.
*/

namespace {
    void* getNameObjCreator(const char *pName) {
        void* creator = NameObjFactory::getCreator(pName);

        if (!creator) {
            for (s32 i = 0; i < cNewCreateNameObjTableCount; i++) {
                const CreateActorEntry entry = cNewCreateNameObjTable[i];

                if (MR::isEqualString(entry.pActorName, pName)) {
                    creator = entry.mCreationFunc;
                    break;
                }
            }
        }

        return creator;
    }

    kmCall(0x803394C0, getNameObjCreator); // redirection hook
    kmCall(0x803430C8, getNameObjCreator);
    kmCall(0x804564D4, getNameObjCreator);
}
