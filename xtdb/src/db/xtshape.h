#ifndef XTSHAPE_H
#define XTSHAPE_H
#include "xtobject.h"

class XtShape: public XtObject
{
protected:
    bool mSelected;
    _XtTech::layer_type mLayer;
public:
    _XtShape(_XtTech::layer_type pLayer);
    void setSelected(bool pSelected);
};

#endif // XTSHAPE_H
