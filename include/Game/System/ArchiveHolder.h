#pragma once

#include "revolution.h"

class JKRArchive;

class ArchiveHolder {
public:
    JKRArchive* getArchive(const char *) const;
};
