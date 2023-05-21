#ifndef _XTNET_H
#define _XTNET_H
#include "xttypes.h"
#include "xtcore.h"
#include <typeindex>
#include "xthashtable.h"

namespace xtdb{
class _XtNet : public _XtObject
{
public:
    typedef std::unordered_map<std::type_index, void*> Type2HashTblMap;
    _XtNet();
    ~_XtNet();
    char* mName;
    Type2HashTblMap mChildType2HashTblMap;
    uint mWireSegListSize;
};
}

#endif // _XTNET_H
