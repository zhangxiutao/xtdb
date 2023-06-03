#ifndef XTLINE_H
#define XTLINE_H
#include "xtrectangle.h"

namespace xtdb {
class XtBlock;
class XtLine : public XtRectangle
{
public:
    static XtLine* create(XtBlock* pBlock);
    void destroy();
};
}
#endif // XTLINE_H
