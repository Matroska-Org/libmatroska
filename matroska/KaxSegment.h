// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_SEGMENT_H
#define LIBMATROSKA_SEGMENT_H

#include "matroska/KaxTypes.h"
#include <ebml/EbmlMaster.h>
#include "matroska/KaxDefines.h"

using namespace libebml;

namespace libmatroska {

DECLARE_MKX_MASTER_CONS(KaxSegment)
  public:
    /*!
      \brief give the position of the element in the segment
    */
    std::uint64_t GetRelativePosition(const EbmlElement & Elt) const;
    std::uint64_t GetRelativePosition(std::uint64_t aGlobalPosition) const;

    /*!
      \brief give the position of the element in the file
    */
    std::uint64_t GetGlobalPosition(std::uint64_t aRelativePosition) const;
};

} // namespace libmatroska

#endif // LIBMATROSKA_SEGMENT_H
