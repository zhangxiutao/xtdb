#include "xtstream.h"
#include "catch.hpp"
#include <iostream>
#include <string>
#include <filesystem>
#include "xtblock.h"
#include "xtrectangle.h"

namespace fs = std::filesystem;
using namespace std;

TEST_CASE("New layout", "[create new layout]")
{
    SECTION("Default Settings")
    {
        const char *fn = "layout.xdb";
        XtBlock block;


        char *read_s;
        XtOStream os(fn);

        REQUIRE(fs::exists(fn));

        XtIStream is(fn);
        is >> read_s;
        REQUIRE(string(s) == string(read_s));
    }
}
