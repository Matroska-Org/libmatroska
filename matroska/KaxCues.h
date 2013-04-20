/****************************************************************************
** libmatroska : parse Matroska files, see http://www.matroska.org/
**
** <file/class description>
**
** Copyright (C) 2002-2010 Steve Lhomme.  All rights reserved.
**
** This file is part of libmatroska.
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
	\version \$Id: KaxCues.h,v 1.7 2004/04/14 23:26:17 robux4 Exp $
	\author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_CUES_H
#define LIBMATROSKA_CUES_H

#include <vector>

#include "matroska/KaxTypes.h"
#include "ebml/EbmlMaster.h"
#include "matroska/KaxBlock.h"

using namespace LIBEBML_NAMESPACE;

START_LIBMATROSKA_NAMESPACE

class KaxCuePoint;

DECLARE_MKX_MASTER(KaxCues)
	public:
		~KaxCues();

		//bool AddBlockGroup(const KaxBlockGroup & BlockReference); // deprecated
		bool AddBlockBlob(const KaxBlockBlob & BlockReference);

		/*!
			\brief Indicate that the position for this Block is set
		*/
		void PositionSet(const KaxBlockGroup & BlockReference);
		void PositionSet(const KaxBlockBlob & BlockReference);

		/*!
			\brief override to sort by timecode/track
		*/
		filepos_t Render(IOCallback & output, bool bSaveDefault = false) {
			Sort();
			return EbmlMaster::Render(output, bSaveDefault);
		}

		uint64 GetTimecodePosition(uint64 aTimecode) const;
		const KaxCuePoint * GetTimecodePoint(uint64 aTimecode) const;

		void SetGlobalTimecodeScale(uint64 aGlobalTimecodeScale) {
			mGlobalTimecodeScale = aGlobalTimecodeScale;
			bGlobalTimecodeScaleIsSet = true;
		}
		uint64 GlobalTimecodeScale() const {
			assert(bGlobalTimecodeScaleIsSet); 
			return mGlobalTimecodeScale;
		}

	protected:
		std::vector<const KaxBlockBlob *> myTempReferences;
		bool   bGlobalTimecodeScaleIsSet;
		uint64 mGlobalTimecodeScale;
};

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_CUES_H
