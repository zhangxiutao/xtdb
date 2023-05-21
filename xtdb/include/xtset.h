#ifndef XTSET_H
#define XTSET_H
#include "xtiterator.h"
#include "xtcontainer.h"
#include <algorithm>
#include <vector>
namespace xtdb {
template <typename T>
class XtSet
{
private:
    std::vector<void*> mContainers;
public:
    XtSet(void* pContainer);
    XtSet(std::vector<void*>&& pContainers);
    XtIterator<T> begin();
    XtIterator<T> end();
    bool empty();
    uint size();
};

template <typename T>
XtIterator<T> XtSet<T>::begin()
{
    XtContainer* xtcontainer = reinterpret_cast<XtContainer*>(mContainers.front());
    return XtIterator<T>(xtcontainer, xtcontainer->begin());
}

template <typename T>
XtIterator<T> XtSet<T>::end()
{
    XtContainer* xtcontainer = reinterpret_cast<XtContainer*>(mContainers.back());
    return XtIterator<T>(xtcontainer, xtcontainer->end());
}

template <typename T>
XtSet<T>::XtSet(void* pContainer)
{
    mContainers.push_back(pContainer);
}

template <typename T>
XtSet<T>::XtSet(std::vector<void*>&& pContainers)
{
    mContainers = std::move(pContainers);
}

template <typename T>
bool XtSet<T>::empty()
{
    return std::all_of(mContainers.begin(), mContainers.end(), [](void* pContainer){
        XtContainer* xtcontainer = reinterpret_cast<XtContainer*>(pContainer);
        return xtcontainer->empty();
    });
}

template <typename T>
uint XtSet<T>::size()
{
    uint size = 0;
    for (auto container : mContainers)
    {
        XtContainer* xtcontainer = reinterpret_cast<XtContainer*>(container);
        size += xtcontainer->size();
    }
    return size;
}
}
#endif // XTSET_H
