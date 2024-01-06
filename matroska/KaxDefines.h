// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_DEFINES_H
#define LIBMATROSKA_DEFINES_H

#include <ebml/EbmlVersion.h>
#include <ebml/EbmlElement.h>

namespace libmatroska {

class MATROSKA_DLL_API MatroskaProfile : public libebml::EbmlDocVersion
{
public:
    constexpr MatroskaProfile(bool webm, num_version min, num_version max = ANY_VERSION)
        :EbmlDocVersion(min, max)
        ,InWebM(webm)
    {}

    const bool InWebM;
};

}

#define DEFINE_MKX_CONTEXT(a)                DEFINE_xxx_CONTEXT(a,GetKaxGlobal_Context)

#define DEFINE_MKX_MASTER_CONS(a,b,c,d,i,e,versions)  DEFINE_xxx_MASTER_CONS(a,b,c,d,i,e,versions,GetKaxGlobal_Context)
#define DEFINE_MKX_MASTER(a,b,c,d,i,e,versions)       DEFINE_xxx_MASTER(a,b,c,d,i,e,versions,GetKaxGlobal_Context)
#define DEFINE_MKX_MASTER_ORPHAN(a,b,c,i,d,versions)  DEFINE_xxx_MASTER_ORPHAN(a,b,c,i,d,versions,GetKaxGlobal_Context)
#define DEFINE_MKX_UINTEGER_DEF(a,b,c,d,e,versions,v) DEFINE_xxx_UINTEGER_DEF(a,b,c,d,e,versions,GetKaxGlobal_Context,v)
#define DEFINE_MKX_SINTEGER_DEF(a,b,c,d,e,versions,v) DEFINE_xxx_SINTEGER_DEF(a,b,c,d,e,versions,GetKaxGlobal_Context,v)
#define DEFINE_MKX_UINTEGER(a,b,c,d,e,versions)       DEFINE_xxx_UINTEGER(a,b,c,d,e,versions,GetKaxGlobal_Context)
#define DEFINE_MKX_SINTEGER(a,b,c,d,e,versions)       DEFINE_xxx_SINTEGER(a,b,c,d,e,versions,GetKaxGlobal_Context)
#define DEFINE_MKX_STRING_DEF(a,b,c,d,e,versions,v)   DEFINE_xxx_STRING_DEF(a,b,c,d,e,versions,GetKaxGlobal_Context,v)
#define DEFINE_MKX_STRING(a,b,c,d,e,versions)         DEFINE_xxx_STRING(a,b,c,d,e,versions,GetKaxGlobal_Context)
#define DEFINE_MKX_UNISTRING(a,b,c,d,e,versions)      DEFINE_xxx_UNISTRING(a,b,c,d,e,versions,GetKaxGlobal_Context)
#define DEFINE_MKX_BINARY(a,b,c,d,e,versions)         DEFINE_xxx_BINARY(a,b,c,d,e,versions,GetKaxGlobal_Context)
#define DEFINE_MKX_FLOAT_DEF(a,b,c,d,e,versions,v)    DEFINE_xxx_FLOAT_DEF(a,b,c,d,e,versions,GetKaxGlobal_Context,v)
#define DEFINE_MKX_FLOAT(a,b,c,d,e,versions)          DEFINE_xxx_FLOAT(a,b,c,d,e,versions,GetKaxGlobal_Context)
#define DEFINE_MKX_DATE(a,b,c,d,e,versions)           DEFINE_xxx_DATE(a,b,c,d,e,versions,GetKaxGlobal_Context)
#define DEFINE_MKX_BINARY_CONS(a,b,c,d,e,versions)    DEFINE_xxx_CLASS_CONS(a,b,c,d,e,GetKaxGlobal_Context) \
    const libebml::EbmlCallbacks a::ClassInfos(a::Create, Id_##a, false, e, Context_##a, versions);
#define DEFINE_MKX_SINTEGER_CONS(a,b,c,d,e,versions)  DEFINE_xxx_CLASS_CONS(a,b,c,d,e,GetKaxGlobal_Context) \
    const libebml::EbmlCallbacksDefault<std::int64_t> a::ClassInfos(a::Create, Id_##a, e, Context_##a, versions);

#define MATROSKA_CLASS_BODY(x) \
    EBML_CONCRETE_CLASS(x)

#define DECLARE_MKX_MASTER(x)   \
    DECLARE_xxx_MASTER(x, MATROSKA_DLL_API) \
    x(const x & ElementToClone) :EbmlMaster(ElementToClone) {} \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_MASTER_CONS(x)   \
    DECLARE_xxx_MASTER(x, MATROSKA_DLL_API) \
    x(const x & ElementToClone); \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_BINARY(x)   \
    DECLARE_xxx_BINARY(x, MATROSKA_DLL_API) \
    x(const x & ElementToClone) :libebml::EbmlBinary(ElementToClone) {} \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_BINARY_CONS(x)   \
    DECLARE_xxx_BINARY(x, MATROSKA_DLL_API) \
    x(const x & ElementToClone); \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_UNISTRING(x) \
    DECLARE_xxx_UNISTRING(x, MATROSKA_DLL_API) \
    x(const x & ElementToClone) :libebml::EbmlUnicodeString(ElementToClone) {} \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_STRING(x)   \
    DECLARE_xxx_STRING(x, MATROSKA_DLL_API) \
    x(const x & ElementToClone) :libebml::EbmlString(ElementToClone) {} \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_STRING_DEF(x)   \
    DECLARE_xxx_STRING_DEF(x, MATROSKA_DLL_API) \
    x(const x & ElementToClone) :libebml::EbmlString(ElementToClone) {} \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_UINTEGER(x) \
    DECLARE_xxx_UINTEGER(x, MATROSKA_DLL_API) \
    x(const x & ElementToClone) :libebml::EbmlUInteger(ElementToClone) {} \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_UINTEGER_DEF(x) \
    DECLARE_xxx_UINTEGER_DEF(x, MATROSKA_DLL_API) \
    x(const x & ElementToClone) :libebml::EbmlUInteger(ElementToClone) {} \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_SINTEGER_CONS(x) \
    DECLARE_xxx_SINTEGER(x, MATROSKA_DLL_API) \
    x(const x & ElementToClone); \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_SINTEGER(x) \
    DECLARE_xxx_SINTEGER(x, MATROSKA_DLL_API) \
    x(const x & ElementToClone) :libebml::EbmlSInteger(ElementToClone) {} \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_SINTEGER_DEF(x) \
    DECLARE_xxx_SINTEGER_DEF(x, MATROSKA_DLL_API) \
    x(const x & ElementToClone) :libebml::EbmlSInteger(ElementToClone) {} \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_DATE(x)     \
    DECLARE_xxx_DATE(x, MATROSKA_DLL_API) \
    x(const x & ElementToClone) :libebml::EbmlDate(ElementToClone) {} \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_DATE_DEF(x)     \
    DECLARE_xxx_DATE_DEF(x, MATROSKA_DLL_API) \
    x(const x & ElementToClone) :libebml::EbmlDate(ElementToClone) {} \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_FLOAT(x)    \
    DECLARE_xxx_FLOAT(x, MATROSKA_DLL_API) \
    x(const x & ElementToClone) :libebml::EbmlFloat(ElementToClone) {} \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_FLOAT_DEF(x)    \
    DECLARE_xxx_FLOAT_DEF(x, MATROSKA_DLL_API) \
    x(const x & ElementToClone) :libebml::EbmlFloat(ElementToClone) {} \
    MATROSKA_CLASS_BODY(x)

#endif // LIBMATROSKA_DEFINES_H
