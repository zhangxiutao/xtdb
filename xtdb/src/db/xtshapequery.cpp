#include "xtshapequery.h"
#include "_xtblock.h"
#include <unordered_set>
#include "xtrectangle.h"
#include <functional>

namespace xtdb {
XtShapeQuery::XtShapeQuery(XtBlock* pBlock):XtQuery(pBlock)
{

}
void XtShapeQuery::onShapeFoundWrapper(XtShape* pShape)
{
    onShapeFound(pShape);
}
void XtShapeQuery::query(const XtRect& pRegion)
{
    std::unordered_set<_XtRectangle*> foundShapes;
    _XtBlock* block = reinterpret_cast<_XtBlock*>(mBlock);
    std::function<void(XtShape*)> onShapeFoundCallback = std::bind(&XtShapeQuery::onShapeFound, this, std::placeholders::_1);
    block->mQuadtree->search(pRegion, onShapeFoundCallback);
//    for (auto& shape : foundShapes)
//    {
//        onShapeFound(reinterpret_cast<XtRectangle*>(shape));
//    }
}

}
