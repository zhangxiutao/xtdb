#ifndef XTSHAPEQUERY_H
#define XTSHAPEQUERY_H
#include "xtquery.h"

namespace xtdb {
class XtShape;
class XtShapeQuery : public XtQuery
{
public:
    XtShapeQuery(XtBlock* pBlock);
    void query(const XtRect& pRegion) override;
    virtual void onShapeFound(XtShape* pShape) = 0;
};

}

#endif // XTSHAPEQUERY_H
