/**********************************************************************
**  DO NOT EDIT, GENERATED WITH DATA2LIB
** 
**  libmatroska : parse Matroska files, see http://www.matroska.org/
** 
**  Copyright (c) 2002-2010, Matroska (non-profit organisation)
**  All rights reserved.
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
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**
** See http://www.gnu.org/licenses/lgpl-2.1.html for LGPL licensing information.**
** Contact license@matroska.org if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/


#ifndef LIBMATROSKA_SEMANTIC_H
#define LIBMATROSKA_SEMANTIC_H

#include "matroska/KaxTypes.h"
#include "ebml/EbmlUInteger.h"
#include "ebml/EbmlSInteger.h"
#include "ebml/EbmlDate.h"
#include "ebml/EbmlFloat.h"
#include "ebml/EbmlString.h"
#include "ebml/EbmlUnicodeString.h"
#include "ebml/EbmlBinary.h"
#include "ebml/EbmlMaster.h"
#include "matroska/KaxDefines.h"

using namespace LIBEBML_NAMESPACE;

START_LIBMATROSKA_NAMESPACE

DECLARE_MKX_BINARY (KaxSeekID)
public:
	virtual bool ValidateSize() const {return IsFiniteSize() && GetSize() <= 4;}
};

DECLARE_MKX_UINTEGER(KaxSeekPosition)
};

DECLARE_MKX_MASTER(KaxInfo)
};


DECLARE_MKX_BINARY (KaxSegmentUID)
#if defined(HAVE_EBML2) || defined(HAS_EBML2)
public:
	KaxSegmentUID(EBML_DEF_CONS EBML_DEF_SEP EBML_EXTRA_PARAM);
#endif
public:
	virtual bool ValidateSize() const {return IsFiniteSize() && GetSize() == 16;}
};

DECLARE_MKX_UNISTRING(KaxSegmentFilename)
};

DECLARE_MKX_UNISTRING(KaxPrevFilename)
};

DECLARE_MKX_UNISTRING(KaxNextFilename)
};

DECLARE_MKX_BINARY (KaxSegmentFamily)
public:
	virtual bool ValidateSize() const {return IsFiniteSize() && GetSize() == 16;}
};

DECLARE_MKX_MASTER(KaxChapterTranslate)
};


DECLARE_MKX_UINTEGER(KaxChapterTranslateEditionUID)
};

DECLARE_MKX_UINTEGER(KaxChapterTranslateCodec)
};

DECLARE_MKX_BINARY (KaxChapterTranslateID)
};

DECLARE_MKX_UINTEGER(KaxTimecodeScale)
};

DECLARE_MKX_FLOAT(KaxDuration)
};

DECLARE_MKX_DATE    (KaxDateUTC)
};

DECLARE_MKX_UNISTRING(KaxTitle)
};

DECLARE_MKX_UNISTRING(KaxMuxingApp)
};

DECLARE_MKX_UNISTRING(KaxWritingApp)
};

DECLARE_MKX_UINTEGER(KaxClusterTimecode)
};

DECLARE_MKX_MASTER(KaxClusterSilentTracks)
};


DECLARE_MKX_UINTEGER(KaxClusterSilentTrackNumber)
};

DECLARE_MKX_UINTEGER(KaxClusterPosition)
};

DECLARE_MKX_UINTEGER(KaxClusterPrevSize)
};

DECLARE_MKX_MASTER(KaxBlockAdditions)
};


DECLARE_MKX_MASTER(KaxBlockMore)
};


DECLARE_MKX_UINTEGER(KaxBlockAddID)
};

DECLARE_MKX_BINARY (KaxBlockAdditional)
};

DECLARE_MKX_UINTEGER(KaxBlockDuration)
};

DECLARE_MKX_UINTEGER(KaxReferencePriority)
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_SINTEGER(KaxReferenceVirtual)
public:
	filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault);
};

DECLARE_MKX_BINARY (KaxCodecState)
};

DECLARE_MKX_SINTEGER(KaxDiscardPadding)
};
#endif

DECLARE_MKX_MASTER(KaxSlices)
};


DECLARE_MKX_MASTER(KaxTimeSlice)
};


DECLARE_MKX_UINTEGER(KaxSliceLaceNumber)
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_UINTEGER(KaxSliceFrameNumber)
public:
	filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault);
};

DECLARE_MKX_UINTEGER(KaxSliceBlockAddID)
public:
	filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault);
};

DECLARE_MKX_UINTEGER(KaxSliceDelay)
public:
	filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault);
};

DECLARE_MKX_UINTEGER(KaxSliceDuration)
public:
	filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault);
};

DECLARE_MKX_MASTER(KaxReferenceFrame)
};


DECLARE_MKX_UINTEGER(KaxReferenceOffset)
};

DECLARE_MKX_UINTEGER(KaxReferenceTimeCode)
};

DECLARE_MKX_BINARY (KaxEncryptedBlock)
public:
	filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault);
};
#endif

DECLARE_MKX_MASTER(KaxTracks)
};


DECLARE_MKX_UINTEGER(KaxTrackNumber)
};

DECLARE_MKX_UINTEGER(KaxTrackUID)
};

DECLARE_MKX_UINTEGER(KaxTrackType)
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_UINTEGER(KaxTrackFlagEnabled)
};
#endif

DECLARE_MKX_UINTEGER(KaxTrackFlagDefault)
};

DECLARE_MKX_UINTEGER(KaxTrackFlagForced)
};

DECLARE_MKX_UINTEGER(KaxTrackFlagLacing)
};

DECLARE_MKX_UINTEGER(KaxTrackMinCache)
};

DECLARE_MKX_UINTEGER(KaxTrackMaxCache)
};

DECLARE_MKX_UINTEGER(KaxTrackDefaultDuration)
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_UINTEGER(KaxTrackDefaultDecodedFieldDuration)
};
#endif

DECLARE_MKX_FLOAT(KaxTrackTimecodeScale)
public:
	filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault);
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_SINTEGER(KaxTrackOffset)
public:
	filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault);
};
#endif

DECLARE_MKX_UINTEGER(KaxMaxBlockAdditionID)
};

DECLARE_MKX_UNISTRING(KaxTrackName)
};

DECLARE_MKX_STRING(KaxTrackLanguage)
};

DECLARE_MKX_STRING(KaxCodecID)
};

DECLARE_MKX_BINARY (KaxCodecPrivate)
};

DECLARE_MKX_UNISTRING(KaxCodecName)
};

DECLARE_MKX_UINTEGER(KaxTrackAttachmentLink)
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_UNISTRING(KaxCodecSettings)
public:
	filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault);
};

DECLARE_MKX_STRING(KaxCodecInfoURL)
public:
	filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault);
};

DECLARE_MKX_STRING(KaxCodecDownloadURL)
public:
	filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault);
};

DECLARE_MKX_UINTEGER(KaxCodecDecodeAll)
};
#endif

DECLARE_MKX_UINTEGER(KaxTrackOverlay)
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_UINTEGER(KaxCodecDelay)
};

DECLARE_MKX_UINTEGER(KaxSeekPreRoll)
};
#endif

DECLARE_MKX_MASTER(KaxTrackTranslate)
};


DECLARE_MKX_UINTEGER(KaxTrackTranslateEditionUID)
};

DECLARE_MKX_UINTEGER(KaxTrackTranslateCodec)
};

DECLARE_MKX_BINARY (KaxTrackTranslateTrackID)
};

DECLARE_MKX_MASTER(KaxTrackVideo)
};


#if MATROSKA_VERSION >= 2
DECLARE_MKX_UINTEGER(KaxVideoFlagInterlaced)
};

DECLARE_MKX_UINTEGER(KaxVideoStereoMode)
};

DECLARE_MKX_UINTEGER(KaxVideoAlphaMode)
};

DECLARE_MKX_UINTEGER(KaxOldStereoMode)
public:
	filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault);
};
#endif

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

DECLARE_MKX_UINTEGER(KaxVideoDisplayUnit)
};

DECLARE_MKX_UINTEGER(KaxVideoAspectRatio)
};

DECLARE_MKX_BINARY (KaxVideoColourSpace)
public:
	virtual bool ValidateSize() const {return IsFiniteSize() && GetSize() == 4;}
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_FLOAT(KaxVideoGamma)
public:
	filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault);
};

DECLARE_MKX_FLOAT(KaxVideoFrameRate)
public:
	filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault);
};
#endif

DECLARE_MKX_MASTER(KaxTrackAudio)
};


DECLARE_MKX_FLOAT(KaxAudioSamplingFreq)
};

DECLARE_MKX_FLOAT(KaxAudioOutputSamplingFreq)
};

DECLARE_MKX_UINTEGER(KaxAudioChannels)
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_BINARY (KaxAudioPosition)
public:
	filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault);
};
#endif

DECLARE_MKX_UINTEGER(KaxAudioBitDepth)
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_MASTER(KaxTrackOperation)
};


DECLARE_MKX_MASTER(KaxTrackCombinePlanes)
};


DECLARE_MKX_MASTER(KaxTrackPlane)
};


DECLARE_MKX_UINTEGER(KaxTrackPlaneUID)
};

DECLARE_MKX_UINTEGER(KaxTrackPlaneType)
};

DECLARE_MKX_MASTER(KaxTrackJoinBlocks)
};


DECLARE_MKX_UINTEGER(KaxTrackJoinUID)
};

DECLARE_MKX_UINTEGER(KaxTrickTrackUID)
};

DECLARE_MKX_BINARY (KaxTrickTrackSegmentUID)
public:
	virtual bool ValidateSize() const {return IsFiniteSize() && GetSize() == 16;}
};

DECLARE_MKX_UINTEGER(KaxTrickTrackFlag)
};

DECLARE_MKX_UINTEGER(KaxTrickMasterTrackUID)
};

DECLARE_MKX_BINARY (KaxTrickMasterTrackSegmentUID)
public:
	virtual bool ValidateSize() const {return IsFiniteSize() && GetSize() == 16;}
};
#endif

DECLARE_MKX_MASTER(KaxContentEncodings)
};


DECLARE_MKX_MASTER(KaxContentEncoding)
};


DECLARE_MKX_UINTEGER(KaxContentEncodingOrder)
};

DECLARE_MKX_UINTEGER(KaxContentEncodingScope)
};

DECLARE_MKX_UINTEGER(KaxContentEncodingType)
};

DECLARE_MKX_MASTER(KaxContentCompression)
};


DECLARE_MKX_UINTEGER(KaxContentCompAlgo)
};

DECLARE_MKX_BINARY (KaxContentCompSettings)
};

DECLARE_MKX_MASTER(KaxContentEncryption)
};


DECLARE_MKX_UINTEGER(KaxContentEncAlgo)
};

DECLARE_MKX_BINARY (KaxContentEncKeyID)
};

DECLARE_MKX_BINARY (KaxContentSignature)
};

DECLARE_MKX_BINARY (KaxContentSigKeyID)
};

DECLARE_MKX_UINTEGER(KaxContentSigAlgo)
};

DECLARE_MKX_UINTEGER(KaxContentSigHashAlgo)
};

DECLARE_MKX_UINTEGER(KaxCueTime)
};

DECLARE_MKX_UINTEGER(KaxCueTrack)
};

DECLARE_MKX_UINTEGER(KaxCueClusterPosition)
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_UINTEGER(KaxCueRelativePosition)
};

DECLARE_MKX_UINTEGER(KaxCueDuration)
};
#endif

DECLARE_MKX_UINTEGER(KaxCueBlockNumber)
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_UINTEGER(KaxCueCodecState)
};

DECLARE_MKX_UINTEGER(KaxCueRefTime)
};

DECLARE_MKX_UINTEGER(KaxCueRefCluster)
public:
	filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault);
};

DECLARE_MKX_UINTEGER(KaxCueRefNumber)
public:
	filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault);
};

DECLARE_MKX_UINTEGER(KaxCueRefCodecState)
public:
	filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault);
};
#endif

DECLARE_MKX_MASTER(KaxAttachments)
};


DECLARE_MKX_MASTER(KaxAttached)
};


DECLARE_MKX_UNISTRING(KaxFileDescription)
};

DECLARE_MKX_UNISTRING(KaxFileName)
};

DECLARE_MKX_STRING(KaxMimeType)
};

DECLARE_MKX_BINARY (KaxFileData)
};

DECLARE_MKX_UINTEGER(KaxFileUID)
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_BINARY (KaxFileReferral)
public:
	filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault);
};

DECLARE_MKX_UINTEGER(KaxFileUsedStartTime)
};

DECLARE_MKX_UINTEGER(KaxFileUsedEndTime)
};
#endif

DECLARE_MKX_MASTER(KaxChapters)
};


DECLARE_MKX_MASTER(KaxEditionEntry)
};


DECLARE_MKX_UINTEGER(KaxEditionUID)
};

DECLARE_MKX_UINTEGER(KaxEditionFlagHidden)
};

DECLARE_MKX_UINTEGER(KaxEditionFlagDefault)
};

DECLARE_MKX_UINTEGER(KaxEditionFlagOrdered)
};

DECLARE_MKX_MASTER(KaxChapterAtom)
};


DECLARE_MKX_UINTEGER(KaxChapterUID)
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_UNISTRING(KaxChapterStringUID)
};
#endif

DECLARE_MKX_UINTEGER(KaxChapterTimeStart)
};

DECLARE_MKX_UINTEGER(KaxChapterTimeEnd)
};

DECLARE_MKX_UINTEGER(KaxChapterFlagHidden)
};

DECLARE_MKX_UINTEGER(KaxChapterFlagEnabled)
};

DECLARE_MKX_BINARY (KaxChapterSegmentUID)
public:
	virtual bool ValidateSize() const {return IsFiniteSize() && GetSize() == 16;}
};

DECLARE_MKX_UINTEGER(KaxChapterSegmentEditionUID)
};

DECLARE_MKX_UINTEGER(KaxChapterPhysicalEquiv)
};

DECLARE_MKX_MASTER(KaxChapterTrack)
};


DECLARE_MKX_UINTEGER(KaxChapterTrackNumber)
};

DECLARE_MKX_MASTER(KaxChapterDisplay)
};


DECLARE_MKX_UNISTRING(KaxChapterString)
};

DECLARE_MKX_STRING(KaxChapterLanguage)
};

DECLARE_MKX_STRING(KaxChapterCountry)
};

DECLARE_MKX_MASTER(KaxChapterProcess)
};


DECLARE_MKX_UINTEGER(KaxChapterProcessCodecID)
};

DECLARE_MKX_BINARY (KaxChapterProcessPrivate)
};

DECLARE_MKX_MASTER(KaxChapterProcessCommand)
};


DECLARE_MKX_UINTEGER(KaxChapterProcessTime)
};

DECLARE_MKX_BINARY (KaxChapterProcessData)
};

DECLARE_MKX_MASTER(KaxTags)
};


DECLARE_MKX_MASTER(KaxTag)
};


DECLARE_MKX_MASTER(KaxTagTargets)
};


DECLARE_MKX_UINTEGER(KaxTagTargetTypeValue)
};

DECLARE_MKX_STRING(KaxTagTargetType)
};

DECLARE_MKX_UINTEGER(KaxTagTrackUID)
};

DECLARE_MKX_UINTEGER(KaxTagEditionUID)
};

DECLARE_MKX_UINTEGER(KaxTagChapterUID)
};

DECLARE_MKX_UINTEGER(KaxTagAttachmentUID)
};

DECLARE_MKX_MASTER(KaxTagSimple)
};


DECLARE_MKX_UNISTRING(KaxTagName)
};

DECLARE_MKX_STRING(KaxTagLangue)
};

DECLARE_MKX_UINTEGER(KaxTagDefault)
};

DECLARE_MKX_UNISTRING(KaxTagString)
};

DECLARE_MKX_BINARY (KaxTagBinary)
};

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_SEMANTIC_H
