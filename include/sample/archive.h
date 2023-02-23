#pragma once

#include "revolution.h"
#include "JSystem.h"

namespace syati {
    JKRArchive* loadArchive(const char *pArchivePath);
    void* loadResourceFromArchive(const char *pArchivePath, const char *pFile);
};
