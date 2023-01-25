#include "xtobject.h"
#include "xtcore.h"

XtObject::XtObject()
{

}

uint XtObject::getId() const
{
    return ((_XtObject*)this)->getExtId();
}
