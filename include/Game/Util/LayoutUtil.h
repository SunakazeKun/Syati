#pragma once

#include "revolution.h"

class LayoutActor;
class IconAButton;

namespace MR {
	void setTextBoxArgNumberRecursive(LayoutActor *, const char *, s32, s32);
	void setTextBoxGameMessageRecursive(LayoutActor *, const char *, const char *);
	void setTextBoxMessageRecursive(LayoutActor *, const char *, const wchar_t *);
	void setTextBoxFormatRecursive(LayoutActor* layout, const char* paneName, const wchar_t* string ...);

	void showPaneRecursive(LayoutActor *pLayout, const char *pPaneName);
	void hidePaneRecursive(LayoutActor *pLayout, const char *pPaneName);

	void startAnim(LayoutActor *, const char *, u32);
	void startAnimAndSetFrameAndStop(LayoutActor *, const char *, f32, u32);
	bool isAnimStopped(const LayoutActor *, u32);


	bool isFirstStep(const LayoutActor *pLayout);
	bool isLessStep(const LayoutActor *pLayout, s32 step);
	bool isGreaterStep(const LayoutActor *pLayout, s32 step);
	bool isGreaterEqualStep(const LayoutActor *pLayout, s32 step);
	bool isIntervalStep(const LayoutActor *pLayout, s32 step);
	bool isNewNerve(const LayoutActor *pLayout);
	f32 calcNerveEaseInRate(const LayoutActor *pLayout, s32);
	f32 calcNerveEaseInValue(const LayoutActor *pLayout, s32, s32, f32, f32);

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

	IconAButton* createAndSetupIconAButton(LayoutActor *pLayout, bool, bool);
};
