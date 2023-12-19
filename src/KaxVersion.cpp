// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/

#include "matroska/KaxVersion.h"

namespace libmatroska {

const std::string KaxCodeVersion = "2.0.0";

// Up to version 1.4.4 this library exported a build date string. As
// this made the build non-reproducible, replace it by a placeholder to
// remain binary compatible.
const std::string KaxCodeDate = "Unknown";

} // namespace libmatroska
