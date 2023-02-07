#ifndef XTBLOCK_H
#define XTBLOCK_H
#include "xtcontainer.h"

class XtBlock
{
public:
    XtBlock();
    XtContainer* getAllShapes();
    void write(const char* pBlock);
};

#endif // XTBLOCK_H
