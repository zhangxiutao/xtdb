#ifndef XTOBJECTPAGE_H
#define XTOBJECTPAGE_H
#include "xttypes.h"
class XtObjectTable;
class XtObjectPage
{
public:
    uint mPageShiftedIdx; //the index of page, but shifted by XtTable::mPageShift
    uint mAllocCnt;
    XtObjectPage();
    XtObjectTable* mTable;
    bool isEmpty() {
        return 0 == mAllocCnt;
    }
};

#endif // XTOBJECTPAGE_H
