#include "xtdb.h"
#include "catch.hpp"
#include "xtwireseg.h"
#include "xtpccontainer.h"
#include <iostream>
#include "xtnet.h"

using namespace std;
using namespace xtdb;

TEST_CASE("xtwireseg-test", "[xtwireseg-test]")
{
    SECTION("Default Settings")
    {
        //As a user, I want to create wiresegs having different net, and iterate through
        //all wiresegs, and get the net of each wireseg
        XtBlock* block = XtBlock::create();
        XtNet* net0 = XtNet::create(block);
        net0->setName("net0");
        XtNet* net1 = XtNet::create(block);
        net1->setName("net1");
        XtWireSeg* wireseg0_net0 = XtWireSeg::create(block);
        XtWireSeg* wireseg1_net0 = XtWireSeg::create(block);
        XtWireSeg* wireseg0_net1 = XtWireSeg::create(block);
        XtWireSeg* wireseg1_net1 = XtWireSeg::create(block);
        wireseg0_net0->setNet(net0);
        wireseg1_net0->setNet(net0);
        wireseg0_net1->setNet(net1);
        wireseg1_net1->setNet(net1);
        XtSet<XtWireSeg*> wiresegs = block->getAllWiresegs();
        int i = 0;
        for (XtIterator it = wiresegs.begin(); it != wiresegs.end(); it++)
        {
            if (i == 0)
            {
                REQUIRE(it->getNet() == net0);
            }
            else if (i == 1)
            {
                REQUIRE(it->getNet() == net0);
            }
            else if (i == 2)
            {
                REQUIRE(it->getNet() == net1);
            }
            else if (i == 3)
            {
                REQUIRE(it->getNet() == net1);
            }
            i++;
        }
        REQUIRE(4 == i);
        XtBlock::destroy(block);
    }
}
TEST_CASE("xtnetwireseg-test", "[xtnetwireseg-test]")
{
    SECTION("Default Settings")
    {
        //As a user, I want to create wiresegs having different net, and iterate through
        //all wiresegs of same net
        XtBlock* block = XtBlock::create();
        XtNet* net0 = XtNet::create(block);
        net0->setName("net0");
        XtNet* net1 = XtNet::create(block);
        net1->setName("net1");
        XtWireSeg* wireseg0_net0 = XtWireSeg::create(block);
        XtWireSeg* wireseg1_net0 = XtWireSeg::create(block);
        XtWireSeg* wireseg0_net1 = XtWireSeg::create(block);
        XtWireSeg* wireseg1_net1 = XtWireSeg::create(block);
        XtWireSeg* wireseg2_net1 = XtWireSeg::create(block);

        wireseg0_net0->setNet(net0);
        wireseg1_net0->setNet(net0);
        wireseg0_net1->setNet(net1);
        wireseg1_net1->setNet(net1);
        wireseg2_net1->setNet(net1);
        XtSet<XtWireSeg*> wiresegs_net0 = net0->getWiresegs();
        int i = 0;
        for (XtIterator it = wiresegs_net0.begin(); it != wiresegs_net0.end(); it++)
        {
            REQUIRE(it->getNet() == net0);
            i++;
        }
        REQUIRE(2 == i);
        XtSet<XtWireSeg*> wiresegs_net1 = net1->getWiresegs();
        i = 0;
        for (XtIterator it = wiresegs_net1.begin(); it != wiresegs_net1.end(); it++)
        {
            REQUIRE(it->getNet() == net1);
            i++;
        }
        REQUIRE(3 == i);
        XtBlock::destroy(block);
    }
}
TEST_CASE("xtnetnetobj-test", "[xtnetnetobj-test]")
{
    SECTION("Default Settings")
    {
//        XtWireSeg* wireseg1 = XtWireSeg::create(block);
//        wireseg1->setNet(net);
//        XtWireSeg* wireseg2 = XtWireSeg::create(block);
//        wireseg2->setNet(net);
//        XtSet<XtNetObject**> netObjs = net->getNetObjects();
//        for (XtIterator it = netObjs.begin(); it != netObjs.end(); it++)
//        {
//            cout << XtNet::getNet(mNetId) << endl;
//        }
//        wireseg1->destroy();
//        wireseg2->destroy();
    }
}
