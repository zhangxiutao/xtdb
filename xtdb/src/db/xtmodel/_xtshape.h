#ifndef _XTSHAPE_H
#define _XTSHAPE_H
#include "xtcore.h"
#include "_xttech.h"
namespace xtdb {
class _XtShape: public _XtObject
{
public:
    _XtTech::layer_type mLayer;
    static xtobject_kind mKind;
protected:
    _XtShape();
    ~_XtShape(){};
};
}
#endif // _XTSHAPE_H
