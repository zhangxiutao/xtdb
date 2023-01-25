#ifndef XTCOLOR_H
#define XTCOLOR_H
#include "xttypes.h"
//这么小的类需要一个文件吗？
class XtColor
{
public:
    uint r;
    uint g;
    uint b;
    uint a;
    XtColor(uint pR, uint pG, uint pB, uint pA):r(pR), g(pG), b(pB), a(pA){};
};
#endif // XTCOLOR_H
