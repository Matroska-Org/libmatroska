// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_CONTEXTS_H
#define LIBMATROSKA_CONTEXTS_H

#include "matroska/KaxConfig.h"
#include <ebml/EbmlElement.h>

namespace libmatroska {

extern const libebml::EbmlSemanticContextMaster MATROSKA_DLL_API Context_KaxMatroska;

extern MATROSKA_DLL_API const libebml::EbmlSemanticContextMaster & GetKaxGlobal_Context();

} // namespace libmatroska

#endif // LIBMATROSKA_CONTEXTS_H
