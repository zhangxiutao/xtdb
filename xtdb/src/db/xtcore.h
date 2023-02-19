#ifndef XTCORE_H
#define XTCORE_H
#include "xttypes.h"
#include "xtobjectpage.h"
#include "xttable.h"
namespace xtdb {


class _XtObject
{
public:
    uint mIntId;
public:
    _XtObject(){};
    uint getExtId() const;
    XtObjectPage* getPageHeader();
    bool isAllocated() const;
};

class _XtFreeObject : public _XtObject
{
public:
    uint mNext;
};

XtOStream& operator<<(XtOStream& pOS, _XtFreeObject& pFreeObj);
XtIStream& operator>>(XtIStream& pOS, _XtFreeObject& pFreeObj);
}
#endif // XTCORE_H
