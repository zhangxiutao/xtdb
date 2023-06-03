#include "_xtnetobject.h"
namespace xtdb {
_XtNetObject::_XtNetObject(): mNetId(0)
{

}
XtIStream& operator>>(XtIStream& pIS, _XtNetObject& pNetObject)
{
    pIS >> pNetObject.mNetId;
    pIS >> pNetObject.mConnWireSegIds;
    pIS >> pNetObject.mConnViaIds;
    pIS >> pNetObject.mConnPortIds;
    pIS >> pNetObject.mConnPortInstIds;
    return pIS;
}
XtOStream& operator<<(XtOStream& pOS, _XtNetObject& pNetObject)
{
    pOS << pNetObject.mNetId;
    pOS << pNetObject.mConnWireSegIds;
    pOS << pNetObject.mConnViaIds;
    pOS << pNetObject.mConnPortIds;
    pOS << pNetObject.mConnPortInstIds;
    return pOS;
}
}

