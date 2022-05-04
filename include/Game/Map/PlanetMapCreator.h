#pragma once

#include "revolution.h"

class PlanetMapCreatorFunction {
public:
    static void* getPlanetMapCreator(const char *);
    static bool isLoadArchiveAfterScenarioSelected(const char *);
    static bool isRegisteredObj(const char *);
};
