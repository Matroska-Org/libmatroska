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
	\version \$Id: KaxContentEncoding.cpp 640 2004-07-09 21:05:36Z mosu $
	\author Moritz Bunkus <moritz @ bunkus.org>
*/
#include "matroska/KaxContentEncoding.h"
#include "matroska/KaxContexts.h"
#include "matroska/KaxDefines.h"

START_LIBMATROSKA_NAMESPACE

DEFINE_START_SEMANTIC(KaxContentEncodings)
DEFINE_SEMANTIC_ITEM(true, false, KaxContentEncoding)
DEFINE_END_SEMANTIC(KaxContentEncodings)

DEFINE_START_SEMANTIC(KaxContentEncoding)
DEFINE_SEMANTIC_ITEM(true, true, KaxContentEncodingOrder)
DEFINE_SEMANTIC_ITEM(true, true, KaxContentEncodingScope)
DEFINE_SEMANTIC_ITEM(true, true, KaxContentEncodingType)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentCompression)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentEncryption)
DEFINE_END_SEMANTIC(KaxContentEncoding)

DEFINE_START_SEMANTIC(KaxContentCompression)
DEFINE_SEMANTIC_ITEM(true, true, KaxContentCompAlgo)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentCompSettings)
DEFINE_END_SEMANTIC(KaxContentCompression)

DEFINE_START_SEMANTIC(KaxContentEncryption)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentEncAlgo)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentEncKeyID)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentSignature)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentSigKeyID)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentSigAlgo)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentSigHashAlgo)
DEFINE_END_SEMANTIC(KaxContentEncryption)

DEFINE_MKX_MASTER      (KaxContentEncodings,     0x6d80, 2, KaxTrackEntry, "ContentEncodings");
DEFINE_MKX_MASTER      (KaxContentEncoding,      0x6240, 2, KaxContentEncodings, "ContentEncoding");
DEFINE_MKX_UINTEGER_DEF(KaxContentEncodingOrder, 0x5031, 2, KaxContentEncoding, "ContentEncodingOrder", 0);
DEFINE_MKX_UINTEGER_DEF(KaxContentEncodingScope, 0x5032, 2, KaxContentEncoding, "ContentEncodingScope", 1);
DEFINE_MKX_UINTEGER_DEF(KaxContentEncodingType,  0x5033, 2, KaxContentEncoding, "ContentEncodingType", 0);
DEFINE_MKX_MASTER      (KaxContentCompression,   0x5034, 2, KaxContentEncoding, "ContentCompression");
DEFINE_MKX_UINTEGER_DEF(KaxContentCompAlgo,      0x4254, 2, KaxContentCompression, "ContentCompAlgo", 0);
DEFINE_MKX_BINARY      (KaxContentCompSettings,  0x4255, 2, KaxContentCompression, "ContentCompSettings");
DEFINE_MKX_MASTER      (KaxContentEncryption,    0x5035, 2, KaxContentEncoding, "ContentEncryption");
DEFINE_MKX_UINTEGER_DEF(KaxContentEncAlgo,       0x47e1, 2, KaxContentEncryption, "ContentEncAlgo", 0);
DEFINE_MKX_BINARY      (KaxContentEncKeyID,      0x47e2, 2, KaxContentEncryption, "ContentEncKeyID");
DEFINE_MKX_BINARY      (KaxContentSignature,     0x47e3, 2, KaxContentEncryption, "ContentSignature");
DEFINE_MKX_BINARY      (KaxContentSigKeyID,      0x47e4, 2, KaxContentEncryption, "ContentSigKeyID");
DEFINE_MKX_UINTEGER_DEF(KaxContentSigAlgo,       0x47e5, 2, KaxContentEncryption, "ContentSigAlgo", 0);
DEFINE_MKX_UINTEGER_DEF(KaxContentSigHashAlgo,   0x47e6, 2, KaxContentEncryption, "ContentSigHashAlgo", 0);

END_LIBMATROSKA_NAMESPACE
