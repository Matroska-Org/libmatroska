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

static const EbmlSemantic ContextList_KaxTagMultiGlobal[1] =
{
	EbmlSemantic(false, false, EBML_INFO(KaxTagMultiComment)),
};

static const EbmlSemantic ContextList_KaxTagMultiComment[3] =
{
	EbmlSemantic(false, true, EBML_INFO(KaxTagMultiCommentName)),
	EbmlSemantic(false, true, EBML_INFO(KaxTagMultiCommentComments)),
	EbmlSemantic(false, true, EBML_INFO(KaxTagMultiCommentLanguage)),
};

static const EbmlSemantic ContextList_KaxTagMultiCommercial[1] =
{
	EbmlSemantic(true, false, EBML_INFO(KaxTagCommercial)),
};

static const EbmlSemantic ContextList_KaxTagCommercial[5] =
{
	EbmlSemantic(true,  true,  EBML_INFO(KaxTagMultiCommercialType)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagMultiCommercialAddress)),
	EbmlSemantic(false, false, EBML_INFO(KaxTagMultiCommercialURL)),
	EbmlSemantic(false, false, EBML_INFO(KaxTagMultiCommercialEmail)),
	EbmlSemantic(false, false, EBML_INFO(KaxTagMultiPrice)),
};

static const EbmlSemantic ContextList_KaxTagMultiPrice[3] =
{
	EbmlSemantic(false, true, EBML_INFO(KaxTagMultiPriceCurrency)),
	EbmlSemantic(false, true, EBML_INFO(KaxTagMultiPriceAmount)),
	EbmlSemantic(false, true, EBML_INFO(KaxTagMultiPricePriceDate)),
};

static const EbmlSemantic ContextList_KaxTagMultiDate[1] =
{
	EbmlSemantic(true, false, EBML_INFO(KaxTagDate)),
};

static const EbmlSemantic ContextList_KaxTagDate[3] =
{
	EbmlSemantic(true,  true, EBML_INFO(KaxTagMultiDateType)),
	EbmlSemantic(false, true, EBML_INFO(KaxTagMultiDateDateBegin)),
	EbmlSemantic(false, true, EBML_INFO(KaxTagMultiDateDateEnd)),
};

static const EbmlSemantic ContextList_KaxTagMultiEntity[1] =
{
	EbmlSemantic(true, false, EBML_INFO(KaxTagEntity)),
};

static const EbmlSemantic ContextList_KaxTagEntity[5] =
{
	EbmlSemantic(true,  true,  EBML_INFO(KaxTagMultiEntityType)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagMultiEntityName)),
	EbmlSemantic(false, false, EBML_INFO(KaxTagMultiEntityURL)),
	EbmlSemantic(false, false, EBML_INFO(KaxTagMultiEntityEmail)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagMultiEntityAddress)),
};

static const EbmlSemantic ContextList_KaxTagMultiIdentifier[1] =
{
	EbmlSemantic(true, false, EBML_INFO(KaxTagIdentifier)),
};

static const EbmlSemantic ContextList_KaxTagIdentifier[3] =
{
	EbmlSemantic(true,  true, EBML_INFO(KaxTagMultiIdentifierType)),
	EbmlSemantic(false, true, EBML_INFO(KaxTagMultiIdentifierBinary)),
	EbmlSemantic(false, true, EBML_INFO(KaxTagMultiIdentifierString)),
};

static const EbmlSemantic ContextList_KaxTagMultiLegal[1] =
{
	EbmlSemantic(true, false, EBML_INFO(KaxTagLegal)),
};

static const EbmlSemantic ContextList_KaxTagLegal[4] =
{
	EbmlSemantic(true,  true,  EBML_INFO(KaxTagMultiLegalType)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagMultiLegalContent)),
	EbmlSemantic(false, false, EBML_INFO(KaxTagMultiLegalURL)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagMultiLegalAddress)),
};

static const EbmlSemantic ContextList_KaxTagMultiTitle[1] =
{
	EbmlSemantic(true, false, EBML_INFO(KaxTagTitle)),
};

static const EbmlSemantic ContextList_KaxTagTitle[8] =
{
	EbmlSemantic(true,  true,  EBML_INFO(KaxTagMultiTitleType)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagMultiTitleName)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagMultiTitleSubTitle)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagMultiTitleEdition)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagMultiTitleAddress)),
	EbmlSemantic(false, false, EBML_INFO(KaxTagMultiTitleURL)),
	EbmlSemantic(false, false, EBML_INFO(KaxTagMultiTitleEmail)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTagMultiTitleLanguage)),
};

static const EbmlSemantic ContextList_KaxTagMultiAttachment[1] =
{
	EbmlSemantic(true, false, EBML_INFO(KaxTagAttachment)),
};

static const EbmlSemantic ContextList_KaxTagAttachment[1] =
{
	EbmlSemantic(false, true,  EBML_INFO(KaxTagAttachmentID)),
};


DEFINE_MKX_CONTEXT(KaxTagMultiGlobal);

const EbmlSemanticContext & GetKaxTagsGlobal_Context()
{
	return Context_KaxTagMultiGlobal;
}


DEFINE_MKX_MASTER   (KaxTagMultiComment,           0x5B7B, 2, KaxTag, "MultiComment");
DEFINE_MKX_STRING   (KaxTagMultiCommentName,       0x5F7D, 2, KaxTagMultiComment, "MultiCommentName");
DEFINE_MKX_UNISTRING(KaxTagMultiCommentComments,   0x5F7C, 2, KaxTagMultiComment, "MultiCommentComments");
DEFINE_MKX_STRING   (KaxTagMultiCommentLanguage, 0x22B59D, 3, KaxTagMultiComment, "MultiCommentLanguage");

DEFINE_xxx_MASTER   (KaxTagMultiCommercial,        0x4DC7, 2, KaxTag, "MultiCommercial", GetKaxTagsGlobal_Context);
DEFINE_xxx_MASTER   (KaxTagCommercial,             0x4EC7, 2, KaxTagMultiCommercial, "Commercial", GetKaxTagsGlobal_Context);
DEFINE_MKX_UINTEGER (KaxTagMultiCommercialType,    0x5BD7, 2, KaxTagCommercial, "MultiCommercialType");
DEFINE_MKX_UNISTRING(KaxTagMultiCommercialAddress, 0x5BBB, 2, KaxTagCommercial, "MultiCommercialAddress");
DEFINE_MKX_STRING   (KaxTagMultiCommercialURL,     0x5BDA, 2, KaxTagCommercial, "MultiCommercialURL");
DEFINE_MKX_STRING   (KaxTagMultiCommercialEmail,   0x5BC0, 2, KaxTagCommercial, "MultiCommercialEmail");
DEFINE_xxx_MASTER   (KaxTagMultiPrice,             0x5BC3, 2, KaxTagCommercial, "MultiPrice", GetKaxTagsGlobal_Context);
DEFINE_MKX_STRING   (KaxTagMultiPriceCurrency,     0x5B6C, 2, KaxTagMultiPrice, "MultiPriceCurrency");
DEFINE_MKX_FLOAT    (KaxTagMultiPriceAmount,       0x5B6E, 2, KaxTagMultiPrice, "MultiPriceAmount");
DEFINE_MKX_DATE     (KaxTagMultiPricePriceDate,    0x5B6F, 2, KaxTagMultiPrice, "MultiPricePriceDate");

DEFINE_xxx_MASTER   (KaxTagMultiDate,              0x4DC8, 2, KaxTag, "MultiDate", GetKaxTagsGlobal_Context);
DEFINE_xxx_MASTER   (KaxTagDate,                   0x4EC8, 2, KaxTagMultiDate, "Date", GetKaxTagsGlobal_Context);
DEFINE_MKX_UINTEGER (KaxTagMultiDateType,          0x5BD8, 2, KaxTagDate, "MultiDateType");
DEFINE_MKX_DATE     (KaxTagMultiDateDateBegin,     0x4460, 2, KaxTagDate, "MultiDateDateBegin");
DEFINE_MKX_DATE     (KaxTagMultiDateDateEnd,       0x4462, 2, KaxTagDate, "MultiDateDateEnd");

DEFINE_xxx_MASTER   (KaxTagMultiEntity,            0x4DC9, 2, KaxTag, "MultiEntity", GetKaxTagsGlobal_Context);
DEFINE_xxx_MASTER   (KaxTagEntity,                 0x4EC9, 2, KaxTagMultiEntity, "Entity", GetKaxTagsGlobal_Context);
DEFINE_MKX_UINTEGER (KaxTagMultiEntityType,        0x5BD9, 2, KaxTagEntity, "MultiEntityType");
DEFINE_MKX_UNISTRING(KaxTagMultiEntityName,        0x5BED, 2, KaxTagEntity, "MultiEntityName");
DEFINE_MKX_STRING   (KaxTagMultiEntityURL,         0x5BDB, 2, KaxTagEntity, "MultiEntityURL");
DEFINE_MKX_STRING   (KaxTagMultiEntityEmail,       0x5BC1, 2, KaxTagEntity, "MultiEntityEmail");
DEFINE_MKX_UNISTRING(KaxTagMultiEntityAddress,     0x5BDC, 2, KaxTagEntity, "MultiEntityAddress");

DEFINE_xxx_MASTER   (KaxTagMultiIdentifier,        0x4DC6, 2, KaxTag, "MultiIdentifier", GetKaxTagsGlobal_Context);
DEFINE_xxx_MASTER   (KaxTagIdentifier,             0x4EC6, 2, KaxTagMultiIdentifier, "Identifier", GetKaxTagsGlobal_Context);
DEFINE_MKX_UINTEGER (KaxTagMultiIdentifierType,    0x5BAD, 2, KaxTagIdentifier, "MultiIdentifierType");
DEFINE_MKX_BINARY   (KaxTagMultiIdentifierBinary,  0x6B67, 2, KaxTagIdentifier, "MultiIdentifierBinary");
DEFINE_MKX_UNISTRING(KaxTagMultiIdentifierString,  0x6B68, 2, KaxTagIdentifier, "MultiIdentifierString");

DEFINE_xxx_MASTER   (KaxTagMultiLegal,             0x4DC5, 2, KaxTag, "MultiLegal", GetKaxTagsGlobal_Context);
DEFINE_xxx_MASTER   (KaxTagLegal,                  0x4EC5, 2, KaxTagMultiLegal, "Legal", GetKaxTagsGlobal_Context);
DEFINE_MKX_UINTEGER (KaxTagMultiLegalType,         0x5BBD, 2, KaxTagLegal, "MultiLegalType");
DEFINE_MKX_UNISTRING(KaxTagMultiLegalContent,      0x5BB2, 2, KaxTagLegal, "MultiLegalContent");
DEFINE_MKX_STRING   (KaxTagMultiLegalURL,          0x5B34, 2, KaxTagLegal, "MultiLegalURL");
DEFINE_MKX_UNISTRING(KaxTagMultiLegalAddress,      0x5B9B, 2, KaxTagLegal, "MultiLegalAddress");

DEFINE_xxx_MASTER   (KaxTagMultiTitle,             0x4DC4, 2, KaxTag, "MultiTitle", GetKaxTagsGlobal_Context);
DEFINE_xxx_MASTER   (KaxTagTitle,                  0x4EC4, 2, KaxTagMultiTitle, "Title", GetKaxTagsGlobal_Context);
DEFINE_MKX_UINTEGER (KaxTagMultiTitleType,         0x5B7D, 2, KaxTagTitle, "MultiTitleType");
DEFINE_MKX_UNISTRING(KaxTagMultiTitleName,         0x5BB9, 2, KaxTagTitle, "MultiTitleName");
DEFINE_MKX_UNISTRING(KaxTagMultiTitleSubTitle,     0x5B5B, 2, KaxTagTitle, "MultiTitleSubTitle");
DEFINE_MKX_UNISTRING(KaxTagMultiTitleEdition,      0x5BAE, 2, KaxTagTitle, "MultiTitleEdition");
DEFINE_MKX_UNISTRING(KaxTagMultiTitleAddress,      0x5B33, 2, KaxTagTitle, "MultiTitleAddress");
DEFINE_MKX_STRING   (KaxTagMultiTitleURL,          0x5BA9, 2, KaxTagTitle, "MultiTitleURL");
DEFINE_MKX_STRING   (KaxTagMultiTitleEmail,        0x5BC9, 2, KaxTagTitle, "MultiTitleEmail");
DEFINE_MKX_STRING   (KaxTagMultiTitleLanguage,   0x22B59E, 3, KaxTagTitle, "MultiTitleLanguage");

DEFINE_xxx_MASTER   (KaxTagMultiAttachment,        0x4DC3, 2, KaxTag, "MultiAttachment", GetKaxTagsGlobal_Context);
DEFINE_xxx_MASTER   (KaxTagAttachment,             0x4EC3, 2, KaxTagMultiAttachment, "Attachment", GetKaxTagsGlobal_Context);
DEFINE_MKX_UINTEGER (KaxTagAttachmentID,           0x5BA0, 2, KaxTagAttachment, "AttachmentID");

KaxTagMultiComment::KaxTagMultiComment()
	:EbmlMaster(KaxTagMultiComment_Context)
{}


KaxTagMultiCommercial::KaxTagMultiCommercial()
	:EbmlMaster(KaxTagMultiCommercial_Context)
{}

KaxTagCommercial::KaxTagCommercial()
	:EbmlMaster(KaxTagCommercial_Context)
{}

KaxTagMultiPrice::KaxTagMultiPrice()
	:EbmlMaster(KaxTagMultiPrice_Context)
{}

KaxTagMultiDate::KaxTagMultiDate()
	:EbmlMaster(KaxTagMultiDate_Context)
{}

KaxTagDate::KaxTagDate()
	:EbmlMaster(KaxTagDate_Context)
{}

KaxTagMultiEntity::KaxTagMultiEntity()
	:EbmlMaster(KaxTagMultiEntity_Context)
{}
	
KaxTagEntity::KaxTagEntity()
	:EbmlMaster(KaxTagEntity_Context)
{}
	
KaxTagMultiLegal::KaxTagMultiLegal()
	:EbmlMaster(KaxTagMultiLegal_Context)
{}

KaxTagLegal::KaxTagLegal()
	:EbmlMaster(KaxTagLegal_Context)
{}

KaxTagMultiIdentifier::KaxTagMultiIdentifier()
	:EbmlMaster(KaxTagMultiIdentifier_Context)
{}

KaxTagIdentifier::KaxTagIdentifier()
	:EbmlMaster(KaxTagIdentifier_Context)
{}

KaxTagMultiTitle::KaxTagMultiTitle()
	:EbmlMaster(KaxTagMultiTitle_Context)
{}

KaxTagTitle::KaxTagTitle()
	:EbmlMaster(KaxTagTitle_Context)
{}

KaxTagMultiAttachment::KaxTagMultiAttachment()
	:EbmlMaster(KaxTagMultiAttachment_Context)
{}

KaxTagAttachment::KaxTagAttachment()
	:EbmlMaster(KaxTagAttachment_Context)
{}

END_LIBMATROSKA_NAMESPACE
