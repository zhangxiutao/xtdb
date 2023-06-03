#include "_xtnet.h"
#include "xtnet.h"
#include "_xtblock.h"
#include <cstdlib>
#include <cstring>
#include "_xtwireseg.h"
#include "xtpccontainer.h"

namespace xtdb {
xtobject_kind _XtNet::mKind = xtobject_kind::NET;
_XtNet::_XtNet():mName(nullptr)
{

}

_XtNet::~_XtNet()
{
    if (mName)
    {
        free(mName);
    }
    for (auto& [type, hashTbl] : mChildType2HashTblMap)
    {
        XtHashTable<_XtWireSeg>* wireSegs = reinterpret_cast<XtHashTable<_XtWireSeg>*>(hashTbl);
        delete wireSegs;
    }
}

bool _XtNet::operator==(const _XtNet& pRhs)
{
    if (mName && pRhs.mName)
    {
        if (strcmp(mName, pRhs.mName) != 0)
        {
            return false;
        }
    }
    else if (mName || pRhs.mName)
    {
        return false;
    }
    return true;
}

void XtNet::setName(const char* pName)
{
    _XtNet* net = reinterpret_cast<_XtNet*>(this);
    if (net->mName)
    {
        free(net->mName);
    }
    net->mName = strdup(pName);
}
XtSet<XtWireSeg*> XtNet::getWiresegs()
{
    _XtNet* net = reinterpret_cast<_XtNet*>(this);
    _XtBlock* block = reinterpret_cast<_XtBlock*>(net->getOwner());
    block->mNetWireSegContainer->setParent(net);
    return XtSet<XtWireSeg*>(block->mNetWireSegContainer);
}

XtNet* XtNet::create(XtBlock* pBlock)
{
    _XtBlock* block = reinterpret_cast<_XtBlock*>(pBlock);
    _XtNet* net = block->mNetTbl->create();
    return reinterpret_cast<XtNet*>(net);
}

XtIStream& operator>>(XtIStream& pIS, _XtNet& pNet)
{
    pIS >> pNet.mName;
    return pIS;
}

XtOStream& operator<<(XtOStream& pOS, _XtNet& pNet)
{
    pOS << pNet.mName;
    return pOS;
}
//XtSet<XtNetObject*> getNetObjects()
//{
//    std::vector<XtNetObject*> netObjects;
//    netObjects.push_back();
//    XtSet<XtNetObject*> netObjects();
//}
}
