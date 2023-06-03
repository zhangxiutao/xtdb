#include "_xtrectangle.h"
#include "xttable.h"
#include "catch.hpp"
#include <iostream>
#include <string>
#include <filesystem>
#include "xthashtable.h"
namespace fs = std::filesystem;
using namespace std;
using namespace xtdb;

TEST_CASE("xttable", "[xttable tests]")
{
    SECTION("Default Settings")
    {
        // as a user
        // I want to create a rect and get its id
        // so that we can make sure that the creation and destruction is correct
        XtTable<_XtRectangle> xtb;
        for (int i = 1; i < 128; i++) {
            _XtRectangle* rect = xtb.create();
            REQUIRE(rect->getExtId() == i);
        }
        //create the first obj in the second page
        _XtRectangle* rect = xtb.create();
        REQUIRE(rect->getExtId() == 128);
        //destroy the first obj in the first page
        _XtRectangle* firstRect = (_XtRectangle*)xtb.getPtr(1);
        xtb.destroy(firstRect);
        REQUIRE(((_XtFreeObject*)firstRect)->mNext == (1 << 7 | 1));
        //destroy the third obj in the first page
        _XtRectangle* thirdRect = (_XtRectangle*)xtb.getPtr(3);
        xtb.destroy(thirdRect);
        REQUIRE(((_XtFreeObject*)thirdRect)->mNext == (0 << 7 | 1));
        //test if the next obj of the second obj is the 4th obj
        REQUIRE(xtb.next(2) == 4);

        XtObjectTable* gotTbl = rect->getTable();
        XtContainer* gotCon = (XtContainer*)gotTbl;
        uint gotConBegin = gotCon->begin();
        uint gotConSize = gotCon->size();
    }
}
