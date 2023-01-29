#ifndef XTSTREAM_HPP
#define XTSTREAM_HPP
#include <cstdlib>
#include "xttablepage.h"
#include "xttable.h"
#include "xtcore.h"
#include <new>
#include <cmath>
#include <cstdio>
template <typename T>
XtTable<T>::XtTable(uint pPageSize):
    mPages(nullptr),mFreeList(0),mPageCnt(0),mPageCap(0),
    mPageSize(pPageSize), mPageMask(pPageSize - 1),mPageShift(log2(pPageSize)),
    mTopId(0), mBottomId(0), XtObjectTable(sizeof(T))
{
}

template <typename T>
void XtTable<T>::newPage()
{
    if (mPageCap == mPageCnt) {
        reallocPages();
    }
    XtTablePage *page = (XtTablePage*)malloc(sizeof(XtObjectPage) + mPageSize*sizeof(T));
    mPages[mPageCnt] = page;

    //update page header
    page->mPageShiftedIdx = mPageCnt << mPageShift;
    page->mTable = this;
    page->mAllocCnt = 0;
    char* last = (char*)page + sizeof(XtObjectPage) + mPageMask*sizeof(T);
    ((_XtFreeObject*)last)->mNext = 0;
    ((_XtObject*)last)->mIntId = mPageMask*sizeof(T);
    mFreeList = ((_XtObject*)last)->getExtId();

    for(int i = mPageMask - 1; i >= 0 ; i--) {
        uint offsetBits = i*sizeof(T);
        char* cur = (char*)page + sizeof(XtObjectPage) + offsetBits;
        ((_XtObject*)cur)->mIntId = offsetBits;
        pushFreeList((_XtFreeObject*)cur);
    }
    if (0 == mPageCnt) {
        popFreeList();
        //id 0 is reserved for expressing "there is no next object" in next(), therefore pop id 0;
        mBottomId = 1;
    }
    mPageCnt += 1;
}

template <typename T>
void XtTable<T>::reallocPages()
{
    if (0 == mPageCap) {
        mPageCap = 1;
    } else {
        mPageCap *= 2;
    }
    XtTablePage **tmp = new XtTablePage*[mPageCap];
    for (uint i = 0; i < mPageCnt; i++) {
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
_XtObject* XtTable<T>::getPtr(uint pExtId)//这个pId的低mPageShift位指的是长为sizeof(T)的基向量的下标。
{
    return (_XtObject*)((char*)(mPages[pExtId >> mPageShift]) + sizeof(XtObjectPage) + sizeof(T) * (pExtId & mPageMask));
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
}

template <typename T>
uint XtTable<T>::begin()
{
    return mBottomId;
}

template <typename T>
uint XtTable<T>::next(uint pExtId)
{
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
        if ((pExtId >> mPageShift) >= mPageCnt) {
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
#endif // XTSTREAM_HPP
