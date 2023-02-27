#pragma once

#include "revolution.h"

class Nerve;
class NerveExecutor;

namespace MR {
    bool isStep(const NerveExecutor *pExecutor, s32 step);
    bool isFirstStep(const NerveExecutor *pExecutor);
    bool isLessStep(const NerveExecutor *pExecutor, s32 step);
    bool isLessEqualStep(const NerveExecutor *pExecutor, s32 step);
    bool isGreaterStep(const NerveExecutor *pExecutor, s32 step);
    bool isGreaterEqualStep(const NerveExecutor *pExecutor, s32 step);
    bool isIntervalStep(const NerveExecutor *pExecutor, s32 step);
    bool isNewNerve(const NerveExecutor *pExecutor);
    f32 calcNerveRate(const NerveExecutor *pExecutor, s32 step);
    f32 calcNerveRate(const NerveExecutor *pExecutor, s32 startStep, s32 endStep);
    f32 calcNerveEaseInRate(const NerveExecutor *pExecutor, s32 step);
    f32 calcNerveEaseOutRate(const NerveExecutor *pExecutor, s32 step);
    f32 calcNerveEaseInOutRate(const NerveExecutor *pExecutor, s32 step);
    f32 calcNerveValue(const NerveExecutor *pExecutor, s32, f32, f32);
    f32 calcNerveEaseInValue(const NerveExecutor *pExecutor, s32, f32, f32);
    f32 calcNerveEaseOutValue(const NerveExecutor *pExecutor, s32, f32, f32);
    f32 calcNerveEaseOutValue(const NerveExecutor *pExecutor, s32, s32, f32, f32);
    f32 calcNerveEaseInOutValue(const NerveExecutor *pExecutor, s32, f32, f32);
    f32 calcNerveEaseInOutValue(const NerveExecutor *pExecutor, s32, s32, f32, f32);
    f32 calcNerveParabolaValue(const NerveExecutor *pExecutor, s32 step);

    void setNerveAtStep(NerveExecutor *pExecutor, const Nerve *pNerve, s32 step);
};
