#ifndef XTCORE_H
#define XTCORE_H
#include "xttypes.h"
#include "xtobjectpage.h"
#include "xttable.h"

class _XtObject
{
public:
    uint mIntId;
public:
    _XtObject(){};
    uint getExtId() const
    {
        uint offsetBits = (mIntId & XT_OFFSET_MASK);
        XtObjectPage* pageHeader = (XtObjectPage*)((char*)this - offsetBits - sizeof(XtObjectPage));
        uint pageIdx = pageHeader->mPageIdx;
        offsetBits/pageHeader->mTable->
        return pageIdx |
    }
};

class _XtFreeObject : public _XtObject
{
public:
    uint mNext;
};

#endif // XTCORE_H
