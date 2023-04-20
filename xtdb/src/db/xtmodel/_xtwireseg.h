#ifndef _XTWIRE_H
#define _XTWIRE_H
#include "xtcore.h"
#include "_xtnetobject.h"
#include <vector>

namespace xtdb {
class _XtNet;
class _XtShape;
class _XtVia;
class _XtWireSeg : public _XtNetObject
{
public:
    _XtWireSeg();
    _XtNet* mNet;
    _XtShape* mShape;
    std::vector<_XtWireSeg*> mConnectedWireSegs;
    std::vector<_XtVia*> mConnectedVias;
};
}
#endif // _XTWIRE_H
