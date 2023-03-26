#include "xtcore.h"
#include "xtobject.h"

namespace xtdb {
uint _XtObject::getExtId() const
{
    uint offsetBits = (mIntId & XT_INTID_OFFSET_MASK);
    XtObjectPage* pageHeader = (XtObjectPage*)((char*)this - offsetBits - sizeof(XtObjectPage));
    uint offsetObjs = offsetBits/(pageHeader->mTable->mObjSize);
    return pageHeader->mPageShiftedIdx | offsetObjs;
}

XtObjectPage* _XtObject::getPageHeader() const
{
    uint offsetBits = (mIntId & XT_INTID_OFFSET_MASK);
    XtObjectPage* pageHeader = (XtObjectPage*)((char*)this - offsetBits - sizeof(XtObjectPage));
    return pageHeader;
}

bool _XtObject::isAllocated() const
{
    if (mIntId & XT_INTID_ALLOC_BIT)
    {
        return true;
    }
    else
    {
        return false;
    }
}

XtObjectTable* _XtObject::getTable() const
{
    return getPageHeader()->mTable;
}

_XtObject* _XtObject::getOwner() const
{
    return getTable()->mOwner;
}

XtObject::XtObject()
{

}

uint XtObject::getId() const
{
    return ((_XtObject*)this)->getExtId();
}

bool XtObject::isAlive() const
{
    _XtObject* obj = (_XtObject*)this;
    return obj->isAllocated();
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
}
