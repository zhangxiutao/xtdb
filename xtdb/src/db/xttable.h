#ifndef XTTABLE_H
#define XTTABLE_H
#include "xttypes.h"
#include "xtobjecttable.h"
#include "xtcontainer.h"
#include "xttablepage.h"
#include "xtstream.h"

class XtObjectPage;
class _XtFreeObject;
class _XtObject;
template <typename T>
class XtTable : public XtObjectTable, public XtContainer
{
private:
    XtTablePage **mPages;
    uint mFreeList;
    uint mPageCnt;
    uint mPageCap;
    uint mPageSize;
    uint mPageMask;
    uint mPageShift;
    uint mTopId;        // largest allocated id.
    uint mBottomId;     // smallest allocated id.
public:
    XtTable(uint pPageSize = 128);
    void reallocPages();
    _XtObject* getPtr(uint pExtId);
    void newPage();
    T *create();
    void destroy(T* t);
    _XtFreeObject* popFreeList();
    void pushFreeList(_XtFreeObject *pFreeObj);
    uint begin() override;
    uint end() override {return 0;};
    uint next(uint pExtId) override;
    bool isAllocated(uint pExtId)
    {
        return getPtr(pExtId)->isAllocated();
    }
    XtObjectPage* getPageHeader(uint pExtId)
    {
        return mPages[pExtId >> mPageShift];
    }
};
template <typename T>
XtOStream& operator<<(XtOStream &pStream, const XtTable<T>& table);
template <typename T>
XtIStream& operator>>(XtIStream &pStream, const XtTable<T>& table);
#endif // XTTABLE_H
