#ifndef XTNET_H
#define XTNET_H
#include "xteobject.h"
#include "xtblock.h"

namespace xtdb {
class XtNetObject;
class XtWireSeg;
class XtNet : public XtEObject
{
public:
    void setName(const char* pName);
    static XtNet* create(XtBlock* pBlock);
    XtSet<XtNetObject*> getNetObjects();
    XtSet<XtWireSeg*> getWiresegs();
};
}
#endif // XTNET_H
