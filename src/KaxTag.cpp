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

DEFINE_START_SEMANTIC(KaxTag)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagTargets)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagGeneral)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagGenres)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagAudioSpecific)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagImageSpecific)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiCommercial)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiDate)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiEntity)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiIdentifier)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiLegal)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiTitle)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiAttachment)
//DEFINE_SEMANTIC_ITEM(false, false, KaxTagLength)
//DEFINE_SEMANTIC_ITEM(false, false, KaxTagPlaylistDelay)
//DEFINE_SEMANTIC_ITEM(false, false, KaxTagUnsynchronisedText)
//DEFINE_SEMANTIC_ITEM(false, false, KaxTagUserDefinedURL)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagMultiComment)
DEFINE_SEMANTIC_ITEM(true, false, KaxTagSimple)
DEFINE_END_SEMANTIC(KaxTag)

DEFINE_START_SEMANTIC(KaxTagTargets)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagTargetTypeValue)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagTargetType)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagTrackUID)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagEditionUID)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagChapterUID)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagAttachmentUID)
DEFINE_END_SEMANTIC(KaxTagTargets)

DEFINE_START_SEMANTIC(KaxTagGeneral)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagArchivalLocation)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagFile)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagKeywords)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMood)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagRecordLocation)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagSource)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagSourceForm)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagProduct)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagOriginalMediaType)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagPlayCounter)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagPopularimeter)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagSubject)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagBibliography)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagLanguage)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagRating)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagEncoder)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagEncodeSettings)
DEFINE_END_SEMANTIC(KaxTagGeneral)

DEFINE_START_SEMANTIC(KaxTagGenres)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagAudioGenre)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagVideoGenre)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagSubGenre)
DEFINE_END_SEMANTIC(KaxTagGenres)

DEFINE_START_SEMANTIC(KaxTagAudioSpecific)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagAudioPeak)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagAudioEncryption)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagAudioGain)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagBPM)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagDiscTrack)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagSetPart)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagEqualisation)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagInitialKey)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagOfficialAudioFileURL)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagOfficialAudioSourceURL)
DEFINE_END_SEMANTIC(KaxTagAudioSpecific)

DEFINE_START_SEMANTIC(KaxTagImageSpecific)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagCaptureDPI)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagCaptureLightness)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagCapturePaletteSetting)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagCaptureSharpness)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagCropped)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagOriginalDimensions)
DEFINE_END_SEMANTIC(KaxTagImageSpecific)

DEFINE_START_SEMANTIC(KaxTagSimple)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagName)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagLangue)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagDefault)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagString)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagBinary)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagSimple)
DEFINE_END_SEMANTIC(KaxTagSimple)

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
