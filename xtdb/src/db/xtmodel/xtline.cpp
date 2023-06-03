#include "_xtline.h"
#include "_xtblock.h"
#include "xtline.h"
namespace xtdb {
xtobject_kind _XtLine::mKind = xtobject_kind::LINE;
_XtLine::_XtLine()
{
}
XtLine* XtLine::create(XtBlock* pBlock)
{
    _XtBlock* block = reinterpret_cast<_XtBlock*>(pBlock);
    XtLine* line = reinterpret_cast<XtLine*>(block->mLineTbl->create());
    return line;
}
void XtLine::destroy()
{
    _XtLine* line = reinterpret_cast<_XtLine*>(this);
    _XtBlock* block = reinterpret_cast<_XtBlock*>(line->getOwner());
    block->mLineTbl->destroy(line); //this calls destructor of rect, must be called at the end
}

XtIStream& operator>>(XtIStream& pIS, _XtLine::direction& pDir)
{
    FILE* fp = pIS.getFileDescriptor();
    if (R_ABNORMAL == fread(&pDir, sizeof(pDir), 1, fp)) {
    }
    return pIS;
}

XtIStream& operator>>(XtIStream& pIS, _XtLine& pLine)
{
    pIS >> pLine.mX1;
    pIS >> pLine.mY1;
    pIS >> pLine.mX2;
    pIS >> pLine.mY2;
    pIS >> pLine.mDirection;
    return pIS;
}

XtOStream& operator<<(XtOStream& pOS, _XtLine::direction& pDir)
{
    FILE* fp = pOS.getFileDescriptor();
    if (R_ABNORMAL == fwrite(&pOS, sizeof(pOS), 1, fp))
    {
        //TODO: exception
    }
    return pOS;
}

XtOStream& operator<<(XtOStream& pOS, _XtLine& pLine)
{
    pOS << pLine.mX1;
    pOS << pLine.mY1;
    pOS << pLine.mX2;
    pOS << pLine.mY2;
    pOS << pLine.mDirection;
    return pOS;
}

}
