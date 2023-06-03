#include "_xtinst.h"
#include "xtinst.h"
#include "_xtblock.h"
#include "_xtrectangle.h"

namespace xtdb {
xtobject_kind _XtInst::mKind = xtobject_kind::INST;
_XtInst::_XtInst():mName(nullptr), mCellViewNm(nullptr), mBlockId(0), mShapeId(0),
    mOrigin({0,0}), mPlaced(false)
{
//TODO:initialize mtransform
}

_XtInst::~_XtInst()
{
    if (mName)
    {
        free(reinterpret_cast<void*>(mName));
    }
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

const char* XtInst::getCellViewName()
{
    _XtInst* inst = reinterpret_cast<_XtInst*>(this);
    return inst->mCellViewNm;
}

bool XtInst::placed()
{
    _XtInst* inst = reinterpret_cast<_XtInst*>(this);
    return inst->mPlaced;
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

void XtInst::setCellViewName(const char* pCellViewNm)
{
    _XtInst* inst = reinterpret_cast<_XtInst*>(this);
    if (inst->mCellViewNm)
    {
        free(inst->mCellViewNm);
    }
    inst->mCellViewNm = strdup(pCellViewNm);
}

bool XtInst::operator==(const XtInst& pRhs) const
{
   const _XtInst* inst = reinterpret_cast<const _XtInst*>(this);
   const _XtInst& rhs = reinterpret_cast<const _XtInst&>(pRhs);
   return *inst == rhs;
}

void XtInst::setName(const char* pName)
{
    _XtInst* inst = reinterpret_cast<_XtInst*>(this);
    if (inst->mName)
    {
        free(inst->mName);
    }
    inst->mName = strdup(pName);
}

bool _XtInst::operator==(const _XtInst& pRhs) const
{
    //TODO: compare more members
    if (mName && pRhs.mName)
    {
        if (std::string(mName) != std::string(pRhs.mName))
        {
            return false;
        }
    }
    else if (mName || pRhs.mName)
    {
        return false;
    }

    if (mCellViewNm && pRhs.mCellViewNm)
    {
        if (std::string(mCellViewNm) != std::string(pRhs.mCellViewNm))
        {
            return false;
        }
    }
    else if (mCellViewNm || pRhs.mCellViewNm)
    {
        return false;
    }
    return true;
}

XtInst* XtInst::create(XtBlock* pBlock)
{
    _XtBlock* block = reinterpret_cast<_XtBlock*>(pBlock);
    _XtInst* inst = block->mInstTbl->create();
    return reinterpret_cast<XtInst*>(inst);
}

void XtInst::setBlockId(uint pBlockId)
{
    _XtInst* inst = reinterpret_cast<_XtInst*>(this);
    inst->mBlockId = pBlockId;
}

XtIStream& operator>>(XtIStream& pIS, _XtInst& pInst)
{
    pIS >> pInst.mName;
    pIS >> pInst.mCellViewNm;
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
    pOS << pInst.mCellViewNm;
    pOS << pInst.mShapeId;
    pOS << pInst.mOrigin;
//    pOS << pInst.mTransform;
    pOS << pInst.mPortInstIds;
//    pOS << pInst.mCustomParams;
    return pOS;
}
}
