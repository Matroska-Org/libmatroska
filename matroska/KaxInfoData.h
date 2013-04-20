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
	\version \$Id$
	\author Steve Lhomme     <robux4 @ users.sf.net>
	\author John Cannon      <spyder2555 @ users.sf.net>
	\author Moritz Bunkus    <moritz @ bunkus.org>
*/
#ifndef LIBMATROSKA_INFO_DATA_H
#define LIBMATROSKA_INFO_DATA_H

#include "matroska/KaxTypes.h"
#include "ebml/EbmlUInteger.h"
#include "ebml/EbmlFloat.h"
#include "ebml/EbmlUnicodeString.h"
#include "ebml/EbmlBinary.h"
#include "ebml/EbmlDate.h"
#include "ebml/EbmlMaster.h"
#include "matroska/KaxDefines.h"
#include "matroska/KaxSemantic.h"

using namespace LIBEBML_NAMESPACE;

START_LIBMATROSKA_NAMESPACE

DECLARE_MKX_CONTEXT(KaxPrevUID);
class MATROSKA_DLL_API KaxPrevUID : public KaxSegmentUID {
	public:
		KaxPrevUID(EBML_EXTRA_PARAM);
		KaxPrevUID(const KaxPrevUID & ElementToClone) :KaxSegmentUID(ElementToClone){}
		virtual bool ValidateSize() const { return IsFiniteSize() && (GetSize() == 16);}

        EBML_CONCRETE_CLASS(KaxPrevUID)
};

DECLARE_MKX_CONTEXT(KaxNextUID);
class MATROSKA_DLL_API KaxNextUID : public KaxSegmentUID {
	public:
		KaxNextUID(EBML_EXTRA_PARAM);
		KaxNextUID(const KaxNextUID & ElementToClone) :KaxSegmentUID(ElementToClone){}
		virtual bool ValidateSize() const { return IsFiniteSize() && (GetSize() == 16);}

        EBML_CONCRETE_CLASS(KaxNextUID)
};

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_INFO_DATA_H
