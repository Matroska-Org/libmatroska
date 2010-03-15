/****************************************************************************
** libmatroska : parse Matroska files, see http://www.matroska.org/
**
** <file/class description>
**
** Copyright (C) 2002-2004 Steve Lhomme.  All rights reserved.
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
	\version \$Id: KaxContentEncoding.h,v 1.7 2004/04/14 23:26:17 robux4 Exp $
	\author Moritz Bunkus <moritz @ bunkus.org>
*/
#ifndef LIBMATROSKA_CONTENT_ENCODING_H
#define LIBMATROSKA_CONTENT_ENCODING_H

#include "matroska/KaxTypes.h"
#include "ebml/EbmlMaster.h"
#include "ebml/EbmlUInteger.h"
#include "ebml/EbmlBinary.h"

using namespace LIBEBML_NAMESPACE;

START_LIBMATROSKA_NAMESPACE

class MATROSKA_DLL_API KaxContentEncodings: public EbmlMaster {
    public:
        KaxContentEncodings();
        KaxContentEncodings(const KaxContentEncodings &ElementToClone):
            EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxContentEncodings)
};

class MATROSKA_DLL_API KaxContentEncoding: public EbmlMaster {
    public:
        KaxContentEncoding();
        KaxContentEncoding(const KaxContentEncoding &ElementToClone):
            EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxContentEncoding)
};

class MATROSKA_DLL_API KaxContentEncodingOrder: public EbmlUInteger {
    public:
        KaxContentEncodingOrder(): EbmlUInteger(0) {}
        KaxContentEncodingOrder(const KaxContentEncodingOrder &ElementToClone):
            EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxContentEncodingOrder)
};

class MATROSKA_DLL_API KaxContentEncodingScope: public EbmlUInteger {
    public:
        KaxContentEncodingScope(): EbmlUInteger(1) {}
        KaxContentEncodingScope(const KaxContentEncodingScope &ElementToClone):
        EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxContentEncodingScope)
};

class MATROSKA_DLL_API KaxContentEncodingType: public EbmlUInteger {
    public:
        KaxContentEncodingType(): EbmlUInteger(0) {}
        KaxContentEncodingType(const KaxContentEncodingType &ElementToClone):
            EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxContentEncodingType)
};

class MATROSKA_DLL_API KaxContentCompression: public EbmlMaster {
    public:
        KaxContentCompression();
        KaxContentCompression(const KaxContentCompression &ElementToClone):
            EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxContentCompression)
};

class MATROSKA_DLL_API KaxContentCompAlgo: public EbmlUInteger {
    public:
        KaxContentCompAlgo(): EbmlUInteger(0) {}
        KaxContentCompAlgo(const KaxContentCompAlgo &ElementToClone):
            EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxContentCompAlgo)
};

class MATROSKA_DLL_API KaxContentCompSettings: public EbmlBinary {
    public:
        KaxContentCompSettings() {}
        KaxContentCompSettings(const KaxContentCompSettings &ElementToClone):
            EbmlBinary(ElementToClone) {}
        bool ValidateSize(void) const { return true; }

        EBML_CONCRETE_CLASS(KaxContentCompSettings)
};

class MATROSKA_DLL_API KaxContentEncryption: public EbmlMaster {
    public:
        KaxContentEncryption();
        KaxContentEncryption(const KaxContentEncryption &ElementToClone):
            EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxContentEncryption)
};

class MATROSKA_DLL_API KaxContentEncAlgo: public EbmlUInteger {
    public:
        KaxContentEncAlgo(): EbmlUInteger(0) {}
        KaxContentEncAlgo(const KaxContentEncAlgo &ElementToClone):
            EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxContentEncAlgo)
};

class MATROSKA_DLL_API KaxContentEncKeyID: public EbmlBinary {
    public:
        KaxContentEncKeyID() {}
        KaxContentEncKeyID(const KaxContentEncKeyID &ElementToClone):
            EbmlBinary(ElementToClone) {}
        bool ValidateSize(void) const { return true; }

        EBML_CONCRETE_CLASS(KaxContentEncKeyID)
};

class MATROSKA_DLL_API KaxContentSignature: public EbmlBinary {
    public:
        KaxContentSignature() {}
        KaxContentSignature(const KaxContentSignature &ElementToClone):
            EbmlBinary(ElementToClone) {}
        bool ValidateSize(void) const { return true; }

        EBML_CONCRETE_CLASS(KaxContentSignature)
};

class MATROSKA_DLL_API KaxContentSigKeyID: public EbmlBinary {
    public:
        KaxContentSigKeyID() {}
        KaxContentSigKeyID(const KaxContentSigKeyID &ElementToClone):
            EbmlBinary(ElementToClone) {}
        bool ValidateSize(void) const { return true; }

        EBML_CONCRETE_CLASS(KaxContentSigKeyID)
};

class MATROSKA_DLL_API KaxContentSigAlgo: public EbmlUInteger {
    public:
        KaxContentSigAlgo() {}
        KaxContentSigAlgo(const KaxContentSigAlgo &ElementToClone):
            EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxContentSigAlgo)
};

class MATROSKA_DLL_API KaxContentSigHashAlgo: public EbmlUInteger {
    public:
        KaxContentSigHashAlgo() {}
        KaxContentSigHashAlgo(const KaxContentSigHashAlgo &ElementToClone):
            EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxContentSigHashAlgo)
};

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_CONTENT_ENCODING_H
