#include "xtblock.h"
#include "_xtblock.h"
#include "_xtrectangle.h"
#include "xttable.h"
#include "xthashtable.h"
#include "xtstream.h"
#include <fstream>
#include "xtdm.h"
#include "xtinst.h"
#include "_xtinst.h"
#include "_xtwireseg.h"
#include "_xtportinst.h"
#include "_xtport.h"
#include "_xtvia.h"
#include "_xtline.h"
#include "_xtrectangle.h"

namespace xtdb {
static XtTable<_XtBlock> blockTbl;
static XtHashTable<_XtBlock> blockHashTbl(&blockTbl);

_XtBlock::_XtBlock():mInstTbl(new XtTable<_XtInst>(this)),
    mWireSegTbl(new XtTable<_XtWireSeg>(this)),
    mPortInstTbl(new XtTable<_XtPortInst>(this)),
    mPortTbl(new XtTable<_XtPort>(this)),
    mViaTbl(new XtTable<_XtVia>),
    mLineTbl(new XtTable<_XtLine>),
    mRectTbl(new XtTable<_XtRectangle>(this)),
    mQuadtree(new XtQuadtree<_XtRectangle*>())
{
}

_XtBlock::~_XtBlock()
{
    delete mRectTbl;
    delete mQuadtree;
}

bool _XtBlock::operator==(const _XtBlock& pRhs) const
{
    return (*mRectTbl == *pRhs.mRectTbl);
}

XtSet<XtShape*> XtBlock::getAllShapes()
{
    //TODO: 定义一个新的数据结构可以串联起多个table，也可以串联起多个自己。这样就可以串联recttable，triangletable...
    return XtSet<XtShape*>(reinterpret_cast<_XtBlock*>(this)->mRectTbl);
}

XtSet<XtInst*> XtBlock::getAllInsts()
{
    return XtSet<XtInst*>(reinterpret_cast<_XtBlock*>(this)->mInstTbl);
}

XtOStream& operator<<(XtOStream& pOS, _XtBlock& pBlock)
{
    pOS << *pBlock.mInstTbl;
    pOS << *pBlock.mRectTbl;    
    return pOS;
}

XtIStream& operator>>(XtIStream& pIS, _XtBlock& pBlock)
{
    pIS >> *pBlock.mInstTbl;
    pIS >> *pBlock.mRectTbl;
    return pIS;
}
//cell view name example: invertor/layout
void XtBlock::loadAllSubBlocks(const char* pCellViewNm)
{
    if (blockHashTbl.find(pCellViewNm))
    {
        return;
    }
    XtBlock* block = XtBlock::create();
    block->load(pCellViewNm);
    blockHashTbl.insert(reinterpret_cast<_XtBlock*>(block)); //TODO: check if it is better to insert inside XtBlock::load

    XtSet<XtInst*> instsSet = block->getAllInsts();
    for (XtIterator<XtInst*> it = instsSet.begin(); it != instsSet.end(); it++)
    {
        XtInst* inst = (XtInst*)(*it);
        std::string cellViewNm = inst->getCellViewNm();
        loadAllSubBlocks(cellViewNm.c_str());
    }
}

//load all objects from disk into memory
void XtBlock::load(const char* pCellViewNm)
{
    std::string cellViewPath = XtDM::cellViewNmToFilePath(pCellViewNm);
    _XtBlock* block = reinterpret_cast<_XtBlock*>(this);
    XtIStream is(cellViewPath);
    is >> *block;
    XtSet<XtInst*> instSet = getAllInsts();
    for (XtIterator<XtInst*> instIt = instSet.begin(); instIt != instSet.end(); instIt++)
    {
        XtRectangle* rect = instIt->getShape();
        block->mQuadtree->insert(reinterpret_cast<_XtRectangle*>(rect));
    }
    XtSet<XtShape*> shapesSet = getAllShapes();
    for (XtIterator<XtShape*> it = shapesSet.begin(); it != shapesSet.end(); it++)
    {
        block->mQuadtree->insert(reinterpret_cast<_XtRectangle*>(*it));
    }
}

void XtBlock::write(const char* pCellViewNm)
{
    _XtBlock* block = reinterpret_cast<_XtBlock*>(this);
    std::string cellViewPath = XtDM::cellViewNmToFilePath(pCellViewNm);

    std::ofstream file(cellViewPath, std::ios::out | std::ios::trunc); //create empty file TODO:create folder if it doesn't exist
    file.close();
    XtOStream os(cellViewPath);
    os << *block;
}

bool XtBlock::operator==(const XtBlock& pRhs) const
{
    return (*(_XtBlock*)this) == (_XtBlock&)pRhs;
}

XtBlock* XtBlock::create()
{
    XtBlock* block = reinterpret_cast<XtBlock*>(blockTbl.create());
    return block;
}

void XtBlock::destroy(XtBlock* pBlock)
{
    _XtBlock* block = reinterpret_cast<_XtBlock*>(pBlock);
    blockTbl.destroy(block);
}
}
