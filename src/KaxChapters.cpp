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

DEFINE_START_SEMANTIC(KaxChapters)
DEFINE_SEMANTIC_ITEM(true, false, KaxEditionEntry)
DEFINE_END_SEMANTIC(KaxChapters)

DEFINE_START_SEMANTIC(KaxEditionEntry)
DEFINE_SEMANTIC_ITEM(false, true, KaxEditionUID)
DEFINE_SEMANTIC_ITEM(true, true, KaxEditionFlagHidden)
DEFINE_SEMANTIC_ITEM(true, true, KaxEditionFlagDefault)
DEFINE_SEMANTIC_ITEM(false, true, KaxEditionFlagOrdered)
DEFINE_SEMANTIC_ITEM(true, false, KaxChapterAtom)
DEFINE_END_SEMANTIC(KaxEditionEntry)

DEFINE_START_SEMANTIC(KaxChapterAtom)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapterAtom)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterUID)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterTimeStart)
DEFINE_SEMANTIC_ITEM(false, true, KaxChapterTimeEnd)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterFlagHidden)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterFlagEnabled)
DEFINE_SEMANTIC_ITEM(false, true, KaxChapterSegmentUID)
DEFINE_SEMANTIC_ITEM(false, true, KaxChapterSegmentEditionUID)
DEFINE_SEMANTIC_ITEM(false, true, KaxChapterPhysicalEquiv)
DEFINE_SEMANTIC_ITEM(false, true, KaxChapterTrack)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapterDisplay)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapterProcess)
DEFINE_END_SEMANTIC(KaxChapterAtom)

DEFINE_START_SEMANTIC(KaxChapterTrack)
DEFINE_SEMANTIC_ITEM(true, false, KaxChapterTrackNumber)
DEFINE_END_SEMANTIC(KaxChapterTrack)

DEFINE_START_SEMANTIC(KaxChapterDisplay)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterString)
DEFINE_SEMANTIC_ITEM(true, false, KaxChapterLanguage)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapterCountry)
DEFINE_END_SEMANTIC(KaxChapterDisplay)

DEFINE_START_SEMANTIC(KaxChapterProcess)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterProcessCodecID)
DEFINE_SEMANTIC_ITEM(false, true, KaxChapterProcessPrivate)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapterProcessCommand)
DEFINE_END_SEMANTIC(KaxChapterProcess)

DEFINE_START_SEMANTIC(KaxChapterProcessCommand)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterProcessTime)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterProcessData)
DEFINE_END_SEMANTIC(KaxChapterProcessCommand)

DEFINE_MKX_MASTER      (KaxChapters,             0x1043A770, 4, KaxSegment, "Chapters");
DEFINE_MKX_MASTER      (KaxEditionEntry,             0x45B9, 2, KaxChapters, "EditionEntry");
DEFINE_MKX_UINTEGER    (KaxEditionUID,               0x45BC, 2, KaxEditionEntry, "EditionUID");
DEFINE_MKX_UINTEGER_DEF(KaxEditionFlagHidden,        0x45BD, 2, KaxEditionEntry, "EditionFlagHidden", 0);
DEFINE_MKX_UINTEGER_DEF(KaxEditionFlagDefault,       0x45DB, 2, KaxEditionEntry, "EditionFlagDefault", 0);
DEFINE_MKX_UINTEGER_DEF(KaxEditionFlagOrdered,       0x45DD, 2, KaxEditionEntry, "EditionFlagOrdered", 0);
DEFINE_MKX_MASTER      (KaxChapterAtom,                0xB6, 1, KaxEditionEntry, "ChapterAtom");
DEFINE_MKX_UINTEGER    (KaxChapterUID,               0x73C4, 2, KaxChapterAtom, "ChapterUID");
DEFINE_MKX_UINTEGER    (KaxChapterTimeStart,           0x91, 1, KaxChapterAtom, "ChapterTimeStart");
DEFINE_MKX_UINTEGER    (KaxChapterTimeEnd,             0x92, 1, KaxChapterAtom, "ChapterTimeEnd");
DEFINE_MKX_UINTEGER_DEF(KaxChapterFlagHidden,          0x98, 1, KaxChapterAtom, "ChapterFlagHidden", 0);
DEFINE_MKX_UINTEGER_DEF(KaxChapterFlagEnabled,       0x4598, 2, KaxChapterAtom, "ChapterFlagEnabled", 1);
DEFINE_MKX_BINARY      (KaxChapterSegmentUID,        0x6E67, 2, KaxChapterAtom, "ChapterSegmentUID");
DEFINE_MKX_BINARY      (KaxChapterSegmentEditionUID, 0x6EBC, 2, KaxChapterAtom, "ChapterSegmentEditionUID");
DEFINE_MKX_UINTEGER    (KaxChapterPhysicalEquiv,     0x63C3, 2, KaxChapterAtom, "ChapterPhysicalEquiv");
DEFINE_MKX_MASTER      (KaxChapterTrack,               0x8F, 1, KaxChapterAtom, "ChapterTrack");
DEFINE_MKX_UINTEGER    (KaxChapterTrackNumber,         0x89, 1, KaxChapterTrack, "ChapterTrackNumber");
DEFINE_MKX_MASTER      (KaxChapterDisplay,             0x80, 1, KaxChapterAtom, "ChapterDisplay");
DEFINE_MKX_UNISTRING   (KaxChapterString,              0x85, 1, KaxChapterDisplay, "ChapterString");
DEFINE_MKX_STRING_DEF  (KaxChapterLanguage,          0x437C, 2, KaxChapterDisplay, "ChapterLanguage", "eng"); // parent context ?
DEFINE_MKX_STRING      (KaxChapterCountry,           0x437E, 2, KaxChapterDisplay, "ChapterCountry"); // parent context ?
DEFINE_MKX_MASTER      (KaxChapterProcess,           0x6944, 2, KaxChapterAtom, "ChapterProcess");
DEFINE_MKX_UINTEGER_DEF(KaxChapterProcessCodecID,    0x6955, 2, KaxChapterProcess, "ChapterProcessCodecID", 0);
DEFINE_MKX_BINARY      (KaxChapterProcessPrivate,    0x450D, 2, KaxChapterProcess, "ChapterProcessPrivate");
DEFINE_MKX_MASTER      (KaxChapterProcessCommand,    0x6911, 2, KaxChapterProcess, "ChapterProcessCommand");
DEFINE_MKX_UINTEGER    (KaxChapterProcessTime,       0x6922, 2, KaxChapterProcessCommand, "ChapterProcessTime");
DEFINE_MKX_BINARY      (KaxChapterProcessData,       0x6933, 2, KaxChapterProcessCommand, "ChapterProcessData");

END_LIBMATROSKA_NAMESPACE
