#ifndef _XTINST_H
#define _XTINST_H
#include "xtcore.h"
#include <vector>
#include "xtpoint.h"
#include "xtopermat.h"

namespace xtdb {
class _XtPortInst;
class _XtShape;
class _XtInst : public _XtObject
{
public:
    _XtInst();
    char* mName;
    _XtShape* mShape;
    std::vector<_XtPortInst*> mPortInsts;
    XtPoint mOrigin;
    XtOperMat mTransform;
};
}
#endif // _XTINST_H
