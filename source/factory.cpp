#include "syati.h"
#include "syati/Actor/ExtendedActorFactory.h"


/*********************************************************************************************************************/
/* Extended NameObjFactory                                                                                           */
/*********************************************************************************************************************/
namespace syati {
    void* getNameObjCreator(const char *pName) {
        void* creator = NameObjFactory::getCreator(pName);

        if (!creator) {
            for (s32 i = 0; i < NUM_ACTORS; i++) {
                const CreateActorEntry entry = cCreateTable[i];

                if (MR::isEqualStringCase(entry.pActorName, pName)) {
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
