#pragma once

#include "revolution.h"
#include "Game/Map/RailGraphIter.h"

class RailGraphNodeSelecter {
public:
   virtual bool isSatisfy(RailGraphIter &) = 0;
};
