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
	\version \$Id: KaxContexts.h,v 1.6 2004/04/14 23:26:17 robux4 Exp $
	\author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_CONTEXTS_H
#define LIBMATROSKA_CONTEXTS_H

#include "matroska/KaxTypes.h"
#include "ebml/EbmlElement.h"

using namespace LIBEBML_NAMESPACE;

START_LIBMATROSKA_NAMESPACE

extern const EbmlSemanticContext MATROSKA_DLL_API KaxMatroska_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxSegment_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxAttachments_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxAttached_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxFileDescription_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxFileName_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxMimeType_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxFileData_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxChapters_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxCluster_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxTags_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxTag_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxBlockGroup_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxReferencePriority_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxReferenceBlock_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxReferenceVirtual_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxCues_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxInfo_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxSeekHead_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxTracks_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxTrackEntry_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxTrackNumber_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxTrackType_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxTrackFlagEnabled_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxTrackFlagDefault_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxTrackFlagLacing_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxTrackName_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxTrackLanguage_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxCodecID_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxCodecPrivate_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxCodecName_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxCodecSettings_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxCodecInfoURL_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxCodecDownloadURL_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxCodecDecodeAll_Context;
extern const EbmlSemanticContext MATROSKA_DLL_API KaxTrackOverlay_Context;

#define Context_KaxMatroska              KaxMatroska_Context
#define Context_KaxSegment               KaxSegment_Context
#define Context_KaxTrackEntry            KaxTrackEntry_Context
#define Context_KaxTracks                KaxTracks_Context
#define Context_KaxTrackVideo            KaxTrackVideo_Context
#define Context_KaxCluster               KaxCluster_Context
#define Context_KaxBlockMore             KaxBlockMore_Context
#define Context_KaxBlockAdditions        KaxBlockAdditions_Context
#define Context_KaxBlockGroup            KaxBlockGroup_Context
#define Context_KaxTimeSlice             KaxTimeSlice_Context
#define Context_KaxSlices                KaxSlices_Context
#define Context_KaxContentEncoding       KaxContentEncoding_Context
#define Context_KaxContentEncodings      KaxContentEncodings_Context
#define Context_KaxContentCompression    KaxContentCompression_Context
#define Context_KaxContentEncryption     KaxContentEncryption_Context
#define Context_KaxInfo                  KaxInfo_Context
#define Context_KaxChapterTranslate      KaxChapterTranslate_Context
#define Context_KaxTrackAudio            KaxTrackAudio_Context
#define Context_KaxTrackTranslate        KaxTrackTranslate_Context
#define Context_KaxAttached              KaxAttached_Context
#define Context_KaxAttachments           KaxAttachments_Context
#define Context_KaxEditionEntry          KaxEditionEntry_Context
#define Context_KaxChapters              KaxChapters_Context
#define Context_KaxChapterAtom           KaxChapterAtom_Context
#define Context_KaxChapterTrack          KaxChapterTrack_Context
#define Context_KaxChapterDisplay        KaxChapterDisplay_Context
#define Context_KaxChapterProcess        KaxChapterProcess_Context
#define Context_KaxChapterProcessCommand KaxChapterProcessCommand_Context
#define Context_KaxClusterSilentTracks   KaxClusterSilentTracks_Context
#define Context_KaxCues                  KaxCues_Context
#define Context_KaxCuePoint              KaxCuePoint_Context
#define Context_KaxCueTrackPositions     KaxCueTrackPositions_Context
#define Context_KaxCueReference          KaxCueReference_Context
#define Context_KaxSeek                  KaxSeek_Context
#define Context_KaxTags                  KaxTags_Context
#define Context_KaxSeekHead              KaxSeekHead_Context
#define Context_KaxTagGeneral            KaxTagGeneral_Context
#define Context_KaxTagAudioSpecific      KaxTagAudioSpecific_Context
#define Context_KaxTagImageSpecific      KaxTagImageSpecific_Context
#define Context_KaxTagGenres             KaxTagGenres_Context
#define Context_KaxTagTargets            KaxTagTargets_Context
#define Context_KaxTag                   KaxTag_Context
#define Context_KaxTagSimple             KaxTagSimple_Context
#define Context_KaxTagMultiComment       KaxTagMultiComment_Context
#define Context_KaxTagMultiCommercial    KaxTagMultiCommercial_Context
#define Context_KaxTagCommercial         KaxTagCommercial_Context
#define Context_KaxTagMultiPrice         KaxTagMultiPrice_Context
#define Context_KaxTagMultiDate          KaxTagMultiDate_Context
#define Context_KaxTagDate               KaxTagDate_Context
#define Context_KaxTagMultiEntity        KaxTagMultiEntity_Context
#define Context_KaxTagEntity             KaxTagEntity_Context
#define Context_KaxTagMultiLegal         KaxTagMultiLegal_Context
#define Context_KaxTagLegal              KaxTagLegal_Context
#define Context_KaxTagMultiIdentifier    KaxTagMultiIdentifier_Context
#define Context_KaxTagIdentifier         KaxTagIdentifier_Context
#define Context_KaxTagMultiTitle         KaxTagMultiTitle_Context
#define Context_KaxTagTitle              KaxTagTitle_Context
#define Context_KaxTagMultiAttachment    KaxTagMultiAttachment_Context
#define Context_KaxTagAttachment         KaxTagAttachment_Context

extern const EbmlSemanticContext & MATROSKA_DLL_API GetKaxGlobal_Context();
//extern const EbmlSemanticContext & MATROSKA_DLL_API GetKaxTagsGlobal_Context();

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_CONTEXTS_H
