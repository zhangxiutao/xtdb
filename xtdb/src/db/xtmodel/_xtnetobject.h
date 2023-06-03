#ifndef _XTNETOBJECT_H
#define _XTNETOBJECT_H
#include "_xteobject.h"
#include <vector>
namespace xtdb {
class _XtNetObject : public _XtEObject, public _XtNamedObject
{
public:
    uint mNetId;
    std::vector<uint> mConnWireSegIds;
    std::vector<uint> mConnViaIds;
    std::vector<uint> mConnPortIds;
    std::vector<uint> mConnPortInstIds;
    _XtNetObject();
};
XtIStream& operator>>(XtIStream& pIS, _XtNetObject& pNetObject);
XtOStream& operator<<(XtOStream& pOS, _XtNetObject& pNetObject);
}
#endif // _XTNETOBJECT_H
