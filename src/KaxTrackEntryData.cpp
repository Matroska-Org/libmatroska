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
	\version \$Id: KaxTrackEntryData.cpp 1201 2005-08-30 14:28:27Z robux4 $
	\author Steve Lhomme     <robux4 @ users.sf.net>
	\author John Cannon      <spyder2555 @ users.sf.net>
*/
#include "matroska/KaxTrackEntryData.h"
#include "matroska/KaxContexts.h"
#include "matroska/KaxDefines.h"

START_LIBMATROSKA_NAMESPACE

static const EbmlSemantic ContextList_KaxTrackTranslate[3] =
{
	EbmlSemantic(false, false,EBML_INFO(KaxTrackTranslateEditionUID)),
	EbmlSemantic(true , true, EBML_INFO(KaxTrackTranslateCodec)),
	EbmlSemantic(true , true, EBML_INFO(KaxTrackTranslateTrackID)),
};

DEFINE_MKX_UINTEGER (KaxTrackNumber,                0xD7, 1, KaxTracks, "TrackNumber");
DEFINE_MKX_UINTEGER (KaxTrackUID,                 0x73C5, 2, KaxTracks, "TrackUID");
DEFINE_MKX_UINTEGER (KaxTrackType,                  0x83, 1, KaxTracks, "TrackType");
DEFINE_MKX_UINTEGER (KaxTrackFlagDefault,           0x88, 1, KaxTracks, "TrackFlagEnabled");
DEFINE_MKX_UINTEGER (KaxTrackFlagForced,          0x55AA, 2, KaxTracks, "TrackFlagForced");
DEFINE_MKX_UINTEGER (KaxTrackFlagLacing,            0x9C, 1, KaxTracks, "TrackFlagLacing");
DEFINE_MKX_UINTEGER (KaxTrackMinCache,            0x6DE7, 2, KaxTracks, "TrackMinCache");
DEFINE_MKX_UINTEGER (KaxTrackMaxCache,            0x6DF8, 2, KaxTracks, "TrackMaxCache\0rotomodobopo");
DEFINE_MKX_UINTEGER (KaxTrackDefaultDuration,   0x23E383, 3, KaxTracks, "TrackDefaultDuration");
DEFINE_MKX_FLOAT    (KaxTrackTimecodeScale,     0x23314F, 3, KaxTracks, "TrackTimecodeScale");
DEFINE_MKX_UINTEGER (KaxMaxBlockAdditionID,       0x55EE, 2, KaxTracks, "MaxBlockAdditionID");
DEFINE_MKX_UNISTRING(KaxTrackName,                0x536E, 2, KaxTracks, "TrackName");
DEFINE_MKX_STRING   (KaxTrackLanguage,          0x22B59C, 3, KaxTracks, "TrackLanguage");
DEFINE_MKX_STRING   (KaxCodecID,                    0x86, 1, KaxTracks, "CodecID");
DEFINE_MKX_BINARY   (KaxCodecPrivate,             0x63A2, 2, KaxTracks, "CodecPrivate");
DEFINE_MKX_UNISTRING(KaxCodecName,              0x258688, 3, KaxTracks, "CodecName");
DEFINE_MKX_BINARY   (KaxTrackAttachmentLink,      0x7446, 2, KaxTracks, "TrackAttachmentLink");
DEFINE_MKX_UINTEGER (KaxTrackOverlay,             0x6FAB, 2, KaxTracks, "TrackOverlay");
DEFINE_MKX_MASTER   (KaxTrackTranslate,           0x6624, 2, KaxTracks, "TrackTranslate");
DEFINE_MKX_UINTEGER (KaxTrackTranslateEditionUID, 0x66FC, 2, KaxTrackTranslate, "TrackTranslateEditionUID");
DEFINE_MKX_UINTEGER (KaxTrackTranslateCodec,      0x66BF, 2, KaxTrackTranslate, "TrackTranslateCodec");
DEFINE_MKX_BINARY   (KaxTrackTranslateTrackID,    0x66A5, 2, KaxTrackTranslate, "TrackTranslateTrackID");
#if MATROSKA_VERSION >= 2
DEFINE_MKX_UINTEGER (KaxTrackFlagEnabled,           0xB9, 1, KaxTracks, "TrackFlagDefault");
DEFINE_MKX_UNISTRING(KaxCodecSettings,          0x3A9697, 3, KaxTracks, "CodecSettings");
DEFINE_MKX_STRING   (KaxCodecInfoURL,           0x3B4040, 3, KaxTracks, "CodecInfoURL");
DEFINE_MKX_STRING   (KaxCodecDownloadURL,       0x26B240, 3, KaxTracks, "CodecDownloadURL");
DEFINE_MKX_UINTEGER (KaxCodecDecodeAll,             0xAA, 1, KaxTracks, "CodecDecodeAll");
#endif

KaxTrackTranslate::KaxTrackTranslate()
	:EbmlMaster(Context_KaxTrackTranslate)
{}

END_LIBMATROSKA_NAMESPACE
