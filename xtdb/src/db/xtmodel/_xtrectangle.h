#ifndef _XTRECTANGLE_H
#define _XTRECTANGLE_H
#include "_xtshape.h"
#include "xtrect.h"

namespace xtdb {
class _XtBlock;
template <typename T>
class XtQuadtreeNode;
class _XtRectangle: public _XtShape, public _XtNamedObject
{
public:
    int mX1;
    int mY1;
    int mX2;
    int mY2;
    int mW;
    int mH;
    XtQuadtreeNode<_XtRectangle*>* mOwnerNode;
    static xtobject_kind mKind;
public:
    _XtRectangle();
    ~_XtRectangle(){};
    XtRect getZone();
    XtQuadtreeNode<_XtRectangle*>* getOwnerNode();
    bool operator==(const _XtRectangle& pRhs);
    bool operator!=(const _XtRectangle& pRhs);
};
XtOStream& operator<<(XtOStream& pOS, _XtRectangle& pRect);
XtIStream& operator>>(XtIStream& pIS, _XtRectangle& pRect);
}
#endif // _XTRECTANGLE_H
