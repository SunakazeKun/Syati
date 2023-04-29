#pragma once

#include "revolution.h"
#include "JSystem.h"

/* FINISHED */

class TalkMessageFuncBase {
public:
    virtual bool operator()(u32 funcType) const = 0;
    virtual TalkMessageFuncBase* clone() const = 0;
    virtual TalkMessageFuncBase* clone(JKRHeap *) const = 0;
};

template<typename T, typename U>
class TalkMessageFuncM : public TalkMessageFuncBase {
public:
    inline TalkMessageFuncM(T call, U callee)
        : mCaller(call), mCallee(callee) {
    }

    inline TalkMessageFuncM() {

    }

    virtual bool operator()(u32 funcType) const {
        return (mCaller->*mCallee)(funcType);
    }

    virtual TalkMessageFuncM* clone() const {
        return new TalkMessageFuncM(*this);
    }

    virtual TalkMessageFuncM* clone(JKRHeap *pHeap) const {
        return new (pHeap, 0) TalkMessageFuncM(*this);
    };

    T mCaller;
    U mCallee;
};

template<class T>
static TalkMessageFuncM<T *, bool (T::*)(u32)> TalkMessageFunc(T* caller, bool (T::*callee)(u32)) {
    return TalkMessageFuncM<T *, bool (T::*)(u32)>(caller, callee);
}
