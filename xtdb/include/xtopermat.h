#ifndef XTOPERMAT_H
#define XTOPERMAT_H

#include "xtstream.h"
#include <vector>

namespace xtdb {
class XtOperMat
{
public:
    enum class transform_type {
        NONE = 0,
        MIRROR_X,
        MIRROR_Y,
        CLOCK_ROTATE_90,
        COUNTER_CLOCK_ROTATE_90
    };
    transform_type mTrans;
    XtOperMat():mTrans(transform_type::NONE){};
    XtOperMat(const transform_type& pTrans);
};
}

#endif // XTOPERMAT_H
