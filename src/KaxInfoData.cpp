// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
  \author John Cannon      <spyder2555 @ users.sf.net>
*/
#include "matroska/KaxInfoData.h"
#include "matroska/KaxContexts.h"
#include "matroska/KaxDefines.h"
#include "matroska/KaxSemantic.h"

namespace libmatroska {

#if defined(HAVE_EBML2) || defined(HAS_EBML2)
KaxSegmentUID::KaxSegmentUID()
  :EbmlBinary(EBML_DEF_PARAM)
{
}
#endif

} // namespace libmatroska
