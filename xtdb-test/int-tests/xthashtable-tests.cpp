#include "_xtrectangle.h"
#include "catch.hpp"
#include <iostream>
#include <string>
#include <filesystem>
#include "xthashtable.hpp"
namespace fs = std::filesystem;
using namespace std;
using namespace xtdb;

TEST_CASE("xthashtable", "[insert, remove, find, iteration]")
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

        _XtRectangle* rect3 = xtb.create();
        rect3->mName = "rect3";
        hashtbl.insert(rect3);
        _XtRectangle* rect3_found = hashtbl.find("rect3");
        REQUIRE(string("rect3") == string(rect3_found->mName));

        hashtbl.initItr();
        _XtRectangle* rect;
        while ((rect = hashtbl.next()))
        {
            cout << rect->mName << endl;
        }
        //TODO: rename test
    }
}
