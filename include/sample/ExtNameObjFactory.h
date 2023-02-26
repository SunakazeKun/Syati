#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"
#include "Game/NameObj/NameObjFactory.h"
#include "sample/SampleActor.h"

namespace {
    template<typename T>
    NameObj* createExtActor(const char *pName) {
        return new T(pName);
    }

    // ----------------------------------------------------------------------------------------------------------------

    const CreateActorEntry cNewCreateNameObjTable[] = {
        // Custom
        { "SampleActor", createExtActor<SampleActor> },

        // AreaObj
        { "ExtraWallCheckCylinder", NameObjFactory::createBaseOriginCylinder<AreaObj> },
        { "ForbidJumpArea", NameObjFactory::createNameObj<AreaObj> },
        { "ForbidWaterSearchArea", NameObjFactory::createNameObj<AreaObj> },
        { "PipeModeCube", NameObjFactory::createBaseOriginCube<AreaObj> },
        { "PlaneCircularModeCube", NameObjFactory::createBaseOriginCube<AreaObj> }
    };

    const s32 cNewCreateNameObjTableCount = sizeof(cNewCreateNameObjTable) / sizeof(CreateActorEntry);
};
