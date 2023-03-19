#ifndef XTHASHTABLE_HPP
#define XTHASHTABLE_HPP
#include "xthashtable.h"
namespace xtdb {
template <typename T>
XtHashTable<T>::XtHashTable(XtTable<T>* pTbl):mData(nullptr), mTbl(pTbl), mObjCnt(1), mCapacity(0), mHeadDoubleLL(0), mItr(0)
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
    if (mObjCnt >= mCapacity * overLoadingFactor)
    {
        growTable();
    }
    uint oid  = pObj->getExtId();
    if (0 == mHeadDoubleLL)
    {
        mHeadDoubleLL = oid;
    }
    else
    {
        T* headObjDoubleLL = (T*)(mTbl->getPtr(mHeadDoubleLL));
        headObjDoubleLL->mDoubleLLPrev = oid;
        pObj->mDoubleLLNext = mHeadDoubleLL;
        mHeadDoubleLL = oid;
    }
    uint hashid = hashString(pObj->mName);
    if (0 != mData[hashid])
    {
        T* headObj = (T*)(mTbl->getPtr(mData[hashid]));
        pObj->mNext = headObj->mNext;
        headObj->mNext = oid;
    }
    else
    {
        mData[hashid] = oid;
    }
    mObjCnt++;
    return;
}
template <typename T>
void XtHashTable<T>::growTable()
{
    if (0 == mCapacity)
    {
        mData = new uint();
        mCapacity++;
        return;
    }
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
    delete [] origData;
    return;
}
template <typename T>
T* XtHashTable<T>::find(const char* pName)
{
    uint cur = mData[hashString(pName)];
    while (0 != cur)
    {
        T* obj = (T*)(mTbl->getPtr(cur));
        if (pName == obj->mName)
        {
            return obj;
        }
        else
        {
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
        if (pName == curObj->mName)
        {
            if (0 == prev)
            {
                mData[hashId] = curObj->mNext;
            }
            else
            {
                T* prevObj = (T*)(mTbl->getPtr(prev));
                prevObj->mNext = curObj->mNext;
            }
            //support double linked list
            if (1 == mObjCnt) // head and tail is the same
            {
                mHeadDoubleLL = 0;
                curObj->mDoubleLLPrev = 0;
                curObj->mDoubleLLNext = 0;
                break;
            }
            if (mHeadDoubleLL == cur) //remove head obj
            {
                mHeadDoubleLL = curObj->mDoubleLLNext;
                T* nextObj =(T*)(mTbl->getPtr(curObj->mDoubleLLNext));
                nextObj->mDoubleLLPrev = 0;
                curObj->mDoubleLLNext = 0;
                break;
            }
            else if (0 == curObj->mDoubleLLNext) // remove tail obj
            {
                T* prevObj = (T*)(mTbl->getPtr(curObj->mDoubleLLPrev));
                prevObj->mDoubleLLNext = 0;
                curObj->mDoubleLLPrev = 0;
                break;
            }
            T* prevObj = (T*)(mTbl->getPtr(curObj->mDoubleLLPrev));
            T* nextObj =(T*)(mTbl->getPtr(curObj->mDoubleLLNext));
            prevObj->mDoubleLLNext = nextObj->getExtId();
            nextObj->mDoubleLLPrev = prevObj->getExtId();
            curObj->mDoubleLLPrev = 0;
            curObj->mDoubleLLNext = 0;
            break;
        }
        else
        {
            prev = cur;
            cur = curObj->mNext;
        }
    }
    mObjCnt--;
    return;
}
template <typename T>
void XtHashTable<T>::initItr()
{
    mItr = mHeadDoubleLL;
    return;
}
template <typename T>
T* XtHashTable<T>::next()
{
    if (0 == mItr)
    {
        return nullptr;
    }
    T* curObj = (T*)(mTbl->getPtr(mItr));
    mItr = curObj->mDoubleLLNext;
    return curObj;
}

}
#endif // XTHASHTABLE_HPP
