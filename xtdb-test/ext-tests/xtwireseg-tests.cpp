#include "xtdb.h"
#include "catch.hpp"
#include <iostream>
#include <string>
#include "_xtrectangle.h"
#include "xttable.h"
using namespace std;
using namespace xtdb;

TEST_CASE("add and delete shapes of wiresegs", "[add and delete shapes of wiresegs]")
{
    SECTION("Default Settings")
    {
        XtBlock* block = XtBlock::create();
        XtWireSeg* wireSeg = XtWireSeg::create(block);
        XtRectangle* rect = XtRectangle::create(block);
        wireSeg->setShape(rect);
        XtShape* shape = wireSeg->getShape();
        REQUIRE(shape->getKind() == xtobject_kind::RECTANGLE);

        XtLine* line = XtLine::create(block);
        wireSeg->setShape(line);
        shape = wireSeg->getShape();
        REQUIRE(shape->getKind() == xtobject_kind::LINE);

        XtBlock::destroy(block);
    }
}
