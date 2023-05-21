#ifndef XTCONTAINER_H
#define XTCONTAINER_H
#include <xttypes.h>
namespace xtdb {
class _XtObject;
class XtContainer
{
public:
    virtual uint begin() const = 0;
    virtual uint end() const = 0;
    virtual uint next(uint pExtId) const = 0;
    virtual _XtObject* getPtr(uint pExtId) const = 0;
    virtual uint size() const = 0;
    virtual bool empty() const = 0;
};
}
#endif // XTITERATOR_H
