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
	\version \$Id: KaxTracks.h,v 1.7 2004/04/14 23:26:17 robux4 Exp $
	\author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_TRACKS_H
#define LIBMATROSKA_TRACKS_H

#include "matroska/KaxTypes.h"
#include "ebml/EbmlMaster.h"
#include "ebml/EbmlUInteger.h"
#include "matroska/KaxDefines.h"
#include "matroska/KaxSemantic.h"

using namespace LIBEBML_NAMESPACE;

START_LIBMATROSKA_NAMESPACE

DECLARE_MKX_MASTER(KaxTrackEntry)
	public:
		EbmlUInteger & TrackNumber() const { return *(static_cast<EbmlUInteger *>(FindElt(EBML_INFO(KaxTrackNumber)))); }

		void EnableLacing(bool bEnable = true);

		/*!
			\note lacing set by default
		*/
		inline bool LacingEnabled() const {
			KaxTrackFlagLacing * myLacing = static_cast<KaxTrackFlagLacing *>(FindFirstElt(EBML_INFO(KaxTrackFlagLacing)));
			return((myLacing == NULL) || (uint8(*myLacing) != 0));
		}

		void SetGlobalTimecodeScale(uint64 aGlobalTimecodeScale) {
			mGlobalTimecodeScale = aGlobalTimecodeScale;
			bGlobalTimecodeScaleIsSet = true;
		}
		uint64 GlobalTimecodeScale() const {
			assert(bGlobalTimecodeScaleIsSet); 
			return mGlobalTimecodeScale;
		}

	protected:
		bool   bGlobalTimecodeScaleIsSet;
		uint64 mGlobalTimecodeScale;
};

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_TRACKS_H
