// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include <cassert>

#include "matroska/KaxBlockData.h"
#include "matroska/KaxContexts.h"
#include "matroska/KaxBlock.h"
#include "matroska/KaxDefines.h"
#include "matroska/KaxSemantic.h"

using namespace libebml;

namespace libmatroska {

const KaxBlockBlob & KaxReferenceBlock::RefBlock() const
{
  assert(RefdBlock);
  return *RefdBlock;
}

KaxReferenceBlock::KaxReferenceBlock()
  :EbmlSInteger(KaxReferenceBlock::ClassInfos)
{
  bTimecodeSet = false;
}

KaxReferenceBlock::KaxReferenceBlock(const KaxReferenceBlock & ElementToClone)
  :EbmlSInteger(ElementToClone)
  ,bTimecodeSet(ElementToClone.bTimecodeSet)
{
}

KaxReferenceBlock::~KaxReferenceBlock()
{
  FreeBlob();
}

void KaxReferenceBlock::FreeBlob()
{
  if (bOurBlob && RefdBlock)
    delete RefdBlock;
  RefdBlock = nullptr;
}

filepos_t KaxReferenceBlock::UpdateSize(bool bSaveDefault, bool bForceRender)
{
  if (!bTimecodeSet) {
    assert(RefdBlock);
    assert(ParentBlock);

    auto &block = static_cast<KaxInternalBlock&>(*RefdBlock);
    SetValue(static_cast<std::int64_t>(block.GlobalTimecode()) - static_cast<std::int64_t>(ParentBlock->GlobalTimecode()) / static_cast<std::int64_t>(ParentBlock->GlobalTimecodeScale()));
  }
  return EbmlSInteger::UpdateSize(bSaveDefault, bForceRender);
}

void KaxReferenceBlock::SetReferencedBlock(const KaxBlockBlob * aRefdBlock)
{
  assert(!RefdBlock);
  assert(aRefdBlock);
  FreeBlob();
  RefdBlock = aRefdBlock;
  bOurBlob = true;
  SetValueIsSet();
}

void KaxReferenceBlock::SetReferencedBlock(const KaxBlockGroup & aRefdBlock)
{
  FreeBlob();
  auto block_blob = new KaxBlockBlob(BLOCK_BLOB_NO_SIMPLE);
  block_blob->SetBlockGroup(*const_cast<KaxBlockGroup*>(&aRefdBlock));
  RefdBlock = block_blob;
  bOurBlob = true;
  SetValueIsSet();
}

} // namespace libmatroska
