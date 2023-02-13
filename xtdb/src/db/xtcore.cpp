#include "xtcore.h"

uint _XtObject::getExtId() const
{
    uint offsetBits = (mIntId & XT_INTID_OFFSET_MASK);
    XtObjectPage* pageHeader = (XtObjectPage*)((char*)this - offsetBits - sizeof(XtObjectPage));
    uint offsetObjs = offsetBits/(pageHeader->mTable->mObjSize);
    return pageHeader->mPageShiftedIdx | offsetObjs;
}
XtObjectPage* _XtObject::getPageHeader()
{
    uint offsetBits = (mIntId & XT_INTID_OFFSET_MASK);
    XtObjectPage* pageHeader = (XtObjectPage*)((char*)this - offsetBits - sizeof(XtObjectPage));
    return pageHeader;
}
bool _XtObject::isAllocated() const
{
    if (mIntId & XT_INTID_ALLOC_BIT) {
        return true;
    } else {
        return false;
    }
}

XtOStream& operator<<(XtOStream& pOS, _XtFreeObject& pFreeObj)
{
    pOS << pFreeObj.mNext;
    return pOS;
}

XtIStream& operator>>(XtIStream& pIS, _XtFreeObject& pFreeObj)
{
    pIS >> pFreeObj.mNext;
    return pIS;
}
