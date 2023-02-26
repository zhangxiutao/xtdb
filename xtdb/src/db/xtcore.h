#ifndef XTCORE_H
#define XTCORE_H
#include "xttypes.h"
#include "xtobjectpage.h"
#include "xtobjecttable.h"
#include "xtstream.h"

namespace xtdb {

class _XtObject
{
public:
    uint mIntId;
public:
    _XtObject(){};
    uint getExtId() const;
    XtObjectPage* getPageHeader() const;
    XtObjectTable* getTable() const;
    bool isAllocated() const;
    _XtObject* getOwner() const;
};

class _XtFreeObject : public _XtObject
{
public:
    uint mNext;
};

class XtObjectTable
{
public:
    uint mObjSize;
    _XtObject* mOwner; //先定义为_XtObject*试一下，如果要定义为_XtObject，我必须把XtObjectTable也放在xtcore.h不然会循环依赖。
    XtObjectTable(uint pObjSize, _XtObject* pObj):mObjSize(pObjSize), mOwner(pObj){};
};

XtOStream& operator<<(XtOStream& pOS, _XtFreeObject& pFreeObj);
XtIStream& operator>>(XtIStream& pOS, _XtFreeObject& pFreeObj);
}
#endif // XTCORE_H
