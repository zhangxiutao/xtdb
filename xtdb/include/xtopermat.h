#ifndef XTOPERMAT_H
#define XTOPERMAT_H

#include "xtstream.h"
#include <vector>

namespace xtdb {
class XtOperMat
{
public:
    enum TRANSFORM_TYPE{
        NONE = 0,
        MIRROR_X,
        MIRROR_Y,
        CLOCK_ROTATE_90,
        COUNTER_CLOCK_ROTATE_90
    };
    TRANSFORM_TYPE mTrans;
    XtOperMat():mTrans(NONE){};
    XtOperMat(const TRANSFORM_TYPE& pTrans);
};
}

#endif // XTOPERMAT_H
