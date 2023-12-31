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
    libebml::filepos_t Render(libebml::IOCallback & output, KaxCues & CueToUpdate, ShouldWrite writeFilter = WriteSkipDefault);

    /*!
      \return the global timecode of this Cluster
    */
    std::uint64_t GlobalTimecode() const;

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

    void SetPreviousTimecode(std::uint64_t aPreviousTimecode, std::int64_t aTimecodeScale) {
      bPreviousTimecodeIsSet = true;
      PreviousTimecode = aPreviousTimecode;
      SetGlobalTimecodeScale(aTimecodeScale);
    }

    /*!
      \note dirty hack to get the mandatory data back after reading
      \todo there should be a better way to get mandatory data
    */
    void InitTimecode(std::uint64_t aTimecode, std::int64_t aTimecodeScale) {
      SetGlobalTimecodeScale(aTimecodeScale);
      MinTimecode = MaxTimecode = PreviousTimecode = aTimecode * TimecodeScale;
      bFirstFrameInside = bPreviousTimecodeIsSet = true;
    }

    std::int16_t GetBlockLocalTimecode(std::uint64_t GlobalTimecode) const;

    std::uint64_t GetBlockGlobalTimecode(std::int16_t LocalTimecode);

    void SetGlobalTimecodeScale(std::uint64_t aGlobalTimecodeScale) {
      TimecodeScale = aGlobalTimecodeScale;
      bTimecodeScaleIsSet = true;
    }
    std::uint64_t GlobalTimecodeScale() const {
      assert(bTimecodeScaleIsSet);
      return TimecodeScale;
    }

    bool SetSilentTrackUsed()
    {
      bSilentTracksUsed = true;
      return FindFirstElt(EBML_INFO(KaxClusterSilentTracks), true) != nullptr;
    }

    bool AddBlockBlob(KaxBlockBlob * NewBlob);

    const KaxSegment *GetParentSegment() const { return ParentSegment; }

  protected:
    KaxBlockBlob     * currentNewBlob;
    std::vector<KaxBlockBlob*> Blobs;
    KaxBlockGroup    * currentNewBlock{nullptr};
    const KaxSegment * ParentSegment{nullptr};

    std::uint64_t MinTimecode, MaxTimecode, PreviousTimecode;
    std::int64_t  TimecodeScale;

    bool   bFirstFrameInside{false}; // used to speed research
    bool   bPreviousTimecodeIsSet{false};
    bool   bTimecodeScaleIsSet{false};
    bool   bSilentTracksUsed{false};

    /*!
      \note method used internally
    */
    bool AddFrameInternal(const KaxTrackEntry & track, std::uint64_t timestamp, DataBuffer & buffer, KaxBlockGroup * & MyNewBlock, const KaxBlockGroup * PastBlock, const KaxBlockGroup * ForwBlock, LacingType lacing);
};

} // namespace libmatroska

#endif // LIBMATROSKA_CLUSTER_H
