#ifndef XTBLOCK_H
#define XTBLOCK_H
#include "xtset.h"
class XtBlock
{
public:
    XtBlock();
    XtSet getAllShapes();
    static XtBlock* create();
    void load(const char* pFileNm);
    void write(const char* pFileNm);
    bool operator==(const XtBlock& pRhs) const;
};
#endif // XTBLOCK_H
