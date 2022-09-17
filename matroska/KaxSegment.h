/****************************************************************************
** libmatroska : parse Matroska files, see http://www.matroska.org/
**
** <file/class MATROSKA_DLL_API description>
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
  \version \$Id: KaxSegment.h,v 1.8 2004/04/14 23:26:17 robux4 Exp $
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_SEGMENT_H
#define LIBMATROSKA_SEGMENT_H

#include "matroska/KaxTypes.h"
#include "ebml/EbmlMaster.h"
#include "matroska/KaxDefines.h"

using namespace libebml;

namespace libmatroska {

DECLARE_MKX_MASTER_CONS(KaxSegment)
  public:
    /*!
      \brief give the position of the element in the segment
    */
    uint64 GetRelativePosition(const EbmlElement & Elt) const;
    uint64 GetRelativePosition(uint64 aGlobalPosition) const;

    /*!
      \brief give the position of the element in the file
    */
    uint64 GetGlobalPosition(uint64 aRelativePosition) const;
};

} // namespace libmatroska

#endif // LIBMATROSKA_SEGMENT_H
