// Copyright © 2002-2004 Moritz Bunkus.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
    \file
    \brief Test writing tags
    \author Moritz Bunkus     <mosu @ users.sf.net>
*/

#include <matroska/FileKax.h>
#include <matroska/KaxBlock.h>
#include <matroska/KaxCluster.h>
#include <matroska/KaxCues.h>
#include <matroska/KaxSeekHead.h>
#include <matroska/KaxSegment.h>
#include <matroska/KaxTracks.h>
#include <matroska/KaxVersion.h>

#include <ebml/EbmlHead.h>
#include <ebml/EbmlSubHead.h>
#include <ebml/EbmlVersion.h>
#include <ebml/EbmlVoid.h>
#include <ebml/StdIOCallback.h>

#include <time.h>

#include <typeinfo>

using namespace std;
using namespace libebml;
using namespace libmatroska;

int main() {

  try {
    EbmlHead head;
    KaxSegment segment;
    StdIOCallback out("test.mkv", MODE_CREATE);

    EDocType &doc_type = GetChild<EDocType>(head);
    doc_type.SetValue("matroska");
    EDocTypeVersion &doc_type_ver = GetChild<EDocTypeVersion>(head);
    doc_type_ver.SetValue(1);
    EDocTypeReadVersion &doc_type_read_ver =
      GetChild<EDocTypeReadVersion>(head);
    doc_type_read_ver.SetValue(1);

    head.Render(out);

    KaxInfo &info = GetChild<KaxInfo>(segment);
    KaxTimecodeScale &time_scale = GetChild<KaxTimecodeScale>(info);
    time_scale.SetValue(1000000);

    segment.WriteHead(out, 5);

    // Write some dummy tags.
    KaxTags &tags = GetChild<KaxTags>(segment);

    KaxTag &tag = GetChild<KaxTag>(tags);

    KaxTagTargets &targets = GetChild<KaxTagTargets>(tag);
    GetChild<KaxTagTrackUID>(targets).SetValue(1234);

    KaxTagSimple &stag_l1 = GetChild<KaxTagSimple>(tag);
    GetChild<KaxTagName>(stag_l1).SetValue(
      UTFstring{L"SIMPLE_TAG_NAME_LEVEL1_1"});
    GetChild<KaxTagString>(stag_l1).SetValue(
      UTFstring{L"SIMPLE_TAG_STRING_LEVEL1_1"});
    KaxTagSimple &stag_l1_2 = GetNextChild<KaxTagSimple>(tag, stag_l1);
    GetChild<KaxTagName>(stag_l1_2).SetValue(
      UTFstring{L"SIMPLE_TAG_NAME_LEVEL1_2"});
    KaxTagBinary &tbin = GetChild<KaxTagBinary>(stag_l1_2);
    tbin.CopyBuffer((binary *)"SIMPLE_TAG_BINARY_LEVEL1_2",
                    strlen("SIMPLE_TAG_BINARY_LEVEL1_2"));
    KaxTagSimple &stag_l2 = GetChild<KaxTagSimple>(stag_l1);
    GetChild<KaxTagName>(stag_l2).SetValue(
      UTFstring{L"SIMPLE_TAG_NAME_LEVEL2"});
    GetChild<KaxTagString>(stag_l2).SetValue(
      UTFstring{L"SIMPLE_TAG_STRING_LEVEL2"});
    KaxTagSimple &stag_l3 = GetChild<KaxTagSimple>(stag_l2);
    GetChild<KaxTagName>(stag_l3).SetValue(
      UTFstring{L"SIMPLE_TAG_NAME_LEVEL3"});
    GetChild<KaxTagString>(stag_l3).SetValue(
      UTFstring{L"SIMPLE_TAG_STRING_LEVEL3"});

    tags.Render(out);

  } catch (...) {
    printf("exception\n");
  }

  return 0;
}
