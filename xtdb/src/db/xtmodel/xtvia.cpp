#include "_xtvia.h"

namespace xtdb {
xtobject_kind _XtVia::mKind = xtobject_kind::VIA;
_XtVia::_XtVia()
{

}
bool _XtVia::operator==(const _XtVia& pVia)
{
    return true;
}
}
