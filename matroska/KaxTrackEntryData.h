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
	public:
		KaxTrackNumber(const KaxTrackNumber & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_UINTEGER(KaxTrackUID)
	public:
		KaxTrackUID(const KaxTrackUID & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_UINTEGER(KaxTrackType)
	public:
		KaxTrackType(const KaxTrackType & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_UINTEGER(KaxTrackFlagEnabled)
	public:
		KaxTrackFlagEnabled(const KaxTrackFlagEnabled & ElementToClone) :EbmlUInteger(ElementToClone) {}
};
#endif // MATROSKA_VERSION

DECLARE_MKX_UINTEGER(KaxTrackFlagDefault)
	public:
		KaxTrackFlagDefault(const KaxTrackFlagDefault & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_UINTEGER(KaxTrackFlagForced)
	public:
		KaxTrackFlagForced(const KaxTrackFlagForced & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_UINTEGER(KaxTrackFlagLacing)
	public:
		KaxTrackFlagLacing(const KaxTrackFlagLacing & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_UINTEGER(KaxTrackMinCache)
	public:
		KaxTrackMinCache(const KaxTrackMinCache & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_UINTEGER(KaxTrackMaxCache)
	public:
		KaxTrackMaxCache(const KaxTrackMaxCache & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_UINTEGER(KaxTrackDefaultDuration)
	public:
		KaxTrackDefaultDuration(const KaxTrackDefaultDuration & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_FLOAT(KaxTrackTimecodeScale)
	public:
		KaxTrackTimecodeScale(const KaxTrackTimecodeScale & ElementToClone) :EbmlFloat(ElementToClone) {}
};

DECLARE_MKX_UINTEGER(KaxMaxBlockAdditionID)
	public:
		KaxMaxBlockAdditionID(const KaxMaxBlockAdditionID & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_UNISTRING(KaxTrackName)
	public:
		KaxTrackName(const KaxTrackName & ElementToClone) :EbmlUnicodeString(ElementToClone) {}
};

DECLARE_MKX_STRING(KaxTrackLanguage)
	public:
		KaxTrackLanguage(const KaxTrackLanguage & ElementToClone) :EbmlString(ElementToClone) {}
};

DECLARE_MKX_STRING(KaxCodecID)
	public:
		KaxCodecID(const KaxCodecID & ElementToClone) :EbmlString(ElementToClone) {}
};

DECLARE_MKX_BINARY(KaxCodecPrivate)
	public:
		KaxCodecPrivate(const KaxCodecPrivate & ElementToClone) :EbmlBinary(ElementToClone){}
		bool ValidateSize() const {return true;} // we don't mind about what's inside
};

DECLARE_MKX_UNISTRING(KaxCodecName)
	public:
		KaxCodecName(const KaxCodecName & ElementToClone) :EbmlUnicodeString(ElementToClone) {}
};

DECLARE_MKX_BINARY(KaxTrackAttachmentLink)
	public:
		KaxTrackAttachmentLink(const KaxTrackAttachmentLink & ElementToClone) :EbmlBinary(ElementToClone){}
		bool ValidateSize() const {return true;} // we don't mind about what's inside
};

DECLARE_MKX_UINTEGER(KaxTrackOverlay)
	public:
		KaxTrackOverlay(const KaxTrackOverlay & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_MASTER(KaxTrackTranslate)
	public:
		KaxTrackTranslate(const KaxTrackTranslate & ElementToClone) :EbmlMaster(ElementToClone) {}
};

DECLARE_MKX_UINTEGER(KaxTrackTranslateCodec)
	public:
		KaxTrackTranslateCodec(const KaxTrackTranslateCodec & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_UINTEGER(KaxTrackTranslateEditionUID)
	public:
		KaxTrackTranslateEditionUID(const KaxTrackTranslateEditionUID & ElementToClone) :EbmlUInteger(ElementToClone) {}
};

DECLARE_MKX_BINARY(KaxTrackTranslateTrackID)
	public:
		KaxTrackTranslateTrackID(const KaxTrackTranslateTrackID & ElementToClone) :EbmlBinary(ElementToClone){}
		bool ValidateSize() const { return true;}
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_UNISTRING(KaxCodecSettings)
	public:
		KaxCodecSettings(const KaxCodecSettings & ElementToClone) :EbmlUnicodeString(ElementToClone) {}
};

DECLARE_MKX_STRING(KaxCodecInfoURL)
	public:
		KaxCodecInfoURL(const KaxCodecInfoURL & ElementToClone) :EbmlString(ElementToClone) {}
};

DECLARE_MKX_STRING(KaxCodecDownloadURL)
	public:
		KaxCodecDownloadURL(const KaxCodecDownloadURL & ElementToClone) :EbmlString(ElementToClone) {}
};

DECLARE_MKX_UINTEGER(KaxCodecDecodeAll)
	public:
		KaxCodecDecodeAll(const KaxCodecDecodeAll & ElementToClone) :EbmlUInteger(ElementToClone) {}
};
#endif // MATROSKA_VERSION

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_TRACK_ENTRY_DATA_H
