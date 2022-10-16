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
