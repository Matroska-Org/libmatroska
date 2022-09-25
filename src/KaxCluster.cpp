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
  \version \$Id: KaxCluster.cpp 1228 2005-10-14 19:36:51Z robux4 $
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
  auto Itr = begin();
  while (Itr != end()) {
    if (EbmlId(**Itr) == EBML_ID(KaxBlockGroup)) {
      static_cast<KaxBlockGroup   *>(*Itr)->SetParent(*this);
    } else if (EbmlId(**Itr) == EBML_ID(KaxBlock)) {
      static_cast<KaxBlock        *>(*Itr)->SetParent(*this);
    } else if (EbmlId(**Itr) == EBML_ID(KaxBlockVirtual)) {
      static_cast<KaxBlockVirtual *>(*Itr)->SetParent(*this);
    }
    ++Itr;
  }
}

bool KaxCluster::AddBlockBlob(KaxBlockBlob * NewBlob)
{
  Blobs.push_back(NewBlob);
  return true;
}

bool KaxCluster::AddFrameInternal(const KaxTrackEntry & track, uint64 timecode, DataBuffer & buffer, KaxBlockGroup * & MyNewBlock, const KaxBlockGroup * PastBlock, const KaxBlockGroup * ForwBlock, LacingType lacing)
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
  if (currentNewBlock == nullptr || static_cast<uint32>(track.TrackNumber()) != static_cast<uint32>(currentNewBlock->TrackNumber()) || PastBlock != nullptr || ForwBlock != nullptr) {
    KaxBlockGroup & aNewBlock = GetNewBlock();
    MyNewBlock = currentNewBlock = &aNewBlock;
  }

  if (PastBlock != nullptr) {
    if (ForwBlock != nullptr) {
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

bool KaxCluster::AddFrame(const KaxTrackEntry & track, uint64 timecode, DataBuffer & buffer, KaxBlockGroup * & MyNewBlock, LacingType lacing)
{
  assert(Blobs.empty()); // mutually exclusive for the moment
  return AddFrameInternal(track, timecode, buffer, MyNewBlock, nullptr, nullptr, lacing);
}

bool KaxCluster::AddFrame(const KaxTrackEntry & track, uint64 timecode, DataBuffer & buffer, KaxBlockGroup * & MyNewBlock, const KaxBlockGroup & PastBlock, LacingType lacing)
{
  assert(Blobs.empty()); // mutually exclusive for the moment
  return AddFrameInternal(track, timecode, buffer, MyNewBlock, &PastBlock, nullptr, lacing);
}

bool KaxCluster::AddFrame(const KaxTrackEntry & track, uint64 timecode, DataBuffer & buffer, KaxBlockGroup * & MyNewBlock, const KaxBlockGroup & PastBlock, const KaxBlockGroup & ForwBlock, LacingType lacing)
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
  size_t Index;

  // update the Timecode of the Cluster before writing
  auto Timecode = static_cast<KaxClusterTimecode *>(this->FindElt(EBML_INFO(KaxClusterTimecode)));
  *static_cast<EbmlUInteger *>(Timecode) = GlobalTimecode() / GlobalTimecodeScale();

  if (Blobs.empty()) {
    // old-school direct KaxBlockGroup

    // SilentTracks handling
    // check the parent cluster for existing tracks and see if they are contained in this cluster or not
    if (bSilentTracksUsed) {
      auto MyTracks = static_cast<KaxTracks *>(ParentSegment->FindElt(EBML_INFO(KaxTracks)));
      for (auto&& Trk : *MyTracks) {
        if (EbmlId(*Trk) == EBML_ID(KaxTrackEntry)) {
          auto entry = static_cast<KaxTrackEntry *>(Trk);
          auto tracknum = static_cast<uint32>(entry->TrackNumber());
          auto track = std::find_if(ElementList.begin(), ElementList.end(), [=](EbmlElement *element)
              { return EbmlId(*element) == EBML_ID(KaxBlockGroup) && static_cast<KaxBlockGroup *>(element)->TrackNumber() == tracknum;  });
          // the track wasn't found in this cluster
          if (track == ElementList.end()) {
            auto SilentTracks = static_cast<KaxClusterSilentTracks *>(this->FindFirstElt(EBML_INFO(KaxClusterSilentTracks)));
            assert(SilentTracks != nullptr); // the flag bSilentTracksUsed should be set when creating the Cluster
            auto trackelt = static_cast<KaxClusterSilentTrackNumber *>(SilentTracks->AddNewElt(EBML_INFO(KaxClusterSilentTrackNumber)));
            *static_cast<EbmlUInteger *>(trackelt) = tracknum;
          }
        }
      }
    }

    Result = EbmlMaster::Render(output, bSaveDefault);
    // For all Blocks add their position on the CueEntry

    for (auto&& element : ElementList) {
      if (EbmlId(*element) == EBML_ID(KaxBlockGroup)) {
        CueToUpdate.PositionSet(*static_cast<const KaxBlockGroup *>(element));
      }
    }
  } else {
    // new school, using KaxBlockBlob
    for (Index = 0; Index<Blobs.size(); Index++) {
      if (Blobs[Index]->IsSimpleBlock())
        PushElement( static_cast<KaxSimpleBlock&>(*Blobs[Index]));
      else
        PushElement( static_cast<KaxBlockGroup&>(*Blobs[Index]));
    }

    // SilentTracks handling
    // check the parent cluster for existing tracks and see if they are contained in this cluster or not
    if (bSilentTracksUsed) {
      auto MyTracks = static_cast<KaxTracks *>(ParentSegment->FindElt(EBML_INFO(KaxTracks)));
      for (auto&& Trk : *MyTracks) {
        if (EbmlId(*Trk) == EBML_ID(KaxTrackEntry)) {
          auto entry = static_cast<KaxTrackEntry *>(Trk);
          auto tracknum = static_cast<uint32>(entry->TrackNumber());
          for (Index = 0; Index<Blobs.size(); Index++) {
            if (static_cast<KaxInternalBlock&>(*Blobs[Index]).TrackNum() == tracknum)
              break; // this track is used
          }
          // the track wasn't found in this cluster
          if (Index == ListSize()) {
            auto SilentTracks = static_cast<KaxClusterSilentTracks *>(this->FindFirstElt(EBML_INFO(KaxClusterSilentTracks)));
            assert(SilentTracks != nullptr); // the flag bSilentTracksUsed should be set when creating the Cluster
            auto trackelt = static_cast<KaxClusterSilentTrackNumber *>(SilentTracks->AddNewElt(EBML_INFO(KaxClusterSilentTrackNumber)));
            *static_cast<EbmlUInteger *>(trackelt) = tracknum;
          }
        }
      }
    }

    Result = EbmlMaster::Render(output, bSaveDefault);

    // For all Blocks add their position on the CueEntry
    for (Index = 0; Index<Blobs.size(); Index++) {
      CueToUpdate.PositionSet(*Blobs[Index]);
    }

    Blobs.clear();
  }

  return Result;
}

/*!
  \todo automatically choose valid timecode for the Cluster based on the previous cluster timecode (must be incremental)
*/
uint64 KaxCluster::GlobalTimecode() const
{
  assert(bPreviousTimecodeIsSet);
  uint64 result = MinTimecode;

  if (result < PreviousTimecode)
    result = PreviousTimecode + 1;

  return result;
}

/*!
  \brief retrieve the relative
  \todo !!! We need a way to know the TimecodeScale
*/
int16 KaxCluster::GetBlockLocalTimecode(uint64 aGlobalTimecode) const
{
  const int64 TimecodeDelay = (static_cast<int64>(aGlobalTimecode) - static_cast<int64>(GlobalTimecode())) / static_cast<int64>(GlobalTimecodeScale());
  assert(TimecodeDelay >= int16(0x8000) && TimecodeDelay <= int16(0x7FFF));
  return static_cast<int16>(TimecodeDelay);
}

uint64 KaxCluster::GetBlockGlobalTimecode(int16 LocalTimecode)
{
  if (!bFirstFrameInside) {
    auto Timecode = static_cast<KaxClusterTimecode *>(this->FindElt(EBML_INFO(KaxClusterTimecode)));
    assert (bFirstFrameInside); // use the InitTimecode() hack for now
    MinTimecode = MaxTimecode = PreviousTimecode = static_cast<uint64>(*static_cast<EbmlUInteger *>(Timecode));
    bFirstFrameInside = true;
    bPreviousTimecodeIsSet = true;
  }
  return static_cast<int64>(LocalTimecode * GlobalTimecodeScale()) + GlobalTimecode();
}

KaxBlockGroup & KaxCluster::GetNewBlock()
{
  auto & MyBlock = AddNewChild<KaxBlockGroup>(*this);
  MyBlock.SetParent(*this);
  return MyBlock;
}

void KaxCluster::ReleaseFrames()
{
  for (auto&& element : ElementList) {
    if (EbmlId(*element) == EBML_ID(KaxBlockGroup)) {
      static_cast<KaxBlockGroup *>(element)->ReleaseFrames();
    }
  }
}

uint64 KaxCluster::GetPosition() const
{
  assert(ParentSegment != nullptr);
  return ParentSegment->GetRelativePosition(*this);
}

} // namespace libmatroska
