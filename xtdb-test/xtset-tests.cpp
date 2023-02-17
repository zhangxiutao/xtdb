#include "xtblock.h"
#include "xtrectangle.h"
#include "xtset.h"
#include "catch.hpp"
#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

TEST_CASE("iterate through xttable", "[iterate through xttable]")
{
    SECTION("Default Settings")
    {
        const char *fn = "layout.xdb";
        XtBlock* block1 = XtBlock::create();
        XtRectangle* rect1 = XtRectangle::create(block1);
        rect1->setCoodinates(0, 0, 100, 100);
        XtRectangle* rect2 = XtRectangle::create(block1);
        rect2->setCoodinates(0, 0, 200, 200);
        XtSet shapesSet = block1->getAllShapes();
        for (XtIterator it = shapesSet.begin(); it != shapesSet.end(); it++)
        {

        }
    }
}
