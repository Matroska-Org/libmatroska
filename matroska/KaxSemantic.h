/**********************************************************************
**  DO NOT EDIT, GENERATED WITH DATA2LIB
**  https://github.com/Matroska-Org/foundation-source/tree/master/spectool
**
**  libmatroska : parse Matroska files, see https://www.matroska.org/
**
**  Copyright (c) 2002-2022, Matroska (non-profit organisation)
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

using namespace libebml;

namespace libmatroska {
DECLARE_MKX_BINARY (KaxSeekID)
public:
  bool ValidateSize() const override {return IsFiniteSize() && GetSize() <= 4;}
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
  bool ValidateSize() const override {return IsFiniteSize() && GetSize() == 16;}
};

DECLARE_MKX_UNISTRING(KaxSegmentFilename)
};

DECLARE_MKX_UNISTRING(KaxPrevFilename)
};

DECLARE_MKX_UNISTRING(KaxNextFilename)
};

DECLARE_MKX_BINARY (KaxSegmentFamily)
public:
  bool ValidateSize() const override {return IsFiniteSize() && GetSize() == 16;}
};

DECLARE_MKX_MASTER(KaxChapterTranslate)
};

DECLARE_MKX_BINARY (KaxChapterTranslateID)
};

DECLARE_MKX_UINTEGER(KaxChapterTranslateCodec)
};

DECLARE_MKX_UINTEGER(KaxChapterTranslateEditionUID)
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
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_UINTEGER(KaxClusterSilentTrackNumber)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_UINTEGER(KaxClusterPosition)
};

DECLARE_MKX_UINTEGER(KaxClusterPrevSize)
};

DECLARE_MKX_MASTER(KaxBlockAdditions)
};

DECLARE_MKX_MASTER(KaxBlockMore)
};

DECLARE_MKX_BINARY (KaxBlockAdditional)
};

DECLARE_MKX_UINTEGER(KaxBlockAddID)
};

DECLARE_MKX_UINTEGER(KaxBlockDuration)
};

DECLARE_MKX_UINTEGER(KaxReferencePriority)
};

DECLARE_MKX_SINTEGER(KaxReferenceVirtual)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_BINARY (KaxCodecState)
};

DECLARE_MKX_SINTEGER(KaxDiscardPadding)
};

DECLARE_MKX_MASTER(KaxSlices)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_MASTER(KaxTimeSlice)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_UINTEGER(KaxSliceLaceNumber)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_UINTEGER(KaxSliceFrameNumber)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_UINTEGER(KaxSliceBlockAddID)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_UINTEGER(KaxSliceDelay)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_UINTEGER(KaxSliceDuration)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_MASTER(KaxReferenceFrame)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_UINTEGER(KaxReferenceOffset)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_UINTEGER(KaxReferenceTimeCode)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_BINARY (KaxEncryptedBlock)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_MASTER(KaxTracks)
};

DECLARE_MKX_UINTEGER(KaxTrackNumber)
};

DECLARE_MKX_UINTEGER(KaxTrackUID)
};

DECLARE_MKX_UINTEGER(KaxTrackType)
};

DECLARE_MKX_UINTEGER(KaxTrackFlagEnabled)
};

DECLARE_MKX_UINTEGER(KaxTrackFlagDefault)
};

DECLARE_MKX_UINTEGER(KaxTrackFlagForced)
};

DECLARE_MKX_UINTEGER(KaxFlagHearingImpaired)
};

DECLARE_MKX_UINTEGER(KaxFlagVisualImpaired)
};

DECLARE_MKX_UINTEGER(KaxFlagTextDescriptions)
};

DECLARE_MKX_UINTEGER(KaxFlagOriginal)
};

DECLARE_MKX_UINTEGER(KaxFlagCommentary)
};

DECLARE_MKX_UINTEGER(KaxTrackFlagLacing)
};

DECLARE_MKX_UINTEGER(KaxTrackMinCache)
};

DECLARE_MKX_UINTEGER(KaxTrackMaxCache)
};

DECLARE_MKX_UINTEGER(KaxTrackDefaultDuration)
};

DECLARE_MKX_UINTEGER(KaxTrackDefaultDecodedFieldDuration)
};

DECLARE_MKX_FLOAT(KaxTrackTimecodeScale)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_SINTEGER(KaxTrackOffset)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_UINTEGER(KaxMaxBlockAdditionID)
};

DECLARE_MKX_MASTER(KaxBlockAdditionMapping)
};

DECLARE_MKX_UINTEGER(KaxBlockAddIDValue)
};

DECLARE_MKX_STRING(KaxBlockAddIDName)
};

DECLARE_MKX_UINTEGER(KaxBlockAddIDType)
};

DECLARE_MKX_BINARY (KaxBlockAddIDExtraData)
};

DECLARE_MKX_UNISTRING(KaxTrackName)
};

DECLARE_MKX_STRING(KaxTrackLanguage)
};

DECLARE_MKX_STRING(KaxLanguageIETF)
};

DECLARE_MKX_STRING(KaxCodecID)
};

DECLARE_MKX_BINARY (KaxCodecPrivate)
};

DECLARE_MKX_UNISTRING(KaxCodecName)
};

DECLARE_MKX_UINTEGER(KaxTrackAttachmentLink)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_UNISTRING(KaxCodecSettings)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_STRING(KaxCodecInfoURL)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_STRING(KaxCodecDownloadURL)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_UINTEGER(KaxCodecDecodeAll)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_UINTEGER(KaxTrackOverlay)
};

DECLARE_MKX_UINTEGER(KaxCodecDelay)
};

DECLARE_MKX_UINTEGER(KaxSeekPreRoll)
};

DECLARE_MKX_MASTER(KaxTrackTranslate)
};

DECLARE_MKX_BINARY (KaxTrackTranslateTrackID)
};

DECLARE_MKX_UINTEGER(KaxTrackTranslateCodec)
};

DECLARE_MKX_UINTEGER(KaxTrackTranslateEditionUID)
};

DECLARE_MKX_MASTER(KaxTrackVideo)
};

DECLARE_MKX_UINTEGER(KaxVideoFlagInterlaced)
};

DECLARE_MKX_UINTEGER(KaxVideoFieldOrder)
};

DECLARE_MKX_UINTEGER(KaxVideoStereoMode)
};

DECLARE_MKX_UINTEGER(KaxVideoAlphaMode)
};

DECLARE_MKX_UINTEGER(KaxOldStereoMode)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

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
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_BINARY (KaxVideoColourSpace)
public:
  bool ValidateSize() const override {return IsFiniteSize() && GetSize() == 4;}
};

DECLARE_MKX_FLOAT(KaxVideoGamma)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_FLOAT(KaxVideoFrameRate)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_MASTER(KaxVideoColour)
};

DECLARE_MKX_UINTEGER(KaxVideoColourMatrix)
};

DECLARE_MKX_UINTEGER(KaxVideoBitsPerChannel)
};

DECLARE_MKX_UINTEGER(KaxVideoChromaSubsampHorz)
};

DECLARE_MKX_UINTEGER(KaxVideoChromaSubsampVert)
};

DECLARE_MKX_UINTEGER(KaxVideoCbSubsampHorz)
};

DECLARE_MKX_UINTEGER(KaxVideoCbSubsampVert)
};

DECLARE_MKX_UINTEGER(KaxVideoChromaSitHorz)
};

DECLARE_MKX_UINTEGER(KaxVideoChromaSitVert)
};

DECLARE_MKX_UINTEGER(KaxVideoColourRange)
};

DECLARE_MKX_UINTEGER(KaxVideoColourTransferCharacter)
};

DECLARE_MKX_UINTEGER(KaxVideoColourPrimaries)
};

DECLARE_MKX_UINTEGER(KaxVideoColourMaxCLL)
};

DECLARE_MKX_UINTEGER(KaxVideoColourMaxFALL)
};

DECLARE_MKX_MASTER(KaxVideoColourMasterMeta)
};

DECLARE_MKX_FLOAT(KaxVideoRChromaX)
};

DECLARE_MKX_FLOAT(KaxVideoRChromaY)
};

DECLARE_MKX_FLOAT(KaxVideoGChromaX)
};

DECLARE_MKX_FLOAT(KaxVideoGChromaY)
};

DECLARE_MKX_FLOAT(KaxVideoBChromaX)
};

DECLARE_MKX_FLOAT(KaxVideoBChromaY)
};

DECLARE_MKX_FLOAT(KaxVideoWhitePointChromaX)
};

DECLARE_MKX_FLOAT(KaxVideoWhitePointChromaY)
};

DECLARE_MKX_FLOAT(KaxVideoLuminanceMax)
};

DECLARE_MKX_FLOAT(KaxVideoLuminanceMin)
};

DECLARE_MKX_MASTER(KaxVideoProjection)
};

DECLARE_MKX_UINTEGER(KaxVideoProjectionType)
};

DECLARE_MKX_BINARY (KaxVideoProjectionPrivate)
};

DECLARE_MKX_FLOAT(KaxVideoProjectionPoseYaw)
};

DECLARE_MKX_FLOAT(KaxVideoProjectionPosePitch)
};

DECLARE_MKX_FLOAT(KaxVideoProjectionPoseRoll)
};

DECLARE_MKX_MASTER(KaxTrackAudio)
};

DECLARE_MKX_FLOAT(KaxAudioSamplingFreq)
};

DECLARE_MKX_FLOAT(KaxAudioOutputSamplingFreq)
};

DECLARE_MKX_UINTEGER(KaxAudioChannels)
};

DECLARE_MKX_BINARY (KaxAudioPosition)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_UINTEGER(KaxAudioBitDepth)
};

DECLARE_MKX_UINTEGER(KaxEmphasis)
};

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
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_BINARY (KaxTrickTrackSegmentUID)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
  bool ValidateSize() const override {return IsFiniteSize() && GetSize() == 16;}
};

DECLARE_MKX_UINTEGER(KaxTrickTrackFlag)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_UINTEGER(KaxTrickMasterTrackUID)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_BINARY (KaxTrickMasterTrackSegmentUID)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
  bool ValidateSize() const override {return IsFiniteSize() && GetSize() == 16;}
};

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

DECLARE_MKX_MASTER(KaxContentEncAESSettings)
};

DECLARE_MKX_UINTEGER(KaxAESSettingsCipherMode)
};

DECLARE_MKX_BINARY (KaxContentSignature)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_BINARY (KaxContentSigKeyID)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_UINTEGER(KaxContentSigAlgo)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_UINTEGER(KaxContentSigHashAlgo)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_UINTEGER(KaxCueTime)
};

DECLARE_MKX_UINTEGER(KaxCueTrack)
};

DECLARE_MKX_UINTEGER(KaxCueClusterPosition)
};

DECLARE_MKX_UINTEGER(KaxCueRelativePosition)
};

DECLARE_MKX_UINTEGER(KaxCueDuration)
};

DECLARE_MKX_UINTEGER(KaxCueBlockNumber)
};

DECLARE_MKX_UINTEGER(KaxCueCodecState)
};

DECLARE_MKX_UINTEGER(KaxCueRefTime)
};

DECLARE_MKX_UINTEGER(KaxCueRefCluster)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_UINTEGER(KaxCueRefNumber)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_UINTEGER(KaxCueRefCodecState)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

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

DECLARE_MKX_BINARY (KaxFileReferral)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_UINTEGER(KaxFileUsedStartTime)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_UINTEGER(KaxFileUsedEndTime)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

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

DECLARE_MKX_MASTER(KaxEditionDisplay)
};

DECLARE_MKX_UNISTRING(KaxEditionString)
};

DECLARE_MKX_STRING(KaxEditionLanguageIETF)
};

DECLARE_MKX_MASTER(KaxChapterAtom)
};

DECLARE_MKX_UINTEGER(KaxChapterUID)
};

DECLARE_MKX_UNISTRING(KaxChapterStringUID)
};

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
  bool ValidateSize() const override {return IsFiniteSize() && GetSize() == 16;}
};

DECLARE_MKX_UINTEGER(KaxChapterSkipType)
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

DECLARE_MKX_STRING(KaxChapLanguageIETF)
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

DECLARE_MKX_STRING(KaxTagLanguageIETF)
};

DECLARE_MKX_UINTEGER(KaxTagDefault)
};

DECLARE_MKX_UINTEGER(KaxTagDefaultBogus)
public:
  filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;
};

DECLARE_MKX_UNISTRING(KaxTagString)
};

DECLARE_MKX_BINARY (KaxTagBinary)
};

/**
 *The `TrackType` defines the type of each frame found in the Track.
The value **SHOULD** be stored on 1 octet.
 */
typedef enum {
  MATROSKA_TRACK_TYPE_VIDEO            = 0x1, // An image.
  MATROSKA_TRACK_TYPE_AUDIO            = 0x2, // Audio samples.
  MATROSKA_TRACK_TYPE_COMPLEX          = 0x3, // A mix of different other TrackType. The codec needs to define how the `Matroska Player` should interpret such data.
  MATROSKA_TRACK_TYPE_LOGO             = 0x10, // An image to be rendered over the video track(s).
  MATROSKA_TRACK_TYPE_SUBTITLE         = 0x11, // Subtitle or closed caption data to be rendered over the video track(s).
  MATROSKA_TRACK_TYPE_BUTTONS          = 0x12, // Interactive button(s) to be rendered over the video track(s).
  MATROSKA_TRACK_TYPE_CONTROL          = 0x20, // Metadata used to control the player of the `Matroska Player`.
  MATROSKA_TRACK_TYPE_METADATA         = 0x21, // Timed metadata that can be passed on to the `Matroska Player`.
} MatroskaTrackType;

/**
 *The compression algorithm used.
 */
typedef enum {
  MATROSKA_TRACK_ENCODING_COMP_NONE             = -1,
  MATROSKA_TRACK_ENCODING_COMP_ZLIB             = 0, // zlib compression [@!RFC1950].
  MATROSKA_TRACK_ENCODING_COMP_BZLIB            = 1, // bzip2 compression [@!BZIP2], **SHOULD NOT** be used; see usage notes.
  MATROSKA_TRACK_ENCODING_COMP_LZO1X            = 2, // Lempel-Ziv-Oberhumer compression [@!LZO], **SHOULD NOT** be used; see usage notes.
  MATROSKA_TRACK_ENCODING_COMP_HEADERSTRIP      = 3, // Octets in `ContentCompSettings` ((#contentcompsettings-element)) have been stripped from each frame.
} MatroskaTrackEncodingCompAlgo;

/**
 *This `ChapterTranslate` applies to this chapter codec of the given chapter edition(s); see (#chapprocesscodecid-element).
 */
typedef enum {
  MATROSKA_CHAPTERTRANSLATECODEC_MATROSKA_SCRIPT  = 0, // Chapter commands using the Matroska Script codec.
  MATROSKA_CHAPTERTRANSLATECODEC_DVD_MENU         = 1, // Chapter commands using the DVD-like codec.
} MatroskaChapterTranslateCodec;

/**
 *This `TrackTranslate` applies to this chapter codec of the given chapter edition(s); see (#chapprocesscodecid-element).
 */
typedef enum {
  MATROSKA_TRACKTRANSLATECODEC_MATROSKA_SCRIPT  = 0, // Chapter commands using the Matroska Script codec.
  MATROSKA_TRACKTRANSLATECODEC_DVD_MENU         = 1, // Chapter commands using the DVD-like codec.
} MatroskaTrackTranslateCodec;

/**
 *Specify whether the video frames in this track are interlaced or not.
 */
typedef enum {
  MATROSKA_VIDEO_FLAGINTERLACED_UNDETERMINED     = 0, // Unknown status.
  MATROSKA_VIDEO_FLAGINTERLACED_INTERLACED       = 1, // Interlaced frames.
  MATROSKA_VIDEO_FLAGINTERLACED_PROGRESSIVE      = 2, // No interlacing.
} MatroskaVideoFlagInterlaced;

/**
 *Specify the field ordering of video frames in this track.
 */
typedef enum {
  MATROSKA_VIDEO_FIELDORDER_PROGRESSIVE      = 0, // Interlaced frames.
  MATROSKA_VIDEO_FIELDORDER_TOPFIELDFIRST    = 1, // Top field displayed first. Top field stored first.
  MATROSKA_VIDEO_FIELDORDER_UNDETERMINED     = 2, // Unknown field order.
  MATROSKA_VIDEO_FIELDORDER_BOTTOMFIELDFIRST = 6, // Bottom field displayed first. Bottom field stored first.
  MATROSKA_VIDEO_FIELDORDER_BOTTOMFIELDSWAPPED = 9, // Top field displayed first. Fields are interleaved in storage with the top line of the top field stored first.
  MATROSKA_VIDEO_FIELDORDER_TOPFIELDSWAPPED  = 14, // Bottom field displayed first. Fields are interleaved in storage with the top line of the top field stored first.
} MatroskaVideoFieldOrder;

/**
 *Stereo-3D video mode. There are some more details in (#multi-planar-and-3d-videos).
 */
typedef enum {
  MATROSKA_VIDEO_STEREO_MONO             = 0,
  MATROSKA_VIDEO_STEREO_LEFT_RIGHT       = 1,
  MATROSKA_VIDEO_STEREO_BOTTOM_TOP       = 2,
  MATROSKA_VIDEO_STEREO_TOP_BOTTOM       = 3,
  MATROSKA_VIDEO_STEREO_CHECKBOARD_RL    = 4,
  MATROSKA_VIDEO_STEREO_CHECKBOARD_LR    = 5,
  MATROSKA_VIDEO_STEREO_ROW_INTERLEAVED_RL = 6,
  MATROSKA_VIDEO_STEREO_ROW_INTERLEAVED_LR = 7,
  MATROSKA_VIDEO_STEREO_COL_INTERLEAVED_RL = 8,
  MATROSKA_VIDEO_STEREO_COL_INTERLEAVED_LR = 9,
  MATROSKA_VIDEO_STEREO_ANAGLYPH_CYAN_RED = 10,
  MATROSKA_VIDEO_STEREO_RIGHT_LEFT       = 11,
  MATROSKA_VIDEO_STEREO_ANAGLYPH_GREEN_MAG = 12,
  MATROSKA_VIDEO_STEREO_BOTH_EYES_BLOCK_LR = 13,
  MATROSKA_VIDEO_STEREO_BOTH_EYES_BLOCK_RL = 14,
} MatroskaVideoStereoMode;

/**
 *Indicate whether the BlockAdditional Element with BlockAddID of "1" contains Alpha data, as defined by to the Codec Mapping for the `CodecID`.
Undefined values **SHOULD NOT** be used as the behavior of known implementations is different (considered either as 0 or 1).
 */
typedef enum {
  MATROSKA_VIDEO_ALPHAMODE_NONE             = 0, // The BlockAdditional Element with BlockAddID of "1" does not exist or **SHOULD NOT** be considered as containing such data.
  MATROSKA_VIDEO_ALPHAMODE_PRESENT          = 1, // The BlockAdditional Element with BlockAddID of "1" contains alpha channel data.
} MatroskaVideoAlphaMode;

/**
 *Bogus StereoMode value used in old versions of libmatroska.
 */
typedef enum {
  MATROSKA_VIDEO_OLDSTEREOMODE_MONO             = 0,
  MATROSKA_VIDEO_OLDSTEREOMODE_RIGHT_EYE        = 1,
  MATROSKA_VIDEO_OLDSTEREOMODE_LEFT_EYE         = 2,
  MATROSKA_VIDEO_OLDSTEREOMODE_BOTH_EYES        = 3,
} MatroskaVideoOldStereoMode;

/**
 *How DisplayWidth & DisplayHeight are interpreted.
 */
typedef enum {
  MATROSKA_DISPLAY_UNIT_PIXELS           = 0,
  MATROSKA_DISPLAY_UNIT_CENTIMETERS      = 1,
  MATROSKA_DISPLAY_UNIT_INCHES           = 2,
  MATROSKA_DISPLAY_UNIT_DISPLAYASPECTRATIO = 3,
  MATROSKA_DISPLAY_UNIT_UNKNOWN          = 4,
} MatroskaVideoDisplayUnit;

/**
 *Specify the possible modifications to the aspect ratio.
 */
typedef enum {
  MATROSKA_VIDEO_ASPECTRATIOTYPE_FREE_RESIZING    = 0,
  MATROSKA_VIDEO_ASPECTRATIOTYPE_KEEP_ASPECT_RATIO = 1,
  MATROSKA_VIDEO_ASPECTRATIOTYPE_FIXED            = 2,
} MatroskaVideoAspectRatioType;

/**
 *The Matrix Coefficients of the video used to derive luma and chroma values from red, green, and blue color primaries.
For clarity, the value and meanings for MatrixCoefficients are adopted from Table 4 of ISO/IEC 23001-8:2016 or ITU-T H.273.
 */
typedef enum {
  MATROSKA_VIDEO_MATRIXCOEFFICIENTS_IDENTITY         = 0,
  MATROSKA_VIDEO_MATRIXCOEFFICIENTS_BT709            = 1,
  MATROSKA_VIDEO_MATRIXCOEFFICIENTS_UNSPECIFIED      = 2,
  MATROSKA_VIDEO_MATRIXCOEFFICIENTS_RESERVED         = 3,
  MATROSKA_VIDEO_MATRIXCOEFFICIENTS_US_FCC_73_682    = 4,
  MATROSKA_VIDEO_MATRIXCOEFFICIENTS_BT470BG          = 5,
  MATROSKA_VIDEO_MATRIXCOEFFICIENTS_SMPTE_170M       = 6,
  MATROSKA_VIDEO_MATRIXCOEFFICIENTS_SMPTE_240M       = 7,
  MATROSKA_VIDEO_MATRIXCOEFFICIENTS_YCOCG            = 8,
  MATROSKA_VIDEO_MATRIXCOEFFICIENTS_BT2020_NCL       = 9,
  MATROSKA_VIDEO_MATRIXCOEFFICIENTS_BT2020_CL        = 10,
  MATROSKA_VIDEO_MATRIXCOEFFICIENTS_SMPTE_2085       = 11,
  MATROSKA_VIDEO_MATRIXCOEFFICIENTS_CHROMA_DERIVED_NCL = 12,
  MATROSKA_VIDEO_MATRIXCOEFFICIENTS_CHROMA_DERIVED_CL = 13,
  MATROSKA_VIDEO_MATRIXCOEFFICIENTS_ITU_R_BT_2100_0  = 14,
} MatroskaVideoMatrixCoefficients;

/**
 *How chroma is subsampled horizontally.
 */
typedef enum {
  MATROSKA_VIDEO_CHROMASITINGHORZ_UNSPECIFIED      = 0,
  MATROSKA_VIDEO_CHROMASITINGHORZ_LEFT             = 1,
  MATROSKA_VIDEO_CHROMASITINGHORZ_HALF             = 2,
} MatroskaColourChromaSitingHorz;

/**
 *How chroma is subsampled vertically.
 */
typedef enum {
  MATROSKA_VIDEO_CHROMASITINGVERT_UNSPECIFIED      = 0,
  MATROSKA_VIDEO_CHROMASITINGVERT_TOP              = 1,
  MATROSKA_VIDEO_CHROMASITINGVERT_HALF             = 2,
} MatroskaColourChromaSitingVert;

/**
 *Clipping of the color ranges.
 */
typedef enum {
  MATROSKA_VIDEO_RANGE_UNSPECIFIED      = 0,
  MATROSKA_VIDEO_RANGE_BROADCAST_RANGE  = 1,
  MATROSKA_VIDEO_RANGE_FULL_RANGE       = 2,
  MATROSKA_VIDEO_RANGE_DEFINED_BY_MATRIXCOEFFICIENTS = 3,
} MatroskaVideoRange;

/**
 *The transfer characteristics of the video. For clarity,
the value and meanings for TransferCharacteristics are adopted from Table 3 of ISO/IEC 23091-4 or ITU-T H.273.
 */
typedef enum {
  MATROSKA_TRANSFER_RESERVED         = 0,
  MATROSKA_TRANSFER_BT709            = 1,
  MATROSKA_TRANSFER_UNSPECIFIED      = 2,
  MATROSKA_TRANSFER_RESERVED2        = 3,
  MATROSKA_TRANSFER_GAMMA22          = 4,
  MATROSKA_TRANSFER_GAMMA28          = 5,
  MATROSKA_TRANSFER_SMPTE_170M       = 6,
  MATROSKA_TRANSFER_SMPTE_240M       = 7,
  MATROSKA_TRANSFER_LINEAR           = 8,
  MATROSKA_TRANSFER_LOG              = 9,
  MATROSKA_TRANSFER_LOG_SQRT         = 10,
  MATROSKA_TRANSFER_IEC_61966_2_4    = 11,
  MATROSKA_TRANSFER_BT1361_ECG       = 12,
  MATROSKA_TRANSFER_IEC_61966_2_1    = 13,
  MATROSKA_TRANSFER_BT2020_10_BIT    = 14,
  MATROSKA_TRANSFER_BT2020_12_BIT    = 15,
  MATROSKA_TRANSFER_BT2100_PQ        = 16,
  MATROSKA_TRANSFER_SMPTE_428_1      = 17,
  MATROSKA_TRANSFER_ARIB_STD_B67     = 18,
} MatroskaVideoTransferCharacteristics;

/**
 *The colour primaries of the video. For clarity,
the value and meanings for Primaries are adopted from Table 2 of ISO/IEC 23091-4 or ITU-T H.273.
 */
typedef enum {
  MATROSKA_VIDEO_PRIMARIES_RESERVED         = 0,
  MATROSKA_VIDEO_PRIMARIES_BT709            = 1,
  MATROSKA_VIDEO_PRIMARIES_UNSPECIFIED      = 2,
  MATROSKA_VIDEO_PRIMARIES_RESERVED2        = 3,
  MATROSKA_VIDEO_PRIMARIES_BT470M           = 4,
  MATROSKA_VIDEO_PRIMARIES_BT470BG          = 5,
  MATROSKA_VIDEO_PRIMARIES_BT601_525        = 6,
  MATROSKA_VIDEO_PRIMARIES_SMPTE_240M       = 7,
  MATROSKA_VIDEO_PRIMARIES_FILM             = 8,
  MATROSKA_VIDEO_PRIMARIES_BT2020           = 9,
  MATROSKA_VIDEO_PRIMARIES_SMPTE_428_1      = 10,
  MATROSKA_VIDEO_PRIMARIES_SMPTE_RP_432_2   = 11,
  MATROSKA_VIDEO_PRIMARIES_SMPTE_EG_432_2   = 12,
  MATROSKA_VIDEO_PRIMARIES_JEDEC_P22        = 22,
} MatroskaVideoPrimaries;

/**
 *Describes the projection used for this video track.
 */
typedef enum {
  MATROSKA_VIDEO_PROJECTIONTYPE_RECTANGULAR      = 0,
  MATROSKA_VIDEO_PROJECTIONTYPE_EQUIRECTANGULAR  = 1,
  MATROSKA_VIDEO_PROJECTIONTYPE_CUBEMAP          = 2,
  MATROSKA_VIDEO_PROJECTIONTYPE_MESH             = 3,
} MatroskaVideoProjectionType;

/**
 *Audio emphasis applied on audio samples. The player **MUST** apply the inverse emphasis to get the proper audio samples.
 */
typedef enum {
  MATROSKA_EMPHASIS_NO_EMPHASIS      = 0,
  MATROSKA_EMPHASIS_CD_AUDIO         = 1, // First order filter with zero point at 50 microseconds and a pole at 15 microseconds. Also found on DVD Audio and MPEG audio.
  MATROSKA_EMPHASIS_RESERVED         = 2,
  MATROSKA_EMPHASIS_CCIT_J_17        = 3, // Defined in [@!ITU-J.17].
  MATROSKA_EMPHASIS_FM_50            = 4, // FM Radio in Europe. RC Filter with a time constant of 50 microseconds.
  MATROSKA_EMPHASIS_FM_75            = 5, // FM Radio in the USA. RC Filter with a time constant of 75 microseconds.
  MATROSKA_EMPHASIS_PHONO_RIAA       = 10, // Phono filter with time constants of t1=3180, t2=318 and t3=75 microseconds. [@!NAB1964]
  MATROSKA_EMPHASIS_PHONO_IEC_N78    = 11, // Phono filter with time constants of t1=3180, t2=450 and t3=50 microseconds.
  MATROSKA_EMPHASIS_PHONO_TELDEC     = 12, // Phono filter with time constants of t1=3180, t2=318 and t3=50 microseconds.
  MATROSKA_EMPHASIS_PHONO_EMI        = 13, // Phono filter with time constants of t1=2500, t2=500 and t3=70 microseconds.
  MATROSKA_EMPHASIS_PHONO_COLUMBIA_LP = 14, // Phono filter with time constants of t1=1590, t2=318 and t3=100 microseconds.
  MATROSKA_EMPHASIS_PHONO_LONDON     = 15, // Phono filter with time constants of t1=1590, t2=318 and t3=50 microseconds.
  MATROSKA_EMPHASIS_PHONO_NARTB      = 16, // Phono filter with time constants of t1=3180, t2=318 and t3=100 microseconds.
} MatroskaAudioEmphasis;

/**
 *The kind of plane this track corresponds to.
 */
typedef enum {
  MATROSKA_TRACKPLANETYPE_LEFT_EYE         = 0,
  MATROSKA_TRACKPLANETYPE_RIGHT_EYE        = 1,
  MATROSKA_TRACKPLANETYPE_BACKGROUND       = 2,
} MatroskaTrackPlaneType;

/**
 *A bit field that describes which Elements have been modified in this way.
Values (big-endian) can be OR'ed.
 */
typedef enum {
  MATROSKA_CONTENTENCODINGSCOPE_BLOCK            = 1, // All frame contents, excluding lacing data.
  MATROSKA_CONTENTENCODINGSCOPE_PRIVATE          = 2, // The track's private data.
  MATROSKA_CONTENTENCODINGSCOPE_NEXT             = 4, // The next ContentEncoding (next `ContentEncodingOrder`. Either the data inside `ContentCompression` and/or `ContentEncryption`).
} MatroskaContentEncodingScope;

/**
 *A value describing what kind of transformation is applied.
 */
typedef enum {
  MATROSKA_CONTENTENCODINGTYPE_COMPRESSION      = 0,
  MATROSKA_CONTENTENCODINGTYPE_ENCRYPTION       = 1,
} MatroskaContentEncodingType;

/**
 *The encryption algorithm used.
 */
typedef enum {
  MATROSKA_CONTENTENCALGO_NOT_ENCRYPTED    = 0, // The data are not encrypted.
  MATROSKA_CONTENTENCALGO_DES              = 1, // Data Encryption Standard (DES) [@!FIPS.46-3].
  MATROSKA_CONTENTENCALGO_3DES             = 2, // Triple Data Encryption Algorithm [@!SP.800-67].
  MATROSKA_CONTENTENCALGO_TWOFISH          = 3, // Twofish Encryption Algorithm [@!Twofish].
  MATROSKA_CONTENTENCALGO_BLOWFISH         = 4, // Blowfish Encryption Algorithm [@!Blowfish].
  MATROSKA_CONTENTENCALGO_AES              = 5, // Advanced Encryption Standard (AES) [@!FIPS.197].
} MatroskaContentEncodingAlgo;

/**
 *The AES cipher mode used in the encryption.
 */
typedef enum {
  MATROSKA_AESSETTINGSCIPHERMODE_AES_CTR          = 1, // Counter [@!SP.800-38A].
  MATROSKA_AESSETTINGSCIPHERMODE_AES_CBC          = 2, // Cipher Block Chaining [@!SP.800-38A].
} MatroskaAESSettingsCipherMode;

/**
 *The algorithm used for the signature.
 */
typedef enum {
  MATROSKA_CONTENTSIGALGO_NOT_SIGNED       = 0,
  MATROSKA_CONTENTSIGALGO_RSA              = 1,
} MatroskaContentSignatureAlgo;

/**
 *The hash algorithm used for the signature.
 */
typedef enum {
  MATROSKA_CONTENTSIGHASHALGO_NOT_SIGNED       = 0,
  MATROSKA_CONTENTSIGHASHALGO_SHA1_160         = 1,
  MATROSKA_CONTENTSIGHASHALGO_MD5              = 2,
} MatroskaContentSigHashAlgo;

/**
 *Indicate what type of content the ChapterAtom contains and might be skipped. It can be used to automatically skip content based on the type.
If a `ChapterAtom` is inside a `ChapterAtom` that has a `ChapterSkipType` set, it **MUST NOT** have a `ChapterSkipType` or have a `ChapterSkipType` with the same value as it's parent `ChapterAtom`.
If the `ChapterAtom` doesn't contain a `ChapterTimeEnd`, the value of the `ChapterSkipType` is only valid until the next `ChapterAtom` with a `ChapterSkipType` value or the end of the file.
    
 */
typedef enum {
  MATROSKA_CHAPTERSKIPTYPE_NO_SKIPPING      = 0, // Content which should not be skipped.
  MATROSKA_CHAPTERSKIPTYPE_OPENING_CREDITS  = 1, // Credits usually found at the beginning of the content.
  MATROSKA_CHAPTERSKIPTYPE_END_CREDITS      = 2, // Credits usually found at the end of the content.
  MATROSKA_CHAPTERSKIPTYPE_RECAP            = 3, // Recap of previous episodes of the content, usually found around the beginning.
  MATROSKA_CHAPTERSKIPTYPE_NEXT_PREVIEW     = 4, // Preview of the next episode of the content, usually found around the end. It may contain spoilers the user wants to avoid.
  MATROSKA_CHAPTERSKIPTYPE_PREVIEW          = 5, // Preview of the current episode of the content, usually found around the beginning. It may contain spoilers the user want to avoid.
  MATROSKA_CHAPTERSKIPTYPE_ADVERTISEMENT    = 6, // Advertisement within the content.
} MatroskaChapterSkipType;

/**
 *Defines when the process command **SHOULD** be handled
 */
typedef enum {
  MATROSKA_CHAPPROCESSTIME_DURING           = 0,
  MATROSKA_CHAPPROCESSTIME_BEFORE           = 1,
  MATROSKA_CHAPPROCESSTIME_AFTER            = 2,
} MatroskaChapterProcessTime;

/**
 *A number to indicate the logical level of the target.
 */
typedef enum {
  MATROSKA_TARGET_TYPE_COLLECTION       = 70, // The highest hierarchical level that tags can describe.
  MATROSKA_TARGET_TYPE_EDITION          = 60, // A list of lower levels grouped together.
  MATROSKA_TARGET_TYPE_ALBUM            = 50, // The most common grouping level of music and video (equals to an episode for TV series).
  MATROSKA_TARGET_TYPE_PART             = 40, // When an album or episode has different logical parts.
  MATROSKA_TARGET_TYPE_TRACK            = 30, // The common parts of an album or movie.
  MATROSKA_TARGET_TYPE_SUBTRACK         = 20, // Corresponds to parts of a track for audio (like a movement).
  MATROSKA_TARGET_TYPE_SHOT             = 10, // The lowest hierarchy found in music or movies.
} MatroskaTargetTypeValue;


} // namespace libmatroska

#endif // LIBMATROSKA_SEMANTIC_H
