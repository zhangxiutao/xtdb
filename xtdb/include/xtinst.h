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
    std::string getCellViewNm();
    void setOrigin(const XtPoint& pPnt);
    void setTransform(const XtOperMat& pOperMat);
    XtRectangle* getShape();
};
}
#endif // XTINST_H
