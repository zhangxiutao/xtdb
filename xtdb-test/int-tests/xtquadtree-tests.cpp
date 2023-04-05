#include "_xtrectangle.h"
#include "xttable.h"
#include "xtquadtree.h"
#include <unordered_set>
#include "catch.hpp"
#include <iostream>
#include <functional>

using namespace std;
using namespace xtdb;

class Querier
{
public:
    unordered_set<XtShape*> mFoundShapes;
    void onShapeFound(XtShape* pShape)
    {
       mFoundShapes.insert(pShape);
    }
};
TEST_CASE("xtquadtree", "[insert, search, clear]")
{
    SECTION("Default Settings")
    {
        XtQuadtree<_XtRectangle*> t;
        XtTable<_XtRectangle> tbl;
        _XtRectangle* rect1 = tbl.create();
        rect1->mX1 = 500;
        rect1->mY1 = 500;
        rect1->mX2 = 700;
        rect1->mY2 = 700;
        t.insert(rect1);

        _XtRectangle* rect2 = tbl.create();
        rect2->mX1 = 0;
        rect2->mY1 = 1;
        rect2->mX2 = 300;
        rect2->mY2 = 300;
        t.insert(rect2);

        unordered_set<XtShape*> shapesInside;
        shapesInside.insert(reinterpret_cast<XtShape*>(rect1));
        XtRect zone(500, 500, 700, 700);
        Querier querier;
        function<void(XtShape*)> callback = std::bind(&Querier::onShapeFound, &querier, std::placeholders::_1);
        t.search(zone, callback);
        REQUIRE(querier.mFoundShapes == shapesInside);
    }
}
