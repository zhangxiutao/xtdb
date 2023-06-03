#include "xtdb.h"
#include "catch.hpp"
#include <iostream>
#include <string>
#include <filesystem>
#include "_xtblock.h"
#include "xtdm.h"

namespace fs = std::filesystem;
using namespace std;
using namespace xtdb;

TEST_CASE("xtstream-test", "[write xttable and reload it]")
{
    SECTION("Default Settings")
    {
        std::string cell = "inv";
        std::string cellView = "inv/layout.xtb";
        XtBlock* xtblock1 = XtBlock::create();
        XtRectangle* rect = XtRectangle::create(xtblock1);
        rect->setCoodinates(0, 0, 100, 100);
        xtblock1->write(cellView.c_str());
        REQUIRE(fs::exists(cellView));
        XtBlock* xtblock2 = XtBlock::create();
        xtblock2->load(cellView.c_str());
        REQUIRE(!xtblock2->getName()); //since inv/layout.xtb is already opened

        //copy the file and rename it, so that block with same content but different name can be created.
        std::string _cell = std::string("_") + cell;
        std::string _cellView = "_" + cellView;
        fs::remove_all(_cell);
        fs::copy(cell, _cell, fs::copy_options::recursive);
        xtblock2->load(_cellView.c_str());
        REQUIRE(*xtblock1 == *xtblock2);
        XtBlock::destroy(xtblock1);
        XtBlock::destroy(xtblock2);
    }
}
