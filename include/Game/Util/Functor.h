#pragma once

#include "revolution.h"
#include "JSystem.h"

namespace MR {
	class FunctorBase {
	public:
		virtual void operator()() const = 0;
		virtual FunctorBase* clone(JKRHeap *pHeap) const = 0;
	};

    template<typename T, typename U>
    class FunctorV0M : public FunctorBase {
    public:
        inline FunctorV0M() { }

        inline FunctorV0M(T caller, U callee)
            : mCaller(caller), mCallee(callee) {
        }

        virtual void operator()() const {
            (mCaller->*mCallee)();
        }

        virtual FunctorBase* clone(JKRHeap *pHeap) const {
            return new (pHeap, 0) FunctorV0M(mCaller, mCallee);
        };

        T mCaller;
        U mCallee;
    };

    template<class T>
    static FunctorV0M<T *, void (T::*)()> Functor(T* caller, void (T::*callee)()) {
        return FunctorV0M<T *, void (T::*)()>(caller, callee);
    }

    class FunctorV0F : public FunctorBase {
    public:
        inline FunctorV0F(void (*pFunc)(void)) {
            mFunc = pFunc;
        };

        virtual void operator()() const;
        virtual FunctorBase* clone(JKRHeap *pHeap) const;

        void* mFunc;
    };
};
