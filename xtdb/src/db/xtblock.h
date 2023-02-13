#ifndef XTBLOCK_H
#define XTBLOCK_H
#include "xtcontainer.h"
class XtBlock
{
public:
    XtBlock();
    XtContainer* getAllShapes();
    static XtBlock* create();
    void load(const char* pFileNm);
    void write(const char* pFileNm);
    bool operator==(const XtBlock& pRhs) const;
};
#endif // XTBLOCK_H
