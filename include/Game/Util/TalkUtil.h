#pragma once

#include "revolution.h"
#include "JSystem.h"

class JMapInfoIter;
class LiveActor;
class TalkMessageCtrl;
class TalkMessageFuncBase;

namespace MR {
    void registerBranchFunc(TalkMessageCtrl *pTalkCtrl, const TalkMessageFuncBase &rTalkFunc);
    void registerEventFunc(TalkMessageCtrl *pTalkCtrl, const TalkMessageFuncBase &rTalkFunc);
    void registerAnimeFunc(TalkMessageCtrl *pTalkCtrl, const TalkMessageFuncBase &rTalkFunc);
    void registerKillFunc(TalkMessageCtrl *pTalkCtrl, const TalkMessageFuncBase &rTalkFunc);
    void setMessageArg(TalkMessageCtrl *pTalkCtrl, int arg);

    TalkMessageCtrl* createTalkCtrl(LiveActor *pActor, const JMapInfoIter &rIter, const TVec3f &rOffset, MtxPtr pFollowMtx);
    TalkMessageCtrl* createTalkCtrlDirect(LiveActor *pActor, const JMapInfoIter &rIter, const char *pLabel, const TVec3f &rOffset, MtxPtr pFollowMtx);
    TalkMessageCtrl* createTalkCtrlDirect(LiveActor *pActor, const char *pLabel, const TVec3f &rOffset, MtxPtr pFollowMtx);
    TalkMessageCtrl* createTalkCtrlDirectOnRootNodeAutomatic(LiveActor *pActor, const JMapInfoIter &rIter, const char *pLabel, const TVec3f &rOffset, MtxPtr pFollowMtx);
    TalkMessageCtrl* tryCreateTalkCtrlDirectOnRootNodeAutomatic(LiveActor *pActor, const JMapInfoIter &rIter, const char *pLabel, const TVec3f &rOffset, MtxPtr pFollowMtx);

    bool tryTalkNearPlayer(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkNearPlayerAtEnd(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkForce(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkForceMarioPuppetable(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkForceAtEnd(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkForceMarioPuppetableAtEnd(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkWithoutDemo(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkWithoutDemoMarioPuppetable(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkWithoutDemoAtEnd(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkWithoutDemoMarioPuppetableAtEnd(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkTimeKeepDemoMarioPuppetable(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkTimeKeepDemoForceWithoutDemo(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkTimeKeepDemoWithoutPauseMarioPuppetable(TalkMessageCtrl *pTalkCtrl);

    bool tryTalkRequest(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkSelectLeft(TalkMessageCtrl *pTalkCtrl);

    const MtxPtr getMessageBallonFollowMtx(const TalkMessageCtrl *pTalkCtrl);
    const TVec3f* getMessageBalloonFollowOffset(const TalkMessageCtrl *pTalkCtrl);
    void setMessageBalloonFollowOffset(TalkMessageCtrl *pTalkCtrl, const TVec3f &rFollowOffset);

    bool isNearPlayer(const TalkMessageCtrl *pTalkCtrl, f32 distance);
    bool isTalkNone(const TalkMessageCtrl *pTalkCtrl);
    bool isTalkEntry(const TalkMessageCtrl *pTalkCtrl);
    bool isTalkTalking(const TalkMessageCtrl *pTalkCtrl);
    bool isTalkEnableEnd(const TalkMessageCtrl *pTalkCtrl);

    void resetNode(TalkMessageCtrl *pTalkCtrl);
    void readMessage(TalkMessageCtrl *pTalkCtrl);
    bool isMessageRead(const TalkMessageCtrl *pTalkCtrl);
    void forwardNode(TalkMessageCtrl *pTalkCtrl);
    void resetAndForwardNode(TalkMessageCtrl *pTalkCtrl, s32 nodeCount);
    bool tryForwardNode(TalkMessageCtrl *pTalkCtrl);
    bool isExistNextNode(const TalkMessageCtrl *pTalkCtrl);

    // one unknown function here...

    bool isShortTalk(const TalkMessageCtrl *pTalkCtrl);
    void setDistanceToTalk(TalkMessageCtrl *pTalkCtrl, f32 distance);
    void onRootNodeAutomatic(TalkMessageCtrl *pTalkCtrl);
    void offRootNodeAutomatic(TalkMessageCtrl *pTalkCtrl);

    // several unknown functions here...

    bool isTalkStart(const TalkMessageCtrl *pTalkCtrl);
};
