#pragma once

#include "Game/Screen/LayoutActor.h"
#include "Game/System/NerveExecutor.h"
#include "Game/Screen/IconAButton.h"

class StageResultInformer;
class SimpleEffectLayout;

class DisplayInformationForResult : public NerveExecutor {
public:
    DisplayInformationForResult(StageResultInformer *pInformer);

    virtual ~DisplayInformationForResult();

    void exeAppear();

    StageResultInformer* mInformer; // _8
    const char* mMessageLabel;      // _C
    const wchar_t* mReplaceString;  // _10
};

class StageResultInformer : public LayoutActor {
public:
    StageResultInformer();

    virtual ~StageResultInformer();
    virtual void init(const JMapInfoIter &rIter);
    virtual void appear();
    virtual void kill();

    void exeAppearGetPowerStar();
    void exeCountUpPowerStar();
    void exeDisplayGetPowerStar();
    void exeDisappearGetPowerStar();
    void exeAppearGetCometMedal();
    void exeCountUpGetCometMedal();
    void exeDisplayGetCometMedal();
    void exeDisappearGetCometMedal();
    void exeComplete();
    void exeAppearGetStarPiece();
    void exeDisplayGetStarPiece();
    void exeWaitBeforeDisappearGetStarPiece();
    void exeDisappearGetStarPiece();
    void exeAppearGetCoin();
    void exeDisplayGetCoin();
    void exeWaitBeforeDisappearGetCoin();

    void exeDisappearGetCoin();
    void exeAppearBestTime();
    void exeDisplayBestTime();
    void exeDisappearBestTime();

    const Nerve* getNextNerve() const;
    void decideNextNerve();
    bool tryWaitSystemPadTriggerDecide(const Nerve *);
    bool tryWaitIntervalBeforeKeyWait(const Nerve *, int);
    bool tryShowAndKeyWaitInformationWindow(const char *, const char *);
    void updateStarPieceCount();
    void updateCoinCount();

    void hideCounterPanes();
    void endResultPane();
    bool isCompleted() const;

    DisplayInformationForResult* mDisplayInformation; // _2C
    IconAButton* mIconAButton;                        // _30
    s32 _34;
    bool _38;
    SimpleEffectLayout* mOneUpEffect;                 // _34
    s32 _40;
    bool _44;
};

namespace NrvStageResultInformer {
    NERVE(StageResultInformerNrvAppearGetPowerStar);
    NERVE(StageResultInformerNrvWaitBeforeCountUpPowerStar);
    NERVE(StageResultInformerNrvCountUpPowerStar);
    NERVE(StageResultInformerNrvDisplayGetPowerStar);
    NERVE(StageResultInformerNrvDisappearGetPowerStar);
    NERVE(StageResultInformerNrvAppearGetCometMedal);
    NERVE(StageResultInformerNrvWaitBeforeCountUpCometMedal);
    NERVE(StageResultInformerNrvCountUpGetCometMedal);
    NERVE(StageResultInformerNrvDisplayGetCometMedal);
    NERVE(StageResultInformerNrvDisappearGetCometMedal);
    NERVE(StageResultInformerNrvComplete);
    NERVE(StageResultInformerNrvGhostAppear);
    NERVE(StageResultInformerNrvAppearGetStarPiece);
    NERVE(StageResultInformerNrvDisplayGetStarPiece);
    NERVE(StageResultInformerNrvWaitBeforeDisappearGetStarPiece);
    NERVE(StageResultInformerNrvDisappearGetStarPiece);
    NERVE(StageResultInformerNrvAppearGetCoin);
    ENDABLE_NERVE(StageResultInformerNrvDisplayGetCoin);
    NERVE(StageResultInformerNrvWaitBeforeDisappearGetCoin);

    NERVE(StageResultInformerNrvDisappearGetCoin);
    NERVE(StageResultInformerNrvAppearBestTime);
    NERVE(StageResultInformerNrvWaitBeforeDisplayBestTime);
    NERVE(StageResultInformerNrvDisplayBestTime);
    NERVE(StageResultInformerNrvDisappearBestTime);
};

namespace NrvDisplayInformationForResult {
    NERVE(DisplayInformationForResultNrvAppear);
    NERVE(DisplayInformationForResultNrvIdle);
};
