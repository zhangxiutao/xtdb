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
    _XtVia();
    std::vector<_XtWireSeg*> mConnectedWireSegs;
    std::vector<Rectangle*> mShapes;
};
}
#endif // _XTVIA_H
