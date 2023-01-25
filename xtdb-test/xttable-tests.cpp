#include "xttable.hpp"
#include "catch.hpp"
#include "_xtrectangle.h"
#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

TEST_CASE("xttable", "[xttable tests]")
{
    SECTION("Default Settings")
    {
        // as a user
        // I want to create a rect and get its id
        // so that we can make sure that the creation is correct
        XtTable<_XtRectangle> xtb;
        for (int i = 0; i < 256; i++) {
            _XtRectangle* rect = xtb.create();
            REQUIRE(rect->getId() == i);
        }
    }
}
