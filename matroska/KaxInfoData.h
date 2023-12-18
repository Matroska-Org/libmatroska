// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
  \author John Cannon      <spyder2555 @ users.sf.net>
  \author Moritz Bunkus    <moritz @ bunkus.org>
*/
#ifndef LIBMATROSKA_INFO_DATA_H
#define LIBMATROSKA_INFO_DATA_H

#include "matroska/KaxTypes.h"
#include <ebml/EbmlUInteger.h>
#include <ebml/EbmlFloat.h>
#include <ebml/EbmlUnicodeString.h>
#include <ebml/EbmlBinary.h>
#include <ebml/EbmlDate.h>
#include <ebml/EbmlMaster.h>
#include "matroska/KaxDefines.h"
#include "matroska/KaxSemantic.h"

using namespace libebml;

namespace libmatroska {

DECLARE_MKX_CONTEXT(KaxPrevUID)
class MATROSKA_DLL_API KaxPrevUID : public KaxSegmentUID {
  public:
    KaxPrevUID() = default;
    KaxPrevUID(const KaxPrevUID & ElementToClone) = default;
    bool ValidateSize() const override { return IsFiniteSize() && (GetSize() == 16);}

        EBML_CONCRETE_CLASS(KaxPrevUID)
};

DECLARE_MKX_CONTEXT(KaxNextUID)
class MATROSKA_DLL_API KaxNextUID : public KaxSegmentUID {
  public:
    KaxNextUID() = default;
    KaxNextUID(const KaxNextUID & ElementToClone) = default;
    bool ValidateSize() const override { return IsFiniteSize() && (GetSize() == 16);}

        EBML_CONCRETE_CLASS(KaxNextUID)
};

} // namespace libmatroska

#endif // LIBMATROSKA_INFO_DATA_H
