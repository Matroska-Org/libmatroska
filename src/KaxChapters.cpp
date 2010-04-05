/****************************************************************************
** libmatroska : parse Matroska files, see http://www.matroska.org/
**
** <file/class description>
**
** Copyright (C) 2002-2010 Steve Lhomme.  All rights reserved.
**
** This file is part of libmatroska.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License as published by the Free Software Foundation; either
** version 2.1 of the License, or (at your option) any later version.
** 
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** Lesser General Public License for more details.
** 
** You should have received a copy of the GNU Lesser General Public
** License along with this library; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
**
** See http://www.matroska.org/license/lgpl/ for LGPL licensing information.**
** Contact license@matroska.org if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

/*!
	\file
	\version \$Id: KaxChapters.cpp 1201 2005-08-30 14:28:27Z robux4 $
	\author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include "matroska/KaxChapters.h"
#include "matroska/KaxContexts.h"
#include "matroska/KaxDefines.h"

// sub elements
START_LIBMATROSKA_NAMESPACE

static const EbmlSemantic ContextList_KaxChapters[1] =
{
    EbmlSemantic(true, false,  EBML_INFO(KaxEditionEntry)),
};

static const EbmlSemantic ContextList_KaxEditionEntry[5] =
{
    EbmlSemantic(false, true , EBML_INFO(KaxEditionUID)),
    EbmlSemantic(true , true , EBML_INFO(KaxEditionFlagHidden)),
    EbmlSemantic(true , true , EBML_INFO(KaxEditionFlagDefault)),
    EbmlSemantic(false, true , EBML_INFO(KaxEditionFlagOrdered)),
    EbmlSemantic(true , false, EBML_INFO(KaxChapterAtom)),
};

static const EbmlSemantic ContextList_KaxChapterAtom[12] =
{
    EbmlSemantic(false, false, EBML_INFO(KaxChapterAtom)),
    EbmlSemantic(true,  true,  EBML_INFO(KaxChapterUID)),
    EbmlSemantic(true,  true,  EBML_INFO(KaxChapterTimeStart)),
    EbmlSemantic(false, true,  EBML_INFO(KaxChapterTimeEnd)),
    EbmlSemantic(true , true,  EBML_INFO(KaxChapterFlagHidden)),
    EbmlSemantic(true , true,  EBML_INFO(KaxChapterFlagEnabled)),
    EbmlSemantic(false, true,  EBML_INFO(KaxChapterSegmentUID)),
    EbmlSemantic(false, true,  EBML_INFO(KaxChapterSegmentEditionUID)),
    EbmlSemantic(false, true,  EBML_INFO(KaxChapterPhysicalEquiv)),
    EbmlSemantic(false, true,  EBML_INFO(KaxChapterTrack)),
    EbmlSemantic(false, false, EBML_INFO(KaxChapterDisplay)),
    EbmlSemantic(false, false, EBML_INFO(KaxChapterProcess)),
};

static const EbmlSemantic ContextList_KaxChapterTrack[1] =
{
    EbmlSemantic(true, false, EBML_INFO(KaxChapterTrackNumber)),
};

static const EbmlSemantic ContextList_KaxChapterDisplay[3] =
{
    EbmlSemantic(true,  true,  EBML_INFO(KaxChapterString)),
    EbmlSemantic(true,  false, EBML_INFO(KaxChapterLanguage)),
    EbmlSemantic(false, false, EBML_INFO(KaxChapterCountry)),
};

static const EbmlSemantic ContextList_KaxChapterProcess[3] =
{
    EbmlSemantic(true,  true,  EBML_INFO(KaxChapterProcessCodecID)),
    EbmlSemantic(false, true,  EBML_INFO(KaxChapterProcessPrivate)),
    EbmlSemantic(false, false, EBML_INFO(KaxChapterProcessCommand)),
};

static const EbmlSemantic ContextList_KaxChapterProcessCommand[2] =
{
    EbmlSemantic(true,  true,  EBML_INFO(KaxChapterProcessTime)),
    EbmlSemantic(true,  true,  EBML_INFO(KaxChapterProcessData)),
};

DEFINE_MKX_MASTER   (KaxChapters,             0x1043A770, 4, KaxSegment, "Chapters");
DEFINE_MKX_MASTER   (KaxEditionEntry,             0x45B9, 2, KaxChapters, "EditionEntry");
DEFINE_MKX_UINTEGER (KaxEditionUID,               0x45BC, 2, KaxEditionEntry, "EditionUID");
DEFINE_MKX_UINTEGER (KaxEditionFlagHidden,        0x45BD, 2, KaxEditionEntry, "EditionFlagHidden");
DEFINE_MKX_UINTEGER (KaxEditionFlagDefault,       0x45DB, 2, KaxEditionEntry, "EditionFlagDefault");
DEFINE_MKX_UINTEGER (KaxEditionFlagOrdered,       0x45DD, 2, KaxEditionEntry, "EditionFlagOrdered");
DEFINE_MKX_MASTER   (KaxChapterAtom,                0xB6, 1, KaxEditionEntry, "ChapterAtom");
DEFINE_MKX_UINTEGER (KaxChapterUID,               0x73C4, 2, KaxChapterAtom, "ChapterUID");
DEFINE_MKX_UINTEGER (KaxChapterTimeStart,           0x91, 1, KaxChapterAtom, "ChapterTimeStart");
DEFINE_MKX_UINTEGER (KaxChapterTimeEnd,             0x92, 1, KaxChapterAtom, "ChapterTimeEnd");
DEFINE_MKX_UINTEGER (KaxChapterFlagHidden,          0x98, 1, KaxChapterAtom, "ChapterFlagHidden");
DEFINE_MKX_UINTEGER (KaxChapterFlagEnabled,       0x4598, 2, KaxChapterAtom, "ChapterFlagEnabled");
DEFINE_MKX_BINARY   (KaxChapterSegmentUID,        0x6E67, 2, KaxChapterAtom, "ChapterSegmentUID");
DEFINE_MKX_BINARY   (KaxChapterSegmentEditionUID, 0x6EBC, 2, KaxChapterAtom, "ChapterSegmentEditionUID");
DEFINE_MKX_UINTEGER (KaxChapterPhysicalEquiv,     0x63C3, 2, KaxChapterAtom, "ChapterPhysicalEquiv");
DEFINE_MKX_MASTER   (KaxChapterTrack,               0x8F, 1, KaxChapterAtom, "ChapterTrack");
DEFINE_MKX_UINTEGER (KaxChapterTrackNumber,         0x89, 1, KaxChapterTrack, "ChapterTrackNumber");
DEFINE_MKX_MASTER   (KaxChapterDisplay,             0x80, 1, KaxChapterAtom, "ChapterDisplay");
DEFINE_MKX_UNISTRING(KaxChapterString,              0x85, 1, KaxChapterDisplay, "ChapterString");
DEFINE_MKX_STRING   (KaxChapterLanguage,          0x437C, 2, KaxChapterLanguage, "ChapterLanguage"); // parent context ?
DEFINE_MKX_STRING   (KaxChapterCountry,           0x437E, 2, KaxChapterCountry, "ChapterCountry"); // parent context ?
DEFINE_MKX_MASTER   (KaxChapterProcess,           0x6944, 2, KaxChapterAtom, "ChapterProcess");
DEFINE_MKX_UINTEGER (KaxChapterProcessCodecID,    0x6955, 2, KaxChapterProcess, "ChapterProcessCodecID");
DEFINE_MKX_BINARY   (KaxChapterProcessPrivate,    0x450D, 2, KaxChapterProcess, "ChapterProcessPrivate");
DEFINE_MKX_MASTER   (KaxChapterProcessCommand,    0x6911, 2, KaxChapterProcess, "ChapterProcessCommand");
DEFINE_MKX_UINTEGER (KaxChapterProcessTime,       0x6922, 2, KaxChapterProcessCommand, "ChapterProcessTime");
DEFINE_MKX_BINARY   (KaxChapterProcessData,       0x6933, 2, KaxChapterProcessCommand, "ChapterProcessData");


KaxChapters::KaxChapters()
 :EbmlMaster(Context_KaxChapters)
{}

KaxEditionEntry::KaxEditionEntry()
:EbmlMaster(Context_KaxEditionEntry)
{}

KaxChapterAtom::KaxChapterAtom()
:EbmlMaster(Context_KaxChapterAtom)
{}

KaxChapterTrack::KaxChapterTrack()
:EbmlMaster(Context_KaxChapterTrack)
{}

KaxChapterDisplay::KaxChapterDisplay()
:EbmlMaster(Context_KaxChapterDisplay)
{}

KaxChapterProcess::KaxChapterProcess()
:EbmlMaster(Context_KaxChapterProcess)
{}

KaxChapterProcessCommand::KaxChapterProcessCommand()
:EbmlMaster(Context_KaxChapterProcessCommand)
{}

END_LIBMATROSKA_NAMESPACE
