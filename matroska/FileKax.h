// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_FILE_H
#define LIBMATROSKA_FILE_H

//#include <vector>

#include "matroska/KaxConfig.h"
#include <ebml/IOCallback.h>
//#include "MainHeader.h"
//#include "TrackType.h"
//#include "StreamInfo.h"
//#include "Cluster.h"
//#include "CodecHeader.h"

namespace libmatroska {

//class Track;
//class Frame;

/*!
    \class MATROSKA_DLL_API FileMatroska
    \brief General container of all the parameters and data of an Matroska file
    \todo Handle the filename and next filename
    \todo Handle the IOCallback selection/type
*/
class MATROSKA_DLL_API FileMatroska {
    public:
    FileMatroska(libebml::IOCallback & output);
    ~FileMatroska() = default;
    libebml::IOCallback & myFile;

};

} // namespace libmatroska

#endif // FILE_KAX_HPP
