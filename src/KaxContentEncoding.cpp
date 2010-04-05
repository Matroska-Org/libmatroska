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

static const EbmlSemantic ContextList_KaxContentEncodings[1] = {
  EbmlSemantic(true, true, EBML_INFO(KaxContentEncoding)),
};

static const EbmlSemantic ContextList_KaxContentEncoding[5] = {
  EbmlSemantic(true, true, EBML_INFO(KaxContentEncodingOrder)),
  EbmlSemantic(true, true, EBML_INFO(KaxContentEncodingScope)),
  EbmlSemantic(true, true, EBML_INFO(KaxContentEncodingType)),
  EbmlSemantic(false, true, EBML_INFO(KaxContentCompression)),
  EbmlSemantic(false, true, EBML_INFO(KaxContentEncryption)),
};

static const EbmlSemantic ContextList_KaxContentCompression[2] = {
  EbmlSemantic(true, true, EBML_INFO(KaxContentCompAlgo)),
  EbmlSemantic(false, true, EBML_INFO(KaxContentCompSettings)),
};

static const EbmlSemantic ContextList_KaxContentEncryption[6] = {
  EbmlSemantic(false, true, EBML_INFO(KaxContentEncAlgo)),
  EbmlSemantic(false, true, EBML_INFO(KaxContentEncKeyID)),
  EbmlSemantic(false, true, EBML_INFO(KaxContentSignature)),
  EbmlSemantic(false, true, EBML_INFO(KaxContentSigKeyID)),
  EbmlSemantic(false, true, EBML_INFO(KaxContentSigAlgo)),
  EbmlSemantic(false, true, EBML_INFO(KaxContentSigHashAlgo)),
};

DEFINE_MKX_MASTER  (KaxContentEncodings,     0x6d80, 2, KaxTrackEntry, "ContentEncodings");
DEFINE_MKX_MASTER  (KaxContentEncoding,      0x6240, 2, KaxContentEncodings, "ContentEncoding");
DEFINE_MKX_UINTEGER(KaxContentEncodingOrder, 0x5031, 2, KaxContentEncoding, "ContentEncodingOrder");
DEFINE_MKX_UINTEGER(KaxContentEncodingScope, 0x5032, 2, KaxContentEncoding, "ContentEncodingScope");
DEFINE_MKX_UINTEGER(KaxContentEncodingType,  0x5033, 2, KaxContentEncoding, "ContentEncodingType");
DEFINE_MKX_MASTER  (KaxContentCompression,   0x5034, 2, KaxContentEncoding, "ContentCompression");
DEFINE_MKX_UINTEGER(KaxContentCompAlgo,      0x4254, 2, KaxContentCompression, "ContentCompAlgo");
DEFINE_MKX_UINTEGER(KaxContentCompSettings,  0x4255, 2, KaxContentCompression, "ContentCompSettings");
DEFINE_MKX_MASTER  (KaxContentEncryption,    0x5035, 2, KaxContentEncoding, "ContentEncryption");
DEFINE_MKX_UINTEGER(KaxContentEncAlgo,       0x47e1, 2, KaxContentEncryption, "ContentEncAlgo");
DEFINE_MKX_BINARY  (KaxContentEncKeyID,      0x47e2, 2, KaxContentEncryption, "ContentEncKeyID");
DEFINE_MKX_BINARY  (KaxContentSignature,     0x47e3, 2, KaxContentEncryption, "ContentSignature");
DEFINE_MKX_BINARY  (KaxContentSigKeyID,      0x47e4, 2, KaxContentEncryption, "ContentSigKeyID");
DEFINE_MKX_UINTEGER(KaxContentSigAlgo,       0x47e5, 2, KaxContentEncryption, "ContentSigAlgo");
DEFINE_MKX_UINTEGER(KaxContentSigHashAlgo,   0x47e6, 2, KaxContentEncryption, "ContentSigHashAlgo");

END_LIBMATROSKA_NAMESPACE
