// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include "matroska/KaxSeekHead.h"
#include "matroska/KaxContexts.h"
#include "matroska/KaxSegment.h"
#include "matroska/KaxCues.h"
#include "matroska/KaxDefines.h"

using namespace libebml;

// sub elements
namespace libmatroska {

/*!
  \todo verify that the element is not already in the list
*/
KaxSeek * KaxSeekHead::IndexThis(const EbmlElement & aElt, const KaxSegment & ParentSegment)
{
  // create a new point
  auto & aNewPoint = AddNewChild<KaxSeek>(*this);

  // add the informations to this element
  auto & aNewPos = GetChild<KaxSeekPosition>(aNewPoint);
  static_cast<EbmlUInteger &>(aNewPos) = ParentSegment.GetRelativePosition(aElt);

  auto & aNewID = GetChild<KaxSeekID>(aNewPoint);
  binary ID[4];
  static_cast<const EbmlId&>(aElt).Fill(ID);
  aNewID.CopyBuffer(ID, EBML_ID_LENGTH((const EbmlId&)aElt));

  return &aNewPoint;
}

KaxSeek * KaxSeekHead::FindFirstOf(const EbmlCallbacks & Callbacks) const
{
  // parse all the Entries and find the first to match the type
  auto aElt = static_cast<KaxSeek *>(FindFirstElt(EBML_INFO(KaxSeek)));
  while (aElt) {
    auto it = std::find_if(aElt->begin(), aElt->end(), [&](auto Elt)
      { return (EbmlId(*Elt) == EBML_ID(KaxSeekID)); });
    if (it != aElt->end()) {
      const auto aId = static_cast<KaxSeekID*>(*it);
      const auto aEbmlId = EbmlId(aId->GetBuffer(), aId->GetSize());
      if (aEbmlId == EBML_INFO_ID(Callbacks)) {
        return aElt;
      }
    }
    aElt = static_cast<KaxSeek *>(FindNextElt(*aElt));
  }

  return nullptr;
}

KaxSeek * KaxSeekHead::FindNextOf(const KaxSeek &aPrev) const
{
  // look for the previous in the list
  auto it = std::find(this->begin(), this->end(), static_cast<const EbmlElement*>(&aPrev));
  if (it == this->end())
    return nullptr;

  auto it2 = std::find_if(it + 1, this->end(), [&](auto e)
      { return (EbmlId(*(*it)) == EBML_ID(KaxSeek)) && static_cast<KaxSeek *>(e)->IsEbmlId(aPrev); });
  if (it2 == this->end())
    return nullptr;

  return static_cast<KaxSeek*>(*it2);
}

std::int64_t KaxSeek::Location() const
{
  auto aPos = static_cast<KaxSeekPosition*>(FindFirstElt(EBML_INFO(KaxSeekPosition)));
  if (!aPos)
    return 0;
  return static_cast<std::uint64_t>(*aPos);
}

bool KaxSeek::IsEbmlId(const EbmlId & aId) const
{
  auto _Id = static_cast<KaxSeekID*>(FindFirstElt(EBML_INFO(KaxSeekID)));
  if (!_Id)
    return false;
  const auto aEbmlId = EbmlId(_Id->GetBuffer(), _Id->GetSize());
  return (aId == aEbmlId);
}

bool KaxSeek::IsEbmlId(const KaxSeek & aPoint) const
{
  auto _IdA = static_cast<KaxSeekID*>(FindFirstElt(EBML_INFO(KaxSeekID)));
  if (!_IdA)
    return false;
  auto _IdB = static_cast<KaxSeekID*>(aPoint.FindFirstElt(EBML_INFO(KaxSeekID)));
  if (!_IdB)
    return false;
  const auto aEbmlIdA = EbmlId(_IdA->GetBuffer(), _IdA->GetSize());
  const auto aEbmlIdB = EbmlId(_IdB->GetBuffer(), _IdB->GetSize());
  return aEbmlIdA == aEbmlIdB;
}

} // namespace libmatroska
