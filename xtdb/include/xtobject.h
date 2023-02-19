#ifndef XTOBJECT_H
#define XTOBJECT_H
#include "xttypes.h"

namespace xtdb {
    class XtObject
    {
    private:
        uint mId;
    public:
        XtObject();
        uint getId() const;
    };
}

#endif // XTOBJECT_H
