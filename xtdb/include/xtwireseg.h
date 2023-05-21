#ifndef XTWIRESEG_H
#define XTWIRESEG_H
#include "xtnetobject.h"

namespace xtdb {
class XtBlock;
class XtNet;
class XtWireSeg : public XtNetObject
{
public:
    static XtWireSeg* create(XtBlock* pBlock);
    void destroy();
    void setNet(XtNet* pNet);
    XtNet* getNet();
};
}
#endif // XTWIRESEG_H
