#ifndef XTRECT_H
#define XTRECT_H
namespace xtdb {

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
        return (left() <= pRect.left()) && (top() <= pRect.top()) && (right() >= pRect.right()) && (bottom() >= pRect.bottom());
    }
    inline constexpr bool intersects(const XtRect& pRect) const noexcept
    {
        return !((right() < pRect.left()) || (bottom() < pRect.top()) || (left() > pRect.right()) || (top() > pRect.bottom()));
    }
    inline constexpr int left() const noexcept
    {
        return mX1 < mX2 ? mX1 : mX2;
    }
    inline constexpr int width() const noexcept
    {
        return right() - left() + 1;
    }
    inline constexpr int right() const noexcept
    {
        return  mX2 > mX1 ? mX2 : mX1;
    }
    inline constexpr int height() const noexcept
    {
        return bottom() - top() + 1;
    }
    inline constexpr int top() const noexcept
    {
        return mY1 < mY2 ? mY1 : mY2;
    }
    inline constexpr int bottom() const noexcept
    {
        return mY2 > mY1 ? mY2 : mY1;
    }
};

}

#endif // XTRECT_H
