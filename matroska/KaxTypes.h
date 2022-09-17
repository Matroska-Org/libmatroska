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
  \version \$Id: KaxTypes.h,v 1.4 2004/04/14 23:26:17 robux4 Exp $
*/
#ifndef LIBMATROSKA_TYPES_H
#define LIBMATROSKA_TYPES_H

#include "matroska/KaxConfig.h"
#include "ebml/EbmlTypes.h"
#include "matroska/c/libmatroska_t.h"

namespace libmatroska {

enum LacingType {
  LACING_NONE = 0,
  LACING_XIPH,
  LACING_FIXED,
  LACING_EBML,
  LACING_AUTO
};

enum BlockBlobType {
  BLOCK_BLOB_NO_SIMPLE = 0,
  BLOCK_BLOB_SIMPLE_AUTO,
  BLOCK_BLOB_ALWAYS_SIMPLE,
};

} // namespace libmatroska

#endif // LIBMATROSKA_TYPES_H
