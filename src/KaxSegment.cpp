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
  \version \$Id: KaxSegment.cpp 1096 2005-03-17 09:14:52Z robux4 $
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include "matroska/KaxSegment.h"
#include "ebml/EbmlHead.h"

// sub elements
#include "matroska/KaxCluster.h"
#include "matroska/KaxSeekHead.h"
#include "matroska/KaxCues.h"
#include "matroska/KaxTracks.h"
#include "matroska/KaxContexts.h"
#include "matroska/KaxDefines.h"

START_LIBMATROSKA_NAMESPACE

KaxSegment::KaxSegment(EBML_EXTRA_DEF)
  :EbmlMaster(EBML_CLASS_SEMCONTEXT(KaxSegment) EBML_DEF_SEP EBML_EXTRA_CALL)
{
  SetSizeLength(5); // mandatory min size support (for easier updating) (2^(7*5)-2 = 32Go)
  SetSizeInfinite(); // by default a segment is big and the size is unknown in advance
}

KaxSegment::KaxSegment(const KaxSegment & ElementToClone)
  :EbmlMaster(ElementToClone)
{
  // update the parent of each children
  auto Itr = begin();
  while (Itr != end()) {
    if (EbmlId(**Itr) == EBML_ID(KaxCluster)) {
      static_cast<KaxCluster *>(*Itr)->SetParent(*this);
    }
    ++Itr;
  }
}


uint64 KaxSegment::GetRelativePosition(uint64 aGlobalPosition) const
{
  return aGlobalPosition - GetElementPosition() - HeadSize();
}

uint64 KaxSegment::GetRelativePosition(const EbmlElement & Elt) const
{
  return GetRelativePosition(Elt.GetElementPosition());
}

uint64 KaxSegment::GetGlobalPosition(uint64 aRelativePosition) const
{
  return aRelativePosition + GetElementPosition() + HeadSize();
}

END_LIBMATROSKA_NAMESPACE
