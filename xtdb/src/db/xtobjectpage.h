#ifndef XTOBJECTPAGE_H
#define XTOBJECTPAGE_H
#include "xttypes.h"
#include "xttable.h"
class XtObjectTable;
class XtObjectPage
{
public:
    uint mPageShiftedIdx;
    XtObjectTable* mTable;
    XtObjectPage();
};

#endif // XTOBJECTPAGE_H
