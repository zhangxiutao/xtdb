#include "xtiterator.h"
#include "xtcontainer.h"

inline XtIterator& XtIterator::operator++()
{
    mId = mContainer->next(mId);
    return *this;
}

inline XtIterator XtIterator::operator++(int)
{
    uint tmpId = mId;
    mId = mContainer->next(mId);
    return XtIterator(mContainer, tmpId);
}
