#ifndef XTPOINT_H
#define XTPOINT_H
#include "xtstream.h"

namespace xtdb {
class XtPoint
{
public:
    XtPoint();
    XtPoint(int pX, int pY);
    int mX;
    int mY;
};
inline XtPoint::XtPoint():mX(0), mY(0){};
inline XtPoint::XtPoint(int pX, int pY):mX(pX), mY(pY){};
XtOStream& operator<<(XtOStream& pOS, XtPoint& pPnt);
XtIStream& operator>>(XtIStream& pIS, XtPoint& pPnt);
}
#endif // XTPOINT_H
