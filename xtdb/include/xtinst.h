#ifndef XTINST_H
#define XTINST_H
#include "xttypes.h"
#include "xtcontainer.h"
#include "xtpoint.h"
#include "xtopermat.h"
#include "xtdm.h"
#include "xteobject.h"

namespace xtdb {
class XtBlock;
class XtRectangle;
class XtInst : public XtEObject
{
public:
    static XtInst* create(XtBlock* pBlock);
    const char* getCellViewName();
    void setOrigin(const XtPoint& pPnt);
    void setTransform(const XtOperMat& pOperMat);
    void setBlockId(uint pBlockId);
    void setCellViewName(const char* pCellViewNm);
    void setName(const char* pName);
    XtRectangle* getShape();
    bool placed();
    bool operator==(const XtInst& pRhs) const;
};
}
#endif // XTINST_H
