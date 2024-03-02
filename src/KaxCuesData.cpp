// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include <cassert>

#include "matroska/KaxCuesData.h"
#include "matroska/KaxContexts.h"
#include "matroska/KaxBlock.h"
#include "matroska/KaxBlockData.h"
#include "matroska/KaxCluster.h"
#include "matroska/KaxSegment.h"
#include "matroska/KaxDefines.h"
#include "matroska/KaxSemantic.h"

using namespace libebml;

namespace libmatroska {

/*!
  \todo handle codec state checking
  \todo remove duplicate references (reference to 2 frames that each reference the same frame)
*/
void KaxCuePoint::PositionSet(const KaxBlockGroup & BlockReference, std::uint64_t GlobalTimestampScale)
{
  // fill me
  auto & NewTime = GetChild<KaxCueTime>(*this);
  NewTime.SetValue(BlockReference.GlobalTimestamp() / GlobalTimestampScale);

  auto & NewPositions = AddNewChild<KaxCueTrackPositions>(*this);
  auto & TheTrack = GetChild<KaxCueTrack>(NewPositions);
  TheTrack.SetValue(BlockReference.TrackNumber());

  auto & TheClustPos = GetChild<KaxCueClusterPosition>(NewPositions);
  TheClustPos.SetValue(BlockReference.ClusterPosition());

  // handle reference use
  if (BlockReference.ReferenceCount() != 0) {
    for (unsigned int i=0; i<BlockReference.ReferenceCount(); i++) {
      auto & NewRefs = AddNewChild<KaxCueReference>(NewPositions);
      NewRefs.AddReference(BlockReference.Reference(i).RefBlock(), GlobalTimestampScale);
    }
  }

  auto CodecState = static_cast<KaxCodecState *>(BlockReference.FindFirstElt(EBML_INFO(KaxCodecState)));
  if (CodecState) {
    auto &CueCodecState = AddNewChild<KaxCueCodecState>(NewPositions);
    CueCodecState.SetValue(BlockReference.GetParentCluster()->GetParentSegment()->GetRelativePosition(CodecState->GetElementPosition()));
  }

  SetValueIsSet();
}

void KaxCuePoint::PositionSet(const KaxBlockBlob & BlobReference, std::uint64_t GlobalTimestampScale)
{
  auto &BlockReference = static_cast<KaxInternalBlock&>(BlobReference);
  const KaxBlockGroup *BlockGroupPointer = nullptr;

  if (!BlobReference.IsSimpleBlock()) {
    auto &BlockGroup = static_cast<KaxBlockGroup&>(BlobReference);
    BlockGroupPointer = &BlockGroup;
  }
  PositionSet(BlockReference, BlockGroupPointer, GlobalTimestampScale);
}

void KaxCuePoint::PositionSet(const KaxSimpleBlock & BlockReference, std::uint64_t GlobalTimestampScale)
{
  PositionSet(BlockReference, nullptr, GlobalTimestampScale);
}

void KaxCuePoint::PositionSet(const KaxInternalBlock & BlockReference, const KaxBlockGroup *BlockGroup, std::uint64_t GlobalTimestampScale)
{
  // fill me
  auto & NewTime = GetChild<KaxCueTime>(*this);
  NewTime.SetValue(BlockReference.GlobalTimestamp() / GlobalTimestampScale);

  auto & NewPositions = AddNewChild<KaxCueTrackPositions>(*this);
  auto & TheTrack = GetChild<KaxCueTrack>(NewPositions);
  TheTrack.SetValue(BlockReference.TrackNum());

  auto & TheClustPos = GetChild<KaxCueClusterPosition>(NewPositions);
  TheClustPos.SetValue(BlockReference.ClusterPosition());

#if 0 // MATROSKA_VERSION >= 2
  // handle reference use
  if (BlockReference.ReferenceCount() != 0) {
    unsigned int i;
    for (i=0; i<BlockReference.ReferenceCount(); i++) {
      KaxCueReference & NewRefs = AddNewChild<KaxCueReference>(NewPositions);
      NewRefs.AddReference(BlockReference.Reference(i).RefBlock(), GlobalTimestampScale);
    }
  }
#endif // MATROSKA_VERSION

  if (BlockGroup) {
    const auto CodecState = static_cast<const KaxCodecState *>(BlockGroup->FindFirstElt(EBML_INFO(KaxCodecState)));
    if (CodecState) {
      auto &CueCodecState = AddNewChild<KaxCueCodecState>(NewPositions);
      CueCodecState.SetValue(BlockGroup->GetParentCluster()->GetParentSegment()->GetRelativePosition(CodecState->GetElementPosition()));
    }
  }

  SetValueIsSet();
}

/*!
  \todo handle codec state checking
*/
void KaxCueReference::AddReference(const KaxBlockBlob & BlockReference, std::uint64_t GlobalTimestampScale)
{
  auto& theBlock = static_cast<KaxInternalBlock&>(BlockReference);
  auto& NewTime = GetChild<KaxCueRefTime>(*this);
  NewTime.SetValue(theBlock.GlobalTimestamp() / GlobalTimestampScale);

  auto & TheClustPos = GetChild<KaxCueRefCluster>(*this);
  TheClustPos.SetValue(theBlock.ClusterPosition());
}

bool KaxCuePoint::IsSmallerThan(const EbmlElement * Cmp) const
{
  assert(EbmlId(*this) == EBML_ID(KaxCuePoint));
  assert(EbmlId(*Cmp)  == EBML_ID(KaxCuePoint));

  auto theCmp = static_cast<const KaxCuePoint *>(Cmp);

  // compare timestamp
  auto TimestampA = static_cast<const KaxCueTime *>(FindElt(EBML_INFO(KaxCueTime)));
  if (!TimestampA)
    return false;

  auto TimestampB = static_cast<const KaxCueTime *>(theCmp->FindElt(EBML_INFO(KaxCueTime)));
  if (!TimestampB)
    return false;

  if (TimestampA->IsSmallerThan(TimestampB))
    return true;

  if (TimestampB->IsSmallerThan(TimestampA))
    return false;

  // compare tracks (timestamp are equal)
  const auto TrackA = static_cast<const KaxCueTrack *>(FindElt(EBML_INFO(KaxCueTrack)));
  if (!TrackA)
    return false;

  const auto TrackB = static_cast<const KaxCueTrack *>(theCmp->FindElt(EBML_INFO(KaxCueTrack)));
  if (!TrackB)
    return false;

  if (TrackA->IsSmallerThan(TrackB))
    return true;

  if (TrackB->IsSmallerThan(TrackA))
    return false;

  return false;
}

bool KaxCuePoint::Timestamp(std::uint64_t & aTimestamp, std::uint64_t GlobalTimestampScale) const
{
  const auto aTime = static_cast<const KaxCueTime *>(FindFirstElt(EBML_INFO(KaxCueTime)));
  if (!aTime)
    return false;
  aTimestamp = static_cast<std::uint64_t>(*aTime) * GlobalTimestampScale;
  return true;
}

/*!
  \brief return the position of the Cluster to load
*/
const KaxCueTrackPositions * KaxCuePoint::GetSeekPosition() const
{
  const KaxCueTrackPositions * result = nullptr;
  std::uint64_t aPosition = 0xFFFFFFFFFFFFFFFLL;
  // find the position of the "earlier" Cluster
  auto aPoss = static_cast<const KaxCueTrackPositions *>(FindFirstElt(EBML_INFO(KaxCueTrackPositions)));
  while (aPoss) {
    auto aPos = static_cast<const KaxCueClusterPosition *>(aPoss->FindFirstElt(EBML_INFO(KaxCueClusterPosition)));
    if (aPos && static_cast<std::uint64_t>(*aPos) < aPosition) {
      aPosition = static_cast<std::uint64_t>(*aPos);
      result = aPoss;
    }

    aPoss = static_cast<const KaxCueTrackPositions *>(FindNextElt(*aPoss));
  }
  return result;
}

std::uint64_t KaxCueTrackPositions::ClusterPosition() const
{
  const auto aPos = static_cast<const KaxCueClusterPosition *>(FindFirstElt(EBML_INFO(KaxCueClusterPosition)));
  if (!aPos)
    return 0;

  return static_cast<std::uint64_t>(*aPos);
}

std::uint16_t KaxCueTrackPositions::TrackNumber() const
{
  const auto aTrack = static_cast<const KaxCueTrack *>(FindFirstElt(EBML_INFO(KaxCueTrack)));
  if (!aTrack)
    return 0;

  return static_cast<std::uint16_t>(*aTrack);
}


} // namespace libmatroska
