#ifndef XTSET_H
#define XTSET_H
#include "xtiterator.h"
#include "xtcontainer.h"
namespace xtdb {
template <typename T>
class XtSet
{
private:
    void* mContainer;
public:
    XtSet(void* pContainer);
    XtIterator<T> begin();
    XtIterator<T> end();
    bool empty();
    uint size();
};

template <typename T>
XtIterator<T> XtSet<T>::begin()
{
    XtContainer* xtcontainer = reinterpret_cast<XtContainer*>(mContainer);
    return XtIterator<T>(xtcontainer, xtcontainer->begin());
}

template <typename T>
XtIterator<T> XtSet<T>::end()
{
    XtContainer* xtcontainer = reinterpret_cast<XtContainer*>(mContainer);
    return XtIterator<T>(xtcontainer, xtcontainer->end());
}

template <typename T>
XtSet<T>::XtSet(void* pContainer):mContainer(pContainer)
{

}

template <typename T>
bool XtSet<T>::empty()
{
    return (begin() == end());
}

template <typename T>
uint XtSet<T>::size()
{
    XtContainer* xtcontainer = reinterpret_cast<XtContainer*>(mContainer);
    return xtcontainer->size();
}
}
#endif // XTSET_H
