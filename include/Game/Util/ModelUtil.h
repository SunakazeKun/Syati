#pragma once

#include "revolution.h"

class LiveActor;
class J3DModel;

namespace MR {
    bool isExistCollisionResource(const LiveActor *, const char *);

    J3DModel* getJ3DModel(const LiveActor *);

    void hideMaterial(J3DModel *, const char *);
    void hideMaterial(const LiveActor *, const char *);
    void showMaterial(J3DModel *, const char *);
    void showMaterial(const LiveActor *, const char *);
};
