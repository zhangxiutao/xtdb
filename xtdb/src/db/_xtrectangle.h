#ifndef _XTRECTANGLE_H
#define _XTRECTANGLE_H
#include "_xtshape.h"
class _XtBlock;
class _XtRectangle: public _XtShape
{
public:
    int mX1; //X1,Y1是先确定的点还是左上角的点？
    int mY1;
    int mX2;
    int mY2;
    int mW;
    int mH;
public:
    _XtRectangle();
    _XtRectangle(int pX1, int pY1, int pW, int pH, _XtTech::layer_type layer);
    bool operator==(const _XtRectangle& pRhs);
    bool operator!=(const _XtRectangle& pRhs);
};
XtOStream& operator<<(XtOStream& pOS, _XtRectangle& pRect);
XtIStream& operator>>(XtIStream& pIS, _XtRectangle& pRect);
#endif // _XTRECTANGLE_H
