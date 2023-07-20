#pragma once

#include "syati.h"

class RecursiveHelper;

// None of these return types are known.
class TalkNodeCtrl {
public:
    TalkNodeCtrl();
    ~TalkNodeCtrl();

    void createFlowNode(TalkMessageCtrl*, const JMapInfoIter&, const char*, ActorCameraInfo**);
    void resetFlowNode();
    void resetTempFlowNode();
    void recordTempFlowNode();
    void forwardFlowNode();
    bool isExistNextNode() const;
    bool isNextNodeMessage() const;
    bool isCurrentNodeEvent();
    void initNodeRecursive(TalkMessageCtrl*, const JMapInfoIter&, ActorCameraInfo*, RecursiveHelper*);
    s32 getNextNode() const;
    s32 getNextNodeBranch() const;
    s32 getCurrentNodeBranch() const;
    s32 getCurrentNodeMessage() const;
    s32 getCurrentNodeEvent() const;
    s32 getNextNodeEvent() const;
    void updateMessage();
    void readMessage();
    void forwardCurrentBranchNode(bool);
    
    s32 _0;
    s32 _4;
    s32 _8;
    s32 _C;
    s32 _10;
    s32 _14;
    s32 _18;
    s32 _1C;
    s32 _20;
    s32 _24;
    s32 _28;
    s32 _2C;
    s32 _30;
    s32 _34;
    s32 _38;
    s32 _3C;
    s32 _40;
    s32 _44;
    s32 _48;
    s32 _4C;
};