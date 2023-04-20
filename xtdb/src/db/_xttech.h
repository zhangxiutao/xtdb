#ifndef _XTTECH_H
#define _XTTECH_H
#include "xtsize.h"
namespace xtdb {
class _XtTech
{
public:
    _XtTech();
//    static constexpr XtSize canvasSize{800, 800};
//    static constexpr int gridWidth = 100;
    enum layer_type
    {
        METAL1 = 0,
        METAL2,
        METAL3,
        POLY
    };
//    static XtColor textureOfLayer[4];
};
}
#endif // XTTECH_H
