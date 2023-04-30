#include "xtdb.h"
#include "catch.hpp"
#include <iostream>
#include <string>
using namespace std;
using namespace xtdb;

TEST_CASE("iterate through xttable", "[iterate through xttable]")
{
    SECTION("Default Settings")
    {
        XtBlock* block1 = XtBlock::create();
        XtRectangle* rect1 = XtRectangle::create(block1);
        rect1->setCoodinates(0, 50, 100, 130);
        XtRectangle* rect2 = XtRectangle::create(block1);
        rect2->setCoodinates(0, 30, 200, 250);
        XtSet<XtShape*> shapesSet = block1->getAllShapes();
        for (XtIterator it = shapesSet.begin(); it != shapesSet.end(); it++)
        {
            XtRectangle* rectangle = (XtRectangle*)(*it);
            if (1 == rectangle->getId())
            {
                REQUIRE(0 == rectangle->getX1());
                REQUIRE(50 == rectangle->getY1());
                REQUIRE(100 == rectangle->getX2());
                REQUIRE(130 == rectangle->getY2());
            }
            else if (2 == rectangle->getId())
            {
                REQUIRE(0 == rectangle->getX1());
                REQUIRE(30 == rectangle->getY1());
                REQUIRE(200 == rectangle->getX2());
                REQUIRE(250 == rectangle->getY2());
            }
            else
            {
                cout << "wrong id!" << endl;
                break;
            }
        }
        XtBlock::destroy(block1);
    }
}
