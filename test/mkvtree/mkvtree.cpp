// Copyright © 2008-2024 Matroska (non-profit organisation).
// SPDX-License-Identifier: BSD-3-Clause

#include <ebml/EbmlMaster.h>
#include <ebml/EbmlUInteger.h>
#include <ebml/EbmlSInteger.h>
#include <ebml/EbmlUnicodeString.h>
#include <ebml/EbmlString.h>
#include <ebml/EbmlUnicodeString.h>
#include <ebml/EbmlFloat.h>
#include <ebml/EbmlDate.h>
#include <ebml/EbmlVoid.h>
#include <ebml/EbmlCrc32.h>
#include <ebml/EbmlStream.h>
#include <ebml/EbmlHead.h>
#include <ebml/EbmlDummy.h>
#include <ebml/StdIOCallback.h>

#include <matroska/KaxSegment.h>

#include <cinttypes>
#include <cstdio>
#include <ctime>

using namespace libebml;

static int ShowPos = 0;

#if 0 // TODO allowing find top level elements using an EbmlSemanticContextMaster
DEFINE_START_SEMANTIC(KaxStream)
DEFINE_SEMANTIC_ITEM(true, true, libebml::EbmlHead)
DEFINE_SEMANTIC_ITEM(true, true, libmatroska::KaxSegment)
DEFINE_END_SEMANTIC(KaxStream)

DEFINE_xxx_CONTEXT(KaxStream,libmatroska::GetKaxGlobal_Context)
#endif

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


static void EndLine(EbmlElement *Element)
{
    if (ShowPos && (Element)->GetElementPosition()!=INVALID_FILEPOS_T)
        fprintf(stdout," at %" PRId64 "\r\n",(Element)->GetElementPosition());
    else
        fprintf(stdout,"\r\n");
}

static EbmlElement *OutputElement(EbmlElement *Element, const EbmlSemanticContext *Context, EbmlStream *Input, unsigned int *Level)
{
    assert(*Level < 10); // safety check
    unsigned int LevelPrint;
    for (LevelPrint=0;LevelPrint<*Level;++LevelPrint)
        fprintf(stdout,"+ ");
    fprintf(stdout,"%s: ", EBML_NAME(Element));
    if (dynamic_cast<const EbmlMaster*>(Element) != nullptr)
    {
        int UpperElement = 0;
        EbmlElement *SubElement,*NewElement;
        // EbmlSemanticContext SubContext;

        if (Element->GetSize() == INVALID_FILEPOS_T)
            fprintf(stdout,"(master)");
        else if (!(Element)->IsFiniteSize())
            fprintf(stdout,"(master) [unknown size]");
        else
            fprintf(stdout,"(master) [%" PRId64 " bytes]",Element->GetSize());
        EndLine(Element);
        // SubContext.UpContext = Context;
        // SubContext.Context = EBML_CONTEXT(Element);
        // SubContext.EndPosition = Element->GetEndPosition();
        // SubContext.Profile = Context->Profile;
        // SubElement = EBML_FindNextElement(Input, &SubContext, &UpperElement, 1);
        SubElement = Input->FindNextElement(EBML_CONTEXT(Element), UpperElement, UINT64_MAX, true);
		while (SubElement != NULL && UpperElement<=0 && (!(Element)->IsFiniteSize() || (SubElement)->GetElementPosition() <= Element->GetEndPosition()))
        {
            // a sub element == not higher level and contained inside the current element
            (*Level)++;
            NewElement = OutputElement(SubElement, &EBML_CONTEXT(Element), Input, Level);
            delete SubElement;
            if (NewElement)
                SubElement = NewElement;
            else
            {
                if ((Element)->IsFiniteSize() && Input->I_O().getFilePointer() >= Element->GetEndPosition())
                {
                    SubElement = nullptr;
                    // break;
                }
                else
                    SubElement = Input->FindNextElement(EBML_CONTEXT(Element), UpperElement, UINT64_MAX, true);
            }
            assert(*Level > 0);
            (*Level)--;

			if (UpperElement < 0)
            {
                // global element
                // assert(*Level + UpperElement >= 0);
				// *Level += UpperElement;
            }
			else if (UpperElement != 0 && *Level>0)
            {
                assert((int)*Level >= UpperElement-1);
				*Level -= UpperElement-1;
            }
        }
        return SubElement;
        //EBML_ElementSkipData(Element, Input, Element->Context, NULL, 0);
    }
    else if (dynamic_cast<const EbmlVoid*>(Element) != nullptr)
    {
        fprintf(stdout,"[%" PRId64 " bytes]",Element->GetSize());
        Element->SkipData(*Input, *Context, nullptr, 0);
        EndLine(Element);
	}
    else if (dynamic_cast<const EbmlCrc32*>(Element) != nullptr)
    {
        // TODO: handle crc32
        fprintf(stdout,"[%" PRId64 " bytes]",Element->GetSize());
        Element->SkipData(*Input, *Context, nullptr, 0);
        EndLine(Element);
	}
    else if (dynamic_cast<const EbmlString*>(Element) != nullptr || dynamic_cast<const EbmlUnicodeString*>(Element) != nullptr)
    {
        //tchar_t UnicodeString[MAXDATA];
        if (Element->ReadData(Input->I_O(),SCOPE_ALL_DATA) != INVALID_FILEPOS_T)
        {
            if (dynamic_cast<const EbmlString*>(Element) != nullptr)
                fprintf(stdout,"'%s'",static_cast<const EbmlString *>(Element)->GetValue().c_str());
            else
                fprintf(stdout,"'%s'",static_cast<const EbmlUnicodeString *>(Element)->GetValueUTF8().c_str());
        } else
            fprintf(stdout,"<error reading>");
        EndLine(Element);
    }
    else if (dynamic_cast<const EbmlDate*>(Element) != nullptr)
    {
        if (Element->ReadData(Input->I_O(),SCOPE_ALL_DATA) != INVALID_FILEPOS_T)
        {
            auto DateTime = static_cast<const EbmlDate *>(Element)->GetEpochDate();
            datepack_t Date;
            time_t ot;
            struct tm *date;

            ot = DateTime;
            date = localtime(&ot);

            if (date)
            {
                Date.Second = date->tm_sec;
                Date.Minute = date->tm_min;
                Date.Hour = date->tm_hour;
                Date.Day = date->tm_mday;
                Date.Month = date->tm_mon + 1;
                Date.Year = date->tm_year + 1900;
                Date.WeekDay = date->tm_wday + 1;
            }

            fprintf(stdout,"%04" PRIdPTR "-%02" PRIdPTR "-%02" PRIdPTR " %02" PRIdPTR ":%02" PRIdPTR ":%02" PRIdPTR " UTC",Date.Year,Date.Month,Date.Day,Date.Hour,Date.Minute,Date.Second);
        }
        else
            fprintf(stdout,"<error reading>");
        EndLine(Element);
    }
    else if (dynamic_cast<const EbmlUInteger*>(Element) != nullptr || dynamic_cast<const EbmlSInteger*>(Element) != nullptr)
    {
        if (Element->ReadData(Input->I_O(),SCOPE_ALL_DATA) != INVALID_FILEPOS_T)
        {
            if (dynamic_cast<const EbmlSInteger*>(Element) != nullptr)
                fprintf(stdout,"%" PRId64,static_cast<const EbmlSInteger *>(Element)->GetValue());
            else
                fprintf(stdout,"%" PRIu64,static_cast<const EbmlUInteger *>(Element)->GetValue());
        }
        else
            fprintf(stdout,"<error reading>");
        EndLine(Element);
    }
    else if (dynamic_cast<const EbmlFloat*>(Element) != nullptr)
    {
        if (Element->ReadData(Input->I_O(),SCOPE_ALL_DATA) != INVALID_FILEPOS_T)
            fprintf(stdout,"%f",static_cast<const EbmlFloat *>(Element)->GetValue());
        else
            fprintf(stdout,"<error reading>");
        EndLine(Element);
    }
    else if (Element->IsDummy())
    {
        fprintf(stdout,"[%X] [%" PRId64 " bytes]",static_cast<const EbmlDummy *>(Element)->GetClassId().GetValue(),Element->GetSize());
        Element->SkipData(*Input, *Context, nullptr, 0);
        EndLine(Element);
    }
    else if (dynamic_cast<const EbmlBinary*>(Element) != nullptr)
    {
        if (Element->ReadData(Input->I_O(),SCOPE_PARTIAL_DATA) != INVALID_FILEPOS_T)
        {
            const uint8_t *Data = static_cast<const EbmlBinary *>(Element)->GetBuffer();
            if (Element->GetSize() != 0)
            {
                if (Data==NULL)
                    fprintf(stdout,"[data too large] (%" PRId64 ")",Element->GetSize());
                else if (Element->GetSize() == 1)
                    fprintf(stdout,"%02X (%" PRId64 ")",Data[0],Element->GetSize());
                else if (Element->GetSize() == 2)
                    fprintf(stdout,"%02X %02X (%" PRId64 ")",Data[0],Data[1],Element->GetSize());
                else if (Element->GetSize() == 3)
                    fprintf(stdout,"%02X %02X %02X (%" PRId64 ")",Data[0],Data[1],Data[2],Element->GetSize());
                else if (Element->GetSize() == 4)
                    fprintf(stdout,"%02X %02X %02X %02X (%" PRId64 ")",Data[0],Data[1],Data[2],Data[3],Element->GetSize());
                else
                    fprintf(stdout,"%02X %02X %02X %02X.. (%" PRId64 ")",Data[0],Data[1],Data[2],Data[3],Element->GetSize());
            }
        }
        else
            fprintf(stdout,"<error reading>");
		Element->SkipData(*Input, *Context, nullptr, 0);
        EndLine(Element);
    }
    else
    {
#ifdef IS_BIG_ENDIAN
        fprintf(stdout,"<unsupported element %x>\r\n",EBML_ElementClassID(Element));
#else
        auto Id = Element->GetClassId().GetValue();
        fprintf(stdout,"<unsupported element ");
        while (Id & 0xFF)
        {
            fprintf(stdout,"[%x]",Id & 0xFF);
            Id >>= 8;
        }
        fprintf(stdout,"%X>",Element->GetClassId().GetValue());
#endif
        Element->SkipData(*Input, *Context, nullptr, 0);
        EndLine(Element);
    }
    return NULL;
}

static void OutputEbmlhead(EbmlStream *Input)
{
    EbmlElement *Element = Input->FindNextID<libebml::EbmlHead>(UINT64_MAX);
    if (Element)
    {
		unsigned int Level = 0;
        OutputElement(Element, NULL, Input, &Level);
        delete Element;
    }
}

static void OutputTree(EbmlStream *Input)
{
    EbmlElement *Element = Input->FindNextID<libmatroska::KaxSegment>(UINT64_MAX);
    if (Element)
    {
		unsigned int Level = 0;
        OutputElement(Element, NULL, Input, &Level);
        delete Element;
    }
}

int main(int argc, const char *argv[])
{
    EbmlStream *Input;

    if ((argc!=2 && argc!=3) || (argc==3 && strcmp(argv[1],"--pos")))
    {
        fprintf(stderr, "Usage: mkvtree --pos [matroska_file]\r\n");
		fprintf(stderr, "Options:\r\n");
		fprintf(stderr, "  --pos     output the position of elements\r\n");
        return 1;
    }

    if (argc==3)
        ShowPos = 1;

    // open the file to parse
    Input = new EbmlStream(*(new StdIOCallback(argv[argc-1], MODE_READ)));
    if (Input == NULL)
        fprintf(stderr, "error: mkvtree cannot open file \"%s\"\r\n",argv[1]);
    else
    {
        OutputEbmlhead(Input);
        OutputTree(Input);

        Input->I_O().close();
        delete &(Input->I_O());
        delete Input;
    }

    return 0;
}
