#pragma once

#include "syati.h"

class TalkMessageFuncBase;
class RecursiveHelper;

class TalkMessageCtrl : public NameObj {
public:
    TalkMessageCtrl(LiveActor* actor, const TVec3f&, MtxPtr*);
    virtual ~TalkMessageCtrl();

    void createMessage(const JMapInfoIter&, const char*);
    void createMessageDirect(const JMapInfoIter&, const char*);
    s32 getMessageID() const;
    void requestTalk();
    void requestTalkForce();
    void startTalk();
    void startTalkForce();
    void startTalkForcePuppetable();
    void startTalkForceWithoutDemo();
    void startTalkForceWithoutDemoPuppetable();
    void endTalk();
    void updateBalloonPos();
    bool isNearPlayer(const TalkMessageCtrl*);
    bool isNearPlayer(f32);
    void startCamera(s32);
    void rootNodePre(bool);
    void rootNodePst();
    void isCurrentNodeContinue() const;
    void rootNodeEve();
    void rootNodeSel(bool);
    void registerBranchFunc(const TalkMessageFuncBase&);
    void registerEventFunc(const TalkMessageFuncBase&);
    void registerAnimeFunc(const TalkMessageFuncBase&);
    void registerKillFunc(const TalkMessageFuncBase&);
    void readMessage();
    bool isSelectYesNo();
    const char* getBranchID() const;

    LiveActor* _14;
    TalkNodeCtrl* mTalkNodeCtrl;
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
    s32 _50;
    s32 _54;
    s32 _58;
    s32 _5C;
    s32 _60;
    s32 _64;
    s32 _68;
    s32 _6C;
    s32 _70;
    s32 _74;
    s32 _78;
    s32 _7C;
};

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
    void* getNextNodeBranch() const;
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