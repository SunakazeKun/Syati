#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObj.h"

struct CreateActorEntry {
    const char* pActorName; // _0
    NameObj* (*mCreationFunc)(const char *); // _4
};

struct PostCreationEntry {
    const char* pActorName; // _0
    void (*mPostCreationFunc)(const JMapInfoIter &); // _4
};

class NameObjFactory {
public:
    static void* getCreator(const char *pName);
    static void callPostCreation(const char *pName, const JMapInfoIter &rIter);
    static NameObj* initChildObj(const JMapInfoIter &rIter, int index);

    static CreateActorEntry cCreateTable[1003];
    static PostCreationEntry cPostCreationTable[27];

    template<typename T>
    static NameObj* createNameObj(const char *pName);

    template<typename T>
    static NameObj* createBaseOriginCube(const char *pName);

    template<typename T>
    static NameObj* createCenterOriginCube(const char *pName);

    template<typename T>
    static NameObj* createSphere(const char *pName);

    template<typename T>
    static NameObj* createBaseOriginCylinder(const char *pName);
};
