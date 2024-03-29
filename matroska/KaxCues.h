// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_CUES_H
#define LIBMATROSKA_CUES_H

#include <vector>

#include "matroska/KaxTypes.h"
#include <ebml/EbmlMaster.h>
#include "matroska/KaxBlock.h"

namespace libmatroska {

class KaxCuePoint;

DECLARE_MKX_MASTER(KaxCues)
  public:
    ~KaxCues() override;

    //bool AddBlockGroup(const KaxBlockGroup & BlockReference); // deprecated
    bool AddBlockBlob(const KaxBlockBlob & BlockReference);

    /*!
      \brief Indicate that the position for this Block is set
    */
    void PositionSet(const KaxBlockGroup & BlockReference);
    void PositionSet(const KaxBlockBlob & BlockReference);

    /*!
      \brief override to sort by timestamp/track
    */
    libebml::filepos_t Render(libebml::IOCallback & output, const ShouldWrite& writeFilter = WriteSkipDefault) {
      Sort();
      return EbmlMaster::Render(output, writeFilter);
    }

    std::uint64_t GetTimestampPosition(std::uint64_t aTimestamp) const;
    const KaxCuePoint * GetTimestampPoint(std::uint64_t aTimestamp) const;

    void SetGlobalTimestampScale(std::uint64_t aGlobalTimestampScale) {
      mGlobalTimestampScale = aGlobalTimestampScale;
      bGlobalTimestampScaleIsSet = true;
    }
    std::uint64_t GlobalTimestampScale() const {
      assert(bGlobalTimestampScaleIsSet);
      return mGlobalTimestampScale;
    }

  protected:
    std::vector<const KaxBlockBlob *> myTempReferences;
    bool   bGlobalTimestampScaleIsSet;
    std::uint64_t mGlobalTimestampScale;
};

} // namespace libmatroska

#endif // LIBMATROSKA_CUES_H
