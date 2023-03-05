#ifndef XTSET_HPP
#define XTSET_HPP
#include "xtset.h"
#include "xtcontainer.h"
namespace xtdb {
template <typename T>
XtIterator<T> XtSet<T>::begin()
{
    XtContainer* xtcontainer = (XtContainer*)mContainer;
    return XtIterator<T>(xtcontainer, xtcontainer->begin());
}

template <typename T>
XtIterator<T> XtSet<T>::end()
{
    XtContainer* xtcontainer = (XtContainer*)mContainer;
    return XtIterator<T>(xtcontainer, xtcontainer->end());
}

template <typename T>
XtSet<T>::XtSet(void* pContainer):mContainer(pContainer)
{

};
}
#endif //XTSET_HPP
