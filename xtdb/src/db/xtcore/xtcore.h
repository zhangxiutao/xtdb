#ifndef XTCORE_H
#define XTCORE_H
#include "xttypes.h"
#include "xtstream.h"
#include "xtobjectpage.h"
#include <unordered_map>
#include "xtcontainer.h"

namespace xtdb {
class _XtObject
{
public:
    uint mIntId;
    std::unordered_map<uint, void*> mExtendedObjMap; //TODO: consider the technique unsed for PCContainer as well
public:
    void* getExtendedObj(uint pExtendedClassId) const;
    void setExtendedObj(uint pExtendedClassId, void* pExtendedObj);
    uint getExtId() const;
    XtObjectPage* getPageHeader() const;
    XtObjectTable* getTable() const;
    bool isAllocated() const;
    _XtObject* getOwner() const;
    xtobject_kind getKind() const;
    _XtObject(){};
    ~_XtObject(){};
};

class _XtFreeObject : public _XtObject
{
public:
    uint mNext;
};

class XtObjectTable : public XtContainer
{
public:
    uint mObjSize;
    _XtObject* mOwner;
    xtobject_kind mKind;
    XtObjectTable(uint pObjSize, _XtObject* pObj, xtobject_kind pKind):mObjSize(pObjSize), mOwner(pObj), mKind(pKind){};
    xtobject_kind getObjKind() const {return mKind; };
};

class _XtNamedObject
{
public:
    char* mName;
    uint mNext;
    uint mDoubleLLPrev; //support double linked list of xthashtable
    uint mDoubleLLNext;
    _XtNamedObject():mName(nullptr), mNext(0), mDoubleLLPrev(0), mDoubleLLNext(0){};
};

XtOStream& operator<<(XtOStream& pOS, _XtFreeObject& pFreeObj);
XtIStream& operator>>(XtIStream& pOS, _XtFreeObject& pFreeObj);
}
#endif // XTCORE_H
