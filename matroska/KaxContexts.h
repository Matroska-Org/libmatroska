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

namespace libmatroska {

extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxMatroska;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxSegment;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxAttachments;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxAttached;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxFileDescription;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxFileName;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxMimeType;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxFileData;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxChapters;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxCluster;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxTags;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxTag;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxBlockGroup;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxReferencePriority;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxReferenceBlock;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxReferenceVirtual;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxCues;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxInfo;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxSeekHead;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxTracks;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxTrackEntry;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxTrackNumber;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxTrackType;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxTrackFlagEnabled;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxTrackFlagDefault;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxTrackFlagLacing;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxTrackName;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxTrackLanguage;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxCodecID;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxCodecPrivate;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxCodecName;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxCodecSettings;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxCodecInfoURL;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxCodecDownloadURL;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxCodecDecodeAll;
extern const libebml::EbmlSemanticContext MATROSKA_DLL_API Context_KaxTrackOverlay;

extern MATROSKA_DLL_API const libebml::EbmlSemanticContext & GetKaxGlobal_Context();

} // namespace libmatroska

#endif // LIBMATROSKA_CONTEXTS_H
