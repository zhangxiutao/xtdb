#ifndef XTSHAPE_H
#define XTSHAPE_H
#include "xtcore.h"
#include "xttech.h"
class _XtShape: public _XtObject
{
protected:
    bool mSelected;
    _XtTech::layer_type mLayer;
public:
    _XtShape(_XtTech::layer_type pLayer);
    void setSelected(bool pSelected);
};

#endif // XTSHAPE_H
