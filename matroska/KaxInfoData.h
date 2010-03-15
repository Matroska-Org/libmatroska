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

using namespace LIBEBML_NAMESPACE;

START_LIBMATROSKA_NAMESPACE

class MATROSKA_DLL_API KaxSegmentUID : public EbmlBinary {
	public:
		KaxSegmentUID() {}
		KaxSegmentUID(const KaxSegmentUID & ElementToClone) :EbmlBinary(ElementToClone){}
		bool ValidateSize() const { return (GetSize() == 16);}

        EBML_CONCRETE_CLASS(KaxSegmentUID)
};

class MATROSKA_DLL_API KaxSegmentFilename : public EbmlUnicodeString {
	public:
		KaxSegmentFilename() {}
		KaxSegmentFilename(const KaxSegmentFilename & ElementToClone) :EbmlUnicodeString(ElementToClone){}

        EBML_CONCRETE_CLASS(KaxSegmentFilename)
};

class MATROSKA_DLL_API KaxPrevUID : public KaxSegmentUID {
	public:
		KaxPrevUID() {}
		KaxPrevUID(const KaxPrevUID & ElementToClone) :KaxSegmentUID(ElementToClone){}
		bool ValidateSize() const { return (GetSize() == 16);}

        EBML_CONCRETE_CLASS(KaxPrevUID)
};

class MATROSKA_DLL_API KaxPrevFilename : public EbmlUnicodeString {
	public:
		KaxPrevFilename() :EbmlUnicodeString() {}
		KaxPrevFilename(const KaxPrevFilename & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxPrevFilename)
};

class MATROSKA_DLL_API KaxNextUID : public KaxSegmentUID {
	public:
		KaxNextUID() {}
		KaxNextUID(const KaxNextUID & ElementToClone) :KaxSegmentUID(ElementToClone){}
		bool ValidateSize() const { return (GetSize() == 16);}

        EBML_CONCRETE_CLASS(KaxNextUID)
};

class MATROSKA_DLL_API KaxNextFilename : public EbmlUnicodeString {
	public:
		KaxNextFilename() {}
		KaxNextFilename(const KaxNextFilename & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxNextFilename)
};

class MATROSKA_DLL_API KaxSegmentFamily : public EbmlBinary {
	public:
		KaxSegmentFamily() {}
		KaxSegmentFamily(const KaxSegmentFamily & ElementToClone) :EbmlBinary(ElementToClone){}
		bool ValidateSize() const { return (GetSize() == 16);}

        EBML_CONCRETE_CLASS(KaxSegmentFamily)
};

class MATROSKA_DLL_API KaxChapterTranslate : public EbmlMaster {
	public:
		KaxChapterTranslate();
		KaxChapterTranslate(const KaxChapterTranslate & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxChapterTranslate)
};

class MATROSKA_DLL_API KaxChapterTranslateCodec : public EbmlUInteger {
	public:
		KaxChapterTranslateCodec() {}
		KaxChapterTranslateCodec(const KaxChapterTranslateCodec & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxChapterTranslateCodec)
};

class MATROSKA_DLL_API KaxChapterTranslateEditionUID : public EbmlUInteger {
	public:
		KaxChapterTranslateEditionUID() {}
		KaxChapterTranslateEditionUID(const KaxChapterTranslateEditionUID & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxChapterTranslateEditionUID)
};

class MATROSKA_DLL_API KaxChapterTranslateID : public EbmlBinary {
	public:
		KaxChapterTranslateID() {}
		KaxChapterTranslateID(const KaxChapterTranslateID & ElementToClone) :EbmlBinary(ElementToClone){}
		bool ValidateSize() const { return true;}

        EBML_CONCRETE_CLASS(KaxChapterTranslateID)
};

class MATROSKA_DLL_API KaxTimecodeScale : public EbmlUInteger {
	public:
		KaxTimecodeScale() :EbmlUInteger(1000000) {}
		KaxTimecodeScale(const KaxTimecodeScale & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTimecodeScale)
};

class MATROSKA_DLL_API KaxDuration : public EbmlFloat {
	public:
		KaxDuration(): EbmlFloat(FLOAT_64) {}
		KaxDuration(const KaxDuration & ElementToClone) :EbmlFloat(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxDuration)
};

class MATROSKA_DLL_API KaxDateUTC : public EbmlDate {
	public:
		KaxDateUTC() {}
		KaxDateUTC(const KaxDateUTC & ElementToClone) :EbmlDate(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxDateUTC)
};

class MATROSKA_DLL_API KaxTitle : public EbmlUnicodeString {
	public:
		KaxTitle() {}
		KaxTitle(const KaxTitle & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTitle)
};

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_INFO_DATA_H
