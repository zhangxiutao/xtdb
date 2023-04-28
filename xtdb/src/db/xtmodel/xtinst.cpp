#include "_xtinst.h"
#include "xtinst.h"
#include "_xtblock.h"
#include "_xtrectangle.h"

namespace xtdb {
_XtInst::_XtInst()
{

}

void _XtInst::setOrigin(const XtPoint& pPnt)
{
    mOrigin = pPnt;
}

void _XtInst::setTransform(const XtOperMat& pOperMat)
{
//TODO:
}

XtRectangle* XtInst::getShape()
{
    _XtInst* inst = reinterpret_cast<_XtInst*>(this);
    _XtBlock* block = reinterpret_cast<_XtBlock*>(inst->getOwner());
    return reinterpret_cast<XtRectangle*>(block->mRectTbl->getPtr(inst->mShapeId));
}

std::string XtInst::getCellViewNm()
{
    _XtInst* inst = reinterpret_cast<_XtInst*>(this);
    return std::string(inst->mCellNm) + std::string(inst->mViewNm);
}

void XtInst::setOrigin(const XtPoint& pPnt)
{
    _XtInst* inst = reinterpret_cast<_XtInst*>(this);
    inst->setOrigin(pPnt);
}

void XtInst::setTransform(const XtOperMat& pOperMat)
{
//TODO:
}

XtInst* XtInst::create(XtBlock* pBlock)
{
    _XtBlock* block = reinterpret_cast<_XtBlock*>(pBlock);
    _XtInst* inst = block->mInstTbl->create();
    return reinterpret_cast<XtInst*>(inst);
}

XtIStream& operator>>(XtIStream& pIS, _XtInst& pInst)
{
    pIS >> pInst.mName;
    pIS >> pInst.mCellNm;
    pIS >> pInst.mViewNm;
    pIS >> pInst.mShapeId;
    pIS >> pInst.mOrigin;
//    pIS >> pInst.mTransform;//TODO: xtopermat
    pIS >> pInst.mPortInstIds;
//    pIS >> pInst.mCustomParams; //TODO: pdk
    return pIS;
}

XtOStream& operator<<(XtOStream& pOS, _XtInst& pInst)
{
    pOS << pInst.mName;
    pOS << pInst.mCellNm;
    pOS << pInst.mViewNm;
    pOS << pInst.mShapeId;
    pOS << pInst.mOrigin;
//    pOS << pInst.mTransform;
    pOS << pInst.mPortInstIds;
//    pOS << pInst.mCustomParams;
    return pOS;
}
}
