#include "xtblock.h"
#include "_xtblock.h"
#include "_xtrectangle.h"
#include "xttable.hpp"
#include "xtstream.h"
#include <fstream>

_XtBlock::_XtBlock():mRectTbl(new XtTable<_XtRectangle>)
{

}

//_XtBlock::~_XtBlock()
//{
//TODO: delete mRectTbl
//}

bool _XtBlock::operator==(const _XtBlock& pRhs) const
{
    return (*mRectTbl == *pRhs.mRectTbl);
}

XtBlock::XtBlock()
{

}

XtSet XtBlock::getAllShapes()
{
    //TODO: 定义一个新的数据结构可以串联起多个table，也可以串联起多个自己。这样就可以串联recttable，triangletable...
    return XtSet(((_XtBlock*)this)->mRectTbl);
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
    _XtBlock* block = (_XtBlock*)this;
    XtIStream is(pFileNm);
    is >> *block;
}

void XtBlock::write(const char* pFileNm)
{
    _XtBlock* block = (_XtBlock*)this;

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
    //TODO: create in blockTbl
    return (XtBlock*)(new _XtBlock);
}

