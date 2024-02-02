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
    constexpr MatroskaProfile(bool webm, bool divx, version_type min, version_type max = ANY_VERSION)
        :EbmlDocVersion(min, max)
        ,InWebM(webm)
        ,InDivX(divx)
    {}

    const bool InWebM;
    const bool InDivX;
};

}

#define DEFINE_MKX_CONTEXT(a)                DEFINE_xxx_CONTEXT(a,GetKaxGlobal_Context)

#define DEFINE_MKX_MASTER_CONS(a,b,d,i,e,versions)  DEFINE_xxx_MASTER_CONS(a,b,d,i,e,versions,GetKaxGlobal_Context)
#define DEFINE_MKX_MASTER(a,b,d,i,e,versions)       DEFINE_xxx_MASTER(a,b,d,i,e,versions,GetKaxGlobal_Context)
#define DEFINE_MKX_MASTER_ORPHAN(a,b,i,d,versions)  DEFINE_xxx_MASTER_ORPHAN(a,b,i,d,versions,GetKaxGlobal_Context)
#define DEFINE_MKX_UINTEGER_DEF(a,b,d,e,versions,v) DEFINE_xxx_UINTEGER_DEF(a,b,d,e,versions,GetKaxGlobal_Context,v)
#define DEFINE_MKX_SINTEGER_DEF(a,b,d,e,versions,v) DEFINE_xxx_SINTEGER_DEF(a,b,d,e,versions,GetKaxGlobal_Context,v)
#define DEFINE_MKX_UINTEGER(a,b,d,e,versions)       DEFINE_xxx_UINTEGER(a,b,d,e,versions,GetKaxGlobal_Context)
#define DEFINE_MKX_SINTEGER(a,b,d,e,versions)       DEFINE_xxx_SINTEGER(a,b,d,e,versions,GetKaxGlobal_Context)
#define DEFINE_MKX_STRING_DEF(a,b,d,e,versions,v)   DEFINE_xxx_STRING_DEF(a,b,d,e,versions,GetKaxGlobal_Context,v)
#define DEFINE_MKX_STRING(a,b,d,e,versions)         DEFINE_xxx_STRING(a,b,d,e,versions,GetKaxGlobal_Context)
#define DEFINE_MKX_UNISTRING(a,b,d,e,versions)      DEFINE_xxx_UNISTRING(a,b,d,e,versions,GetKaxGlobal_Context)
#define DEFINE_MKX_BINARY(a,b,d,e,versions)         DEFINE_xxx_BINARY(a,b,d,e,versions,GetKaxGlobal_Context)
#define DEFINE_MKX_FLOAT_DEF(a,b,d,e,versions,v)    DEFINE_xxx_FLOAT_DEF(a,b,d,e,versions,GetKaxGlobal_Context,v)
#define DEFINE_MKX_FLOAT(a,b,d,e,versions)          DEFINE_xxx_FLOAT(a,b,d,e,versions,GetKaxGlobal_Context)
#define DEFINE_MKX_DATE(a,b,d,e,versions)           DEFINE_xxx_DATE(a,b,d,e,versions,GetKaxGlobal_Context)
#define DEFINE_MKX_BINARY_CONS(a,b,d,e,versions)    DEFINE_xxx_CLASS_CONS(a,b,d,e,GetKaxGlobal_Context) \
    constexpr const libebml::EbmlCallbacks a::ClassInfos(a::Create, Id_##a, false, false, e, Context_##a, versions);
#define DEFINE_MKX_SINTEGER_CONS(a,b,d,e,versions)  DEFINE_xxx_CLASS_CONS(a,b,d,e,GetKaxGlobal_Context) \
    const libebml::EbmlCallbacksDefault<std::int64_t> a::ClassInfos(a::Create, Id_##a, e, Context_##a, versions);

#define MATROSKA_CLASS_BODY(x) \
    EBML_CONCRETE_CLASS(x)

#define DECLARE_MKX_MASTER(x)   \
    DECLARE_xxx_MASTER(x, MATROSKA_DLL_API) \
    using EbmlMaster::EbmlMaster; \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_MASTER_CONS(x)   \
    DECLARE_xxx_MASTER(x, MATROSKA_DLL_API) \
    ~x() override; \
    x(const x & ElementToClone); \
    x& operator=(const x &) = delete; \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_BINARY(x)   \
    DECLARE_xxx_BINARY(x, MATROSKA_DLL_API) \
    using EbmlBinary::EbmlBinary; \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_BINARY_CONS(x)   \
    DECLARE_xxx_BINARY(x, MATROSKA_DLL_API) \
    ~x() override; \
    x(const x & ElementToClone); \
    x& operator=(const x &) = delete; \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_BINARY_LENGTH(x,len)   \
    DECLARE_xxx_BINARY_LENGTH(x, len, MATROSKA_DLL_API) \
    using EbmlBinary::EbmlBinary; \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_UNISTRING(x) \
    DECLARE_xxx_UNISTRING(x, MATROSKA_DLL_API) \
    using EbmlUnicodeString::EbmlUnicodeString; \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_STRING(x)   \
    DECLARE_xxx_STRING(x, MATROSKA_DLL_API) \
    using EbmlString::EbmlString; \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_STRING_DEF(x)   \
    DECLARE_xxx_STRING_DEF(x, MATROSKA_DLL_API) \
    using EbmlString::EbmlString; \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_UINTEGER(x) \
    DECLARE_xxx_UINTEGER(x, MATROSKA_DLL_API) \
    using EbmlUInteger::EbmlUInteger; \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_UINTEGER_DEF(x) \
    DECLARE_xxx_UINTEGER_DEF(x, MATROSKA_DLL_API) \
    using EbmlUInteger::EbmlUInteger; \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_SINTEGER_CONS(x) \
    DECLARE_xxx_SINTEGER(x, MATROSKA_DLL_API) \
    ~x() override; \
    x(const x & ElementToClone); \
    x& operator=(const x &) = delete; \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_SINTEGER(x) \
    DECLARE_xxx_SINTEGER(x, MATROSKA_DLL_API) \
    using EbmlSInteger::EbmlSInteger; \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_SINTEGER_DEF(x) \
    DECLARE_xxx_SINTEGER_DEF(x, MATROSKA_DLL_API) \
    using EbmlSInteger::EbmlSInteger; \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_DATE(x)     \
    DECLARE_xxx_DATE(x, MATROSKA_DLL_API) \
    using EbmlDate::EbmlDate; \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_DATE_DEF(x)     \
    DECLARE_xxx_DATE_DEF(x, MATROSKA_DLL_API) \
    using EbmlDate::EbmlDate; \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_FLOAT(x)    \
    DECLARE_xxx_FLOAT(x, MATROSKA_DLL_API) \
    using EbmlFloat::EbmlFloat; \
    MATROSKA_CLASS_BODY(x)

#define DECLARE_MKX_FLOAT_DEF(x)    \
    DECLARE_xxx_FLOAT_DEF(x, MATROSKA_DLL_API) \
    using EbmlFloat::EbmlFloat; \
    MATROSKA_CLASS_BODY(x)

#endif // LIBMATROSKA_DEFINES_H
