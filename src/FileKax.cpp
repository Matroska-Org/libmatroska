// Copyright © 2002-2003 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

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
