// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_CONTEXTS_H
#define LIBMATROSKA_CONTEXTS_H

#include "matroska/KaxTypes.h"
#include <ebml/EbmlElement.h>

using namespace libebml;

namespace libmatroska {

extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxMatroska;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxSegment;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxAttachments;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxAttached;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxFileDescription;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxFileName;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxMimeType;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxFileData;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxChapters;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxCluster;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxTags;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxTag;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxBlockGroup;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxReferencePriority;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxReferenceBlock;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxReferenceVirtual;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxCues;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxInfo;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxSeekHead;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxTracks;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxTrackEntry;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxTrackNumber;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxTrackType;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxTrackFlagEnabled;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxTrackFlagDefault;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxTrackFlagLacing;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxTrackName;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxTrackLanguage;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxCodecID;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxCodecPrivate;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxCodecName;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxCodecSettings;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxCodecInfoURL;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxCodecDownloadURL;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxCodecDecodeAll;
extern const EbmlSemanticContext MATROSKA_DLL_API Context_KaxTrackOverlay;

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

} // namespace libmatroska

#endif // LIBMATROSKA_CONTEXTS_H
