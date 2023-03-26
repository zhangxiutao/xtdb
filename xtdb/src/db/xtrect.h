#ifndef XTRECT_H
#define XTRECT_H

class XtRect
{
public:
    int mX1;
    int mY1;
    int mX2;
    int mY2;
    XtRect():mX1(0), mY1(0), mX2(0), mY2(0){};
    XtRect(int pX1, int pY1, int pX2, int pY2):mX1(pX1), mY1(pY1), mX2(pX2), mY2(pY2){};
    inline constexpr bool contains(const XtRect& pRect) const noexcept
    {
        return (mX1 <= pRect.mX1) && (mY1 <= pRect.mY1) && (mX2 >= pRect.mX2) && (mY2 >= pRect.mY2);
    }
    inline constexpr bool intersects(const XtRect& pRect) const noexcept
    {
        return !((mX2 < pRect.mX1) || (mY2 < pRect.mY1) || (mY1 > pRect.mY2) || (mX1 > pRect.mX2));
    }
    inline constexpr int left() const noexcept
    {
        return mX1;
    }
    inline constexpr int width() const noexcept
    {
        return mX2 - mX1 + 1;
    }
    inline constexpr int right()
    {
        return mX2;
    }
    inline constexpr int height()
    {
        return mY2 - mY1 + 1;
    }
    inline constexpr int top()
    {
        return mY1;
    }
    inline constexpr int bottom()
    {
        return mY2;
    }
};

#endif // XTRECT_H
