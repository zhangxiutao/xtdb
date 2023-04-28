#include "xtpoint.h"

namespace xtdb {
XtOStream& operator<<(XtOStream& pOS, XtPoint& pPnt)
{
    pOS << pPnt.mX;
    pOS << pPnt.mY;
    return pOS;
}
XtIStream& operator>>(XtIStream& pIS, XtPoint& pPnt)
{
    pIS >> pPnt.mX;
    pIS >> pPnt.mY;
    return pIS;
}
}
