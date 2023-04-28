#include "xtshapequery.h"
#include "_xtblock.h"
#include <unordered_set>
#include "xtrectangle.h"
#include <functional>
#include "_xtrectangle.h"
namespace xtdb {
XtShapeQuery::XtShapeQuery(XtBlock* pBlock):XtQuery(pBlock)
{

}
void XtShapeQuery::query(const XtRect& pRegion, bool ONLY_FULLY_CONTAINED)
{
    _XtBlock* block = reinterpret_cast<_XtBlock*>(mBlock);
    std::function<void(XtShape*)> onShapeFoundCallback = std::bind(&XtShapeQuery::onShapeFound, this, std::placeholders::_1);
    block->mQuadtree->search(pRegion, onShapeFoundCallback, ONLY_FULLY_CONTAINED);
}
}
