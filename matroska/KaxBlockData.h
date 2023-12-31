// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_BLOCK_ADDITIONAL_H
#define LIBMATROSKA_BLOCK_ADDITIONAL_H

#include "matroska/KaxTypes.h"
#include <ebml/EbmlMaster.h>
#include <ebml/EbmlUInteger.h>
#include <ebml/EbmlSInteger.h>
#include "matroska/KaxDefines.h"
#include "matroska/KaxBlock.h"

namespace libmatroska {

/*!
  \brief element used for B frame-likes
*/
DECLARE_MKX_SINTEGER_CONS(KaxReferenceBlock)
  public:
        ~KaxReferenceBlock() override;
    /*!
      \brief override this method to compute the timestamp value
    */
    libebml::filepos_t UpdateSize(ShouldWrite writeFilter = WriteSkipDefault, bool bForceRender = false) override;

    const KaxBlockBlob & RefBlock() const;
    void SetReferencedBlock(const KaxBlockBlob * aRefdBlock);
    void SetReferencedBlock(const KaxBlockGroup & aRefdBlock);
    void SetParentBlock(const KaxBlockGroup & aParentBlock) {ParentBlock = &aParentBlock;}
    void SetReferencedTimecode(std::int64_t refTimestamp) { SetValue(refTimestamp); bTimestampSet = true;};

  protected:
    const KaxBlockBlob * RefdBlock{nullptr};
    const KaxBlockGroup * ParentBlock{nullptr};
    bool bTimestampSet{false};
        bool bOurBlob{false};
        void FreeBlob();
};

} // namespace libmatroska

#endif // LIBMATROSKA_BLOCK_ADDITIONAL_H
