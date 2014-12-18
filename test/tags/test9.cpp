/****************************************************************************
** libmatroska : parse Matroska files, see http://www.matroska.org/
**
** <file/class description>
**
** Copyright (C) 2002-2004 Moritz Bunkus.  All rights reserved.
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

/*!
    \file
    \version \$Id: test9.cpp 640 2004-07-09 21:05:36Z mosu $
    \brief Test writing tags
    \author Moritz Bunkus     <mosu @ users.sf.net>
*/

#include <time.h>

#include <typeinfo>

#include <ebml/EbmlHead.h>
#include <ebml/EbmlSubHead.h>
#include <ebml/EbmlVersion.h>
#include <ebml/EbmlVoid.h>
#include <ebml/StdIOCallback.h>

#include <matroska/FileKax.h>
#include <matroska/KaxBlock.h>
#include <matroska/KaxCluster.h>
#include <matroska/KaxClusterData.h>
#include <matroska/KaxCues.h>
#include <matroska/KaxInfo.h>
#include <matroska/KaxInfoData.h>
#include <matroska/KaxSeekHead.h>
#include <matroska/KaxSegment.h>
#include <matroska/KaxTags.h>
#include <matroska/KaxTag.h>
#include <matroska/KaxTracks.h>
#include <matroska/KaxTrackEntryData.h>
#include <matroska/KaxTrackAudio.h>
#include <matroska/KaxTrackVideo.h>
#include <matroska/KaxVersion.h>

using namespace std;
using namespace libebml;
using namespace libmatroska;

int main() {

  try {
    EbmlHead head;
    KaxSegment segment;
    StdIOCallback out("test.mkv", MODE_CREATE);

    EDocType &doc_type = GetChild<EDocType>(head);
    *static_cast<EbmlString *>(&doc_type) = "matroska";
    EDocTypeVersion &doc_type_ver = GetChild<EDocTypeVersion>(head);
    *(static_cast<EbmlUInteger *>(&doc_type_ver)) = 1;
    EDocTypeReadVersion &doc_type_read_ver =
      GetChild<EDocTypeReadVersion>(head);
    *(static_cast<EbmlUInteger *>(&doc_type_read_ver)) = 1;

    head.Render(out);

    KaxInfo &info = GetChild<KaxInfo>(segment);
    KaxTimecodeScale &time_scale = GetChild<KaxTimecodeScale>(info);
    *(static_cast<EbmlUInteger *>(&time_scale)) = 1000000;

    segment.WriteHead(out, 5);

    // Write some dummy tags.
    KaxTags &tags = GetChild<KaxTags>(segment);

    KaxTag &tag = GetChild<KaxTag>(tags);

    KaxTagTargets &targets = GetChild<KaxTagTargets>(tag);
    *(static_cast<EbmlUInteger *>(&GetChild<KaxTagTrackUID>(targets))) =
      1234;

#if 0
  // comment of the Targets
     KaxTagMultiComment &mcomB = GetChild<KaxTagMultiComment>(targets);
    *(static_cast<EbmlString *>
      (&GetChild<KaxTagMultiCommentName>(mcomB))) =
      "Comment Level 5";

    *(static_cast<EbmlUInteger *>(&GetChild<KaxTagChapterUID>(targets))) =
      5678;

     KaxTagMultiComment &mcomA = GetChild<KaxTagMultiComment>(tag);
    *(static_cast<EbmlString *>
      (&GetChild<KaxTagMultiCommentName>(mcomA))) =
      "Comment Level 3";

    KaxTagGeneral &general = GetChild<KaxTagGeneral>(tag);
    *(static_cast<EbmlUnicodeString *>(&GetChild<KaxTagSubject>(general))) =
      L"Subject";
    *(static_cast<EbmlUnicodeString *>
      (&GetChild<KaxTagBibliography>(general))) =
      L"Bibliography";
    *(static_cast<EbmlString *>(&GetChild<KaxTagLanguage>(general))) = "ger";
    KaxTagRating &rating = GetChild<KaxTagRating>(general);
    rating.CopyBuffer((binary *)"hallo", 5);
     *(static_cast<EbmlUnicodeString *>
       (&GetChild<KaxTagEncoder>(general))) =
       L"Encoder";
     *(static_cast<EbmlUnicodeString *>
       (&GetChild<KaxTagEncodeSettings>(general))) =
       L"EncodeSettings";
     *(static_cast<EbmlUnicodeString *>
       (&GetChild<KaxTagFile>(general))) =
       L"File";
    *(static_cast<EbmlUnicodeString *>
      (&GetChild<KaxTagArchivalLocation>(general))) =
      L"ArchivalLocation";
    KaxTagKeywords &keywords1 = GetChild<KaxTagKeywords>(general);
    *(static_cast<EbmlUnicodeString *>(&keywords1)) =
      L"Keywords, 1";
    *(static_cast<EbmlUnicodeString *>
      (&GetNextChild<KaxTagKeywords>(general, keywords1))) =
      L"Keywords, 2";
    *(static_cast<EbmlUnicodeString *>
      (&GetChild<KaxTagMood>(general))) =
      L"Mood";
    KaxTagRecordLocation &recordLocation1 =
      GetChild<KaxTagRecordLocation>(general);
    *(static_cast<EbmlString *>(&recordLocation1)) =
      "RecordLocation, 1";
    *(static_cast<EbmlString *>
      (&GetNextChild<KaxTagRecordLocation>(general, recordLocation1))) =
      "RecordLocation, 2";
    *(static_cast<EbmlUnicodeString *>
      (&GetChild<KaxTagSource>(general))) =
      L"Source";
    *(static_cast<EbmlUnicodeString *>
      (&GetChild<KaxTagSourceForm>(general))) =
      L"SourceForm";
    *(static_cast<EbmlUnicodeString *>
      (&GetChild<KaxTagProduct>(general))) =
      L"Product";
    *(static_cast<EbmlUnicodeString *>
      (&GetChild<KaxTagOriginalMediaType>(general))) =
      L"OriginalMediaType";
    *(static_cast<EbmlUInteger *>
      (&GetChild<KaxTagPlayCounter>(general))) =
      123456;
    *(static_cast<EbmlSInteger *>
      (&GetChild<KaxTagPopularimeter>(general))) =
      234567;

    KaxTagGenres &genres = GetChild<KaxTagGenres>(tag);
    *(static_cast<EbmlString *>
      (&GetChild<KaxTagAudioGenre>(genres))) =
      "AudioGenre";
    KaxTagVideoGenre &videoGenre = GetChild<KaxTagVideoGenre>(genres);
    videoGenre.CopyBuffer((binary *)"hallo", 5);
    *(static_cast<EbmlString *>
      (&GetChild<KaxTagSubGenre>(genres))) =
      "SubGenre";

    KaxTagAudioSpecific &aspec = GetChild<KaxTagAudioSpecific>(tag);
    KaxTagAudioEncryption &aenc = GetChild<KaxTagAudioEncryption>(aspec);
    aenc.CopyBuffer((binary *)"hallo", 5);
    *(static_cast<EbmlFloat *>
      (&GetChild<KaxTagAudioGain>(aspec))) =
      42.0;
    *(static_cast<EbmlFloat *>
      (&GetChild<KaxTagAudioPeak>(aspec))) =
      54.0;
    *(static_cast<EbmlFloat *>
      (&GetChild<KaxTagBPM>(aspec))) =
      23.0;
    KaxTagEqualisation &aeq = GetChild<KaxTagEqualisation>(aspec);
    aeq.CopyBuffer((binary *)"hallo", 5);
    *(static_cast<EbmlUInteger *>
      (&GetChild<KaxTagDiscTrack>(aspec))) =
      2;
    *(static_cast<EbmlUInteger *>
      (&GetChild<KaxTagSetPart>(aspec))) =
      4;
    *(static_cast<EbmlString *>
      (&GetChild<KaxTagInitialKey>(aspec))) =
      "InitialKey";
    *(static_cast<EbmlString *>
      (&GetChild<KaxTagOfficialAudioFileURL>(aspec))) =
      "OfficialAudioFileURL";
    *(static_cast<EbmlString *>
      (&GetChild<KaxTagOfficialAudioSourceURL>(aspec))) =
      "OfficialAudioSourceURL";

    KaxTagImageSpecific &ispec = GetChild<KaxTagImageSpecific>(tag);
    *(static_cast<EbmlUInteger *>
      (&GetChild<KaxTagCaptureDPI>(ispec))) =
      42;
    KaxTagCaptureLightness &clight = GetChild<KaxTagCaptureLightness>(ispec);
    clight.CopyBuffer((binary *)"hallo", 5);
    *(static_cast<EbmlUInteger *>
      (&GetChild<KaxTagCapturePaletteSetting>(ispec))) =
      54;
    KaxTagCaptureSharpness &csharp = GetChild<KaxTagCaptureSharpness>(ispec);
    csharp.CopyBuffer((binary *)"hallo", 5);
    *(static_cast<EbmlUnicodeString *>
      (&GetChild<KaxTagCropped>(ispec))) =
      L"Cropped";
    *(static_cast<EbmlString *>
      (&GetChild<KaxTagOriginalDimensions>(ispec))) =
      "OriginalDimensions";

    KaxTagMultiCommercial &mcmrcl = GetChild<KaxTagMultiCommercial>(tag);
    KaxTagCommercial &cmrcl = GetChild<KaxTagCommercial>(mcmrcl);
    *(static_cast<EbmlUInteger *>
      (&GetChild<KaxTagMultiCommercialType>(cmrcl))) =
      3;
    *(static_cast<EbmlUnicodeString *>
      (&GetChild<KaxTagMultiCommercialAddress>(cmrcl))) =
      L"MultiCommercialAddress";
    *(static_cast<EbmlString *>
      (&GetChild<KaxTagMultiCommercialURL>(cmrcl))) =
      "MultiCommercialURL";
    *(static_cast<EbmlString *>
      (&GetChild<KaxTagMultiCommercialEmail>(cmrcl))) =
      "MultiCommercialEmail";

     KaxTagMultiPrice &mprice = GetChild<KaxTagMultiPrice>(cmrcl);
     *(static_cast<EbmlString *>
       (&GetChild<KaxTagMultiPriceCurrency>(mprice))) =
       "MultiPriceCurrency";
     *(static_cast<EbmlFloat *>
       (&GetChild<KaxTagMultiPriceAmount>(mprice))) =
       42.0;
     KaxTagMultiPricePriceDate &pdate =
       GetChild<KaxTagMultiPricePriceDate>(mprice);
     pdate.SetEpochDate(time(NULL));

    KaxTagMultiDate &mdate = GetChild<KaxTagMultiDate>(tag);
    KaxTagDate &date = GetChild<KaxTagDate>(mdate);
    *(static_cast<EbmlUInteger *>
      (&GetChild<KaxTagMultiDateType>(date))) =
      4;
    KaxTagMultiDateDateBegin &dbeg =
      GetChild<KaxTagMultiDateDateBegin>(date);
    dbeg.SetEpochDate(time(NULL));
    KaxTagMultiDateDateEnd &dend =
      GetChild<KaxTagMultiDateDateEnd>(date);
    dend.SetEpochDate(time(NULL));

    KaxTagMultiEntity &ment = GetChild<KaxTagMultiEntity>(tag);
    KaxTagEntity &ent = GetChild<KaxTagEntity>(ment);
    *(static_cast<EbmlUInteger *>
      (&GetChild<KaxTagMultiEntityType>(ent))) =
      1;
    *(static_cast<EbmlUnicodeString *>
      (&GetChild<KaxTagMultiEntityName>(ent))) =
      L"MultiEntityName";
    *(static_cast<EbmlString *>
      (&GetChild<KaxTagMultiEntityURL>(ent))) =
      "MultiEntityURL";
    *(static_cast<EbmlString *>
      (&GetChild<KaxTagMultiEntityEmail>(ent))) =
      "MultiEntityEmail";
    *(static_cast<EbmlUnicodeString *>
      (&GetChild<KaxTagMultiEntityAddress>(ent))) =
      L"MultiEntityAddress";

     KaxTagMultiIdentifier &mident = GetChild<KaxTagMultiIdentifier>(tag);
     KaxTagIdentifier &ident = GetChild<KaxTagIdentifier>(mident);
     *(static_cast<EbmlUInteger *>
       (&GetChild<KaxTagMultiIdentifierType>(ident))) =
       5;
     KaxTagMultiIdentifierBinary &ibin =
       GetChild<KaxTagMultiIdentifierBinary>(ident);
     ibin.CopyBuffer((binary *)"hallo", 5);
     *(static_cast<EbmlUnicodeString *>
       (&GetChild<KaxTagMultiIdentifierString>(ident))) =
       L"MultiIdentifierString";

    KaxTagMultiLegal &mlegal = GetChild<KaxTagMultiLegal>(tag);
    KaxTagLegal &legal = GetChild<KaxTagLegal>(mlegal);
    *(static_cast<EbmlUInteger *>
      (&GetChild<KaxTagMultiLegalType>(legal))) =
      3;
    *(static_cast<EbmlString *>
      (&GetChild<KaxTagMultiLegalURL>(legal))) =
      "MultiLegalURL";
    *(static_cast<EbmlUnicodeString *>
      (&GetChild<KaxTagMultiLegalAddress>(legal))) =
      L"MultiLegalAddress";

    KaxTagMultiTitle &mtit = GetChild<KaxTagMultiTitle>(tag);
    KaxTagTitle &tit = GetChild<KaxTagTitle>(mtit);
    *(static_cast<EbmlUInteger *>
      (&GetChild<KaxTagMultiTitleType>(tit))) =
      2;
    *(static_cast<EbmlUnicodeString *>
      (&GetChild<KaxTagMultiTitleName>(tit))) =
      L"MultiTitleName";
    *(static_cast<EbmlUnicodeString *>
      (&GetChild<KaxTagMultiTitleSubTitle>(tit))) =
      L"MultiTitleSubTitle";
    *(static_cast<EbmlUnicodeString *>
      (&GetChild<KaxTagMultiTitleEdition>(tit))) =
      L"MultiTitleEdition";
    *(static_cast<EbmlUnicodeString *>
      (&GetChild<KaxTagMultiTitleAddress>(tit))) =
      L"MultiTitleAddress";
    *(static_cast<EbmlString *>
      (&GetChild<KaxTagMultiTitleURL>(tit))) =
      "MultiTitleURL";
    *(static_cast<EbmlString *>
      (&GetChild<KaxTagMultiTitleEmail>(tit))) =
      "MultiTitleEmail";
    *(static_cast<EbmlString *>
      (&GetChild<KaxTagMultiTitleLanguage>(tit))) =
      "MultiTitleLanguage";
#endif

    KaxTagSimple &stag_l1 = GetChild<KaxTagSimple>(tag);
    *(static_cast<EbmlUnicodeString *>(&GetChild<KaxTagName>(stag_l1))) =
      L"SIMPLE_TAG_NAME_LEVEL1_1";
    *(static_cast<EbmlUnicodeString *>(&GetChild<KaxTagString>(stag_l1))) =
      L"SIMPLE_TAG_STRING_LEVEL1_1";
    KaxTagSimple &stag_l1_2 = GetNextChild<KaxTagSimple>(tag, stag_l1);
    *(static_cast<EbmlUnicodeString *>(&GetChild<KaxTagName>(stag_l1_2))) =
      L"SIMPLE_TAG_NAME_LEVEL1_2";
    KaxTagBinary &tbin = GetChild<KaxTagBinary>(stag_l1_2);
    tbin.CopyBuffer((binary *)"SIMPLE_TAG_BINARY_LEVEL1_2",
                    strlen("SIMPLE_TAG_BINARY_LEVEL1_2"));
    KaxTagSimple &stag_l2 = GetChild<KaxTagSimple>(stag_l1);
    *(static_cast<EbmlUnicodeString *>(&GetChild<KaxTagName>(stag_l2))) =
      L"SIMPLE_TAG_NAME_LEVEL2";
    *(static_cast<EbmlUnicodeString *>(&GetChild<KaxTagString>(stag_l2))) =
      L"SIMPLE_TAG_STRING_LEVEL2";
    KaxTagSimple &stag_l3 = GetChild<KaxTagSimple>(stag_l2);
    *(static_cast<EbmlUnicodeString *>(&GetChild<KaxTagName>(stag_l3))) =
      L"SIMPLE_TAG_NAME_LEVEL3";
    *(static_cast<EbmlUnicodeString *>(&GetChild<KaxTagString>(stag_l3))) =
      L"SIMPLE_TAG_STRING_LEVEL3";

    tags.Render(out);

  } catch (...) {
    printf("exception\n");
  }

  return 0;
}
