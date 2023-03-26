#include "_xtshape.h"
#include "xtshape.h"
namespace xtdb {

_XtShape::_XtShape(_XtTech::layer_type pLayer):mSelected(false), mLayer(_XtTech::METAL1)
{

}

void XtShape::setSelected(bool pSelected)
{
    _XtShape* shape = reinterpret_cast<_XtShape*>(this);
    shape->mSelected = pSelected;
}

}
