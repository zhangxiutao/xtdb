#ifndef XTSETITERATOR_H
#define XTSETITERATOR_H
#include "xttypes.h"

class XtContainer;
class XtIterator
{
public:
    XtIterator(XtContainer* pContainer, uint pId):
        mContainer(pContainer), mId(pId){}
    XtContainer* mContainer;
    uint mId;
    XtIterator& operator++();
    XtIterator operator++(int);
};

#endif // XTSETITERATOR_H
