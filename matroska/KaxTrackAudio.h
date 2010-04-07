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
	\version \$Id: KaxTrackAudio.h,v 1.11 2004/04/14 23:26:17 robux4 Exp $
	\author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_TRACK_AUDIO_H
#define LIBMATROSKA_TRACK_AUDIO_H

#include "matroska/KaxTypes.h"
#include "ebml/EbmlMaster.h"
#include "ebml/EbmlFloat.h"
#include "ebml/EbmlUInteger.h"
#include "ebml/EbmlBinary.h"
#include "matroska/KaxDefines.h"

using namespace LIBEBML_NAMESPACE;

START_LIBMATROSKA_NAMESPACE

DECLARE_MKX_MASTER(KaxTrackAudio)
};

DECLARE_MKX_FLOAT(KaxAudioSamplingFreq)
};

DECLARE_MKX_FLOAT(KaxAudioOutputSamplingFreq)
};

DECLARE_MKX_UINTEGER(KaxAudioChannels)
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_BINARY(KaxAudioPosition)
	public:
        bool ValidateSize(void) const {return true;}
};
#endif // MATROSKA_VERSION

DECLARE_MKX_UINTEGER(KaxAudioBitDepth)
};

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_TRACK_AUDIO_H
