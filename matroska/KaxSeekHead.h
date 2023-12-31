// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_SEEK_HEAD_H
#define LIBMATROSKA_SEEK_HEAD_H

#include "matroska/KaxTypes.h"
#include <ebml/EbmlMaster.h>
#include <ebml/EbmlBinary.h>
#include <ebml/EbmlUInteger.h>
#include "matroska/KaxDefines.h"

namespace libmatroska {

class KaxSegment;

DECLARE_MKX_MASTER(KaxSeek)
  public:
    std::int64_t Location() const;
    bool IsEbmlId(const libebml::EbmlId & aId) const;
    bool IsEbmlId(const KaxSeek & aPoint) const;
};

DECLARE_MKX_MASTER(KaxSeekHead)
  public:
    /*!
      \brief add an element to index in the Meta Seek data
      \note the element should already be written in the file
    */
    KaxSeek * IndexThis(const EbmlElement & aElt, const KaxSegment & ParentSegment);

    KaxSeek * FindFirstOf(const libebml::EbmlCallbacks & Callbacks) const;
    KaxSeek * FindNextOf(const KaxSeek &aPrev) const;
};

} // namespace libmatroska

#endif // LIBMATROSKA_SEEK_HEAD_H
