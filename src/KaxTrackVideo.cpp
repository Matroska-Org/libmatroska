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
#include "matroska/KaxDefines.h"

START_LIBMATROSKA_NAMESPACE

DEFINE_START_SEMANTIC(KaxTrackVideo)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoPixelWidth)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoPixelHeight)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoPixelCropBottom)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoPixelCropTop)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoPixelCropLeft)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoPixelCropRight)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoDisplayWidth)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoDisplayHeight)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoColourSpace)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoFrameRate)
#if MATROSKA_VERSION >= 2
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoFlagInterlaced)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoStereoMode)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoDisplayUnit)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoAspectRatio)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoGamma)
#endif // MATROSKA_VERSION
DEFINE_END_SEMANTIC(KaxTrackVideo)

DEFINE_MKX_MASTER      (KaxTrackVideo,             0xE0, 1, KaxTrackEntry, "TrackVideo");
DEFINE_MKX_UINTEGER    (KaxVideoPixelWidth,        0xB0, 1, KaxTrackVideo, "VideoPixelWidth");
DEFINE_MKX_UINTEGER    (KaxVideoPixelHeight,       0xBA, 1, KaxTrackVideo, "VideoPixelHeight");
DEFINE_MKX_UINTEGER_DEF(KaxVideoPixelCropBottom, 0x54AA, 2, KaxTrackVideo, "VideoPixelCropBottom", 0);
DEFINE_MKX_UINTEGER_DEF(KaxVideoPixelCropTop,    0x54BB, 2, KaxTrackVideo, "VideoPixelCropTop", 0);
DEFINE_MKX_UINTEGER_DEF(KaxVideoPixelCropLeft,   0x54CC, 2, KaxTrackVideo, "VideoPixelCropLeft", 0);
DEFINE_MKX_UINTEGER_DEF(KaxVideoPixelCropRight,  0x54DD, 2, KaxTrackVideo, "VideoPixelCropRight", 0);
DEFINE_MKX_UINTEGER    (KaxVideoDisplayWidth,    0x54B0, 2, KaxTrackVideo, "VideoDisplayWidth");
DEFINE_MKX_UINTEGER    (KaxVideoDisplayHeight,   0x54BA, 2, KaxTrackVideo, "VideoDisplayHeight");
DEFINE_MKX_BINARY      (KaxVideoColourSpace,   0x2EB524, 3, KaxTrackVideo, "VideoColourSpace");
DEFINE_MKX_FLOAT       (KaxVideoFrameRate,     0x2383E3, 3, KaxTrackVideo, "VideoFrameRate");
#if MATROSKA_VERSION >= 2
DEFINE_MKX_UINTEGER_DEF(KaxVideoFlagInterlaced,    0x9A, 1, KaxTrackVideo, "VideoFlagInterlaced", 0);
DEFINE_MKX_UINTEGER_DEF(KaxVideoStereoMode,      0x53B8, 2, KaxTrackVideo, "VideoStereoMode", 0);
DEFINE_MKX_UINTEGER_DEF(KaxVideoDisplayUnit,     0x54B2, 2, KaxTrackVideo, "VideoDisplayUnit", 0);
DEFINE_MKX_UINTEGER_DEF(KaxVideoAspectRatio,     0x54B3, 2, KaxTrackVideo, "VideoAspectRatio", 0);
DEFINE_MKX_FLOAT       (KaxVideoGamma,         0x2FB523, 3, KaxTrackVideo, "VideoGamma");
#endif

filepos_t KaxVideoFrameRate::RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault)
{
	assert(false); // no you are not allowed to use this element !
	return 0;
}

END_LIBMATROSKA_NAMESPACE
