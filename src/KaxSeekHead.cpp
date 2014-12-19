/****************************************************************************
** libmatroska : parse Matroska files, see http://www.matroska.org/
**
** <file/class description>
**
** Copyright (C) 2002-2010 Steve Lhomme.  All rights reserved.
**
** This file is part of libmatroska.
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
  \version \$Id: KaxSeekHead.cpp 640 2004-07-09 21:05:36Z mosu $
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include "matroska/KaxSeekHead.h"
#include "matroska/KaxContexts.h"
#include "matroska/KaxSegment.h"
#include "matroska/KaxCues.h"
#include "matroska/KaxDefines.h"

using namespace LIBEBML_NAMESPACE;

// sub elements
START_LIBMATROSKA_NAMESPACE

/*!
  \todo verify that the element is not already in the list
*/
void KaxSeekHead::IndexThis(const EbmlElement & aElt, const KaxSegment & ParentSegment)
{
  // create a new point
  KaxSeek & aNewPoint = AddNewChild<KaxSeek>(*this);

  // add the informations to this element
  KaxSeekPosition & aNewPos = GetChild<KaxSeekPosition>(aNewPoint);
  *static_cast<EbmlUInteger *>(&aNewPos) = ParentSegment.GetRelativePosition(aElt);

  KaxSeekID & aNewID = GetChild<KaxSeekID>(aNewPoint);
  binary ID[4];
  ((const EbmlId&)aElt).Fill(ID);
  aNewID.CopyBuffer(ID, EBML_ID_LENGTH((const EbmlId&)aElt));
}

KaxSeek * KaxSeekHead::FindFirstOf(const EbmlCallbacks & Callbacks) const
{
  // parse all the Entries and find the first to match the type
  KaxSeek * aElt = static_cast<KaxSeek *>(FindFirstElt(EBML_INFO(KaxSeek)));
  while (aElt != NULL) {
    KaxSeekID * aId = NULL;
    EBML_MASTER_ITERATOR Itr;
    for (Itr = aElt->begin(); Itr != aElt->end(); ++Itr) {
      if (EbmlId(*(*Itr)) == EBML_ID(KaxSeekID)) {
        aId = static_cast<KaxSeekID*>(*Itr);
        EbmlId aEbmlId(aId->GetBuffer(), aId->GetSize());
        if (aEbmlId == EBML_INFO_ID(Callbacks)) {
          return aElt;
        }
        break;
      }
    }
    aElt = static_cast<KaxSeek *>(FindNextElt(*aElt));
  }

  return NULL;
}

KaxSeek * KaxSeekHead::FindNextOf(const KaxSeek &aPrev) const
{
  EBML_MASTER_CONST_ITERATOR Itr;
  KaxSeek *tmp;

  // look for the previous in the list
  for (Itr = begin(); Itr != end(); ++Itr) {
    if (*Itr == static_cast<const EbmlElement*>(&aPrev))
      break;
  }

  if (Itr != end()) {
    ++Itr;
    for (; Itr != end(); ++Itr) {
      if (EbmlId(*(*Itr)) == EBML_ID(KaxSeek)) {
        tmp = (KaxSeek *)(*Itr);
        if (tmp->IsEbmlId(aPrev))
          return tmp;
      }
    }
  }

  return NULL;
}

int64 KaxSeek::Location() const
{
  KaxSeekPosition *aPos = static_cast<KaxSeekPosition*>(FindFirstElt(EBML_INFO(KaxSeekPosition)));
  if (aPos == NULL)
    return 0;
  return uint64(*aPos);
}

bool KaxSeek::IsEbmlId(const EbmlId & aId) const
{
  KaxSeekID *_Id = static_cast<KaxSeekID*>(FindFirstElt(EBML_INFO(KaxSeekID)));
  if (_Id == NULL)
    return false;
  EbmlId aEbmlId(_Id->GetBuffer(), _Id->GetSize());
  return (aId == aEbmlId);
}

bool KaxSeek::IsEbmlId(const KaxSeek & aPoint) const
{
  KaxSeekID *_IdA = static_cast<KaxSeekID*>(FindFirstElt(EBML_INFO(KaxSeekID)));
  if (_IdA == NULL)
    return false;
  KaxSeekID *_IdB = static_cast<KaxSeekID*>(aPoint.FindFirstElt(EBML_INFO(KaxSeekID)));
  if (_IdB == NULL)
    return false;
  EbmlId aEbmlIdA(_IdA->GetBuffer(), _IdA->GetSize());
  EbmlId aEbmlIdB(_IdB->GetBuffer(), _IdB->GetSize());
  return (aEbmlIdA == aEbmlIdB);
}

END_LIBMATROSKA_NAMESPACE
