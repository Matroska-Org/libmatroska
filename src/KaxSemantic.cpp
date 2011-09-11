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
** Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
**
** See http://www.matroska.org/license/lgpl/ for LGPL licensing information.**
** Contact license@matroska.org if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

#include "matroska/KaxContexts.h"
#include "matroska/KaxSemantic.h"
#include "matroska/KaxSegment.h"
#include "matroska/KaxSeekHead.h"
#include "matroska/KaxCluster.h"
#include "matroska/KaxTracks.h"
#include "matroska/KaxCues.h"
#include "matroska/KaxInfoData.h"
#include "matroska/KaxBlockData.h"
#include "matroska/KaxCuesData.h"

START_LIBMATROSKA_NAMESPACE

DEFINE_START_SEMANTIC(KaxSegment)
DEFINE_SEMANTIC_ITEM(false, false, KaxSeekHead)
DEFINE_SEMANTIC_ITEM(true, false, KaxInfo)
DEFINE_SEMANTIC_ITEM(false, false, KaxCluster)
DEFINE_SEMANTIC_ITEM(false, false, KaxTracks)
DEFINE_SEMANTIC_ITEM(false, true, KaxCues)
DEFINE_SEMANTIC_ITEM(false, true, KaxAttachments)
DEFINE_SEMANTIC_ITEM(false, true, KaxChapters)
DEFINE_SEMANTIC_ITEM(false, false, KaxTags)
DEFINE_END_SEMANTIC(KaxSegment)

DEFINE_MKX_MASTER_ORPHAN(KaxSegment, 0x18538067, 4, "Segment");

DEFINE_START_SEMANTIC(KaxSeekHead)
DEFINE_SEMANTIC_ITEM(true, false, KaxSeek)
DEFINE_END_SEMANTIC(KaxSeekHead)

DEFINE_MKX_MASTER(KaxSeekHead, 0x114D9B74, 4, KaxSegment, "SeekHeader");

DEFINE_START_SEMANTIC(KaxSeek)
DEFINE_SEMANTIC_ITEM(true, true, KaxSeekID)
DEFINE_SEMANTIC_ITEM(true, true, KaxSeekPosition)
DEFINE_END_SEMANTIC(KaxSeek)

DEFINE_MKX_MASTER(KaxSeek, 0x4DBB, 2, KaxSeekHead, "SeekPoint");
DEFINE_MKX_BINARY (KaxSeekID, 0x53AB, 2, KaxSeek, "SeekID");
DEFINE_MKX_UINTEGER(KaxSeekPosition, 0x53AC, 2, KaxSeek, "SeekPosition");

DEFINE_START_SEMANTIC(KaxInfo)
DEFINE_SEMANTIC_ITEM(false, true, KaxSegmentUID)
DEFINE_SEMANTIC_ITEM(false, true, KaxSegmentFilename)
DEFINE_SEMANTIC_ITEM(false, true, KaxPrevUID)
DEFINE_SEMANTIC_ITEM(false, true, KaxPrevFilename)
DEFINE_SEMANTIC_ITEM(false, true, KaxNextUID)
DEFINE_SEMANTIC_ITEM(false, true, KaxNextFilename)
DEFINE_SEMANTIC_ITEM(false, false, KaxSegmentFamily)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapterTranslate)
DEFINE_SEMANTIC_ITEM(true, true, KaxTimecodeScale)
DEFINE_SEMANTIC_ITEM(false, true, KaxDuration)
DEFINE_SEMANTIC_ITEM(false, true, KaxDateUTC)
DEFINE_SEMANTIC_ITEM(false, true, KaxTitle)
DEFINE_SEMANTIC_ITEM(true, true, KaxMuxingApp)
DEFINE_SEMANTIC_ITEM(true, true, KaxWritingApp)
DEFINE_END_SEMANTIC(KaxInfo)

DEFINE_MKX_MASTER(KaxInfo, 0x1549A966, 4, KaxSegment, "Info");
DEFINE_MKX_BINARY (KaxSegmentUID, 0x73A4, 2, KaxInfo, "SegmentUID");
DEFINE_MKX_UNISTRING(KaxSegmentFilename, 0x7384, 2, KaxInfo, "SegmentFilename");
DEFINE_MKX_BINARY_CONS(KaxPrevUID, 0x3CB923, 3, KaxInfo, "PrevUID");
DEFINE_MKX_UNISTRING(KaxPrevFilename, 0x3C83AB, 3, KaxInfo, "PrevFilename");
DEFINE_MKX_BINARY_CONS(KaxNextUID, 0x3EB923, 3, KaxInfo, "NextUID");
DEFINE_MKX_UNISTRING(KaxNextFilename, 0x3E83BB, 3, KaxInfo, "NextFilename");
DEFINE_MKX_BINARY (KaxSegmentFamily, 0x4444, 2, KaxInfo, "SegmentFamily");

DEFINE_START_SEMANTIC(KaxChapterTranslate)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapterTranslateEditionUID)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterTranslateCodec)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterTranslateID)
DEFINE_END_SEMANTIC(KaxChapterTranslate)

DEFINE_MKX_MASTER(KaxChapterTranslate, 0x6924, 2, KaxInfo, "ChapterTranslate");
DEFINE_MKX_UINTEGER(KaxChapterTranslateEditionUID, 0x69FC, 2, KaxChapterTranslate, "ChapterTranslateEditionUID");
DEFINE_MKX_UINTEGER(KaxChapterTranslateCodec, 0x69BF, 2, KaxChapterTranslate, "ChapterTranslateCodec");
DEFINE_MKX_BINARY (KaxChapterTranslateID, 0x69A5, 2, KaxChapterTranslate, "ChapterTranslateID");
DEFINE_MKX_UINTEGER_DEF(KaxTimecodeScale, 0x2AD7B1, 3, KaxInfo, "TimecodeScale", 1000000);
DEFINE_MKX_FLOAT(KaxDuration, 0x4489, 2, KaxInfo, "Duration");
DEFINE_MKX_DATE    (KaxDateUTC, 0x4461, 2, KaxInfo, "DateUTC");
DEFINE_MKX_UNISTRING(KaxTitle, 0x7BA9, 2, KaxInfo, "Title");
DEFINE_MKX_UNISTRING(KaxMuxingApp, 0x4D80, 2, KaxInfo, "MuxingApp");
DEFINE_MKX_UNISTRING(KaxWritingApp, 0x5741, 2, KaxInfo, "WritingApp");

DEFINE_START_SEMANTIC(KaxCluster)
DEFINE_SEMANTIC_ITEM(true, true, KaxClusterTimecode)
DEFINE_SEMANTIC_ITEM(false, true, KaxClusterSilentTracks)
DEFINE_SEMANTIC_ITEM(false, true, KaxClusterPosition)
DEFINE_SEMANTIC_ITEM(false, true, KaxClusterPrevSize)
#if MATROSKA_VERSION >= 2
DEFINE_SEMANTIC_ITEM(false, false, KaxSimpleBlock)
#endif // MATROSKA_VERSION
DEFINE_SEMANTIC_ITEM(false, false, KaxBlockGroup)
#if MATROSKA_VERSION >= 2
DEFINE_SEMANTIC_ITEM(false, false, KaxEncryptedBlock) // not supported
#endif // MATROSKA_VERSION
DEFINE_END_SEMANTIC(KaxCluster)

DEFINE_MKX_MASTER_CONS(KaxCluster, 0x1F43B675, 4, KaxSegment, "Cluster");
DEFINE_MKX_UINTEGER(KaxClusterTimecode, 0xE7, 1, KaxCluster, "ClusterTimecode");

DEFINE_START_SEMANTIC(KaxClusterSilentTracks)
DEFINE_SEMANTIC_ITEM(false, false, KaxClusterSilentTrackNumber)
DEFINE_END_SEMANTIC(KaxClusterSilentTracks)

DEFINE_MKX_MASTER(KaxClusterSilentTracks, 0x5854, 2, KaxCluster, "ClusterSilentTracks");
DEFINE_MKX_UINTEGER(KaxClusterSilentTrackNumber, 0x58D7, 2, KaxClusterSilentTracks, "ClusterSilentTrackNumber");
DEFINE_MKX_UINTEGER(KaxClusterPosition, 0xA7, 1, KaxCluster, "ClusterPosition");
DEFINE_MKX_UINTEGER(KaxClusterPrevSize, 0xAB, 1, KaxCluster, "ClusterPrevSize");
#if MATROSKA_VERSION >= 2
DEFINE_MKX_BINARY_CONS(KaxSimpleBlock, 0xA3, 1, KaxCluster, "SimpleBlock");
#endif

DEFINE_START_SEMANTIC(KaxBlockGroup)
DEFINE_SEMANTIC_ITEM(true, true, KaxBlock)
#if MATROSKA_VERSION >= 2
DEFINE_SEMANTIC_ITEM(false, true, KaxBlockVirtual) // not supported
#endif // MATROSKA_VERSION
DEFINE_SEMANTIC_ITEM(false, true, KaxBlockAdditions)
DEFINE_SEMANTIC_ITEM(false, true, KaxBlockDuration)
DEFINE_SEMANTIC_ITEM(true, true, KaxReferencePriority)
DEFINE_SEMANTIC_ITEM(false, false, KaxReferenceBlock)
#if MATROSKA_VERSION >= 2
DEFINE_SEMANTIC_ITEM(false, true, KaxReferenceVirtual) // not supported
DEFINE_SEMANTIC_ITEM(false, true, KaxCodecState)
#endif // MATROSKA_VERSION
DEFINE_SEMANTIC_ITEM(false, true, KaxSlices)
#if MATROSKA_VERSION >= 2
DEFINE_SEMANTIC_ITEM(false, true, KaxReferenceFrame) // DivX specific
#endif // MATROSKA_VERSION
DEFINE_END_SEMANTIC(KaxBlockGroup)

DEFINE_MKX_MASTER_CONS(KaxBlockGroup, 0xA0, 1, KaxCluster, "BlockGroup");
DEFINE_MKX_BINARY_CONS(KaxBlock, 0xA1, 1, KaxBlockGroup, "Block");
#if MATROSKA_VERSION >= 2
DEFINE_MKX_BINARY_CONS(KaxBlockVirtual, 0xA2, 1, KaxBlockGroup, "BlockVirtual");
#endif

DEFINE_START_SEMANTIC(KaxBlockAdditions)
DEFINE_SEMANTIC_ITEM(true, false, KaxBlockMore)
DEFINE_END_SEMANTIC(KaxBlockAdditions)

DEFINE_MKX_MASTER(KaxBlockAdditions, 0x75A1, 2, KaxBlockGroup, "BlockAdditions");

DEFINE_START_SEMANTIC(KaxBlockMore)
DEFINE_SEMANTIC_ITEM(true, true, KaxBlockAddID)
DEFINE_SEMANTIC_ITEM(true, true, KaxBlockAdditional)
DEFINE_END_SEMANTIC(KaxBlockMore)

DEFINE_MKX_MASTER(KaxBlockMore, 0xA6, 1, KaxBlockAdditions, "BlockMore");
DEFINE_MKX_UINTEGER_DEF(KaxBlockAddID, 0xEE, 1, KaxBlockMore, "BlockAddID", 1);
DEFINE_MKX_BINARY (KaxBlockAdditional, 0xA5, 1, KaxBlockMore, "BlockAdditional");
DEFINE_MKX_UINTEGER(KaxBlockDuration, 0x9B, 1, KaxBlockGroup, "BlockDuration");
DEFINE_MKX_UINTEGER_DEF(KaxReferencePriority, 0xFA, 1, KaxBlockGroup, "FlagReferenced", 0);
DEFINE_MKX_SINTEGER_CONS(KaxReferenceBlock, 0xFB, 1, KaxBlockGroup, "ReferenceBlock");
#if MATROSKA_VERSION >= 2
DEFINE_MKX_SINTEGER(KaxReferenceVirtual, 0xFD, 1, KaxBlockGroup, "ReferenceVirtual");
DEFINE_MKX_BINARY (KaxCodecState, 0xA4, 1, KaxBlockGroup, "CodecState");
#endif

DEFINE_START_SEMANTIC(KaxSlices)
DEFINE_SEMANTIC_ITEM(false, false, KaxTimeSlice)
DEFINE_END_SEMANTIC(KaxSlices)

DEFINE_MKX_MASTER(KaxSlices, 0x8E, 1, KaxBlockGroup, "Slices");

DEFINE_START_SEMANTIC(KaxTimeSlice)
DEFINE_SEMANTIC_ITEM(false, true, KaxSliceLaceNumber)
#if MATROSKA_VERSION >= 2
DEFINE_SEMANTIC_ITEM(false, true, KaxSliceFrameNumber) // not supported
DEFINE_SEMANTIC_ITEM(false, true, KaxSliceBlockAddID) // not supported
DEFINE_SEMANTIC_ITEM(false, true, KaxSliceDelay) // not supported
DEFINE_SEMANTIC_ITEM(false, true, KaxSliceDuration) // not supported
#endif // MATROSKA_VERSION
DEFINE_END_SEMANTIC(KaxTimeSlice)

DEFINE_MKX_MASTER(KaxTimeSlice, 0xE8, 1, KaxSlices, "TimeSlice");
DEFINE_MKX_UINTEGER_DEF(KaxSliceLaceNumber, 0xCC, 1, KaxTimeSlice, "SliceLaceNumber", 0);
#if MATROSKA_VERSION >= 2
DEFINE_MKX_UINTEGER_DEF(KaxSliceFrameNumber, 0xCD, 1, KaxTimeSlice, "SliceFrameNumber", 0);
DEFINE_MKX_UINTEGER_DEF(KaxSliceBlockAddID, 0xCB, 1, KaxTimeSlice, "SliceBlockAddID", 0);
DEFINE_MKX_UINTEGER_DEF(KaxSliceDelay, 0xCE, 1, KaxTimeSlice, "SliceDelay", 0);
DEFINE_MKX_UINTEGER_DEF(KaxSliceDuration, 0xCF, 1, KaxTimeSlice, "SliceDuration", 0);

DEFINE_START_SEMANTIC(KaxReferenceFrame)
DEFINE_SEMANTIC_ITEM(true, true, KaxReferenceOffset) // DivX specific
DEFINE_SEMANTIC_ITEM(true, true, KaxReferenceTimeCode) // DivX specific
DEFINE_END_SEMANTIC(KaxReferenceFrame)

DEFINE_MKX_MASTER(KaxReferenceFrame, 0xC8, 1, KaxBlockGroup, "ReferenceFrame");
DEFINE_MKX_UINTEGER(KaxReferenceOffset, 0xC9, 1, KaxReferenceFrame, "ReferenceOffset");
DEFINE_MKX_UINTEGER(KaxReferenceTimeCode, 0xCA, 1, KaxReferenceFrame, "ReferenceTimeCode");
DEFINE_MKX_BINARY (KaxEncryptedBlock, 0xAF, 1, KaxCluster, "EncryptedBlock");
#endif

DEFINE_START_SEMANTIC(KaxTracks)
DEFINE_SEMANTIC_ITEM(true, false, KaxTrackEntry)
DEFINE_END_SEMANTIC(KaxTracks)

DEFINE_MKX_MASTER(KaxTracks, 0x1654AE6B, 4, KaxSegment, "Tracks");

DEFINE_START_SEMANTIC(KaxTrackEntry)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackNumber)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackUID)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackType)
#if MATROSKA_VERSION >= 2
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackFlagEnabled)
#endif // MATROSKA_VERSION
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackFlagDefault)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackFlagForced)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackFlagLacing)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackMinCache)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackMaxCache)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackDefaultDuration)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackTimecodeScale)
#if MATROSKA_VERSION >= 2
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackOffset) // not supported
#endif // MATROSKA_VERSION
DEFINE_SEMANTIC_ITEM(true, true, KaxMaxBlockAdditionID)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackName)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackLanguage)
DEFINE_SEMANTIC_ITEM(true, true, KaxCodecID)
DEFINE_SEMANTIC_ITEM(false, true, KaxCodecPrivate)
DEFINE_SEMANTIC_ITEM(false, true, KaxCodecName)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackAttachmentLink)
#if MATROSKA_VERSION >= 2
DEFINE_SEMANTIC_ITEM(false, true, KaxCodecSettings) // not supported
DEFINE_SEMANTIC_ITEM(false, false, KaxCodecInfoURL) // not supported
DEFINE_SEMANTIC_ITEM(false, false, KaxCodecDownloadURL) // not supported
DEFINE_SEMANTIC_ITEM(true, true, KaxCodecDecodeAll)
#endif // MATROSKA_VERSION
DEFINE_SEMANTIC_ITEM(false, false, KaxTrackOverlay)
DEFINE_SEMANTIC_ITEM(false, false, KaxTrackTranslate)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackVideo)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackAudio)
#if MATROSKA_VERSION >= 2
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackOperation)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrickTrackUID) // DivX specific
DEFINE_SEMANTIC_ITEM(false, true, KaxTrickTrackSegmentUID) // DivX specific
DEFINE_SEMANTIC_ITEM(false, true, KaxTrickTrackFlag) // DivX specific
DEFINE_SEMANTIC_ITEM(false, true, KaxTrickMasterTrackUID) // DivX specific
DEFINE_SEMANTIC_ITEM(false, true, KaxTrickMasterTrackSegmentUID) // DivX specific
#endif // MATROSKA_VERSION
DEFINE_SEMANTIC_ITEM(false, true, KaxContentEncodings)
DEFINE_END_SEMANTIC(KaxTrackEntry)

DEFINE_MKX_MASTER_CONS(KaxTrackEntry, 0xAE, 1, KaxTracks, "TrackEntry");
DEFINE_MKX_UINTEGER(KaxTrackNumber, 0xD7, 1, KaxTrackEntry, "TrackNumber");
DEFINE_MKX_UINTEGER(KaxTrackUID, 0x73C5, 2, KaxTrackEntry, "TrackUID");
DEFINE_MKX_UINTEGER(KaxTrackType, 0x83, 1, KaxTrackEntry, "TrackType");
#if MATROSKA_VERSION >= 2
DEFINE_MKX_UINTEGER_DEF(KaxTrackFlagEnabled, 0xB9, 1, KaxTrackEntry, "TrackFlagEnabled", 1);
#endif
DEFINE_MKX_UINTEGER_DEF(KaxTrackFlagDefault, 0x88, 1, KaxTrackEntry, "TrackFlagDefault", 1);
DEFINE_MKX_UINTEGER_DEF(KaxTrackFlagForced, 0x55AA, 2, KaxTrackEntry, "TrackFlagForced", 0);
DEFINE_MKX_UINTEGER_DEF(KaxTrackFlagLacing, 0x9C, 1, KaxTrackEntry, "TrackFlagLacing", 1);
DEFINE_MKX_UINTEGER_DEF(KaxTrackMinCache, 0x6DE7, 2, KaxTrackEntry, "TrackMinCache", 0);
DEFINE_MKX_UINTEGER(KaxTrackMaxCache, 0x6DF8, 2, KaxTrackEntry, "TrackMaxCache");
DEFINE_MKX_UINTEGER(KaxTrackDefaultDuration, 0x23E383, 3, KaxTrackEntry, "TrackDefaultDuration");
DEFINE_MKX_FLOAT_DEF(KaxTrackTimecodeScale, 0x23314F, 3, KaxTrackEntry, "TrackTimecodeScale", 1);
#if MATROSKA_VERSION >= 2
DEFINE_MKX_SINTEGER_DEF(KaxTrackOffset, 0x537F, 2, KaxTrackEntry, "TrackOffset", 0);
#endif
DEFINE_MKX_UINTEGER_DEF(KaxMaxBlockAdditionID, 0x55EE, 2, KaxTrackEntry, "MaxBlockAdditionID", 0);
DEFINE_MKX_UNISTRING(KaxTrackName, 0x536E, 2, KaxTrackEntry, "TrackName");
DEFINE_MKX_STRING_DEF(KaxTrackLanguage, 0x22B59C, 3, KaxTrackEntry, "TrackLanguage", "eng");
DEFINE_MKX_STRING(KaxCodecID, 0x86, 1, KaxTrackEntry, "CodecID");
DEFINE_MKX_BINARY (KaxCodecPrivate, 0x63A2, 2, KaxTrackEntry, "CodecPrivate");
DEFINE_MKX_UNISTRING(KaxCodecName, 0x258688, 3, KaxTrackEntry, "CodecName");
DEFINE_MKX_UINTEGER(KaxTrackAttachmentLink, 0x7446, 2, KaxTrackEntry, "TrackAttachmentLink");
#if MATROSKA_VERSION >= 2
DEFINE_MKX_UNISTRING(KaxCodecSettings, 0x3A9697, 3, KaxTrackEntry, "CodecSettings");
DEFINE_MKX_STRING(KaxCodecInfoURL, 0x3B4040, 3, KaxTrackEntry, "CodecInfoURL");
DEFINE_MKX_STRING(KaxCodecDownloadURL, 0x26B240, 3, KaxTrackEntry, "CodecDownloadURL");
DEFINE_MKX_UINTEGER_DEF(KaxCodecDecodeAll, 0xAA, 1, KaxTrackEntry, "CodecDecodeAll", 1);
#endif
DEFINE_MKX_UINTEGER(KaxTrackOverlay, 0x6FAB, 2, KaxTrackEntry, "TrackOverlay");

DEFINE_START_SEMANTIC(KaxTrackTranslate)
DEFINE_SEMANTIC_ITEM(false, false, KaxTrackTranslateEditionUID)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackTranslateCodec)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackTranslateTrackID)
DEFINE_END_SEMANTIC(KaxTrackTranslate)

DEFINE_MKX_MASTER(KaxTrackTranslate, 0x6624, 2, KaxTrackEntry, "TrackTranslate");
DEFINE_MKX_UINTEGER(KaxTrackTranslateEditionUID, 0x66FC, 2, KaxTrackTranslate, "TrackTranslateEditionUID");
DEFINE_MKX_UINTEGER(KaxTrackTranslateCodec, 0x66BF, 2, KaxTrackTranslate, "TrackTranslateCodec");
DEFINE_MKX_BINARY (KaxTrackTranslateTrackID, 0x66A5, 2, KaxTrackTranslate, "TrackTranslateTrackID");

DEFINE_START_SEMANTIC(KaxTrackVideo)
#if MATROSKA_VERSION >= 2
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoFlagInterlaced)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoStereoMode)
DEFINE_SEMANTIC_ITEM(false, true, KaxOldStereoMode) // not supported
#endif // MATROSKA_VERSION
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoPixelWidth)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoPixelHeight)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoPixelCropBottom)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoPixelCropTop)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoPixelCropLeft)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoPixelCropRight)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoDisplayWidth)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoDisplayHeight)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoDisplayUnit)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoAspectRatio)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoColourSpace)
#if MATROSKA_VERSION >= 2
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoGamma) // not supported
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoFrameRate) // not supported
#endif // MATROSKA_VERSION
DEFINE_END_SEMANTIC(KaxTrackVideo)

DEFINE_MKX_MASTER(KaxTrackVideo, 0xE0, 1, KaxTrackEntry, "TrackVideo");
#if MATROSKA_VERSION >= 2
DEFINE_MKX_UINTEGER_DEF(KaxVideoFlagInterlaced, 0x9A, 1, KaxTrackVideo, "VideoFlagInterlaced", 0);
DEFINE_MKX_UINTEGER_DEF(KaxVideoStereoMode, 0x53B8, 2, KaxTrackVideo, "VideoStereoMode", 0);
DEFINE_MKX_UINTEGER(KaxOldStereoMode, 0x53B9, 2, KaxTrackVideo, "OldStereoMode");
#endif
DEFINE_MKX_UINTEGER(KaxVideoPixelWidth, 0xB0, 1, KaxTrackVideo, "VideoPixelWidth");
DEFINE_MKX_UINTEGER(KaxVideoPixelHeight, 0xBA, 1, KaxTrackVideo, "VideoPixelHeight");
DEFINE_MKX_UINTEGER_DEF(KaxVideoPixelCropBottom, 0x54AA, 2, KaxTrackVideo, "VideoPixelCropBottom", 0);
DEFINE_MKX_UINTEGER_DEF(KaxVideoPixelCropTop, 0x54BB, 2, KaxTrackVideo, "VideoPixelCropTop", 0);
DEFINE_MKX_UINTEGER_DEF(KaxVideoPixelCropLeft, 0x54CC, 2, KaxTrackVideo, "VideoPixelCropLeft", 0);
DEFINE_MKX_UINTEGER_DEF(KaxVideoPixelCropRight, 0x54DD, 2, KaxTrackVideo, "VideoPixelCropRight", 0);
DEFINE_MKX_UINTEGER(KaxVideoDisplayWidth, 0x54B0, 2, KaxTrackVideo, "VideoDisplayWidth");
DEFINE_MKX_UINTEGER(KaxVideoDisplayHeight, 0x54BA, 2, KaxTrackVideo, "VideoDisplayHeight");
DEFINE_MKX_UINTEGER_DEF(KaxVideoDisplayUnit, 0x54B2, 2, KaxTrackVideo, "VideoDisplayUnit", 0);
DEFINE_MKX_UINTEGER_DEF(KaxVideoAspectRatio, 0x54B3, 2, KaxTrackVideo, "VideoAspectRatio", 0);
DEFINE_MKX_BINARY (KaxVideoColourSpace, 0x2EB524, 3, KaxTrackVideo, "VideoColourSpace");
#if MATROSKA_VERSION >= 2
DEFINE_MKX_FLOAT(KaxVideoGamma, 0x2FB523, 3, KaxTrackVideo, "VideoGamma");
DEFINE_MKX_FLOAT(KaxVideoFrameRate, 0x2383E3, 3, KaxTrackVideo, "VideoFrameRate");
#endif

DEFINE_START_SEMANTIC(KaxTrackAudio)
DEFINE_SEMANTIC_ITEM(true, true, KaxAudioSamplingFreq)
DEFINE_SEMANTIC_ITEM(false, true, KaxAudioOutputSamplingFreq)
DEFINE_SEMANTIC_ITEM(true, true, KaxAudioChannels)
#if MATROSKA_VERSION >= 2
DEFINE_SEMANTIC_ITEM(false, true, KaxAudioPosition) // not supported
#endif // MATROSKA_VERSION
DEFINE_SEMANTIC_ITEM(false, true, KaxAudioBitDepth)
DEFINE_END_SEMANTIC(KaxTrackAudio)

DEFINE_MKX_MASTER(KaxTrackAudio, 0xE1, 1, KaxTrackEntry, "TrackAudio");
DEFINE_MKX_FLOAT_DEF(KaxAudioSamplingFreq, 0xB5, 1, KaxTrackAudio, "AudioSamplingFreq", 8000);
DEFINE_MKX_FLOAT(KaxAudioOutputSamplingFreq, 0x78B5, 2, KaxTrackAudio, "AudioOutputSamplingFreq");
DEFINE_MKX_UINTEGER_DEF(KaxAudioChannels, 0x9F, 1, KaxTrackAudio, "AudioChannels", 1);
#if MATROSKA_VERSION >= 2
DEFINE_MKX_BINARY (KaxAudioPosition, 0x7D7B, 2, KaxTrackAudio, "AudioPosition");
#endif
DEFINE_MKX_UINTEGER(KaxAudioBitDepth, 0x6264, 2, KaxTrackAudio, "AudioBitDepth");
#if MATROSKA_VERSION >= 2

DEFINE_START_SEMANTIC(KaxTrackOperation)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackCombinePlanes)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackJoinBlocks)
DEFINE_END_SEMANTIC(KaxTrackOperation)

DEFINE_MKX_MASTER(KaxTrackOperation, 0xE2, 1, KaxTrackEntry, "TrackOperation");

DEFINE_START_SEMANTIC(KaxTrackCombinePlanes)
DEFINE_SEMANTIC_ITEM(true, false, KaxTrackPlane)
DEFINE_END_SEMANTIC(KaxTrackCombinePlanes)

DEFINE_MKX_MASTER(KaxTrackCombinePlanes, 0xE3, 1, KaxTrackOperation, "TrackCombinePlanes");

DEFINE_START_SEMANTIC(KaxTrackPlane)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackPlaneUID)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackPlaneType)
DEFINE_END_SEMANTIC(KaxTrackPlane)

DEFINE_MKX_MASTER(KaxTrackPlane, 0xE4, 1, KaxTrackCombinePlanes, "TrackPlane");
DEFINE_MKX_UINTEGER(KaxTrackPlaneUID, 0xE5, 1, KaxTrackPlane, "TrackPlaneUID");
DEFINE_MKX_UINTEGER(KaxTrackPlaneType, 0xE6, 1, KaxTrackPlane, "TrackPlaneType");

DEFINE_START_SEMANTIC(KaxTrackJoinBlocks)
DEFINE_SEMANTIC_ITEM(true, false, KaxTrackJoinUID)
DEFINE_END_SEMANTIC(KaxTrackJoinBlocks)

DEFINE_MKX_MASTER(KaxTrackJoinBlocks, 0xE9, 1, KaxTrackOperation, "TrackJoinBlocks");
DEFINE_MKX_UINTEGER(KaxTrackJoinUID, 0xED, 1, KaxTrackJoinBlocks, "TrackJoinUID");
DEFINE_MKX_UINTEGER(KaxTrickTrackUID, 0xC0, 1, KaxTrackEntry, "TrickTrackUID");
DEFINE_MKX_BINARY (KaxTrickTrackSegmentUID, 0xC1, 1, KaxTrackEntry, "TrickTrackSegmentUID");
DEFINE_MKX_UINTEGER_DEF(KaxTrickTrackFlag, 0xC6, 1, KaxTrackEntry, "TrickTrackFlag", 0);
DEFINE_MKX_UINTEGER(KaxTrickMasterTrackUID, 0xC7, 1, KaxTrackEntry, "TrickMasterTrackUID");
DEFINE_MKX_BINARY (KaxTrickMasterTrackSegmentUID, 0xC4, 1, KaxTrackEntry, "TrickMasterTrackSegmentUID");
#endif

DEFINE_START_SEMANTIC(KaxContentEncodings)
DEFINE_SEMANTIC_ITEM(true, false, KaxContentEncoding)
DEFINE_END_SEMANTIC(KaxContentEncodings)

DEFINE_MKX_MASTER(KaxContentEncodings, 0x6D80, 2, KaxTrackEntry, "ContentEncodings");

DEFINE_START_SEMANTIC(KaxContentEncoding)
DEFINE_SEMANTIC_ITEM(true, true, KaxContentEncodingOrder)
DEFINE_SEMANTIC_ITEM(true, true, KaxContentEncodingScope)
DEFINE_SEMANTIC_ITEM(true, true, KaxContentEncodingType)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentCompression)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentEncryption)
DEFINE_END_SEMANTIC(KaxContentEncoding)

DEFINE_MKX_MASTER(KaxContentEncoding, 0x6240, 2, KaxContentEncodings, "ContentEncoding");
DEFINE_MKX_UINTEGER_DEF(KaxContentEncodingOrder, 0x5031, 2, KaxContentEncoding, "ContentEncodingOrder", 0);
DEFINE_MKX_UINTEGER_DEF(KaxContentEncodingScope, 0x5032, 2, KaxContentEncoding, "ContentEncodingScope", 1);
DEFINE_MKX_UINTEGER_DEF(KaxContentEncodingType, 0x5033, 2, KaxContentEncoding, "ContentEncodingType", 0);

DEFINE_START_SEMANTIC(KaxContentCompression)
DEFINE_SEMANTIC_ITEM(true, true, KaxContentCompAlgo)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentCompSettings)
DEFINE_END_SEMANTIC(KaxContentCompression)

DEFINE_MKX_MASTER(KaxContentCompression, 0x5034, 2, KaxContentEncoding, "ContentCompression");
DEFINE_MKX_UINTEGER_DEF(KaxContentCompAlgo, 0x4254, 2, KaxContentCompression, "ContentCompAlgo", 0);
DEFINE_MKX_BINARY (KaxContentCompSettings, 0x4255, 2, KaxContentCompression, "ContentCompSettings");

DEFINE_START_SEMANTIC(KaxContentEncryption)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentEncAlgo)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentEncKeyID)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentSignature)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentSigKeyID)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentSigAlgo)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentSigHashAlgo)
DEFINE_END_SEMANTIC(KaxContentEncryption)

DEFINE_MKX_MASTER(KaxContentEncryption, 0x5035, 2, KaxContentEncoding, "ContentEncryption");
DEFINE_MKX_UINTEGER_DEF(KaxContentEncAlgo, 0x47E1, 2, KaxContentEncryption, "ContentEncAlgo", 0);
DEFINE_MKX_BINARY (KaxContentEncKeyID, 0x47E2, 2, KaxContentEncryption, "ContentEncKeyID");
DEFINE_MKX_BINARY (KaxContentSignature, 0x47E3, 2, KaxContentEncryption, "ContentSignature");
DEFINE_MKX_BINARY (KaxContentSigKeyID, 0x47E4, 2, KaxContentEncryption, "ContentSigKeyID");
DEFINE_MKX_UINTEGER_DEF(KaxContentSigAlgo, 0x47E5, 2, KaxContentEncryption, "ContentSigAlgo", 0);
DEFINE_MKX_UINTEGER_DEF(KaxContentSigHashAlgo, 0x47E6, 2, KaxContentEncryption, "ContentSigHashAlgo", 0);

DEFINE_START_SEMANTIC(KaxCues)
DEFINE_SEMANTIC_ITEM(true, false, KaxCuePoint)
DEFINE_END_SEMANTIC(KaxCues)

DEFINE_MKX_MASTER(KaxCues, 0x1C53BB6B, 4, KaxSegment, "Cues");

DEFINE_START_SEMANTIC(KaxCuePoint)
DEFINE_SEMANTIC_ITEM(true, true, KaxCueTime)
DEFINE_SEMANTIC_ITEM(true, false, KaxCueTrackPositions)
DEFINE_END_SEMANTIC(KaxCuePoint)

DEFINE_MKX_MASTER(KaxCuePoint, 0xBB, 1, KaxCues, "CuePoint");
DEFINE_MKX_UINTEGER(KaxCueTime, 0xB3, 1, KaxCuePoint, "CueTime");

DEFINE_START_SEMANTIC(KaxCueTrackPositions)
DEFINE_SEMANTIC_ITEM(true, true, KaxCueTrack)
DEFINE_SEMANTIC_ITEM(true, true, KaxCueClusterPosition)
DEFINE_SEMANTIC_ITEM(false, true, KaxCueBlockNumber)
#if MATROSKA_VERSION >= 2
DEFINE_SEMANTIC_ITEM(false, true, KaxCueCodecState)
DEFINE_SEMANTIC_ITEM(false, false, KaxCueReference)
#endif // MATROSKA_VERSION
DEFINE_END_SEMANTIC(KaxCueTrackPositions)

DEFINE_MKX_MASTER(KaxCueTrackPositions, 0xB7, 1, KaxCuePoint, "CueTrackPositions");
DEFINE_MKX_UINTEGER(KaxCueTrack, 0xF7, 1, KaxCueTrackPositions, "CueTrack");
DEFINE_MKX_UINTEGER(KaxCueClusterPosition, 0xF1, 1, KaxCueTrackPositions, "CueClusterPosition");
DEFINE_MKX_UINTEGER_DEF(KaxCueBlockNumber, 0x5378, 2, KaxCueTrackPositions, "CueBlockNumber", 1);
#if MATROSKA_VERSION >= 2
DEFINE_MKX_UINTEGER_DEF(KaxCueCodecState, 0xEA, 1, KaxCueTrackPositions, "CueCodecState", 0);

DEFINE_START_SEMANTIC(KaxCueReference)
DEFINE_SEMANTIC_ITEM(true, true, KaxCueRefTime)
DEFINE_SEMANTIC_ITEM(true, true, KaxCueRefCluster) // not supported
DEFINE_SEMANTIC_ITEM(false, true, KaxCueRefNumber) // not supported
DEFINE_SEMANTIC_ITEM(false, true, KaxCueRefCodecState) // not supported
DEFINE_END_SEMANTIC(KaxCueReference)

DEFINE_MKX_MASTER(KaxCueReference, 0xDB, 1, KaxCueTrackPositions, "CueReference");
DEFINE_MKX_UINTEGER(KaxCueRefTime, 0x96, 1, KaxCueReference, "CueRefTime");
DEFINE_MKX_UINTEGER(KaxCueRefCluster, 0x97, 1, KaxCueReference, "CueRefCluster");
DEFINE_MKX_UINTEGER_DEF(KaxCueRefNumber, 0x535F, 2, KaxCueReference, "CueRefNumber", 1);
DEFINE_MKX_UINTEGER_DEF(KaxCueRefCodecState, 0xEB, 1, KaxCueReference, "CueRefCodecState", 0);
#endif

DEFINE_START_SEMANTIC(KaxAttachments)
DEFINE_SEMANTIC_ITEM(true, false, KaxAttached)
DEFINE_END_SEMANTIC(KaxAttachments)

DEFINE_MKX_MASTER_CONS(KaxAttachments, 0x1941A469, 4, KaxSegment, "Attachments");

DEFINE_START_SEMANTIC(KaxAttached)
DEFINE_SEMANTIC_ITEM(false, true, KaxFileDescription)
DEFINE_SEMANTIC_ITEM(true, true, KaxFileName)
DEFINE_SEMANTIC_ITEM(true, true, KaxMimeType)
DEFINE_SEMANTIC_ITEM(true, true, KaxFileData)
DEFINE_SEMANTIC_ITEM(true, true, KaxFileUID)
#if MATROSKA_VERSION >= 2
DEFINE_SEMANTIC_ITEM(false, true, KaxFileReferral) // not supported
DEFINE_SEMANTIC_ITEM(false, true, KaxFileUsedStartTime) // DivX specific
DEFINE_SEMANTIC_ITEM(false, true, KaxFileUsedEndTime) // DivX specific
#endif // MATROSKA_VERSION
DEFINE_END_SEMANTIC(KaxAttached)

DEFINE_MKX_MASTER_CONS(KaxAttached, 0x61A7, 2, KaxAttachments, "AttachedFile");
DEFINE_MKX_UNISTRING(KaxFileDescription, 0x467E, 2, KaxAttached, "FileDescription");
DEFINE_MKX_UNISTRING(KaxFileName, 0x466E, 2, KaxAttached, "FileName");
DEFINE_MKX_STRING(KaxMimeType, 0x4660, 2, KaxAttached, "FileMimeType");
DEFINE_MKX_BINARY (KaxFileData, 0x465C, 2, KaxAttached, "FileData");
DEFINE_MKX_UINTEGER(KaxFileUID, 0x46AE, 2, KaxAttached, "FileUID");
#if MATROSKA_VERSION >= 2
DEFINE_MKX_BINARY (KaxFileReferral, 0x4675, 2, KaxAttached, "FileReferral");
DEFINE_MKX_UINTEGER(KaxFileUsedStartTime, 0x4661, 2, KaxAttached, "FileUsedStartTime");
DEFINE_MKX_UINTEGER(KaxFileUsedEndTime, 0x4662, 2, KaxAttached, "FileUsedEndTime");
#endif

DEFINE_START_SEMANTIC(KaxChapters)
DEFINE_SEMANTIC_ITEM(true, false, KaxEditionEntry)
DEFINE_END_SEMANTIC(KaxChapters)

DEFINE_MKX_MASTER(KaxChapters, 0x1043A770, 4, KaxSegment, "Chapters");

DEFINE_START_SEMANTIC(KaxEditionEntry)
DEFINE_SEMANTIC_ITEM(false, true, KaxEditionUID)
DEFINE_SEMANTIC_ITEM(true, true, KaxEditionFlagHidden)
DEFINE_SEMANTIC_ITEM(true, true, KaxEditionFlagDefault)
DEFINE_SEMANTIC_ITEM(false, true, KaxEditionFlagOrdered)
DEFINE_SEMANTIC_ITEM(true, false, KaxChapterAtom)
DEFINE_END_SEMANTIC(KaxEditionEntry)

DEFINE_MKX_MASTER(KaxEditionEntry, 0x45B9, 2, KaxChapters, "EditionEntry");
DEFINE_MKX_UINTEGER(KaxEditionUID, 0x45BC, 2, KaxEditionEntry, "EditionUID");
DEFINE_MKX_UINTEGER_DEF(KaxEditionFlagHidden, 0x45BD, 2, KaxEditionEntry, "EditionFlagHidden", 0);
DEFINE_MKX_UINTEGER_DEF(KaxEditionFlagDefault, 0x45DB, 2, KaxEditionEntry, "EditionFlagDefault", 0);
DEFINE_MKX_UINTEGER_DEF(KaxEditionFlagOrdered, 0x45DD, 2, KaxEditionEntry, "EditionFlagOrdered", 0);

DEFINE_START_SEMANTIC(KaxChapterAtom)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapterAtom) // recursive
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterUID)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterTimeStart)
DEFINE_SEMANTIC_ITEM(false, true, KaxChapterTimeEnd)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterFlagHidden)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterFlagEnabled)
DEFINE_SEMANTIC_ITEM(false, true, KaxChapterSegmentUID)
DEFINE_SEMANTIC_ITEM(false, true, KaxChapterSegmentEditionUID)
DEFINE_SEMANTIC_ITEM(false, true, KaxChapterPhysicalEquiv)
DEFINE_SEMANTIC_ITEM(false, true, KaxChapterTrack)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapterDisplay)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapterProcess)
DEFINE_END_SEMANTIC(KaxChapterAtom)

DEFINE_MKX_MASTER(KaxChapterAtom, 0xB6, 1, KaxEditionEntry, "ChapterAtom");
DEFINE_MKX_UINTEGER(KaxChapterUID, 0x73C4, 2, KaxChapterAtom, "ChapterUID");
DEFINE_MKX_UINTEGER(KaxChapterTimeStart, 0x91, 1, KaxChapterAtom, "ChapterTimeStart");
DEFINE_MKX_UINTEGER(KaxChapterTimeEnd, 0x92, 1, KaxChapterAtom, "ChapterTimeEnd");
DEFINE_MKX_UINTEGER_DEF(KaxChapterFlagHidden, 0x98, 1, KaxChapterAtom, "ChapterFlagHidden", 0);
DEFINE_MKX_UINTEGER_DEF(KaxChapterFlagEnabled, 0x4598, 2, KaxChapterAtom, "ChapterFlagEnabled", 1);
DEFINE_MKX_BINARY (KaxChapterSegmentUID, 0x6E67, 2, KaxChapterAtom, "ChapterSegmentUID");
DEFINE_MKX_UINTEGER(KaxChapterSegmentEditionUID, 0x6EBC, 2, KaxChapterAtom, "ChapterSegmentEditionUID");
DEFINE_MKX_UINTEGER(KaxChapterPhysicalEquiv, 0x63C3, 2, KaxChapterAtom, "ChapterPhysicalEquiv");

DEFINE_START_SEMANTIC(KaxChapterTrack)
DEFINE_SEMANTIC_ITEM(true, false, KaxChapterTrackNumber)
DEFINE_END_SEMANTIC(KaxChapterTrack)

DEFINE_MKX_MASTER(KaxChapterTrack, 0x8F, 1, KaxChapterAtom, "ChapterTrack");
DEFINE_MKX_UINTEGER(KaxChapterTrackNumber, 0x89, 1, KaxChapterTrack, "ChapterTrackNumber");

DEFINE_START_SEMANTIC(KaxChapterDisplay)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterString)
DEFINE_SEMANTIC_ITEM(true, false, KaxChapterLanguage)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapterCountry)
DEFINE_END_SEMANTIC(KaxChapterDisplay)

DEFINE_MKX_MASTER(KaxChapterDisplay, 0x80, 1, KaxChapterAtom, "ChapterDisplay");
DEFINE_MKX_UNISTRING(KaxChapterString, 0x85, 1, KaxChapterDisplay, "ChapterString");
DEFINE_MKX_STRING_DEF(KaxChapterLanguage, 0x437C, 2, KaxChapterDisplay, "ChapterLanguage", "eng");
DEFINE_MKX_STRING(KaxChapterCountry, 0x437E, 2, KaxChapterDisplay, "ChapterCountry");

DEFINE_START_SEMANTIC(KaxChapterProcess)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterProcessCodecID)
DEFINE_SEMANTIC_ITEM(false, true, KaxChapterProcessPrivate)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapterProcessCommand)
DEFINE_END_SEMANTIC(KaxChapterProcess)

DEFINE_MKX_MASTER(KaxChapterProcess, 0x6944, 2, KaxChapterAtom, "ChapterProcess");
DEFINE_MKX_UINTEGER_DEF(KaxChapterProcessCodecID, 0x6955, 2, KaxChapterProcess, "ChapterProcessCodecID", 0);
DEFINE_MKX_BINARY (KaxChapterProcessPrivate, 0x450D, 2, KaxChapterProcess, "ChapterProcessPrivate");

DEFINE_START_SEMANTIC(KaxChapterProcessCommand)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterProcessTime)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterProcessData)
DEFINE_END_SEMANTIC(KaxChapterProcessCommand)

DEFINE_MKX_MASTER(KaxChapterProcessCommand, 0x6911, 2, KaxChapterProcess, "ChapterProcessCommand");
DEFINE_MKX_UINTEGER(KaxChapterProcessTime, 0x6922, 2, KaxChapterProcessCommand, "ChapterProcessTime");
DEFINE_MKX_BINARY (KaxChapterProcessData, 0x6933, 2, KaxChapterProcessCommand, "ChapterProcessData");

DEFINE_START_SEMANTIC(KaxTags)
DEFINE_SEMANTIC_ITEM(true, false, KaxTag)
DEFINE_END_SEMANTIC(KaxTags)

DEFINE_MKX_MASTER(KaxTags, 0x1254C367, 4, KaxSegment, "Tags");

DEFINE_START_SEMANTIC(KaxTag)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagTargets)
DEFINE_SEMANTIC_ITEM(true, false, KaxTagSimple)
DEFINE_END_SEMANTIC(KaxTag)

DEFINE_MKX_MASTER(KaxTag, 0x7373, 2, KaxTags, "Tag");

DEFINE_START_SEMANTIC(KaxTagTargets)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagTargetTypeValue)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagTargetType)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagTrackUID)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagEditionUID)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagChapterUID)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagAttachmentUID)
DEFINE_END_SEMANTIC(KaxTagTargets)

DEFINE_MKX_MASTER(KaxTagTargets, 0x63C0, 2, KaxTag, "TagTargets");
DEFINE_MKX_UINTEGER_DEF(KaxTagTargetTypeValue, 0x68CA, 2, KaxTagTargets, "TagTargetTypeValue", 50);
DEFINE_MKX_STRING(KaxTagTargetType, 0x63CA, 2, KaxTagTargets, "TagTargetType");
DEFINE_MKX_UINTEGER_DEF(KaxTagTrackUID, 0x63C5, 2, KaxTagTargets, "TagTrackUID", 0);
DEFINE_MKX_UINTEGER_DEF(KaxTagEditionUID, 0x63C9, 2, KaxTagTargets, "TagEditionUID", 0);
DEFINE_MKX_UINTEGER_DEF(KaxTagChapterUID, 0x63C4, 2, KaxTagTargets, "TagChapterUID", 0);
DEFINE_MKX_UINTEGER_DEF(KaxTagAttachmentUID, 0x63C6, 2, KaxTagTargets, "TagAttachmentUID", 0);

DEFINE_START_SEMANTIC(KaxTagSimple)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagSimple) // recursive
DEFINE_SEMANTIC_ITEM(true, true, KaxTagName)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagLangue)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagDefault)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagString)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagBinary)
DEFINE_END_SEMANTIC(KaxTagSimple)

DEFINE_MKX_MASTER(KaxTagSimple, 0x67C8, 2, KaxTag, "TagSimple");
DEFINE_MKX_UNISTRING(KaxTagName, 0x45A3, 2, KaxTagSimple, "TagName");
DEFINE_MKX_STRING_DEF(KaxTagLangue, 0x447A, 2, KaxTagSimple, "TagLanguage", "und");
DEFINE_MKX_UINTEGER_DEF(KaxTagDefault, 0x4484, 2, KaxTagSimple, "TagDefault", 1);
DEFINE_MKX_UNISTRING(KaxTagString, 0x4487, 2, KaxTagSimple, "TagString");
DEFINE_MKX_BINARY (KaxTagBinary, 0x4485, 2, KaxTagSimple, "TagBinary");

filepos_t KaxBlockVirtual::RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) {
	assert(false); // no you are not allowed to use this element !
	return 0;
}

filepos_t KaxReferenceVirtual::RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) {
	assert(false); // no you are not allowed to use this element !
	return 0;
}

filepos_t KaxSliceFrameNumber::RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) {
	assert(false); // no you are not allowed to use this element !
	return 0;
}

filepos_t KaxSliceBlockAddID::RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) {
	assert(false); // no you are not allowed to use this element !
	return 0;
}

filepos_t KaxSliceDelay::RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) {
	assert(false); // no you are not allowed to use this element !
	return 0;
}

filepos_t KaxSliceDuration::RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) {
	assert(false); // no you are not allowed to use this element !
	return 0;
}

filepos_t KaxEncryptedBlock::RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) {
	assert(false); // no you are not allowed to use this element !
	return 0;
}

filepos_t KaxTrackOffset::RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) {
	assert(false); // no you are not allowed to use this element !
	return 0;
}

filepos_t KaxCodecSettings::RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) {
	assert(false); // no you are not allowed to use this element !
	return 0;
}

filepos_t KaxCodecInfoURL::RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) {
	assert(false); // no you are not allowed to use this element !
	return 0;
}

filepos_t KaxCodecDownloadURL::RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) {
	assert(false); // no you are not allowed to use this element !
	return 0;
}

filepos_t KaxOldStereoMode::RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) {
	assert(false); // no you are not allowed to use this element !
	return 0;
}

filepos_t KaxVideoGamma::RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) {
	assert(false); // no you are not allowed to use this element !
	return 0;
}

filepos_t KaxVideoFrameRate::RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) {
	assert(false); // no you are not allowed to use this element !
	return 0;
}

filepos_t KaxAudioPosition::RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) {
	assert(false); // no you are not allowed to use this element !
	return 0;
}

filepos_t KaxCueRefCluster::RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) {
	assert(false); // no you are not allowed to use this element !
	return 0;
}

filepos_t KaxCueRefNumber::RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) {
	assert(false); // no you are not allowed to use this element !
	return 0;
}

filepos_t KaxCueRefCodecState::RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) {
	assert(false); // no you are not allowed to use this element !
	return 0;
}

filepos_t KaxFileReferral::RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) {
	assert(false); // no you are not allowed to use this element !
	return 0;
}

END_LIBMATROSKA_NAMESPACE
