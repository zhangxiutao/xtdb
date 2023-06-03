#ifndef XTBLOCK_H
#define XTBLOCK_H
#include "xtset.h"
#include "xtobject.h"
#include <string>
namespace xtdb {
class XtShape;
class XtInst;
class XtWireSeg;
class XtBlock : public XtObject
{
private:
    ~XtBlock() = delete;
public:
    char* getName();
    XtSet<XtShape*> getAllShapes();
    XtSet<XtInst*> getAllInsts();
    XtSet<XtWireSeg*> getAllWiresegs();
    static XtSet<XtBlock*> getAllBlocks();
    static XtBlock* create();
    static void destroy(XtBlock* pBlock);
    static uint loadAllSubBlocks(const char* pCellViewNm);
    void load(const char* pCellViewNm);
    void write(const char* pCellViewNm);
    void saveAndClose(const char* pCellViewNm);
    bool operator==(const XtBlock& pRhs) const;
};
}
#endif // XTBLOCK_H
