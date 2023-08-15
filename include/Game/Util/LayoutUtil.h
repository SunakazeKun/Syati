#pragma once

#include "revolution.h"

class LayoutActor;
class IconAButton;
class ResourceHolder;
class LayoutGroupCtrl;
class LayoutPaneCtrl;
struct TextBoxRecursiveOperation;
class SimpleLayout;
class Nerve;

namespace MR {
	ResourceHolder* createAndAddLayoutHolder(const char *);
	ResourceHolder* createAndAddLayoutHolderRawData(const char *);
	LayoutPaneCtrl* createAndAddPaneCtrl(LayoutActor *, const char *, u32);
	LayoutGroupCtrl* createAndAddGroupCtrl(LayoutActor *, const char *, u32);

	bool isExistPaneCtrl(LayoutActor *, const char *);
	// one unknown function

	void setInfluencedAlphaToChild(const LayoutActor *);
	void setLayoutAlphaFloat(const LayoutActor *, f32);

	void executeTextBoxRecursive(LayoutActor *, const char *, const TextBoxRecursiveOperation &);

	void setTextBoxSystemMessageRecursive(LayoutActor *, const char *, const char *);
	void setTextBoxGameMessageRecursive(LayoutActor *, const char *, const char *);
	void setTextBoxNumberRecursive(LayoutActor *, const char *, s32);
	void setTextBoxMessageRecursive(LayoutActor *, const char *, const wchar_t *);
	void setTextBoxFormatRecursive(LayoutActor* layout, const char* paneName, const wchar_t* string ...);
	void setTextBoxArgNumberRecursive(LayoutActor *, const char *, s32, s32);
	void setTextBoxArgStringRecursive(LayoutActor *, const char *, const wchar_t *, s32);
	void setTextBoxVerticalPositionCenterRecursive(LayoutActor *, const char *);
	void setTextBoxVerticalPositionBottomRecursive(LayoutActor *, const char *);
	void clearTextBoxMessageRecursive(LayoutActor *, const char *);
	void updateClearTimeTextBox(LayoutActor *, const char *, u32);
	void updateMinuteAndSecondTextBox(LayoutActor *, const char *, u32);
	// setTextBoxFontRecursive

	void showPane(LayoutActor *pLayout, const char *pPaneName);
	void showPaneRecursive(LayoutActor *pLayout, const char *pPaneName);
	void hidePane(LayoutActor *pLayout, const char *pPaneName);
	void hidePaneRecursive(LayoutActor *pLayout, const char *pPaneName);
	bool isHiddenPane(LayoutActor *pLayout, const char *pPaneName);
	void showScreen(LayoutActor *pLayout);
	void hideScreen(LayoutActor *pLayout);

	// various more functions here...
	void calcScreenPosition(TVec2f*, const TVec3f&);

	void startAnim(LayoutActor *, const char *, u32);
	void startAnimAtFirstStep(LayoutActor *, const char *, u32);
	void startPaneAnim(LayoutActor *, const char *, const char *, u32);
	void startPaneAnimAtStep(LayoutActor *, const char *, const char *, s32, u32);
	void startPaneAnimAtFirstStep(LayoutActor *, const char *, const char *, u32);
	void startAnimAndSetFrameAndStop(LayoutActor *, const char *, f32, u32);
	void startPaneAnimAndSetFrameAndStop(LayoutActor *, const char *, const char *, f32, u32);
	void setAnimFrameAndStop(LayoutActor *, f32, u32);
	void setAnimFrameAndStopAtEnd(LayoutActor *, u32);
	void setAnimFrameAndStopAdjustTextWidth(LayoutActor *, const char *, u32);
	void setAnimFrameAndStopAdjustTextHeight(LayoutActor *, const char *, u32);
	void setPaneAnimFrameAndStop(LayoutActor *, const char *, f32, u32);
	void setAnimFrame(LayoutActor *, f32, u32);
	void setPaneAnimFrame(LayoutActor *, const char *, f32, u32);
	void setAnimRate(LayoutActor *, f32, u32);
	void setPaneAnimRate(LayoutActor *, const char *, f32, u32);
	void stopAnim(LayoutActor *, u32);
	void stopPaneAnim(LayoutActor *, const char *, u32);
	bool isAnimStopped(const LayoutActor *, u32);
	bool isPaneAnimStopped(const LayoutActor *, const char *, u32);
	f32 getAnimFrame(const LayoutActor *, u32);
	f32 getPaneAnimFrame(const LayoutActor *, const char *, u32);
	f32 getAnimFrameMax(const LayoutActor *, u32);
	f32 getPaneAnimFrameMax(const LayoutActor *, const char *, u32);
	f32 getAnimFrameMax(const LayoutActor *, const char *);
	//getAnimCtrl
	//getPaneAnimCtrl
	void emitEffect(LayoutActor *, const char *);
	void deleteEffect(LayoutActor *, const char *);
	void forceDeleteEffect(LayoutActor *, const char *);
	void deleteEffectAll(LayoutActor *);
	void forceDeleteEffectAll(LayoutActor *);
	void setEffectHostMtx(LayoutActor *, const char *, MtxPtr);
	void setEffectRate(LayoutActor *, const char *, f32);
	void setEffectDirectionalSpeed(LayoutActor *, const char *, f32);
	void pauseOffEffectAll(LayoutActor *);
	bool isRegisteredEffect(const LayoutActor *, const char *);

	bool isFirstStep(const LayoutActor *pLayout);
	bool isLessStep(const LayoutActor *pLayout, s32 step);
	bool isGreaterStep(const LayoutActor *pLayout, s32 step);
	bool isGreaterEqualStep(const LayoutActor *pLayout, s32 step);
	bool isIntervalStep(const LayoutActor *pLayout, s32 step);
	bool isNewNerve(const LayoutActor *pLayout);
	f32 calcNerveEaseInRate(const LayoutActor *pLayout, s32);
	f32 calcNerveEaseInValue(const LayoutActor *pLayout, s32, s32, f32, f32);
	f32 calcNerveEaseOutValue(const LayoutActor *pLayout, s32, f32, f32);

	void setNerveAtStep(LayoutActor *pLayout, const Nerve *pNerve, s32 step);
	void setNerveAtAnimStopped(LayoutActor *pLayout, const Nerve *pNerve, u32);
	void setNerveAtPaneAnimStopped(LayoutActor *pLayout, const char *pPaneName, const Nerve *pNerve, u32);
	void killAtAnimStopped(LayoutActor *pLayout, u32);

	bool isDead(const LayoutActor *pLayout);
	bool isHiddenLayout(const LayoutActor *pLayout);
	void showLayout(LayoutActor *pLayout);
	void hideLayout(LayoutActor *pLayout);

	bool isStopAnimFrame(const LayoutActor *pLayout);
	void stopAnimFrame(LayoutActor *pLayout);
	void releaseAnimFrame(LayoutActor *pLayout);
	void onCalcAnim(LayoutActor *pLayout);
	void offCalcAnim(LayoutActor *pLayout);
	bool isExecuteCalcAnimLayout(const LayoutActor *pLayout);
	bool isExecuteDrawLayout(const LayoutActor *pLayout);

	SimpleLayout* createSimpleLayout(const char *, const char *, u32);
	SimpleLayout* createSimpleLayoutTalkParts(const char *, const char *, u32);
	IconAButton* createAndSetupIconAButton(LayoutActor *pLayout, bool, bool);

	// getPane
	// getRootPane
	
	// calcTextBoxRectRecursive
	u32 getTextLineNumMaxRecursive(const LayoutActor *pLayout, const char *);
	void invalidateParentAnim(LayoutActor *pLayout);
};
