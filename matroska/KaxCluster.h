// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
  \author Julien Coloos    <suiryc @ users.sf.net>

*/
#ifndef LIBMATROSKA_CLUSTER_H
#define LIBMATROSKA_CLUSTER_H

#include "matroska/KaxTypes.h"
#include <ebml/EbmlMaster.h>
#include "matroska/KaxTracks.h"
#include "matroska/KaxBlock.h"
#include "matroska/KaxCues.h"
#include "matroska/KaxDefines.h"

namespace libmatroska {

class KaxSegment;

DECLARE_MKX_MASTER_CONS(KaxCluster)
  public:
    /*!
      \brief Addition of a frame without references

      \param timestamp the timestamp is expressed in nanoseconds, relative to the beggining of the Segment
    */
    bool AddFrame(const KaxTrackEntry & track, std::uint64_t timestamp, DataBuffer & buffer, KaxBlockGroup * & MyNewBlock, LacingType lacing = LACING_AUTO);
    /*!
      \brief Addition of a frame with a backward reference (P frame)
      \param timestamp the timestamp is expressed in nanoseconds, relative to the beggining of the Segment

    */
    bool AddFrame(const KaxTrackEntry & track, std::uint64_t timestamp, DataBuffer & buffer, KaxBlockGroup * & MyNewBlock, const KaxBlockGroup & PastBlock, LacingType lacing = LACING_AUTO);

    /*!
      \brief Addition of a frame with a backward+forward reference (B frame)
      \param timestamp the timestamp is expressed in nanoseconds, relative to the beggining of the Segment

    */
    bool AddFrame(const KaxTrackEntry & track, std::uint64_t timestamp, DataBuffer & buffer, KaxBlockGroup * & MyNewBlock, const KaxBlockGroup & PastBlock, const KaxBlockGroup & ForwBlock, LacingType lacing = LACING_AUTO);

    /*!
      \brief Render the data to the stream and retrieve the position of BlockGroups for later cue entries
    */
    libebml::filepos_t Render(libebml::IOCallback & output, KaxCues & CueToUpdate, const ShouldWrite& writeFilter = WriteSkipDefault);

    /*!
      \return the global timestamp of this Cluster
    */
    std::uint64_t GlobalTimestamp() const;

    KaxBlockGroup & GetNewBlock();

    /*!
      \brief release all the frames of all Blocks
      \note this is a convenience to be able to keep Clusters+Blocks in memory (for future reference) withouht being a memory hog
    */
    void ReleaseFrames();

    /*!
      \brief return the position offset compared to the beggining of the Segment
    */
    std::uint64_t GetPosition() const;

    void SetParent(const KaxSegment & aParentSegment) {ParentSegment = &aParentSegment;}

    void SetPreviousTimestamp(std::uint64_t aPreviousTimestamp, std::int64_t aTimestampScale) {
      bPreviousTimestampIsSet = true;
      PreviousTimestamp = aPreviousTimestamp;
      SetGlobalTimestampScale(aTimestampScale);
    }

    /*!
      \note dirty hack to get the mandatory data back after reading
      \todo there should be a better way to get mandatory data
    */
    void InitTimestamp(std::uint64_t aTimestamp, std::int64_t aTimestampScale) {
      SetGlobalTimestampScale(aTimestampScale);
      MinTimestamp = MaxTimestamp = PreviousTimestamp = aTimestamp * TimestampScale;
      bFirstFrameInside = bPreviousTimestampIsSet = true;
    }

    std::int16_t GetBlockLocalTimestamp(std::uint64_t GlobalTimestamp) const;

    std::uint64_t GetBlockGlobalTimestamp(std::int16_t LocalTimestamp);

    void SetGlobalTimestampScale(std::uint64_t aGlobalTimestampScale) {
      TimestampScale = aGlobalTimestampScale;
      bTimestampScaleIsSet = true;
    }
    std::uint64_t GlobalTimestampScale() const {
      assert(bTimestampScaleIsSet);
      return TimestampScale;
    }

    bool AddBlockBlob(KaxBlockBlob * NewBlob);

    const KaxSegment *GetParentSegment() const { return ParentSegment; }

  protected:
    KaxBlockBlob     * currentNewBlob;
    std::vector<KaxBlockBlob*> Blobs;
    KaxBlockGroup    * currentNewBlock{nullptr};
    const KaxSegment * ParentSegment{nullptr};

    std::uint64_t MinTimestamp, MaxTimestamp, PreviousTimestamp;
    std::int64_t  TimestampScale;

    bool   bFirstFrameInside{false}; // used to speed research
    bool   bPreviousTimestampIsSet{false};
    bool   bTimestampScaleIsSet{false};

    /*!
      \note method used internally
    */
    bool AddFrameInternal(const KaxTrackEntry & track, std::uint64_t timestamp, DataBuffer & buffer, KaxBlockGroup * & MyNewBlock, const KaxBlockGroup * PastBlock, const KaxBlockGroup * ForwBlock, LacingType lacing);
};

} // namespace libmatroska

#endif // LIBMATROSKA_CLUSTER_H
