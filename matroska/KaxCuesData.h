// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_CUES_DATA_H
#define LIBMATROSKA_CUES_DATA_H

#include "matroska/KaxTypes.h"
#include <ebml/EbmlUInteger.h>
#include <ebml/EbmlMaster.h>
#include "matroska/KaxDefines.h"

namespace libmatroska {

class KaxBlockGroup;
class KaxBlockBlob;
class KaxCueTrackPositions;
class KaxInternalBlock;
class KaxSimpleBlock;

DECLARE_MKX_MASTER(KaxCuePoint)
  public:
    void PositionSet(const KaxBlockGroup & BlockReference, std::uint64_t GlobalTimestampScale);
    void PositionSet(const KaxBlockBlob & BlobReference, std::uint64_t GlobalTimestampScale);
    void PositionSet(const KaxSimpleBlock & BlockReference, std::uint64_t GlobalTimestampScale);
    void PositionSet(const KaxInternalBlock & BlockReference, const KaxBlockGroup *BlockGroup, std::uint64_t GlobalTimestampScale);

    bool IsSmallerThan(const EbmlElement *Cmp) const override;

    const KaxCueTrackPositions * GetSeekPosition() const;
    bool Timecode(std::uint64_t & aTimestamp, std::uint64_t GlobalTimestampScale) const;
};

DECLARE_MKX_MASTER(KaxCueTrackPositions)
  public:
    std::uint64_t ClusterPosition() const;
    std::uint16_t TrackNumber() const;
};

DECLARE_MKX_MASTER(KaxCueReference)
  public:
    void AddReference(const KaxBlockGroup & BlockReferenced, std::uint64_t GlobalTimestampScale);
    void AddReference(const KaxBlockBlob & BlockReferenced, std::uint64_t GlobalTimestampScale);
};

} // namespace libmatroska

#endif // LIBMATROSKA_CUES_DATA_H
