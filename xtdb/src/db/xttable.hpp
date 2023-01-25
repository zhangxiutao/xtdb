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
    XtObjectTable(sizeof(T))
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
    mFreeList = mPageCnt << mPageShift;
    for(uint i = 0; i < mPageMask; i++) {
        uint offsetBits = i*sizeof(T);
        char* cur = (char*)page + sizeof(XtObjectPage) + offsetBits;
        ((_XtFreeObject*)cur)->mNext = i + 1;
        ((_XtObject*)cur)->mIntId = offsetBits;
    }
    char* last = (char*)page + sizeof(XtObjectPage) + mPageMask*sizeof(T);
    ((_XtFreeObject*)last)->mNext = 0;
    ((_XtObject*)last)->mIntId = mPageMask*sizeof(T);

    //update page header
    page->mPageShiftedIdx = mPageCnt << mPageShift;
    page->mTable = this;
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
    T* objAddr = (T*)pop();
    new (objAddr) T();
    ((_XtObject*)objAddr)->mIntId = ((_XtObject*)objAddr)->mIntId | XT_ALLOC_BIT;
    return objAddr;
}

template <typename T>
_XtFreeObject* XtTable<T>::pop()
{
   _XtFreeObject* tmp = (_XtFreeObject*)getPtr(mFreeList);
   mFreeList = tmp->mNext;
   return tmp;
}

template <typename T>
char* XtTable<T>::getPtr(uint pId)//这个pId的低mPageShift位指的是长为sizeof(T)的基向量的下标。
{
    return (char*)(mPages[pId >> mPageShift]) + sizeof(XtObjectPage) + sizeof(T) * (pId & mPageMask);
}
#endif // XTSTREAM_HPP
