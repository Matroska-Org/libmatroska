/****************************************************************************
** libmatroska : parse Matroska files, see http://www.matroska.org/
**
** <file/class description>
**
** Copyright (C) 2002-2010 Steve Lhomme.  All rights reserved.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License as published by the Free Software Foundation; either
** version 2.1 of the License, or (at your option) any later version.
**
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** Lesser General Public License for more details.
**
** You should have received a copy of the GNU Lesser General Public
** License along with this library; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**
** See http://www.gnu.org/licenses/lgpl-2.1.html for LGPL licensing information.**
** Contact license@matroska.org if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

/*!
  \file
  \version \$Id: KaxCluster.h,v 1.10 2004/04/14 23:26:17 robux4 Exp $
  \author Steve Lhomme     <robux4 @ users.sf.net>
  \author Julien Coloos    <suiryc @ users.sf.net>

*/
#ifndef LIBMATROSKA_CLUSTER_H
#define LIBMATROSKA_CLUSTER_H

#include "matroska/KaxTypes.h"
#include "ebml/EbmlMaster.h"
#include "matroska/KaxTracks.h"
#include "matroska/KaxBlock.h"
#include "matroska/KaxCues.h"
#include "matroska/KaxDefines.h"

using namespace libebml;

namespace libmatroska {

class KaxSegment;

DECLARE_MKX_MASTER_CONS(KaxCluster)
  public:
    /*!
      \brief Addition of a frame without references

      \param timecode the timecode is expressed in nanoseconds, relative to the beggining of the Segment
    */
    bool AddFrame(const KaxTrackEntry & track, uint64 timecode, DataBuffer & buffer, KaxBlockGroup * & MyNewBlock, LacingType lacing = LACING_AUTO);
    /*!
      \brief Addition of a frame with a backward reference (P frame)
      \param timecode the timecode is expressed in nanoseconds, relative to the beggining of the Segment

    */
    bool AddFrame(const KaxTrackEntry & track, uint64 timecode, DataBuffer & buffer, KaxBlockGroup * & MyNewBlock, const KaxBlockGroup & PastBlock, LacingType lacing = LACING_AUTO);

    /*!
      \brief Addition of a frame with a backward+forward reference (B frame)
      \param timecode the timecode is expressed in nanoseconds, relative to the beggining of the Segment

    */
    bool AddFrame(const KaxTrackEntry & track, uint64 timecode, DataBuffer & buffer, KaxBlockGroup * & MyNewBlock, const KaxBlockGroup & PastBlock, const KaxBlockGroup & ForwBlock, LacingType lacing = LACING_AUTO);

    /*!
      \brief Render the data to the stream and retrieve the position of BlockGroups for later cue entries
    */
    filepos_t Render(IOCallback & output, KaxCues & CueToUpdate, bool bSaveDefault = false);

    /*!
      \return the global timecode of this Cluster
    */
    uint64 GlobalTimecode() const;

    KaxBlockGroup & GetNewBlock();

    /*!
      \brief release all the frames of all Blocks
      \note this is a convenience to be able to keep Clusters+Blocks in memory (for future reference) withouht being a memory hog
    */
    void ReleaseFrames();

    /*!
      \brief return the position offset compared to the beggining of the Segment
    */
    uint64 GetPosition() const;

    void SetParent(const KaxSegment & aParentSegment) {ParentSegment = &aParentSegment;}

    void SetPreviousTimecode(uint64 aPreviousTimecode, int64 aTimecodeScale) {
      bPreviousTimecodeIsSet = true;
      PreviousTimecode = aPreviousTimecode;
      SetGlobalTimecodeScale(aTimecodeScale);
    }

    /*!
      \note dirty hack to get the mandatory data back after reading
      \todo there should be a better way to get mandatory data
    */
    void InitTimecode(uint64 aTimecode, int64 aTimecodeScale) {
      SetGlobalTimecodeScale(aTimecodeScale);
      MinTimecode = MaxTimecode = PreviousTimecode = aTimecode * TimecodeScale;
      bFirstFrameInside = bPreviousTimecodeIsSet = true;
    }

    int16 GetBlockLocalTimecode(uint64 GlobalTimecode) const;

    uint64 GetBlockGlobalTimecode(int16 LocalTimecode);

    void SetGlobalTimecodeScale(uint64 aGlobalTimecodeScale) {
      TimecodeScale = aGlobalTimecodeScale;
      bTimecodeScaleIsSet = true;
    }
    uint64 GlobalTimecodeScale() const {
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

    uint64 MinTimecode, MaxTimecode, PreviousTimecode;
    int64  TimecodeScale;

    bool   bFirstFrameInside{false}; // used to speed research
    bool   bPreviousTimecodeIsSet{false};
    bool   bTimecodeScaleIsSet{false};
    bool   bSilentTracksUsed{false};

    /*!
      \note method used internally
    */
    bool AddFrameInternal(const KaxTrackEntry & track, uint64 timecode, DataBuffer & buffer, KaxBlockGroup * & MyNewBlock, const KaxBlockGroup * PastBlock, const KaxBlockGroup * ForwBlock, LacingType lacing);
};

} // namespace libmatroska

#endif // LIBMATROSKA_CLUSTER_H
