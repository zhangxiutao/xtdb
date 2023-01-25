#ifndef XTTABLE_H
#define XTTABLE_H
#include "xttypes.h"

class XtTablePage;
class _XtFreeObject;

template <typename T>
class XtTable
{
private:
    XtTablePage **mPages;
    uint mFreeList;
    uint mPageCnt;
    uint mPageCap;
    uint mPageSize;
    uint mPageMask;
    uint mPageShift;
    uint mObjSize;
public:
    XtTable(uint pPageSize = 128);
    void reallocPages();
    char *getPtr(uint pId);
    void newPage();
    T *create();
    _XtFreeObject* pop();
};

#endif // XTTABLE_H
