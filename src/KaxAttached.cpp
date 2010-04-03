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

#if MATROSKA_VERSION == 1
static const EbmlSemantic ContextList_KaxAttached[5] =
#else // MATROSKA_VERSION
static const EbmlSemantic ContextList_KaxAttached[6] =
#endif // MATROSKA_VERSION
{
	EbmlSemantic(true,  true, EBML_INFO(KaxFileName)),
	EbmlSemantic(true,  true, EBML_INFO(KaxMimeType)),
	EbmlSemantic(true,  true, EBML_INFO(KaxFileData)),
	EbmlSemantic(false, true, EBML_INFO(KaxFileDescription)),
	EbmlSemantic(true,  true, EBML_INFO(KaxFileUID)),
#if MATROSKA_VERSION >= 2
	EbmlSemantic(false, true, EBML_INFO(KaxFileReferral)),
#endif // MATROSKA_VERSION
};

DEFINE_MKX_MASTER   (KaxAttached,        0x61A7, 2, KaxAttachments, "AttachedFile");
DEFINE_MKX_UNISTRING(KaxFileDescription, 0x467E, 2, KaxAttachments, "FileDescription");
DEFINE_MKX_UNISTRING(KaxFileName,        0x466E, 2, KaxAttachments, "FileName");
DEFINE_MKX_STRING   (KaxMimeType,        0x4660, 2, KaxAttachments, "FileMimeType");
DEFINE_MKX_BINARY   (KaxFileData,        0x465C, 2, KaxAttachments, "FileData");
DEFINE_MKX_UINTEGER (KaxFileUID,         0x46AE, 2, KaxAttachments, "FileUID");
#if MATROSKA_VERSION >= 2
DEFINE_MKX_BINARY   (KaxFileReferral,    0x4675, 2, KaxAttachments, "FileReferral");
#endif

KaxAttached::KaxAttached()
 :EbmlMaster(KaxAttached_Context)
{
	SetSizeLength(2); // mandatory min size support (for easier updating) (2^(7*2)-2 = 16Ko)
}

END_LIBMATROSKA_NAMESPACE
