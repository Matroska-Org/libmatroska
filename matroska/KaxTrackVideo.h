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
	\version \$Id: KaxTrackVideo.h,v 1.9 2004/04/14 23:26:17 robux4 Exp $
	\author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_TRACK_VIDEO_H
#define LIBMATROSKA_TRACK_VIDEO_H

#include "matroska/KaxTypes.h"
#include "ebml/EbmlMaster.h"
#include "ebml/EbmlUInteger.h"
#include "ebml/EbmlBinary.h"
#include "ebml/EbmlFloat.h"
#include "matroska/KaxDefines.h"

using namespace LIBEBML_NAMESPACE;

START_LIBMATROSKA_NAMESPACE

DECLARE_MKX_MASTER(KaxTrackVideo)
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_UINTEGER(KaxVideoFlagInterlaced)
};

DECLARE_MKX_UINTEGER(KaxVideoStereoMode)
};
#endif // MATROSKA_VERSION

DECLARE_MKX_UINTEGER(KaxVideoPixelWidth)
};

DECLARE_MKX_UINTEGER(KaxVideoPixelHeight)
};

DECLARE_MKX_UINTEGER(KaxVideoPixelCropBottom)
};

DECLARE_MKX_UINTEGER(KaxVideoPixelCropTop)
};

DECLARE_MKX_UINTEGER(KaxVideoPixelCropLeft)
};

DECLARE_MKX_UINTEGER(KaxVideoPixelCropRight)
};

DECLARE_MKX_UINTEGER(KaxVideoDisplayWidth)
};

DECLARE_MKX_UINTEGER(KaxVideoDisplayHeight)
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_UINTEGER(KaxVideoDisplayUnit)
};

DECLARE_MKX_UINTEGER(KaxVideoAspectRatio)
};
#endif // MATROSKA_VERSION

DECLARE_MKX_BINARY(KaxVideoColourSpace)
	public:
        bool ValidateSize(void) const {return (GetSize() == 4);}
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_FLOAT(KaxVideoGamma)
};
#endif // MATROSKA_VERSION

DECLARE_MKX_FLOAT(KaxVideoFrameRate)
	public:
		filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault);
};


END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_TRACK_VIDEO_H
