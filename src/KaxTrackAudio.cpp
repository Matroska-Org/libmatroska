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
	\version \$Id: KaxTrackAudio.cpp 640 2004-07-09 21:05:36Z mosu $
	\author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include "matroska/KaxTrackAudio.h"

// sub elements
#include "matroska/KaxContexts.h"
#include "matroska/KaxDefines.h"

START_LIBMATROSKA_NAMESPACE

DEFINE_START_SEMANTIC(KaxTrackAudio)
DEFINE_SEMANTIC_ITEM(true, true, KaxAudioSamplingFreq)
DEFINE_SEMANTIC_ITEM(true, true, KaxAudioChannels)
DEFINE_SEMANTIC_ITEM(false, true, KaxAudioBitDepth)
DEFINE_SEMANTIC_ITEM(false, true, KaxAudioOutputSamplingFreq)
#if MATROSKA_VERSION >= 2
DEFINE_SEMANTIC_ITEM(false, true, KaxAudioPosition)
#endif // MATROSKA_VERSION
DEFINE_END_SEMANTIC(KaxTrackAudio)

DEFINE_MKX_MASTER      (KaxTrackAudio,                0xE1, 1, KaxTrackEntry, "TrackAudio");
DEFINE_MKX_FLOAT_DEF   (KaxAudioSamplingFreq,         0xB5, 1, KaxTrackAudio, "AudioSamplingFreq", 8000.0);
DEFINE_MKX_FLOAT       (KaxAudioOutputSamplingFreq, 0x78B5, 2, KaxTrackAudio, "AudioOutputSamplingFreq");
DEFINE_MKX_UINTEGER_DEF(KaxAudioChannels,             0x9F, 1, KaxTrackAudio, "AudioChannels", 1);
DEFINE_MKX_UINTEGER    (KaxAudioBitDepth,           0x6264, 2, KaxTrackAudio, "AudioBitDepth");
#if MATROSKA_VERSION >= 2
DEFINE_MKX_BINARY      (KaxAudioPosition,           0x7D7B, 2, KaxTrackAudio, "AudioPosition");
#endif

END_LIBMATROSKA_NAMESPACE
