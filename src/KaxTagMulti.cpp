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
	\version \$Id: KaxTagMulti.cpp 640 2004-07-09 21:05:36Z mosu $
	\author Jory Stone       <jcsston @ toughguy.net>
	\author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include "matroska/KaxTagMulti.h"
#include "matroska/KaxContexts.h"
#include "matroska/KaxDefines.h"

using namespace LIBEBML_NAMESPACE;

START_LIBMATROSKA_NAMESPACE

DEFINE_START_SEMANTIC(KaxTagMultiGlobal)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagMultiComment)
DEFINE_END_SEMANTIC(KaxTagMultiGlobal)

DEFINE_START_SEMANTIC(KaxTagMultiComment)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiCommentName)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiCommentComments)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiCommentLanguage)
DEFINE_END_SEMANTIC(KaxTagMultiComment)

DEFINE_START_SEMANTIC(KaxTagMultiCommercial)
DEFINE_SEMANTIC_ITEM(true, false, KaxTagCommercial)
DEFINE_END_SEMANTIC(KaxTagMultiCommercial)

DEFINE_START_SEMANTIC(KaxTagCommercial)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagMultiCommercialType)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiCommercialAddress)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagMultiCommercialURL)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagMultiCommercialEmail)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagMultiPrice)
DEFINE_END_SEMANTIC(KaxTagCommercial)

DEFINE_START_SEMANTIC(KaxTagMultiPrice)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiPriceCurrency)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiPriceAmount)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiPricePriceDate)
DEFINE_END_SEMANTIC(KaxTagMultiPrice)

DEFINE_START_SEMANTIC(KaxTagMultiDate)
DEFINE_SEMANTIC_ITEM(true, false, KaxTagDate)
DEFINE_END_SEMANTIC(KaxTagMultiDate)

DEFINE_START_SEMANTIC(KaxTagDate)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagMultiDateType)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiDateDateBegin)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiDateDateEnd)
DEFINE_END_SEMANTIC(KaxTagDate)

DEFINE_START_SEMANTIC(KaxTagMultiEntity)
DEFINE_SEMANTIC_ITEM(true, false, KaxTagEntity)
DEFINE_END_SEMANTIC(KaxTagMultiEntity)

DEFINE_START_SEMANTIC(KaxTagEntity)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagMultiEntityType)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiEntityName)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagMultiEntityURL)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagMultiEntityEmail)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiEntityAddress)
DEFINE_END_SEMANTIC(KaxTagEntity)

DEFINE_START_SEMANTIC(KaxTagMultiIdentifier)
DEFINE_SEMANTIC_ITEM(true, false, KaxTagIdentifier)
DEFINE_END_SEMANTIC(KaxTagMultiIdentifier)

DEFINE_START_SEMANTIC(KaxTagIdentifier)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagMultiIdentifierType)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiIdentifierBinary)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiIdentifierString)
DEFINE_END_SEMANTIC(KaxTagIdentifier)

DEFINE_START_SEMANTIC(KaxTagMultiLegal)
DEFINE_SEMANTIC_ITEM(true, false, KaxTagLegal)
DEFINE_END_SEMANTIC(KaxTagMultiLegal)

DEFINE_START_SEMANTIC(KaxTagLegal)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagMultiLegalType)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiLegalContent)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagMultiLegalURL)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiLegalAddress)
DEFINE_END_SEMANTIC(KaxTagLegal)

DEFINE_START_SEMANTIC(KaxTagMultiTitle)
DEFINE_SEMANTIC_ITEM(true, false, KaxTagTitle)
DEFINE_END_SEMANTIC(KaxTagMultiTitle)

DEFINE_START_SEMANTIC(KaxTagTitle)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagMultiTitleType)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiTitleName)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiTitleSubTitle)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiTitleEdition)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiTitleAddress)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagMultiTitleURL)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagMultiTitleEmail)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagMultiTitleLanguage)
DEFINE_END_SEMANTIC(KaxTagTitle)

DEFINE_START_SEMANTIC(KaxTagMultiAttachment)
DEFINE_SEMANTIC_ITEM(true, false, KaxTagAttachment)
DEFINE_END_SEMANTIC(KaxTagMultiAttachment)

DEFINE_START_SEMANTIC(KaxTagAttachment)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagAttachmentID)
DEFINE_END_SEMANTIC(KaxTagAttachment)


DEFINE_MKX_CONTEXT(KaxTagMultiGlobal);

const EbmlSemanticContext & GetKaxTagsGlobal_Context()
{
	return Context_KaxTagMultiGlobal;
}

#define DEFINE_TAG_MASTER(a,b,c,d,e)   DEFINE_xxx_MASTER(a,b,c,d,e,*GetKaxTagsGlobal_Context)


DEFINE_MKX_MASTER   (KaxTagMultiComment,           0x5B7B, 2, KaxTag, "MultiComment");
DEFINE_MKX_STRING   (KaxTagMultiCommentName,       0x5F7D, 2, KaxTagMultiComment, "MultiCommentName");
DEFINE_MKX_UNISTRING(KaxTagMultiCommentComments,   0x5F7C, 2, KaxTagMultiComment, "MultiCommentComments");
DEFINE_MKX_STRING   (KaxTagMultiCommentLanguage, 0x22B59D, 3, KaxTagMultiComment, "MultiCommentLanguage");

DEFINE_TAG_MASTER   (KaxTagMultiCommercial,        0x4DC7, 2, KaxTag, "MultiCommercial");
DEFINE_TAG_MASTER   (KaxTagCommercial,             0x4EC7, 2, KaxTagMultiCommercial, "Commercial");
DEFINE_MKX_UINTEGER (KaxTagMultiCommercialType,    0x5BD7, 2, KaxTagCommercial, "MultiCommercialType");
DEFINE_MKX_UNISTRING(KaxTagMultiCommercialAddress, 0x5BBB, 2, KaxTagCommercial, "MultiCommercialAddress");
DEFINE_MKX_STRING   (KaxTagMultiCommercialURL,     0x5BDA, 2, KaxTagCommercial, "MultiCommercialURL");
DEFINE_MKX_STRING   (KaxTagMultiCommercialEmail,   0x5BC0, 2, KaxTagCommercial, "MultiCommercialEmail");
DEFINE_TAG_MASTER   (KaxTagMultiPrice,             0x5BC3, 2, KaxTagCommercial, "MultiPrice");
DEFINE_MKX_STRING   (KaxTagMultiPriceCurrency,     0x5B6C, 2, KaxTagMultiPrice, "MultiPriceCurrency");
DEFINE_MKX_FLOAT    (KaxTagMultiPriceAmount,       0x5B6E, 2, KaxTagMultiPrice, "MultiPriceAmount");
DEFINE_MKX_DATE     (KaxTagMultiPricePriceDate,    0x5B6F, 2, KaxTagMultiPrice, "MultiPricePriceDate");

DEFINE_TAG_MASTER   (KaxTagMultiDate,              0x4DC8, 2, KaxTag, "MultiDate");
DEFINE_TAG_MASTER   (KaxTagDate,                   0x4EC8, 2, KaxTagMultiDate, "Date");
DEFINE_MKX_UINTEGER (KaxTagMultiDateType,          0x5BD8, 2, KaxTagDate, "MultiDateType");
DEFINE_MKX_DATE     (KaxTagMultiDateDateBegin,     0x4460, 2, KaxTagDate, "MultiDateDateBegin");
DEFINE_MKX_DATE     (KaxTagMultiDateDateEnd,       0x4462, 2, KaxTagDate, "MultiDateDateEnd");

DEFINE_TAG_MASTER   (KaxTagMultiEntity,            0x4DC9, 2, KaxTag, "MultiEntity");
DEFINE_TAG_MASTER   (KaxTagEntity,                 0x4EC9, 2, KaxTagMultiEntity, "Entity");
DEFINE_MKX_UINTEGER (KaxTagMultiEntityType,        0x5BD9, 2, KaxTagEntity, "MultiEntityType");
DEFINE_MKX_UNISTRING(KaxTagMultiEntityName,        0x5BED, 2, KaxTagEntity, "MultiEntityName");
DEFINE_MKX_STRING   (KaxTagMultiEntityURL,         0x5BDB, 2, KaxTagEntity, "MultiEntityURL");
DEFINE_MKX_STRING   (KaxTagMultiEntityEmail,       0x5BC1, 2, KaxTagEntity, "MultiEntityEmail");
DEFINE_MKX_UNISTRING(KaxTagMultiEntityAddress,     0x5BDC, 2, KaxTagEntity, "MultiEntityAddress");

DEFINE_TAG_MASTER   (KaxTagMultiIdentifier,        0x4DC6, 2, KaxTag, "MultiIdentifier");
DEFINE_TAG_MASTER   (KaxTagIdentifier,             0x4EC6, 2, KaxTagMultiIdentifier, "Identifier");
DEFINE_MKX_UINTEGER (KaxTagMultiIdentifierType,    0x5BAD, 2, KaxTagIdentifier, "MultiIdentifierType");
DEFINE_MKX_BINARY   (KaxTagMultiIdentifierBinary,  0x6B67, 2, KaxTagIdentifier, "MultiIdentifierBinary");
DEFINE_MKX_UNISTRING(KaxTagMultiIdentifierString,  0x6B68, 2, KaxTagIdentifier, "MultiIdentifierString");

DEFINE_TAG_MASTER   (KaxTagMultiLegal,             0x4DC5, 2, KaxTag, "MultiLegal");
DEFINE_TAG_MASTER   (KaxTagLegal,                  0x4EC5, 2, KaxTagMultiLegal, "Legal");
DEFINE_MKX_UINTEGER (KaxTagMultiLegalType,         0x5BBD, 2, KaxTagLegal, "MultiLegalType");
DEFINE_MKX_UNISTRING(KaxTagMultiLegalContent,      0x5BB2, 2, KaxTagLegal, "MultiLegalContent");
DEFINE_MKX_STRING   (KaxTagMultiLegalURL,          0x5B34, 2, KaxTagLegal, "MultiLegalURL");
DEFINE_MKX_UNISTRING(KaxTagMultiLegalAddress,      0x5B9B, 2, KaxTagLegal, "MultiLegalAddress");

DEFINE_TAG_MASTER   (KaxTagMultiTitle,             0x4DC4, 2, KaxTag, "MultiTitle");
DEFINE_TAG_MASTER   (KaxTagTitle,                  0x4EC4, 2, KaxTagMultiTitle, "Title");
DEFINE_MKX_UINTEGER (KaxTagMultiTitleType,         0x5B7D, 2, KaxTagTitle, "MultiTitleType");
DEFINE_MKX_UNISTRING(KaxTagMultiTitleName,         0x5BB9, 2, KaxTagTitle, "MultiTitleName");
DEFINE_MKX_UNISTRING(KaxTagMultiTitleSubTitle,     0x5B5B, 2, KaxTagTitle, "MultiTitleSubTitle");
DEFINE_MKX_UNISTRING(KaxTagMultiTitleEdition,      0x5BAE, 2, KaxTagTitle, "MultiTitleEdition");
DEFINE_MKX_UNISTRING(KaxTagMultiTitleAddress,      0x5B33, 2, KaxTagTitle, "MultiTitleAddress");
DEFINE_MKX_STRING   (KaxTagMultiTitleURL,          0x5BA9, 2, KaxTagTitle, "MultiTitleURL");
DEFINE_MKX_STRING   (KaxTagMultiTitleEmail,        0x5BC9, 2, KaxTagTitle, "MultiTitleEmail");
DEFINE_MKX_STRING   (KaxTagMultiTitleLanguage,   0x22B59E, 3, KaxTagTitle, "MultiTitleLanguage");

DEFINE_TAG_MASTER   (KaxTagMultiAttachment,        0x4DC3, 2, KaxTag, "MultiAttachment");
DEFINE_TAG_MASTER   (KaxTagAttachment,             0x4EC3, 2, KaxTagMultiAttachment, "Attachment");
DEFINE_MKX_UINTEGER (KaxTagAttachmentID,           0x5BA0, 2, KaxTagAttachment, "AttachmentID");

END_LIBMATROSKA_NAMESPACE
