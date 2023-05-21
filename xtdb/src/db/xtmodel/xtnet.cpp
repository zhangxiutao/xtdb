#include "_xtnet.h"
#include "xtnet.h"
#include "_xtblock.h"
#include <cstdlib>
#include <cstring>
#include "_xtwireseg.h"
#include "xtpccontainer.h"

namespace xtdb {
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
//XtSet<XtNetObject*> getNetObjects()
//{
//    std::vector<XtNetObject*> netObjects;
//    netObjects.push_back();
//    XtSet<XtNetObject*> netObjects();
//}
}
