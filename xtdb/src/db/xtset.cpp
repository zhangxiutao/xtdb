#include "xtset.h"

XtSet::XtSet()
{

}

XtSetIterator XtSet::begin()
{
    return XtSetIterator(mContainer, mContainer->begin());
}
