// Copyright © 2002-2004 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
    \file
    \brief Test muxing two tracks into valid clusters/blocks/frames
    \author Steve Lhomme     <robux4 @ users.sf.net>
*/

#ifdef _MSC_VER
#include <windows.h>      // for min/max
#endif // _MSC_VER

#include "matroska/FileKax.h"
#include "matroska/KaxSegment.h"
#include "matroska/KaxTracks.h"
#include "matroska/KaxCluster.h"
#include "matroska/KaxSeekHead.h"
#include "matroska/KaxCues.h"

#include <ebml/StdIOCallback.h>
#include <ebml/EbmlHead.h>
#include <ebml/EbmlSubHead.h>
#include <ebml/EbmlVoid.h>

#include <iostream>

using namespace libebml;
using namespace libmatroska;
using namespace std;

unsigned int BIN_FILE_SIZE = 15000;
unsigned int TXT_FILE_SIZE = 3000;
const std::uint64_t  TIMESTAMP_SCALE = 1000000;

const EbmlElement::ShouldWrite bWriteDefaultValues = EbmlElement::WriteSkipDefault;

/*!
    The first file is a "binary" file with data scaling from 0x00 to 0xFF repeatedly
    The second file is a "text" file with data scaling from 'z' to 'a'
*/
int main(int /*argc*/, char **/*argv*/)
{
    cout << "Creating \"muxed.mkv\"" << endl;

    try {
    // write the head of the file (with everything already configured)
    StdIOCallback out_file("muxed.mkv", MODE_CREATE);

    ///// Writing EBML test
    EbmlHead FileHead;

    EDocType & MyDocType = GetChild<EDocType>(FileHead);
    MyDocType.SetValue("matroska");

    EDocTypeVersion & MyDocTypeVer = GetChild<EDocTypeVersion>(FileHead);
    MyDocTypeVer.SetValue(2);

    EDocTypeReadVersion & MyDocTypeReadVer = GetChild<EDocTypeReadVersion>(FileHead);
    MyDocTypeReadVer.SetValue(1);

    FileHead.Render(out_file, bWriteDefaultValues);

    KaxSegment FileSegment;

    // size is unknown and will always be, we can render it right away
    std::uint64_t SegmentSize = FileSegment.WriteHead(out_file, 5, bWriteDefaultValues);

    KaxTracks & MyTracks = GetChild<KaxTracks>(FileSegment);

    // reserve some space for the Meta Seek writen at the end
    EbmlVoid Dummy;
    Dummy.SetSize(300); // 300 octets
    Dummy.Render(out_file, bWriteDefaultValues);

    KaxSeekHead MetaSeek;

    // fill the mandatory Info section
    KaxInfo & MyInfos = GetChild<KaxInfo>(FileSegment);
    KaxTimecodeScale & TimeScale = GetChild<KaxTimecodeScale>(MyInfos);
    TimeScale.SetValue(TIMESTAMP_SCALE);

    KaxDuration & SegDuration = GetChild<KaxDuration>(MyInfos);
    SegDuration.SetValue(0.0);

    GetChild<KaxMuxingApp>(MyInfos).SetValue(UTFstring{L"libmatroska 0.5.0"});
    GetChild<KaxWritingApp>(MyInfos).SetValue(UTFstring{L"����"});
    GetChild<KaxWritingApp>(MyInfos).SetDefaultSize(25);

    filepos_t InfoSize = MyInfos.Render(out_file);
    MetaSeek.IndexThis(MyInfos, FileSegment);

    // fill track 1 params
    KaxTrackEntry & MyTrack1 = GetChild<KaxTrackEntry>(MyTracks);
    MyTrack1.SetGlobalTimecodeScale(TIMESTAMP_SCALE);

    KaxTrackNumber & MyTrack1Number = GetChild<KaxTrackNumber>(MyTrack1);
    MyTrack1Number.SetValue(1);

    KaxTrackUID & MyTrack1UID = GetChild<KaxTrackUID>(MyTrack1);
    MyTrack1UID.SetValue(7);

    GetChild<KaxTrackType>(MyTrack1).SetValue(track_audio);

    KaxCodecID & MyTrack1CodecID = GetChild<KaxCodecID>(MyTrack1);
    MyTrack1CodecID.SetValue("Dummy Audio Codec");

    MyTrack1.EnableLacing(true);

    // Test the new ContentEncoding elements
    KaxContentEncodings &cencodings = GetChild<KaxContentEncodings>(MyTrack1);
    KaxContentEncoding &cencoding = GetChild<KaxContentEncoding>(cencodings);
    GetChild<KaxContentEncodingOrder>(cencoding).SetValue(10);
    GetChild<KaxContentEncodingScope>(cencoding).SetValue(11);
    GetChild<KaxContentEncodingType>(cencoding).SetValue(12);

    KaxContentCompression &ccompression = GetChild<KaxContentCompression>(cencoding);
    GetChild<KaxContentCompAlgo>(ccompression).SetValue(13);
    GetChild<KaxContentCompSettings>(ccompression).CopyBuffer((const binary *)"hello1", 6);

    KaxContentEncryption &cencryption = GetChild<KaxContentEncryption>(cencoding);
    GetChild<KaxContentEncAlgo>(cencryption).SetValue(14);
    GetChild<KaxContentEncKeyID>(cencryption).CopyBuffer((const binary *)"hello2", 6);
    GetChild<KaxContentSigAlgo>(cencryption).SetValue(15);
    GetChild<KaxContentSigHashAlgo>(cencryption).SetValue(16);
    GetChild<KaxContentSigKeyID>(cencryption).CopyBuffer((const binary *)"hello3", 6);
    GetChild<KaxContentSignature>(cencryption).CopyBuffer((const binary *)"hello4", 6);

    // audio specific params
    KaxTrackAudio & MyTrack1Audio = GetChild<KaxTrackAudio>(MyTrack1);

    KaxAudioSamplingFreq & MyTrack1Freq = GetChild<KaxAudioSamplingFreq>(MyTrack1Audio);
    MyTrack1Freq.SetValue(44100.0);
    MyTrack1Freq.ValidateSize();

    KaxAudioPosition & MyTrack1Pos = GetChild<KaxAudioPosition>(MyTrack1Audio);
    binary *_Pos = new binary[5];
    _Pos[0] = '0';
    _Pos[1] = '1';
    _Pos[2] = '2';
    _Pos[3] = '3';
    _Pos[4] = '\0';
    MyTrack1Pos.SetBuffer(_Pos, 5);

    KaxAudioChannels & MyTrack1Channels = GetChild<KaxAudioChannels>(MyTrack1Audio);
    MyTrack1Channels.SetValue(2);

    // fill track 2 params
    KaxTrackEntry & MyTrack2 = GetNextChild<KaxTrackEntry>(MyTracks, MyTrack1);
    MyTrack2.SetGlobalTimecodeScale(TIMESTAMP_SCALE);

    KaxTrackNumber & MyTrack2Number = GetChild<KaxTrackNumber>(MyTrack2);
    MyTrack2Number.SetValue(200);

    KaxTrackUID & MyTrack2UID = GetChild<KaxTrackUID>(MyTrack2);
    MyTrack2UID.SetValue(13);

    GetChild<KaxTrackType>(MyTrack2).SetValue(track_video);

    KaxCodecID & MyTrack2CodecID = GetChild<KaxCodecID>(MyTrack2);
    MyTrack2CodecID.SetValue("Dummy Video Codec)");

    MyTrack2.EnableLacing(false);

    // video specific params
    KaxTrackVideo & MyTrack2Video = GetChild<KaxTrackVideo>(MyTrack2);

    KaxVideoPixelHeight & MyTrack2PHeight = GetChild<KaxVideoPixelHeight>(MyTrack2Video);
    MyTrack2PHeight.SetValue(200);

    KaxVideoPixelWidth & MyTrack2PWidth = GetChild<KaxVideoPixelWidth>(MyTrack2Video);
    MyTrack2PWidth.SetValue(320);

    std::uint64_t TrackSize = MyTracks.Render(out_file, bWriteDefaultValues);

    KaxTracks * pMyTracks2 = static_cast<KaxTracks *>(MyTracks.Clone());
//    KaxTracks * pMyTracks2 = new KaxTracks(MyTracks);

    MetaSeek.IndexThis(MyTracks, FileSegment);


    // "manual" filling of a cluster"
    /// \todo whenever a BlockGroup is created, we should memorize it's position
    KaxCues AllCues;
    AllCues.SetGlobalTimecodeScale(TIMESTAMP_SCALE);

    KaxCluster Clust1;
    Clust1.SetParent(FileSegment); // mandatory to store references in this Cluster
    Clust1.SetPreviousTimecode(0, TIMESTAMP_SCALE); // the first timestamp here
    Clust1.EnableChecksum();

    // automatic filling of a Cluster
    // simple frame
    KaxBlockGroup *MyNewBlock, *MyLastBlockTrk1 = NULL, *MyLastBlockTrk2 = NULL, *MyNewBlock2;
    DataBuffer *data7 = new DataBuffer((binary *)"tototototo", countof("tototototo"));
    Clust1.AddFrame(MyTrack1, 250 * TIMESTAMP_SCALE, *data7, MyNewBlock, LACING_EBML);
    if (MyNewBlock != NULL)
      MyLastBlockTrk1 = MyNewBlock;
    DataBuffer *data0 = new DataBuffer((binary *)"TOTOTOTO", countof("TOTOTOTO"));
    Clust1.AddFrame(MyTrack1, 260 * TIMESTAMP_SCALE, *data0, MyNewBlock); // to test EBML lacing
    if (MyNewBlock != NULL)
      MyLastBlockTrk1 = MyNewBlock;
    DataBuffer *data6 = new DataBuffer((binary *)"tototototo", countof("tototototo"));
    Clust1.AddFrame(MyTrack1, 270 * TIMESTAMP_SCALE, *data6, MyNewBlock); // to test lacing
    if (MyNewBlock != NULL) {
      MyLastBlockTrk1 = MyNewBlock;
    } else {
      MyLastBlockTrk1->SetBlockDuration(50 * TIMESTAMP_SCALE);
    }

    DataBuffer *data5 = new DataBuffer((binary *)"tototototo", countof("tototototo"));
    Clust1.AddFrame(MyTrack2, 23 * TIMESTAMP_SCALE, *data5, MyNewBlock); // to test with another track

    // add the "real" block to the cue entries
        KaxBlockBlob *Blob1 = new KaxBlockBlob(BLOCK_BLOB_NO_SIMPLE);
        Blob1->SetBlockGroup(*MyLastBlockTrk1);
    AllCues.AddBlockBlob(*Blob1);

    // frame for Track 2
    DataBuffer *data8 = new DataBuffer((binary *)"tttyyy", countof("tttyyy"));
    Clust1.AddFrame(MyTrack2, 107 * TIMESTAMP_SCALE, *data8, MyNewBlock, *MyLastBlockTrk2);

        KaxBlockBlob *Blob2 = new KaxBlockBlob(BLOCK_BLOB_NO_SIMPLE);
        Blob2->SetBlockGroup(*MyNewBlock);
    AllCues.AddBlockBlob(*Blob2);

    // frame with a past reference
    DataBuffer *data4 = new DataBuffer((binary *)"tttyyy", countof("tttyyy"));
    Clust1.AddFrame(MyTrack1, 300 * TIMESTAMP_SCALE, *data4, MyNewBlock, *MyLastBlockTrk1);

    // frame with a past & future reference
    if (MyNewBlock != NULL) {
      DataBuffer *data3 = new DataBuffer((binary *)"tttyyy", countof("tttyyy"));
      if (Clust1.AddFrame(MyTrack1, 280 * TIMESTAMP_SCALE, *data3, MyNewBlock2, *MyLastBlockTrk1, *MyNewBlock)) {
        MyNewBlock2->SetBlockDuration(20 * TIMESTAMP_SCALE);
        MyLastBlockTrk1 = MyNewBlock2;
      } else {
        printf("Error adding a frame !!!");
      }
    }

        KaxBlockBlob *Blob3 = new KaxBlockBlob(BLOCK_BLOB_NO_SIMPLE);
        Blob3->SetBlockGroup(*MyLastBlockTrk1);
    AllCues.AddBlockBlob(*Blob3);
    //AllCues.UpdateSize();

    // simulate the writing of the stream :
    // - write an empty element with enough size for the cue entry
    // - write the cluster(s)
    // - seek back in the file and write the cue entry over the empty element

    std::uint64_t ClusterSize = Clust1.Render(out_file, AllCues, bWriteDefaultValues);
    Clust1.ReleaseFrames();
    MetaSeek.IndexThis(Clust1, FileSegment);

    KaxCluster Clust2;
    Clust2.SetParent(FileSegment); // mandatory to store references in this Cluster
    Clust2.SetPreviousTimecode(300 * TIMESTAMP_SCALE, TIMESTAMP_SCALE); // the first timestamp here
    Clust2.EnableChecksum();

    DataBuffer *data2 = new DataBuffer((binary *)"tttyyy", countof("tttyyy"));
    Clust2.AddFrame(MyTrack1, 350 * TIMESTAMP_SCALE, *data2, MyNewBlock, *MyLastBlockTrk1);

        KaxBlockBlob *Blob4 = new KaxBlockBlob(BLOCK_BLOB_NO_SIMPLE);
        Blob4->SetBlockGroup(*MyNewBlock);
    AllCues.AddBlockBlob(*Blob4);

    ClusterSize += Clust2.Render(out_file, AllCues, bWriteDefaultValues);
    Clust2.ReleaseFrames();

// older version, write at the end    AllCues.Render(out_file);
    filepos_t CueSize = AllCues.Render(out_file, bWriteDefaultValues);
    MetaSeek.IndexThis(AllCues, FileSegment);

    // Chapters
    KaxChapters Chapters;
    Chapters.EnableChecksum();
    KaxEditionEntry & aEdition = GetChild<KaxEditionEntry>(Chapters);
    KaxChapterAtom & aAtom = GetChild<KaxChapterAtom>(aEdition);
    KaxChapterUID & aUID = GetChild<KaxChapterUID>(aAtom);
    aUID.SetValue(0x67890);

    KaxChapterTimeStart & aChapStart = GetChild<KaxChapterTimeStart>(aAtom);
    aChapStart.SetValue(0);

    KaxChapterTimeEnd & aChapEnd = GetChild<KaxChapterTimeEnd>(aAtom);
    aChapEnd.SetValue(300 * TIMESTAMP_SCALE);

    KaxChapterDisplay & aDisplay = GetChild<KaxChapterDisplay>(aAtom);
    KaxChapterString & aChapString = GetChild<KaxChapterString>(aDisplay);
    aChapString.SetValue(UTFstring{L"Le film r�duit � un chapitre"});

    KaxChapterLanguage & aChapLang = GetChild<KaxChapterLanguage>(aDisplay);
    aChapLang.SetValue("fra");

    KaxChapterDisplay & aDisplay2 = GetNextChild<KaxChapterDisplay>(aAtom, aDisplay);
    KaxChapterString & aChapString2 = GetChild<KaxChapterString>(aDisplay2);
    aChapString2.SetValue(UTFstring{L"The movie in one chapter"});

    KaxChapterLanguage & aChapLang2 = GetChild<KaxChapterLanguage>(aDisplay2);
    aChapLang2.SetValue("eng");

    filepos_t ChapterSize = Chapters.Render(out_file, bWriteDefaultValues);
    MetaSeek.IndexThis(Chapters, FileSegment);

    // Write some tags
    KaxTags AllTags;
    AllTags.EnableChecksum();
    KaxTag & aTag = GetChild<KaxTag>(AllTags);
    KaxTagTargets & Targets = GetChild<KaxTagTargets>(aTag);
    KaxTagSimple & TagSimple = GetChild<KaxTagSimple>(aTag);

    KaxTagTrackUID & TrackUID = GetChild<KaxTagTrackUID>(Targets);
    TrackUID.SetValue(0x12345);

    KaxTagChapterUID & ChapterUID = GetChild<KaxTagChapterUID>(Targets);
    ChapterUID.SetValue(0x67890);

        KaxTagName & aTagName = GetChild<KaxTagName>(TagSimple);
        aTagName.SetValue(UTFstring{L"NAME"});

        KaxTagString & aTagtring = GetChild<KaxTagString>(TagSimple);
        aTagtring.SetValue(UTFstring{L"Test�123"});

    filepos_t TagsSize = AllTags.Render(out_file, bWriteDefaultValues);
    MetaSeek.IndexThis(AllTags, FileSegment);

    TrackSize += pMyTracks2->Render(out_file, bWriteDefaultValues);
    MetaSeek.IndexThis(*pMyTracks2, FileSegment);

    // \todo put it just before the Cue Entries
    filepos_t MetaSeekSize = Dummy.ReplaceWith(MetaSeek, out_file, true, bWriteDefaultValues);

#ifdef VOID_TEST
    MyInfos.VoidMe(out_file);
#endif // VOID_TEST

    // let's assume we know the size of the Segment element
    // the size of the FileSegment is also computed because mandatory elements we don't write ourself exist
    if (FileSegment.ForceSize(SegmentSize - FileSegment.HeadSize() + MetaSeekSize
                            + TrackSize + ClusterSize + CueSize + InfoSize + TagsSize + ChapterSize)) {
      FileSegment.OverwriteHead(out_file);
    }

#if 0
    delete[] buf_bin;
    delete[] buf_txt;
#endif // 0

    out_file.close();

        delete Blob1;
        delete Blob2;
        delete Blob3;
        delete Blob4;
    }
    catch (exception & Ex)
    {
    cout << Ex.what() << endl;
    }

    return 0;
}
