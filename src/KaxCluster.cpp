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
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include "matroska/KaxCluster.h"
#include "matroska/KaxBlock.h"
#include "matroska/KaxContexts.h"
#include "matroska/KaxSegment.h"
#include "matroska/KaxDefines.h"

// sub elements
namespace libmatroska {

KaxCluster::KaxCluster(EBML_EXTRA_DEF)
  :EbmlMaster(EBML_CLASS_SEMCONTEXT(KaxCluster) EBML_DEF_SEP EBML_EXTRA_CALL)
{}

KaxCluster::KaxCluster(const KaxCluster & ElementToClone)
  :EbmlMaster(ElementToClone)
  ,bSilentTracksUsed(ElementToClone.bSilentTracksUsed)
{
  // update the parent of each children
  for (const auto& child : *this) {
    if (EbmlId(*child) == EBML_ID(KaxBlockGroup)) {
      static_cast<KaxBlockGroup   *>(child)->SetParent(*this);
    } else if (EbmlId(*child) == EBML_ID(KaxBlock)) {
      static_cast<KaxBlock        *>(child)->SetParent(*this);
    } else if (EbmlId(*child) == EBML_ID(KaxBlockVirtual)) {
      static_cast<KaxBlockVirtual *>(child)->SetParent(*this);
    }
  }
}

bool KaxCluster::AddBlockBlob(KaxBlockBlob * NewBlob)
{
  Blobs.push_back(NewBlob);
  return true;
}

bool KaxCluster::AddFrameInternal(const KaxTrackEntry & track, std::uint64_t timecode, DataBuffer & buffer, KaxBlockGroup * & MyNewBlock, const KaxBlockGroup * PastBlock, const KaxBlockGroup * ForwBlock, LacingType lacing)
{
  if (!bFirstFrameInside) {
    bFirstFrameInside = true;
    MinTimecode = MaxTimecode = timecode;
  } else {
    if (timecode < MinTimecode)
      MinTimecode = timecode;
    if (timecode > MaxTimecode)
      MaxTimecode = timecode;
  }

  MyNewBlock = nullptr;

  if (lacing == LACING_NONE || !track.LacingEnabled()) {
    currentNewBlock = nullptr;
  }

  // force creation of a new block
  if (!currentNewBlock || static_cast<std::uint32_t>(track.TrackNumber()) != static_cast<std::uint32_t>(currentNewBlock->TrackNumber()) || PastBlock || ForwBlock) {
    KaxBlockGroup & aNewBlock = GetNewBlock();
    MyNewBlock = currentNewBlock = &aNewBlock;
  }

  if (PastBlock) {
    if (ForwBlock) {
      if (currentNewBlock->AddFrame(track, timecode, buffer, *PastBlock, *ForwBlock, lacing)) {
        // more data are allowed in this Block
        return true;
      }

      currentNewBlock = nullptr;
      return false;
    }
    if (currentNewBlock->AddFrame(track, timecode, buffer, *PastBlock, lacing)) {
        // more data are allowed in this Block
        return true;
      }
    currentNewBlock = nullptr;
    return false;
  }

  if (currentNewBlock->AddFrame(track, timecode, buffer, lacing)) {
    // more data are allowed in this Block
    return true;
  }

  currentNewBlock = nullptr;
  return false;
}

bool KaxCluster::AddFrame(const KaxTrackEntry & track, std::uint64_t timecode, DataBuffer & buffer, KaxBlockGroup * & MyNewBlock, LacingType lacing)
{
  assert(Blobs.empty()); // mutually exclusive for the moment
  return AddFrameInternal(track, timecode, buffer, MyNewBlock, nullptr, nullptr, lacing);
}

bool KaxCluster::AddFrame(const KaxTrackEntry & track, std::uint64_t timecode, DataBuffer & buffer, KaxBlockGroup * & MyNewBlock, const KaxBlockGroup & PastBlock, LacingType lacing)
{
  assert(Blobs.empty()); // mutually exclusive for the moment
  return AddFrameInternal(track, timecode, buffer, MyNewBlock, &PastBlock, nullptr, lacing);
}

bool KaxCluster::AddFrame(const KaxTrackEntry & track, std::uint64_t timecode, DataBuffer & buffer, KaxBlockGroup * & MyNewBlock, const KaxBlockGroup & PastBlock, const KaxBlockGroup & ForwBlock, LacingType lacing)
{
  assert(Blobs.empty()); // mutually exclusive for the moment
  return AddFrameInternal(track, timecode, buffer, MyNewBlock, &PastBlock, &ForwBlock, lacing);
}

/*!
  \todo only put the Blocks written in the cue entries
*/
filepos_t KaxCluster::Render(IOCallback & output, KaxCues & CueToUpdate, bool bSaveDefault)
{
  filepos_t Result = 0;
  std::size_t Index;

  // update the Timecode of the Cluster before writing
  auto Timecode = static_cast<KaxClusterTimecode *>(this->FindElt(EBML_INFO(KaxClusterTimecode)));
  *static_cast<EbmlUInteger *>(Timecode) = GlobalTimecode() / GlobalTimecodeScale();

  if (Blobs.empty()) {
    // old-school direct KaxBlockGroup

    // SilentTracks handling
    // check the parent cluster for existing tracks and see if they are contained in this cluster or not
    if (bSilentTracksUsed) {
      auto MyTracks = static_cast<KaxTracks *>(ParentSegment->FindElt(EBML_INFO(KaxTracks)));
      for (const auto& Trk : *MyTracks) {
        if (EbmlId(*Trk) == EBML_ID(KaxTrackEntry)) {
          auto entry = static_cast<KaxTrackEntry *>(Trk);
          auto tracknum = static_cast<std::uint32_t>(entry->TrackNumber());
          auto track = std::find_if(ElementList.begin(), ElementList.end(), [=](EbmlElement *element)
              { return EbmlId(*element) == EBML_ID(KaxBlockGroup) && static_cast<KaxBlockGroup *>(element)->TrackNumber() == tracknum;  });
          // the track wasn't found in this cluster
          if (track == ElementList.end()) {
            auto SilentTracks = static_cast<KaxClusterSilentTracks *>(this->FindFirstElt(EBML_INFO(KaxClusterSilentTracks)));
            assert(SilentTracks); // the flag bSilentTracksUsed should be set when creating the Cluster
            auto trackelt = static_cast<KaxClusterSilentTrackNumber *>(SilentTracks->AddNewElt(EBML_INFO(KaxClusterSilentTrackNumber)));
            *static_cast<EbmlUInteger *>(trackelt) = tracknum;
          }
        }
      }
    }

    Result = EbmlMaster::Render(output, bSaveDefault);
    // For all Blocks add their position on the CueEntry

    for (const auto& element : ElementList) {
      if (EbmlId(*element) == EBML_ID(KaxBlockGroup)) {
        CueToUpdate.PositionSet(*static_cast<const KaxBlockGroup *>(element));
      }
    }
  } else {
    // new school, using KaxBlockBlob
    for (const auto& blob : Blobs) {
      if (blob->IsSimpleBlock())
        PushElement( static_cast<KaxSimpleBlock&>(*blob));
      else
        PushElement( static_cast<KaxBlockGroup&>(*blob));
    }

    // SilentTracks handling
    // check the parent cluster for existing tracks and see if they are contained in this cluster or not
    if (bSilentTracksUsed) {
      auto MyTracks = static_cast<KaxTracks *>(ParentSegment->FindElt(EBML_INFO(KaxTracks)));
      for (const auto& Trk : *MyTracks) {
        if (EbmlId(*Trk) == EBML_ID(KaxTrackEntry)) {
          auto entry = static_cast<KaxTrackEntry *>(Trk);
          auto tracknum = static_cast<std::uint32_t>(entry->TrackNumber());
          for (Index = 0; Index<Blobs.size(); Index++) {
            if (static_cast<KaxInternalBlock&>(*Blobs[Index]).TrackNum() == tracknum)
              break; // this track is used
          }
          // the track wasn't found in this cluster
          if (Index == ListSize()) {
            auto SilentTracks = static_cast<KaxClusterSilentTracks *>(this->FindFirstElt(EBML_INFO(KaxClusterSilentTracks)));
            assert(SilentTracks); // the flag bSilentTracksUsed should be set when creating the Cluster
            auto trackelt = static_cast<KaxClusterSilentTrackNumber *>(SilentTracks->AddNewElt(EBML_INFO(KaxClusterSilentTrackNumber)));
            *static_cast<EbmlUInteger *>(trackelt) = tracknum;
          }
        }
      }
    }

    Result = EbmlMaster::Render(output, bSaveDefault);

    // For all Blocks add their position on the CueEntry
    for (const auto& blob : Blobs)
      CueToUpdate.PositionSet(*blob);

    Blobs.clear();
  }

  return Result;
}

/*!
  \todo automatically choose valid timecode for the Cluster based on the previous cluster timecode (must be incremental)
*/
std::uint64_t KaxCluster::GlobalTimecode() const
{
  assert(bPreviousTimecodeIsSet);
  std::uint64_t result = MinTimecode;

  if (result < PreviousTimecode)
    result = PreviousTimecode + 1;

  return result;
}

/*!
  \brief retrieve the relative
  \todo !!! We need a way to know the TimecodeScale
*/
std::int16_t KaxCluster::GetBlockLocalTimecode(std::uint64_t aGlobalTimecode) const
{
  const std::int64_t TimecodeDelay = (static_cast<std::int64_t>(aGlobalTimecode) - static_cast<std::int64_t>(GlobalTimecode())) / static_cast<std::int64_t>(GlobalTimecodeScale());
  assert(TimecodeDelay >= std::int16_t(0x8000) && TimecodeDelay <= std::int16_t(0x7FFF));
  return static_cast<std::int16_t>(TimecodeDelay);
}

std::uint64_t KaxCluster::GetBlockGlobalTimecode(std::int16_t LocalTimecode)
{
  if (!bFirstFrameInside) {
    auto Timecode = static_cast<KaxClusterTimecode *>(this->FindElt(EBML_INFO(KaxClusterTimecode)));
    assert (bFirstFrameInside); // use the InitTimecode() hack for now
    MinTimecode = MaxTimecode = PreviousTimecode = static_cast<std::uint64_t>(*static_cast<EbmlUInteger *>(Timecode));
    bFirstFrameInside = true;
    bPreviousTimecodeIsSet = true;
  }
  return static_cast<std::int64_t>(LocalTimecode * GlobalTimecodeScale()) + GlobalTimecode();
}

KaxBlockGroup & KaxCluster::GetNewBlock()
{
  auto & MyBlock = AddNewChild<KaxBlockGroup>(*this);
  MyBlock.SetParent(*this);
  return MyBlock;
}

void KaxCluster::ReleaseFrames()
{
  for (const auto& element : ElementList) {
    if (EbmlId(*element) == EBML_ID(KaxBlockGroup)) {
      static_cast<KaxBlockGroup *>(element)->ReleaseFrames();
    }
  }
}

std::uint64_t KaxCluster::GetPosition() const
{
  assert(ParentSegment);
  return ParentSegment->GetRelativePosition(*this);
}

} // namespace libmatroska
