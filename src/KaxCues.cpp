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
  \version \$Id: KaxCues.cpp 1265 2007-01-14 17:20:35Z mosu $
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include <cassert>

#include "matroska/KaxCues.h"
#include "matroska/KaxCuesData.h"
#include "matroska/KaxContexts.h"
#include "ebml/EbmlStream.h"
#include "matroska/KaxDefines.h"
#include "matroska/KaxSemantic.h"

// sub elements
START_LIBMATROSKA_NAMESPACE

KaxCues::~KaxCues()
{
  assert(myTempReferences.size() == 0); // otherwise that means you have added references and forgot to set the position
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
  std::vector<const KaxBlockBlob *>::iterator ListIdx;

  for (ListIdx = myTempReferences.begin(); ListIdx != myTempReferences.end(); ++ListIdx)
    if (*ListIdx == &BlockReference)
      return true;

  myTempReferences.push_back(&BlockReference);
  return true;
}

void KaxCues::PositionSet(const KaxBlockBlob & BlockReference)
{
  // look for the element in the temporary references
  std::vector<const KaxBlockBlob *>::iterator ListIdx;

  for (ListIdx = myTempReferences.begin(); ListIdx != myTempReferences.end(); ++ListIdx) {
    if (*ListIdx == &BlockReference) {
      // found, now add the element to the entry list
      KaxCuePoint & NewPoint = AddNewChild<KaxCuePoint>(*this);
      NewPoint.PositionSet(BlockReference, GlobalTimecodeScale());
      myTempReferences.erase(ListIdx);
      break;
    }
  }
}

void KaxCues::PositionSet(const KaxBlockGroup & BlockRef)
{
  // look for the element in the temporary references
  std::vector<const KaxBlockBlob *>::iterator ListIdx;

  for (ListIdx = myTempReferences.begin(); ListIdx != myTempReferences.end(); ++ListIdx) {
    const KaxInternalBlock &refTmp = **ListIdx;
    if (refTmp.GlobalTimecode() == BlockRef.GlobalTimecode() &&
        refTmp.TrackNum() == BlockRef.TrackNumber()) {
      // found, now add the element to the entry list
      KaxCuePoint & NewPoint = AddNewChild<KaxCuePoint>(*this);
      NewPoint.PositionSet(**ListIdx, GlobalTimecodeScale());
      myTempReferences.erase(ListIdx);
      break;
    }
  }
}

/*!
  \warning Assume that the list has been sorted (Sort())
*/
const KaxCuePoint * KaxCues::GetTimecodePoint(uint64 aTimecode) const
{
  uint64 TimecodeToLocate = aTimecode / GlobalTimecodeScale();
  const KaxCuePoint * aPointPrev = NULL;
  uint64 aPrevTime = 0;
  uint64 aNextTime = EBML_PRETTYLONGINT(0xFFFFFFFFFFFF);

  EBML_MASTER_CONST_ITERATOR Itr;
  for (Itr = begin(); Itr != end(); ++Itr) {
    if (EbmlId(*(*Itr)) == EBML_ID(KaxCuePoint)) {
      const KaxCuePoint *tmp = static_cast<const KaxCuePoint *>(*Itr);
      // check the tile
      const KaxCueTime *aTime = static_cast<const KaxCueTime *>(tmp->FindFirstElt(EBML_INFO(KaxCueTime)));
      if (aTime != NULL) {
        uint64 _Time = uint64(*aTime);
        if (_Time > aPrevTime && _Time < TimecodeToLocate) {
          aPrevTime = _Time;
          aPointPrev = tmp;
        }
        if (_Time < aNextTime && _Time > TimecodeToLocate) {
          aNextTime= _Time;
        }
      }
    }
  }

  return aPointPrev;
}

uint64 KaxCues::GetTimecodePosition(uint64 aTimecode) const
{
  const KaxCuePoint * aPoint = GetTimecodePoint(aTimecode);
  if (aPoint == NULL)
    return 0;

  const KaxCueTrackPositions * aTrack = aPoint->GetSeekPosition();
  if (aTrack == NULL)
    return 0;

  return aTrack->ClusterPosition();
}

END_LIBMATROSKA_NAMESPACE
