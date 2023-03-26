#include "_xtrectangle.h"
#include "xttable.hpp"
#include "xtquadtree.hpp"
#include <unordered_set>
#include "catch.hpp"
#include <iostream>

using namespace std;
using namespace xtdb;

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
        rect2->mX2 = 700;
        rect2->mY2 = 700;
        t.insert(rect2);

        XtRect zone(0, 0, 700, 700);
        unordered_set<_XtRectangle*> foundRects;
        t.search(zone, foundRects);
    }
}
