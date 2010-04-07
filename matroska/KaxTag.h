/****************************************************************************
** libmatroska : parse Matroska files, see http://www.matroska.org/
**
** <file/class MATROSKA_DLL_API description>
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
	\version \$Id: KaxTag.h,v 1.9 2004/04/14 23:26:17 robux4 Exp $
	\author Jory Stone     <jcsston @ toughguy.net>
	\author Steve Lhomme   <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_TAG_H
#define LIBMATROSKA_TAG_H

#include "matroska/KaxTypes.h"
#include "ebml/EbmlMaster.h"
#include "ebml/EbmlFloat.h"
#include "ebml/EbmlSInteger.h"
#include "ebml/EbmlUInteger.h"
#include "ebml/EbmlString.h"
#include "ebml/EbmlUnicodeString.h"
#include "ebml/EbmlBinary.h"
#include "matroska/KaxDefines.h"

using namespace LIBEBML_NAMESPACE;

START_LIBMATROSKA_NAMESPACE

DECLARE_MKX_MASTER(KaxTag)
};

DECLARE_MKX_MASTER(KaxTagTargets)
};

DECLARE_MKX_MASTER(KaxTagGeneral)
};

DECLARE_MKX_MASTER(KaxTagGenres)
};

DECLARE_MKX_MASTER(KaxTagAudioSpecific)
};

DECLARE_MKX_MASTER(KaxTagImageSpecific)
};

DECLARE_MKX_UINTEGER(KaxTagTargetTypeValue)
};

DECLARE_MKX_STRING(KaxTagTargetType)
};

DECLARE_MKX_UINTEGER(KaxTagTrackUID)
};

DECLARE_MKX_UINTEGER(KaxTagEditionUID)
};

DECLARE_MKX_UINTEGER(KaxTagChapterUID)
};

DECLARE_MKX_UINTEGER(KaxTagAttachmentUID)
};

DECLARE_MKX_UNISTRING(KaxTagArchivalLocation)
};

DECLARE_MKX_BINARY(KaxTagAudioEncryption)
};

DECLARE_MKX_FLOAT(KaxTagAudioGain)
};

DECLARE_MKX_STRING(KaxTagAudioGenre)
};

DECLARE_MKX_FLOAT(KaxTagAudioPeak)
};

DECLARE_MKX_UNISTRING(KaxTagBibliography)
};

DECLARE_MKX_FLOAT(KaxTagBPM)
};

DECLARE_MKX_UINTEGER(KaxTagCaptureDPI)
};

DECLARE_MKX_BINARY(KaxTagCaptureLightness)
};

DECLARE_MKX_UINTEGER(KaxTagCapturePaletteSetting)
};

DECLARE_MKX_BINARY(KaxTagCaptureSharpness)
};

DECLARE_MKX_UNISTRING(KaxTagCropped)
};

DECLARE_MKX_UINTEGER(KaxTagDiscTrack)
};

DECLARE_MKX_UNISTRING(KaxTagEncoder)
};

DECLARE_MKX_UNISTRING(KaxTagEncodeSettings)
};

DECLARE_MKX_BINARY(KaxTagEqualisation)
};

DECLARE_MKX_UNISTRING(KaxTagFile)
};

DECLARE_MKX_STRING(KaxTagInitialKey)
};

DECLARE_MKX_UNISTRING(KaxTagKeywords)
};

DECLARE_MKX_STRING(KaxTagLanguage)
};

DECLARE_MKX_UINTEGER(KaxTagLength)
};

DECLARE_MKX_UNISTRING(KaxTagMood)
};

DECLARE_MKX_STRING(KaxTagOfficialAudioFileURL)
};

DECLARE_MKX_STRING(KaxTagOfficialAudioSourceURL)
};

DECLARE_MKX_STRING(KaxTagOriginalDimensions)
};

DECLARE_MKX_UNISTRING(KaxTagOriginalMediaType)
};

DECLARE_MKX_UINTEGER(KaxTagPlayCounter)
};			 

DECLARE_MKX_UINTEGER(KaxTagPlaylistDelay)
};

DECLARE_MKX_SINTEGER(KaxTagPopularimeter)
};

DECLARE_MKX_UNISTRING(KaxTagProduct)
};

DECLARE_MKX_BINARY(KaxTagRating)
};

DECLARE_MKX_STRING(KaxTagRecordLocation)
};

DECLARE_MKX_UINTEGER(KaxTagSetPart)
};

DECLARE_MKX_UNISTRING(KaxTagSource)
};

DECLARE_MKX_UNISTRING(KaxTagSourceForm)
};

DECLARE_MKX_STRING(KaxTagSubGenre)
};

DECLARE_MKX_UNISTRING(KaxTagSubject)
};

DECLARE_MKX_UNISTRING(KaxTagUnsynchronisedText)
};

DECLARE_MKX_STRING(KaxTagUserDefinedURL)
};

DECLARE_MKX_BINARY(KaxTagVideoGenre)
	public:
		virtual bool ValidateSize() const {return (GetSize() >= 2);}
};

DECLARE_MKX_MASTER(KaxTagSimple)
};

DECLARE_MKX_UNISTRING(KaxTagName)
};

DECLARE_MKX_STRING(KaxTagLangue)
};

DECLARE_MKX_UINTEGER(KaxTagDefault)
};

DECLARE_MKX_UNISTRING(KaxTagString)
};

DECLARE_MKX_BINARY(KaxTagBinary)
};

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_TAG_H
