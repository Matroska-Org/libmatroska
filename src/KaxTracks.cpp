// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include "matroska/KaxTracks.h"

// sub elements
#include "matroska/KaxContexts.h"
#include "matroska/KaxDefines.h"

namespace libmatroska {

KaxTrackEntry::KaxTrackEntry()
  :EbmlMaster(EBML_CLASS_SEMCONTEXT(KaxTrackEntry))
{}

void KaxTrackEntry::EnableLacing(bool bEnable)
{
  auto & myLacing = GetChild<KaxTrackFlagLacing>(*this);
  *(static_cast<EbmlUInteger *>(&myLacing)) = bEnable ? 1 : 0;
}

} // namespace libmatroska
