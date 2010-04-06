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
	public:
		KaxTag(const KaxTag & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTag)
};

DECLARE_MKX_MASTER(KaxTagTargets)
	public:
		KaxTagTargets(const KaxTagTargets & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagTargets)
};

DECLARE_MKX_MASTER(KaxTagGeneral)
	public:
		KaxTagGeneral(const KaxTagGeneral & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagGeneral)
};

DECLARE_MKX_MASTER(KaxTagGenres)
	public:
		KaxTagGenres(const KaxTagGenres & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagGenres)
};

DECLARE_MKX_MASTER(KaxTagAudioSpecific)
	public:
		KaxTagAudioSpecific(const KaxTagAudioSpecific & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagAudioSpecific)
};

DECLARE_MKX_MASTER(KaxTagImageSpecific)
	public:
		KaxTagImageSpecific(const KaxTagImageSpecific & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagImageSpecific)
};

DECLARE_MKX_UINTEGER(KaxTagTargetTypeValue)
	public:
		KaxTagTargetTypeValue(const KaxTagTargetTypeValue & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagTargetTypeValue)
};

DECLARE_MKX_STRING(KaxTagTargetType)
	public:
		KaxTagTargetType(const KaxTagTargetType & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagTargetType)
};

DECLARE_MKX_UINTEGER(KaxTagTrackUID)
	public:
		KaxTagTrackUID(const KaxTagTrackUID & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagTrackUID)
};

DECLARE_MKX_UINTEGER(KaxTagEditionUID)
	public:
		KaxTagEditionUID(const KaxTagEditionUID & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagEditionUID)
};

DECLARE_MKX_UINTEGER(KaxTagChapterUID)
	public:
		KaxTagChapterUID(const KaxTagChapterUID & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagChapterUID)
};

DECLARE_MKX_UINTEGER(KaxTagAttachmentUID)
	public:
		KaxTagAttachmentUID(const KaxTagAttachmentUID & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagAttachmentUID)
};

DECLARE_MKX_UNISTRING(KaxTagArchivalLocation)
	public:
		KaxTagArchivalLocation(const KaxTagArchivalLocation & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagArchivalLocation)
};

DECLARE_MKX_BINARY(KaxTagAudioEncryption)
	public:
		KaxTagAudioEncryption(const KaxTagAudioEncryption & ElementToClone) :EbmlBinary(ElementToClone){}
		bool ValidateSize() const {return true;} // we don't mind about what's inside

        EBML_CONCRETE_CLASS(KaxTagAudioEncryption)
};

DECLARE_MKX_FLOAT(KaxTagAudioGain)
	public:
		KaxTagAudioGain(const KaxTagAudioGain & ElementToClone) :EbmlFloat(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagAudioGain)
};

DECLARE_MKX_STRING(KaxTagAudioGenre)
	public:
		KaxTagAudioGenre(const KaxTagAudioGenre & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagAudioGenre)
};

DECLARE_MKX_FLOAT(KaxTagAudioPeak)
	public:
		KaxTagAudioPeak(const KaxTagAudioPeak & ElementToClone) :EbmlFloat(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagAudioPeak)
};

DECLARE_MKX_UNISTRING(KaxTagBibliography)
	public:
		KaxTagBibliography(const KaxTagBibliography & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagBibliography)
};

DECLARE_MKX_FLOAT(KaxTagBPM)
	public:
		KaxTagBPM(const KaxTagBPM & ElementToClone) :EbmlFloat(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagBPM)
};

DECLARE_MKX_UINTEGER(KaxTagCaptureDPI)
	public:
		KaxTagCaptureDPI(const KaxTagCaptureDPI & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagCaptureDPI)
};

DECLARE_MKX_BINARY(KaxTagCaptureLightness)
	public:
		KaxTagCaptureLightness(const KaxTagCaptureLightness & ElementToClone) :EbmlBinary(ElementToClone){}
		bool ValidateSize() const {return true;} // we don't mind about what's inside

        EBML_CONCRETE_CLASS(KaxTagCaptureLightness)
};

DECLARE_MKX_UINTEGER(KaxTagCapturePaletteSetting)
	public:
		KaxTagCapturePaletteSetting(const KaxTagCapturePaletteSetting & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagCapturePaletteSetting)
};

DECLARE_MKX_BINARY(KaxTagCaptureSharpness)
	public:
		KaxTagCaptureSharpness(const KaxTagCaptureSharpness & ElementToClone) :EbmlBinary(ElementToClone){}
		bool ValidateSize() const {return true;} // we don't mind about what's inside

        EBML_CONCRETE_CLASS(KaxTagCaptureSharpness)
};

DECLARE_MKX_UNISTRING(KaxTagCropped)
	public:
		KaxTagCropped(const KaxTagCropped & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagCropped)
};

DECLARE_MKX_UINTEGER(KaxTagDiscTrack)
	public:
		KaxTagDiscTrack(const KaxTagDiscTrack & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagDiscTrack)
};

DECLARE_MKX_UNISTRING(KaxTagEncoder)
	public:
		KaxTagEncoder(const KaxTagEncoder & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagEncoder)
};

DECLARE_MKX_UNISTRING(KaxTagEncodeSettings)
	public:
		KaxTagEncodeSettings(const KaxTagEncodeSettings & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagEncodeSettings)
};

DECLARE_MKX_BINARY(KaxTagEqualisation)
	public:
		KaxTagEqualisation(const KaxTagEqualisation & ElementToClone) :EbmlBinary(ElementToClone){}
		bool ValidateSize() const {return true;} // we don't mind about what's inside

        EBML_CONCRETE_CLASS(KaxTagEqualisation)
};

DECLARE_MKX_UNISTRING(KaxTagFile)
	public:
		KaxTagFile(const KaxTagFile & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagFile)
};

DECLARE_MKX_STRING(KaxTagInitialKey)
	public:
		KaxTagInitialKey(const KaxTagInitialKey & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagInitialKey)
};

DECLARE_MKX_UNISTRING(KaxTagKeywords)
	public:
		KaxTagKeywords(const KaxTagKeywords & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagKeywords)
};

DECLARE_MKX_STRING(KaxTagLanguage)
	public:
		KaxTagLanguage(const KaxTagLanguage & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagLanguage)
};

DECLARE_MKX_UINTEGER(KaxTagLength)
	public:
		KaxTagLength(const KaxTagLength & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagLength)
};

DECLARE_MKX_UNISTRING(KaxTagMood)
	public:
		KaxTagMood(const KaxTagMood & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMood)
};

DECLARE_MKX_STRING(KaxTagOfficialAudioFileURL)
	public:
		KaxTagOfficialAudioFileURL(const KaxTagOfficialAudioFileURL & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagOfficialAudioFileURL)
};

DECLARE_MKX_STRING(KaxTagOfficialAudioSourceURL)
	public:
		KaxTagOfficialAudioSourceURL(const KaxTagOfficialAudioSourceURL & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagOfficialAudioSourceURL)
};

DECLARE_MKX_STRING(KaxTagOriginalDimensions)
	public:
		KaxTagOriginalDimensions(const KaxTagOriginalDimensions & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagOriginalDimensions)
};

DECLARE_MKX_UNISTRING(KaxTagOriginalMediaType)
	public:
		KaxTagOriginalMediaType(const KaxTagOriginalMediaType & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagOriginalMediaType)
};

DECLARE_MKX_UINTEGER(KaxTagPlayCounter)
	public:
		KaxTagPlayCounter(const KaxTagPlayCounter & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagPlayCounter)
};			 

DECLARE_MKX_UINTEGER(KaxTagPlaylistDelay)
	public:
		KaxTagPlaylistDelay(const KaxTagPlaylistDelay & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagPlaylistDelay)
};

DECLARE_MKX_SINTEGER(KaxTagPopularimeter)
	public:
		KaxTagPopularimeter(const KaxTagPopularimeter & ElementToClone) :EbmlSInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagPopularimeter)
};

DECLARE_MKX_UNISTRING(KaxTagProduct)
	public:
		KaxTagProduct(const KaxTagProduct & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagProduct)
};

DECLARE_MKX_BINARY(KaxTagRating)
	public:
		KaxTagRating(const KaxTagRating & ElementToClone) :EbmlBinary(ElementToClone){}
		bool ValidateSize() const {return true;} // we don't mind about what's inside

        EBML_CONCRETE_CLASS(KaxTagRating)
};

DECLARE_MKX_STRING(KaxTagRecordLocation)
	public:
		KaxTagRecordLocation(const KaxTagRecordLocation & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagRecordLocation)
};

DECLARE_MKX_UINTEGER(KaxTagSetPart)
	public:
		KaxTagSetPart(const KaxTagSetPart & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagSetPart)
};

DECLARE_MKX_UNISTRING(KaxTagSource)
	public:
		KaxTagSource(const KaxTagSource & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagSource)
};

DECLARE_MKX_UNISTRING(KaxTagSourceForm)
	public:
		KaxTagSourceForm(const KaxTagSourceForm & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagSourceForm)
};

DECLARE_MKX_STRING(KaxTagSubGenre)
	public:
		KaxTagSubGenre(const KaxTagSubGenre & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagSubGenre)
};

DECLARE_MKX_UNISTRING(KaxTagSubject)
	public:
		KaxTagSubject(const KaxTagSubject & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagSubject)
};

DECLARE_MKX_UNISTRING(KaxTagUnsynchronisedText)
	public:
		KaxTagUnsynchronisedText(const KaxTagUnsynchronisedText & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagUnsynchronisedText)
};

DECLARE_MKX_STRING(KaxTagUserDefinedURL)
	public:
		KaxTagUserDefinedURL(const KaxTagUserDefinedURL & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagUserDefinedURL)
};

DECLARE_MKX_BINARY(KaxTagVideoGenre)
	public:
		KaxTagVideoGenre(const KaxTagVideoGenre & ElementToClone) :EbmlBinary(ElementToClone){}
		bool ValidateSize() const {return (GetSize() >= 2);}

        EBML_CONCRETE_CLASS(KaxTagVideoGenre)
};

DECLARE_MKX_MASTER(KaxTagSimple)
	public:
		KaxTagSimple(const KaxTagSimple & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagSimple)
};

DECLARE_MKX_UNISTRING(KaxTagName)
	public:
		KaxTagName(const KaxTagName & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagName)
};

DECLARE_MKX_STRING(KaxTagLangue)
	public:
		KaxTagLangue(const KaxTagLangue & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagLangue)
};

DECLARE_MKX_UINTEGER(KaxTagDefault)
	public:
		KaxTagDefault(const KaxTagTrackUID & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagDefault)
};

DECLARE_MKX_UNISTRING(KaxTagString)
	public:
		KaxTagString(const KaxTagString & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagString)
};

DECLARE_MKX_BINARY(KaxTagBinary)
	public:
		KaxTagBinary(const KaxTagBinary & ElementToClone) :EbmlBinary(ElementToClone){}
		bool ValidateSize() const {return true;} // {return (GetSize() >= 0);}

        EBML_CONCRETE_CLASS(KaxTagBinary)
};

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_TAG_H
