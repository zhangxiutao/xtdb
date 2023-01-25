#ifndef XTBLOCK_H
#define XTBLOCK_H
#include "xttable.hpp"
#include "_xtrectangle.h"
class _XtBlock
{
public:
    _XtBlock();
    XtTable<_XtRectangle> mRectTbl; //我不能new一个_XtShape，所以XtTable<_XtShape>::create()应该是会编译报错的。
    //getAllShapes是怎么实现的？
};

#endif // XTBLOCK_H
