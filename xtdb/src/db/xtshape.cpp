#include "_xtshape.h"
#include "xtshape.h"

void XtShape::setSelected(bool pSelected)
{
    _XtShape* shape = (_XtShape*)this;
    shape->mSelected = pSelected;
}

_XtShape::_XtShape(_XtTech::layer_type pLayer):mSelected(false), mLayer(_XtTech::METAL1)
{

}

