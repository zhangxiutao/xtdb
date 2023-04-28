#ifndef _XTPORTINST_H
#define _XTPORTINST_H

#include "_xtnetobject.h"

namespace xtdb {
class _XtPortInst : public _XtNetObject
{
public:
    _XtPortInst();
    char* mName;
    uint mInstId;
};
}
#endif // _XTPORTINST_H
