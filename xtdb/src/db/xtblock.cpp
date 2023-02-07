#include "xtblock.h"
#include "_xtblock.h"
#include "_xtrectangle.h"
#include "xtstream.h"
XtBlock::XtBlock()
{

}

XtContainer* XtBlock::getAllShapes()
{
    //TODO: 定义一个新的数据结构可以串联起多个table，也可以串联起多个自己。这样就可以串联recttable，triangletable...
    return &(((_XtBlock*)this)->mRectTbl);
}

XtOStream& operator<<(XtOStream& pOS, const _XtBlock& pBlock)
{
    pOS << pBlock.mRectTbl;
}

void XtBlock::write(const char* pFileNm)
{
    _XtBlock* block = (_XtBlock*)this;
    XtOStream os(pFileNm);
    os << *block;
}

