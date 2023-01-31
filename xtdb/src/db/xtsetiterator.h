#ifndef XTSETITERATOR_H
#define XTSETITERATOR_H
#include "xttypes.h"

class XtContainer;
class XtSetIterator
{
public:
    XtSetIterator(XtContainer* pContainer, uint pId):
        mContainer(pContainer), mId(pId){}
    XtContainer* mContainer;
    uint mId;
    XtSetIterator& operator++();
    XtSetIterator operator++(int);
};

#endif // XTSETITERATOR_H
