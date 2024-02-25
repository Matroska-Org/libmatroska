// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include <ebml/EbmlContexts.h>
#include <ebml/EbmlHead.h>
#include "matroska/KaxContexts.h"
#include "matroska/KaxBlock.h"
#include "matroska/KaxCluster.h"
#include "matroska/KaxSegment.h"
#include "matroska/KaxTracks.h"

using namespace libebml;

namespace libmatroska {

DEFINE_START_SEMANTIC(KaxMatroska)
DEFINE_SEMANTIC_ITEM(true, true, EbmlHead)
DEFINE_SEMANTIC_ITEM(false, false, KaxSegment)
DEFINE_END_SEMANTIC(KaxMatroska)

DEFINE_MKX_CONTEXT(KaxMatroska)

// for the moment
const EbmlSemanticContext & GetKaxGlobal_Context()
{
  return GetEbmlGlobal_Context();
}

} // namespace libmatroska
