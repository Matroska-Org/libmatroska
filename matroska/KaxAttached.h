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
	\version \$Id: KaxAttached.h,v 1.8 2004/04/14 23:26:17 robux4 Exp $
	\author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_ATTACHED_H
#define LIBMATROSKA_ATTACHED_H

#include "matroska/KaxTypes.h"
#include "ebml/EbmlMaster.h"
#include "ebml/EbmlUnicodeString.h"
#include "ebml/EbmlString.h"
#include "ebml/EbmlBinary.h"
#include "ebml/EbmlUInteger.h"

using namespace LIBEBML_NAMESPACE;

START_LIBMATROSKA_NAMESPACE

class MATROSKA_DLL_API KaxAttached : public EbmlMaster {
	public:
		KaxAttached();
		KaxAttached(const KaxAttached & ElementToClone) : EbmlMaster(ElementToClone) {}
        
        EBML_CONCRETE_CLASS(KaxAttached)
};

class MATROSKA_DLL_API KaxFileDescription : public EbmlUnicodeString {
	public:
		KaxFileDescription() {}
		KaxFileDescription(const KaxFileDescription & ElementToClone) : EbmlUnicodeString(ElementToClone) {}
        
        EBML_CONCRETE_CLASS(KaxFileDescription)
};

class MATROSKA_DLL_API KaxFileName : public EbmlUnicodeString {
	public:
		KaxFileName() {}
		KaxFileName(const KaxFileName & ElementToClone) : EbmlUnicodeString(ElementToClone) {}
        
        EBML_CONCRETE_CLASS(KaxFileName)
};

class MATROSKA_DLL_API KaxMimeType : public EbmlString {
	public:
		KaxMimeType() {}
		KaxMimeType(const KaxMimeType & ElementToClone) : EbmlString(ElementToClone) {}
        
        EBML_CONCRETE_CLASS(KaxMimeType)
};

class MATROSKA_DLL_API KaxFileData : public EbmlBinary {
	public:
		KaxFileData() {}
		KaxFileData(const KaxFileData & ElementToClone) :EbmlBinary(ElementToClone){}
	
		bool ValidateSize() const {return true;} // we don't mind about what's inside
		
        EBML_CONCRETE_CLASS(KaxFileData)
};

class MATROSKA_DLL_API KaxFileReferral : public EbmlBinary {
	public:
		KaxFileReferral() {}
		KaxFileReferral(const KaxFileReferral & ElementToClone) :EbmlBinary(ElementToClone){}
		bool ValidateSize() const {return true;} // we don't mind about what's inside
		
        EBML_CONCRETE_CLASS(KaxFileReferral)
};

class MATROSKA_DLL_API KaxFileUID : public EbmlUInteger {
	public:
		KaxFileUID() {}
		KaxFileUID(const KaxFileUID & ElementToClone) : EbmlUInteger(ElementToClone) {}
        
        EBML_CONCRETE_CLASS(KaxFileUID)
};

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_ATTACHED_H
