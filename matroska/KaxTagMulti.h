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
	\version \$Id: KaxTagMulti.h,v 1.9 2004/04/14 23:26:17 robux4 Exp $
	\author Jory Stone     <jcsston @ toughguy.net>
	\author Steve Lhomme   <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_TAGMULTI_H
#define LIBMATROSKA_TAGMULTI_H

#include "matroska/KaxTypes.h"
#include "ebml/EbmlMaster.h"
#include "ebml/EbmlDate.h"
#include "ebml/EbmlFloat.h"
#include "ebml/EbmlSInteger.h"
#include "ebml/EbmlUInteger.h"
#include "ebml/EbmlString.h"
#include "ebml/EbmlUnicodeString.h"
#include "ebml/EbmlBinary.h"
#include "matroska/KaxDefines.h"

using namespace LIBEBML_NAMESPACE;

START_LIBMATROSKA_NAMESPACE

enum KaxTagMultiCommercialTypes {
	KaxTagMultiCommercialType_FilePurchase = 1, //Information on where to purchase this file. This is akin to the WPAY tag in ID3.
	KaxTagMultiCommercialType_ItemPurchase,	//Information on where to purchase this album. This is akin to the WCOM tag in ID3.
	KaxTagMultiCommercialType_Owner  //Information on the purchase that occurred for this file. This is akin to the OWNE tag in ID3.
};
enum KaxTagMultiDateTypes {
	KaxTagMultiDateType_EncodingDate = 1, //The time that the encoding of this item was completed. This is akin to the TDEN tag in ID3.
	KaxTagMultiDateType_RecordingDate, //The time that the recording began, and finished. This is akin to the TDRC tag in ID3.
	KaxTagMultiDateType_ReleaseDate, //The time that the item was originaly released. This is akin to the TDRL tag in ID3.
	KaxTagMultiDateType_OriginalReleaseDate, //The time that the item was originaly released if it is a remake. This is akin to the TDOR tag in ID3.
	KaxTagMultiDateType_TaggingDate, //The time that the tags were done for this item. This is akin to the TDTG tag in ID3.
	KaxTagMultiDateType_DigitizingDate  //The time that the item was tranfered to a digital medium. This is akin to the IDIT tag in RIFF
};
enum KaxTagMultiEntitiesTypes {
	KaxTagMultiEntitiesType_LyricistTextWriter = 1, //The person that wrote the words/script for this item. This is akin to the TEXT tag in ID3.
	KaxTagMultiEntitiesType_Composer, //The name of the composer of this item. This is akin to the TCOM tag in ID3.
	KaxTagMultiEntitiesType_LeadPerformerSoloist, //This is akin to the TPE1 tag in ID3.
	KaxTagMultiEntitiesType_BandOrchestraAccompaniment, //This is akin to the TPE2 tag in ID3.
	KaxTagMultiEntitiesType_OriginalLyricistTextWriter, //This is akin to the TOLY tag in ID3.
	KaxTagMultiEntitiesType_OriginalArtistPerformer, //This is akin to the TOPE tag in ID3.
	KaxTagMultiEntitiesType_OriginalAlbumMovieShowTitle, //This is akin to the TOAL tag in ID3.
	KaxTagMultiEntitiesType_ConductorPerformerRefinement, //This is akin to the TPE3 tag in ID3.
	KaxTagMultiEntitiesType_InterpretedRemixedBy, //This is akin to the TPE4 tag in ID3.
	KaxTagMultiEntitiesType_Director, //This is akin to the IART tag in RIFF
	KaxTagMultiEntitiesType_ProducedBy, //This is akin to the IPRO tag in Extended RIFF
	KaxTagMultiEntitiesType_Cinematographer, //This is akin to the ICNM tag in Extended RIFF
	KaxTagMultiEntitiesType_ProductionDesigner, //This is akin to the IPDS tag in Extended RIFF
	KaxTagMultiEntitiesType_CostumeDesigner, //This is akin to the ICDS tag in Extended RIFF
	KaxTagMultiEntitiesType_ProductionStudio, //This is akin to the ISTD tag in Extended RIFF
	KaxTagMultiEntitiesType_DistributedBy, //This is akin to the IDST tag in Extended RIFF
	KaxTagMultiEntitiesType_CommissionedBy, //This is akin to the ICMS tag in RIFF
	KaxTagMultiEntitiesType_Engineer, //This is akin to the IENG tag in RIFF
	KaxTagMultiEntitiesType_EditedBy, //This is akin to the IEDT tag in Extended RIFF
	KaxTagMultiEntitiesType_EncodedBy, //This is akin to the TENC tag in ID3.
	KaxTagMultiEntitiesType_RippedBy, //This is akin to the IRIP tag in Extended RIFF
	KaxTagMultiEntitiesType_InvolvedPeopleList, //A very general tag for everyone else that wants to be listed. This is akin to the TMCL tag in ID3.
	KaxTagMultiEntitiesType_InternetRadioStationName, //This is akin to the TSRN tag in ID3.
	KaxTagMultiEntitiesType_Publisher  //This is akin to the TPUB tag in ID3.
};

enum KaxTagMultiIdentifierTypes {
	KaxTagMultiIdentifierType_ISRC = 1, //String, The International Standard Recording Code
	KaxTagMultiIdentifierType_CDIdentifier, //Binary, This is a binary dump of the TOC of the CDROM that this item was taken from. This holds the same information as the MCDI in ID3.
	KaxTagMultiIdentifierType_ISBN, //String, International Standard Book Number
	KaxTagMultiIdentifierType_Catalog, //String, sometimes the EAN/UPC, often some letters followed by some numbers
	KaxTagMultiIdentifierType_EAN, //String, EAN-13 bar code identifier
	KaxTagMultiIdentifierType_UPC, //String, UPC-A bar code identifier
	KaxTagMultiIdentifierType_LabelCode, //String, Typically printed as ________ (LC) xxxx) ~~~~~~~~ or _________ (LC) 0xxxx) ~~~~~~~~~ on CDs medias or covers, where xxxx is a 4-digit number.
	KaxTagMultiIdentifierType_LCCN, //String, Library of Congress Control Number
	KaxTagMultiIdentifierType_UniqueFileIdentifier, //Binary, This used for a dump of the UFID field in ID3. This field would only be used if the item was pulled from an MP3.
	CDROM_CD_TEXT_PACK_TOC_INFO2  //Binary
};

enum KaxTagMultiLegalTypes {
	KaxTagMultiLegalType_Copyright = 1, //The copyright information as per the copyright holder. This is akin to the TCOP tag in ID3.
	KaxTagMultiLegalType_ProductionCopyright, //The copyright information as per the production copyright holder. This is akin to the TPRO tag in ID3.
	KaxTagMultiLegalType_TermsOfUse  //The terms of use for this item. This is akin to the USER tag in ID3.
};

enum KaxTagMultiTitleTypes {
	KaxTagMultiTitleType_TrackTitle = 1,
		//The title of this item. In the case of a track, the Name element should be identical to the Name element.
		//For example, for music you might label this "Canon in D", or for video's audio track you might use "English 5.1" This is akin to the TIT2 tag in ID3.
	KaxTagMultiTitleType_AlbumMovieShowTitle,
		//This is the name given to a grouping of tracks and/or chapters. 
		//For example, all video, audio, and subtitle tracks for a movie would be grouped under this and be given the name of the movie. 
		//All tracks for a particular CD would be grouped together under the title of the CD, or if all tracks for a CD were recorded as a single track, seperated by chapters, the same would apply.
		//You could use this to label episode 3 of The Simpsons. This is akin to the TALB tag in ID3.
	KaxTagMultiTitleType_SetTitle,	//This would be used to label a set of ID 2. For example, season 13 of The Simpsons.
	KaxTagMultiTitleType_Series  //This would be used to label a set of ID 3. For example, The Simpsons.
};

DECLARE_MKX_MASTER(KaxTagMultiComment)
	public:
		KaxTagMultiComment(const KaxTagMultiComment & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiComment)
};

DECLARE_MKX_STRING(KaxTagMultiCommentName)
	public:
		KaxTagMultiCommentName(const KaxTagMultiCommentName & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiCommentName)
};

DECLARE_MKX_UNISTRING(KaxTagMultiCommentComments)
	public:
		KaxTagMultiCommentComments(const KaxTagMultiCommentComments & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiCommentComments)
};

DECLARE_MKX_STRING(KaxTagMultiCommentLanguage)
	public:
		KaxTagMultiCommentLanguage(const KaxTagMultiCommentLanguage & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiCommentLanguage)
};

DECLARE_MKX_MASTER(KaxTagMultiCommercial)
	public:
		KaxTagMultiCommercial(const KaxTagMultiCommercial & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiCommercial)
};

DECLARE_MKX_MASTER(KaxTagCommercial)
	public:
		KaxTagCommercial(const KaxTagCommercial & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagCommercial)
};

DECLARE_MKX_UINTEGER(KaxTagMultiCommercialType)
	public:
		KaxTagMultiCommercialType(const KaxTagMultiCommercialType & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiCommercialType)
};

DECLARE_MKX_UNISTRING(KaxTagMultiCommercialAddress)
	public:
		KaxTagMultiCommercialAddress(const KaxTagMultiCommercialAddress & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiCommercialAddress)
};

DECLARE_MKX_STRING(KaxTagMultiCommercialURL)
	public:
		KaxTagMultiCommercialURL(const KaxTagMultiCommercialURL & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiCommercialURL)
};

DECLARE_MKX_STRING(KaxTagMultiCommercialEmail)
	public:
		KaxTagMultiCommercialEmail(const KaxTagMultiCommercialEmail & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiCommercialEmail)
};

DECLARE_MKX_MASTER(KaxTagMultiPrice)
	public:
		KaxTagMultiPrice(const KaxTagMultiPrice & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiPrice)
};

DECLARE_MKX_STRING(KaxTagMultiPriceCurrency)
	public:
		KaxTagMultiPriceCurrency(const KaxTagMultiPriceCurrency & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiPriceCurrency)
};

DECLARE_MKX_FLOAT(KaxTagMultiPriceAmount)
	public:
		KaxTagMultiPriceAmount(const KaxTagMultiPriceAmount & ElementToClone) :EbmlFloat(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiPriceAmount)
};

DECLARE_MKX_DATE(KaxTagMultiPricePriceDate)
	public:
		KaxTagMultiPricePriceDate(const KaxTagMultiPricePriceDate & ElementToClone) :EbmlDate(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiPricePriceDate)
};

DECLARE_MKX_MASTER(KaxTagMultiDate)
	public:
		KaxTagMultiDate(const KaxTagMultiDate & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiDate)
};

DECLARE_MKX_MASTER(KaxTagDate)
	public:
		KaxTagDate(const KaxTagDate & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagDate)
};

DECLARE_MKX_UINTEGER(KaxTagMultiDateType)
	public:
		KaxTagMultiDateType(const KaxTagMultiDateType & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiDateType)
};

DECLARE_MKX_DATE(KaxTagMultiDateDateBegin)
	public:
		KaxTagMultiDateDateBegin(const KaxTagMultiDateDateBegin & ElementToClone) :EbmlDate(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiDateDateBegin)
};

DECLARE_MKX_DATE(KaxTagMultiDateDateEnd)
	public:
		KaxTagMultiDateDateEnd(const KaxTagMultiDateDateEnd & ElementToClone) :EbmlDate(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiDateDateEnd)
};

DECLARE_MKX_MASTER(KaxTagMultiEntity)
	public:
		KaxTagMultiEntity(const KaxTagMultiEntity & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiEntity)
};

DECLARE_MKX_MASTER(KaxTagEntity)
	public:
		KaxTagEntity(const KaxTagEntity & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagEntity)
};

DECLARE_MKX_UINTEGER(KaxTagMultiEntityType)
	public:
		KaxTagMultiEntityType(const KaxTagMultiEntityType & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiEntityType)
};

DECLARE_MKX_UNISTRING(KaxTagMultiEntityName)
	public:
		KaxTagMultiEntityName(const KaxTagMultiEntityName & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiEntityName)
};

DECLARE_MKX_UNISTRING(KaxTagMultiEntityAddress)
	public:
		KaxTagMultiEntityAddress(const KaxTagMultiEntityAddress & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiEntityAddress)
};

DECLARE_MKX_STRING(KaxTagMultiEntityURL)
	public:
		KaxTagMultiEntityURL(const KaxTagMultiEntityURL & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiEntityURL)
};

DECLARE_MKX_STRING(KaxTagMultiEntityEmail)
	public:
		KaxTagMultiEntityEmail(const KaxTagMultiEntityEmail & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiEntityEmail)
};

DECLARE_MKX_MASTER(KaxTagMultiIdentifier)
	public:
		KaxTagMultiIdentifier(const KaxTagMultiIdentifier & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiIdentifier)
};

DECLARE_MKX_MASTER(KaxTagIdentifier)
	public:
		KaxTagIdentifier(const KaxTagIdentifier & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagIdentifier)
};

DECLARE_MKX_UINTEGER(KaxTagMultiIdentifierType)
	public:
		KaxTagMultiIdentifierType(const KaxTagMultiIdentifierType & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiIdentifierType)
};

DECLARE_MKX_BINARY(KaxTagMultiIdentifierBinary)
	public:
		KaxTagMultiIdentifierBinary(const KaxTagMultiIdentifierBinary & ElementToClone) :EbmlBinary(ElementToClone){}
		bool ValidateSize() const {return true;} // we don't mind about what's inside

        EBML_CONCRETE_CLASS(KaxTagMultiIdentifierBinary)
};

DECLARE_MKX_UNISTRING(KaxTagMultiIdentifierString)
	public:
		KaxTagMultiIdentifierString(const KaxTagMultiIdentifierString & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiIdentifierString)
};

DECLARE_MKX_MASTER(KaxTagMultiLegal)
	public:
		KaxTagMultiLegal(const KaxTagMultiLegal & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiLegal)
};

DECLARE_MKX_MASTER(KaxTagLegal)
	public:
		KaxTagLegal(const KaxTagLegal & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagLegal)
};

DECLARE_MKX_UINTEGER(KaxTagMultiLegalType)
	public:
		KaxTagMultiLegalType(const KaxTagMultiLegalType & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiLegalType)
};

DECLARE_MKX_UNISTRING(KaxTagMultiLegalContent)
	public:
		KaxTagMultiLegalContent(const KaxTagMultiLegalContent & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiLegalContent)
};

DECLARE_MKX_STRING(KaxTagMultiLegalURL)
	public:
		KaxTagMultiLegalURL(const KaxTagMultiLegalURL & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiLegalURL)
};

DECLARE_MKX_UNISTRING(KaxTagMultiLegalAddress)
	public:
		KaxTagMultiLegalAddress(const KaxTagMultiLegalAddress & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiLegalAddress)
};

DECLARE_MKX_MASTER(KaxTagMultiTitle)
	public:
		KaxTagMultiTitle(const KaxTagMultiTitle & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiTitle)
};

DECLARE_MKX_MASTER(KaxTagTitle)
	public:
		KaxTagTitle(const KaxTagTitle & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagTitle)
};

DECLARE_MKX_UINTEGER(KaxTagMultiTitleType)
	public:
		KaxTagMultiTitleType(const KaxTagMultiTitleType & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiTitleType)
};


DECLARE_MKX_UNISTRING(KaxTagMultiTitleName)
	public:
		KaxTagMultiTitleName(const KaxTagMultiTitleName & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiTitleName)
};

DECLARE_MKX_UNISTRING(KaxTagMultiTitleSubTitle)
	public:
		KaxTagMultiTitleSubTitle(const KaxTagMultiTitleSubTitle & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiTitleSubTitle)
};

DECLARE_MKX_UNISTRING(KaxTagMultiTitleEdition)
	public:
		KaxTagMultiTitleEdition(const KaxTagMultiTitleEdition & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiTitleEdition)
};

DECLARE_MKX_UNISTRING(KaxTagMultiTitleAddress)
	public:
		KaxTagMultiTitleAddress(const KaxTagMultiTitleAddress & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiTitleAddress)
};

DECLARE_MKX_STRING(KaxTagMultiTitleURL)
	public:
		KaxTagMultiTitleURL(const KaxTagMultiTitleURL & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiTitleURL)
};

DECLARE_MKX_STRING(KaxTagMultiTitleEmail)
	public:
		KaxTagMultiTitleEmail(const KaxTagMultiTitleEmail & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiTitleEmail)
};

DECLARE_MKX_STRING(KaxTagMultiTitleLanguage)
	public:
		KaxTagMultiTitleLanguage(const KaxTagMultiTitleLanguage & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiTitleLanguage)
};

DECLARE_MKX_MASTER(KaxTagMultiAttachment)
	public:
		KaxTagMultiAttachment(const KaxTagMultiAttachment & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiAttachment)
};

DECLARE_MKX_MASTER(KaxTagAttachment)
	public:
		KaxTagAttachment(const KaxTagAttachment & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagAttachment)
};

DECLARE_MKX_UINTEGER(KaxTagAttachmentID)
	public:
		KaxTagAttachmentID(const KaxTagAttachmentID & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagAttachmentID)
};

#if 0
DECLARE_MKX_FLOAT(KaxTagBPM)
	public:
        EBML_CONCRETE_CLASS(KaxTagBPM)
};

DECLARE_MKX_SINTEGER(KaxTagPopularimeter)
	public:
        EBML_CONCRETE_CLASS(KaxTagPopularimeter)
};

DECLARE_MKX_BINARY(KaxTagRating)
	public:
		bool ValidateSize() const {return true;} // we don't mind about what's inside

        EBML_CONCRETE_CLASS(KaxTagRating)
};

DECLARE_MKX_UINTEGER(KaxTagSetPart)
        EBML_CONCRETE_CLASS(KaxTagSetPart)
};

DECLARE_MKX_STRING(KaxTagUserDefinedURL)
        EBML_CONCRETE_CLASS(KaxTagUserDefinedURL)
};

DECLARE_MKX_BINARY(KaxTagVideoSecondaryGenre)
	public:
		bool ValidateSize() const {return (Size >= 4);}

        EBML_CONCRETE_CLASS(KaxTagVideoSecondaryGenre)
};

DECLARE_MKX_UNISTRING(KaxWritingApp)
        EBML_CONCRETE_CLASS(KaxWritingApp)
};
#endif

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_TAGMULTI_H
