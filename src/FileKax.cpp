/****************************************************************************
** libmatroska : parse Matroska files, see http://www.matroska.org/
**
** <file/class description>
**
** Copyright (C) 2002-2003 Steve Lhomme.  All rights reserved.
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
//#include "StdInclude.h"
#include "matroska/FileKax.h"
#include <ebml/EbmlVersion.h>
#include <ebml/EbmlContexts.h>
//#include "Cluster.h"
//#include "Track.h"
//#include "Block.h"
//#include "Frame.h"
//#include "Version.h"

namespace libmatroska {

//typedef Track *TrackID;

FileMatroska::FileMatroska(IOCallback & output)
  :myFile(output)
{
}

/* FileMatroska::~FileMatroska()
{
  //  if (myCurrCluster != NULL)
  //    throw 0; // there are some data left to write
  //  if (myCurrReadCluster != NULL || myCurrReadBlock != NULL)
  //    throw 0; // there are some data left to write
} */

} // namespace libmatroska

void matroska_init()
{
#if defined(HAVE_EBML2) || defined(HAS_EBML2)
  ebml_init();
#endif
}

void matroska_done()
{
#if defined(HAVE_EBML2) || defined(HAS_EBML2)
  ebml_done();
#endif
}
