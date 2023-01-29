#ifndef XTITERATOR_H
#define XTITERATOR_H
#include <xttypes.h>

class XtIterator
{
public:
    XtIterator();
    virtual uint begin() = 0;
    virtual uint next(uint pExtId) = 0;
};

#endif // XTITERATOR_H
