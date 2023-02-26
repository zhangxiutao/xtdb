#ifndef XTTABLE_H
#define XTTABLE_H
#include "xttypes.h"
#include "xtcore.h"
#include "xtcontainer.h"
#include "xttablepage.h"
#include "xtstream.h"
namespace xtdb {
class XtObjectPage;
class _XtFreeObject;
class _XtObject;
template <typename T>
class XtTable : public XtObjectTable, public XtContainer
{
public:
    XtTablePage **mPages;
    uint mFreeList;
    uint mPagesCnt;
    uint mPagesCap;
    uint mPageSize;
    uint mPageMask;
    uint mPageShift;
    uint mTopId;        // largest allocated id.
    uint mBottomId;     // smallest allocated id.
    uint mAllocCnt;
public:
    XtTable(_XtObject* pOwner = nullptr, uint pPageSize = 128);
    void reallocPages();
    _XtObject* getPtr(uint pExtId) const override;
    void newPage();
    T *create();
    void destroy(T* t);
    _XtFreeObject* popFreeList();
    void pushFreeList(_XtFreeObject* pFreeObj);
    uint begin () const override;
    uint end() const override {return 0;};
    uint next(uint pExtId) const override;
    bool operator==(const XtTable& pRhs) const;
    bool isAllocated(uint pExtId) const
    {
        return getPtr(pExtId)->isAllocated();
    }
    XtObjectPage* getPageHeader(uint pExtId) const
    {
        return mPages[pExtId >> mPageShift];
    }
};
template <typename T>
XtOStream& operator<<(XtOStream &pStream, XtTable<T>& table);
template <typename T>
XtIStream& operator>>(XtIStream &pStream, XtTable<T>& table);
}
#endif // XTTABLE_H
