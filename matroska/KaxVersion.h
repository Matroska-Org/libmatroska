// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_VERSION_H
#define LIBMATROSKA_VERSION_H

#include <string>

#include <ebml/EbmlConfig.h>
#include "matroska/KaxConfig.h"

namespace libmatroska {

#define LIBMATROSKA_VERSION 0x020000

extern const MATROSKA_DLL_API std::string KaxCodeVersion;

/*!
  \todo Improve the CRC/ECC system (backward and forward possible ?) to fit streaming/live writing/simple reading
*/

} // namespace libmatroska

#endif // LIBMATROSKA_VERSION_H
