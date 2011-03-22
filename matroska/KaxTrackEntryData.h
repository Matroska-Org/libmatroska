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
	\version \$Id: KaxTrackEntryData.h,v 1.9 2004/04/14 23:26:17 robux4 Exp $
	\author Steve Lhomme     <robux4 @ users.sf.net>
	\author John Cannon      <spyder2555 @ users.sf.net>
*/
#ifndef LIBMATROSKA_TRACK_ENTRY_DATA_H
#define LIBMATROSKA_TRACK_ENTRY_DATA_H

#include "matroska/KaxTypes.h"
#include "ebml/EbmlUInteger.h"
#include "ebml/EbmlFloat.h"
#include "ebml/EbmlString.h"
#include "ebml/EbmlUnicodeString.h"
#include "ebml/EbmlBinary.h"
#include "ebml/EbmlMaster.h"
#include "matroska/KaxDefines.h"

using namespace LIBEBML_NAMESPACE;

START_LIBMATROSKA_NAMESPACE

DECLARE_MKX_UINTEGER(KaxTrackNumber)
};

DECLARE_MKX_UINTEGER(KaxTrackUID)
};

DECLARE_MKX_UINTEGER(KaxTrackType)
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_UINTEGER(KaxTrackFlagEnabled)
};
#endif // MATROSKA_VERSION

DECLARE_MKX_UINTEGER(KaxTrackFlagDefault)
};

DECLARE_MKX_UINTEGER(KaxTrackFlagForced)
};

DECLARE_MKX_UINTEGER(KaxTrackFlagLacing)
};

DECLARE_MKX_UINTEGER(KaxTrackMinCache)
};

DECLARE_MKX_UINTEGER(KaxTrackMaxCache)
};

DECLARE_MKX_UINTEGER(KaxTrackDefaultDuration)
};

DECLARE_MKX_FLOAT(KaxTrackTimecodeScale)
};

DECLARE_MKX_UINTEGER(KaxMaxBlockAdditionID)
};

DECLARE_MKX_UNISTRING(KaxTrackName)
};

DECLARE_MKX_STRING(KaxTrackLanguage)
};

DECLARE_MKX_STRING(KaxCodecID)
};

DECLARE_MKX_BINARY(KaxCodecPrivate)
};

DECLARE_MKX_UNISTRING(KaxCodecName)
};

DECLARE_MKX_UINTEGER(KaxTrackAttachmentLink)
};

DECLARE_MKX_UINTEGER(KaxTrackOverlay)
};

DECLARE_MKX_MASTER(KaxTrackTranslate)
};

DECLARE_MKX_UINTEGER(KaxTrackTranslateCodec)
};

DECLARE_MKX_UINTEGER(KaxTrackTranslateEditionUID)
};

DECLARE_MKX_BINARY(KaxTrackTranslateTrackID)
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_UNISTRING(KaxCodecSettings)
};

DECLARE_MKX_STRING(KaxCodecInfoURL)
};

DECLARE_MKX_STRING(KaxCodecDownloadURL)
};

DECLARE_MKX_UINTEGER(KaxCodecDecodeAll)
};
#endif // MATROSKA_VERSION

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_TRACK_ENTRY_DATA_H
