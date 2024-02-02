// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include "matroska/KaxSegment.h"
#include <ebml/EbmlHead.h>

// sub elements
#include "matroska/KaxCluster.h"
#include "matroska/KaxSeekHead.h"
#include "matroska/KaxCues.h"
#include "matroska/KaxTracks.h"
#include "matroska/KaxContexts.h"
#include "matroska/KaxDefines.h"

using namespace libebml;

namespace libmatroska {

KaxSegment::KaxSegment()
  :EbmlMaster(KaxSegment::ClassInfos)
{
  SetSizeLength(5); // mandatory min size support (for easier updating) (2^(7*5)-2 = 32Go)
  SetSizeInfinite(); // by default a segment is big and the size is unknown in advance
}

KaxSegment::KaxSegment(const KaxSegment & ElementToClone)
  :EbmlMaster(ElementToClone)
{
  // update the parent of each children
  for (const auto& child : *this)
    if (EbmlId(*child) == EBML_ID(KaxCluster))
      static_cast<KaxCluster *>(child)->SetParent(*this);
}

KaxSegment::~KaxSegment() = default;

std::uint64_t KaxSegment::GetRelativePosition(std::uint64_t aGlobalPosition) const
{
  return aGlobalPosition - GetElementPosition() - HeadSize();
}

std::uint64_t KaxSegment::GetRelativePosition(const EbmlElement & Elt) const
{
  return GetRelativePosition(Elt.GetElementPosition());
}

std::uint64_t KaxSegment::GetGlobalPosition(std::uint64_t aRelativePosition) const
{
  return aRelativePosition + GetElementPosition() + HeadSize();
}

} // namespace libmatroska
