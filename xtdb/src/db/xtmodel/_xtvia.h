#ifndef _XTVIA_H
#define _XTVIA_H
#include "_xtnetobject.h"
#include <vector>

namespace xtdb{
class _XtWireSeg;
class Rectangle;
class Via;
class _XtVia : public _XtNetObject
{
public:
    static xtobject_kind mKind;
    _XtVia();
    bool operator==(const _XtVia& pVia);
};
}
#endif // _XTVIA_H
