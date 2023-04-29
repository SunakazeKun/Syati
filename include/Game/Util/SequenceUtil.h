#pragma once

#include "revolution.h"

/* FINISHED */

namespace MR {
    bool isExecScenarioStarter();
    bool isStageStateScenarioOpeningCamera();
    bool isStageStatePowerStarAppeared();

    void requestPowerStarGetDemo();
    void requestGrandStarGetDemo();
    void requestStartGameOverDemo();
    void requestEndGameOverDemo();
    void requestEndMissDemo();

    void executeOnWelcomeAndRetry();
};
