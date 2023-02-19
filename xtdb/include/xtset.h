#ifndef XTSET_H
#define XTSET_H
#include "xtiterator.hpp"
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
};
}
#endif // XTSET_H
