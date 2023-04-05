#ifndef XTBLOCK_H
#define XTBLOCK_H
#include "xtset.h"
#include "xtshape.h"
namespace xtdb {
class XtBlock
{
private:
    ~XtBlock() = delete;
public:
    XtSet<XtShape*> getAllShapes();
    static XtBlock* create();
    static void destroy(XtBlock* pBlock);
    void load(const char* pFileNm);
    void write(const char* pFileNm);
    bool operator==(const XtBlock& pRhs) const;
};
}
#endif // XTBLOCK_H
