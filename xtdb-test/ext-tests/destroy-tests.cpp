#include "xtdb.h"
#include "catch.hpp"
#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;
using namespace xtdb;

TEST_CASE("destroy one XtObject", "[destroy one XtObject]")
{
    SECTION("Default Settings")
    {
        const char *fn = "layout.xdb";
        XtBlock* block1 = XtBlock::create();
        XtRectangle* rect1 = XtRectangle::create(block1);
        rect1->setCoodinates(0, 50, 100, 130);
        REQUIRE(rect1->isAlive());
        rect1->destroy();
        REQUIRE(!(rect1->isAlive()));
    }
}
