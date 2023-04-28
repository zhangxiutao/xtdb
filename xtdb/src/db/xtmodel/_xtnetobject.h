#ifndef _XTNETOBJECT_H
#define _XTNETOBJECT_H
#include "_xteobject.h"
#include <vector>
namespace xtdb {
class _XtNetObject : public _XtEObject
{
public:
    _XtNetObject();
    uint mNetId;
    std::vector<uint> mConnWireSegIds;
    std::vector<uint> mConnViaIds;
    std::vector<uint> mConnPortIds;
    std::vector<uint> mConnectedViaIds;
};
}
#endif // _XTNETOBJECT_H
