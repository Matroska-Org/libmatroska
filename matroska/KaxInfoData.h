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
** Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
**
** See http://www.matroska.org/license/lgpl/ for LGPL licensing information.**
** Contact license@matroska.org if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

/*!
	\file
	\version \$Id: KaxInfoData.h,v 1.7 2004/04/14 23:26:17 robux4 Exp $
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

using namespace LIBEBML_NAMESPACE;

START_LIBMATROSKA_NAMESPACE

DECLARE_MKX_BINARY(KaxSegmentUID)
	public:
		bool ValidateSize() const { return (GetSize() == 16);}
};

DECLARE_MKX_UNISTRING(KaxSegmentFilename)
};

DECLARE_MKX_CONTEXT(KaxPrevUID);
class MATROSKA_DLL_API KaxPrevUID : public KaxSegmentUID {
	public:
		KaxPrevUID();
		KaxPrevUID(const KaxPrevUID & ElementToClone) :KaxSegmentUID(ElementToClone){}
		bool ValidateSize() const { return (GetSize() == 16);}

        EBML_CONCRETE_CLASS(KaxPrevUID)
};

DECLARE_MKX_UNISTRING(KaxPrevFilename)
};

DECLARE_MKX_CONTEXT(KaxNextUID);
class MATROSKA_DLL_API KaxNextUID : public KaxSegmentUID {
	public:
		KaxNextUID();
		KaxNextUID(const KaxNextUID & ElementToClone) :KaxSegmentUID(ElementToClone){}
		bool ValidateSize() const { return (GetSize() == 16);}

        EBML_CONCRETE_CLASS(KaxNextUID)
};

DECLARE_MKX_UNISTRING(KaxNextFilename)
};

DECLARE_MKX_BINARY(KaxSegmentFamily)
	public:
		bool ValidateSize() const { return (GetSize() == 16);}
};

DECLARE_MKX_MASTER(KaxChapterTranslate)
};

DECLARE_MKX_UINTEGER(KaxChapterTranslateCodec)
};

DECLARE_MKX_UINTEGER(KaxChapterTranslateEditionUID)
};

DECLARE_MKX_BINARY(KaxChapterTranslateID)
	public:
		bool ValidateSize() const { return true;}
};

DECLARE_MKX_UINTEGER(KaxTimecodeScale)
};

DECLARE_MKX_FLOAT(KaxDuration)
};

DECLARE_MKX_DATE(KaxDateUTC)
};

DECLARE_MKX_UNISTRING(KaxTitle)
};

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_INFO_DATA_H
