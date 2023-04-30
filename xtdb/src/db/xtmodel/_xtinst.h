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
    char* mCellViewNm; //const char* cannot be freed, during streaming in, malloc is performed, it must be freed.
    uint mBlockId;
    uint mShapeId;
    XtPoint mOrigin;
    XtOperMat mTransform;
    bool mPlaced;
    std::vector<uint> mPortInstIds;
//    std::unordered_map<std::string, std::string> mCustomParams;
public:
   _XtInst();
   ~_XtInst();
    void setOrigin(const XtPoint& pPnt);
    void setTransform(const XtOperMat& pOperMat);
    bool operator==(const _XtInst& pRhs) const;
};
XtOStream& operator<<(XtOStream& pOS, _XtInst& pInst);
XtIStream& operator>>(XtIStream& pIS, _XtInst& pInst);
}
#endif // _XTINST_H
