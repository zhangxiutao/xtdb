#ifndef _XTINST_H
#define _XTINST_H
#include "_xteobject.h"
#include <unordered_map>
#include <vector>
#include <string>
#include "xtpoint.h"
#include "xtopermat.h"

namespace xtdb {
class XtBlock;
class _XtInst : public _XtEObject
{
public:
    char* mName;
    char* mCellNm;
    char* mViewNm;
    uint mShapeId;
    XtPoint mOrigin;
    XtOperMat mTransform;
    std::vector<uint> mPortInstIds;
//    std::unordered_map<std::string, std::string> mCustomParams;
public:
   _XtInst();
    void setOrigin(const XtPoint& pPnt);
    void setTransform(const XtOperMat& pOperMat);
};
XtOStream& operator<<(XtOStream& pOS, _XtInst& pInst);
XtIStream& operator>>(XtIStream& pIS, _XtInst& pInst);
}
#endif // _XTINST_H
