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
        uint offsetBits = (mIntId & XT_INTID_OFFSET_MASK);
        XtObjectPage* pageHeader = (XtObjectPage*)((char*)this - offsetBits - sizeof(XtObjectPage));
        uint offsetObjs = offsetBits/(pageHeader->mTable->mObjSize);
        return pageHeader->mPageShiftedIdx | offsetObjs;
    }
    XtObjectPage* getPageHeader()
    {
        uint offsetBits = (mIntId & XT_INTID_OFFSET_MASK);
        XtObjectPage* pageHeader = (XtObjectPage*)((char*)this - offsetBits - sizeof(XtObjectPage));
        return pageHeader;
    }
    bool isAllocated() const
    {
        if (mIntId & XT_INTID_ALLOC_BIT) {
            return true;
        } else {
            return false;
        }
    }
};

class _XtFreeObject : public _XtObject
{
public:
    uint mNext;
};

#endif // XTCORE_H
