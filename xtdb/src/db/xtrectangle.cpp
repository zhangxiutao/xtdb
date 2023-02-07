#include "_xtrectangle.h"
#include "_xtblock.h"
#include "xttech.h"
#include "xtstream.h"
_XtRectangle::_XtRectangle():
    mX1(0), mY1(0), mX2(0), mY2(0), _XtShape(_XtTech::METAL1)
{

}

_XtRectangle::_XtRectangle(int pX1, int pY1, int pW, int pH, _XtTech::layer_type pLayer):
    mX1(pX1), mY1(pY1), mX2(pX1 + pW), mY2(pY1 + pH), _XtShape(pLayer)
{

}

_XtRectangle* _XtRectangle::create(_XtBlock* pBlock)
{
    _XtRectangle* rect = pBlock->mRectTbl.create();
}

XtOStream& operator<<(XtOStream& pOS, const _XtRectangle& pRect)
{
    pOS << pRect.mX1;
    pOS << pRect.mY1;
    pOS << pRect.mX2;
    pOS << pRect.mY2;
}
//void XtRectangle::draw(QPainter *pPainter)
//{
//    QPen pen;
//    pen.setBrush(QBrush(QColor(0,255,0,255)));
//    pPainter->setPen(pen);

//    QBrush brush;
//    if(mSelected)
//    {
//        pPainter->setBrush(QColor(255,255,255,255));
//    }
//    else
//    {
//        pPainter->setBrush(GlobalSetting::textureOfLayer.value(mLayer));
//    }
//    pPainter->drawRect(mRect);
//}
