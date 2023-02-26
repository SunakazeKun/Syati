#pragma once

#include "Game/NameObj/NameObj.h"

/* FINISHED */

class LiveActor;

class NameObjExecuteInfo {
public:
    NameObjExecuteInfo();

    void setConnectInfo(NameObj *pObj, int movementType, int calcAnimType, int drawBufferType, int drawType);
    void initConnectting();
    void requestConnect(u8 *pState);
    void requestDisconnect(u8 *pState, bool);
    void executeRequirementConnectMovement();
    void executeRequirementDisconnectMovement();
    void executeRequirementConnectDraw();
    void executeRequirementDisconnectDraw();
    void executeRequirementDisconnectDrawDelay();
    void requestMovementOn(int movementType);
    void requestMovementOff(int movementType);
    void findLightInfo() const;
    void connectToScene();
    void disconnectToScene();
    void connectToDraw();
    void disconnectToDraw();

    NameObj* mExecutedObject; // _0
    u8 mSceneConnectState;    // _4
    u8 mDrawConnectState;     // _5
    u8 mMovementType;         // _6
    u8 mCalcAnimType;         // _7
    u8 mDrawType;             // _8
    u8 mDrawBufferType;       // _9
    s16 mDrawBufferIndex;     // _A
};

class NameObjExecuteHolder : public NameObj {
public:
    NameObjExecuteHolder(int size);

    virtual ~NameObjExecuteHolder();

    void registerActor(NameObj *pObj, int movementType, int calcAnimType, int drawBufferType, int drawType);
    void initConnectting();
    void connectToScene(NameObj *pObj);
    void connectToDraw(NameObj *pObj);
    void disconnectToScene(NameObj *pObj);
    void disconnectToDraw(NameObj *pObj);
    bool isConnectToDraw(const NameObj *pObj) const;
    void executeRequirementConnectMovement();
    void executeRequirementDisconnectMovement();
    void executeRequirementConnectDraw();
    void executeRequirementDisconnectDraw();
    void executeRequirementDisconnectDrawDelay();
    void requestMovementOn(int movementType);
    void requestMovementOff(int movementType);
    NameObjExecuteInfo* getConnectToSceneInfo(const NameObj *pObj) const;

    NameObjExecuteInfo* mExecuteArray; // _14
    s32 mExecuteSize;                  // _18
    s32 mExecuteCount;                 // _1C
    bool mIsConnectScene;              // _20
    bool mIsDisconnectScene;           // _21
    bool mIsConnectDraw;               // _22
    bool mIsDisconnectDraw;            // _23
    bool mIsDisconnectDrawDelay;       // _24
};

namespace MR {
    void registerNameObjToExecuteHolder(NameObj *pObj, int movementType, int calcAnimType, int drawBufferType, int drawType);
    void initConnectting();
    void connectToSceneTemporarily(NameObj *pObj);
    void disconnectToSceneTemporarily(NameObj *pObj);
    void connectToDrawTemporarily(NameObj *pObj);
    void disconnectToDrawTemporarily(NameObj *pObj);
    bool isConnectToDrawTemporarily(const NameObj *pObj);
    void executeRequirementConnectMovement();
    void executeRequirementDisconnectMovement();
    void executeRequirementConnectDraw();
    void executeRequirementDisconnectDraw();
    void executeRequirementDisconnectDrawDelay();
    void requestMovementOnWithCategory(int movementType);
    void requestMovementOffWithCategory(int movementType);
    void findActorLightInfo(const LiveActor *pActor);
};
