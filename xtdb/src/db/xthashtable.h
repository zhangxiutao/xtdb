#include "xttable.hpp"
#include "xttypes.h"
namespace xtdb {
template <typename T>
class XtHashTable
{
private:
    const uint overLoadingFactor = 4;
    uint* mData;
    XtTable<T>* mTbl;
    uint mObjCnt;
    uint mCapacity;
    uint mHeadDoubleLL;
    uint mItr;
public:
    XtHashTable(XtTable<T>* pTbl);
    ~XtHashTable();
    uint hashString(const char* pName);
    void insert(T* pObj);
    T* find(const char* pName);
    void remove(const char* pName);
    void growTable();
    void initItr();
    T* next();
};
}

