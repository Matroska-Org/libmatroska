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
	\version \$Id: KaxTrackVideo.cpp 738 2004-08-30 09:21:46Z robux4 $
	\author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include "matroska/KaxTrackVideo.h"

// sub elements
#include "matroska/KaxContexts.h"

START_LIBMATROSKA_NAMESPACE

#if MATROSKA_VERSION == 1
const EbmlSemantic KaxTrackVideo_ContextList[10] =
#else // MATROSKA_VERSION
const EbmlSemantic KaxTrackVideo_ContextList[15] =
#endif // MATROSKA_VERSION
{
	EbmlSemantic(true , true, EBML_INFO(KaxVideoPixelWidth)),
	EbmlSemantic(true , true, EBML_INFO(KaxVideoPixelHeight)),
	EbmlSemantic(false, true, EBML_INFO(KaxVideoPixelCropBottom)),
	EbmlSemantic(false, true, EBML_INFO(KaxVideoPixelCropTop)),
	EbmlSemantic(false, true, EBML_INFO(KaxVideoPixelCropLeft)),
	EbmlSemantic(false, true, EBML_INFO(KaxVideoPixelCropRight)),
	EbmlSemantic(false, true, EBML_INFO(KaxVideoDisplayWidth)),
	EbmlSemantic(false, true, EBML_INFO(KaxVideoDisplayHeight)),
	EbmlSemantic(false, true, EBML_INFO(KaxVideoColourSpace)),
	EbmlSemantic(false, true, EBML_INFO(KaxVideoFrameRate)),
#if MATROSKA_VERSION >= 2
	EbmlSemantic(true , true, EBML_INFO(KaxVideoFlagInterlaced)),
	EbmlSemantic(false, true, EBML_INFO(KaxVideoStereoMode)),
	EbmlSemantic(false, true, EBML_INFO(KaxVideoDisplayUnit)),
	EbmlSemantic(false, true, EBML_INFO(KaxVideoAspectRatio)),
	EbmlSemantic(false, true, EBML_INFO(KaxVideoGamma)),
#endif // MATROSKA_VERSION
};

const EbmlSemanticContext KaxTrackVideo_Context = EbmlSemanticContext(countof(KaxTrackVideo_ContextList), KaxTrackVideo_ContextList, &KaxTrackEntry_Context, *GetKaxGlobal_Context, &EBML_INFO(KaxTrackVideo));
const EbmlSemanticContext KaxVideoPixelWidth_Context = EbmlSemanticContext(0, NULL, &KaxTrackVideo_Context, *GetKaxGlobal_Context, &EBML_INFO(KaxVideoPixelWidth));
const EbmlSemanticContext KaxVideoPixelHeight_Context = EbmlSemanticContext(0, NULL, &KaxTrackVideo_Context, *GetKaxGlobal_Context, &EBML_INFO(KaxVideoPixelHeight));
const EbmlSemanticContext KaxVideoPixelCropBottom_Context = EbmlSemanticContext(0, NULL, &KaxTrackVideo_Context, *GetKaxGlobal_Context, &EBML_INFO(KaxVideoPixelCropBottom));
const EbmlSemanticContext KaxVideoPixelCropTop_Context = EbmlSemanticContext(0, NULL, &KaxTrackVideo_Context, *GetKaxGlobal_Context, &EBML_INFO(KaxVideoPixelCropTop));
const EbmlSemanticContext KaxVideoPixelCropRight_Context = EbmlSemanticContext(0, NULL, &KaxTrackVideo_Context, *GetKaxGlobal_Context, &EBML_INFO(KaxVideoPixelCropLeft));
const EbmlSemanticContext KaxVideoPixelCropLeft_Context = EbmlSemanticContext(0, NULL, &KaxTrackVideo_Context, *GetKaxGlobal_Context, &EBML_INFO(KaxVideoPixelCropRight));
const EbmlSemanticContext KaxVideoDisplayWidth_Context = EbmlSemanticContext(0, NULL, &KaxTrackVideo_Context, *GetKaxGlobal_Context, &EBML_INFO(KaxVideoDisplayWidth));
const EbmlSemanticContext KaxVideoDisplayHeight_Context = EbmlSemanticContext(0, NULL, &KaxTrackVideo_Context, *GetKaxGlobal_Context, &EBML_INFO(KaxVideoDisplayHeight));
const EbmlSemanticContext KaxVideoColourSpace_Context = EbmlSemanticContext(0, NULL, &KaxTrackVideo_Context, *GetKaxGlobal_Context, &EBML_INFO(KaxVideoColourSpace));
const EbmlSemanticContext KaxVideoFrameRate_Context = EbmlSemanticContext(0, NULL, &KaxTrackVideo_Context, *GetKaxGlobal_Context, &EBML_INFO(KaxVideoFrameRate));
#if MATROSKA_VERSION >= 2
const EbmlSemanticContext KaxVideoFlagInterlaced_Context = EbmlSemanticContext(0, NULL, &KaxTrackVideo_Context, *GetKaxGlobal_Context, &EBML_INFO(KaxVideoFlagInterlaced));
const EbmlSemanticContext KaxVideoStereoMode_Context = EbmlSemanticContext(0, NULL, &KaxTrackVideo_Context, *GetKaxGlobal_Context, &EBML_INFO(KaxVideoStereoMode));
const EbmlSemanticContext KaxVideoDisplayUnit_Context = EbmlSemanticContext(0, NULL, &KaxTrackVideo_Context, *GetKaxGlobal_Context, &EBML_INFO(KaxVideoDisplayUnit));
const EbmlSemanticContext KaxVideoAspectRatio_Context = EbmlSemanticContext(0, NULL, &KaxTrackVideo_Context, *GetKaxGlobal_Context, &EBML_INFO(KaxVideoAspectRatio));
const EbmlSemanticContext KaxVideoGamma_Context = EbmlSemanticContext(0, NULL, &KaxTrackVideo_Context, *GetKaxGlobal_Context, &EBML_INFO(KaxVideoGamma));
#endif // MATROSKA_VERSION

EbmlId KaxTrackVideo_TheId          (0xE0, 1);
EbmlId KaxVideoPixelWidth_TheId     (0xB0, 1);
EbmlId KaxVideoPixelHeight_TheId    (0xBA, 1);
EbmlId KaxVideoPixelCropBottom_TheId(0x54AA, 2);
EbmlId KaxVideoPixelCropTop_TheId   (0x54BB, 2);
EbmlId KaxVideoPixelCropLeft_TheId  (0x54CC, 2);
EbmlId KaxVideoPixelCropRight_TheId (0x54DD, 2);
EbmlId KaxVideoDisplayWidth_TheId   (0x54B0, 2);
EbmlId KaxVideoDisplayHeight_TheId  (0x54BA, 2);
EbmlId KaxVideoColourSpace_TheId    (0x2EB524, 3);
EbmlId KaxVideoFrameRate_TheId      (0x2383E3, 3);
#if MATROSKA_VERSION >= 2
EbmlId KaxVideoFlagInterlaced_TheId (0x9A, 1);
EbmlId KaxVideoStereoMode_TheId     (0x53B9, 2);
EbmlId KaxVideoDisplayUnit_TheId    (0x54B2, 2);
EbmlId KaxVideoAspectRatio_TheId    (0x54B3, 1);
EbmlId KaxVideoGamma_TheId          (0x2FB523, 3);
#endif // MATROSKA_VERSION

const EbmlCallbacks KaxTrackVideo::ClassInfos(KaxTrackVideo::Create, KaxTrackVideo_TheId, "TrackAudio", KaxTrackVideo_Context);
const EbmlCallbacks KaxVideoPixelWidth::ClassInfos(KaxVideoPixelWidth::Create, KaxVideoPixelWidth_TheId, "VideoPixelWidth", KaxVideoPixelWidth_Context);
const EbmlCallbacks KaxVideoPixelHeight::ClassInfos(KaxVideoPixelHeight::Create, KaxVideoPixelHeight_TheId, "VideoPixelHeight", KaxVideoPixelHeight_Context);
const EbmlCallbacks KaxVideoPixelCropBottom::ClassInfos(KaxVideoPixelCropBottom::Create, KaxVideoPixelCropBottom_TheId, "VideoPixelCropBottom", KaxVideoPixelCropBottom_Context);
const EbmlCallbacks KaxVideoPixelCropTop::ClassInfos(KaxVideoPixelCropTop::Create, KaxVideoPixelCropTop_TheId, "VideoPixelCropTop", KaxVideoPixelCropTop_Context);
const EbmlCallbacks KaxVideoPixelCropLeft::ClassInfos(KaxVideoPixelCropLeft::Create, KaxVideoPixelCropLeft_TheId, "VideoPixelCropLeft", KaxVideoPixelCropLeft_Context);
const EbmlCallbacks KaxVideoPixelCropRight::ClassInfos(KaxVideoPixelCropRight::Create, KaxVideoPixelCropRight_TheId, "VideoPixelCropRight", KaxVideoPixelCropRight_Context);
const EbmlCallbacks KaxVideoDisplayWidth::ClassInfos(KaxVideoDisplayWidth::Create, KaxVideoDisplayWidth_TheId, "VideoDisplayWidth", KaxVideoDisplayWidth_Context);
const EbmlCallbacks KaxVideoDisplayHeight::ClassInfos(KaxVideoDisplayHeight::Create, KaxVideoDisplayHeight_TheId, "VideoDisplayHeight", KaxVideoDisplayHeight_Context);
const EbmlCallbacks KaxVideoColourSpace::ClassInfos(KaxVideoColourSpace::Create, KaxVideoColourSpace_TheId, "VideoColourSpace", KaxVideoColourSpace_Context);
const EbmlCallbacks KaxVideoFrameRate::ClassInfos(KaxVideoFrameRate::Create, KaxVideoFrameRate_TheId, "VideoFrameRate", KaxVideoFrameRate_Context);
#if MATROSKA_VERSION >= 2
const EbmlCallbacks KaxVideoFlagInterlaced::ClassInfos(KaxVideoFlagInterlaced::Create, KaxVideoFlagInterlaced_TheId, "VideoFlagInterlaced", KaxVideoFlagInterlaced_Context);
const EbmlCallbacks KaxVideoStereoMode::ClassInfos(KaxVideoStereoMode::Create, KaxVideoStereoMode_TheId, "VideoStereoMode", KaxVideoStereoMode_Context);
const EbmlCallbacks KaxVideoDisplayUnit::ClassInfos(KaxVideoDisplayUnit::Create, KaxVideoDisplayUnit_TheId, "VideoDisplayUnit", KaxVideoDisplayUnit_Context);
const EbmlCallbacks KaxVideoAspectRatio::ClassInfos(KaxVideoAspectRatio::Create, KaxVideoAspectRatio_TheId, "VideoAspectRatio", KaxVideoAspectRatio_Context);
const EbmlCallbacks KaxVideoGamma::ClassInfos(KaxVideoGamma::Create, KaxVideoGamma_TheId, "VideoGamma", KaxVideoGamma_Context);
#endif // MATROSKA_VERSION

KaxTrackVideo::KaxTrackVideo()
	:EbmlMaster(KaxTrackVideo_Context)
{}

uint32 KaxVideoFrameRate::RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault)
{
	assert(false); // no you are not allowed to use this element !
	return 0;
}

END_LIBMATROSKA_NAMESPACE
