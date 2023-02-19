#ifndef _XTSHAPE_H
#define _XTSHAPE_H
#include "xtcore.h"
#include "_xttech.h"
namespace xtdb {
class _XtShape: public _XtObject
{
public:
    bool mSelected;
    _XtTech::layer_type mLayer;
protected:
    _XtShape(_XtTech::layer_type pLayer);
};
}
#endif // _XTSHAPE_H
