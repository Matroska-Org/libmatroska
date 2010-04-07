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
};

DECLARE_MKX_STRING(KaxTagMultiCommentName)
};

DECLARE_MKX_UNISTRING(KaxTagMultiCommentComments)
};

DECLARE_MKX_STRING(KaxTagMultiCommentLanguage)
};

DECLARE_MKX_MASTER(KaxTagMultiCommercial)
};

DECLARE_MKX_MASTER(KaxTagCommercial)
};

DECLARE_MKX_UINTEGER(KaxTagMultiCommercialType)
};

DECLARE_MKX_UNISTRING(KaxTagMultiCommercialAddress)
};

DECLARE_MKX_STRING(KaxTagMultiCommercialURL)
};

DECLARE_MKX_STRING(KaxTagMultiCommercialEmail)
};

DECLARE_MKX_MASTER(KaxTagMultiPrice)
};

DECLARE_MKX_STRING(KaxTagMultiPriceCurrency)
};

DECLARE_MKX_FLOAT(KaxTagMultiPriceAmount)
};

DECLARE_MKX_DATE(KaxTagMultiPricePriceDate)
};

DECLARE_MKX_MASTER(KaxTagMultiDate)
};

DECLARE_MKX_MASTER(KaxTagDate)
};

DECLARE_MKX_UINTEGER(KaxTagMultiDateType)
};

DECLARE_MKX_DATE(KaxTagMultiDateDateBegin)
};

DECLARE_MKX_DATE(KaxTagMultiDateDateEnd)
};

DECLARE_MKX_MASTER(KaxTagMultiEntity)
};

DECLARE_MKX_MASTER(KaxTagEntity)
};

DECLARE_MKX_UINTEGER(KaxTagMultiEntityType)
};

DECLARE_MKX_UNISTRING(KaxTagMultiEntityName)
};

DECLARE_MKX_UNISTRING(KaxTagMultiEntityAddress)
};

DECLARE_MKX_STRING(KaxTagMultiEntityURL)
};

DECLARE_MKX_STRING(KaxTagMultiEntityEmail)
};

DECLARE_MKX_MASTER(KaxTagMultiIdentifier)
};

DECLARE_MKX_MASTER(KaxTagIdentifier)
};

DECLARE_MKX_UINTEGER(KaxTagMultiIdentifierType)
};

DECLARE_MKX_BINARY(KaxTagMultiIdentifierBinary)
};

DECLARE_MKX_UNISTRING(KaxTagMultiIdentifierString)
};

DECLARE_MKX_MASTER(KaxTagMultiLegal)
};

DECLARE_MKX_MASTER(KaxTagLegal)
};

DECLARE_MKX_UINTEGER(KaxTagMultiLegalType)
};

DECLARE_MKX_UNISTRING(KaxTagMultiLegalContent)
};

DECLARE_MKX_STRING(KaxTagMultiLegalURL)
};

DECLARE_MKX_UNISTRING(KaxTagMultiLegalAddress)
};

DECLARE_MKX_MASTER(KaxTagMultiTitle)
};

DECLARE_MKX_MASTER(KaxTagTitle)
};

DECLARE_MKX_UINTEGER(KaxTagMultiTitleType)
};


DECLARE_MKX_UNISTRING(KaxTagMultiTitleName)
};

DECLARE_MKX_UNISTRING(KaxTagMultiTitleSubTitle)
};

DECLARE_MKX_UNISTRING(KaxTagMultiTitleEdition)
};

DECLARE_MKX_UNISTRING(KaxTagMultiTitleAddress)
};

DECLARE_MKX_STRING(KaxTagMultiTitleURL)
};

DECLARE_MKX_STRING(KaxTagMultiTitleEmail)
};

DECLARE_MKX_STRING(KaxTagMultiTitleLanguage)
};

DECLARE_MKX_MASTER(KaxTagMultiAttachment)
};

DECLARE_MKX_MASTER(KaxTagAttachment)
};

DECLARE_MKX_UINTEGER(KaxTagAttachmentID)
};

#if 0
DECLARE_MKX_FLOAT(KaxTagBPM)
};

DECLARE_MKX_SINTEGER(KaxTagPopularimeter)
};

DECLARE_MKX_BINARY(KaxTagRating)
};

DECLARE_MKX_UINTEGER(KaxTagSetPart)
};

DECLARE_MKX_STRING(KaxTagUserDefinedURL)
};

DECLARE_MKX_BINARY(KaxTagVideoSecondaryGenre)
	public:
		bool ValidateSize() const {return (Size >= 4);
};

DECLARE_MKX_UNISTRING(KaxWritingApp)
};
#endif

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_TAGMULTI_H
