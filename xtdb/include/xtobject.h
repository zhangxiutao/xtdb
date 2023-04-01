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
    bool isAlive() const;
    void* getExtendedObj(uint pExtendedClassId) const;
    void setExtendedObj(uint pExtendedClassId, void* pExtendedObj);
};
}

#endif // XTOBJECT_H
