#ifndef _XTBLOCK_H
#define _XTBLOCK_H
#include "xttable.h"
#include "xtquadtree.h"
#include "xthashtable.h"
#include "xtpccontainer.h"

namespace xtdb {
class _XtRectangle;
class _XtInst;
class _XtWireSeg;
class _XtPortInst;
class _XtPort;
class _XtVia;
class _XtLine;
class _XtNet;
class _XtNetObject;
class _XtBlock: public _XtObject
{
public:
    //PERSISTANT MEMBER
    XtTable<_XtNet>* mNetTbl;
    XtTable<_XtInst>* mInstTbl;
    XtTable<_XtWireSeg>* mWireSegTbl;
    XtTable<_XtPortInst>* mPortInstTbl;
    XtTable<_XtPort>* mPortTbl;
    XtTable<_XtVia>* mViaTbl;
    XtTable<_XtRectangle>* mRectTbl;
    XtTable<_XtLine>* mLineTbl;
    XtQuadtree<_XtRectangle*>* mQuadtree;

    //NON-PERSISTANT MEMBER
    char* mName; //inv/layout.xtb, can be deduced from the path, no need to dump
    uint mNext;
    uint mDoubleLLPrev;
    uint mDoubleLLNext;
    XtPCContainer<_XtNet, _XtWireSeg>* mNetWireSegContainer;

    static xtobject_kind mKind;
    static XtTable<_XtBlock> blockTbl;
    static XtHashTable<_XtBlock> blockHashTbl;
public:
    _XtBlock();
    ~_XtBlock();
    void setName(const char* pName);
    //getAllShapes是怎么实现的？难道是将所有存储shape的table的信息综合起来生成一个新的table？这样效率不是很低？
    bool operator==(const _XtBlock& pRhs) const;
};

}
#endif // _XTBLOCK_H
