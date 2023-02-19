#ifndef XTSETITERATOR_H
#define XTSETITERATOR_H
#include "xttypes.h"
namespace xtdb {
class XtContainer;
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
    T& operator*();
    T* operator->();
};
}
#endif // XTSETITERATOR_H
