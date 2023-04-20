#ifndef XTPOINT_H
#define XTPOINT_H
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
}
#endif // XTPOINT_H
