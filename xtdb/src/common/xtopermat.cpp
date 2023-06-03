#include "xtopermat.h"

namespace xtdb {
XtOperMat::XtOperMat(const transform_type& pTrans):mTrans(pTrans)
{

};

//XtOStream& operator<<(XtOStream& pOS, XtOperMat& pOperMat)
//{
//    pOS << pOperMat.mTrans;
//    return pOS;
//}

//XtIStream& operator>>(XtIStream& pIS, XtOperMat& pOperMat)
//{
//    pIS >> pOperMat.mTrans;
//    return pIS;
//}
}
