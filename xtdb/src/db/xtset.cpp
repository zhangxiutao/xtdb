#include "xtset.h"

XtSet::XtSet()
{

}

XtIterator XtSet::begin()
{
    return XtIterator(mContainer, mContainer->begin());
}

XtIterator XtSet::end()
{
    return XtIterator(mContainer, mContainer->end());
}
