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
	\version \$Id: KaxChapters.h,v 1.9 2004/04/14 23:26:17 robux4 Exp $
	\author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_CHAPTERS_H
#define LIBMATROSKA_CHAPTERS_H

#include "matroska/KaxTypes.h"
#include "ebml/EbmlMaster.h"
#include "ebml/EbmlUInteger.h"
#include "ebml/EbmlUnicodeString.h"
#include "ebml/EbmlString.h"
#include "ebml/EbmlBinary.h"
#include "matroska/KaxDefines.h"

using namespace LIBEBML_NAMESPACE;

START_LIBMATROSKA_NAMESPACE

DECLARE_MKX_MASTER(KaxChapters)
	public:
		KaxChapters(const KaxChapters & ElementToClone) :EbmlMaster(ElementToClone) {}
};

DECLARE_MKX_MASTER(KaxEditionEntry)
	public:
		KaxEditionEntry(const KaxEditionEntry & ElementToClone) :EbmlMaster(ElementToClone) {}
};

DECLARE_MKX_UINTEGER(KaxEditionUID)
    public:
	    KaxEditionUID(const KaxEditionUID & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_UINTEGER(KaxEditionFlagHidden)
    public:
	    KaxEditionFlagHidden(const KaxEditionFlagHidden & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_UINTEGER(KaxEditionFlagDefault)
    public:
	    KaxEditionFlagDefault(const KaxEditionFlagDefault & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_UINTEGER(KaxEditionFlagOrdered)
    public:
	    KaxEditionFlagOrdered(const KaxEditionFlagOrdered & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_MASTER(KaxChapterAtom)
    public:
	    KaxChapterAtom(const KaxChapterAtom & ElementToClone) :EbmlMaster(ElementToClone) {}
};

DECLARE_MKX_UINTEGER(KaxChapterUID)
    public:
	    KaxChapterUID(const KaxChapterUID & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_UINTEGER(KaxChapterTimeStart)
    public:
	    KaxChapterTimeStart(const KaxChapterTimeStart & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_UINTEGER(KaxChapterTimeEnd)
    public:
	    KaxChapterTimeEnd(const KaxChapterTimeEnd & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_UINTEGER(KaxChapterFlagHidden)
    public:
	    KaxChapterFlagHidden(const KaxChapterFlagHidden & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_UINTEGER(KaxChapterFlagEnabled)
    public:
	    KaxChapterFlagEnabled(const KaxChapterFlagEnabled & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_BINARY(KaxChapterSegmentUID)
    public:
	    KaxChapterSegmentUID(const KaxChapterSegmentUID & ElementToClone) :EbmlBinary(ElementToClone) {}
	    bool ValidateSize() const { return (GetSize() == 16);}
};

DECLARE_MKX_BINARY(KaxChapterSegmentEditionUID)
    public:
	    KaxChapterSegmentEditionUID(const KaxChapterSegmentEditionUID & ElementToClone) :EbmlBinary(ElementToClone) {}
	    bool ValidateSize() const { return (GetSize() == 16);}
};

DECLARE_MKX_UINTEGER(KaxChapterPhysicalEquiv)
    public:
	    KaxChapterPhysicalEquiv(const KaxChapterPhysicalEquiv & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_MASTER(KaxChapterTrack)
    public:
	    KaxChapterTrack(const KaxChapterTrack & ElementToClone) :EbmlMaster(ElementToClone) {}
};

DECLARE_MKX_UINTEGER(KaxChapterTrackNumber)
    public:
	    KaxChapterTrackNumber(const KaxChapterTrackNumber & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_MASTER(KaxChapterDisplay)
    public:
	    KaxChapterDisplay(const KaxChapterDisplay & ElementToClone) :EbmlMaster(ElementToClone) {}
};

DECLARE_MKX_UNISTRING(KaxChapterString)
    public:
	    KaxChapterString(const KaxChapterString & ElementToClone) :EbmlUnicodeString(ElementToClone) {}
};

DECLARE_MKX_STRING(KaxChapterLanguage)
    public:
	    KaxChapterLanguage(const KaxChapterLanguage & ElementToClone) :EbmlString(ElementToClone) {}
};

DECLARE_MKX_STRING(KaxChapterCountry)
    public:
	    KaxChapterCountry(const KaxChapterCountry & ElementToClone) :EbmlString(ElementToClone) {}
};

DECLARE_MKX_MASTER(KaxChapterProcess)
    public:
	    KaxChapterProcess(const KaxChapterProcess & ElementToClone) :EbmlMaster(ElementToClone) {}
};

DECLARE_MKX_UINTEGER(KaxChapterProcessCodecID)
    public:
	    KaxChapterProcessCodecID(const KaxChapterProcessCodecID & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_BINARY(KaxChapterProcessPrivate)
    public:
	    KaxChapterProcessPrivate(const KaxChapterProcessPrivate & ElementToClone) :EbmlBinary(ElementToClone) {}
	    bool ValidateSize() const {return true;}
};

DECLARE_MKX_MASTER(KaxChapterProcessCommand)
    public:
	    KaxChapterProcessCommand(const KaxChapterProcessCommand & ElementToClone) :EbmlMaster(ElementToClone) {}
};

DECLARE_MKX_UINTEGER(KaxChapterProcessTime)
    public:
	    KaxChapterProcessTime(const KaxChapterProcessTime & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_BINARY(KaxChapterProcessData)
    public:
	    KaxChapterProcessData(const KaxChapterProcessData & ElementToClone) :EbmlBinary(ElementToClone) {}
	    bool ValidateSize() const {return true;}
};

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_CHAPTERS_H
