#ifndef XTBLOCK_H
#define XTBLOCK_H
#include "xtset.h"
#include "xtobject.h"

namespace xtdb {
class XtShape;
class XtInst;
class XtBlock : public XtObject
{
private:
    ~XtBlock() = delete;
public:
    XtSet<XtShape*> getAllShapes();
    XtSet<XtInst*> getAllInsts();
    static XtSet<XtBlock*> getAllBlocks();
    static XtBlock* create();
    static void destroy(XtBlock* pBlock);
    static uint loadAllSubBlocks(const char* pCellViewNm);
    void load(const char* pCellViewNm);
    void write(const char* pCellViewNm);
    void setName(const char* pName);
    void saveAndClose(const char* pCellViewNm);
    bool operator==(const XtBlock& pRhs) const;
};
}
#endif // XTBLOCK_H
