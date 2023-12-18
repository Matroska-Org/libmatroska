// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
  \author Moritz Bunkus <moritz @ bunkus.org>
*/
#ifndef LIBMATROSKA_CONFIG_H
#define LIBMATROSKA_CONFIG_H

#define LIBMATROSKA_NAMESPACE       libmatroska
#define START_LIBMATROSKA_NAMESPACE namespace LIBMATROSKA_NAMESPACE {
#define END_LIBMATROSKA_NAMESPACE   }

#include "matroska_export.h"

#if defined(MATROSKA_VERSION) && MATROSKA_VERSION < 2
#error MATROSKA_VERSION <= 2 no longer supported, update your code accordingly
#endif // MATROSKA_VERSION


#endif // LIBMATROSKA_CONFIG_H
