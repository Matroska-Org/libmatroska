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
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**
** See http://www.gnu.org/licenses/lgpl-2.1.html for LGPL licensing information.**
** Contact license@matroska.org if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

/*!
	\file
	\version \$Id$
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
#define Context_KaxCluster               KaxCluster_Context
#define Context_KaxBlockGroup            KaxBlockGroup_Context
#define Context_KaxInfo                  KaxInfo_Context
#define Context_KaxAttached              KaxAttached_Context
#define Context_KaxAttachments           KaxAttachments_Context
#define Context_KaxChapters              KaxChapters_Context
#define Context_KaxCues                  KaxCues_Context
#define Context_KaxTags                  KaxTags_Context
#define Context_KaxSeekHead              KaxSeekHead_Context
#define Context_KaxTag                   KaxTag_Context
#define Context_KaxTagCommercial         KaxTagCommercial_Context

extern MATROSKA_DLL_API const EbmlSemanticContext & GetKaxGlobal_Context();
//extern MATROSKA_DLL_API const EbmlSemanticContext & GetKaxTagsGlobal_Context();

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_CONTEXTS_H
