#ifndef XTRECTANGLE_H
#define XTRECTANGLE_H
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
    static _XtRectangle* create(_XtBlock* pBlock);
};

#endif // XTRECTANGLE_H
