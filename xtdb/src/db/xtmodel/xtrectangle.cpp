#include "_xtrectangle.h"
#include "xtrectangle.h"
#include "xtquadtree.h"
#include "_xtblock.h"
#include "_xttech.h"
#include "xtstream.h"
namespace xtdb {

_XtRectangle::_XtRectangle():
    mX1(0), mY1(0), mX2(0), mY2(0), mNext(0), mName(""), _XtShape(_XtTech::METAL1), mDoubleLLPrev(0), mDoubleLLNext(0)
{

}

bool _XtRectangle::operator==(const _XtRectangle& pRhs)
{
    if (mX1 != pRhs.mX1
        || mY1 != pRhs.mY1
        || mX2 != pRhs.mX2
        || mY2 != pRhs.mY2)
    {
        return false;
    }
    return true;
}

bool _XtRectangle::operator!=(const _XtRectangle& pRhs)
{
    return !(*this == pRhs);
}

XtRect _XtRectangle::getZone()
{
    return XtRect(mX1, mY1, mX2, mY2);
}

XtRect XtRectangle::getZone()
{
    _XtRectangle* rect = reinterpret_cast<_XtRectangle*>(this);
    return rect->getZone();
}

XtRectangle* XtRectangle::create(XtBlock* pBlock)
{
    _XtBlock* block = reinterpret_cast<_XtBlock*>(pBlock);
    _XtRectangle* rect = block->mRectTbl->create();
    block->mQuadtree->insert(rect);
    return reinterpret_cast<XtRectangle*>(rect);
}

void XtRectangle::setCoodinates(int pX1, int pY1, int pX2, int pY2)
{
    _XtRectangle* rect = reinterpret_cast<_XtRectangle*>(this);
    rect->mX1 = pX1;
    rect->mX2 = pX2;
    rect->mY1 = pY1;
    rect->mY2 = pY2;
    rect->mW = rect->mX2 - rect->mX1;
    rect->mH = rect->mY2 - rect->mY1;
    rect->mOwnerNode->removeObj(rect); //reset coordinate causes the change of quadtree ownernode
    _XtBlock* block = reinterpret_cast<_XtBlock*>(rect->getOwner());
    block->mQuadtree->insert(rect);
}

int XtRectangle::getX1()
{
    return reinterpret_cast<_XtRectangle*>(this)->mX1;
}

int XtRectangle::getY1()
{
    return reinterpret_cast<_XtRectangle*>(this)->mY1;
}

int XtRectangle::getX2()
{
    return reinterpret_cast<_XtRectangle*>(this)->mX2;
}

int XtRectangle::getY2()
{
    return reinterpret_cast<_XtRectangle*>(this)->mY2;
}

void XtRectangle::setX1(int pX1)
{
    _XtRectangle* rect = reinterpret_cast<_XtRectangle*>(this);
    rect->mX1 = pX1;
    rect->mW = rect->mX2 - rect->mX1;
    rect->mOwnerNode->removeObj(rect);
    _XtBlock* block = reinterpret_cast<_XtBlock*>(rect->getOwner());
    block->mQuadtree->insert(rect);
}

void XtRectangle::setY1(int pY1)
{
    _XtRectangle* rect = reinterpret_cast<_XtRectangle*>(this);
    rect->mY1 = pY1;
    rect->mH = rect->mY2 - rect->mY1;
    rect->mOwnerNode->removeObj(rect);
    _XtBlock* block = reinterpret_cast<_XtBlock*>(rect->getOwner());
    block->mQuadtree->insert(rect);
}

void XtRectangle::setX2(int pX2)
{
    _XtRectangle* rect = reinterpret_cast<_XtRectangle*>(this);
    rect->mX2 = pX2;
    rect->mW = rect->mX2 - rect->mX1;
    rect->mOwnerNode->removeObj(rect);
    _XtBlock* block = reinterpret_cast<_XtBlock*>(rect->getOwner());
    block->mQuadtree->insert(rect);
}

void XtRectangle::setY2(int pY2)
{
    _XtRectangle* rect = reinterpret_cast<_XtRectangle*>(this);
    rect->mY2 = pY2;
    rect->mH = rect->mY2 - rect->mY1;
    rect->mOwnerNode->removeObj(rect);
    _XtBlock* block = reinterpret_cast<_XtBlock*>(rect->getOwner());
    block->mQuadtree->insert(rect);
}

void XtRectangle::destroy()
{
    _XtRectangle* rect = reinterpret_cast<_XtRectangle*>(this);
    _XtBlock* block = reinterpret_cast<_XtBlock*>(rect->getOwner());
    block->mRectTbl->destroy(rect);
    rect->mOwnerNode->removeObj(rect);
}

XtOStream& operator<<(XtOStream& pOS, _XtRectangle& pRect)
{
    pOS << pRect.mX1;
    pOS << pRect.mY1;
    pOS << pRect.mX2;
    pOS << pRect.mY2;
    return pOS;
}

XtIStream& operator>>(XtIStream& pIS, _XtRectangle& pRect)
{
    pIS >> pRect.mX1;
    pIS >> pRect.mY1;
    pIS >> pRect.mX2;
    pIS >> pRect.mY2;
    return pIS;
}

}
