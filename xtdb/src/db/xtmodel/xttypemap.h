#ifndef XTTYPEMAP_H
#define XTTYPEMAP_H
#include "_xtnet.h"
#include "xtnet.h"
#include "_xtwireseg.h"
#include "xtwireseg.h"
#include "_xtport.h"
#include "xtport.h"
#include "_xtportinst.h"
#include "xtportinst.h"
#include "_xtvia.h"
#include "xtvia.h"
#include "_xtshape.h"
#include "xtshape.h"
#include "_xtinst.h"
#include "xtinst.h"
#include "_xtline.h"
#include "xtline.h"
#include "_xteobject.h"
#include "xteobject.h"
#include "_xtblock.h"
#include "xtblock.h"
#include "_xtnetobject.h"
#include "xtnetobject.h"

namespace xtdb {
template <typename T>
class _ {};

template <>
class _<XtNet>
{
public:
    typedef _XtNet type;
};

template <>
class _<XtWireSeg>
{
public:
    typedef _XtWireSeg type;
};

template <>
class _<XtPort>
{
public:
    typedef _XtPort type;
};

template <>
class _<XtPortInst>
{
public:
    typedef _XtPortInst type;
};

template <>
class _<XtVia>
{
public:
    typedef _XtVia type;
};

template <>
class _<XtShape>
{
public:
    typedef _XtShape type;
};

template <>
class _<XtInst>
{
public:
    typedef _XtInst type;
};

template <>
class _<XtLine>
{
public:
    typedef _XtLine type;
};

template <>
class _<XtEObject>
{
public:
    typedef _XtEObject type;
};

template <>
class _<XtBlock>
{
public:
    typedef _XtBlock type;
};

template <>
class _<XtNetObject>
{
public:
    typedef _XtNetObject type;
};
}
#endif // XTTYPEMAP_H
