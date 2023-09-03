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
        
        inline FunctorV0M(const FunctorV0M& ref)
            : mCaller(ref.mCaller), mCallee(ref.mCallee) { }

        virtual void operator()() const {
            (mCaller->*mCallee)();
        }

        virtual FunctorBase* clone(JKRHeap *pHeap) const {
            return new (pHeap, 0) FunctorV0M(*this);
        };

        T mCaller;
        U mCallee;
    };

    template<class T>
    static FunctorV0M<T *, void (T::*)()> Functor(T* caller, void (T::*callee)()) {
        return FunctorV0M<T *, void (T::*)()>(caller, callee);
    }

    template<typename T, typename U, typename V>
    class FunctorV1M : public FunctorBase {
        public:
        inline FunctorV1M() { }

        inline FunctorV1M(T caller, U callee, V arg0) :
        mCaller(caller), mCallee(callee), mArg0(arg0) {

        }

        inline FunctorV1M(const FunctorV1M& ref) 
            : mCaller(ref.mCaller), mCallee(ref.mCallee), mArg0(mArg0) {}

        virtual void operator()() const {
            (mCaller->*mCallee)(mArg0);
        }

        virtual FunctorBase* clone(JKRHeap *pHeap) const {
            return new (pHeap, 0) FunctorV1M(*this);
        };

        T mCaller;
        U mCallee;
        V mArg0;
    };

    template<typename T, typename U>
    static FunctorV1M<T *, void (T::*)(U), U> Functor(T* caller, void (T::*callee)(U), U arg0) {
        return FunctorV1M<T *, void (T::*)(U), U>(caller, callee, arg0);
    }

    template<typename T, typename U, typename V, typename W>
    class FunctorV2M : public FunctorBase {
        public:
        inline FunctorV2M() { }

        inline FunctorV2M(T caller, U calee, V arg0, W arg1) :
        mCaller(caller), mCallee(calee), mArg0(arg0), mArg1(arg1) {

        }

        inline FunctorV2M(const FunctorV2M& ref) :
        mCaller(ref.mCaller), mCallee(ref.mCallee), mArg0(ref.mArg0), mArg1(ref.mArg1) { }

        virtual void operator()() const {
            (mCaller->*mCallee)(mArg0, mArg1);
        }

        virtual FunctorBase* clone(JKRHeap *pHeap) const {
            return new (pHeap, 0) FunctorV2M(*this);
        }

        T mCaller;
        U mCallee;
        V mArg0;
        W mArg1;
    };

    template<class T, typename U, typename V>
    static FunctorV2M<T *, void (T::*)(U, V), U, V> Functor(T* caller, void (T::*callee)(U, V), U arg0, V arg1) {
        return FunctorV2M<T *, void (T::*)(U, V), U, V>(caller, callee, arg0, arg1);
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
