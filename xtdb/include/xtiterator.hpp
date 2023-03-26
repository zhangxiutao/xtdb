#ifndef XTITERATOR_HPP
#define XTITERATOR_HPP
#include "xtiterator.h"
#include "xtcontainer.h"
//TODO: merge hpp and h, since user is not used to include .hpp
namespace xtdb {
template <typename T>
XtIterator<T>::XtIterator(void* pContainer, uint pId):
    mContainer(pContainer), mExtId(pId)
{

}

template <typename T>
inline XtIterator<T>& XtIterator<T>::operator++()
{
    mExtId = ((XtContainer*)mContainer)->next(mExtId);
    return *this;
}

template <typename T>
inline XtIterator<T> XtIterator<T>::operator++(int)
{
    uint tmpId = mExtId;
    mExtId = ((XtContainer*)mContainer)->next(mExtId);
    return XtIterator(mContainer, tmpId);
}

template <typename T>
inline bool XtIterator<T>::operator==(const XtIterator& pItr)
{
    return mExtId == pItr.mExtId;
}

template <typename T>
inline bool XtIterator<T>::operator!=(const XtIterator& pItr)
{
    return mExtId != pItr.mExtId;
}

template <typename T>
inline T& XtIterator<T>::operator*()
{
    return *(T*)(((XtContainer*)mContainer)->getPtr(mExtId));
}

template <typename T>
inline T* XtIterator<T>::operator->()
{
    return (T*)(((XtContainer*)mContainer)->getPtr(mExtId));
}
}
#endif //XTITERATOR_HPP
