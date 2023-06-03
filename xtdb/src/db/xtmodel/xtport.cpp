#include "_xtport.h"

namespace xtdb {
xtobject_kind _XtPort::mKind = xtobject_kind::PORT;
_XtPort::_XtPort()
{

}

bool _XtPort::operator==(const _XtPort& pRhs)
{
    return true;
}
}
