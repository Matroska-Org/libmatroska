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
  \version \$Id: KaxCuesData.cpp 1265 2007-01-14 17:20:35Z mosu $
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

START_LIBMATROSKA_NAMESPACE

/*!
  \todo handle codec state checking
  \todo remove duplicate references (reference to 2 frames that each reference the same frame)
*/
void KaxCuePoint::PositionSet(const KaxBlockGroup & BlockReference, uint64 GlobalTimecodeScale)
{
  // fill me
  KaxCueTime & NewTime = GetChild<KaxCueTime>(*this);
  *static_cast<EbmlUInteger*>(&NewTime) = BlockReference.GlobalTimecode() / GlobalTimecodeScale;

  KaxCueTrackPositions & NewPositions = AddNewChild<KaxCueTrackPositions>(*this);
  KaxCueTrack & TheTrack = GetChild<KaxCueTrack>(NewPositions);
  *static_cast<EbmlUInteger*>(&TheTrack) = BlockReference.TrackNumber();

  KaxCueClusterPosition & TheClustPos = GetChild<KaxCueClusterPosition>(NewPositions);
  *static_cast<EbmlUInteger*>(&TheClustPos) = BlockReference.ClusterPosition();

#if MATROSKA_VERSION >= 2
  // handle reference use
  if (BlockReference.ReferenceCount() != 0) {
    unsigned int i;
    for (i=0; i<BlockReference.ReferenceCount(); i++) {
      KaxCueReference & NewRefs = AddNewChild<KaxCueReference>(NewPositions);
      NewRefs.AddReference(BlockReference.Reference(i).RefBlock(), GlobalTimecodeScale);
    }
  }

  KaxCodecState *CodecState = static_cast<KaxCodecState *>(BlockReference.FindFirstElt(EBML_INFO(KaxCodecState)));
  if (CodecState != NULL) {
    KaxCueCodecState &CueCodecState = AddNewChild<KaxCueCodecState>(NewPositions);
    *static_cast<EbmlUInteger*>(&CueCodecState) = BlockReference.GetParentCluster()->GetParentSegment()->GetRelativePosition(CodecState->GetElementPosition());
  }
#endif // MATROSKA_VERSION

  SetValueIsSet();
}

void KaxCuePoint::PositionSet(const KaxBlockBlob & BlobReference, uint64 GlobalTimecodeScale)
{
  const KaxInternalBlock &BlockReference = BlobReference;

  // fill me
  KaxCueTime & NewTime = GetChild<KaxCueTime>(*this);
  *static_cast<EbmlUInteger*>(&NewTime) = BlockReference.GlobalTimecode() / GlobalTimecodeScale;

  KaxCueTrackPositions & NewPositions = AddNewChild<KaxCueTrackPositions>(*this);
  KaxCueTrack & TheTrack = GetChild<KaxCueTrack>(NewPositions);
  *static_cast<EbmlUInteger*>(&TheTrack) = BlockReference.TrackNum();

  KaxCueClusterPosition & TheClustPos = GetChild<KaxCueClusterPosition>(NewPositions);
  *static_cast<EbmlUInteger*>(&TheClustPos) = BlockReference.ClusterPosition();

#if 0 // MATROSKA_VERSION >= 2
  // handle reference use
  if (BlockReference.ReferenceCount() != 0) {
    unsigned int i;
    for (i=0; i<BlockReference.ReferenceCount(); i++) {
      KaxCueReference & NewRefs = AddNewChild<KaxCueReference>(NewPositions);
      NewRefs.AddReference(BlockReference.Reference(i).RefBlock(), GlobalTimecodeScale);
    }
  }
#endif // MATROSKA_VERSION

#if MATROSKA_VERSION >= 2
  if (!BlobReference.IsSimpleBlock()) {
    const KaxBlockGroup &BlockGroup = BlobReference;
    const KaxCodecState *CodecState = static_cast<KaxCodecState *>(BlockGroup.FindFirstElt(EBML_INFO(KaxCodecState)));
    if (CodecState != NULL) {
      KaxCueCodecState &CueCodecState = AddNewChild<KaxCueCodecState>(NewPositions);
      *static_cast<EbmlUInteger*>(&CueCodecState) = BlockGroup.GetParentCluster()->GetParentSegment()->GetRelativePosition(CodecState->GetElementPosition());
    }
  }
#endif // MATROSKA_VERSION

  SetValueIsSet();
}

#if MATROSKA_VERSION >= 2
/*!
  \todo handle codec state checking
*/
void KaxCueReference::AddReference(const KaxBlockBlob & BlockReference, uint64 GlobalTimecodeScale)
{
  const KaxInternalBlock & theBlock = BlockReference;
  KaxCueRefTime & NewTime = GetChild<KaxCueRefTime>(*this);
  *static_cast<EbmlUInteger*>(&NewTime) = theBlock.GlobalTimecode() / GlobalTimecodeScale;

  KaxCueRefCluster & TheClustPos = GetChild<KaxCueRefCluster>(*this);
  *static_cast<EbmlUInteger*>(&TheClustPos) = theBlock.ClusterPosition();

#ifdef OLD
  // handle recursive reference use
  if (BlockReference.ReferenceCount() != 0) {
    unsigned int i;
    for (i=0; i<BlockReference.ReferenceCount(); i++) {
      AddReference(BlockReference.Reference(i).RefBlock());
    }
  }
#endif /* OLD */
}
#endif

bool KaxCuePoint::IsSmallerThan(const EbmlElement * EltB) const
{
  assert(EbmlId(*this) == EBML_ID(KaxCuePoint));
  assert(EbmlId(*EltB) == EBML_ID(KaxCuePoint));

  const KaxCuePoint & theEltB = *static_cast<const KaxCuePoint *>(EltB);

  // compare timecode
  const KaxCueTime * TimeCodeA = static_cast<const KaxCueTime *>(FindElt(EBML_INFO(KaxCueTime)));
  if (TimeCodeA == NULL)
    return false;

  const KaxCueTime * TimeCodeB = static_cast<const KaxCueTime *>(theEltB.FindElt(EBML_INFO(KaxCueTime)));
  if (TimeCodeB == NULL)
    return false;

  if (TimeCodeA->IsSmallerThan(TimeCodeB))
    return true;

  if (TimeCodeB->IsSmallerThan(TimeCodeA))
    return false;

  // compare tracks (timecodes are equal)
  const KaxCueTrack * TrackA = static_cast<const KaxCueTrack *>(FindElt(EBML_INFO(KaxCueTrack)));
  if (TrackA == NULL)
    return false;

  const KaxCueTrack * TrackB = static_cast<const KaxCueTrack *>(theEltB.FindElt(EBML_INFO(KaxCueTrack)));
  if (TrackB == NULL)
    return false;

  if (TrackA->IsSmallerThan(TrackB))
    return true;

  if (TrackB->IsSmallerThan(TrackA))
    return false;

  return false;
}

bool KaxCuePoint::Timecode(uint64 & aTimecode, uint64 GlobalTimecodeScale) const
{
  const KaxCueTime *aTime = static_cast<const KaxCueTime *>(FindFirstElt(EBML_INFO(KaxCueTime)));
  if (aTime == NULL)
    return false;
  aTimecode = uint64(*aTime) * GlobalTimecodeScale;
  return true;
}

/*!
  \brief return the position of the Cluster to load
*/
const KaxCueTrackPositions * KaxCuePoint::GetSeekPosition() const
{
  const KaxCueTrackPositions * result = NULL;
  uint64 aPosition = EBML_PRETTYLONGINT(0xFFFFFFFFFFFFFFF);
  // find the position of the "earlier" Cluster
  const KaxCueTrackPositions *aPoss = static_cast<const KaxCueTrackPositions *>(FindFirstElt(EBML_INFO(KaxCueTrackPositions)));
  while (aPoss != NULL) {
    const KaxCueClusterPosition *aPos = static_cast<const KaxCueClusterPosition *>(aPoss->FindFirstElt(EBML_INFO(KaxCueClusterPosition)));
    if (aPos != NULL && uint64(*aPos) < aPosition) {
      aPosition = uint64(*aPos);
      result = aPoss;
    }

    aPoss = static_cast<const KaxCueTrackPositions *>(FindNextElt(*aPoss));
  }
  return result;
}

uint64 KaxCueTrackPositions::ClusterPosition() const
{
  const KaxCueClusterPosition *aPos = static_cast<const KaxCueClusterPosition *>(FindFirstElt(EBML_INFO(KaxCueClusterPosition)));
  if (aPos == NULL)
    return 0;

  return uint64(*aPos);
}

uint16 KaxCueTrackPositions::TrackNumber() const
{
  const KaxCueTrack *aTrack = static_cast<const KaxCueTrack *>(FindFirstElt(EBML_INFO(KaxCueTrack)));
  if (aTrack == NULL)
    return 0;

  return uint16(*aTrack);
}


END_LIBMATROSKA_NAMESPACE
