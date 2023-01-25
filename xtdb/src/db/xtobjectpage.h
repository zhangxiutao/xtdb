#ifndef XTOBJECTPAGE_H
#define XTOBJECTPAGE_H
#include "xttypes.h"
#include "xttable.h"
template <typename T>
class XtObjectPage
{
public:
    uint mPageIdx;
    XtTable<T>* mTable;
    XtObjectPage();
};

#endif // XTOBJECTPAGE_H
