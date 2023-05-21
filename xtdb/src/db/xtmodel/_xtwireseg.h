#ifndef _XTWIRE_H
#define _XTWIRE_H
#include "xtcore.h"
#include "_xtnetobject.h"
#include <vector>

namespace xtdb {
class _XtWireSeg : public _XtNetObject
{
public:
    _XtWireSeg();
    ~_XtWireSeg();
    uint mShapeId;
};
}
#endif // _XTWIRE_H
