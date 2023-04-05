#include "xtblock.h"
#include "_xtblock.h"
#include "_xtrectangle.h"
#include "xttable.h"
#include "xtstream.h"
#include <fstream>
namespace xtdb {
static XtTable<_XtBlock>* blockTbl = nullptr;

_XtBlock::_XtBlock():mRectTbl(new XtTable<_XtRectangle>(this)), mQuadtree(new XtQuadtree<_XtRectangle*>())
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

XtOStream& operator<<(XtOStream& pOS, _XtBlock& pBlock)
{
    pOS << *pBlock.mRectTbl;
    return pOS;
}

XtIStream& operator>>(XtIStream& pIS, _XtBlock& pBlock)
{
    pIS >> *pBlock.mRectTbl;
    return pIS;
}

void XtBlock::load(const char* pFileNm)
{
    _XtBlock* block = reinterpret_cast<_XtBlock*>(this);
    XtIStream is(pFileNm);
    is >> *block;
}

void XtBlock::write(const char* pFileNm)
{
    _XtBlock* block = reinterpret_cast<_XtBlock*>(this);

    std::ofstream file(pFileNm, std::ios::out | std::ios::trunc);
    file.close();
    XtOStream os(pFileNm);
    os << *block;
}

bool XtBlock::operator==(const XtBlock& pRhs) const
{
    return (*(_XtBlock*)this) == (_XtBlock&)pRhs;
}

XtBlock* XtBlock::create()
{
    if (!blockTbl)
    {
        blockTbl = new XtTable<_XtBlock>();
    }
    XtBlock* block = reinterpret_cast<XtBlock*>(blockTbl->create());
    return block;
}

void XtBlock::destroy(XtBlock* pBlock)
{
    _XtBlock* block = reinterpret_cast<_XtBlock*>(pBlock);
    blockTbl->destroy(block);
}
}
