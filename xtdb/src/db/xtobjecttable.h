#ifndef XTOBJECTTABLE_H
#define XTOBJECTTABLE_H
#include "xttypes.h"
namespace xtdb {
class XtObjectTable
{
public:
    uint mObjSize;
    XtObjectTable(uint pObjSize):mObjSize(pObjSize){};
};
}
#endif // XTOBJECTTABLE_H
