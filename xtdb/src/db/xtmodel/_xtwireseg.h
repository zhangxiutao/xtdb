#ifndef _XTWIRE_H
#define _XTWIRE_H
#include "xtcore.h"
#include "_xtnetobject.h"
#include <vector>

namespace xtdb {
class XtContainer;
class _XtWireSeg : public _XtNetObject
{
public:
    uint mShapeId; //TODO:is it better to use pointer to point to the shape? Then we may get rid of XtContainer
    xtobject_kind mShapeKind;
    static xtobject_kind mKind;
    _XtWireSeg();
    ~_XtWireSeg();
    bool operator==(const _XtWireSeg& pRhs);
};
XtIStream& operator>>(XtIStream& pIS, _XtWireSeg& pWireSeg);
XtOStream& operator<<(XtOStream& pOS, _XtWireSeg& pWireSeg);
}
#endif // _XTWIRE_H
