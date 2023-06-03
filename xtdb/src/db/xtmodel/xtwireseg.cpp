#include "_xtwireseg.h"
#include "xtwireseg.h"
#include "_xtblock.h"
#include "xtnet.h"
#include "_xtnet.h"
#include "xtshape.h"
#include "_xtshape.h"
#include <cassert>
#include "xtrectangle.h"
#include "_xtrectangle.h"
#include "_xtline.h"

namespace xtdb {
xtobject_kind _XtWireSeg::mKind = xtobject_kind::WIRESEG;
_XtWireSeg::_XtWireSeg():mShapeId(0)
{
    //every object stored in hashtable must have name
    static uint nameId = 0;
    nameId++;
    mName = strdup((std::string("WIRESEG") + std::to_string(nameId).c_str()).c_str());
}
_XtWireSeg::~_XtWireSeg()
{
    free(reinterpret_cast<void*>(mName));
}
bool _XtWireSeg::operator==(const _XtWireSeg& pRhs)
{

}
//TODO: implicit construction of double-direction link between wireseg and net is good or bad practice?
void XtWireSeg::setNet(XtNet* pNet)
{
    _XtWireSeg* wireSeg = reinterpret_cast<_XtWireSeg*>(this);
    _XtBlock* block = reinterpret_cast<_XtBlock*>(wireSeg->getOwner());
    wireSeg->mNetId = pNet->getId();

    //insert this wireseg to the hashtable in the corresponding _XtNet
    _XtNet* net = reinterpret_cast<_XtNet*>(pNet);
    _XtNet::Type2HashTblMap& hashTbl = net->mChildType2HashTblMap;
    _XtNet::Type2HashTblMap::iterator wireSegHashTblItr = hashTbl.find(typeid(_XtWireSeg));
    if (hashTbl.end() == wireSegHashTblItr)
    {
        hashTbl[typeid(_XtWireSeg)] = new XtHashTable<_XtWireSeg>(block->mWireSegTbl);
    }
    XtHashTable<_XtWireSeg>* wireSegs = reinterpret_cast<XtHashTable<_XtWireSeg>*>(hashTbl[typeid(_XtWireSeg)]);
    wireSegs->insert(wireSeg);
    return;
}
XtNet* XtWireSeg::getNet()
{
    _XtWireSeg* wireSeg = reinterpret_cast<_XtWireSeg*>(this);
    _XtBlock* block = reinterpret_cast<_XtBlock*>(wireSeg->getOwner());
    return reinterpret_cast<XtNet*>(block->mNetTbl->getPtr(wireSeg->mNetId));
}
void XtWireSeg::setShape(XtShape* pShape)
{
    _XtWireSeg* wireSeg = reinterpret_cast<_XtWireSeg*>(this);
    _XtShape* shape = reinterpret_cast<_XtShape*>(pShape);
    wireSeg->mShapeId = pShape->getId();
    wireSeg->mShapeKind = reinterpret_cast<XtContainer*>(shape->getTable())->getObjKind();
}
XtShape* XtWireSeg::getShape()
{
    _XtWireSeg* wireSeg = reinterpret_cast<_XtWireSeg*>(this);
    _XtBlock* block = reinterpret_cast<_XtBlock*>(wireSeg->getOwner());
    if (wireSeg->mShapeKind == xtobject_kind::LINE)
    {
        return reinterpret_cast<XtShape*>(block->mLineTbl->getPtr(wireSeg->mShapeId));
    }
    else
    {
        return reinterpret_cast<XtShape*>(block->mRectTbl->getPtr(wireSeg->mShapeId));
    }
}
XtWireSeg* XtWireSeg::create(XtBlock* pBlock)
{
    _XtBlock* block = reinterpret_cast<_XtBlock*>(pBlock);
    _XtWireSeg* wireSeg = block->mWireSegTbl->create();
    return reinterpret_cast<XtWireSeg*>(wireSeg);
}
void XtWireSeg::destroy()
{
    _XtWireSeg* wireSeg = reinterpret_cast<_XtWireSeg*>(this);
    _XtBlock* block = reinterpret_cast<_XtBlock*>(wireSeg->getOwner());

    //remove this wireseg from the hashtable in the corresponding _XtNet
    if (0 != wireSeg->mNetId) {
        _XtNet* net = reinterpret_cast<_XtNet*>(block->mNetTbl->getPtr(wireSeg->mNetId));
        _XtNet::Type2HashTblMap& hashTbl = net->mChildType2HashTblMap;
        _XtNet::Type2HashTblMap::iterator wireSegHashTblItr = hashTbl.find(typeid(_XtWireSeg));
        assert(hashTbl.end() != wireSegHashTblItr);
        XtHashTable<_XtWireSeg>* wireSegs = reinterpret_cast<XtHashTable<_XtWireSeg>*>(wireSegHashTblItr->second);
        wireSegs->remove(wireSeg);
    }
    block->mWireSegTbl->destroy(wireSeg); //this calls destructor of wireSeg, must be called at the end
}
XtIStream& operator>>(XtIStream& pIS, _XtWireSeg& pWireSeg)
{
    pIS >> reinterpret_cast<_XtNetObject&>(pWireSeg);
    pIS >> pWireSeg.mShapeId;
    pIS >> pWireSeg.mShapeKind;
    return pIS;
}
XtOStream& operator<<(XtOStream& pOS, _XtWireSeg& pWireSeg)
{
    pOS << reinterpret_cast<_XtNetObject&>(pWireSeg);
    pOS << pWireSeg.mShapeId;
    pOS << pWireSeg.mShapeKind;
    return pOS;
}
}
