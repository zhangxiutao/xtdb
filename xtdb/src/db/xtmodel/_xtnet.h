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

    //PERSISTENT MEMBER
    char* mName;

    //NON-PERSISTANT MEMBER
    Type2HashTblMap mChildType2HashTblMap; //TODO: fill this map when streaming from file
    static xtobject_kind mKind;
    bool operator==(const _XtNet& pRhs);
    _XtNet();
    ~_XtNet();
};
XtIStream& operator>>(XtIStream& pIS, _XtNet& pNet);
XtOStream& operator<<(XtOStream& pOS, _XtNet& pNet);
}

#endif // _XTNET_H
