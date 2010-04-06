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
	\version \$Id: KaxContentEncoding.h,v 1.7 2004/04/14 23:26:17 robux4 Exp $
	\author Moritz Bunkus <moritz @ bunkus.org>
*/
#ifndef LIBMATROSKA_CONTENT_ENCODING_H
#define LIBMATROSKA_CONTENT_ENCODING_H

#include "matroska/KaxTypes.h"
#include "ebml/EbmlMaster.h"
#include "ebml/EbmlUInteger.h"
#include "ebml/EbmlBinary.h"
#include "matroska/KaxDefines.h"

using namespace LIBEBML_NAMESPACE;

START_LIBMATROSKA_NAMESPACE

DECLARE_MKX_MASTER(KaxContentEncodings)
    public:
        KaxContentEncodings(const KaxContentEncodings &ElementToClone):
            EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxContentEncodings)
};

DECLARE_MKX_MASTER(KaxContentEncoding)
    public:
        KaxContentEncoding(const KaxContentEncoding &ElementToClone):
            EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxContentEncoding)
};

DECLARE_MKX_UINTEGER(KaxContentEncodingOrder)
    public:
        KaxContentEncodingOrder(const KaxContentEncodingOrder &ElementToClone):
            EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxContentEncodingOrder)
};

DECLARE_MKX_UINTEGER(KaxContentEncodingScope)
    public:
        KaxContentEncodingScope(const KaxContentEncodingScope &ElementToClone):
        EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxContentEncodingScope)
};

DECLARE_MKX_UINTEGER(KaxContentEncodingType)
    public:
        KaxContentEncodingType(const KaxContentEncodingType &ElementToClone):
            EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxContentEncodingType)
};

DECLARE_MKX_MASTER(KaxContentCompression)
    public:
        KaxContentCompression(const KaxContentCompression &ElementToClone):
            EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxContentCompression)
};

DECLARE_MKX_UINTEGER(KaxContentCompAlgo)
    public:
        KaxContentCompAlgo(const KaxContentCompAlgo &ElementToClone):
            EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxContentCompAlgo)
};

DECLARE_MKX_BINARY(KaxContentCompSettings)
    public:
        KaxContentCompSettings(const KaxContentCompSettings &ElementToClone):
            EbmlBinary(ElementToClone) {}
        bool ValidateSize(void) const { return true; }

        EBML_CONCRETE_CLASS(KaxContentCompSettings)
};

DECLARE_MKX_MASTER(KaxContentEncryption)
    public:
        KaxContentEncryption(const KaxContentEncryption &ElementToClone):
            EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxContentEncryption)
};

DECLARE_MKX_UINTEGER(KaxContentEncAlgo)
    public:
        KaxContentEncAlgo(const KaxContentEncAlgo &ElementToClone):
            EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxContentEncAlgo)
};

DECLARE_MKX_BINARY(KaxContentEncKeyID)
    public:
        KaxContentEncKeyID(const KaxContentEncKeyID &ElementToClone):
            EbmlBinary(ElementToClone) {}
        bool ValidateSize(void) const { return true; }

        EBML_CONCRETE_CLASS(KaxContentEncKeyID)
};

DECLARE_MKX_BINARY(KaxContentSignature)
    public:
        KaxContentSignature(const KaxContentSignature &ElementToClone):
            EbmlBinary(ElementToClone) {}
        bool ValidateSize(void) const { return true; }

        EBML_CONCRETE_CLASS(KaxContentSignature)
};

DECLARE_MKX_BINARY(KaxContentSigKeyID)
    public:
        KaxContentSigKeyID(const KaxContentSigKeyID &ElementToClone):
            EbmlBinary(ElementToClone) {}
        bool ValidateSize(void) const { return true; }

        EBML_CONCRETE_CLASS(KaxContentSigKeyID)
};

DECLARE_MKX_UINTEGER(KaxContentSigAlgo)
    public:
        KaxContentSigAlgo(const KaxContentSigAlgo &ElementToClone):
            EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxContentSigAlgo)
};

DECLARE_MKX_UINTEGER(KaxContentSigHashAlgo)
    public:
        KaxContentSigHashAlgo(const KaxContentSigHashAlgo &ElementToClone):
            EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxContentSigHashAlgo)
};

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_CONTENT_ENCODING_H
