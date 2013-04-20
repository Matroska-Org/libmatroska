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
	\version \$Id: KaxBlockData.h,v 1.10 2004/04/14 23:26:17 robux4 Exp $
	\author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_BLOCK_ADDITIONAL_H
#define LIBMATROSKA_BLOCK_ADDITIONAL_H

#include "matroska/KaxTypes.h"
#include "ebml/EbmlMaster.h"
#include "ebml/EbmlUInteger.h"
#include "ebml/EbmlSInteger.h"
#include "matroska/KaxDefines.h"
#include "matroska/KaxBlock.h"

using namespace LIBEBML_NAMESPACE;

START_LIBMATROSKA_NAMESPACE

/*!
	\brief element used for B frame-likes
*/
DECLARE_MKX_SINTEGER_CONS(KaxReferenceBlock)
	public:
        ~KaxReferenceBlock();
		/*!
			\brief override this method to compute the timecode value
		*/
		virtual filepos_t UpdateSize(bool bSaveDefault = false, bool bForceRender = false);

		const KaxBlockBlob & RefBlock() const;
		void SetReferencedBlock(const KaxBlockBlob * aRefdBlock);
		void SetReferencedBlock(const KaxBlockGroup & aRefdBlock);
		void SetParentBlock(const KaxBlockGroup & aParentBlock) {ParentBlock = &aParentBlock;}
		
	protected:
		const KaxBlockBlob * RefdBlock;
		const KaxBlockGroup * ParentBlock;
		void SetReferencedTimecode(int64 refTimecode) {*static_cast<EbmlSInteger*>(this) = refTimecode; bTimecodeSet = true;};
		bool bTimecodeSet;
        bool bOurBlob;
        void FreeBlob();
};

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_BLOCK_ADDITIONAL_H
