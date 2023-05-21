#ifndef _XTNETOBJECT_H
#define _XTNETOBJECT_H
#include "_xteobject.h"
#include <vector>
namespace xtdb {
class _XtNetObject : public _XtEObject, public _XtNamedObject
{
public:
    enum NETOBJECT_TYPE
    {
        WIRESEG,
        VIA,
        PORT,
        PORTINST
    };
    uint mNextNetObjId; //next net object with mNetId
    uint mNetId;
    NETOBJECT_TYPE mType;
    std::vector<uint> mConnWireSegIds;
    std::vector<uint> mConnViaIds;
    std::vector<uint> mConnPortIds;
    std::vector<uint> mConnPortInstIds;
    _XtNetObject(NETOBJECT_TYPE pType);
};
}
#endif // _XTNETOBJECT_H
