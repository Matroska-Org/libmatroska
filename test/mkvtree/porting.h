#include <ebml/EbmlMaster.h>
#include <ebml/EbmlUInteger.h>
#include <ebml/EbmlVoid.h>
#include <ebml/EbmlStream.h>
#include <ebml/StdIOCallback.h>
#include <ebml/EbmlHead.h>

#include <matroska/KaxSemantic.h>
#include <matroska/KaxCluster.h>
#include <matroska/KaxBlock.h>
#include <matroska/KaxBlockData.h>
#include <matroska/KaxSeekHead.h>
#include <matroska/KaxCuesData.h>
#include <matroska/KaxSegment.h>
#include <matroska/KaxContexts.h>

#include <limits>
#include <cstdint>
#include <cinttypes>

// FIXME remove ?
using tchar_t = char;
#define T(x)  x
#define TSIZEOF(x) sizeof(x)
#define TPRId64 PRId64
#define TPRIx64 PRIx64
#define tcslen(s)  strlen(s)
#define tcscpy_s(d,dn,s) strcpy(d,s)
#define tcscat_s(d,dn,s) strcat(d,s)
#define tcscmp(a,b)  strcmp(a,b)
#define tcsnicmp_ascii(a,b,n)  strncmp(a,b,n)
#define stprintf_s   std::snprintf
#define stcatprintf_s(d,dn,f,a1) std::snprintf(d+tcslen(d),dn-tcslen(d),f,a1)
#define stcatprintf_s2(d,dn,f,a1,a2) std::snprintf(d+tcslen(d),dn-tcslen(d),f,a1,a2)
#define StringToInt(s,r) std::atoi(s)

#define TextPrintf fprintf
#define TextWrite fprintf
using textwriter = FILE;
#define StdErr stderr

#define SFLAG_RDONLY  MODE_READ
#define SFLAG_WRONLY  MODE_WRITE
#define SFLAG_CREATE  MODE_CREATE
#define StreamOpen(c,p,f)  new libebml::EbmlStream(*(new libebml::StdIOCallback(p, (libebml::open_mode)(f))))
static inline void StreamClose(libebml::EbmlStream *s)
{
    s->I_O().close();
    delete &(s->I_O());
    delete s;
}
static inline libebml::filepos_t Stream_Seek(libebml::IOCallback *s, std::uint64_t l, int w)
{
    (s)->setFilePointer(l,(libebml::seek_mode)w);
    return (s)->getFilePointer();
}
#define Stream_Write(s,b,l,p)  (s)->writeFully(b,l)

#define Node_FromStr(c,d,dn,s)  strcpy(d,s)
#define Node_FromUTF8(c,d,dn,s) strcpy(d,s)
#define Node_ToUTF8(c,d,dn,s)   strcpy(d,s)

#define MAXPATH 1024
#define MAXPATHFULL 1024
#define MAXLINE 2048
#define MAXDATA 2048

using bool_t = bool;

#define ARRAYBEGIN(v,t)  (v).begin()
#define ARRAYEND(v,t)    (v).end()
#define ARRAYCOUNT(v,t)  (v).size()
#define ARRAYAT(v,t,i)   (&((v).at(i)))
#define ArrayInit(v)     (v)->clear()
#define ArrayClear(v)    (v)->clear()
#define ArrayResize(v,s,t,a) (v)->resize(s)
#define ArrayRemove(v,t,i,c,o) // TODO
#define ArrayZero(v) // nothing, it's always used after resize
#define ArrayAppend(v,e,s,a)  (v)->push_back(e)
#define ArrayShrink(v,l)  (v)->resize((v)->size() - l); (v)->shrink_to_fit()

#define NodeDelete(o)    delete o

using ebml_element = libebml::EbmlElement;
using ebml_master = libebml::EbmlMaster;
using ebml_integer = libebml::EbmlUInteger;
using ebml_float = libebml::EbmlFloat;
using ebml_string = libebml::EbmlString;
using ebml_unistring = libebml::EbmlUnicodeString;
using ebml_date = libebml::EbmlDate;
using ebml_binary = libebml::EbmlBinary;
using nodetree = libebml::EbmlMaster;

using matroska_cluster = libmatroska::KaxCluster;

using EBML_MASTER_CLASS = libebml::EbmlMaster;
using EBML_STRING_CLASS = libebml::EbmlString;
using EBML_UNISTRING_CLASS = libebml::EbmlUnicodeString;
using EBML_DATE_CLASS = libebml::EbmlDate;
using EBML_SINTEGER_CLASS = libebml::EbmlSInteger;
using EBML_INTEGER_CLASS = libebml::EbmlUInteger;
using EBML_FLOAT_CLASS = libebml::EbmlFloat;
using EBML_BINARY_CLASS = libebml::EbmlBinary;
using EBML_VOID_CLASS = libebml::EbmlVoid;
using EBML_CRC_CLASS = libebml::EbmlCrc32;

#define Node_IsPartOf(n,c)  (dynamic_cast<const c*>(n) != nullptr)

using node = libebml::EbmlElement;
using fourcc_t = std::uint32_t;

using ebml_parser_context = libebml::EbmlSemanticContext;
using parsercontext = void *;
#define ParserContext_Init(a,b,c,d)
#define ParserContext_Done(c)
#define EBML_Init(x)
#define EBML_Done(x)
#define MATROSKA_Init(x)
#define MATROSKA_Done(x)

using stream = libebml::EbmlStream;

#define ERR_NONE          (!INVALID_FILEPOS_T)
#define ERR_INVALID_DATA  INVALID_FILEPOS_T
using err_t = libebml::filepos_t;

#define EBML_getContextHead()                libebml::EbmlHead
#define EBML_getContextReadVersion()         libebml::EReadVersion
#define EBML_getContextMaxIdLength()         libebml::EMaxIdLength
#define EBML_getContextMaxSizeLength()       libebml::EMaxSizeLength
#define EBML_getContextDocType()             libebml::EDocType
#define EBML_getContextDocTypeVersion()      libebml::EDocTypeVersion
#define EBML_getContextDocTypeReadVersion()  libebml::EDocTypeReadVersion
#define EBML_getContextEbmlVoid()            libebml::EbmlVoid

#define MATROSKA_getContextInfo()           libmatroska::KaxInfo
#define MATROSKA_getContextTimestampScale() libmatroska::KaxTimestampScale
#define MATROSKA_getContextSeek()           libmatroska::KaxSeek
#define MATROSKA_getContextSegment()        libmatroska::KaxSegment
#define MATROSKA_getContextSeekID()         libmatroska::KaxSeekID
#define MATROSKA_getContextSeekPosition()   libmatroska::KaxSeekPosition
#define MATROSKA_getContextBlock()          libmatroska::KaxBlock
#define MATROSKA_getContextSimpleBlock()    libmatroska::KaxSimpleBlock
#define MATROSKA_getContextBlockGroup()     libmatroska::KaxBlockGroup
#define MATROSKA_getContextTrackNumber()    libmatroska::KaxTrackNumber

#define EBML_CodedSizeLength  CodedSizeLength

#define EBML_ElementCreate(n,c,d,p,o)  new (c)()

#define EBML_ElementGetName(e,d,dn)   strcpy(d,EBML_NAME(e))
#define EBML_ElementClassID(e)        (*e).GetClassId().GetValue()
#define EBML_ElementPosition(e)       (e)->GetElementPosition()
#define EBML_ElementDataSize(e,u)     (e)->GetSize()
#define EBML_ElementFullSize(e,u)     (e)->ElementSize((u != 0) ? libebml::EbmlElement::WriteAll : libebml::EbmlElement::WriteSkipDefault)
#define EBML_ElementPositionEnd(e)    (e)->GetEndPosition()
#define EBML_ElementPositionData(e)   ((e)->GetEndPosition() - (e)->GetSize())
#define EBML_ElementIsType(e,t)       ((e)->GetClassId() == EBML_ID(t))
#define EBML_ElementGetClassName(e)   EBML_NAME(e)
#define EBML_ElementContext(e)        EBML_CONTEXT(e)
#define EBML_ElementIsDummy(e)        (e)->IsDummy()
#define EBML_ElementReadData(e,i,b,c,s,f) (e)->ReadData(*i,s), ERR_NONE
#define EBML_ElementSkipData(e,s,c,p,d)   (e)->SkipData(*(s),c,p,d)
#define EBML_FindNextElement(stream, sem, level, dummy) (stream)->FindNextElement(sem, *level, UINT64_MAX, dummy)
#define EBML_ElementSizeLength(e)      (e)->GetSizeLength()
#define EBML_ElementSetSizeLength(e,s) (e)->SetSizeLength(s)
#define EBML_ElementIsFiniteSize(e)       (e)->IsFiniteSize()
#define EBML_ElementSetInfiniteSize(e,i)  (e)->SetSizeInfinite(i)
#define EBML_ElementUpdateSize(e,d,f,p) (e)->UpdateSize(p,f)
#define EBML_ElementForceDataSize(e,s)  (e)->ForceSize(s)
#define EBML_ElementForcePosition(e,p)  (e)->ForcePosition(p)
#define EBML_ElementForceContext(e,c) // FIXME turn OldStereo to new Stereo
static inline err_t EBML_ElementRenderHead(libebml::EbmlMaster *e, libebml::IOCallback *o, bool_t bKeepPosition, libebml::filepos_t *Rendered, const libebml::EbmlElement::ShouldWrite &p)
{
    return (e)->WriteHead(*o, 0, p);
}

static inline std::vector<libebml::EbmlElement *>::iterator EBML_MasterChildren(ebml_master * m)
{
    return m->begin();
}
static inline std::vector<libebml::EbmlElement *>::const_iterator EBML_MasterChildren(const ebml_master * m)
{
    return m->begin();
}
static inline std::vector<libebml::EbmlElement *>::iterator EBML_MasterChildren(matroska_cluster * c)
{
    return reinterpret_cast<libmatroska::KaxCluster &>(c).begin();
}

static inline bool EBML_MasterEnd(std::vector<libebml::EbmlElement *>::iterator i, ebml_master * m)
{
    return i != (m)->end();
}
static inline bool EBML_MasterEnd(std::vector<libebml::EbmlElement *>::const_iterator i, const ebml_master * m)
{
    return i != (m)->end();
}
static inline bool EBML_MasterEnd(std::vector<libebml::EbmlElement *>::iterator i, matroska_cluster * c)
{
    return i != reinterpret_cast<libmatroska::KaxCluster &>(c).end();
}
static inline bool EBML_MasterEnd(std::vector<libebml::EbmlElement *>::const_iterator i, const matroska_cluster * c)
{
    return i != reinterpret_cast<const libmatroska::KaxCluster &>(c).end();
}

#define EBML_MasterNext(i)      (i)++
#define EBML_MasterEmpty(m)     ((static_cast<const EbmlMaster *>(m))->begin() == (static_cast<const EbmlMaster *>(m))->end())
#define EBML_MasterRemove(m,e)  (m)->Remove(e)
#define EBML_MasterAppend(m,e)  (m)->PushElement(*(e))

#define EBML_MasterFindChild(m,c)     FindChild<c>(*(libebml::EbmlMaster *)(m))
#define EBML_MasterGetChild(m,c,u)    &GetChild<c>(*(libebml::EbmlMaster *)(m))
#define EBML_MasterNextChild(m,p)     FindNextChild(*(libebml::EbmlMaster *)(m), *p)
#define EBML_MasterIsChecksumValid(m) (m)->VerifyChecksum()
#define EBML_MasterFindFirstElt(m,c,n,d,p)  &GetChild<c>(*(libebml::EbmlMaster *)(m))
#define EBML_MasterAddElt(m,c,d,p)    (m)->AddNewElt(EBML_INFO(c))

#define NodeTree_Clear(m)             (m)->RemoveAll()
#define NodeTree_SetParent(e,p,u)     (static_cast<libebml::EbmlMaster *>(p))->PushElement(*(e))

#define EBML_IntegerValue(e)          (reinterpret_cast<const libebml::EbmlUInteger*>(e))->GetValue()
#define EBML_IntegerSetValue(e,v)     (reinterpret_cast<libebml::EbmlUInteger*>(e))->SetValue(v)

#define EBML_StringGet(e,d,dn)         strcpy(d,(e)->GetValue().c_str())
#define EBML_StringGetUnicode(e,d,dn)  strcpy(d,(e)->GetValueUTF8().c_str())
static inline err_t EBML_StringSetValue(libebml::EbmlString *e, const char *v)
{
    (e)->SetValue(v);
    return ERR_NONE;
}
static inline err_t EBML_UniStringSetValue(libebml::EbmlUnicodeString *e, const char *v)
{
    (e)->SetValueUTF8(v);
    return ERR_NONE;
}

#define EBML_FloatValue(e)             (reinterpret_cast<libebml::EbmlFloat*>(e))->GetValue()
#define EBML_FloatSetValue(e,v)        (e)->SetValue(v)

#define EBML_BinaryGetData(e)          (e)->GetBuffer()



//////  ebml_date  ///////

#include <ctime>

using datetime_t = time_t;
struct datepack_t
{
    intptr_t Year; // 2001, 2007, etc
    intptr_t Month; // 1-12
    intptr_t Day; // 1-31
    intptr_t Hour; // 24-hour
    intptr_t Minute; // 0-59
    intptr_t Second; // 0-59
    intptr_t WeekDay; // 1 = Sunday, 2 = Monday, etc
};

static inline datetime_t GetTimeDate()
{
    return time(NULL);
}

static inline void EBML_DateSetDateTime(libebml::EbmlDate *e, datetime_t d)
{
    e->SetEpochDate(d);
}

#define EBML_DateTime(d)               ((d)->GetValue() / UINT64_C(1'000'000'000))

#define INVALID_DATETIME_T  0
#define DATETIME_OFFSET     0x3A4FC880

static inline bool_t GetDatePacked(datetime_t t, datepack_t *tp, bool_t Local)
{
	time_t ot;
	struct tm *date;

	if (!tp || t == INVALID_DATETIME_T)
        return 0;

	ot = t + DATETIME_OFFSET;
    if (Local)
        date = localtime(&ot);
    else
	    date = gmtime(&ot);

	if (date)
    {
		tp->Second = date->tm_sec;
		tp->Minute = date->tm_min;
		tp->Hour = date->tm_hour;
		tp->Day = date->tm_mday;
		tp->Month = date->tm_mon + 1;
		tp->Year = date->tm_year + 1900;
		tp->WeekDay = date->tm_wday + 1;
		return 1;
	}

	return 0;
}
