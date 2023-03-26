#include "xtshapequery.h"
#include "_xtblock.h"
#include <unordered_set>
#include "xtrectangle.h"

namespace xtdb {
XtShapeQuery::XtShapeQuery(XtBlock* pBlock):XtQuery(pBlock)
{

}
void XtShapeQuery::query(const XtRect& pRegion)
{
    std::unordered_set<_XtRectangle*> foundShapes;
    _XtBlock* block = reinterpret_cast<_XtBlock*>(mBlock);
    block->mQuadtree->search(pRegion, foundShapes);
    for (auto& shape : foundShapes)
    {
        OnShapeFound(reinterpret_cast<XtRectangle*>(shape));
    }
}

}
