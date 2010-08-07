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
	\version \$Id: KaxTracks.cpp 1202 2005-08-30 14:39:01Z robux4 $
	\author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include "matroska/KaxTracks.h"

// sub elements
#include "matroska/KaxTrackEntryData.h"
#include "matroska/KaxTrackAudio.h"
#include "matroska/KaxTrackVideo.h"
#include "matroska/KaxContentEncoding.h"
#include "matroska/KaxContexts.h"
#include "matroska/KaxDefines.h"

START_LIBMATROSKA_NAMESPACE

DEFINE_START_SEMANTIC(KaxTracks)
DEFINE_SEMANTIC_ITEM(true, false, KaxTrackEntry)
#if MATROSKA_VERSION >= 2
DEFINE_SEMANTIC_ITEM(false, false, KaxTrackDependency)
#endif
DEFINE_END_SEMANTIC(KaxTracks)

DEFINE_START_SEMANTIC(KaxTrackEntry)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackNumber)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackUID)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackType)
#if MATROSKA_VERSION >= 2
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackFlagEnabled)
#endif // MATROSKA_VERSION
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackFlagDefault)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackFlagForced)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackFlagLacing)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackMinCache)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackMaxCache)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackDefaultDuration)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackTimecodeScale)
DEFINE_SEMANTIC_ITEM(true, true, KaxMaxBlockAdditionID)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackName)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackLanguage)
DEFINE_SEMANTIC_ITEM(true, true, KaxCodecID)
DEFINE_SEMANTIC_ITEM(false, true, KaxCodecPrivate)
DEFINE_SEMANTIC_ITEM(false, true, KaxCodecName)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackAttachmentLink)
#if MATROSKA_VERSION >= 2
DEFINE_SEMANTIC_ITEM(false, true, KaxCodecSettings)
DEFINE_SEMANTIC_ITEM(false, false, KaxCodecInfoURL)
DEFINE_SEMANTIC_ITEM(false, false, KaxCodecDownloadURL)
DEFINE_SEMANTIC_ITEM(true, true, KaxCodecDecodeAll)
#endif // MATROSKA_VERSION
DEFINE_SEMANTIC_ITEM(false, false, KaxTrackOverlay)
DEFINE_SEMANTIC_ITEM(false, false, KaxTrackTranslate)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackAudio)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackVideo)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentEncodings)
DEFINE_END_SEMANTIC(KaxTrackEntry)

DEFINE_MKX_MASTER     (KaxTracks, 0x1654AE6B, 4, KaxSegment, "Tracks");
DEFINE_MKX_MASTER_CONS(KaxTrackEntry,   0xAE, 1, KaxTracks, "TrackEntry");

#if MATROSKA_VERSION >= 2
DEFINE_START_SEMANTIC(KaxTrackDependency)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackDependencyType)
DEFINE_SEMANTIC_ITEM(true, false, KaxTrackDependencyItem)
DEFINE_END_SEMANTIC(KaxTrackDependency)

DEFINE_START_SEMANTIC(KaxTrackDependencyItem)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackDependencyUID)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackDependencyStereoPos)
DEFINE_END_SEMANTIC(KaxTrackDependencyItem)

DEFINE_MKX_MASTER  (KaxTrackDependency,          0xE2, 1, KaxTracks, "TrackDependency");
DEFINE_MKX_UINTEGER(KaxTrackDependencyType,      0xE3, 1, KaxTrackDependency, "TrackDependencyType");
DEFINE_MKX_MASTER  (KaxTrackDependencyItem,      0xE4, 1, KaxTrackDependency, "TrackDependencyItem");
DEFINE_MKX_UINTEGER(KaxTrackDependencyUID,       0xE5, 1, KaxTrackDependencyItem, "TrackDependencyUID");
DEFINE_MKX_UINTEGER(KaxTrackDependencyStereoPos, 0xE9, 1, KaxTrackDependencyItem, "TrackDependencyStereoPos");
#endif

KaxTrackEntry::KaxTrackEntry(EBML_EXTRA_DEF)
	:EbmlMaster(EBML_CLASS_SEMCONTEXT(KaxTrackEntry) EBML_DEF_SEP EBML_EXTRA_CALL)
	,bGlobalTimecodeScaleIsSet(false)
{}

void KaxTrackEntry::EnableLacing(bool bEnable)
{
	KaxTrackFlagLacing & myLacing = GetChild<KaxTrackFlagLacing>(*this);
	*(static_cast<EbmlUInteger *>(&myLacing)) = bEnable ? 1 : 0;
}

END_LIBMATROSKA_NAMESPACE
