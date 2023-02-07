#ifndef XTCONTAINER_H
#define XTCONTAINER_H
#include <xttypes.h>

class XtContainer
{
public:
    virtual uint begin() = 0;
    virtual uint end() = 0;
    virtual uint next(uint pExtId) = 0;
};

#endif // XTITERATOR_H
