#ifndef XTRECTANGLE_H
#define XTRECTANGLE_H
#include "_xtshape.h"
class XtBlock;
class XtRectangle: public _XtShape
{
public:
    static XtRectangle* create(XtBlock* pBlock);
    void setCoodinates(int pX1, int pY1, int pX2, int pY2);
};
#endif // XTRECTANGLE_H
