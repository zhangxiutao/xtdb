#ifndef XTHASHTABLE_HPP
#define XTHASHTABLE_HPP
#include "xthashtable.h"
namespace xtdb {
template <typename T>
XtHashTable<T>::XtHashTable(XtTable<T>* pTbl):mData(nullptr), mTbl(pTbl), mObjCnt(1), mCapacity(0)
{
}
template <typename T>
XtHashTable<T>::~XtHashTable()
{
    delete [] mData;
}
template <typename T>
uint XtHashTable<T>::hashString(const char* str)
{
    uint hash = 0;
    while (uint ch = (uint)*str++)
    {
        hash = hash * 131 + ch;
    }
    return hash%mCapacity;
}
template <typename T>
void XtHashTable<T>::insert(T* pObj)
{
    if (0 == mCapacity) {
        mData = new uint();
        mCapacity++;
    }
    uint hashid = hashString(pObj->mName);
    if (0 != mData[hashid]) {
        T* headObj = (T*)(mTbl->getPtr(mData[hashid]));
        pObj->mNext = headObj->mNext;
        headObj->mNext = pObj->getExtId();
    } else {
        mData[hashid] = pObj->getExtId();
    }
    mObjCnt++;
    if (mObjCnt >= mCapacity * overLoadingFactor) {
        growTable();
    }
}
template <typename T>
void XtHashTable<T>::growTable()
{
    uint* origData = mData;
    mData = new uint[mCapacity * 2]();
    for (uint i = 0; i < mCapacity; i++)
    {
        if (0 != origData[i]) {
            uint cur = origData[i];
            while (0 != cur)
            {
                T* curObj = (T*)(mTbl->getPtr(cur));
                uint next = curObj->mNext;
                insert(curObj);
                cur = next;
            }
        }
    }
    /*
    uint headLastReversedList = 0;
    uint l,m,r;
    for (uint i = 0; i < mCapacity; i++)
    {
        if (0 != mData[i]) {
            l = mData[i];
            m = mTbl.getPtr(mData[i])->mNext;
            if (0 == m) {
                headLastReversedList = l;
                break;
            }
            r = mTbl.getPtr(m)->mNext;
            if (0 == r) {
                mTbl.getPtr(l)->mNext = headLastReversedList;
                mTbl.getPtr(m)->mNext = l;
                headLastReversedList = m;
                break;
            }
        }
        mTbl.getPtr(l)->mNext = headLastReversedList;
        while (true)
        {
            mTbl.getPtr(m)->mNext = l;
            l = m;
            m = r;
            r = mTbl.getPtr(r)->mNext;
        }
    }*/
}
template <typename T>
T* XtHashTable<T>::find(const char* pName)
{
    uint cur = mData[hashString(pName)];
    while (0 != cur)
    {
        T* obj = (T*)mTbl->getPtr(cur);
        if (pName == obj->mName) {
            return obj;
        } else {
            cur = obj->mNext;
        }
    }
    return nullptr;
}
template <typename T>
void XtHashTable<T>::remove(const char* pName)
{
    uint prev = 0;
    uint hashId = hashString(pName);
    uint cur = mData[hashId];
    while (0 != cur)
    {
        T* curObj = (T*)(mTbl->getPtr(cur));
        if (pName == curObj->mName) {
            if (0 == prev) {
                mData[hashId] = curObj->mNext;
            } else {
                T* prevObj = (T*)(mTbl->getPtr(prev));
                prevObj->mNext = curObj->mNext;
            }
            curObj->mNext = 0;
            break;
        } else {
            prev = cur;
            cur = curObj->mNext;
        }
    }
}
}
#endif // XTHASHTABLE_HPP
