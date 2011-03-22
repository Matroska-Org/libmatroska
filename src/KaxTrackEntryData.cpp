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

DEFINE_START_SEMANTIC(KaxTrackTranslate)
DEFINE_SEMANTIC_ITEM(false, false, KaxTrackTranslateEditionUID)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackTranslateCodec)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackTranslateTrackID)
DEFINE_END_SEMANTIC(KaxTrackTranslate)

DEFINE_MKX_UINTEGER    (KaxTrackNumber,                0xD7, 1, KaxTrackEntry, "TrackNumber");
DEFINE_MKX_UINTEGER    (KaxTrackUID,                 0x73C5, 2, KaxTrackEntry, "TrackUID");
DEFINE_MKX_UINTEGER    (KaxTrackType,                  0x83, 1, KaxTrackEntry, "TrackType");
DEFINE_MKX_UINTEGER_DEF(KaxTrackFlagDefault,           0x88, 1, KaxTrackEntry, "TrackFlagDefault", 1);
DEFINE_MKX_UINTEGER_DEF(KaxTrackFlagForced,          0x55AA, 2, KaxTrackEntry, "TrackFlagForced", 0);
DEFINE_MKX_UINTEGER_DEF(KaxTrackFlagLacing,            0x9C, 1, KaxTrackEntry, "TrackFlagLacing", 1);
DEFINE_MKX_UINTEGER_DEF(KaxTrackMinCache,            0x6DE7, 2, KaxTrackEntry, "TrackMinCache", 0);
DEFINE_MKX_UINTEGER    (KaxTrackMaxCache,            0x6DF8, 2, KaxTrackEntry, "TrackMaxCache\0rotomodobopo");
DEFINE_MKX_UINTEGER    (KaxTrackDefaultDuration,   0x23E383, 3, KaxTrackEntry, "TrackDefaultDuration");
DEFINE_MKX_FLOAT_DEF   (KaxTrackTimecodeScale,     0x23314F, 3, KaxTrackEntry, "TrackTimecodeScale", 1.0);
DEFINE_MKX_UINTEGER_DEF(KaxMaxBlockAdditionID,       0x55EE, 2, KaxTrackEntry, "MaxBlockAdditionID", 0);
//DEFINE_MKX_SINTEGER_DEF(KaxTrackOffset,            0x537F, 2, KaxTrackEntry, "TrackOffset", 0);
DEFINE_MKX_UNISTRING   (KaxTrackName,                0x536E, 2, KaxTrackEntry, "TrackName");
DEFINE_MKX_STRING_DEF  (KaxTrackLanguage,          0x22B59C, 3, KaxTrackEntry, "TrackLanguage", "eng");
DEFINE_MKX_STRING      (KaxCodecID,                    0x86, 1, KaxTrackEntry, "CodecID");
DEFINE_MKX_BINARY      (KaxCodecPrivate,             0x63A2, 2, KaxTrackEntry, "CodecPrivate");
DEFINE_MKX_UNISTRING   (KaxCodecName,              0x258688, 3, KaxTrackEntry, "CodecName");
DEFINE_MKX_UINTEGER    (KaxTrackAttachmentLink,      0x7446, 2, KaxTrackEntry, "TrackAttachmentLink");
DEFINE_MKX_UINTEGER    (KaxTrackOverlay,             0x6FAB, 2, KaxTrackEntry, "TrackOverlay");
DEFINE_MKX_MASTER      (KaxTrackTranslate,           0x6624, 2, KaxTrackEntry, "TrackTranslate");
DEFINE_MKX_UINTEGER    (KaxTrackTranslateEditionUID, 0x66FC, 2, KaxTrackTranslate, "TrackTranslateEditionUID");
DEFINE_MKX_UINTEGER    (KaxTrackTranslateCodec,      0x66BF, 2, KaxTrackTranslate, "TrackTranslateCodec");
DEFINE_MKX_BINARY      (KaxTrackTranslateTrackID,    0x66A5, 2, KaxTrackTranslate, "TrackTranslateTrackID");
#if MATROSKA_VERSION >= 2
DEFINE_MKX_UINTEGER_DEF(KaxTrackFlagEnabled,           0xB9, 1, KaxTrackEntry, "TrackFlagEnabled", 1);
DEFINE_MKX_UNISTRING   (KaxCodecSettings,          0x3A9697, 3, KaxTrackEntry, "CodecSettings");
DEFINE_MKX_STRING      (KaxCodecInfoURL,           0x3B4040, 3, KaxTrackEntry, "CodecInfoURL");
DEFINE_MKX_STRING      (KaxCodecDownloadURL,       0x26B240, 3, KaxTrackEntry, "CodecDownloadURL");
DEFINE_MKX_UINTEGER_DEF(KaxCodecDecodeAll,             0xAA, 1, KaxTrackEntry, "CodecDecodeAll", 1);
#endif

END_LIBMATROSKA_NAMESPACE
