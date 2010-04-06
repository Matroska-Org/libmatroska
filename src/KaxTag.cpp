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
	\version \$Id: KaxTag.cpp 1325 2009-03-30 07:56:54Z robux4 $
	\author Jory Stone       <jcsston @ toughguy.net>
	\author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include "matroska/KaxTag.h"
#include "matroska/KaxTagMulti.h"
#include "matroska/KaxContexts.h"
#include "matroska/KaxDefines.h"

using namespace LIBEBML_NAMESPACE;

// sub elements
START_LIBMATROSKA_NAMESPACE

static const EbmlSemantic ContextList_KaxTag[14] =
{	
	EbmlSemantic(true,  true,  EBML_INFO(KaxTagTargets)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagGeneral)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagGenres)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagAudioSpecific)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagImageSpecific)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagMultiCommercial)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagMultiDate)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagMultiEntity)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagMultiIdentifier)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagMultiLegal)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagMultiTitle)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagMultiAttachment)),
//	EbmlSemantic(false, false, EBML_INFO(KaxTagLength)),
//	EbmlSemantic(false, false, EBML_INFO(KaxTagPlaylistDelay)),
//	EbmlSemantic(false, false, EBML_INFO(KaxTagUnsynchronisedText)),
//	EbmlSemantic(false, false, EBML_INFO(KaxTagUserDefinedURL)),
	EbmlSemantic(false, false, EBML_INFO(KaxTagMultiComment)),
	EbmlSemantic(true,  false, EBML_INFO(KaxTagSimple)),
};

static const EbmlSemantic ContextList_KaxTagTargets[6] =
{	
	EbmlSemantic(false, true,  EBML_INFO(KaxTagTargetTypeValue)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagTargetType)),
	EbmlSemantic(false, false, EBML_INFO(KaxTagTrackUID)),
	EbmlSemantic(false, false, EBML_INFO(KaxTagEditionUID)),
	EbmlSemantic(false, false, EBML_INFO(KaxTagChapterUID)),
	EbmlSemantic(false, false, EBML_INFO(KaxTagAttachmentUID)),
};

static const EbmlSemantic ContextList_KaxTagGeneral[17] =
{	
	EbmlSemantic(false, true,  EBML_INFO(KaxTagArchivalLocation)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagFile)),
	EbmlSemantic(false, false, EBML_INFO(KaxTagKeywords)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagMood)),
	EbmlSemantic(false, false, EBML_INFO(KaxTagRecordLocation)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagSource)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagSourceForm)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagProduct)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagOriginalMediaType)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagPlayCounter)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagPopularimeter)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagSubject)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagBibliography)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagLanguage)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagRating)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagEncoder)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagEncodeSettings)),
};

static const EbmlSemantic ContextList_KaxTagGenres[3] =
{	
	EbmlSemantic(false, false, EBML_INFO(KaxTagAudioGenre)),
	EbmlSemantic(false, false, EBML_INFO(KaxTagVideoGenre)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagSubGenre)),
};

static const EbmlSemantic ContextList_KaxTagAudioSpecific[10] =
{	
	EbmlSemantic(false, true, EBML_INFO(KaxTagAudioPeak)),
	EbmlSemantic(false, true, EBML_INFO(KaxTagAudioEncryption)),
	EbmlSemantic(false, true, EBML_INFO(KaxTagAudioGain)),
	EbmlSemantic(false, true, EBML_INFO(KaxTagBPM)),
	EbmlSemantic(false, true, EBML_INFO(KaxTagDiscTrack)),
	EbmlSemantic(false, true, EBML_INFO(KaxTagSetPart)),
	EbmlSemantic(false, true, EBML_INFO(KaxTagEqualisation)),
	EbmlSemantic(false, true, EBML_INFO(KaxTagInitialKey)),
	EbmlSemantic(false, true, EBML_INFO(KaxTagOfficialAudioFileURL)),
	EbmlSemantic(false, true, EBML_INFO(KaxTagOfficialAudioSourceURL)),
};

static const EbmlSemantic ContextList_KaxTagImageSpecific[6] =
{
	EbmlSemantic(false, true, EBML_INFO(KaxTagCaptureDPI)),
	EbmlSemantic(false, true, EBML_INFO(KaxTagCaptureLightness)),
	EbmlSemantic(false, true, EBML_INFO(KaxTagCapturePaletteSetting)),
	EbmlSemantic(false, true, EBML_INFO(KaxTagCaptureSharpness)),
	EbmlSemantic(false, true, EBML_INFO(KaxTagCropped)),
	EbmlSemantic(false, true, EBML_INFO(KaxTagOriginalDimensions)),
};

static const EbmlSemantic ContextList_KaxTagSimple[6] =
{	
	EbmlSemantic(true,  true,  EBML_INFO(KaxTagName)),
	EbmlSemantic(true,  true,  EBML_INFO(KaxTagLangue)),
	EbmlSemantic(true,  true,  EBML_INFO(KaxTagDefault)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagString)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagBinary)),
	EbmlSemantic(false, false, EBML_INFO(KaxTagSimple)),
};

DEFINE_MKX_MASTER      (KaxTag,                       0x7373, 2, KaxTags, "Tag");
DEFINE_MKX_MASTER      (KaxTagTargets,                0x63C0, 2, KaxTag, "TagTargets");
DEFINE_MKX_MASTER      (KaxTagGeneral,                0x67C9, 2, KaxTag, "TagGeneral");
DEFINE_MKX_MASTER      (KaxTagGenres,                 0x6583, 2, KaxTag, "TagGenres");
DEFINE_MKX_MASTER      (KaxTagAudioSpecific,          0x41C5, 2, KaxTag, "TagAudioSpecific");
DEFINE_MKX_MASTER      (KaxTagImageSpecific,          0x4990, 2, KaxTag, "TagImageSpecific");
DEFINE_MKX_UNISTRING   (KaxTagBibliography,           0x4488, 2, KaxTag, "Bibliography");
DEFINE_MKX_UNISTRING   (KaxTagEncoder,                0x4431, 2, KaxTag, "Encoder");
DEFINE_MKX_UNISTRING   (KaxTagEncodeSettings,         0x6526, 2, KaxTag, "EncodeSettings");
DEFINE_MKX_STRING      (KaxTagLanguage,             0x22B59F, 3, KaxTag, "Language");
DEFINE_MKX_UINTEGER    (KaxTagLength,                 0x5243, 2, KaxTag, "Length");
DEFINE_MKX_UINTEGER    (KaxTagPlaylistDelay,          0x72CC, 2, KaxTag, "PlaylistDelay");
DEFINE_MKX_BINARY      (KaxTagRating,                 0x52BC, 2, KaxTag, "Rating");
DEFINE_MKX_UNISTRING   (KaxTagSubject,                0x49C1, 2, KaxTag, "Subject");
DEFINE_MKX_UNISTRING   (KaxTagUnsynchronisedText,     0x874B, 2, KaxTag, "UnsynchronisedText");
DEFINE_MKX_STRING      (KaxTagUserDefinedURL,         0x434A, 2, KaxTag, "UserDefinedURL");
DEFINE_MKX_UINTEGER_DEF(KaxTagTargetTypeValue,        0x68CA, 2, KaxTagTargets, "TagTargetTypeValue", 50);
DEFINE_MKX_STRING      (KaxTagTargetType,             0x63CA, 2, KaxTagTargets, "TagTargetType");
DEFINE_MKX_UINTEGER_DEF(KaxTagTrackUID,               0x63C5, 2, KaxTagTargets, "TagTrackUID", 0);
DEFINE_MKX_UINTEGER_DEF(KaxTagEditionUID,             0x63C9, 2, KaxTagTargets, "TagEditionUID", 0);
DEFINE_MKX_UINTEGER_DEF(KaxTagChapterUID,             0x63C4, 2, KaxTagTargets, "TagChapterUID", 0);
DEFINE_MKX_UINTEGER_DEF(KaxTagAttachmentUID,          0x63C6, 2, KaxTagTargets, "TagAttachmentUID", 0);
DEFINE_MKX_UNISTRING   (KaxTagArchivalLocation,       0x45A4, 2, KaxTagGeneral, "ArchivalLocation");
DEFINE_MKX_UNISTRING   (KaxTagFile,                   0x454E, 2, KaxTagGeneral, "File");
DEFINE_MKX_UNISTRING   (KaxTagKeywords,               0x458C, 2, KaxTagGeneral, "Keywords");
DEFINE_MKX_UNISTRING   (KaxTagMood,                   0x45AE, 2, KaxTagGeneral, "Mood");
DEFINE_MKX_STRING      (KaxTagRecordLocation,         0x457E, 2, KaxTagGeneral, "RecordLocation");
DEFINE_MKX_UNISTRING   (KaxTagSource,                 0x458A, 2, KaxTagGeneral, "Source");
DEFINE_MKX_UNISTRING   (KaxTagSourceForm,             0x45B5, 2, KaxTagGeneral, "SourceForm");
DEFINE_MKX_UNISTRING   (KaxTagProduct,                0x45E3, 2, KaxTagGeneral, "Product");
DEFINE_MKX_UNISTRING   (KaxTagOriginalMediaType,      0x45A7, 2, KaxTagGeneral, "OriginalMediaType");
DEFINE_MKX_UINTEGER    (KaxTagPlayCounter,            0x4566, 2, KaxTagTargets, "PlayCounter");
DEFINE_MKX_SINTEGER    (KaxTagPopularimeter,          0x4532, 2, KaxTagTargets, "Popularimeter");
DEFINE_MKX_STRING      (KaxTagAudioGenre,             0x65C2, 2, KaxTagGenres, "AudioGenre");
DEFINE_MKX_BINARY      (KaxTagVideoGenre,             0x65A1, 2, KaxTagGenres, "VideoGenre");
DEFINE_MKX_STRING      (KaxTagSubGenre,               0x65AC, 2, KaxTagGenres, "SubGenre");
DEFINE_MKX_BINARY      (KaxTagAudioEncryption,        0x41B4, 2, KaxTagAudioSpecific, "AudioEncryption");
DEFINE_MKX_FLOAT       (KaxTagAudioGain,              0x4199, 2, KaxTagAudioSpecific, "AudioGain");
DEFINE_MKX_FLOAT       (KaxTagAudioPeak,              0x4189, 2, KaxTagAudioSpecific, "AudioPeak");
DEFINE_MKX_FLOAT       (KaxTagBPM,                    0x41A1, 2, KaxTagAudioSpecific, "BPM");
DEFINE_MKX_UINTEGER    (KaxTagDiscTrack,              0x41B6, 2, KaxTagAudioSpecific, "DiscTrack");
DEFINE_MKX_UINTEGER    (KaxTagSetPart,                0x416E, 2, KaxTagAudioSpecific, "SetPart");
DEFINE_MKX_BINARY      (KaxTagEqualisation,           0x41B1, 2, KaxTagAudioSpecific, "Equalisation");
DEFINE_MKX_STRING      (KaxTagInitialKey,             0x413A, 2, KaxTagAudioSpecific, "InitialKey");
DEFINE_MKX_STRING      (KaxTagOfficialAudioFileURL,   0x4133, 2, KaxTagAudioSpecific, "OfficialAudioFileURL");
DEFINE_MKX_STRING      (KaxTagOfficialAudioSourceURL, 0x413E, 2, KaxTagAudioSpecific, "AudioSourceURL");
DEFINE_MKX_UINTEGER    (KaxTagCaptureDPI,             0x49C7, 2, KaxTagImageSpecific, "CaptureDPI");
DEFINE_MKX_BINARY      (KaxTagCaptureLightness,       0x49E1, 2, KaxTagImageSpecific, "CaptureLightness");
DEFINE_MKX_UINTEGER    (KaxTagCapturePaletteSetting,  0x4934, 2, KaxTagImageSpecific, "CapturePaletteSetting");
DEFINE_MKX_BINARY      (KaxTagCaptureSharpness,       0x4922, 2, KaxTagImageSpecific, "CaptureSharpness");
DEFINE_MKX_UNISTRING   (KaxTagCropped,                0x4987, 2, KaxTagImageSpecific, "Cropped");
DEFINE_MKX_STRING      (KaxTagOriginalDimensions,     0x4933, 2, KaxTagImageSpecific, "OriginalDimensions");

DEFINE_MKX_MASTER      (KaxTagSimple,                 0x67C8, 2, KaxTag, "TagSimple");
DEFINE_MKX_UNISTRING   (KaxTagName,                   0x45A3, 2, KaxTagSimple, "TagName");
DEFINE_MKX_STRING_DEF  (KaxTagLangue,                 0x447A, 2, KaxTagSimple, "TagLanguage", "und");
DEFINE_MKX_UINTEGER_DEF(KaxTagDefault,                0x4484, 2, KaxTagSimple, "TagDefault", 1);
DEFINE_MKX_UNISTRING   (KaxTagString,                 0x4487, 2, KaxTagSimple, "TagString");
DEFINE_MKX_BINARY      (KaxTagBinary,                 0x4485, 2, KaxTagSimple, "TagBinary");

END_LIBMATROSKA_NAMESPACE
