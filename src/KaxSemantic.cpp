// Copyright © 2002-2020 Matroska (non-profit organisation).
// SPDX-License-Identifier: LGPL-2.1-or-later

/**********************************************************************
**  DO NOT EDIT, GENERATED WITH schema_2_kaxsemantic_cpp.xsl
**  https://github.com/Matroska-Org/foundation-source/tree/master/spectool
**********************************************************************/

#include "matroska/KaxContexts.h"
#include "matroska/KaxSemantic.h"
#include "matroska/KaxSegment.h"
#include "matroska/KaxSeekHead.h"
#include "matroska/KaxCluster.h"
#include "matroska/KaxTracks.h"
#include "matroska/KaxCues.h"
#include "matroska/KaxBlockData.h"
#include "matroska/KaxCuesData.h"

namespace libmatroska {

static constexpr const MatroskaProfile VERSION_ALL_MATROSKA = {true, true, 0, MatroskaProfile::ANY_VERSION};
static constexpr const MatroskaProfile VERSION_DEPRECATED   = {false, false, MatroskaProfile::ANY_VERSION, 0};
static constexpr const MatroskaProfile VERSION_DIVX_ONLY    = {false, true, MatroskaProfile::ANY_VERSION, 0};

DEFINE_START_SEMANTIC(KaxSegment)
DEFINE_SEMANTIC_ITEM(false, false, KaxSeekHead)
DEFINE_SEMANTIC_ITEM(true, false, KaxInfo)
DEFINE_SEMANTIC_ITEM(false, false, KaxCluster)
DEFINE_SEMANTIC_ITEM(false, false, KaxTracks)
DEFINE_SEMANTIC_ITEM(false, true, KaxCues)
DEFINE_SEMANTIC_ITEM(false, true, KaxAttachments)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapters)
DEFINE_SEMANTIC_ITEM(false, false, KaxTags)
DEFINE_END_SEMANTIC(KaxSegment)

DEFINE_MKX_MASTER_ORPHAN(KaxSegment, 0x18538067, 4, true, "Segment", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxSeekHead)
DEFINE_SEMANTIC_ITEM(true, false, KaxSeek)
DEFINE_END_SEMANTIC(KaxSeekHead)

DEFINE_MKX_MASTER(KaxSeekHead, 0x114D9B74, 4, KaxSegment, false, "SeekHeader", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxSeek)
DEFINE_SEMANTIC_ITEM(true, true, KaxSeekID)
DEFINE_SEMANTIC_ITEM(true, true, KaxSeekPosition)
DEFINE_END_SEMANTIC(KaxSeek)

DEFINE_MKX_MASTER(KaxSeek, 0x4DBB, 2, KaxSeekHead, false, "SeekPoint", VERSION_ALL_MATROSKA)
DEFINE_MKX_BINARY (KaxSeekID, 0x53AB, 2, KaxSeek, "SeekID", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxSeekPosition, 0x53AC, 2, KaxSeek, "SeekPosition", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxInfo)
DEFINE_SEMANTIC_ITEM(false, true, KaxSegmentUID)
DEFINE_SEMANTIC_ITEM(false, true, KaxSegmentFilename)
DEFINE_SEMANTIC_ITEM(false, true, KaxPrevUID)
DEFINE_SEMANTIC_ITEM(false, true, KaxPrevFilename)
DEFINE_SEMANTIC_ITEM(false, true, KaxNextUID)
DEFINE_SEMANTIC_ITEM(false, true, KaxNextFilename)
DEFINE_SEMANTIC_ITEM(false, false, KaxSegmentFamily)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapterTranslate)
DEFINE_SEMANTIC_ITEM(true, true, KaxTimestampScale)
DEFINE_SEMANTIC_ITEM(false, true, KaxDuration)
DEFINE_SEMANTIC_ITEM(false, true, KaxDateUTC)
DEFINE_SEMANTIC_ITEM(false, true, KaxTitle)
DEFINE_SEMANTIC_ITEM(true, true, KaxMuxingApp)
DEFINE_SEMANTIC_ITEM(true, true, KaxWritingApp)
DEFINE_END_SEMANTIC(KaxInfo)

DEFINE_MKX_MASTER(KaxInfo, 0x1549A966, 4, KaxSegment, false, "Info", VERSION_ALL_MATROSKA)
DEFINE_MKX_BINARY (KaxSegmentUID, 0x73A4, 2, KaxInfo, "SegmentUID", MatroskaProfile(false, false, 0))
DEFINE_MKX_UNISTRING(KaxSegmentFilename, 0x7384, 2, KaxInfo, "SegmentFilename", MatroskaProfile(false, false, 0))
DEFINE_MKX_BINARY (KaxPrevUID, 0x3CB923, 3, KaxInfo, "PrevUID", MatroskaProfile(false, false, 0))
DEFINE_MKX_UNISTRING(KaxPrevFilename, 0x3C83AB, 3, KaxInfo, "PrevFilename", MatroskaProfile(false, false, 0))
DEFINE_MKX_BINARY (KaxNextUID, 0x3EB923, 3, KaxInfo, "NextUID", MatroskaProfile(false, false, 0))
DEFINE_MKX_UNISTRING(KaxNextFilename, 0x3E83BB, 3, KaxInfo, "NextFilename", MatroskaProfile(false, false, 0))
DEFINE_MKX_BINARY (KaxSegmentFamily, 0x4444, 2, KaxInfo, "SegmentFamily", MatroskaProfile(false, false, 0))

DEFINE_START_SEMANTIC(KaxChapterTranslate)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterTranslateID)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterTranslateCodec)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapterTranslateEditionUID)
DEFINE_END_SEMANTIC(KaxChapterTranslate)

DEFINE_MKX_MASTER(KaxChapterTranslate, 0x6924, 2, KaxInfo, false, "ChapterTranslate", MatroskaProfile(false, false, 0))
DEFINE_MKX_BINARY (KaxChapterTranslateID, 0x69A5, 2, KaxChapterTranslate, "ChapterTranslateID", MatroskaProfile(false, false, 0))
DEFINE_MKX_UINTEGER(KaxChapterTranslateCodec, 0x69BF, 2, KaxChapterTranslate, "ChapterTranslateCodec", MatroskaProfile(false, false, 0))
DEFINE_MKX_UINTEGER(KaxChapterTranslateEditionUID, 0x69FC, 2, KaxChapterTranslate, "ChapterTranslateEditionUID", MatroskaProfile(false, false, 0))
DEFINE_MKX_UINTEGER_DEF(KaxTimestampScale, 0x2AD7B1, 3, KaxInfo, "TimestampScale", VERSION_ALL_MATROSKA, 1000000)
DEFINE_MKX_FLOAT(KaxDuration, 0x4489, 2, KaxInfo, "Duration", VERSION_ALL_MATROSKA)
DEFINE_MKX_DATE    (KaxDateUTC, 0x4461, 2, KaxInfo, "DateUTC", VERSION_ALL_MATROSKA)
DEFINE_MKX_UNISTRING(KaxTitle, 0x7BA9, 2, KaxInfo, "Title", VERSION_ALL_MATROSKA)
DEFINE_MKX_UNISTRING(KaxMuxingApp, 0x4D80, 2, KaxInfo, "MuxingApp", VERSION_ALL_MATROSKA)
DEFINE_MKX_UNISTRING(KaxWritingApp, 0x5741, 2, KaxInfo, "WritingApp", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxCluster)
DEFINE_SEMANTIC_ITEM(true, true, KaxClusterTimestamp)
DEFINE_SEMANTIC_ITEM(false, true, KaxClusterSilentTracks)
DEFINE_SEMANTIC_ITEM(false, true, KaxClusterPosition)
DEFINE_SEMANTIC_ITEM(false, true, KaxClusterPrevSize)
DEFINE_SEMANTIC_ITEM(false, false, KaxSimpleBlock)
DEFINE_SEMANTIC_ITEM(false, false, KaxBlockGroup)
DEFINE_SEMANTIC_ITEM(false, false, KaxEncryptedBlock)
DEFINE_END_SEMANTIC(KaxCluster)

DEFINE_MKX_MASTER_CONS(KaxCluster, 0x1F43B675, 4, KaxSegment, true, "Cluster", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxClusterTimestamp, 0xE7, 1, KaxCluster, "ClusterTimestamp", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxClusterSilentTracks)
DEFINE_SEMANTIC_ITEM(false, false, KaxClusterSilentTrackNumber)
DEFINE_END_SEMANTIC(KaxClusterSilentTracks)

DEFINE_MKX_MASTER(KaxClusterSilentTracks, 0x5854, 2, KaxCluster, false, "ClusterSilentTracks", VERSION_DEPRECATED)
DEFINE_MKX_UINTEGER(KaxClusterSilentTrackNumber, 0x58D7, 2, KaxClusterSilentTracks, "ClusterSilentTrackNumber", VERSION_DEPRECATED)
DEFINE_MKX_UINTEGER(KaxClusterPosition, 0xA7, 1, KaxCluster, "ClusterPosition", MatroskaProfile(true, false, 0, 4))
DEFINE_MKX_UINTEGER(KaxClusterPrevSize, 0xAB, 1, KaxCluster, "ClusterPrevSize", VERSION_ALL_MATROSKA)
DEFINE_MKX_BINARY_CONS(KaxSimpleBlock, 0xA3, 1, KaxCluster, "SimpleBlock", MatroskaProfile(true, true, 2))

DEFINE_START_SEMANTIC(KaxBlockGroup)
DEFINE_SEMANTIC_ITEM(true, true, KaxBlock)
DEFINE_SEMANTIC_ITEM(false, true, KaxBlockVirtual)
DEFINE_SEMANTIC_ITEM(false, true, KaxBlockAdditions)
DEFINE_SEMANTIC_ITEM(false, true, KaxBlockDuration)
DEFINE_SEMANTIC_ITEM(true, true, KaxReferencePriority)
DEFINE_SEMANTIC_ITEM(false, false, KaxReferenceBlock)
DEFINE_SEMANTIC_ITEM(false, true, KaxReferenceVirtual)
DEFINE_SEMANTIC_ITEM(false, true, KaxCodecState)
DEFINE_SEMANTIC_ITEM(false, true, KaxDiscardPadding)
DEFINE_SEMANTIC_ITEM(false, true, KaxSlices)
DEFINE_SEMANTIC_ITEM(false, true, KaxReferenceFrame)
DEFINE_END_SEMANTIC(KaxBlockGroup)

DEFINE_MKX_MASTER_CONS(KaxBlockGroup, 0xA0, 1, KaxCluster, false, "BlockGroup", VERSION_ALL_MATROSKA)
DEFINE_MKX_BINARY_CONS(KaxBlock, 0xA1, 1, KaxBlockGroup, "Block", VERSION_ALL_MATROSKA)
DEFINE_MKX_BINARY_CONS(KaxBlockVirtual, 0xA2, 1, KaxBlockGroup, "BlockVirtual", VERSION_DEPRECATED)

DEFINE_START_SEMANTIC(KaxBlockAdditions)
DEFINE_SEMANTIC_ITEM(true, false, KaxBlockMore)
DEFINE_END_SEMANTIC(KaxBlockAdditions)

DEFINE_MKX_MASTER(KaxBlockAdditions, 0x75A1, 2, KaxBlockGroup, false, "BlockAdditions", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxBlockMore)
DEFINE_SEMANTIC_ITEM(true, true, KaxBlockAdditional)
DEFINE_SEMANTIC_ITEM(true, true, KaxBlockAddID)
DEFINE_END_SEMANTIC(KaxBlockMore)

DEFINE_MKX_MASTER(KaxBlockMore, 0xA6, 1, KaxBlockAdditions, false, "BlockMore", VERSION_ALL_MATROSKA)
DEFINE_MKX_BINARY (KaxBlockAdditional, 0xA5, 1, KaxBlockMore, "BlockAdditional", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxBlockAddID, 0xEE, 1, KaxBlockMore, "BlockAddID", VERSION_ALL_MATROSKA, 1)
DEFINE_MKX_UINTEGER(KaxBlockDuration, 0x9B, 1, KaxBlockGroup, "BlockDuration", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxReferencePriority, 0xFA, 1, KaxBlockGroup, "FlagReferenced", MatroskaProfile(false, false, 0), 0)
DEFINE_MKX_SINTEGER_CONS(KaxReferenceBlock, 0xFB, 1, KaxBlockGroup, "ReferenceBlock", VERSION_ALL_MATROSKA)
DEFINE_MKX_SINTEGER(KaxReferenceVirtual, 0xFD, 1, KaxBlockGroup, "ReferenceVirtual", VERSION_DEPRECATED)
DEFINE_MKX_BINARY (KaxCodecState, 0xA4, 1, KaxBlockGroup, "CodecState", MatroskaProfile(false, false, 2))
DEFINE_MKX_SINTEGER(KaxDiscardPadding, 0x75A2, 2, KaxBlockGroup, "DiscardPadding", MatroskaProfile(true, false, 4))

DEFINE_START_SEMANTIC(KaxSlices)
DEFINE_SEMANTIC_ITEM(false, false, KaxTimeSlice)
DEFINE_END_SEMANTIC(KaxSlices)

DEFINE_MKX_MASTER(KaxSlices, 0x8E, 1, KaxBlockGroup, false, "Slices", VERSION_DEPRECATED)

DEFINE_START_SEMANTIC(KaxTimeSlice)
DEFINE_SEMANTIC_ITEM(false, true, KaxSliceLaceNumber)
DEFINE_SEMANTIC_ITEM(false, true, KaxSliceFrameNumber)
DEFINE_SEMANTIC_ITEM(false, true, KaxSliceBlockAddID)
DEFINE_SEMANTIC_ITEM(false, true, KaxSliceDelay)
DEFINE_SEMANTIC_ITEM(false, true, KaxSliceDuration)
DEFINE_END_SEMANTIC(KaxTimeSlice)

DEFINE_MKX_MASTER(KaxTimeSlice, 0xE8, 1, KaxSlices, false, "TimeSlice", VERSION_DEPRECATED)
DEFINE_MKX_UINTEGER(KaxSliceLaceNumber, 0xCC, 1, KaxTimeSlice, "SliceLaceNumber", VERSION_DEPRECATED)
DEFINE_MKX_UINTEGER_DEF(KaxSliceFrameNumber, 0xCD, 1, KaxTimeSlice, "SliceFrameNumber", VERSION_DEPRECATED, 0)
DEFINE_MKX_UINTEGER_DEF(KaxSliceBlockAddID, 0xCB, 1, KaxTimeSlice, "SliceBlockAddID", VERSION_DEPRECATED, 0)
DEFINE_MKX_UINTEGER_DEF(KaxSliceDelay, 0xCE, 1, KaxTimeSlice, "SliceDelay", VERSION_DEPRECATED, 0)
DEFINE_MKX_UINTEGER_DEF(KaxSliceDuration, 0xCF, 1, KaxTimeSlice, "SliceDuration", VERSION_DEPRECATED, 0)

DEFINE_START_SEMANTIC(KaxReferenceFrame)
DEFINE_SEMANTIC_ITEM(true, true, KaxReferenceOffset)
DEFINE_SEMANTIC_ITEM(true, true, KaxReferenceTimestamp)
DEFINE_END_SEMANTIC(KaxReferenceFrame)

DEFINE_MKX_MASTER(KaxReferenceFrame, 0xC8, 1, KaxBlockGroup, false, "ReferenceFrame", VERSION_DIVX_ONLY)
DEFINE_MKX_UINTEGER(KaxReferenceOffset, 0xC9, 1, KaxReferenceFrame, "ReferenceOffset", VERSION_DIVX_ONLY)
DEFINE_MKX_UINTEGER(KaxReferenceTimestamp, 0xCA, 1, KaxReferenceFrame, "ReferenceTimestamp", VERSION_DIVX_ONLY)
DEFINE_MKX_BINARY (KaxEncryptedBlock, 0xAF, 1, KaxCluster, "EncryptedBlock", VERSION_DEPRECATED)

DEFINE_START_SEMANTIC(KaxTracks)
DEFINE_SEMANTIC_ITEM(true, false, KaxTrackEntry)
DEFINE_END_SEMANTIC(KaxTracks)

DEFINE_MKX_MASTER(KaxTracks, 0x1654AE6B, 4, KaxSegment, false, "Tracks", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxTrackEntry)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackNumber)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackUID)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackType)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackFlagEnabled)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackFlagDefault)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackFlagForced)
DEFINE_SEMANTIC_ITEM(false, true, KaxFlagHearingImpaired)
DEFINE_SEMANTIC_ITEM(false, true, KaxFlagVisualImpaired)
DEFINE_SEMANTIC_ITEM(false, true, KaxFlagTextDescriptions)
DEFINE_SEMANTIC_ITEM(false, true, KaxFlagOriginal)
DEFINE_SEMANTIC_ITEM(false, true, KaxFlagCommentary)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackFlagLacing)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackMinCache)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackMaxCache)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackDefaultDuration)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackDefaultDecodedFieldDuration)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackTimestampScale)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackOffset)
DEFINE_SEMANTIC_ITEM(true, true, KaxMaxBlockAdditionID)
DEFINE_SEMANTIC_ITEM(false, false, KaxBlockAdditionMapping)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackName)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackLanguage)
DEFINE_SEMANTIC_ITEM(false, true, KaxLanguageIETF)
DEFINE_SEMANTIC_ITEM(true, true, KaxCodecID)
DEFINE_SEMANTIC_ITEM(false, true, KaxCodecPrivate)
DEFINE_SEMANTIC_ITEM(false, true, KaxCodecName)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackAttachmentLink)
DEFINE_SEMANTIC_ITEM(false, true, KaxCodecSettings)
DEFINE_SEMANTIC_ITEM(false, false, KaxCodecInfoURL)
DEFINE_SEMANTIC_ITEM(false, false, KaxCodecDownloadURL)
DEFINE_SEMANTIC_ITEM(true, true, KaxCodecDecodeAll)
DEFINE_SEMANTIC_ITEM(false, false, KaxTrackOverlay)
DEFINE_SEMANTIC_ITEM(true, true, KaxCodecDelay)
DEFINE_SEMANTIC_ITEM(true, true, KaxSeekPreRoll)
DEFINE_SEMANTIC_ITEM(false, false, KaxTrackTranslate)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackVideo)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackAudio)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackOperation)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrickTrackUID)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrickTrackSegmentUID)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrickTrackFlag)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrickMasterTrackUID)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrickMasterTrackSegmentUID)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentEncodings)
DEFINE_END_SEMANTIC(KaxTrackEntry)

DEFINE_MKX_MASTER(KaxTrackEntry, 0xAE, 1, KaxTracks, false, "TrackEntry", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxTrackNumber, 0xD7, 1, KaxTrackEntry, "TrackNumber", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxTrackUID, 0x73C5, 2, KaxTrackEntry, "TrackUID", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxTrackType, 0x83, 1, KaxTrackEntry, "TrackType", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxTrackFlagEnabled, 0xB9, 1, KaxTrackEntry, "TrackFlagEnabled", MatroskaProfile(true, false, 2), 1)
DEFINE_MKX_UINTEGER_DEF(KaxTrackFlagDefault, 0x88, 1, KaxTrackEntry, "TrackFlagDefault", VERSION_ALL_MATROSKA, 1)
DEFINE_MKX_UINTEGER_DEF(KaxTrackFlagForced, 0x55AA, 2, KaxTrackEntry, "TrackFlagForced", VERSION_ALL_MATROSKA, 0)
DEFINE_MKX_UINTEGER(KaxFlagHearingImpaired, 0x55AB, 2, KaxTrackEntry, "FlagHearingImpaired", MatroskaProfile(false, false, 4))
DEFINE_MKX_UINTEGER(KaxFlagVisualImpaired, 0x55AC, 2, KaxTrackEntry, "FlagVisualImpaired", MatroskaProfile(false, false, 4))
DEFINE_MKX_UINTEGER(KaxFlagTextDescriptions, 0x55AD, 2, KaxTrackEntry, "FlagTextDescriptions", MatroskaProfile(false, false, 4))
DEFINE_MKX_UINTEGER(KaxFlagOriginal, 0x55AE, 2, KaxTrackEntry, "FlagOriginal", MatroskaProfile(false, false, 4))
DEFINE_MKX_UINTEGER(KaxFlagCommentary, 0x55AF, 2, KaxTrackEntry, "FlagCommentary", MatroskaProfile(false, false, 4))
DEFINE_MKX_UINTEGER_DEF(KaxTrackFlagLacing, 0x9C, 1, KaxTrackEntry, "TrackFlagLacing", VERSION_ALL_MATROSKA, 1)
DEFINE_MKX_UINTEGER_DEF(KaxTrackMinCache, 0x6DE7, 2, KaxTrackEntry, "TrackMinCache", VERSION_DEPRECATED, 0)
DEFINE_MKX_UINTEGER(KaxTrackMaxCache, 0x6DF8, 2, KaxTrackEntry, "TrackMaxCache", VERSION_DEPRECATED)
DEFINE_MKX_UINTEGER(KaxTrackDefaultDuration, 0x23E383, 3, KaxTrackEntry, "TrackDefaultDuration", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxTrackDefaultDecodedFieldDuration, 0x234E7A, 3, KaxTrackEntry, "TrackDefaultDecodedFieldDuration", MatroskaProfile(false, false, 4))
DEFINE_MKX_FLOAT_DEF(KaxTrackTimestampScale, 0x23314F, 3, KaxTrackEntry, "TrackTimestampScale", MatroskaProfile(false, false, 0, 3), 1)
DEFINE_MKX_SINTEGER_DEF(KaxTrackOffset, 0x537F, 2, KaxTrackEntry, "TrackOffset", VERSION_DEPRECATED, 0)
DEFINE_MKX_UINTEGER_DEF(KaxMaxBlockAdditionID, 0x55EE, 2, KaxTrackEntry, "MaxBlockAdditionID", MatroskaProfile(false, false, 0), 0)

DEFINE_START_SEMANTIC(KaxBlockAdditionMapping)
DEFINE_SEMANTIC_ITEM(false, true, KaxBlockAddIDValue)
DEFINE_SEMANTIC_ITEM(false, true, KaxBlockAddIDName)
DEFINE_SEMANTIC_ITEM(true, true, KaxBlockAddIDType)
DEFINE_SEMANTIC_ITEM(false, true, KaxBlockAddIDExtraData)
DEFINE_END_SEMANTIC(KaxBlockAdditionMapping)

DEFINE_MKX_MASTER(KaxBlockAdditionMapping, 0x41E4, 2, KaxTrackEntry, false, "BlockAdditionMapping", MatroskaProfile(false, false, 4))
DEFINE_MKX_UINTEGER(KaxBlockAddIDValue, 0x41F0, 2, KaxBlockAdditionMapping, "BlockAddIDValue", MatroskaProfile(false, false, 4))
DEFINE_MKX_STRING(KaxBlockAddIDName, 0x41A4, 2, KaxBlockAdditionMapping, "BlockAddIDName", MatroskaProfile(false, false, 4))
DEFINE_MKX_UINTEGER_DEF(KaxBlockAddIDType, 0x41E7, 2, KaxBlockAdditionMapping, "BlockAddIDType", MatroskaProfile(false, false, 4), 0)
DEFINE_MKX_BINARY (KaxBlockAddIDExtraData, 0x41ED, 2, KaxBlockAdditionMapping, "BlockAddIDExtraData", MatroskaProfile(false, false, 4))
DEFINE_MKX_UNISTRING(KaxTrackName, 0x536E, 2, KaxTrackEntry, "TrackName", VERSION_ALL_MATROSKA)
DEFINE_MKX_STRING_DEF(KaxTrackLanguage, 0x22B59C, 3, KaxTrackEntry, "TrackLanguage", VERSION_ALL_MATROSKA, "eng")
DEFINE_MKX_STRING(KaxLanguageIETF, 0x22B59D, 3, KaxTrackEntry, "LanguageIETF", MatroskaProfile(false, false, 4))
DEFINE_MKX_STRING(KaxCodecID, 0x86, 1, KaxTrackEntry, "CodecID", VERSION_ALL_MATROSKA)
DEFINE_MKX_BINARY (KaxCodecPrivate, 0x63A2, 2, KaxTrackEntry, "CodecPrivate", VERSION_ALL_MATROSKA)
DEFINE_MKX_UNISTRING(KaxCodecName, 0x258688, 3, KaxTrackEntry, "CodecName", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxTrackAttachmentLink, 0x7446, 2, KaxTrackEntry, "TrackAttachmentLink", MatroskaProfile(false, false, 0, 3))
DEFINE_MKX_UNISTRING(KaxCodecSettings, 0x3A9697, 3, KaxTrackEntry, "CodecSettings", VERSION_DEPRECATED)
DEFINE_MKX_STRING(KaxCodecInfoURL, 0x3B4040, 3, KaxTrackEntry, "CodecInfoURL", VERSION_DEPRECATED)
DEFINE_MKX_STRING(KaxCodecDownloadURL, 0x26B240, 3, KaxTrackEntry, "CodecDownloadURL", VERSION_DEPRECATED)
DEFINE_MKX_UINTEGER_DEF(KaxCodecDecodeAll, 0xAA, 1, KaxTrackEntry, "CodecDecodeAll", VERSION_DEPRECATED, 1)
DEFINE_MKX_UINTEGER(KaxTrackOverlay, 0x6FAB, 2, KaxTrackEntry, "TrackOverlay", MatroskaProfile(false, false, 0))
DEFINE_MKX_UINTEGER_DEF(KaxCodecDelay, 0x56AA, 2, KaxTrackEntry, "CodecDelay", MatroskaProfile(true, false, 4), 0)
DEFINE_MKX_UINTEGER_DEF(KaxSeekPreRoll, 0x56BB, 2, KaxTrackEntry, "SeekPreRoll", MatroskaProfile(true, false, 4), 0)

DEFINE_START_SEMANTIC(KaxTrackTranslate)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackTranslateTrackID)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackTranslateCodec)
DEFINE_SEMANTIC_ITEM(false, false, KaxTrackTranslateEditionUID)
DEFINE_END_SEMANTIC(KaxTrackTranslate)

DEFINE_MKX_MASTER(KaxTrackTranslate, 0x6624, 2, KaxTrackEntry, false, "TrackTranslate", MatroskaProfile(false, false, 0))
DEFINE_MKX_BINARY (KaxTrackTranslateTrackID, 0x66A5, 2, KaxTrackTranslate, "TrackTranslateTrackID", MatroskaProfile(false, false, 0))
DEFINE_MKX_UINTEGER(KaxTrackTranslateCodec, 0x66BF, 2, KaxTrackTranslate, "TrackTranslateCodec", MatroskaProfile(false, false, 0))
DEFINE_MKX_UINTEGER(KaxTrackTranslateEditionUID, 0x66FC, 2, KaxTrackTranslate, "TrackTranslateEditionUID", MatroskaProfile(false, false, 0))

DEFINE_START_SEMANTIC(KaxTrackVideo)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoFlagInterlaced)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoFieldOrder)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoStereoMode)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoAlphaMode)
DEFINE_SEMANTIC_ITEM(false, true, KaxOldStereoMode)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoPixelWidth)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoPixelHeight)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoPixelCropBottom)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoPixelCropTop)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoPixelCropLeft)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoPixelCropRight)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoDisplayWidth)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoDisplayHeight)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoDisplayUnit)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoAspectRatio)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoColourSpace)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoGamma)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoFrameRate)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoColour)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoProjection)
DEFINE_END_SEMANTIC(KaxTrackVideo)

DEFINE_MKX_MASTER(KaxTrackVideo, 0xE0, 1, KaxTrackEntry, false, "TrackVideo", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxVideoFlagInterlaced, 0x9A, 1, KaxTrackVideo, "VideoFlagInterlaced", MatroskaProfile(true, false, 2), 0)
DEFINE_MKX_UINTEGER_DEF(KaxVideoFieldOrder, 0x9D, 1, KaxTrackVideo, "VideoFieldOrder", MatroskaProfile(false, false, 4), 2)
DEFINE_MKX_UINTEGER_DEF(KaxVideoStereoMode, 0x53B8, 2, KaxTrackVideo, "VideoStereoMode", MatroskaProfile(true, false, 3), 0)
DEFINE_MKX_UINTEGER_DEF(KaxVideoAlphaMode, 0x53C0, 2, KaxTrackVideo, "VideoAlphaMode", MatroskaProfile(true, false, 3), 0)
DEFINE_MKX_UINTEGER(KaxOldStereoMode, 0x53B9, 2, KaxTrackVideo, "OldStereoMode", MatroskaProfile(false, false, 0, 2))
DEFINE_MKX_UINTEGER(KaxVideoPixelWidth, 0xB0, 1, KaxTrackVideo, "VideoPixelWidth", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxVideoPixelHeight, 0xBA, 1, KaxTrackVideo, "VideoPixelHeight", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxVideoPixelCropBottom, 0x54AA, 2, KaxTrackVideo, "VideoPixelCropBottom", VERSION_ALL_MATROSKA, 0)
DEFINE_MKX_UINTEGER_DEF(KaxVideoPixelCropTop, 0x54BB, 2, KaxTrackVideo, "VideoPixelCropTop", VERSION_ALL_MATROSKA, 0)
DEFINE_MKX_UINTEGER_DEF(KaxVideoPixelCropLeft, 0x54CC, 2, KaxTrackVideo, "VideoPixelCropLeft", VERSION_ALL_MATROSKA, 0)
DEFINE_MKX_UINTEGER_DEF(KaxVideoPixelCropRight, 0x54DD, 2, KaxTrackVideo, "VideoPixelCropRight", VERSION_ALL_MATROSKA, 0)
DEFINE_MKX_UINTEGER(KaxVideoDisplayWidth, 0x54B0, 2, KaxTrackVideo, "VideoDisplayWidth", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxVideoDisplayHeight, 0x54BA, 2, KaxTrackVideo, "VideoDisplayHeight", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxVideoDisplayUnit, 0x54B2, 2, KaxTrackVideo, "VideoDisplayUnit", VERSION_ALL_MATROSKA, 0)
DEFINE_MKX_UINTEGER_DEF(KaxVideoAspectRatio, 0x54B3, 2, KaxTrackVideo, "VideoAspectRatio", VERSION_DEPRECATED, 0)
DEFINE_MKX_BINARY (KaxVideoColourSpace, 0x2EB524, 3, KaxTrackVideo, "VideoColourSpace", MatroskaProfile(false, false, 0))
DEFINE_MKX_FLOAT(KaxVideoGamma, 0x2FB523, 3, KaxTrackVideo, "VideoGamma", VERSION_DEPRECATED)
DEFINE_MKX_FLOAT(KaxVideoFrameRate, 0x2383E3, 3, KaxTrackVideo, "VideoFrameRate", VERSION_DEPRECATED)

DEFINE_START_SEMANTIC(KaxVideoColour)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoColourMatrix)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoBitsPerChannel)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoChromaSubsampHorz)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoChromaSubsampVert)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoCbSubsampHorz)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoCbSubsampVert)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoChromaSitHorz)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoChromaSitVert)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoColourRange)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoColourTransferCharacter)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoColourPrimaries)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoColourMaxCLL)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoColourMaxFALL)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoColourMasterMeta)
DEFINE_END_SEMANTIC(KaxVideoColour)

DEFINE_MKX_MASTER(KaxVideoColour, 0x55B0, 2, KaxTrackVideo, false, "VideoColour", MatroskaProfile(true, false, 4))
DEFINE_MKX_UINTEGER_DEF(KaxVideoColourMatrix, 0x55B1, 2, KaxVideoColour, "VideoColourMatrix", MatroskaProfile(true, false, 4), 2)
DEFINE_MKX_UINTEGER_DEF(KaxVideoBitsPerChannel, 0x55B2, 2, KaxVideoColour, "VideoBitsPerChannel", MatroskaProfile(true, false, 4), 0)
DEFINE_MKX_UINTEGER(KaxVideoChromaSubsampHorz, 0x55B3, 2, KaxVideoColour, "VideoChromaSubsampHorz", MatroskaProfile(true, false, 4))
DEFINE_MKX_UINTEGER(KaxVideoChromaSubsampVert, 0x55B4, 2, KaxVideoColour, "VideoChromaSubsampVert", MatroskaProfile(true, false, 4))
DEFINE_MKX_UINTEGER(KaxVideoCbSubsampHorz, 0x55B5, 2, KaxVideoColour, "VideoCbSubsampHorz", MatroskaProfile(true, false, 4))
DEFINE_MKX_UINTEGER(KaxVideoCbSubsampVert, 0x55B6, 2, KaxVideoColour, "VideoCbSubsampVert", MatroskaProfile(true, false, 4))
DEFINE_MKX_UINTEGER_DEF(KaxVideoChromaSitHorz, 0x55B7, 2, KaxVideoColour, "VideoChromaSitHorz", MatroskaProfile(true, false, 4), 0)
DEFINE_MKX_UINTEGER_DEF(KaxVideoChromaSitVert, 0x55B8, 2, KaxVideoColour, "VideoChromaSitVert", MatroskaProfile(true, false, 4), 0)
DEFINE_MKX_UINTEGER_DEF(KaxVideoColourRange, 0x55B9, 2, KaxVideoColour, "VideoColourRange", MatroskaProfile(true, false, 4), 0)
DEFINE_MKX_UINTEGER_DEF(KaxVideoColourTransferCharacter, 0x55BA, 2, KaxVideoColour, "VideoColourTransferCharacter", MatroskaProfile(true, false, 4), 2)
DEFINE_MKX_UINTEGER_DEF(KaxVideoColourPrimaries, 0x55BB, 2, KaxVideoColour, "VideoColourPrimaries", MatroskaProfile(true, false, 4), 2)
DEFINE_MKX_UINTEGER(KaxVideoColourMaxCLL, 0x55BC, 2, KaxVideoColour, "VideoColourMaxCLL", MatroskaProfile(true, false, 4))
DEFINE_MKX_UINTEGER(KaxVideoColourMaxFALL, 0x55BD, 2, KaxVideoColour, "VideoColourMaxFALL", MatroskaProfile(true, false, 4))

DEFINE_START_SEMANTIC(KaxVideoColourMasterMeta)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoRChromaX)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoRChromaY)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoGChromaX)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoGChromaY)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoBChromaX)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoBChromaY)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoWhitePointChromaX)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoWhitePointChromaY)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoLuminanceMax)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoLuminanceMin)
DEFINE_END_SEMANTIC(KaxVideoColourMasterMeta)

DEFINE_MKX_MASTER(KaxVideoColourMasterMeta, 0x55D0, 2, KaxVideoColour, false, "VideoColourMasterMeta", MatroskaProfile(true, false, 4))
DEFINE_MKX_FLOAT(KaxVideoRChromaX, 0x55D1, 2, KaxVideoColourMasterMeta, "VideoRChromaX", MatroskaProfile(true, false, 4))
DEFINE_MKX_FLOAT(KaxVideoRChromaY, 0x55D2, 2, KaxVideoColourMasterMeta, "VideoRChromaY", MatroskaProfile(true, false, 4))
DEFINE_MKX_FLOAT(KaxVideoGChromaX, 0x55D3, 2, KaxVideoColourMasterMeta, "VideoGChromaX", MatroskaProfile(true, false, 4))
DEFINE_MKX_FLOAT(KaxVideoGChromaY, 0x55D4, 2, KaxVideoColourMasterMeta, "VideoGChromaY", MatroskaProfile(true, false, 4))
DEFINE_MKX_FLOAT(KaxVideoBChromaX, 0x55D5, 2, KaxVideoColourMasterMeta, "VideoBChromaX", MatroskaProfile(true, false, 4))
DEFINE_MKX_FLOAT(KaxVideoBChromaY, 0x55D6, 2, KaxVideoColourMasterMeta, "VideoBChromaY", MatroskaProfile(true, false, 4))
DEFINE_MKX_FLOAT(KaxVideoWhitePointChromaX, 0x55D7, 2, KaxVideoColourMasterMeta, "VideoWhitePointChromaX", MatroskaProfile(true, false, 4))
DEFINE_MKX_FLOAT(KaxVideoWhitePointChromaY, 0x55D8, 2, KaxVideoColourMasterMeta, "VideoWhitePointChromaY", MatroskaProfile(true, false, 4))
DEFINE_MKX_FLOAT(KaxVideoLuminanceMax, 0x55D9, 2, KaxVideoColourMasterMeta, "VideoLuminanceMax", MatroskaProfile(true, false, 4))
DEFINE_MKX_FLOAT(KaxVideoLuminanceMin, 0x55DA, 2, KaxVideoColourMasterMeta, "VideoLuminanceMin", MatroskaProfile(true, false, 4))

DEFINE_START_SEMANTIC(KaxVideoProjection)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoProjectionType)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoProjectionPrivate)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoProjectionPoseYaw)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoProjectionPosePitch)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoProjectionPoseRoll)
DEFINE_END_SEMANTIC(KaxVideoProjection)

DEFINE_MKX_MASTER(KaxVideoProjection, 0x7670, 2, KaxTrackVideo, false, "VideoProjection", MatroskaProfile(true, false, 4))
DEFINE_MKX_UINTEGER_DEF(KaxVideoProjectionType, 0x7671, 2, KaxVideoProjection, "VideoProjectionType", MatroskaProfile(true, false, 4), 0)
DEFINE_MKX_BINARY (KaxVideoProjectionPrivate, 0x7672, 2, KaxVideoProjection, "VideoProjectionPrivate", MatroskaProfile(true, false, 4))
DEFINE_MKX_FLOAT_DEF(KaxVideoProjectionPoseYaw, 0x7673, 2, KaxVideoProjection, "VideoProjectionPoseYaw", MatroskaProfile(true, false, 4), 0)
DEFINE_MKX_FLOAT_DEF(KaxVideoProjectionPosePitch, 0x7674, 2, KaxVideoProjection, "VideoProjectionPosePitch", MatroskaProfile(true, false, 4), 0)
DEFINE_MKX_FLOAT_DEF(KaxVideoProjectionPoseRoll, 0x7675, 2, KaxVideoProjection, "VideoProjectionPoseRoll", MatroskaProfile(true, false, 4), 0)

DEFINE_START_SEMANTIC(KaxTrackAudio)
DEFINE_SEMANTIC_ITEM(true, true, KaxAudioSamplingFreq)
DEFINE_SEMANTIC_ITEM(false, true, KaxAudioOutputSamplingFreq)
DEFINE_SEMANTIC_ITEM(true, true, KaxAudioChannels)
DEFINE_SEMANTIC_ITEM(false, true, KaxAudioPosition)
DEFINE_SEMANTIC_ITEM(false, true, KaxAudioBitDepth)
DEFINE_SEMANTIC_ITEM(true, true, KaxEmphasis)
DEFINE_END_SEMANTIC(KaxTrackAudio)

DEFINE_MKX_MASTER(KaxTrackAudio, 0xE1, 1, KaxTrackEntry, false, "TrackAudio", VERSION_ALL_MATROSKA)
DEFINE_MKX_FLOAT_DEF(KaxAudioSamplingFreq, 0xB5, 1, KaxTrackAudio, "AudioSamplingFreq", VERSION_ALL_MATROSKA, 8000)
DEFINE_MKX_FLOAT(KaxAudioOutputSamplingFreq, 0x78B5, 2, KaxTrackAudio, "AudioOutputSamplingFreq", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxAudioChannels, 0x9F, 1, KaxTrackAudio, "AudioChannels", VERSION_ALL_MATROSKA, 1)
DEFINE_MKX_BINARY (KaxAudioPosition, 0x7D7B, 2, KaxTrackAudio, "AudioPosition", VERSION_DEPRECATED)
DEFINE_MKX_UINTEGER(KaxAudioBitDepth, 0x6264, 2, KaxTrackAudio, "AudioBitDepth", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxEmphasis, 0x52F1, 2, KaxTrackAudio, "Emphasis", MatroskaProfile(false, false, 5), 0)

DEFINE_START_SEMANTIC(KaxTrackOperation)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackCombinePlanes)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackJoinBlocks)
DEFINE_END_SEMANTIC(KaxTrackOperation)

DEFINE_MKX_MASTER(KaxTrackOperation, 0xE2, 1, KaxTrackEntry, false, "TrackOperation", MatroskaProfile(false, false, 3))

DEFINE_START_SEMANTIC(KaxTrackCombinePlanes)
DEFINE_SEMANTIC_ITEM(true, false, KaxTrackPlane)
DEFINE_END_SEMANTIC(KaxTrackCombinePlanes)

DEFINE_MKX_MASTER(KaxTrackCombinePlanes, 0xE3, 1, KaxTrackOperation, false, "TrackCombinePlanes", MatroskaProfile(false, false, 3))

DEFINE_START_SEMANTIC(KaxTrackPlane)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackPlaneUID)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackPlaneType)
DEFINE_END_SEMANTIC(KaxTrackPlane)

DEFINE_MKX_MASTER(KaxTrackPlane, 0xE4, 1, KaxTrackCombinePlanes, false, "TrackPlane", MatroskaProfile(false, false, 3))
DEFINE_MKX_UINTEGER(KaxTrackPlaneUID, 0xE5, 1, KaxTrackPlane, "TrackPlaneUID", MatroskaProfile(false, false, 3))
DEFINE_MKX_UINTEGER(KaxTrackPlaneType, 0xE6, 1, KaxTrackPlane, "TrackPlaneType", MatroskaProfile(false, false, 3))

DEFINE_START_SEMANTIC(KaxTrackJoinBlocks)
DEFINE_SEMANTIC_ITEM(true, false, KaxTrackJoinUID)
DEFINE_END_SEMANTIC(KaxTrackJoinBlocks)

DEFINE_MKX_MASTER(KaxTrackJoinBlocks, 0xE9, 1, KaxTrackOperation, false, "TrackJoinBlocks", MatroskaProfile(false, false, 3))
DEFINE_MKX_UINTEGER(KaxTrackJoinUID, 0xED, 1, KaxTrackJoinBlocks, "TrackJoinUID", MatroskaProfile(false, false, 3))
DEFINE_MKX_UINTEGER(KaxTrickTrackUID, 0xC0, 1, KaxTrackEntry, "TrickTrackUID", VERSION_DIVX_ONLY)
DEFINE_MKX_BINARY (KaxTrickTrackSegmentUID, 0xC1, 1, KaxTrackEntry, "TrickTrackSegmentUID", VERSION_DIVX_ONLY)
DEFINE_MKX_UINTEGER_DEF(KaxTrickTrackFlag, 0xC6, 1, KaxTrackEntry, "TrickTrackFlag", VERSION_DIVX_ONLY, 0)
DEFINE_MKX_UINTEGER(KaxTrickMasterTrackUID, 0xC7, 1, KaxTrackEntry, "TrickMasterTrackUID", VERSION_DIVX_ONLY)
DEFINE_MKX_BINARY (KaxTrickMasterTrackSegmentUID, 0xC4, 1, KaxTrackEntry, "TrickMasterTrackSegmentUID", VERSION_DIVX_ONLY)

DEFINE_START_SEMANTIC(KaxContentEncodings)
DEFINE_SEMANTIC_ITEM(true, false, KaxContentEncoding)
DEFINE_END_SEMANTIC(KaxContentEncodings)

DEFINE_MKX_MASTER(KaxContentEncodings, 0x6D80, 2, KaxTrackEntry, false, "ContentEncodings", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxContentEncoding)
DEFINE_SEMANTIC_ITEM(true, true, KaxContentEncodingOrder)
DEFINE_SEMANTIC_ITEM(true, true, KaxContentEncodingScope)
DEFINE_SEMANTIC_ITEM(true, true, KaxContentEncodingType)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentCompression)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentEncryption)
DEFINE_END_SEMANTIC(KaxContentEncoding)

DEFINE_MKX_MASTER(KaxContentEncoding, 0x6240, 2, KaxContentEncodings, false, "ContentEncoding", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxContentEncodingOrder, 0x5031, 2, KaxContentEncoding, "ContentEncodingOrder", VERSION_ALL_MATROSKA, 0)
DEFINE_MKX_UINTEGER_DEF(KaxContentEncodingScope, 0x5032, 2, KaxContentEncoding, "ContentEncodingScope", VERSION_ALL_MATROSKA, 1)
DEFINE_MKX_UINTEGER_DEF(KaxContentEncodingType, 0x5033, 2, KaxContentEncoding, "ContentEncodingType", VERSION_ALL_MATROSKA, 0)

DEFINE_START_SEMANTIC(KaxContentCompression)
DEFINE_SEMANTIC_ITEM(true, true, KaxContentCompAlgo)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentCompSettings)
DEFINE_END_SEMANTIC(KaxContentCompression)

DEFINE_MKX_MASTER(KaxContentCompression, 0x5034, 2, KaxContentEncoding, false, "ContentCompression", MatroskaProfile(false, false, 0))
DEFINE_MKX_UINTEGER_DEF(KaxContentCompAlgo, 0x4254, 2, KaxContentCompression, "ContentCompAlgo", MatroskaProfile(false, false, 0), 0)
DEFINE_MKX_BINARY (KaxContentCompSettings, 0x4255, 2, KaxContentCompression, "ContentCompSettings", MatroskaProfile(false, false, 0))

DEFINE_START_SEMANTIC(KaxContentEncryption)
DEFINE_SEMANTIC_ITEM(true, true, KaxContentEncAlgo)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentEncKeyID)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentEncAESSettings)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentSignature)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentSigKeyID)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentSigAlgo)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentSigHashAlgo)
DEFINE_END_SEMANTIC(KaxContentEncryption)

DEFINE_MKX_MASTER(KaxContentEncryption, 0x5035, 2, KaxContentEncoding, false, "ContentEncryption", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxContentEncAlgo, 0x47E1, 2, KaxContentEncryption, "ContentEncAlgo", VERSION_ALL_MATROSKA, 0)
DEFINE_MKX_BINARY (KaxContentEncKeyID, 0x47E2, 2, KaxContentEncryption, "ContentEncKeyID", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxContentEncAESSettings)
DEFINE_SEMANTIC_ITEM(true, true, KaxAESSettingsCipherMode)
DEFINE_END_SEMANTIC(KaxContentEncAESSettings)

DEFINE_MKX_MASTER(KaxContentEncAESSettings, 0x47E7, 2, KaxContentEncryption, false, "ContentEncAESSettings", MatroskaProfile(true, false, 4))
DEFINE_MKX_UINTEGER(KaxAESSettingsCipherMode, 0x47E8, 2, KaxContentEncAESSettings, "AESSettingsCipherMode", MatroskaProfile(true, false, 4))
DEFINE_MKX_BINARY (KaxContentSignature, 0x47E3, 2, KaxContentEncryption, "ContentSignature", VERSION_DEPRECATED)
DEFINE_MKX_BINARY (KaxContentSigKeyID, 0x47E4, 2, KaxContentEncryption, "ContentSigKeyID", VERSION_DEPRECATED)
DEFINE_MKX_UINTEGER_DEF(KaxContentSigAlgo, 0x47E5, 2, KaxContentEncryption, "ContentSigAlgo", VERSION_DEPRECATED, 0)
DEFINE_MKX_UINTEGER_DEF(KaxContentSigHashAlgo, 0x47E6, 2, KaxContentEncryption, "ContentSigHashAlgo", VERSION_DEPRECATED, 0)

DEFINE_START_SEMANTIC(KaxCues)
DEFINE_SEMANTIC_ITEM(true, false, KaxCuePoint)
DEFINE_END_SEMANTIC(KaxCues)

DEFINE_MKX_MASTER(KaxCues, 0x1C53BB6B, 4, KaxSegment, false, "Cues", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxCuePoint)
DEFINE_SEMANTIC_ITEM(true, true, KaxCueTime)
DEFINE_SEMANTIC_ITEM(true, false, KaxCueTrackPositions)
DEFINE_END_SEMANTIC(KaxCuePoint)

DEFINE_MKX_MASTER(KaxCuePoint, 0xBB, 1, KaxCues, false, "CuePoint", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxCueTime, 0xB3, 1, KaxCuePoint, "CueTime", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxCueTrackPositions)
DEFINE_SEMANTIC_ITEM(true, true, KaxCueTrack)
DEFINE_SEMANTIC_ITEM(true, true, KaxCueClusterPosition)
DEFINE_SEMANTIC_ITEM(false, true, KaxCueRelativePosition)
DEFINE_SEMANTIC_ITEM(false, true, KaxCueDuration)
DEFINE_SEMANTIC_ITEM(false, true, KaxCueBlockNumber)
DEFINE_SEMANTIC_ITEM(true, true, KaxCueCodecState)
DEFINE_SEMANTIC_ITEM(false, false, KaxCueReference)
DEFINE_END_SEMANTIC(KaxCueTrackPositions)

DEFINE_MKX_MASTER(KaxCueTrackPositions, 0xB7, 1, KaxCuePoint, false, "CueTrackPositions", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxCueTrack, 0xF7, 1, KaxCueTrackPositions, "CueTrack", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxCueClusterPosition, 0xF1, 1, KaxCueTrackPositions, "CueClusterPosition", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxCueRelativePosition, 0xF0, 1, KaxCueTrackPositions, "CueRelativePosition", MatroskaProfile(true, false, 4))
DEFINE_MKX_UINTEGER(KaxCueDuration, 0xB2, 1, KaxCueTrackPositions, "CueDuration", MatroskaProfile(true, false, 4))
DEFINE_MKX_UINTEGER(KaxCueBlockNumber, 0x5378, 2, KaxCueTrackPositions, "CueBlockNumber", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxCueCodecState, 0xEA, 1, KaxCueTrackPositions, "CueCodecState", MatroskaProfile(false, false, 2), 0)

DEFINE_START_SEMANTIC(KaxCueReference)
DEFINE_SEMANTIC_ITEM(true, true, KaxCueRefTime)
DEFINE_SEMANTIC_ITEM(true, true, KaxCueRefCluster)
DEFINE_SEMANTIC_ITEM(false, true, KaxCueRefNumber)
DEFINE_SEMANTIC_ITEM(false, true, KaxCueRefCodecState)
DEFINE_END_SEMANTIC(KaxCueReference)

DEFINE_MKX_MASTER(KaxCueReference, 0xDB, 1, KaxCueTrackPositions, false, "CueReference", MatroskaProfile(false, false, 2))
DEFINE_MKX_UINTEGER(KaxCueRefTime, 0x96, 1, KaxCueReference, "CueRefTime", MatroskaProfile(false, false, 2))
DEFINE_MKX_UINTEGER(KaxCueRefCluster, 0x97, 1, KaxCueReference, "CueRefCluster", VERSION_DEPRECATED)
DEFINE_MKX_UINTEGER_DEF(KaxCueRefNumber, 0x535F, 2, KaxCueReference, "CueRefNumber", VERSION_DEPRECATED, 1)
DEFINE_MKX_UINTEGER_DEF(KaxCueRefCodecState, 0xEB, 1, KaxCueReference, "CueRefCodecState", VERSION_DEPRECATED, 0)

DEFINE_START_SEMANTIC(KaxAttachments)
DEFINE_SEMANTIC_ITEM(true, false, KaxAttached)
DEFINE_END_SEMANTIC(KaxAttachments)

DEFINE_MKX_MASTER_CONS(KaxAttachments, 0x1941A469, 4, KaxSegment, false, "Attachments", MatroskaProfile(false, false, 0))

DEFINE_START_SEMANTIC(KaxAttached)
DEFINE_SEMANTIC_ITEM(false, true, KaxFileDescription)
DEFINE_SEMANTIC_ITEM(true, true, KaxFileName)
DEFINE_SEMANTIC_ITEM(true, true, KaxMimeType)
DEFINE_SEMANTIC_ITEM(true, true, KaxFileData)
DEFINE_SEMANTIC_ITEM(true, true, KaxFileUID)
DEFINE_SEMANTIC_ITEM(false, true, KaxFileReferral)
DEFINE_SEMANTIC_ITEM(false, true, KaxFileUsedStartTime)
DEFINE_SEMANTIC_ITEM(false, true, KaxFileUsedEndTime)
DEFINE_END_SEMANTIC(KaxAttached)

DEFINE_MKX_MASTER_CONS(KaxAttached, 0x61A7, 2, KaxAttachments, false, "AttachedFile", MatroskaProfile(false, false, 0))
DEFINE_MKX_UNISTRING(KaxFileDescription, 0x467E, 2, KaxAttached, "FileDescription", MatroskaProfile(false, false, 0))
DEFINE_MKX_UNISTRING(KaxFileName, 0x466E, 2, KaxAttached, "FileName", MatroskaProfile(false, false, 0))
DEFINE_MKX_STRING(KaxMimeType, 0x4660, 2, KaxAttached, "FileMimeType", MatroskaProfile(false, false, 0))
DEFINE_MKX_BINARY (KaxFileData, 0x465C, 2, KaxAttached, "FileData", MatroskaProfile(false, false, 0))
DEFINE_MKX_UINTEGER(KaxFileUID, 0x46AE, 2, KaxAttached, "FileUID", MatroskaProfile(false, false, 0))
DEFINE_MKX_BINARY (KaxFileReferral, 0x4675, 2, KaxAttached, "FileReferral", VERSION_DEPRECATED)
DEFINE_MKX_UINTEGER(KaxFileUsedStartTime, 0x4661, 2, KaxAttached, "FileUsedStartTime", VERSION_DIVX_ONLY)
DEFINE_MKX_UINTEGER(KaxFileUsedEndTime, 0x4662, 2, KaxAttached, "FileUsedEndTime", VERSION_DIVX_ONLY)

DEFINE_START_SEMANTIC(KaxChapters)
DEFINE_SEMANTIC_ITEM(true, false, KaxEditionEntry)
DEFINE_END_SEMANTIC(KaxChapters)

DEFINE_MKX_MASTER(KaxChapters, 0x1043A770, 4, KaxSegment, false, "Chapters", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxEditionEntry)
DEFINE_SEMANTIC_ITEM(false, true, KaxEditionUID)
DEFINE_SEMANTIC_ITEM(true, true, KaxEditionFlagHidden)
DEFINE_SEMANTIC_ITEM(true, true, KaxEditionFlagDefault)
DEFINE_SEMANTIC_ITEM(true, true, KaxEditionFlagOrdered)
DEFINE_SEMANTIC_ITEM(false, false, KaxEditionDisplay)
DEFINE_SEMANTIC_ITEM(true, false, KaxChapterAtom)
DEFINE_END_SEMANTIC(KaxEditionEntry)

DEFINE_MKX_MASTER(KaxEditionEntry, 0x45B9, 2, KaxChapters, false, "EditionEntry", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxEditionUID, 0x45BC, 2, KaxEditionEntry, "EditionUID", MatroskaProfile(false, false, 0))
DEFINE_MKX_UINTEGER_DEF(KaxEditionFlagHidden, 0x45BD, 2, KaxEditionEntry, "EditionFlagHidden", MatroskaProfile(false, false, 0), 0)
DEFINE_MKX_UINTEGER_DEF(KaxEditionFlagDefault, 0x45DB, 2, KaxEditionEntry, "EditionFlagDefault", MatroskaProfile(false, false, 0), 0)
DEFINE_MKX_UINTEGER_DEF(KaxEditionFlagOrdered, 0x45DD, 2, KaxEditionEntry, "EditionFlagOrdered", MatroskaProfile(false, false, 0), 0)

DEFINE_START_SEMANTIC(KaxEditionDisplay)
DEFINE_SEMANTIC_ITEM(true, true, KaxEditionString)
DEFINE_SEMANTIC_ITEM(false, false, KaxEditionLanguageIETF)
DEFINE_END_SEMANTIC(KaxEditionDisplay)

DEFINE_MKX_MASTER(KaxEditionDisplay, 0x4520, 2, KaxEditionEntry, false, "EditionDisplay", MatroskaProfile(false, false, 5))
DEFINE_MKX_UNISTRING(KaxEditionString, 0x4521, 2, KaxEditionDisplay, "EditionString", MatroskaProfile(false, false, 5))
DEFINE_MKX_STRING(KaxEditionLanguageIETF, 0x45E4, 2, KaxEditionDisplay, "EditionLanguageIETF", MatroskaProfile(false, false, 5))

DEFINE_START_SEMANTIC(KaxChapterAtom)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapterAtom) // recursive
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterUID)
DEFINE_SEMANTIC_ITEM(false, true, KaxChapterStringUID)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterTimeStart)
DEFINE_SEMANTIC_ITEM(false, true, KaxChapterTimeEnd)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterFlagHidden)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterFlagEnabled)
DEFINE_SEMANTIC_ITEM(false, true, KaxChapterSegmentUID)
DEFINE_SEMANTIC_ITEM(false, true, KaxChapterSkipType)
DEFINE_SEMANTIC_ITEM(false, true, KaxChapterSegmentEditionUID)
DEFINE_SEMANTIC_ITEM(false, true, KaxChapterPhysicalEquiv)
DEFINE_SEMANTIC_ITEM(false, true, KaxChapterTrack)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapterDisplay)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapterProcess)
DEFINE_END_SEMANTIC(KaxChapterAtom)

DEFINE_MKX_MASTER(KaxChapterAtom, 0xB6, 1, KaxEditionEntry, false, "ChapterAtom", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxChapterUID, 0x73C4, 2, KaxChapterAtom, "ChapterUID", VERSION_ALL_MATROSKA)
DEFINE_MKX_UNISTRING(KaxChapterStringUID, 0x5654, 2, KaxChapterAtom, "ChapterStringUID", MatroskaProfile(true, false, 3))
DEFINE_MKX_UINTEGER(KaxChapterTimeStart, 0x91, 1, KaxChapterAtom, "ChapterTimeStart", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxChapterTimeEnd, 0x92, 1, KaxChapterAtom, "ChapterTimeEnd", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxChapterFlagHidden, 0x98, 1, KaxChapterAtom, "ChapterFlagHidden", MatroskaProfile(false, false, 0), 0)
DEFINE_MKX_UINTEGER_DEF(KaxChapterFlagEnabled, 0x4598, 2, KaxChapterAtom, "ChapterFlagEnabled", MatroskaProfile(false, false, 0), 1)
DEFINE_MKX_BINARY (KaxChapterSegmentUID, 0x6E67, 2, KaxChapterAtom, "ChapterSegmentUID", MatroskaProfile(false, false, 0))
DEFINE_MKX_UINTEGER(KaxChapterSkipType, 0x4588, 2, KaxChapterAtom, "ChapterSkipType", MatroskaProfile(false, false, 5))
DEFINE_MKX_UINTEGER(KaxChapterSegmentEditionUID, 0x6EBC, 2, KaxChapterAtom, "ChapterSegmentEditionUID", MatroskaProfile(false, false, 0))
DEFINE_MKX_UINTEGER(KaxChapterPhysicalEquiv, 0x63C3, 2, KaxChapterAtom, "ChapterPhysicalEquiv", MatroskaProfile(false, false, 0))

DEFINE_START_SEMANTIC(KaxChapterTrack)
DEFINE_SEMANTIC_ITEM(true, false, KaxChapterTrackNumber)
DEFINE_END_SEMANTIC(KaxChapterTrack)

DEFINE_MKX_MASTER(KaxChapterTrack, 0x8F, 1, KaxChapterAtom, false, "ChapterTrack", MatroskaProfile(false, false, 0))
DEFINE_MKX_UINTEGER(KaxChapterTrackNumber, 0x89, 1, KaxChapterTrack, "ChapterTrackNumber", MatroskaProfile(false, false, 0))

DEFINE_START_SEMANTIC(KaxChapterDisplay)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterString)
DEFINE_SEMANTIC_ITEM(true, false, KaxChapterLanguage)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapLanguageIETF)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapterCountry)
DEFINE_END_SEMANTIC(KaxChapterDisplay)

DEFINE_MKX_MASTER(KaxChapterDisplay, 0x80, 1, KaxChapterAtom, false, "ChapterDisplay", VERSION_ALL_MATROSKA)
DEFINE_MKX_UNISTRING(KaxChapterString, 0x85, 1, KaxChapterDisplay, "ChapterString", VERSION_ALL_MATROSKA)
DEFINE_MKX_STRING_DEF(KaxChapterLanguage, 0x437C, 2, KaxChapterDisplay, "ChapterLanguage", VERSION_ALL_MATROSKA, "eng")
DEFINE_MKX_STRING(KaxChapLanguageIETF, 0x437D, 2, KaxChapterDisplay, "ChapLanguageIETF", MatroskaProfile(false, false, 4))
DEFINE_MKX_STRING(KaxChapterCountry, 0x437E, 2, KaxChapterDisplay, "ChapterCountry", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxChapterProcess)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterProcessCodecID)
DEFINE_SEMANTIC_ITEM(false, true, KaxChapterProcessPrivate)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapterProcessCommand)
DEFINE_END_SEMANTIC(KaxChapterProcess)

DEFINE_MKX_MASTER(KaxChapterProcess, 0x6944, 2, KaxChapterAtom, false, "ChapterProcess", MatroskaProfile(false, false, 0))
DEFINE_MKX_UINTEGER_DEF(KaxChapterProcessCodecID, 0x6955, 2, KaxChapterProcess, "ChapterProcessCodecID", MatroskaProfile(false, false, 0), 0)
DEFINE_MKX_BINARY (KaxChapterProcessPrivate, 0x450D, 2, KaxChapterProcess, "ChapterProcessPrivate", MatroskaProfile(false, false, 0))

DEFINE_START_SEMANTIC(KaxChapterProcessCommand)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterProcessTime)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterProcessData)
DEFINE_END_SEMANTIC(KaxChapterProcessCommand)

DEFINE_MKX_MASTER(KaxChapterProcessCommand, 0x6911, 2, KaxChapterProcess, false, "ChapterProcessCommand", MatroskaProfile(false, false, 0))
DEFINE_MKX_UINTEGER(KaxChapterProcessTime, 0x6922, 2, KaxChapterProcessCommand, "ChapterProcessTime", MatroskaProfile(false, false, 0))
DEFINE_MKX_BINARY (KaxChapterProcessData, 0x6933, 2, KaxChapterProcessCommand, "ChapterProcessData", MatroskaProfile(false, false, 0))

DEFINE_START_SEMANTIC(KaxTags)
DEFINE_SEMANTIC_ITEM(true, false, KaxTag)
DEFINE_END_SEMANTIC(KaxTags)

DEFINE_MKX_MASTER(KaxTags, 0x1254C367, 4, KaxSegment, false, "Tags", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxTag)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagTargets)
DEFINE_SEMANTIC_ITEM(true, false, KaxTagSimple)
DEFINE_END_SEMANTIC(KaxTag)

DEFINE_MKX_MASTER(KaxTag, 0x7373, 2, KaxTags, false, "Tag", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxTagTargets)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagTargetTypeValue)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagTargetType)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagTrackUID)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagEditionUID)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagChapterUID)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagAttachmentUID)
DEFINE_END_SEMANTIC(KaxTagTargets)

DEFINE_MKX_MASTER(KaxTagTargets, 0x63C0, 2, KaxTag, false, "TagTargets", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxTagTargetTypeValue, 0x68CA, 2, KaxTagTargets, "TagTargetTypeValue", VERSION_ALL_MATROSKA, 50)
DEFINE_MKX_STRING(KaxTagTargetType, 0x63CA, 2, KaxTagTargets, "TagTargetType", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxTagTrackUID, 0x63C5, 2, KaxTagTargets, "TagTrackUID", VERSION_ALL_MATROSKA, 0)
DEFINE_MKX_UINTEGER_DEF(KaxTagEditionUID, 0x63C9, 2, KaxTagTargets, "TagEditionUID", MatroskaProfile(false, false, 0), 0)
DEFINE_MKX_UINTEGER_DEF(KaxTagChapterUID, 0x63C4, 2, KaxTagTargets, "TagChapterUID", MatroskaProfile(false, false, 0), 0)
DEFINE_MKX_UINTEGER_DEF(KaxTagAttachmentUID, 0x63C6, 2, KaxTagTargets, "TagAttachmentUID", MatroskaProfile(false, false, 0), 0)

DEFINE_START_SEMANTIC(KaxTagSimple)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagSimple) // recursive
DEFINE_SEMANTIC_ITEM(true, true, KaxTagName)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagLangue)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagLanguageIETF)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagDefault)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagDefaultBogus)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagString)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagBinary)
DEFINE_END_SEMANTIC(KaxTagSimple)

DEFINE_MKX_MASTER(KaxTagSimple, 0x67C8, 2, KaxTag, false, "TagSimple", VERSION_ALL_MATROSKA)
DEFINE_MKX_UNISTRING(KaxTagName, 0x45A3, 2, KaxTagSimple, "TagName", VERSION_ALL_MATROSKA)
DEFINE_MKX_STRING_DEF(KaxTagLangue, 0x447A, 2, KaxTagSimple, "TagLanguage", VERSION_ALL_MATROSKA, "und")
DEFINE_MKX_STRING(KaxTagLanguageIETF, 0x447B, 2, KaxTagSimple, "TagLanguageIETF", MatroskaProfile(false, false, 4))
DEFINE_MKX_UINTEGER_DEF(KaxTagDefault, 0x4484, 2, KaxTagSimple, "TagDefault", VERSION_ALL_MATROSKA, 1)
DEFINE_MKX_UINTEGER_DEF(KaxTagDefaultBogus, 0x44B4, 2, KaxTagSimple, "TagDefaultBogus", VERSION_DEPRECATED, 1)
DEFINE_MKX_UNISTRING(KaxTagString, 0x4487, 2, KaxTagSimple, "TagString", VERSION_ALL_MATROSKA)
DEFINE_MKX_BINARY (KaxTagBinary, 0x4485, 2, KaxTagSimple, "TagBinary", VERSION_ALL_MATROSKA)

libebml::filepos_t KaxClusterSilentTracks::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxClusterSilentTrackNumber::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxBlockVirtual::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxReferenceVirtual::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxSlices::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTimeSlice::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxSliceLaceNumber::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxSliceFrameNumber::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxSliceBlockAddID::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxSliceDelay::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxSliceDuration::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxReferenceFrame::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxReferenceOffset::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxReferenceTimestamp::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxEncryptedBlock::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTrackMinCache::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTrackMaxCache::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTrackTimestampScale::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTrackOffset::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTrackAttachmentLink::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxCodecSettings::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxCodecInfoURL::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxCodecDownloadURL::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxCodecDecodeAll::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxOldStereoMode::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxVideoAspectRatio::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxVideoGamma::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxVideoFrameRate::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxAudioPosition::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTrickTrackUID::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTrickTrackSegmentUID::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTrickTrackFlag::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTrickMasterTrackUID::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTrickMasterTrackSegmentUID::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxContentSignature::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxContentSigKeyID::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxContentSigAlgo::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxContentSigHashAlgo::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxCueRefCluster::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxCueRefNumber::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxCueRefCodecState::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxFileReferral::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxFileUsedStartTime::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxFileUsedEndTime::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTagDefaultBogus::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, ShouldWrite /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

} // namespace libmatroska
