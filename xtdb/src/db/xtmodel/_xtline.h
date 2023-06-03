#ifndef _XTLINE_H
#define _XTLINE_H

#include "_xtrectangle.h"

namespace xtdb {
class _XtLine : public _XtRectangle
{
public:
    enum class direction {
        HORIZONTAL,
        VERTICAL
    };
    direction mDirection;
    static xtobject_kind mKind;
    _XtLine();
};
}
#endif // _XTLINE_H
