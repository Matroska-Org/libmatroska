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
};

DECLARE_MKX_MASTER(KaxEditionEntry)
};

DECLARE_MKX_UINTEGER(KaxEditionUID)
};

DECLARE_MKX_UINTEGER(KaxEditionFlagHidden)
};

DECLARE_MKX_UINTEGER(KaxEditionFlagDefault)
};

DECLARE_MKX_UINTEGER(KaxEditionFlagOrdered)
};

DECLARE_MKX_MASTER(KaxChapterAtom)
};

DECLARE_MKX_UINTEGER(KaxChapterUID)
};

DECLARE_MKX_UINTEGER(KaxChapterTimeStart)
};

DECLARE_MKX_UINTEGER(KaxChapterTimeEnd)
};

DECLARE_MKX_UINTEGER(KaxChapterFlagHidden)
};

DECLARE_MKX_UINTEGER(KaxChapterFlagEnabled)
};

DECLARE_MKX_BINARY(KaxChapterSegmentUID)
    public:
	    virtual bool ValidateSize() const { return (GetSize() == 16);}
};

DECLARE_MKX_BINARY(KaxChapterSegmentEditionUID)
    public:
	    virtual bool ValidateSize() const { return (GetSize() == 16);}
};

DECLARE_MKX_UINTEGER(KaxChapterPhysicalEquiv)
};

DECLARE_MKX_MASTER(KaxChapterTrack)
};

DECLARE_MKX_UINTEGER(KaxChapterTrackNumber)
};

DECLARE_MKX_MASTER(KaxChapterDisplay)
};

DECLARE_MKX_UNISTRING(KaxChapterString)
};

DECLARE_MKX_STRING(KaxChapterLanguage)
};

DECLARE_MKX_STRING(KaxChapterCountry)
};

DECLARE_MKX_MASTER(KaxChapterProcess)
};

DECLARE_MKX_UINTEGER(KaxChapterProcessCodecID)
};

DECLARE_MKX_BINARY(KaxChapterProcessPrivate)
};

DECLARE_MKX_MASTER(KaxChapterProcessCommand)
};

DECLARE_MKX_UINTEGER(KaxChapterProcessTime)
};

DECLARE_MKX_BINARY(KaxChapterProcessData)
};

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_CHAPTERS_H
