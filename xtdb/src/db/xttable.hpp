#ifndef XTTABLE_HPP
#define XTTABLE_HPP
#include "xttablepage.h"
#include "xttable.h"
#include "xtcore.h"
#include "xttypes.h"
#include <new>
#include <cmath>
#include <cstdio>
#include <cstdlib>
namespace xtdb {
template <typename T>
XtTable<T>::XtTable(_XtObject* pOwner, uint pPageSize):
    mPages(nullptr),mFreeList(0),mPagesCnt(0),mPagesCap(0),
    mPageSize(pPageSize), mPageMask(pPageSize - 1),mPageShift(log2(pPageSize)),
    mTopId(0), mBottomId(0), mAllocCnt(0), XtObjectTable(sizeof(T), pOwner)
{
}

template <typename T>
void XtTable<T>::newPage()
{
    if (mPagesCap == mPagesCnt) {
        reallocPages();
    }
    XtTablePage *page = (XtTablePage*)malloc(sizeof(XtObjectPage) + mPageSize*sizeof(T));
    mPages[mPagesCnt] = page;

    //update page header
    page->mPageShiftedIdx = mPagesCnt << mPageShift;
    page->mTable = this;
    page->mAllocCnt = 0;
    char* last = page->mObjects + mPageMask*sizeof(T);
    ((_XtFreeObject*)last)->mNext = 0;
    ((_XtObject*)last)->mIntId = mPageMask*sizeof(T);
    mFreeList = ((_XtObject*)last)->getExtId();

    for(int i = mPageMask - 1; i >= 0 ; i--) {
        uint offsetBits = i*sizeof(T);
        char* cur = page->mObjects + offsetBits;
        ((_XtObject*)cur)->mIntId = offsetBits;
        pushFreeList((_XtFreeObject*)cur);
    }
    if (0 == mPagesCnt) {
        popFreeList();
        //id 0 is reserved for expressing "there is no next object" in next(), therefore pop id 0;
        mBottomId = 1;
    }
    mPagesCnt += 1;
}

template <typename T>
void XtTable<T>::reallocPages()
{
    if (0 == mPagesCap) {
        mPagesCap = 1;
    } else {
        mPagesCap *= 2;
    }
    XtTablePage **tmp = new XtTablePage*[mPagesCap];
    for (uint i = 0; i < mPagesCnt; i++) {
        tmp[i] = mPages[i];
    }
    delete[] mPages;
    mPages = tmp;
}

template <typename T>
T* XtTable<T>::create()
{
    if (0 == mFreeList) {
        newPage();
    }
    T* objAddr = (T*)popFreeList();
    new (objAddr) T();
    objAddr->mIntId |= XT_INTID_ALLOC_BIT;
    objAddr->getPageHeader()->mAllocCnt++;
    uint extId = objAddr->getExtId();
    if (extId < mBottomId) {
        mBottomId = extId;
    }
    mAllocCnt++;
    return objAddr;
}

template <typename T>
_XtFreeObject* XtTable<T>::popFreeList()
{
   _XtFreeObject* tmp = (_XtFreeObject*)getPtr(mFreeList);
   mFreeList = tmp->mNext;
   return tmp;
}

template <typename T>
_XtObject* XtTable<T>::getPtr(uint pExtId) const//这个pId的低mPageShift位指的是长为sizeof(T)的基向量的下标。
{
    return (_XtObject*)(mPages[pExtId >> mPageShift]->mObjects + sizeof(T)*(pExtId & mPageMask));
}

template <typename T>
void XtTable<T>::pushFreeList(_XtFreeObject* pFreeObj)
{
    pFreeObj->mNext = mFreeList;
    mFreeList = pFreeObj->getExtId();
}

template <typename T>
void XtTable<T>::destroy(T* pObj)
{
    uint extId = pObj->getExtId();
    if (mBottomId == extId) {
        mBottomId = next(mBottomId);
    }
    pObj->~T();
    _XtFreeObject* freeObj = (_XtFreeObject*)pObj;
    pushFreeList(freeObj);
    freeObj->mIntId &= ~XT_INTID_ALLOC_BIT;
    ((_XtObject*)pObj)->getPageHeader()->mAllocCnt--;
    mAllocCnt--;
}

template <typename T>
uint XtTable<T>::begin() const
{
    return mBottomId;
}

template <typename T>
uint XtTable<T>::next(uint pExtId) const
{
    if (0 == pExtId)
    {
        return 0;
    }
    //search for the next T in the page of initial pExtId
    uint initPageIdx = pExtId >> mPageShift;
    pExtId++;
    while (true) {
        if (initPageIdx != pExtId >> mPageShift) {
            break;
        }
        if (isAllocated(pExtId)) {
            return pExtId;
        }
        pExtId++;
    }
    //search for the next non-empty page
    while (true) {
        if ((pExtId >> mPageShift) >= mPagesCnt) {
            //there is no next T
            return 0;
        }
        if (getPageHeader(pExtId)->isEmpty()) {
            //jump to the first id of next page
            pExtId = (pExtId + mPageSize) & ~mPageMask;
        } else {
            break;
        }
    }
    //search the for first T in the non-empty page
    while (true) {
        if (isAllocated(pExtId)) {
            return pExtId;
        }
        pExtId++;
    }
    //it is impossible to reach here
    return 0;
}

template <typename T>
bool XtTable<T>::operator==(const XtTable& pRhs) const
{
    if (mFreeList != pRhs.mFreeList
        || mPagesCnt != pRhs.mPagesCnt
        || mPagesCap != pRhs.mPagesCap
        || mPageSize != pRhs.mPageSize
        || mPageMask != pRhs.mPageMask
        || mPageShift != pRhs.mPageShift
        || mTopId != pRhs.mTopId
        || mBottomId != pRhs.mBottomId) {
        return false;
    }
    for (uint pageIdx = mPagesCnt; pageIdx < mPagesCnt; pageIdx++)
    {
        XtTablePage* page = mPages[pageIdx];
        T* obj = (T*)(page->mObjects);
        T* endObj = obj + mPageSize;

        XtTablePage* rhsPage = pRhs.mPages[pageIdx];
        T* rhsObj = (T*)(rhsPage->mObjects);
        T* rhsEndObj = rhsObj + pRhs.mPageSize;
        while (obj != endObj)
        {
            if (*obj != *rhsObj) {
                return false;
            }
            obj++;
        }
    }
    return true;
}

template <typename T>
XtOStream& operator<<(XtOStream& pOS, XtTable<T>& pTable)
{
    pOS << pTable.mFreeList;
    pOS << pTable.mPagesCnt;
    pOS << pTable.mPagesCap;
    pOS << pTable.mPageSize;
    pOS << pTable.mPageMask;
    pOS << pTable.mPageShift;
    pOS << pTable.mTopId;
    pOS << pTable.mBottomId;
    pOS << pTable.mAllocCnt;
    for (uint pageIdx = 0; pageIdx < pTable.mPagesCnt; pageIdx++)
    {
        for (uint idxInPage = 0; idxInPage < pTable.mPageSize; idxInPage++)
        {
            char allocated;
            uint id = pageIdx << pTable.mPageShift | idxInPage;
            if (pTable.isAllocated(id)) {
                allocated = 1;
                pOS << allocated;
                pOS << *(T*)(pTable.getPtr(id));
            } else {
                allocated = 0;
                pOS << allocated;
                pOS << *(_XtFreeObject*)(pTable.getPtr(id));
            }
        }
    }
    return pOS;
}

template <typename T>
XtIStream& operator>>(XtIStream& pIS, XtTable<T>& pTable)
{
    pIS >> pTable.mFreeList;
    pIS >> pTable.mPagesCnt;
    pIS >> pTable.mPagesCap;
    pIS >> pTable.mPageSize;
    pIS >> pTable.mPageMask;
    pIS >> pTable.mPageShift;
    pIS >> pTable.mTopId;
    pIS >> pTable.mBottomId;
    pIS >> pTable.mAllocCnt;
    pTable.mPages = new XtTablePage*[pTable.mPagesCap]; //similar to vector::reserve before push_back, avoid reallocating

    for (uint pageIdx = 0; pageIdx < pTable.mPagesCnt; pageIdx++)
    {
        XtTablePage* page = pTable.mPages[pageIdx];
        page = (XtTablePage*)malloc(sizeof(XtTablePage) + pTable.mPageSize*sizeof(T));
        page->mAllocCnt = 0;
        T* obj = (T*)(page->mObjects);
        T* endObj = obj + pTable.mPageSize;
        while (obj != endObj)
        {
            char allocated;
            pIS >> allocated;
            if (allocated) {
                page->mAllocCnt++;
                obj->mIntId = ((char*)obj - pTable.mPages[pageIdx]->mObjects) | XT_INTID_ALLOC_BIT;
                pIS >> *obj;
            } else {
                obj->mIntId = (char*)obj - pTable.mPages[pageIdx]->mObjects;
                _XtFreeObject* freeObj = (_XtFreeObject*)obj;
                pIS >> *(freeObj);
            }
            obj++;
        }
    }
    return pIS;
}

}
#endif // XTTABLE_HPP
