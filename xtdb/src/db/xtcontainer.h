#ifndef XTCONTAINER_H
#define XTCONTAINER_H
#include <xttypes.h>

class XtContainer
{
public:
    virtual uint begin() const = 0;
    virtual uint end() const = 0;
    virtual uint next(uint pExtId) const = 0;
};

#endif // XTITERATOR_H
