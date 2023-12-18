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

namespace libmatroska {

KaxSegment::KaxSegment()
  :EbmlMaster(EBML_CLASS_SEMCONTEXT(KaxSegment))
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
