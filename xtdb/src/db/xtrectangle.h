#ifndef XTRECTANGLE_H
#define XTRECTANGLE_H
#include "xtshape.h"
class XtBlock;
class XtRectangle: public XtShape
{
public:
    static XtRectangle* create(XtBlock* pBlock);
    void setCoodinates(int pX1, int pY1, int pX2, int pY2);
    int getX1();
    int getY1();
    int getX2();
    int getY2();
};
#endif // XTRECTANGLE_H
