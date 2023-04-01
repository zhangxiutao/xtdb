#include "xtdb.h"
#include "catch.hpp"
#include <iostream>
#include <string>
using namespace std;
using namespace xtdb;

class RectExtension
{
public:
    bool mSelectedFlag;
    bool isSelected()
    {
        return mSelectedFlag;
    }
};

TEST_CASE("extension-tests", "[bind extended object to xtdb object]")
{
    SECTION("Default Settings")
    {
        XtBlock* block1 = XtBlock::create();
        XtRectangle* rect1 = XtRectangle::create(block1);
        rect1->setCoodinates(0, 50, 100, 130);
        XtRectangle* rect2 = XtRectangle::create(block1);
        rect2->setCoodinates(0, 30, 200, 250);
        RectExtension re;
        re.mSelectedFlag = true;
        rect1->setExtendedObj(0, &re);
        RectExtension* re_ = (RectExtension*)rect1->getExtendedObj(0);
        REQUIRE(re_->isSelected() == re.isSelected());
        re.mSelectedFlag = false;
        REQUIRE(re_->isSelected() == re.isSelected());
        cout << re_->isSelected() << endl;
        XtBlock::destroy(block1);
    }
}
