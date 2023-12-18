// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include "matroska/KaxContexts.h"
#include "matroska/KaxDefines.h"
#include "matroska/KaxSemantic.h"

using namespace libebml;

// sub elements
namespace libmatroska {

KaxAttachments::KaxAttachments()
  :EbmlMaster(EBML_CLASS_SEMCONTEXT(KaxAttachments))
{
  SetSizeLength(2); // mandatory min size support (for easier updating) (2^(7*2)-2 = 16Ko)
}

} // namespace libmatroska
