// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include <cassert>

#include "matroska/KaxCues.h"
#include "matroska/KaxCuesData.h"
#include "matroska/KaxContexts.h"
#include <ebml/EbmlStream.h>
#include "matroska/KaxDefines.h"
#include "matroska/KaxSemantic.h"

using namespace libebml;

// sub elements
namespace libmatroska {

KaxCues::~KaxCues()
{
  assert(myTempReferences.empty()); // otherwise that means you have added references and forgot to set the position
}
/* deprecated and wrong
bool KaxCues::AddBlockGroup(const KaxBlockGroup & BlockRef)
{
  // Do not add the element if it's already present.
  std::vector<const KaxBlockBlob *>::iterator ListIdx;
  KaxBlockBlob *BlockReference = new KaxBlockBlob(BLOCK_BLOB_NO_SIMPLE);
  BlockReference->SetBlockGroup(*const_cast<KaxBlockGroup*>(&BlockRef));

  for (ListIdx = myTempReferences.begin(); ListIdx != myTempReferences.end(); ListIdx++)
    if (&(KaxBlockGroup&)*ListIdx == &BlockRef) {
      delete BlockReference;
      return true;
    }

  myTempReferences.push_back(BlockReference);
  return true;
}
*/
bool KaxCues::AddBlockBlob(const KaxBlockBlob & BlockReference)
{
  // Do not add the element if it's already present.
  const auto& pr = myTempReferences;
  const bool present = std::find(pr.begin(), pr.end(), &BlockReference) != pr.end();
  if (!present)
    myTempReferences.push_back(&BlockReference);

  return true;
}

void KaxCues::PositionSet(const KaxBlockBlob & BlockReference)
{
  // look for the element in the temporary references
  const auto& pr = myTempReferences;
  auto it = std::find(pr.begin(), pr.end(), &BlockReference);

  if (it != pr.end()) {
    // found, now add the element to the entry list
    auto & NewPoint = AddNewChild<KaxCuePoint>(*this);
    NewPoint.PositionSet(BlockReference, GlobalTimestampScale());
    myTempReferences.erase(it);
  }
}

void KaxCues::PositionSet(const KaxBlockGroup & BlockRef)
{
  // look for the element in the temporary references
  auto it = std::find_if(myTempReferences.begin(), myTempReferences.end(),
    [&](const KaxBlockBlob *myTempReference)
      { auto& refTmp = static_cast<KaxInternalBlock &>(*myTempReference);
        return refTmp.GlobalTimestamp() == BlockRef.GlobalTimestamp()
            && refTmp.TrackNum() == BlockRef.TrackNumber(); });

  if(it != myTempReferences.end()) {
    // found, now add the element to the entry list
    auto & NewPoint = AddNewChild<KaxCuePoint>(*this);
    NewPoint.PositionSet(**it, GlobalTimestampScale());
    myTempReferences.erase(it);
  }
}

/*!
  \warning Assume that the list has been sorted (Sort())
*/
const KaxCuePoint * KaxCues::GetTimestampPoint(std::uint64_t aTimestamp) const
{
  const std::uint64_t TimestampToLocate = aTimestamp / GlobalTimestampScale();
  const KaxCuePoint * aPointPrev = nullptr;
  std::uint64_t aPrevTime = 0;
  std::uint64_t aNextTime = 0xFFFFFFFFFFFFLL;

  for (const auto& e : *this) {
    if (EbmlId(*e) == EBML_ID(KaxCuePoint)) {
      auto tmp = static_cast<const KaxCuePoint *>(e);
      // check the tile
      auto aTime = static_cast<const KaxCueTime *>(tmp->FindFirstElt(EBML_INFO(KaxCueTime)));
      if (aTime) {
        auto _Time = static_cast<std::uint64_t>(*aTime);
        if (_Time > aPrevTime && _Time < TimestampToLocate) {
          aPrevTime = _Time;
          aPointPrev = tmp;
        }
        if (_Time < aNextTime && _Time > TimestampToLocate) {
          aNextTime= _Time;
        }
      }
    }
  }

  return aPointPrev;
}

std::uint64_t KaxCues::GetTimestampPosition(std::uint64_t aTimestamp) const
{
  const auto aPoint = GetTimestampPoint(aTimestamp);
  if (!aPoint)
    return 0;

  const auto aTrack = aPoint->GetSeekPosition();
  if (!aTrack)
    return 0;

  return aTrack->ClusterPosition();
}

} // namespace libmatroska
