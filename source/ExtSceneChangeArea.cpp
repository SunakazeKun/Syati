#include "revolution.h"
#include "kamek/hooks.h"
#include "Game/AreaObj/SceneChangeArea.h"
#include "Game/System/AllData/GameSequenceFunction.h"
#include "Game/Util/PlayerUtil.h"
#include "Game/Util/ScreenUtil.h"

/*
* Reimplementation of SceneChangeArea's "control" method. This allows for customization through Obj_arg0 and Obj_arg1:
* - Obj_arg0: Index of the galaxy to be accessed. Galaxies can be customized in the array below.
* - Obj_arg1: White fade time in frames (60 = 1 second).
*/

namespace {
    /*
    * List of stages to be accessed after entering SceneChangeArea. The area's Obj_arg0 specifies what stage should be
    * accessed. The first entry corresponds to setting Obj_arg0 to 0, and so on.
    */
    const char* cSceneChangeAreaStages[] = {
        "IslandFleetGalaxy",
        "YosshiHomeGalaxy",
        "DigMineGalaxy"
    };

    const int cSceneChangeAreaStagesCount = sizeof(cSceneChangeAreaStages) / sizeof(const char*);

    // ----------------------------------------------------------------------------------------------------------------

    void reimplSceneChangeAreaControl(SceneChangeArea *pArea) {
        if (pArea->isInVolume(*MR::getPlayerPos())) {
            // Freeze the screen & fade to white
            s32 fadeTime = pArea->mObjArg1 < 0 ? 120 : pArea->mObjArg1;
            MR::closeSystemWipeFadeWithCaptureScreen(fadeTime);

            // Access Star Select for desired galaxy
            const char* stageName;

            if (0 <= pArea->mObjArg0 && pArea->mObjArg0 < ::cSceneChangeAreaStagesCount) {
                stageName = ::cSceneChangeAreaStages[pArea->mObjArg0];
            }
            else {
                stageName = "IslandFleetGalaxy";
            }

            GameSequenceFunction::requestChangeScenarioSelect(stageName);

            // Invalidate the area
            pArea->mValidate = false;
        }
    }

#if defined(USA)
    kmWritePointer(0x8066AE4C, reimplSceneChangeAreaControl);
#elif defined(PAL)
    kmWritePointer(0x8067054C, reimplSceneChangeAreaControl);
#elif defined(JPN)
    kmWritePointer(0x8066A62C, reimplSceneChangeAreaControl);
#elif defined(TWN)
    kmWritePointer(0x8066B0EC, reimplSceneChangeAreaControl);
#elif defined(KOR)
    kmWritePointer(0x80669C8C, reimplSceneChangeAreaControl);
#endif
}
