#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObj.h"
#include "Game/Util/Array.h"
#include "Game/Util/Functor.h"

/* FINISHED */

class NameObjDelegator {
public:
    virtual void operator()(NameObj *) = 0;
};

namespace {
    template<typename T>
    class NameObjRealDelegator : public NameObjDelegator {
    public:
        inline NameObjRealDelegator(T pFunc) {
            mFunctionPtr = pFunc;
        }

        void operator()(NameObj *pObj) {
            (pObj->*mFunctionPtr)(pObj, this);
        }

        T mFunctionPtr; // _4
    };
};

typedef void (NameObj::*TNameObjFunc)(const void *, void *);
typedef void (NameObj::*TNameObjConstFunc)(const void *, const void *);

struct CategoryListInitialTable {
    s32 mIndex; // _0
    s32 mCount; // _4
};

class NameObjCategoryList {
public:
    class CategoryInfo {
    public:
        CategoryInfo();
        ~CategoryInfo();

        MR::AssignableArray<NameObj*> mObjs; // _0
        s32 mObjsCount;                      // _8
        MR::FunctorBase* mExecuteFunction;   // _C
        s32 mChecks;                         // _10
    };

    NameObjCategoryList(u32 numCategories, const CategoryListInitialTable *initialTable, TNameObjFunc executeFunc, bool allocateBuffer, const char *pName);
    NameObjCategoryList(u32 numCategories, const CategoryListInitialTable *initialTable, TNameObjConstFunc executeFunc, bool allocateBuffer, const char *pName);

    ~NameObjCategoryList();

    void execute(int categoryType);
    void incrementCheck(NameObj *pObj, int categoryType);
    void allocateBuffer();
    void add(NameObj *pObj, int categoryType);
    void remove(NameObj *pObj, int categoryType);
    void registerExecuteBeforeFunction(const MR::FunctorBase &rFunc, int categoryType);
    bool isRegisteredExecuteFunction() const;
    void initTable(u32 numCategories, const CategoryListInitialTable *initialTable);

    MR::AssignableArray<NameObjCategoryList::CategoryInfo> mCategoryInfo; // _0
    NameObjDelegator* mDelegator;                                         // _8
    bool mBufferAllocated;                                                // _C
    bool mAllocateBuffer;                                                 // _D
};
