#include "xtsetiterator.h"
#include "xtcontainer.h"

inline XtSetIterator& XtSetIterator::operator++()
{
    mId = mContainer->next(mId);
    return *this;
}

inline XtSetIterator XtSetIterator::operator++(int)
{
    uint tmpId = mId;
    mId = mContainer->next(mId);
    return XtSetIterator(mContainer, tmpId);
}
