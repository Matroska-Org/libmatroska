// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_TRACKS_H
#define LIBMATROSKA_TRACKS_H

#include "matroska/KaxTypes.h"
#include <ebml/EbmlMaster.h>
#include <ebml/EbmlUInteger.h>
#include "matroska/KaxDefines.h"
#include "matroska/KaxSemantic.h"

using namespace libebml;

namespace libmatroska {

DECLARE_MKX_MASTER(KaxTrackEntry)
  public:
    EbmlUInteger & TrackNumber() const { return *(static_cast<EbmlUInteger *>(FindElt(EBML_INFO(KaxTrackNumber)))); }

    void EnableLacing(bool bEnable = true);

    /*!
      \note lacing set by default
    */
    inline bool LacingEnabled() const {
      auto myLacing = static_cast<KaxTrackFlagLacing *>(FindFirstElt(EBML_INFO(KaxTrackFlagLacing)));
      return(!myLacing || (static_cast<std::uint8_t>(*myLacing) != 0));
    }

    void SetGlobalTimecodeScale(std::uint64_t aGlobalTimecodeScale) {
      mGlobalTimecodeScale = aGlobalTimecodeScale;
      bGlobalTimecodeScaleIsSet = true;
    }
    std::uint64_t GlobalTimecodeScale() const {
      assert(bGlobalTimecodeScaleIsSet);
      return mGlobalTimecodeScale;
    }

  protected:
    bool   bGlobalTimecodeScaleIsSet{false};
    std::uint64_t mGlobalTimecodeScale;
};

} // namespace libmatroska

#endif // LIBMATROSKA_TRACKS_H
