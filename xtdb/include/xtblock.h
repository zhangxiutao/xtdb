#ifndef XTBLOCK_H
#define XTBLOCK_H
#include "xtset.h"

namespace xtdb {
class XtShape;
class XtInst;
class XtBlock
{
private:
    ~XtBlock() = delete;
public:
    XtSet<XtShape*> getAllShapes();
    XtSet<XtInst*> getAllInsts();
    static XtBlock* create();
    static void destroy(XtBlock* pBlock);
    static void loadAllSubBlocks(const char* pCellViewNm);
    void load(const char* pCellViewNm);
    void write(const char* pCellViewNm);
    bool operator==(const XtBlock& pRhs) const;
};
}
#endif // XTBLOCK_H
