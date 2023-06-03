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

xtobject_kind _XtObject::getKind() const
{
    return getTable()->mKind;
}

void* _XtObject::getExtendedObj(uint pExtendedClassId) const
{
    return mExtendedObjMap.at(pExtendedClassId);
}

void _XtObject::setExtendedObj(uint pExtendedClassId, void* pExtendedObj)
{
    mExtendedObjMap[pExtendedClassId] = pExtendedObj;
}

XtObject::XtObject()
{

}

void XtObject::setExtendedObj(uint pExtendedClassId, void* pExtendedObj)
{
    reinterpret_cast<_XtObject*>(this)->setExtendedObj(pExtendedClassId, pExtendedObj);
}

void* XtObject::getExtendedObj(uint pExtendedClassId) const
{
    return reinterpret_cast<const _XtObject*>(this)->getExtendedObj(pExtendedClassId);
}

uint XtObject::getId() const
{
    return reinterpret_cast<const _XtObject*>(this)->getExtId();
}

bool XtObject::isAlive() const
{
    return reinterpret_cast<const _XtObject*>(this)->isAllocated();
}

xtobject_kind XtObject::getKind() const
{
    const _XtObject* obj = reinterpret_cast<const _XtObject*>(this);
    XtObjectTable* tbl = obj->getTable();
    return tbl->getObjKind();
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
