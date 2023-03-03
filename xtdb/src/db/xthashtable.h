#include "xttable.hpp"
#include "xttypes.h"
#include <vector>
template <typename T>
class XtHashTable
{
private:
	const uint overLoadingFactor = 4;
	std::vector<uint> mArr;
	XtTable<T> mTbl;
	uint objCnt;
public:
	void insert(T* pObj);
	void growTable();
};
template <typename T>
void insert(T* pObj)
{
	uint hashid = hash(pObj)%mArr.size();
	T* headObj = mTbl.getObj(mArr[hashid]);
	pObj->mNext = headObj->mNext;
	headObj->mNext = pObj->getId();

	if (objCnt >= mArr.size() * overLoadingFactor) {
		growTable();
	}
}
template <typename T>
void growTable()
{
	uint headLastReversedList = 0;
	uint l,m,r;
	for (int i = 0; i < mArr.size(); i++)
	{
		if (0 != mArr[i]) {
			l = mArr[i];
			m = mTbl.getObj(mArr[i])->mNext;
			if (0 == m) {
				headLastReversedList = l;
				break;
			}
			r = mTbl.getObj(m)->mNext;
			if (0 == r) {
				mTbl.getObj(l)->mNext = headLastReversedList;
				mTbl.getObj(m)->mNext = l;
				headLastReversedList = m;
				break;
			}
		}
		mTbl.getObj(l)->mNext = headLastReversedList;
		while (true)
		{
			mTbl.getObj(m)->mNext = l;			
			l = m;
			m = r;
			r = mTbl.getObj(r)->mNext;
		}
	}
}

