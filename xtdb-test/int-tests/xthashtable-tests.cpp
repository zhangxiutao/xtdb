#include "_xtrectangle.h"
#include "catch.hpp"
#include <iostream>
#include <string>
#include <filesystem>
#include "xthashtable.hpp"
namespace fs = std::filesystem;
using namespace std;
using namespace xtdb;

TEST_CASE("xthashtable", "[xthashtable tests]")
{
    SECTION("Default Settings")
    {
        XtTable<_XtRectangle> xtb;
        XtHashTable<_XtRectangle> hashtbl(&xtb);

        _XtRectangle* rect1 = xtb.create();
        rect1->mName = "rect1";
        hashtbl.insert(rect1);
        _XtRectangle* rect1_found = hashtbl.find("rect1");
        REQUIRE(string("rect1") == string(rect1_found->mName));

        _XtRectangle* rect2 = xtb.create();
        rect2->mName = "rect2";
        hashtbl.insert(rect2);
        _XtRectangle* rect2_found = hashtbl.find("rect2");
        REQUIRE(string("rect2") == string(rect2_found->mName));

        hashtbl.remove("rect2");
        _XtRectangle* rect2_found_after_remove = hashtbl.find("rect2");
        REQUIRE(!rect2_found_after_remove);

        //TODO: rename test
    }
}
