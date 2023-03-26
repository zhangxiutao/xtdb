#ifndef XTBLOCK_H
#define XTBLOCK_H
#include "xtset.hpp"
#include "xtshape.h"
namespace xtdb {
class XtBlock
{
public:
    XtSet<XtShape> getAllShapes();
    static XtBlock* create();
    void load(const char* pFileNm);
    void write(const char* pFileNm);
    bool operator==(const XtBlock& pRhs) const;
};
}
#endif // XTBLOCK_H
