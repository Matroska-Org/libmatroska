/****************************************************************************
** libmatroska : parse Matroska files, see http://www.matroska.org/
**
** <file/class MATROSKA_DLL_API description>
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

class MATROSKA_DLL_API KaxTagMultiComment : public EbmlMaster {
	public:
		KaxTagMultiComment();
		KaxTagMultiComment(const KaxTagMultiComment & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiComment)
};

class MATROSKA_DLL_API KaxTagMultiCommentName : public EbmlString {
	public:
		KaxTagMultiCommentName() {}
		KaxTagMultiCommentName(const KaxTagMultiCommentName & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiCommentName)
};

class MATROSKA_DLL_API KaxTagMultiCommentComments : public EbmlUnicodeString {
	public:
		KaxTagMultiCommentComments() {}
		KaxTagMultiCommentComments(const KaxTagMultiCommentComments & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiCommentComments)
};

class MATROSKA_DLL_API KaxTagMultiCommentLanguage : public EbmlString {
	public:
		KaxTagMultiCommentLanguage() {}
		KaxTagMultiCommentLanguage(const KaxTagMultiCommentLanguage & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiCommentLanguage)
};

class MATROSKA_DLL_API KaxTagMultiCommercial : public EbmlMaster {
	public:
		KaxTagMultiCommercial();
		KaxTagMultiCommercial(const KaxTagMultiCommercial & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiCommercial)
};

class MATROSKA_DLL_API KaxTagCommercial : public EbmlMaster {
	public:
		KaxTagCommercial();
		KaxTagCommercial(const KaxTagCommercial & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagCommercial)
};

class MATROSKA_DLL_API KaxTagMultiCommercialType : public EbmlUInteger {
	public:
		KaxTagMultiCommercialType() {}
		KaxTagMultiCommercialType(const KaxTagMultiCommercialType & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiCommercialType)
};

class MATROSKA_DLL_API KaxTagMultiCommercialAddress : public EbmlUnicodeString {
	public:
		KaxTagMultiCommercialAddress() {}
		KaxTagMultiCommercialAddress(const KaxTagMultiCommercialAddress & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiCommercialAddress)
};

class MATROSKA_DLL_API KaxTagMultiCommercialURL : public EbmlString {
	public:
		KaxTagMultiCommercialURL() {}
		KaxTagMultiCommercialURL(const KaxTagMultiCommercialURL & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiCommercialURL)
};

class MATROSKA_DLL_API KaxTagMultiCommercialEmail : public EbmlString {
	public:
		KaxTagMultiCommercialEmail() {}
		KaxTagMultiCommercialEmail(const KaxTagMultiCommercialEmail & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiCommercialEmail)
};

class MATROSKA_DLL_API KaxTagMultiPrice : public EbmlMaster {
	public:
		KaxTagMultiPrice();
		KaxTagMultiPrice(const KaxTagMultiPrice & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiPrice)
};

class MATROSKA_DLL_API KaxTagMultiPriceCurrency : public EbmlString {
	public:
		KaxTagMultiPriceCurrency() {}
		KaxTagMultiPriceCurrency(const KaxTagMultiPriceCurrency & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiPriceCurrency)
};

class MATROSKA_DLL_API KaxTagMultiPriceAmount : public EbmlFloat {
	public:
		KaxTagMultiPriceAmount() :EbmlFloat() {}
		KaxTagMultiPriceAmount(const KaxTagMultiPriceAmount & ElementToClone) :EbmlFloat(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiPriceAmount)
};

class MATROSKA_DLL_API KaxTagMultiPricePriceDate : public EbmlDate {
	public:
		KaxTagMultiPricePriceDate() :EbmlDate() {}
		KaxTagMultiPricePriceDate(const KaxTagMultiPricePriceDate & ElementToClone) :EbmlDate(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiPricePriceDate)
};

class MATROSKA_DLL_API KaxTagMultiDate : public EbmlMaster {
	public:
		KaxTagMultiDate();
		KaxTagMultiDate(const KaxTagMultiDate & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiDate)
};

class MATROSKA_DLL_API KaxTagDate : public EbmlMaster {
	public:
		KaxTagDate();
		KaxTagDate(const KaxTagDate & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagDate)
};

class MATROSKA_DLL_API KaxTagMultiDateType : public EbmlUInteger {
	public:
		KaxTagMultiDateType() {}
		KaxTagMultiDateType(const KaxTagMultiDateType & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiDateType)
};

class MATROSKA_DLL_API KaxTagMultiDateDateBegin : public EbmlDate {
	public:
		KaxTagMultiDateDateBegin() :EbmlDate() {}
		KaxTagMultiDateDateBegin(const KaxTagMultiDateDateBegin & ElementToClone) :EbmlDate(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiDateDateBegin)
};

class MATROSKA_DLL_API KaxTagMultiDateDateEnd : public EbmlDate {
	public:
		KaxTagMultiDateDateEnd() :EbmlDate() {}
		KaxTagMultiDateDateEnd(const KaxTagMultiDateDateEnd & ElementToClone) :EbmlDate(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiDateDateEnd)
};

class MATROSKA_DLL_API KaxTagMultiEntity : public EbmlMaster {
	public:
		KaxTagMultiEntity();
		KaxTagMultiEntity(const KaxTagMultiEntity & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiEntity)
};

class MATROSKA_DLL_API KaxTagEntity : public EbmlMaster {
	public:
		KaxTagEntity();
		KaxTagEntity(const KaxTagEntity & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagEntity)
};

class MATROSKA_DLL_API KaxTagMultiEntityType : public EbmlUInteger {
	public:
		KaxTagMultiEntityType() {}
		KaxTagMultiEntityType(const KaxTagMultiEntityType & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiEntityType)
};

class MATROSKA_DLL_API KaxTagMultiEntityName : public EbmlUnicodeString {
	public:
		KaxTagMultiEntityName() {}
		KaxTagMultiEntityName(const KaxTagMultiEntityName & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiEntityName)
};

class MATROSKA_DLL_API KaxTagMultiEntityAddress : public EbmlUnicodeString {
	public:
		KaxTagMultiEntityAddress() {}
		KaxTagMultiEntityAddress(const KaxTagMultiEntityAddress & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiEntityAddress)
};

class MATROSKA_DLL_API KaxTagMultiEntityURL : public EbmlString {
	public:
		KaxTagMultiEntityURL() {}
		KaxTagMultiEntityURL(const KaxTagMultiEntityURL & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiEntityURL)
};

class MATROSKA_DLL_API KaxTagMultiEntityEmail : public EbmlString {
	public:
		KaxTagMultiEntityEmail() {}
		KaxTagMultiEntityEmail(const KaxTagMultiEntityEmail & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiEntityEmail)
};

class MATROSKA_DLL_API KaxTagMultiIdentifier : public EbmlMaster {
	public:
		KaxTagMultiIdentifier();
		KaxTagMultiIdentifier(const KaxTagMultiIdentifier & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiIdentifier)
};

class MATROSKA_DLL_API KaxTagIdentifier : public EbmlMaster {
	public:
		KaxTagIdentifier();
		KaxTagIdentifier(const KaxTagIdentifier & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagIdentifier)
};

class MATROSKA_DLL_API KaxTagMultiIdentifierType : public EbmlUInteger {
	public:
		KaxTagMultiIdentifierType() {}
		KaxTagMultiIdentifierType(const KaxTagMultiIdentifierType & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiIdentifierType)
};

class MATROSKA_DLL_API KaxTagMultiIdentifierBinary : public EbmlBinary {
	public:
		KaxTagMultiIdentifierBinary() {}
		KaxTagMultiIdentifierBinary(const KaxTagMultiIdentifierBinary & ElementToClone) :EbmlBinary(ElementToClone){}
		bool ValidateSize() const {return true;} // we don't mind about what's inside

        EBML_CONCRETE_CLASS(KaxTagMultiIdentifierBinary)
};

class MATROSKA_DLL_API KaxTagMultiIdentifierString : public EbmlUnicodeString {
	public:
		KaxTagMultiIdentifierString() {}
		KaxTagMultiIdentifierString(const KaxTagMultiIdentifierString & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiIdentifierString)
};

class MATROSKA_DLL_API KaxTagMultiLegal : public EbmlMaster {
	public:
		KaxTagMultiLegal();
		KaxTagMultiLegal(const KaxTagMultiLegal & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiLegal)
};

class MATROSKA_DLL_API KaxTagLegal : public EbmlMaster {
	public:
		KaxTagLegal();
		KaxTagLegal(const KaxTagLegal & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagLegal)
};

class MATROSKA_DLL_API KaxTagMultiLegalType : public EbmlUInteger {
	public:
		KaxTagMultiLegalType() {}
		KaxTagMultiLegalType(const KaxTagMultiLegalType & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiLegalType)
};

class MATROSKA_DLL_API KaxTagMultiLegalContent : public EbmlUnicodeString {
	public:
		KaxTagMultiLegalContent() {}
		KaxTagMultiLegalContent(const KaxTagMultiLegalContent & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiLegalContent)
};

class MATROSKA_DLL_API KaxTagMultiLegalURL : public EbmlString {
	public:
		KaxTagMultiLegalURL() {}
		KaxTagMultiLegalURL(const KaxTagMultiLegalURL & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiLegalURL)
};

class MATROSKA_DLL_API KaxTagMultiLegalAddress : public EbmlUnicodeString {
	public:
		KaxTagMultiLegalAddress() {}
		KaxTagMultiLegalAddress(const KaxTagMultiLegalAddress & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiLegalAddress)
};

class MATROSKA_DLL_API KaxTagMultiTitle : public EbmlMaster {
	public:
		KaxTagMultiTitle();
		KaxTagMultiTitle(const KaxTagMultiTitle & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiTitle)
};

class MATROSKA_DLL_API KaxTagTitle : public EbmlMaster {
	public:
		KaxTagTitle();
		KaxTagTitle(const KaxTagTitle & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagTitle)
};

class MATROSKA_DLL_API KaxTagMultiTitleType : public EbmlUInteger {
	public:
		KaxTagMultiTitleType() {}
		KaxTagMultiTitleType(const KaxTagMultiTitleType & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiTitleType)
};


class MATROSKA_DLL_API KaxTagMultiTitleName : public EbmlUnicodeString {
	public:
		KaxTagMultiTitleName() {}
		KaxTagMultiTitleName(const KaxTagMultiTitleName & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiTitleName)
};

class MATROSKA_DLL_API KaxTagMultiTitleSubTitle : public EbmlUnicodeString {
	public:
		KaxTagMultiTitleSubTitle() {}
		KaxTagMultiTitleSubTitle(const KaxTagMultiTitleSubTitle & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiTitleSubTitle)
};

class MATROSKA_DLL_API KaxTagMultiTitleEdition : public EbmlUnicodeString {
	public:
		KaxTagMultiTitleEdition() {}
		KaxTagMultiTitleEdition(const KaxTagMultiTitleEdition & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiTitleEdition)
};

class MATROSKA_DLL_API KaxTagMultiTitleAddress : public EbmlUnicodeString {
	public:
		KaxTagMultiTitleAddress() {}
		KaxTagMultiTitleAddress(const KaxTagMultiTitleAddress & ElementToClone) :EbmlUnicodeString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiTitleAddress)
};

class MATROSKA_DLL_API KaxTagMultiTitleURL : public EbmlString {
	public:
		KaxTagMultiTitleURL() {}
		KaxTagMultiTitleURL(const KaxTagMultiTitleURL & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiTitleURL)
};

class MATROSKA_DLL_API KaxTagMultiTitleEmail : public EbmlString {
	public:
		KaxTagMultiTitleEmail() {}
		KaxTagMultiTitleEmail(const KaxTagMultiTitleEmail & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiTitleEmail)
};

class MATROSKA_DLL_API KaxTagMultiTitleLanguage : public EbmlString {
	public:
		KaxTagMultiTitleLanguage() {}
		KaxTagMultiTitleLanguage(const KaxTagMultiTitleLanguage & ElementToClone) :EbmlString(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiTitleLanguage)
};

class MATROSKA_DLL_API KaxTagMultiAttachment : public EbmlMaster {
	public:
		KaxTagMultiAttachment();
		KaxTagMultiAttachment(const KaxTagMultiAttachment & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagMultiAttachment)
};

class MATROSKA_DLL_API KaxTagAttachment : public EbmlMaster {
	public:
		KaxTagAttachment();
		KaxTagAttachment(const KaxTagAttachment & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagAttachment)
};

class MATROSKA_DLL_API KaxTagAttachmentID : public EbmlUInteger {
	public:
		KaxTagAttachmentID() {}
		KaxTagAttachmentID(const KaxTagAttachmentID & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTagAttachmentID)
};

#if 0
class MATROSKA_DLL_API KaxTagBPM : public EbmlFloat {
	public:
		KaxTagBPM() :EbmlFloat() {}

        EBML_CONCRETE_CLASS(KaxTagBPM)
};

class MATROSKA_DLL_API KaxTagPopularimeter : public EbmlSInteger {
	public:
		KaxTagPopularimeter() {}

        EBML_CONCRETE_CLASS(KaxTagPopularimeter)
};

class MATROSKA_DLL_API KaxTagRating : public EbmlBinary {
	public:
		KaxTagRating() {}
		bool ValidateSize() const {return true;} // we don't mind about what's inside

        EBML_CONCRETE_CLASS(KaxTagRating)
};

class MATROSKA_DLL_API KaxTagSetPart : public EbmlUInteger {
	public:
		KaxTagSetPart() {}

        EBML_CONCRETE_CLASS(KaxTagSetPart)
};

class MATROSKA_DLL_API KaxTagUserDefinedURL : public EbmlString {
	public:
		KaxTagUserDefinedURL() {}

        EBML_CONCRETE_CLASS(KaxTagUserDefinedURL)
};

class MATROSKA_DLL_API KaxTagVideoSecondaryGenre : public EbmlBinary {
	public:
		KaxTagVideoSecondaryGenre() {}
		bool ValidateSize() const {return (Size >= 4);}

        EBML_CONCRETE_CLASS(KaxTagVideoSecondaryGenre)
};

class MATROSKA_DLL_API KaxWritingApp : public EbmlUnicodeString {
	public:
		KaxWritingApp() {}

        EBML_CONCRETE_CLASS(KaxWritingApp)
};
#endif

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_TAGMULTI_H
