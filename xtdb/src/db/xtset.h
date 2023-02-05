#ifndef XTSET_H
#define XTSET_H
#include "xtiterator.h"
#include "xtcontainer.h"
class XtSet
{
private:
    XtContainer* mContainer;
public:
    XtSet();
    XtIterator begin();
    XtIterator end();
};

#endif // XTSET_H
