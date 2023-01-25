#ifndef _XTOBJECT_H
#define _XTOBJECT_H
#include "xttypes.h"

class XtObject
{
private:
    uint mId;
public:
    XtObject();
    uint getId() const;
};

#endif // _XTOBJECT_H
