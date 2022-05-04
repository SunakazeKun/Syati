#pragma once

#include "Game/NameObj/NameObjFactory.h"
#include "syati/Actor/MyFirstActor.h"

// ensure you bump up this value when you add more actors!
#define NUM_ACTORS 1

namespace syati {
    template<typename T>
    NameObj* createExtActor(const char *pName);

	// change me to your custom actor!
    template<>
    NameObj* createExtActor<MyFirstActor>(const char *pName) {
        return new MyFirstActor("MyFirstActor");
    }

    const CreateActorEntry cCreateTable[NUM_ACTORS] = {
        { "MyFirstActor", createExtActor<MyFirstActor> }
    };
};
