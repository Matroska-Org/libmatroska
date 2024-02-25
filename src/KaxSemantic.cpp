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

// available in all Matroska/WebM/DivX version
static constexpr const MatroskaProfile VERSION_ALL_MATROSKA = {true, true, 0, MatroskaProfile::ANY_VERSION};
// available in all versions of Matroska but not WebM or DivX
static constexpr const MatroskaProfile VERSION_MATROSKA_ONLY = {false, false, 0};
// not available in any version on Matroska, WebM or DivX
static constexpr const MatroskaProfile VERSION_DEPRECATED   = {false, false, MatroskaProfile::ANY_VERSION, 0};
// element specific to DivX
static constexpr const MatroskaProfile VERSION_DIVX_ONLY    = {false, true, MatroskaProfile::ANY_VERSION, 0};
// available in all Matroska/WebM/DivX since version 2
static constexpr const MatroskaProfile VERSION_SINCE_V2 = {true, true, 2};
// available since version 2 of Matroska but not WebM or DivX
static constexpr const MatroskaProfile VERSION_MATROSKA_SINCE_V2 = {false, false, 2};
// available since version 3 of Matroska but not WebM or DivX
static constexpr const MatroskaProfile VERSION_MATROSKA_SINCE_V3 = {false, false, 3};
// available since version 4 of Matroska but not WebM or DivX
static constexpr const MatroskaProfile VERSION_MATROSKA_SINCE_V4 = {false, false, 4};
// available since version 5 of Matroska but not WebM or DivX
static constexpr const MatroskaProfile VERSION_MATROSKA_SINCE_V5 = {false, false, 5};
// available since version 2 of Matroska and WebM but not DivX
static constexpr const MatroskaProfile VERSION_WEBM_SINCE_V2 = {true, false, 2};
// available since version 3 of Matroska and WebM but not DivX
static constexpr const MatroskaProfile VERSION_WEBM_SINCE_V3 = {true, false, 3};
// available since version 4 of Matroska and WebM but not DivX
static constexpr const MatroskaProfile VERSION_WEBM_SINCE_V4 = {true, false, 4};
// available since version 1 and 2 of Matroska but not WebM or DivX
static constexpr const MatroskaProfile VERSION_MATROSKA_UP_TO_V2 = {false, false, 0, 2};
// available since version 1, 2 and 3 of Matroska but not WebM or DivX
static constexpr const MatroskaProfile VERSION_MATROSKA_UP_TO_V3 = {false, false, 0, 3};
// available since version 1, 2, 3 and 4 of Matroska and WebM but not DivX
static constexpr const MatroskaProfile VERSION_WEBM_UP_TO_V4 = {true, false, 0, 4};

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

DEFINE_MKX_MASTER_ORPHAN(KaxSegment, 0x18538067, true, "Segment", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxSeekHead)
DEFINE_SEMANTIC_ITEM(true, false, KaxSeek)
DEFINE_END_SEMANTIC(KaxSeekHead)

DEFINE_MKX_MASTER(KaxSeekHead, 0x114D9B74, KaxSegment, false, "SeekHeader", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxSeek)
DEFINE_SEMANTIC_ITEM(true, true, KaxSeekID)
DEFINE_SEMANTIC_ITEM(true, true, KaxSeekPosition)
DEFINE_END_SEMANTIC(KaxSeek)

DEFINE_MKX_MASTER(KaxSeek, 0x4DBB, KaxSeekHead, false, "SeekPoint", VERSION_ALL_MATROSKA)
DEFINE_MKX_BINARY (KaxSeekID, 0x53AB, KaxSeek, "SeekID", KaxSeekID::SizeIsValid, VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxSeekPosition, 0x53AC, KaxSeek, "SeekPosition", VERSION_ALL_MATROSKA)

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

DEFINE_MKX_MASTER(KaxInfo, 0x1549A966, KaxSegment, false, "Info", VERSION_ALL_MATROSKA)
DEFINE_MKX_BINARY (KaxSegmentUID, 0x73A4, KaxInfo, "SegmentUID", KaxSegmentUID::SizeIsValid, VERSION_MATROSKA_ONLY)
DEFINE_MKX_UNISTRING(KaxSegmentFilename, 0x7384, KaxInfo, "SegmentFilename", VERSION_MATROSKA_ONLY)
DEFINE_MKX_BINARY (KaxPrevUID, 0x3CB923, KaxInfo, "PrevUID", KaxPrevUID::SizeIsValid, VERSION_MATROSKA_ONLY)
DEFINE_MKX_UNISTRING(KaxPrevFilename, 0x3C83AB, KaxInfo, "PrevFilename", VERSION_MATROSKA_ONLY)
DEFINE_MKX_BINARY (KaxNextUID, 0x3EB923, KaxInfo, "NextUID", KaxNextUID::SizeIsValid, VERSION_MATROSKA_ONLY)
DEFINE_MKX_UNISTRING(KaxNextFilename, 0x3E83BB, KaxInfo, "NextFilename", VERSION_MATROSKA_ONLY)
DEFINE_MKX_BINARY (KaxSegmentFamily, 0x4444, KaxInfo, "SegmentFamily", KaxSegmentFamily::SizeIsValid, VERSION_MATROSKA_ONLY)

DEFINE_START_SEMANTIC(KaxChapterTranslate)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterTranslateID)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterTranslateCodec)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapterTranslateEditionUID)
DEFINE_END_SEMANTIC(KaxChapterTranslate)

DEFINE_MKX_MASTER(KaxChapterTranslate, 0x6924, KaxInfo, false, "ChapterTranslate", VERSION_MATROSKA_ONLY)
DEFINE_MKX_BINARY (KaxChapterTranslateID, 0x69A5, KaxChapterTranslate, "ChapterTranslateID", libebml::EbmlBinary::SizeIsValid, VERSION_MATROSKA_ONLY)
DEFINE_MKX_UINTEGER(KaxChapterTranslateCodec, 0x69BF, KaxChapterTranslate, "ChapterTranslateCodec", VERSION_MATROSKA_ONLY)
DEFINE_MKX_UINTEGER(KaxChapterTranslateEditionUID, 0x69FC, KaxChapterTranslate, "ChapterTranslateEditionUID", VERSION_MATROSKA_ONLY)
DEFINE_MKX_UINTEGER_DEF(KaxTimestampScale, 0x2AD7B1, KaxInfo, "TimestampScale", VERSION_ALL_MATROSKA, 1000000)
DEFINE_MKX_FLOAT(KaxDuration, 0x4489, KaxInfo, "Duration", VERSION_ALL_MATROSKA)
DEFINE_MKX_DATE    (KaxDateUTC, 0x4461, KaxInfo, "DateUTC", VERSION_ALL_MATROSKA)
DEFINE_MKX_UNISTRING(KaxTitle, 0x7BA9, KaxInfo, "Title", VERSION_ALL_MATROSKA)
DEFINE_MKX_UNISTRING(KaxMuxingApp, 0x4D80, KaxInfo, "MuxingApp", VERSION_ALL_MATROSKA)
DEFINE_MKX_UNISTRING(KaxWritingApp, 0x5741, KaxInfo, "WritingApp", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxCluster)
DEFINE_SEMANTIC_ITEM(true, true, KaxClusterTimestamp)
DEFINE_SEMANTIC_ITEM(false, true, KaxClusterSilentTracks)
DEFINE_SEMANTIC_ITEM(false, true, KaxClusterPosition)
DEFINE_SEMANTIC_ITEM(false, true, KaxClusterPrevSize)
DEFINE_SEMANTIC_ITEM(false, false, KaxSimpleBlock)
DEFINE_SEMANTIC_ITEM(false, false, KaxBlockGroup)
DEFINE_SEMANTIC_ITEM(false, false, KaxEncryptedBlock)
DEFINE_END_SEMANTIC(KaxCluster)

DEFINE_MKX_MASTER_CONS(KaxCluster, 0x1F43B675, KaxSegment, true, "Cluster", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxClusterTimestamp, 0xE7, KaxCluster, "ClusterTimestamp", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxClusterSilentTracks)
DEFINE_SEMANTIC_ITEM(false, false, KaxClusterSilentTrackNumber)
DEFINE_END_SEMANTIC(KaxClusterSilentTracks)

DEFINE_MKX_MASTER(KaxClusterSilentTracks, 0x5854, KaxCluster, false, "ClusterSilentTracks", VERSION_DEPRECATED)
DEFINE_MKX_UINTEGER(KaxClusterSilentTrackNumber, 0x58D7, KaxClusterSilentTracks, "ClusterSilentTrackNumber", VERSION_DEPRECATED)
DEFINE_MKX_UINTEGER(KaxClusterPosition, 0xA7, KaxCluster, "ClusterPosition", VERSION_WEBM_UP_TO_V4)
DEFINE_MKX_UINTEGER(KaxClusterPrevSize, 0xAB, KaxCluster, "ClusterPrevSize", VERSION_ALL_MATROSKA)
DEFINE_MKX_BINARY_CONS(KaxSimpleBlock, 0xA3, KaxCluster, "SimpleBlock", KaxInternalBlock::SizeIsValid, VERSION_SINCE_V2)

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

DEFINE_MKX_MASTER_CONS(KaxBlockGroup, 0xA0, KaxCluster, false, "BlockGroup", VERSION_ALL_MATROSKA)
DEFINE_MKX_BINARY_CONS(KaxBlock, 0xA1, KaxBlockGroup, "Block", KaxInternalBlock::SizeIsValid, VERSION_ALL_MATROSKA)
DEFINE_MKX_BINARY_CONS(KaxBlockVirtual, 0xA2, KaxBlockGroup, "BlockVirtual", KaxInternalBlock::SizeIsValid, VERSION_DEPRECATED)

DEFINE_START_SEMANTIC(KaxBlockAdditions)
DEFINE_SEMANTIC_ITEM(true, false, KaxBlockMore)
DEFINE_END_SEMANTIC(KaxBlockAdditions)

DEFINE_MKX_MASTER(KaxBlockAdditions, 0x75A1, KaxBlockGroup, false, "BlockAdditions", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxBlockMore)
DEFINE_SEMANTIC_ITEM(true, true, KaxBlockAdditional)
DEFINE_SEMANTIC_ITEM(true, true, KaxBlockAddID)
DEFINE_END_SEMANTIC(KaxBlockMore)

DEFINE_MKX_MASTER(KaxBlockMore, 0xA6, KaxBlockAdditions, false, "BlockMore", VERSION_ALL_MATROSKA)
DEFINE_MKX_BINARY (KaxBlockAdditional, 0xA5, KaxBlockMore, "BlockAdditional", libebml::EbmlBinary::SizeIsValid, VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxBlockAddID, 0xEE, KaxBlockMore, "BlockAddID", VERSION_ALL_MATROSKA, 1)
DEFINE_MKX_UINTEGER(KaxBlockDuration, 0x9B, KaxBlockGroup, "BlockDuration", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxReferencePriority, 0xFA, KaxBlockGroup, "FlagReferenced", VERSION_MATROSKA_ONLY, 0)
DEFINE_MKX_SINTEGER_CONS(KaxReferenceBlock, 0xFB, KaxBlockGroup, "ReferenceBlock", VERSION_ALL_MATROSKA)
DEFINE_MKX_SINTEGER(KaxReferenceVirtual, 0xFD, KaxBlockGroup, "ReferenceVirtual", VERSION_DEPRECATED)
DEFINE_MKX_BINARY (KaxCodecState, 0xA4, KaxBlockGroup, "CodecState", libebml::EbmlBinary::SizeIsValid, VERSION_MATROSKA_SINCE_V2)
DEFINE_MKX_SINTEGER(KaxDiscardPadding, 0x75A2, KaxBlockGroup, "DiscardPadding", VERSION_WEBM_SINCE_V4)

DEFINE_START_SEMANTIC(KaxSlices)
DEFINE_SEMANTIC_ITEM(false, false, KaxTimeSlice)
DEFINE_END_SEMANTIC(KaxSlices)

DEFINE_MKX_MASTER(KaxSlices, 0x8E, KaxBlockGroup, false, "Slices", VERSION_DEPRECATED)

DEFINE_START_SEMANTIC(KaxTimeSlice)
DEFINE_SEMANTIC_ITEM(false, true, KaxSliceLaceNumber)
DEFINE_SEMANTIC_ITEM(false, true, KaxSliceFrameNumber)
DEFINE_SEMANTIC_ITEM(false, true, KaxSliceBlockAddID)
DEFINE_SEMANTIC_ITEM(false, true, KaxSliceDelay)
DEFINE_SEMANTIC_ITEM(false, true, KaxSliceDuration)
DEFINE_END_SEMANTIC(KaxTimeSlice)

DEFINE_MKX_MASTER(KaxTimeSlice, 0xE8, KaxSlices, false, "TimeSlice", VERSION_DEPRECATED)
DEFINE_MKX_UINTEGER(KaxSliceLaceNumber, 0xCC, KaxTimeSlice, "SliceLaceNumber", VERSION_DEPRECATED)
DEFINE_MKX_UINTEGER_DEF(KaxSliceFrameNumber, 0xCD, KaxTimeSlice, "SliceFrameNumber", VERSION_DEPRECATED, 0)
DEFINE_MKX_UINTEGER_DEF(KaxSliceBlockAddID, 0xCB, KaxTimeSlice, "SliceBlockAddID", VERSION_DEPRECATED, 0)
DEFINE_MKX_UINTEGER_DEF(KaxSliceDelay, 0xCE, KaxTimeSlice, "SliceDelay", VERSION_DEPRECATED, 0)
DEFINE_MKX_UINTEGER_DEF(KaxSliceDuration, 0xCF, KaxTimeSlice, "SliceDuration", VERSION_DEPRECATED, 0)

DEFINE_START_SEMANTIC(KaxReferenceFrame)
DEFINE_SEMANTIC_ITEM(true, true, KaxReferenceOffset)
DEFINE_SEMANTIC_ITEM(true, true, KaxReferenceTimestamp)
DEFINE_END_SEMANTIC(KaxReferenceFrame)

DEFINE_MKX_MASTER(KaxReferenceFrame, 0xC8, KaxBlockGroup, false, "ReferenceFrame", VERSION_DIVX_ONLY)
DEFINE_MKX_UINTEGER(KaxReferenceOffset, 0xC9, KaxReferenceFrame, "ReferenceOffset", VERSION_DIVX_ONLY)
DEFINE_MKX_UINTEGER(KaxReferenceTimestamp, 0xCA, KaxReferenceFrame, "ReferenceTimestamp", VERSION_DIVX_ONLY)
DEFINE_MKX_BINARY (KaxEncryptedBlock, 0xAF, KaxCluster, "EncryptedBlock", libebml::EbmlBinary::SizeIsValid, VERSION_DEPRECATED)

DEFINE_START_SEMANTIC(KaxTracks)
DEFINE_SEMANTIC_ITEM(true, false, KaxTrackEntry)
DEFINE_END_SEMANTIC(KaxTracks)

DEFINE_MKX_MASTER(KaxTracks, 0x1654AE6B, KaxSegment, false, "Tracks", VERSION_ALL_MATROSKA)

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

DEFINE_MKX_MASTER(KaxTrackEntry, 0xAE, KaxTracks, false, "TrackEntry", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxTrackNumber, 0xD7, KaxTrackEntry, "TrackNumber", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxTrackUID, 0x73C5, KaxTrackEntry, "TrackUID", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxTrackType, 0x83, KaxTrackEntry, "TrackType", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxTrackFlagEnabled, 0xB9, KaxTrackEntry, "TrackFlagEnabled", VERSION_WEBM_SINCE_V3, 1)
DEFINE_MKX_UINTEGER_DEF(KaxTrackFlagDefault, 0x88, KaxTrackEntry, "TrackFlagDefault", VERSION_ALL_MATROSKA, 1)
DEFINE_MKX_UINTEGER_DEF(KaxTrackFlagForced, 0x55AA, KaxTrackEntry, "TrackFlagForced", VERSION_ALL_MATROSKA, 0)
DEFINE_MKX_UINTEGER(KaxFlagHearingImpaired, 0x55AB, KaxTrackEntry, "FlagHearingImpaired", VERSION_MATROSKA_SINCE_V4)
DEFINE_MKX_UINTEGER(KaxFlagVisualImpaired, 0x55AC, KaxTrackEntry, "FlagVisualImpaired", VERSION_MATROSKA_SINCE_V4)
DEFINE_MKX_UINTEGER(KaxFlagTextDescriptions, 0x55AD, KaxTrackEntry, "FlagTextDescriptions", VERSION_MATROSKA_SINCE_V4)
DEFINE_MKX_UINTEGER(KaxFlagOriginal, 0x55AE, KaxTrackEntry, "FlagOriginal", VERSION_MATROSKA_SINCE_V4)
DEFINE_MKX_UINTEGER(KaxFlagCommentary, 0x55AF, KaxTrackEntry, "FlagCommentary", VERSION_MATROSKA_SINCE_V4)
DEFINE_MKX_UINTEGER_DEF(KaxTrackFlagLacing, 0x9C, KaxTrackEntry, "TrackFlagLacing", VERSION_ALL_MATROSKA, 1)
DEFINE_MKX_UINTEGER_DEF(KaxTrackMinCache, 0x6DE7, KaxTrackEntry, "TrackMinCache", VERSION_DEPRECATED, 0)
DEFINE_MKX_UINTEGER(KaxTrackMaxCache, 0x6DF8, KaxTrackEntry, "TrackMaxCache", VERSION_DEPRECATED)
DEFINE_MKX_UINTEGER(KaxTrackDefaultDuration, 0x23E383, KaxTrackEntry, "TrackDefaultDuration", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxTrackDefaultDecodedFieldDuration, 0x234E7A, KaxTrackEntry, "TrackDefaultDecodedFieldDuration", VERSION_MATROSKA_SINCE_V4)
DEFINE_MKX_FLOAT_DEF(KaxTrackTimestampScale, 0x23314F, KaxTrackEntry, "TrackTimestampScale", VERSION_MATROSKA_UP_TO_V3, 1)
DEFINE_MKX_SINTEGER_DEF(KaxTrackOffset, 0x537F, KaxTrackEntry, "TrackOffset", VERSION_DEPRECATED, 0)
DEFINE_MKX_UINTEGER_DEF(KaxMaxBlockAdditionID, 0x55EE, KaxTrackEntry, "MaxBlockAdditionID", VERSION_MATROSKA_ONLY, 0)

DEFINE_START_SEMANTIC(KaxBlockAdditionMapping)
DEFINE_SEMANTIC_ITEM(false, true, KaxBlockAddIDValue)
DEFINE_SEMANTIC_ITEM(false, true, KaxBlockAddIDName)
DEFINE_SEMANTIC_ITEM(true, true, KaxBlockAddIDType)
DEFINE_SEMANTIC_ITEM(false, true, KaxBlockAddIDExtraData)
DEFINE_END_SEMANTIC(KaxBlockAdditionMapping)

DEFINE_MKX_MASTER(KaxBlockAdditionMapping, 0x41E4, KaxTrackEntry, false, "BlockAdditionMapping", VERSION_MATROSKA_SINCE_V4)
DEFINE_MKX_UINTEGER(KaxBlockAddIDValue, 0x41F0, KaxBlockAdditionMapping, "BlockAddIDValue", VERSION_MATROSKA_SINCE_V4)
DEFINE_MKX_STRING(KaxBlockAddIDName, 0x41A4, KaxBlockAdditionMapping, "BlockAddIDName", VERSION_MATROSKA_SINCE_V4)
DEFINE_MKX_UINTEGER_DEF(KaxBlockAddIDType, 0x41E7, KaxBlockAdditionMapping, "BlockAddIDType", VERSION_MATROSKA_SINCE_V4, 0)
DEFINE_MKX_BINARY (KaxBlockAddIDExtraData, 0x41ED, KaxBlockAdditionMapping, "BlockAddIDExtraData", libebml::EbmlBinary::SizeIsValid, VERSION_MATROSKA_SINCE_V4)
DEFINE_MKX_UNISTRING(KaxTrackName, 0x536E, KaxTrackEntry, "TrackName", VERSION_ALL_MATROSKA)
DEFINE_MKX_STRING_DEF(KaxTrackLanguage, 0x22B59C, KaxTrackEntry, "TrackLanguage", VERSION_ALL_MATROSKA, "eng")
DEFINE_MKX_STRING(KaxLanguageIETF, 0x22B59D, KaxTrackEntry, "LanguageIETF", VERSION_MATROSKA_SINCE_V4)
DEFINE_MKX_STRING(KaxCodecID, 0x86, KaxTrackEntry, "CodecID", VERSION_ALL_MATROSKA)
DEFINE_MKX_BINARY (KaxCodecPrivate, 0x63A2, KaxTrackEntry, "CodecPrivate", libebml::EbmlBinary::SizeIsValid, VERSION_ALL_MATROSKA)
DEFINE_MKX_UNISTRING(KaxCodecName, 0x258688, KaxTrackEntry, "CodecName", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxTrackAttachmentLink, 0x7446, KaxTrackEntry, "TrackAttachmentLink", VERSION_MATROSKA_UP_TO_V3)
DEFINE_MKX_UNISTRING(KaxCodecSettings, 0x3A9697, KaxTrackEntry, "CodecSettings", VERSION_DEPRECATED)
DEFINE_MKX_STRING(KaxCodecInfoURL, 0x3B4040, KaxTrackEntry, "CodecInfoURL", VERSION_DEPRECATED)
DEFINE_MKX_STRING(KaxCodecDownloadURL, 0x26B240, KaxTrackEntry, "CodecDownloadURL", VERSION_DEPRECATED)
DEFINE_MKX_UINTEGER_DEF(KaxCodecDecodeAll, 0xAA, KaxTrackEntry, "CodecDecodeAll", VERSION_DEPRECATED, 1)
DEFINE_MKX_UINTEGER(KaxTrackOverlay, 0x6FAB, KaxTrackEntry, "TrackOverlay", VERSION_DEPRECATED)
DEFINE_MKX_UINTEGER_DEF(KaxCodecDelay, 0x56AA, KaxTrackEntry, "CodecDelay", VERSION_WEBM_SINCE_V4, 0)
DEFINE_MKX_UINTEGER_DEF(KaxSeekPreRoll, 0x56BB, KaxTrackEntry, "SeekPreRoll", VERSION_WEBM_SINCE_V4, 0)

DEFINE_START_SEMANTIC(KaxTrackTranslate)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackTranslateTrackID)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackTranslateCodec)
DEFINE_SEMANTIC_ITEM(false, false, KaxTrackTranslateEditionUID)
DEFINE_END_SEMANTIC(KaxTrackTranslate)

DEFINE_MKX_MASTER(KaxTrackTranslate, 0x6624, KaxTrackEntry, false, "TrackTranslate", VERSION_MATROSKA_ONLY)
DEFINE_MKX_BINARY (KaxTrackTranslateTrackID, 0x66A5, KaxTrackTranslate, "TrackTranslateTrackID", libebml::EbmlBinary::SizeIsValid, VERSION_MATROSKA_ONLY)
DEFINE_MKX_UINTEGER(KaxTrackTranslateCodec, 0x66BF, KaxTrackTranslate, "TrackTranslateCodec", VERSION_MATROSKA_ONLY)
DEFINE_MKX_UINTEGER(KaxTrackTranslateEditionUID, 0x66FC, KaxTrackTranslate, "TrackTranslateEditionUID", VERSION_MATROSKA_ONLY)

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

DEFINE_MKX_MASTER(KaxTrackVideo, 0xE0, KaxTrackEntry, false, "TrackVideo", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxVideoFlagInterlaced, 0x9A, KaxTrackVideo, "VideoFlagInterlaced", VERSION_WEBM_SINCE_V3, 0)
DEFINE_MKX_UINTEGER_DEF(KaxVideoFieldOrder, 0x9D, KaxTrackVideo, "VideoFieldOrder", VERSION_MATROSKA_SINCE_V4, 2)
DEFINE_MKX_UINTEGER_DEF(KaxVideoStereoMode, 0x53B8, KaxTrackVideo, "VideoStereoMode", VERSION_WEBM_SINCE_V2, 0)
DEFINE_MKX_UINTEGER_DEF(KaxVideoAlphaMode, 0x53C0, KaxTrackVideo, "VideoAlphaMode", VERSION_WEBM_SINCE_V2, 0)
DEFINE_MKX_UINTEGER(KaxOldStereoMode, 0x53B9, KaxTrackVideo, "OldStereoMode", VERSION_MATROSKA_UP_TO_V2)
DEFINE_MKX_UINTEGER(KaxVideoPixelWidth, 0xB0, KaxTrackVideo, "VideoPixelWidth", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxVideoPixelHeight, 0xBA, KaxTrackVideo, "VideoPixelHeight", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxVideoPixelCropBottom, 0x54AA, KaxTrackVideo, "VideoPixelCropBottom", VERSION_ALL_MATROSKA, 0)
DEFINE_MKX_UINTEGER_DEF(KaxVideoPixelCropTop, 0x54BB, KaxTrackVideo, "VideoPixelCropTop", VERSION_ALL_MATROSKA, 0)
DEFINE_MKX_UINTEGER_DEF(KaxVideoPixelCropLeft, 0x54CC, KaxTrackVideo, "VideoPixelCropLeft", VERSION_ALL_MATROSKA, 0)
DEFINE_MKX_UINTEGER_DEF(KaxVideoPixelCropRight, 0x54DD, KaxTrackVideo, "VideoPixelCropRight", VERSION_ALL_MATROSKA, 0)
DEFINE_MKX_UINTEGER(KaxVideoDisplayWidth, 0x54B0, KaxTrackVideo, "VideoDisplayWidth", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxVideoDisplayHeight, 0x54BA, KaxTrackVideo, "VideoDisplayHeight", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxVideoDisplayUnit, 0x54B2, KaxTrackVideo, "VideoDisplayUnit", VERSION_ALL_MATROSKA, 0)
DEFINE_MKX_UINTEGER_DEF(KaxVideoAspectRatio, 0x54B3, KaxTrackVideo, "VideoAspectRatio", VERSION_DEPRECATED, 0)
DEFINE_MKX_BINARY (KaxVideoColourSpace, 0x2EB524, KaxTrackVideo, "VideoColourSpace", KaxVideoColourSpace::SizeIsValid, VERSION_MATROSKA_ONLY)
DEFINE_MKX_FLOAT(KaxVideoGamma, 0x2FB523, KaxTrackVideo, "VideoGamma", VERSION_DEPRECATED)
DEFINE_MKX_FLOAT(KaxVideoFrameRate, 0x2383E3, KaxTrackVideo, "VideoFrameRate", VERSION_DEPRECATED)

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

DEFINE_MKX_MASTER(KaxVideoColour, 0x55B0, KaxTrackVideo, false, "VideoColour", VERSION_WEBM_SINCE_V4)
DEFINE_MKX_UINTEGER_DEF(KaxVideoColourMatrix, 0x55B1, KaxVideoColour, "VideoColourMatrix", VERSION_WEBM_SINCE_V4, 2)
DEFINE_MKX_UINTEGER_DEF(KaxVideoBitsPerChannel, 0x55B2, KaxVideoColour, "VideoBitsPerChannel", VERSION_WEBM_SINCE_V4, 0)
DEFINE_MKX_UINTEGER(KaxVideoChromaSubsampHorz, 0x55B3, KaxVideoColour, "VideoChromaSubsampHorz", VERSION_WEBM_SINCE_V4)
DEFINE_MKX_UINTEGER(KaxVideoChromaSubsampVert, 0x55B4, KaxVideoColour, "VideoChromaSubsampVert", VERSION_WEBM_SINCE_V4)
DEFINE_MKX_UINTEGER(KaxVideoCbSubsampHorz, 0x55B5, KaxVideoColour, "VideoCbSubsampHorz", VERSION_WEBM_SINCE_V4)
DEFINE_MKX_UINTEGER(KaxVideoCbSubsampVert, 0x55B6, KaxVideoColour, "VideoCbSubsampVert", VERSION_WEBM_SINCE_V4)
DEFINE_MKX_UINTEGER_DEF(KaxVideoChromaSitHorz, 0x55B7, KaxVideoColour, "VideoChromaSitHorz", VERSION_WEBM_SINCE_V4, 0)
DEFINE_MKX_UINTEGER_DEF(KaxVideoChromaSitVert, 0x55B8, KaxVideoColour, "VideoChromaSitVert", VERSION_WEBM_SINCE_V4, 0)
DEFINE_MKX_UINTEGER_DEF(KaxVideoColourRange, 0x55B9, KaxVideoColour, "VideoColourRange", VERSION_WEBM_SINCE_V4, 0)
DEFINE_MKX_UINTEGER_DEF(KaxVideoColourTransferCharacter, 0x55BA, KaxVideoColour, "VideoColourTransferCharacter", VERSION_WEBM_SINCE_V4, 2)
DEFINE_MKX_UINTEGER_DEF(KaxVideoColourPrimaries, 0x55BB, KaxVideoColour, "VideoColourPrimaries", VERSION_WEBM_SINCE_V4, 2)
DEFINE_MKX_UINTEGER(KaxVideoColourMaxCLL, 0x55BC, KaxVideoColour, "VideoColourMaxCLL", VERSION_WEBM_SINCE_V4)
DEFINE_MKX_UINTEGER(KaxVideoColourMaxFALL, 0x55BD, KaxVideoColour, "VideoColourMaxFALL", VERSION_WEBM_SINCE_V4)

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

DEFINE_MKX_MASTER(KaxVideoColourMasterMeta, 0x55D0, KaxVideoColour, false, "VideoColourMasterMeta", VERSION_WEBM_SINCE_V4)
DEFINE_MKX_FLOAT(KaxVideoRChromaX, 0x55D1, KaxVideoColourMasterMeta, "VideoRChromaX", VERSION_WEBM_SINCE_V4)
DEFINE_MKX_FLOAT(KaxVideoRChromaY, 0x55D2, KaxVideoColourMasterMeta, "VideoRChromaY", VERSION_WEBM_SINCE_V4)
DEFINE_MKX_FLOAT(KaxVideoGChromaX, 0x55D3, KaxVideoColourMasterMeta, "VideoGChromaX", VERSION_WEBM_SINCE_V4)
DEFINE_MKX_FLOAT(KaxVideoGChromaY, 0x55D4, KaxVideoColourMasterMeta, "VideoGChromaY", VERSION_WEBM_SINCE_V4)
DEFINE_MKX_FLOAT(KaxVideoBChromaX, 0x55D5, KaxVideoColourMasterMeta, "VideoBChromaX", VERSION_WEBM_SINCE_V4)
DEFINE_MKX_FLOAT(KaxVideoBChromaY, 0x55D6, KaxVideoColourMasterMeta, "VideoBChromaY", VERSION_WEBM_SINCE_V4)
DEFINE_MKX_FLOAT(KaxVideoWhitePointChromaX, 0x55D7, KaxVideoColourMasterMeta, "VideoWhitePointChromaX", VERSION_WEBM_SINCE_V4)
DEFINE_MKX_FLOAT(KaxVideoWhitePointChromaY, 0x55D8, KaxVideoColourMasterMeta, "VideoWhitePointChromaY", VERSION_WEBM_SINCE_V4)
DEFINE_MKX_FLOAT(KaxVideoLuminanceMax, 0x55D9, KaxVideoColourMasterMeta, "VideoLuminanceMax", VERSION_WEBM_SINCE_V4)
DEFINE_MKX_FLOAT(KaxVideoLuminanceMin, 0x55DA, KaxVideoColourMasterMeta, "VideoLuminanceMin", VERSION_WEBM_SINCE_V4)

DEFINE_START_SEMANTIC(KaxVideoProjection)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoProjectionType)
DEFINE_SEMANTIC_ITEM(false, true, KaxVideoProjectionPrivate)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoProjectionPoseYaw)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoProjectionPosePitch)
DEFINE_SEMANTIC_ITEM(true, true, KaxVideoProjectionPoseRoll)
DEFINE_END_SEMANTIC(KaxVideoProjection)

DEFINE_MKX_MASTER(KaxVideoProjection, 0x7670, KaxTrackVideo, false, "VideoProjection", VERSION_WEBM_SINCE_V4)
DEFINE_MKX_UINTEGER_DEF(KaxVideoProjectionType, 0x7671, KaxVideoProjection, "VideoProjectionType", VERSION_WEBM_SINCE_V4, 0)
DEFINE_MKX_BINARY (KaxVideoProjectionPrivate, 0x7672, KaxVideoProjection, "VideoProjectionPrivate", libebml::EbmlBinary::SizeIsValid, VERSION_WEBM_SINCE_V4)
DEFINE_MKX_FLOAT_DEF(KaxVideoProjectionPoseYaw, 0x7673, KaxVideoProjection, "VideoProjectionPoseYaw", VERSION_WEBM_SINCE_V4, 0)
DEFINE_MKX_FLOAT_DEF(KaxVideoProjectionPosePitch, 0x7674, KaxVideoProjection, "VideoProjectionPosePitch", VERSION_WEBM_SINCE_V4, 0)
DEFINE_MKX_FLOAT_DEF(KaxVideoProjectionPoseRoll, 0x7675, KaxVideoProjection, "VideoProjectionPoseRoll", VERSION_WEBM_SINCE_V4, 0)

DEFINE_START_SEMANTIC(KaxTrackAudio)
DEFINE_SEMANTIC_ITEM(true, true, KaxAudioSamplingFreq)
DEFINE_SEMANTIC_ITEM(false, true, KaxAudioOutputSamplingFreq)
DEFINE_SEMANTIC_ITEM(true, true, KaxAudioChannels)
DEFINE_SEMANTIC_ITEM(false, true, KaxAudioPosition)
DEFINE_SEMANTIC_ITEM(false, true, KaxAudioBitDepth)
DEFINE_SEMANTIC_ITEM(true, true, KaxEmphasis)
DEFINE_END_SEMANTIC(KaxTrackAudio)

DEFINE_MKX_MASTER(KaxTrackAudio, 0xE1, KaxTrackEntry, false, "TrackAudio", VERSION_ALL_MATROSKA)
DEFINE_MKX_FLOAT_DEF(KaxAudioSamplingFreq, 0xB5, KaxTrackAudio, "AudioSamplingFreq", VERSION_ALL_MATROSKA, 8000)
DEFINE_MKX_FLOAT(KaxAudioOutputSamplingFreq, 0x78B5, KaxTrackAudio, "AudioOutputSamplingFreq", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxAudioChannels, 0x9F, KaxTrackAudio, "AudioChannels", VERSION_ALL_MATROSKA, 1)
DEFINE_MKX_BINARY (KaxAudioPosition, 0x7D7B, KaxTrackAudio, "AudioPosition", libebml::EbmlBinary::SizeIsValid, VERSION_DEPRECATED)
DEFINE_MKX_UINTEGER(KaxAudioBitDepth, 0x6264, KaxTrackAudio, "AudioBitDepth", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxEmphasis, 0x52F1, KaxTrackAudio, "Emphasis", VERSION_MATROSKA_SINCE_V5, 0)

DEFINE_START_SEMANTIC(KaxTrackOperation)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackCombinePlanes)
DEFINE_SEMANTIC_ITEM(false, true, KaxTrackJoinBlocks)
DEFINE_END_SEMANTIC(KaxTrackOperation)

DEFINE_MKX_MASTER(KaxTrackOperation, 0xE2, KaxTrackEntry, false, "TrackOperation", VERSION_MATROSKA_SINCE_V3)

DEFINE_START_SEMANTIC(KaxTrackCombinePlanes)
DEFINE_SEMANTIC_ITEM(true, false, KaxTrackPlane)
DEFINE_END_SEMANTIC(KaxTrackCombinePlanes)

DEFINE_MKX_MASTER(KaxTrackCombinePlanes, 0xE3, KaxTrackOperation, false, "TrackCombinePlanes", VERSION_MATROSKA_SINCE_V3)

DEFINE_START_SEMANTIC(KaxTrackPlane)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackPlaneUID)
DEFINE_SEMANTIC_ITEM(true, true, KaxTrackPlaneType)
DEFINE_END_SEMANTIC(KaxTrackPlane)

DEFINE_MKX_MASTER(KaxTrackPlane, 0xE4, KaxTrackCombinePlanes, false, "TrackPlane", VERSION_MATROSKA_SINCE_V3)
DEFINE_MKX_UINTEGER(KaxTrackPlaneUID, 0xE5, KaxTrackPlane, "TrackPlaneUID", VERSION_MATROSKA_SINCE_V3)
DEFINE_MKX_UINTEGER(KaxTrackPlaneType, 0xE6, KaxTrackPlane, "TrackPlaneType", VERSION_MATROSKA_SINCE_V3)

DEFINE_START_SEMANTIC(KaxTrackJoinBlocks)
DEFINE_SEMANTIC_ITEM(true, false, KaxTrackJoinUID)
DEFINE_END_SEMANTIC(KaxTrackJoinBlocks)

DEFINE_MKX_MASTER(KaxTrackJoinBlocks, 0xE9, KaxTrackOperation, false, "TrackJoinBlocks", VERSION_MATROSKA_SINCE_V3)
DEFINE_MKX_UINTEGER(KaxTrackJoinUID, 0xED, KaxTrackJoinBlocks, "TrackJoinUID", VERSION_MATROSKA_SINCE_V3)
DEFINE_MKX_UINTEGER(KaxTrickTrackUID, 0xC0, KaxTrackEntry, "TrickTrackUID", VERSION_DIVX_ONLY)
DEFINE_MKX_BINARY (KaxTrickTrackSegmentUID, 0xC1, KaxTrackEntry, "TrickTrackSegmentUID", KaxTrickTrackSegmentUID::SizeIsValid, VERSION_DIVX_ONLY)
DEFINE_MKX_UINTEGER_DEF(KaxTrickTrackFlag, 0xC6, KaxTrackEntry, "TrickTrackFlag", VERSION_DIVX_ONLY, 0)
DEFINE_MKX_UINTEGER(KaxTrickMasterTrackUID, 0xC7, KaxTrackEntry, "TrickMasterTrackUID", VERSION_DIVX_ONLY)
DEFINE_MKX_BINARY (KaxTrickMasterTrackSegmentUID, 0xC4, KaxTrackEntry, "TrickMasterTrackSegmentUID", KaxTrickMasterTrackSegmentUID::SizeIsValid, VERSION_DIVX_ONLY)

DEFINE_START_SEMANTIC(KaxContentEncodings)
DEFINE_SEMANTIC_ITEM(true, false, KaxContentEncoding)
DEFINE_END_SEMANTIC(KaxContentEncodings)

DEFINE_MKX_MASTER(KaxContentEncodings, 0x6D80, KaxTrackEntry, false, "ContentEncodings", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxContentEncoding)
DEFINE_SEMANTIC_ITEM(true, true, KaxContentEncodingOrder)
DEFINE_SEMANTIC_ITEM(true, true, KaxContentEncodingScope)
DEFINE_SEMANTIC_ITEM(true, true, KaxContentEncodingType)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentCompression)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentEncryption)
DEFINE_END_SEMANTIC(KaxContentEncoding)

DEFINE_MKX_MASTER(KaxContentEncoding, 0x6240, KaxContentEncodings, false, "ContentEncoding", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxContentEncodingOrder, 0x5031, KaxContentEncoding, "ContentEncodingOrder", VERSION_ALL_MATROSKA, 0)
DEFINE_MKX_UINTEGER_DEF(KaxContentEncodingScope, 0x5032, KaxContentEncoding, "ContentEncodingScope", VERSION_ALL_MATROSKA, 1)
DEFINE_MKX_UINTEGER_DEF(KaxContentEncodingType, 0x5033, KaxContentEncoding, "ContentEncodingType", VERSION_ALL_MATROSKA, 0)

DEFINE_START_SEMANTIC(KaxContentCompression)
DEFINE_SEMANTIC_ITEM(true, true, KaxContentCompAlgo)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentCompSettings)
DEFINE_END_SEMANTIC(KaxContentCompression)

DEFINE_MKX_MASTER(KaxContentCompression, 0x5034, KaxContentEncoding, false, "ContentCompression", VERSION_MATROSKA_ONLY)
DEFINE_MKX_UINTEGER_DEF(KaxContentCompAlgo, 0x4254, KaxContentCompression, "ContentCompAlgo", VERSION_MATROSKA_ONLY, 0)
DEFINE_MKX_BINARY (KaxContentCompSettings, 0x4255, KaxContentCompression, "ContentCompSettings", libebml::EbmlBinary::SizeIsValid, VERSION_MATROSKA_ONLY)

DEFINE_START_SEMANTIC(KaxContentEncryption)
DEFINE_SEMANTIC_ITEM(true, true, KaxContentEncAlgo)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentEncKeyID)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentEncAESSettings)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentSignature)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentSigKeyID)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentSigAlgo)
DEFINE_SEMANTIC_ITEM(false, true, KaxContentSigHashAlgo)
DEFINE_END_SEMANTIC(KaxContentEncryption)

DEFINE_MKX_MASTER(KaxContentEncryption, 0x5035, KaxContentEncoding, false, "ContentEncryption", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxContentEncAlgo, 0x47E1, KaxContentEncryption, "ContentEncAlgo", VERSION_ALL_MATROSKA, 0)
DEFINE_MKX_BINARY (KaxContentEncKeyID, 0x47E2, KaxContentEncryption, "ContentEncKeyID", libebml::EbmlBinary::SizeIsValid, VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxContentEncAESSettings)
DEFINE_SEMANTIC_ITEM(true, true, KaxAESSettingsCipherMode)
DEFINE_END_SEMANTIC(KaxContentEncAESSettings)

DEFINE_MKX_MASTER(KaxContentEncAESSettings, 0x47E7, KaxContentEncryption, false, "ContentEncAESSettings", VERSION_WEBM_SINCE_V4)
DEFINE_MKX_UINTEGER(KaxAESSettingsCipherMode, 0x47E8, KaxContentEncAESSettings, "AESSettingsCipherMode", VERSION_WEBM_SINCE_V4)
DEFINE_MKX_BINARY (KaxContentSignature, 0x47E3, KaxContentEncryption, "ContentSignature", libebml::EbmlBinary::SizeIsValid, VERSION_DEPRECATED)
DEFINE_MKX_BINARY (KaxContentSigKeyID, 0x47E4, KaxContentEncryption, "ContentSigKeyID", libebml::EbmlBinary::SizeIsValid, VERSION_DEPRECATED)
DEFINE_MKX_UINTEGER_DEF(KaxContentSigAlgo, 0x47E5, KaxContentEncryption, "ContentSigAlgo", VERSION_DEPRECATED, 0)
DEFINE_MKX_UINTEGER_DEF(KaxContentSigHashAlgo, 0x47E6, KaxContentEncryption, "ContentSigHashAlgo", VERSION_DEPRECATED, 0)

DEFINE_START_SEMANTIC(KaxCues)
DEFINE_SEMANTIC_ITEM(true, false, KaxCuePoint)
DEFINE_END_SEMANTIC(KaxCues)

DEFINE_MKX_MASTER(KaxCues, 0x1C53BB6B, KaxSegment, false, "Cues", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxCuePoint)
DEFINE_SEMANTIC_ITEM(true, true, KaxCueTime)
DEFINE_SEMANTIC_ITEM(true, false, KaxCueTrackPositions)
DEFINE_END_SEMANTIC(KaxCuePoint)

DEFINE_MKX_MASTER(KaxCuePoint, 0xBB, KaxCues, false, "CuePoint", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxCueTime, 0xB3, KaxCuePoint, "CueTime", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxCueTrackPositions)
DEFINE_SEMANTIC_ITEM(true, true, KaxCueTrack)
DEFINE_SEMANTIC_ITEM(true, true, KaxCueClusterPosition)
DEFINE_SEMANTIC_ITEM(false, true, KaxCueRelativePosition)
DEFINE_SEMANTIC_ITEM(false, true, KaxCueDuration)
DEFINE_SEMANTIC_ITEM(false, true, KaxCueBlockNumber)
DEFINE_SEMANTIC_ITEM(true, true, KaxCueCodecState)
DEFINE_SEMANTIC_ITEM(false, false, KaxCueReference)
DEFINE_END_SEMANTIC(KaxCueTrackPositions)

DEFINE_MKX_MASTER(KaxCueTrackPositions, 0xB7, KaxCuePoint, false, "CueTrackPositions", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxCueTrack, 0xF7, KaxCueTrackPositions, "CueTrack", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxCueClusterPosition, 0xF1, KaxCueTrackPositions, "CueClusterPosition", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxCueRelativePosition, 0xF0, KaxCueTrackPositions, "CueRelativePosition", VERSION_WEBM_SINCE_V4)
DEFINE_MKX_UINTEGER(KaxCueDuration, 0xB2, KaxCueTrackPositions, "CueDuration", VERSION_WEBM_SINCE_V4)
DEFINE_MKX_UINTEGER(KaxCueBlockNumber, 0x5378, KaxCueTrackPositions, "CueBlockNumber", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxCueCodecState, 0xEA, KaxCueTrackPositions, "CueCodecState", VERSION_MATROSKA_SINCE_V2, 0)

DEFINE_START_SEMANTIC(KaxCueReference)
DEFINE_SEMANTIC_ITEM(true, true, KaxCueRefTime)
DEFINE_SEMANTIC_ITEM(true, true, KaxCueRefCluster)
DEFINE_SEMANTIC_ITEM(false, true, KaxCueRefNumber)
DEFINE_SEMANTIC_ITEM(false, true, KaxCueRefCodecState)
DEFINE_END_SEMANTIC(KaxCueReference)

DEFINE_MKX_MASTER(KaxCueReference, 0xDB, KaxCueTrackPositions, false, "CueReference", VERSION_MATROSKA_SINCE_V2)
DEFINE_MKX_UINTEGER(KaxCueRefTime, 0x96, KaxCueReference, "CueRefTime", VERSION_MATROSKA_SINCE_V2)
DEFINE_MKX_UINTEGER(KaxCueRefCluster, 0x97, KaxCueReference, "CueRefCluster", VERSION_DEPRECATED)
DEFINE_MKX_UINTEGER_DEF(KaxCueRefNumber, 0x535F, KaxCueReference, "CueRefNumber", VERSION_DEPRECATED, 1)
DEFINE_MKX_UINTEGER_DEF(KaxCueRefCodecState, 0xEB, KaxCueReference, "CueRefCodecState", VERSION_DEPRECATED, 0)

DEFINE_START_SEMANTIC(KaxAttachments)
DEFINE_SEMANTIC_ITEM(true, false, KaxAttached)
DEFINE_END_SEMANTIC(KaxAttachments)

DEFINE_MKX_MASTER_CONS(KaxAttachments, 0x1941A469, KaxSegment, false, "Attachments", VERSION_MATROSKA_ONLY)

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

DEFINE_MKX_MASTER_CONS(KaxAttached, 0x61A7, KaxAttachments, false, "AttachedFile", VERSION_MATROSKA_ONLY)
DEFINE_MKX_UNISTRING(KaxFileDescription, 0x467E, KaxAttached, "FileDescription", VERSION_MATROSKA_ONLY)
DEFINE_MKX_UNISTRING(KaxFileName, 0x466E, KaxAttached, "FileName", VERSION_MATROSKA_ONLY)
DEFINE_MKX_STRING(KaxMimeType, 0x4660, KaxAttached, "FileMimeType", VERSION_MATROSKA_ONLY)
DEFINE_MKX_BINARY (KaxFileData, 0x465C, KaxAttached, "FileData", libebml::EbmlBinary::SizeIsValid, VERSION_MATROSKA_ONLY)
DEFINE_MKX_UINTEGER(KaxFileUID, 0x46AE, KaxAttached, "FileUID", VERSION_MATROSKA_ONLY)
DEFINE_MKX_BINARY (KaxFileReferral, 0x4675, KaxAttached, "FileReferral", libebml::EbmlBinary::SizeIsValid, VERSION_DEPRECATED)
DEFINE_MKX_UINTEGER(KaxFileUsedStartTime, 0x4661, KaxAttached, "FileUsedStartTime", VERSION_DIVX_ONLY)
DEFINE_MKX_UINTEGER(KaxFileUsedEndTime, 0x4662, KaxAttached, "FileUsedEndTime", VERSION_DIVX_ONLY)

DEFINE_START_SEMANTIC(KaxChapters)
DEFINE_SEMANTIC_ITEM(true, false, KaxEditionEntry)
DEFINE_END_SEMANTIC(KaxChapters)

DEFINE_MKX_MASTER(KaxChapters, 0x1043A770, KaxSegment, false, "Chapters", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxEditionEntry)
DEFINE_SEMANTIC_ITEM(false, true, KaxEditionUID)
DEFINE_SEMANTIC_ITEM(true, true, KaxEditionFlagHidden)
DEFINE_SEMANTIC_ITEM(true, true, KaxEditionFlagDefault)
DEFINE_SEMANTIC_ITEM(true, true, KaxEditionFlagOrdered)
DEFINE_SEMANTIC_ITEM(false, false, KaxEditionDisplay)
DEFINE_SEMANTIC_ITEM(true, false, KaxChapterAtom)
DEFINE_END_SEMANTIC(KaxEditionEntry)

DEFINE_MKX_MASTER(KaxEditionEntry, 0x45B9, KaxChapters, false, "EditionEntry", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxEditionUID, 0x45BC, KaxEditionEntry, "EditionUID", VERSION_MATROSKA_ONLY)
DEFINE_MKX_UINTEGER_DEF(KaxEditionFlagHidden, 0x45BD, KaxEditionEntry, "EditionFlagHidden", VERSION_MATROSKA_ONLY, 0)
DEFINE_MKX_UINTEGER_DEF(KaxEditionFlagDefault, 0x45DB, KaxEditionEntry, "EditionFlagDefault", VERSION_MATROSKA_ONLY, 0)
DEFINE_MKX_UINTEGER_DEF(KaxEditionFlagOrdered, 0x45DD, KaxEditionEntry, "EditionFlagOrdered", VERSION_MATROSKA_ONLY, 0)

DEFINE_START_SEMANTIC(KaxEditionDisplay)
DEFINE_SEMANTIC_ITEM(true, true, KaxEditionString)
DEFINE_SEMANTIC_ITEM(false, false, KaxEditionLanguageIETF)
DEFINE_END_SEMANTIC(KaxEditionDisplay)

DEFINE_MKX_MASTER(KaxEditionDisplay, 0x4520, KaxEditionEntry, false, "EditionDisplay", VERSION_MATROSKA_SINCE_V5)
DEFINE_MKX_UNISTRING(KaxEditionString, 0x4521, KaxEditionDisplay, "EditionString", VERSION_MATROSKA_SINCE_V5)
DEFINE_MKX_STRING(KaxEditionLanguageIETF, 0x45E4, KaxEditionDisplay, "EditionLanguageIETF", VERSION_MATROSKA_SINCE_V5)

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

DEFINE_MKX_MASTER(KaxChapterAtom, 0xB6, KaxEditionEntry, false, "ChapterAtom", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxChapterUID, 0x73C4, KaxChapterAtom, "ChapterUID", VERSION_ALL_MATROSKA)
DEFINE_MKX_UNISTRING(KaxChapterStringUID, 0x5654, KaxChapterAtom, "ChapterStringUID", VERSION_WEBM_SINCE_V2)
DEFINE_MKX_UINTEGER(KaxChapterTimeStart, 0x91, KaxChapterAtom, "ChapterTimeStart", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER(KaxChapterTimeEnd, 0x92, KaxChapterAtom, "ChapterTimeEnd", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxChapterFlagHidden, 0x98, KaxChapterAtom, "ChapterFlagHidden", VERSION_MATROSKA_ONLY, 0)
DEFINE_MKX_UINTEGER_DEF(KaxChapterFlagEnabled, 0x4598, KaxChapterAtom, "ChapterFlagEnabled", VERSION_MATROSKA_ONLY, 1)
DEFINE_MKX_BINARY (KaxChapterSegmentUID, 0x6E67, KaxChapterAtom, "ChapterSegmentUID", KaxChapterSegmentUID::SizeIsValid, VERSION_MATROSKA_ONLY)
DEFINE_MKX_UINTEGER(KaxChapterSkipType, 0x4588, KaxChapterAtom, "ChapterSkipType", VERSION_MATROSKA_SINCE_V5)
DEFINE_MKX_UINTEGER(KaxChapterSegmentEditionUID, 0x6EBC, KaxChapterAtom, "ChapterSegmentEditionUID", VERSION_MATROSKA_ONLY)
DEFINE_MKX_UINTEGER(KaxChapterPhysicalEquiv, 0x63C3, KaxChapterAtom, "ChapterPhysicalEquiv", VERSION_MATROSKA_ONLY)

DEFINE_START_SEMANTIC(KaxChapterTrack)
DEFINE_SEMANTIC_ITEM(true, false, KaxChapterTrackNumber)
DEFINE_END_SEMANTIC(KaxChapterTrack)

DEFINE_MKX_MASTER(KaxChapterTrack, 0x8F, KaxChapterAtom, false, "ChapterTrack", VERSION_MATROSKA_ONLY)
DEFINE_MKX_UINTEGER(KaxChapterTrackNumber, 0x89, KaxChapterTrack, "ChapterTrackNumber", VERSION_MATROSKA_ONLY)

DEFINE_START_SEMANTIC(KaxChapterDisplay)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterString)
DEFINE_SEMANTIC_ITEM(true, false, KaxChapterLanguage)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapLanguageIETF)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapterCountry)
DEFINE_END_SEMANTIC(KaxChapterDisplay)

DEFINE_MKX_MASTER(KaxChapterDisplay, 0x80, KaxChapterAtom, false, "ChapterDisplay", VERSION_ALL_MATROSKA)
DEFINE_MKX_UNISTRING(KaxChapterString, 0x85, KaxChapterDisplay, "ChapterString", VERSION_ALL_MATROSKA)
DEFINE_MKX_STRING_DEF(KaxChapterLanguage, 0x437C, KaxChapterDisplay, "ChapterLanguage", VERSION_ALL_MATROSKA, "eng")
DEFINE_MKX_STRING(KaxChapLanguageIETF, 0x437D, KaxChapterDisplay, "ChapLanguageIETF", VERSION_MATROSKA_SINCE_V4)
DEFINE_MKX_STRING(KaxChapterCountry, 0x437E, KaxChapterDisplay, "ChapterCountry", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxChapterProcess)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterProcessCodecID)
DEFINE_SEMANTIC_ITEM(false, true, KaxChapterProcessPrivate)
DEFINE_SEMANTIC_ITEM(false, false, KaxChapterProcessCommand)
DEFINE_END_SEMANTIC(KaxChapterProcess)

DEFINE_MKX_MASTER(KaxChapterProcess, 0x6944, KaxChapterAtom, false, "ChapterProcess", VERSION_MATROSKA_ONLY)
DEFINE_MKX_UINTEGER_DEF(KaxChapterProcessCodecID, 0x6955, KaxChapterProcess, "ChapterProcessCodecID", VERSION_MATROSKA_ONLY, 0)
DEFINE_MKX_BINARY (KaxChapterProcessPrivate, 0x450D, KaxChapterProcess, "ChapterProcessPrivate", libebml::EbmlBinary::SizeIsValid, VERSION_MATROSKA_ONLY)

DEFINE_START_SEMANTIC(KaxChapterProcessCommand)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterProcessTime)
DEFINE_SEMANTIC_ITEM(true, true, KaxChapterProcessData)
DEFINE_END_SEMANTIC(KaxChapterProcessCommand)

DEFINE_MKX_MASTER(KaxChapterProcessCommand, 0x6911, KaxChapterProcess, false, "ChapterProcessCommand", VERSION_MATROSKA_ONLY)
DEFINE_MKX_UINTEGER(KaxChapterProcessTime, 0x6922, KaxChapterProcessCommand, "ChapterProcessTime", VERSION_MATROSKA_ONLY)
DEFINE_MKX_BINARY (KaxChapterProcessData, 0x6933, KaxChapterProcessCommand, "ChapterProcessData", libebml::EbmlBinary::SizeIsValid, VERSION_MATROSKA_ONLY)

DEFINE_START_SEMANTIC(KaxTags)
DEFINE_SEMANTIC_ITEM(true, false, KaxTag)
DEFINE_END_SEMANTIC(KaxTags)

DEFINE_MKX_MASTER(KaxTags, 0x1254C367, KaxSegment, false, "Tags", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxTag)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagTargets)
DEFINE_SEMANTIC_ITEM(true, false, KaxTagSimple)
DEFINE_END_SEMANTIC(KaxTag)

DEFINE_MKX_MASTER(KaxTag, 0x7373, KaxTags, false, "Tag", VERSION_ALL_MATROSKA)

DEFINE_START_SEMANTIC(KaxTagTargets)
DEFINE_SEMANTIC_ITEM(true, true, KaxTagTargetTypeValue)
DEFINE_SEMANTIC_ITEM(false, true, KaxTagTargetType)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagTrackUID)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagEditionUID)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagChapterUID)
DEFINE_SEMANTIC_ITEM(false, false, KaxTagAttachmentUID)
DEFINE_END_SEMANTIC(KaxTagTargets)

DEFINE_MKX_MASTER(KaxTagTargets, 0x63C0, KaxTag, false, "TagTargets", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxTagTargetTypeValue, 0x68CA, KaxTagTargets, "TagTargetTypeValue", VERSION_ALL_MATROSKA, 50)
DEFINE_MKX_STRING(KaxTagTargetType, 0x63CA, KaxTagTargets, "TagTargetType", VERSION_ALL_MATROSKA)
DEFINE_MKX_UINTEGER_DEF(KaxTagTrackUID, 0x63C5, KaxTagTargets, "TagTrackUID", VERSION_ALL_MATROSKA, 0)
DEFINE_MKX_UINTEGER_DEF(KaxTagEditionUID, 0x63C9, KaxTagTargets, "TagEditionUID", VERSION_MATROSKA_ONLY, 0)
DEFINE_MKX_UINTEGER_DEF(KaxTagChapterUID, 0x63C4, KaxTagTargets, "TagChapterUID", VERSION_MATROSKA_ONLY, 0)
DEFINE_MKX_UINTEGER_DEF(KaxTagAttachmentUID, 0x63C6, KaxTagTargets, "TagAttachmentUID", VERSION_MATROSKA_ONLY, 0)

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

DEFINE_MKX_MASTER(KaxTagSimple, 0x67C8, KaxTag, false, "TagSimple", VERSION_ALL_MATROSKA)
DEFINE_MKX_UNISTRING(KaxTagName, 0x45A3, KaxTagSimple, "TagName", VERSION_ALL_MATROSKA)
DEFINE_MKX_STRING_DEF(KaxTagLangue, 0x447A, KaxTagSimple, "TagLanguage", VERSION_ALL_MATROSKA, "und")
DEFINE_MKX_STRING(KaxTagLanguageIETF, 0x447B, KaxTagSimple, "TagLanguageIETF", VERSION_MATROSKA_SINCE_V4)
DEFINE_MKX_UINTEGER_DEF(KaxTagDefault, 0x4484, KaxTagSimple, "TagDefault", VERSION_ALL_MATROSKA, 1)
DEFINE_MKX_UINTEGER_DEF(KaxTagDefaultBogus, 0x44B4, KaxTagSimple, "TagDefaultBogus", VERSION_DEPRECATED, 1)
DEFINE_MKX_UNISTRING(KaxTagString, 0x4487, KaxTagSimple, "TagString", VERSION_ALL_MATROSKA)
DEFINE_MKX_BINARY (KaxTagBinary, 0x4485, KaxTagSimple, "TagBinary", libebml::EbmlBinary::SizeIsValid, VERSION_ALL_MATROSKA)

libebml::filepos_t KaxClusterSilentTracks::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxClusterSilentTrackNumber::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxBlockVirtual::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxReferenceVirtual::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxSlices::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTimeSlice::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxSliceLaceNumber::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxSliceFrameNumber::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxSliceBlockAddID::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxSliceDelay::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxSliceDuration::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxReferenceFrame::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxReferenceOffset::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxReferenceTimestamp::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxEncryptedBlock::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTrackMinCache::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTrackMaxCache::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTrackTimestampScale::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTrackOffset::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTrackAttachmentLink::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxCodecSettings::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxCodecInfoURL::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxCodecDownloadURL::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxCodecDecodeAll::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTrackOverlay::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxOldStereoMode::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxVideoAspectRatio::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxVideoGamma::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxVideoFrameRate::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxAudioPosition::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTrickTrackUID::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTrickTrackSegmentUID::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTrickTrackFlag::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTrickMasterTrackUID::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTrickMasterTrackSegmentUID::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxContentSignature::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxContentSigKeyID::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxContentSigAlgo::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxContentSigHashAlgo::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxCueRefCluster::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxCueRefNumber::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxCueRefCodecState::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxFileReferral::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxFileUsedStartTime::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxFileUsedEndTime::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

libebml::filepos_t KaxTagDefaultBogus::RenderData(libebml::IOCallback & /* output */, bool /* bForceRender */, const ShouldWrite & /* writeFilter */) {
  assert(false); // no you are not allowed to use this element !
  return 0;
}

} // namespace libmatroska
