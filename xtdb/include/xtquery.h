#ifndef XTQUERY_H
#define XTQUERY_H
#include "xtrect.h"

namespace xtdb {
class XtBlock;
class XtQuery
{
protected:
    XtBlock* mBlock;
public:
    XtQuery(XtBlock* pBlock);
    virtual void query(const XtRect& pRegion, bool ONLY_FULLY_CONTAINED = false) = 0;
};
}

#endif // XTQUERY_H
