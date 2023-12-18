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
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_CUES_DATA_H
#define LIBMATROSKA_CUES_DATA_H

#include "matroska/KaxTypes.h"
#include <ebml/EbmlUInteger.h>
#include <ebml/EbmlMaster.h>
#include "matroska/KaxDefines.h"

using namespace libebml;

namespace libmatroska {

class KaxBlockGroup;
class KaxBlockBlob;
class KaxCueTrackPositions;
class KaxInternalBlock;
class KaxSimpleBlock;

DECLARE_MKX_MASTER(KaxCuePoint)
  public:
    void PositionSet(const KaxBlockGroup & BlockReference, std::uint64_t GlobalTimecodeScale);
    void PositionSet(const KaxBlockBlob & BlobReference, std::uint64_t GlobalTimecodeScale);
    void PositionSet(const KaxSimpleBlock & BlockReference, std::uint64_t GlobalTimecodeScale);
    void PositionSet(const KaxInternalBlock & BlockReference, const KaxBlockGroup *BlockGroup, std::uint64_t GlobalTimecodeScale);

    bool IsSmallerThan(const EbmlElement *Cmp) const override;

    const KaxCueTrackPositions * GetSeekPosition() const;
    bool Timecode(std::uint64_t & aTimecode, std::uint64_t GlobalTimecodeScale) const;
};

DECLARE_MKX_MASTER(KaxCueTrackPositions)
  public:
    std::uint64_t ClusterPosition() const;
    std::uint16_t TrackNumber() const;
};

DECLARE_MKX_MASTER(KaxCueReference)
  public:
    void AddReference(const KaxBlockGroup & BlockReferenced, std::uint64_t GlobalTimecodeScale);
    void AddReference(const KaxBlockBlob & BlockReferenced, std::uint64_t GlobalTimecodeScale);
};

} // namespace libmatroska

#endif // LIBMATROSKA_CUES_DATA_H
