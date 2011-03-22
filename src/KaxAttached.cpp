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
	\version \$Id: KaxAttached.cpp 1202 2005-08-30 14:39:01Z robux4 $
	\author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include "matroska/KaxAttached.h"
#include "matroska/KaxContexts.h"
#include "matroska/KaxDefines.h"

// sub elements

using namespace LIBEBML_NAMESPACE;

START_LIBMATROSKA_NAMESPACE

DEFINE_START_SEMANTIC(KaxAttached)
DEFINE_SEMANTIC_ITEM(true, true, KaxFileName)
DEFINE_SEMANTIC_ITEM(true, true, KaxMimeType)
DEFINE_SEMANTIC_ITEM(true, true, KaxFileData)
DEFINE_SEMANTIC_ITEM(false, true, KaxFileDescription)
DEFINE_SEMANTIC_ITEM(true, true, KaxFileUID)
#if MATROSKA_VERSION >= 2
DEFINE_SEMANTIC_ITEM(false, true, KaxFileReferral)
#endif // MATROSKA_VERSION
DEFINE_END_SEMANTIC(KaxAttached)

DEFINE_MKX_MASTER_CONS(KaxAttached,        0x61A7, 2, KaxAttachments, "AttachedFile");
DEFINE_MKX_UNISTRING  (KaxFileDescription, 0x467E, 2, KaxAttached, "FileDescription");
DEFINE_MKX_UNISTRING  (KaxFileName,        0x466E, 2, KaxAttached, "FileName");
DEFINE_MKX_STRING     (KaxMimeType,        0x4660, 2, KaxAttached, "FileMimeType");
DEFINE_MKX_BINARY     (KaxFileData,        0x465C, 2, KaxAttached, "FileData");
DEFINE_MKX_UINTEGER   (KaxFileUID,         0x46AE, 2, KaxAttached, "FileUID");
#if MATROSKA_VERSION >= 2
DEFINE_MKX_BINARY     (KaxFileReferral,    0x4675, 2, KaxAttached, "FileReferral");
#endif

KaxAttached::KaxAttached(EBML_EXTRA_DEF)
 :EbmlMaster(EBML_CLASS_SEMCONTEXT(KaxAttached) EBML_DEF_SEP EBML_EXTRA_CALL)
{
	SetSizeLength(2); // mandatory min size support (for easier updating) (2^(7*2)-2 = 16Ko)
}

END_LIBMATROSKA_NAMESPACE
