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

static const EbmlSemantic ContextList_KaxTracks[1] =
{
	EbmlSemantic(true, false, EBML_INFO(KaxTrackEntry)),
};

#if MATROSKA_VERSION == 1
static const EbmlSemantic ContextList_KaxTrackEntry[22] =
#else // MATROSKA_VERSION
static const EbmlSemantic ContextList_KaxTrackEntry[27] =
#endif // MATROSKA_VERSION
{
	EbmlSemantic(true , true, EBML_INFO(KaxTrackNumber)),
	EbmlSemantic(true , true, EBML_INFO(KaxTrackUID)),
	EbmlSemantic(true , true, EBML_INFO(KaxTrackType)),
#if MATROSKA_VERSION >= 2
	EbmlSemantic(true , true, EBML_INFO(KaxTrackFlagEnabled)),
#endif // MATROSKA_VERSION
	EbmlSemantic(true , true, EBML_INFO(KaxTrackFlagDefault)),
	EbmlSemantic(true , true, EBML_INFO(KaxTrackFlagForced)),
	EbmlSemantic(true , true, EBML_INFO(KaxTrackFlagLacing)),
	EbmlSemantic(true , true, EBML_INFO(KaxTrackMinCache)),
	EbmlSemantic(false, true, EBML_INFO(KaxTrackMaxCache)),
	EbmlSemantic(false, true, EBML_INFO(KaxTrackDefaultDuration)),
	EbmlSemantic(true , true, EBML_INFO(KaxTrackTimecodeScale)),
	EbmlSemantic(true , true, EBML_INFO(KaxMaxBlockAdditionID)),
	EbmlSemantic(false, true, EBML_INFO(KaxTrackName)),
	EbmlSemantic(false, true, EBML_INFO(KaxTrackLanguage)),
	EbmlSemantic(true , true, EBML_INFO(KaxCodecID)),
	EbmlSemantic(false, true, EBML_INFO(KaxCodecPrivate)),
	EbmlSemantic(false, true, EBML_INFO(KaxCodecName)),
	EbmlSemantic(false, true, EBML_INFO(KaxTrackAttachmentLink)),
#if MATROSKA_VERSION >= 2
	EbmlSemantic(false, true, EBML_INFO(KaxCodecSettings)),
	EbmlSemantic(false, false,EBML_INFO(KaxCodecInfoURL)),
	EbmlSemantic(false, false,EBML_INFO(KaxCodecDownloadURL)),
	EbmlSemantic(true , true, EBML_INFO(KaxCodecDecodeAll)),
#endif // MATROSKA_VERSION
	EbmlSemantic(false, false,EBML_INFO(KaxTrackOverlay)),
	EbmlSemantic(false, false,EBML_INFO(KaxTrackTranslate)),
	EbmlSemantic(false, true, EBML_INFO(KaxTrackAudio)),
	EbmlSemantic(false, true, EBML_INFO(KaxTrackVideo)),
	EbmlSemantic(false, true, EBML_INFO(KaxContentEncodings)),
};

DEFINE_MKX_MASTER(KaxTracks,        0x1654AE6B, 4, KaxSegment, "Tracks");
DEFINE_MKX_MASTER_NOBODY(KaxTrackEntry,   0xAE, 1, KaxTracks, "TrackEntry");

KaxTrackEntry::KaxTrackEntry()
	:EbmlMaster(Context_KaxTrackEntry)
	,bGlobalTimecodeScaleIsSet(false)
{}

void KaxTrackEntry::EnableLacing(bool bEnable)
{
	KaxTrackFlagLacing & myLacing = GetChild<KaxTrackFlagLacing>(*this);
	*(static_cast<EbmlUInteger *>(&myLacing)) = bEnable ? 1 : 0;
}

END_LIBMATROSKA_NAMESPACE
