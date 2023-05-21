#ifndef XTPCCONTAINER_H
#define XTPCCONTAINER_H

#include "xtcontainer.h"
#include "xttable.h"
#include "xtwireseg.h"
#include <typeinfo>
#include "xtcore.h"
#include "_xtnet.h"
#include "_xtnetobject.h"

namespace xtdb {
template <typename Parent_T, typename Child_T>
class XtPCContainer : public XtContainer
{
public:
//    typedef typename _<Parent_T>::type _Parent_T;
    Parent_T* mParent;
    XtTable<Child_T>* mTbl;
    XtPCContainer(XtTable<Child_T>* pTbl);
    void setParent(Parent_T* pContainer);
    uint begin() const override;
    uint end() const override;
    uint next(uint pExtId) const override;
    _XtObject* getPtr(uint pExtId) const override;
    uint size() const override;
    bool empty() const override;
};

template <typename Parent_T, typename Child_T>
XtPCContainer<Parent_T, Child_T>::XtPCContainer(XtTable<Child_T>* pTbl):mParent(nullptr), mTbl(pTbl)
{

}
template <typename Parent_T, typename Child_T>
void XtPCContainer<Parent_T, Child_T>::setParent(Parent_T* pParent)
{
    mParent = pParent;
}
template <typename Parent_T, typename Child_T>
uint XtPCContainer<Parent_T, Child_T>::begin() const
{
    return reinterpret_cast<XtHashTable<Parent_T>*>(mParent->mChildType2HashTblMap[typeid(Child_T)])->begin();
}
template <typename Parent_T, typename Child_T>
uint XtPCContainer<Parent_T, Child_T>::end() const
{
    return 0;
}
template <typename Parent_T, typename Child_T>
uint XtPCContainer<Parent_T, Child_T>::next(uint pExtId) const
{
    Child_T* child = reinterpret_cast<Child_T*>(mTbl->getPtr(pExtId));
    return child->mDoubleLLNext;
}
template <typename Parent_T, typename Child_T>
_XtObject* XtPCContainer<Parent_T, Child_T>::getPtr(uint pExtId) const
{
    Child_T* child = reinterpret_cast<Child_T*>(mTbl->getPtr(pExtId));
    return child;
}
template <typename Parent_T, typename Child_T>
uint XtPCContainer<Parent_T, Child_T>::size() const
{
    Parent_T* parent = reinterpret_cast<Parent_T*>(mParent);
    return reinterpret_cast<XtHashTable<Parent_T>*>(mParent->mChildType2HashTblMap[typeid(Child_T)])->size();
}
template <typename Parent_T, typename Child_T>
bool XtPCContainer<Parent_T, Child_T>::empty() const
{
    Parent_T* parent = reinterpret_cast<Parent_T*>(mParent);
    return reinterpret_cast<XtHashTable<Parent_T>*>(mParent->mChildType2HashTblMap[typeid(Child_T)])->empty();
}
}
#endif // XTPCCONTAINER_H
