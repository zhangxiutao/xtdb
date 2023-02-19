#ifndef XTTABLEPAGE_H
#define XTTABLEPAGE_H
#include "xttypes.h"
#include "xtobjectpage.h"
//比较一下XtTablePage和XtObjectPage放在一个文件和分开的优缺点。
//xtcore.h就是放在一起。
namespace xtdb {
class XtTablePage : public XtObjectPage
{
public:
    char mObjects[1];
public:
    XtTablePage();
};
}
#endif // XTTABLEPAGE_H
