#include "xtdb.h"
#include "catch.hpp"
#include "xtshapequery.h"
#include "xtrectangle.h"
#include <iostream>
#include <string>
using namespace std;
using namespace xtdb;

class MyShapeQuery : public XtShapeQuery
{
public:
    MyShapeQuery(XtBlock* pBlock):XtShapeQuery(pBlock){};
    void OnShapeFound(XtShape* pShape) override
    {
        XtRectangle* rect = (XtRectangle*)pShape;
        cout << rect->getX1() << "," << rect->getY1() << "," << rect->getX2() << "," << rect->getY2() << endl;
    }
};
TEST_CASE("region query", "[region query]")
{
    SECTION("Default Settings")
    {
        XtBlock* block1 = XtBlock::create();
        XtRectangle* rect1 = XtRectangle::create(block1);
        rect1->setCoodinates(0, 0, 50, 50);
        XtRectangle* rect2 = XtRectangle::create(block1);
        rect2->setCoodinates(100, 100, 200, 200);
        MyShapeQuery msq(block1);
        msq.query(XtRect(25, 25, 75, 75));
    }
}
