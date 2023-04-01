#ifndef XTCORE_H
#define XTCORE_H
#include "xttypes.h"
#include "xtobjectpage.h"
#include "xtstream.h"
#include <unordered_map>

namespace xtdb {

class _XtObject
{
public:
    uint mIntId;
    std::unordered_map<uint, void*> mExtendedObjMap;
public:
    void* getExtendedObj(uint pExtendedClassId) const;
    void setExtendedObj(uint pExtendedClassId, void* pExtendedObj);
    uint getExtId() const;
    XtObjectPage* getPageHeader() const;
    XtObjectTable* getTable() const;
    bool isAllocated() const;
    _XtObject* getOwner() const;
    _XtObject(){};
    ~_XtObject(){};
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
    _XtObject* mOwner;
    XtObjectTable(uint pObjSize, _XtObject* pObj):mObjSize(pObjSize), mOwner(pObj){};
};

XtOStream& operator<<(XtOStream& pOS, _XtFreeObject& pFreeObj);
XtIStream& operator>>(XtIStream& pOS, _XtFreeObject& pFreeObj);
}
#endif // XTCORE_H
