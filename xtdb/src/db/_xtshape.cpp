#include "_xtshape.h"
_XtShape::_XtShape(_XtTech::layer_type pLayer):mSelected(false), mLayer(_XtTech::METAL1)
{
}

void _XtShape::setSelected(bool pSelected)
{
    mSelected = pSelected;
}
