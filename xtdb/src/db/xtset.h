#ifndef XTSET_H
#define XTSET_H
#include "xtiterator.h"
#include "xtcontainer.h"

template <typename T>
class XtSet
{
private:
    void* mContainer;
public:
    XtSet(void* pContainer);
    XtIterator<T> begin();
    XtIterator<T> end();
};

#endif // XTSET_H
