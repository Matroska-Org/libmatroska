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
	\version \$Id: KaxTag.cpp 1325 2009-03-30 07:56:54Z robux4 $
	\author Jory Stone       <jcsston @ toughguy.net>
	\author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include "matroska/KaxTag.h"
#include "matroska/KaxContexts.h"
#include "matroska/KaxDefines.h"

using namespace LIBEBML_NAMESPACE;

// sub elements
START_LIBMATROSKA_NAMESPACE

DEFINE_START_SEMANTIC(KaxTag)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagTargets)
DEFINE_SEMANTIC_ITEM(true, false, KaxTagSimple)
DEFINE_END_SEMANTIC(KaxTag)

DEFINE_START_SEMANTIC(KaxTagTargets)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagTargetTypeValue)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagTargetType)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagTrackUID)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagEditionUID)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagChapterUID)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagAttachmentUID)
DEFINE_END_SEMANTIC(KaxTagTargets)

DEFINE_START_SEMANTIC(KaxTagSimple)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagName)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagLangue)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagDefault)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagString)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagBinary)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagSimple)
DEFINE_END_SEMANTIC(KaxTagSimple)

DEFINE_MKX_MASTER      (KaxTag,                       0x7373, 2, KaxTags, "Tag");
DEFINE_MKX_MASTER      (KaxTagTargets,                0x63C0, 2, KaxTag, "TagTargets");
DEFINE_MKX_UINTEGER_DEF(KaxTagTargetTypeValue,        0x68CA, 2, KaxTagTargets, "TagTargetTypeValue", 50);
DEFINE_MKX_STRING      (KaxTagTargetType,             0x63CA, 2, KaxTagTargets, "TagTargetType");
DEFINE_MKX_UINTEGER_DEF(KaxTagTrackUID,               0x63C5, 2, KaxTagTargets, "TagTrackUID", 0);
DEFINE_MKX_UINTEGER_DEF(KaxTagEditionUID,             0x63C9, 2, KaxTagTargets, "TagEditionUID", 0);
DEFINE_MKX_UINTEGER_DEF(KaxTagChapterUID,             0x63C4, 2, KaxTagTargets, "TagChapterUID", 0);
DEFINE_MKX_UINTEGER_DEF(KaxTagAttachmentUID,          0x63C6, 2, KaxTagTargets, "TagAttachmentUID", 0);

DEFINE_MKX_MASTER      (KaxTagSimple,                 0x67C8, 2, KaxTag, "TagSimple");
DEFINE_MKX_UNISTRING   (KaxTagName,                   0x45A3, 2, KaxTagSimple, "TagName");
DEFINE_MKX_STRING_DEF  (KaxTagLangue,                 0x447A, 2, KaxTagSimple, "TagLanguage", "und");
DEFINE_MKX_UINTEGER_DEF(KaxTagDefault,                0x4484, 2, KaxTagSimple, "TagDefault", 1);
DEFINE_MKX_UNISTRING   (KaxTagString,                 0x4487, 2, KaxTagSimple, "TagString");
DEFINE_MKX_BINARY      (KaxTagBinary,                 0x4485, 2, KaxTagSimple, "TagBinary");

END_LIBMATROSKA_NAMESPACE
