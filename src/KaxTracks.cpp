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

START_LIBMATROSKA_NAMESPACE

const EbmlSemantic KaxTracks_ContextList[1] =
{
	EbmlSemantic(true, false, EBML_INFO(KaxTrackEntry)),
};

#if MATROSKA_VERSION == 1
const EbmlSemantic KaxTrackEntry_ContextList[22] =
#else // MATROSKA_VERSION
const EbmlSemantic KaxTrackEntry_ContextList[27] =
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

const EbmlSemanticContext KaxTracks_Context = EbmlSemanticContext(countof(KaxTracks_ContextList), KaxTracks_ContextList, &KaxSegment_Context, *GetKaxGlobal_Context, &EBML_INFO(KaxTracks));
const EbmlSemanticContext KaxTrackEntry_Context = EbmlSemanticContext(countof(KaxTrackEntry_ContextList), KaxTrackEntry_ContextList, &KaxTracks_Context, *GetKaxGlobal_Context, &EBML_INFO(KaxTrackEntry));

EbmlId KaxTracks_TheId    (0x1654AE6B, 4);
EbmlId KaxTrackEntry_TheId(0xAE, 1);

const EbmlCallbacks KaxTracks::ClassInfos(KaxTracks::Create, KaxTracks_TheId, "Tracks", KaxTracks_Context);
const EbmlCallbacks KaxTrackEntry::ClassInfos(KaxTrackEntry::Create, KaxTrackEntry_TheId, "TrackEntry", KaxTrackEntry_Context);

KaxTracks::KaxTracks()
	:EbmlMaster(KaxTracks_Context)
{}

KaxTrackEntry::KaxTrackEntry()
	:EbmlMaster(KaxTrackEntry_Context)
	,bGlobalTimecodeScaleIsSet(false)
{}

void KaxTrackEntry::EnableLacing(bool bEnable)
{
	KaxTrackFlagLacing & myLacing = GetChild<KaxTrackFlagLacing>(*this);
	*(static_cast<EbmlUInteger *>(&myLacing)) = bEnable ? 1 : 0;
}

END_LIBMATROSKA_NAMESPACE
