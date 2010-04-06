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
	public:
		KaxTrackVideo(const KaxTrackVideo & ElementToClone) :EbmlMaster(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxTrackVideo)
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_UINTEGER(KaxVideoFlagInterlaced)
	public:
		KaxVideoFlagInterlaced(const KaxVideoFlagInterlaced & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxVideoFlagInterlaced)
};

DECLARE_MKX_UINTEGER(KaxVideoStereoMode)
	public:
		KaxVideoStereoMode(const KaxVideoStereoMode & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxVideoStereoMode)
};
#endif // MATROSKA_VERSION

DECLARE_MKX_UINTEGER(KaxVideoPixelWidth)
	public:
		KaxVideoPixelWidth(const KaxVideoPixelWidth & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxVideoPixelWidth)
};

DECLARE_MKX_UINTEGER(KaxVideoPixelHeight)
	public:
		KaxVideoPixelHeight(const KaxVideoPixelHeight & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxVideoPixelHeight)
};

DECLARE_MKX_UINTEGER(KaxVideoPixelCropBottom)
	public:
		KaxVideoPixelCropBottom(const KaxVideoPixelCropBottom & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxVideoPixelCropBottom)
};

DECLARE_MKX_UINTEGER(KaxVideoPixelCropTop)
	public:
		KaxVideoPixelCropTop(const KaxVideoPixelCropTop & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxVideoPixelCropTop)
};

DECLARE_MKX_UINTEGER(KaxVideoPixelCropLeft)
	public:
		KaxVideoPixelCropLeft(const KaxVideoPixelCropLeft & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxVideoPixelCropLeft)
};

DECLARE_MKX_UINTEGER(KaxVideoPixelCropRight)
	public:
		KaxVideoPixelCropRight(const KaxVideoPixelCropRight & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxVideoPixelCropRight)
};

DECLARE_MKX_UINTEGER(KaxVideoDisplayWidth)
	public:
		KaxVideoDisplayWidth(const KaxVideoDisplayWidth & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxVideoDisplayWidth)
};

DECLARE_MKX_UINTEGER(KaxVideoDisplayHeight)
	public:
		KaxVideoDisplayHeight(const KaxVideoDisplayHeight & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxVideoDisplayHeight)
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_UINTEGER(KaxVideoDisplayUnit)
	public:
		KaxVideoDisplayUnit(const KaxVideoDisplayUnit & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxVideoDisplayUnit)
};

DECLARE_MKX_UINTEGER(KaxVideoAspectRatio)
	public:
		KaxVideoAspectRatio(const KaxVideoAspectRatio & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxVideoAspectRatio)
};
#endif // MATROSKA_VERSION

DECLARE_MKX_BINARY(KaxVideoColourSpace)
	public:
		KaxVideoColourSpace(const KaxVideoColourSpace & ElementToClone) :EbmlBinary(ElementToClone){}
        bool ValidateSize(void) const {return (GetSize() == 4);}

        EBML_CONCRETE_CLASS(KaxVideoColourSpace)
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_FLOAT(KaxVideoGamma)
	public:
		KaxVideoGamma(const KaxVideoGamma & ElementToClone) :EbmlFloat(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxVideoGamma)
};
#endif // MATROSKA_VERSION

DECLARE_MKX_FLOAT(KaxVideoFrameRate)
	public:
		KaxVideoFrameRate(const KaxVideoFrameRate & ElementToClone) :EbmlFloat(ElementToClone) {}
		filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault);

        EBML_CONCRETE_CLASS(KaxVideoFrameRate)
};


END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_TRACK_VIDEO_H
