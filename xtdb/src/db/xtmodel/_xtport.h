#ifndef _XTPORT_H
#define _XTPORT_H

#include "_xtnetobject.h"

namespace xtdb {
class _XtPort : public _XtNetObject
{
public:
    _XtPort();
    char* mName;
    static xtobject_kind mKind;
    bool operator==(const _XtPort& pRhs);
};
}
#endif // _XTPORT_H
