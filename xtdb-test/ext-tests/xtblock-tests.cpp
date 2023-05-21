#include "xtdb.h"
#include "catch.hpp"
#include <iostream>
#include <string>
#include <filesystem>
#include "xtinst.h"
#include "_xtblock.h"
#include "xttable.h"
namespace fs = std::filesystem;
using namespace std;
using namespace xtdb;

TEST_CASE("xtblock-tests", "[load all sub blocks]")
{
    SECTION("Default Settings")
    {
        //as a user, I want to load all sub blocks of a block into memory, so that I can access all nodes of the cell tree of this block
        //create,write, and close blocks
        XtBlock* blk_inv = XtBlock::create();
        XtBlock* blk_pmos = XtBlock::create();
        XtSet<XtBlock*> blocks = XtBlock::getAllBlocks();
        REQUIRE(2 == blocks.size());
        XtInst* inst = XtInst::create(blk_inv);
        REQUIRE(1 == blk_inv->getAllInsts().size());
        const char* instCellViewName = "pmos/layout.xtb";
        const char* instName = "INS000";
        inst->setName(instName);
        inst->setCellViewName(instCellViewName);
        REQUIRE(string(instCellViewName) == string((blk_inv->getAllInsts().begin())->getCellViewName()));
        blk_inv->saveAndClose("inv/layout.xtb");
        blk_pmos->saveAndClose(instCellViewName);
        REQUIRE(blocks.empty());

        //load all sub blocks of cell tree
        const char *cellView = "inv/layout.xtb";
        XtBlock::loadAllSubBlocks(cellView);

        //verify that the set of loaded blocks is equal to the set of all sub blocks of the cell tree
        XtTable<_XtBlock> expectedBlkTbl;
        _XtBlock* expected_blk_inv = expectedBlkTbl.create();
        _XtBlock* expected_blk_pmos = expectedBlkTbl.create();
        XtInst* expected_blk_inv_inst = XtInst::create(reinterpret_cast<XtBlock*>(expected_blk_inv));
        expected_blk_inv_inst->setBlockId(expected_blk_pmos->getExtId());
        expected_blk_inv_inst->setName(instName);
        expected_blk_inv_inst->setCellViewName(instCellViewName);
        bool res = (expectedBlkTbl == _XtBlock::blockTbl);
        REQUIRE(res == true);
    }
}
