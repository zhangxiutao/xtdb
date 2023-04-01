#include "xtdb.h"
#include "catch.hpp"
#include <iostream>
#include <string>
#include <filesystem>
#include "_xtblock.h"
namespace fs = std::filesystem;
using namespace std;
using namespace xtdb;

TEST_CASE("xtstream-test", "[write xttable and reload it]")
{
    SECTION("Default Settings")
    {
        const char *fn = "layout.xdb";
        XtBlock* xtblock1 = XtBlock::create();
        XtRectangle* rect = XtRectangle::create(xtblock1);
        rect->setCoodinates(0, 0, 100, 100);
        xtblock1->write(fn);
        REQUIRE(fs::exists(fn));
        XtBlock* xtblock2 = XtBlock::create();
        xtblock2->load(fn);
        REQUIRE(*xtblock1 == *xtblock2);
        XtBlock::destroy(xtblock1);
        XtBlock::destroy(xtblock2);
    }
}
