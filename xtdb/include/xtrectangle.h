#ifndef XTRECTANGLE_H
#define XTRECTANGLE_H
#include "xtshape.h"
namespace xtdb {
class XtBlock;
class XtRectangle: public XtShape
{
public:
    static XtRectangle* create(XtBlock* pBlock);
    void destroy();
    void setCoodinates(int pX1, int pY1, int pX2, int pY2);
    int getX1();
    int getY1();
    int getX2();
    int getY2();
    void setX1(int pX1);
    void setY1(int pY1);
    void setX2(int pX2);
    void setY2(int pY2);
};
}
#endif // XTRECTANGLE_H
