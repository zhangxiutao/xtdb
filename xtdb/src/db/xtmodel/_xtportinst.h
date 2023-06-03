#ifndef _XTPORTINST_H
#define _XTPORTINST_H

#include "_xtnetobject.h"

namespace xtdb {
class _XtPortInst : public _XtNetObject
{
public:
    uint mInstId;
    static xtobject_kind mKind;
    _XtPortInst();
    bool operator==(const _XtPortInst& pRhs);
};
}
#endif // _XTPORTINST_H
