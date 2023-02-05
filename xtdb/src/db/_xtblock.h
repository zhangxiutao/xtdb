#ifndef XTBLOCK_H
#define XTBLOCK_H
#include "xttable.hpp"
#include "_xtrectangle.h"
class _XtBlock
{
public:
    _XtBlock();
    XtTable<_XtRectangle> mRectTbl; //我不能new一个_XtShape，所以XtTable<_XtShape>::create()应该是会编译报错的。XtTable的模板参数一定是具体类。

    //getAllShapes是怎么实现的？难道是将所有存储shape的table的信息综合起来生成一个新的table？这样效率不是很低？

};

#endif // XTBLOCK_H
