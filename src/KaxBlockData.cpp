/****************************************************************************
** libmatroska : parse Matroska files, see http://www.matroska.org/
**
** <file/class description>
**
** Copyright (C) 2002-2010 Steve Lhomme.  All rights reserved.
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

KaxReferenceBlock::KaxReferenceBlock(EBML_EXTRA_DEF)
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
