#ifndef XTSETITERATOR_H
#define XTSETITERATOR_H
#include "xttypes.h"
#include "xtcontainer.h"

namespace xtdb {
template <typename T>
class XtIterator
{
private:
    void* mContainer;
    uint mExtId;
public:
    XtIterator(void* pContainer, uint pId);
    XtIterator& operator++();
    XtIterator operator++(int);
    bool operator==(const XtIterator& pItr);
    bool operator!=(const XtIterator& pItr);
    T operator*();
    T operator->();
};

template <typename T>
XtIterator<T>::XtIterator(void* pContainer, uint pId):
    mContainer(pContainer), mExtId(pId)
{

}

template <typename T>
inline XtIterator<T>& XtIterator<T>::operator++()
{
    mExtId = reinterpret_cast<XtContainer*>(mContainer)->next(mExtId);
    return *this;
}

template <typename T>
inline XtIterator<T> XtIterator<T>::operator++(int)
{
    uint tmpId = mExtId;
    mExtId = reinterpret_cast<XtContainer*>(mContainer)->next(mExtId);
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
inline T XtIterator<T>::operator*()
{
    return reinterpret_cast<T>(reinterpret_cast<XtContainer*>(mContainer)->getPtr(mExtId));
}

template <typename T>
inline T XtIterator<T>::operator->()
{
    return reinterpret_cast<T>(reinterpret_cast<XtContainer*>(mContainer)->getPtr(mExtId));
}

}
#endif // XTSETITERATOR_H
