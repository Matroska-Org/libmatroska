/****************************************************************************
** libmatroska : parse Matroska files, see http://www.matroska.org/
**
** <file/class description>
**
** Copyright (C) 2002-2004 Steve Lhomme.  All rights reserved.
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
    \version \$Id$
    \brief Test muxing two tracks into valid clusters/blocks/frames
    \author Steve Lhomme     <robux4 @ users.sf.net>
*/

#ifdef _MSC_VER
#include <windows.h>      // for min/max
#endif // _MSC_VER

#include <iostream>

#include "ebml/StdIOCallback.h"

#include "ebml/EbmlHead.h"
#include "ebml/EbmlSubHead.h"
#include "ebml/EbmlVoid.h"
#include "matroska/FileKax.h"
#include "matroska/KaxSegment.h"
#include "matroska/KaxTracks.h"
#include "matroska/KaxCluster.h"
#include "matroska/KaxSeekHead.h"
#include "matroska/KaxCues.h"
#include "matroska/KaxInfoData.h"

using namespace LIBMATROSKA_NAMESPACE;
using namespace std;

unsigned int BIN_FILE_SIZE = 15000;
unsigned int TXT_FILE_SIZE = 3000;
const unsigned int BIN_FRAME_SIZE = 1500;
const unsigned int TXT_FRAME_SIZE = 200;
const uint64  TIMECODE_SCALE = 1000000; 

const bool bWriteDefaultValues = false;

/*!
    The first file is a "binary" file with data scaling from 0x00 to 0xFF repeatedly
    The second file is a "text" file with data scaling from 'z' to 'a'
*/
int main(int argc, char **argv)
{
    cout << "Creating \"muxed.mkv\"" << endl;

    try {
		// write the head of the file (with everything already configured)
		StdIOCallback out_file("muxed.mkv", MODE_CREATE);

		///// Writing EBML test
		EbmlHead FileHead;

		EDocType & MyDocType = GetChild<EDocType>(FileHead);
		*static_cast<EbmlString *>(&MyDocType) = "matroska";

		EDocTypeVersion & MyDocTypeVer = GetChild<EDocTypeVersion>(FileHead);
		*(static_cast<EbmlUInteger *>(&MyDocTypeVer)) = MATROSKA_VERSION;

		EDocTypeReadVersion & MyDocTypeReadVer = GetChild<EDocTypeReadVersion>(FileHead);
		*(static_cast<EbmlUInteger *>(&MyDocTypeReadVer)) = 1;

		FileHead.Render(out_file, bWriteDefaultValues);

		KaxSegment FileSegment;

		// size is unknown and will always be, we can render it right away
		uint64 SegmentSize = FileSegment.WriteHead(out_file, 5, bWriteDefaultValues);
		
		KaxTracks & MyTracks = GetChild<KaxTracks>(FileSegment);

		// reserve some space for the Meta Seek writen at the end		
		EbmlVoid Dummy;
		Dummy.SetSize(300); // 300 octets
		Dummy.Render(out_file, bWriteDefaultValues);

		KaxSeekHead MetaSeek;

		// fill the mandatory Info section
		KaxInfo & MyInfos = GetChild<KaxInfo>(FileSegment);
		KaxTimecodeScale & TimeScale = GetChild<KaxTimecodeScale>(MyInfos);
		*(static_cast<EbmlUInteger *>(&TimeScale)) = TIMECODE_SCALE;

		KaxDuration & SegDuration = GetChild<KaxDuration>(MyInfos);
		*(static_cast<EbmlFloat *>(&SegDuration)) = 0.0;

		*((EbmlUnicodeString *)&GetChild<KaxMuxingApp>(MyInfos))  = L"libmatroska 0.5.0";
		*((EbmlUnicodeString *)&GetChild<KaxWritingApp>(MyInfos)) = L"È‡ÙÔ";
		GetChild<KaxWritingApp>(MyInfos).SetDefaultSize(25);

		filepos_t InfoSize = MyInfos.Render(out_file);
		MetaSeek.IndexThis(MyInfos, FileSegment);

		// fill track 1 params
		KaxTrackEntry & MyTrack1 = GetChild<KaxTrackEntry>(MyTracks);
		MyTrack1.SetGlobalTimecodeScale(TIMECODE_SCALE);

		KaxTrackNumber & MyTrack1Number = GetChild<KaxTrackNumber>(MyTrack1);
		*(static_cast<EbmlUInteger *>(&MyTrack1Number)) = 1;

		KaxTrackUID & MyTrack1UID = GetChild<KaxTrackUID>(MyTrack1);
		*(static_cast<EbmlUInteger *>(&MyTrack1UID)) = 7;

		*(static_cast<EbmlUInteger *>(&GetChild<KaxTrackType>(MyTrack1))) = track_audio;

		KaxCodecID & MyTrack1CodecID = GetChild<KaxCodecID>(MyTrack1);
		*static_cast<EbmlString *>(&MyTrack1CodecID) = "Dummy Audio Codec";

		MyTrack1.EnableLacing(true);

		// Test the new ContentEncoding elements
		KaxContentEncodings &cencodings = GetChild<KaxContentEncodings>(MyTrack1);
		KaxContentEncoding &cencoding = GetChild<KaxContentEncoding>(cencodings);
		*(static_cast<EbmlUInteger *>(&GetChild<KaxContentEncodingOrder>(cencoding))) = 10;
		*(static_cast<EbmlUInteger *>(&GetChild<KaxContentEncodingScope>(cencoding))) = 11;
		*(static_cast<EbmlUInteger *>(&GetChild<KaxContentEncodingType>(cencoding))) = 12;

		KaxContentCompression &ccompression = GetChild<KaxContentCompression>(cencoding);
		*(static_cast<EbmlUInteger *>(&GetChild<KaxContentCompAlgo>(ccompression))) = 13;
		GetChild<KaxContentCompSettings>(ccompression).CopyBuffer((const binary *)"hello1", 6);

		KaxContentEncryption &cencryption = GetChild<KaxContentEncryption>(cencoding);
		*(static_cast<EbmlUInteger *>(&GetChild<KaxContentEncAlgo>(cencryption))) = 14;
		GetChild<KaxContentEncKeyID>(cencryption).CopyBuffer((const binary *)"hello2", 6);
		*(static_cast<EbmlUInteger *>(&GetChild<KaxContentSigAlgo>(cencryption))) = 15;
		*(static_cast<EbmlUInteger *>(&GetChild<KaxContentSigHashAlgo>(cencryption))) = 16;
		GetChild<KaxContentSigKeyID>(cencryption).CopyBuffer((const binary *)"hello3", 6);
		GetChild<KaxContentSignature>(cencryption).CopyBuffer((const binary *)"hello4", 6);

		// audio specific params
		KaxTrackAudio & MyTrack1Audio = GetChild<KaxTrackAudio>(MyTrack1);
		
		KaxAudioSamplingFreq & MyTrack1Freq = GetChild<KaxAudioSamplingFreq>(MyTrack1Audio);
		*(static_cast<EbmlFloat *>(&MyTrack1Freq)) = 44100.0;
		MyTrack1Freq.ValidateSize();

#if MATROSKA_VERSION >= 2
		KaxAudioPosition & MyTrack1Pos = GetChild<KaxAudioPosition>(MyTrack1Audio);
		binary *_Pos = new binary[5];
		_Pos[0] = '0';
		_Pos[1] = '1';
		_Pos[2] = '2';
		_Pos[3] = '3';
		_Pos[4] = '\0';
		MyTrack1Pos.SetBuffer(_Pos, 5);
#endif // MATROSKA_VERSION

		KaxAudioChannels & MyTrack1Channels = GetChild<KaxAudioChannels>(MyTrack1Audio);
		*(static_cast<EbmlUInteger *>(&MyTrack1Channels)) = 2;

		// fill track 2 params
		KaxTrackEntry & MyTrack2 = GetNextChild<KaxTrackEntry>(MyTracks, MyTrack1);
		MyTrack2.SetGlobalTimecodeScale(TIMECODE_SCALE);

		KaxTrackNumber & MyTrack2Number = GetChild<KaxTrackNumber>(MyTrack2);
		*(static_cast<EbmlUInteger *>(&MyTrack2Number)) = 200;

		KaxTrackUID & MyTrack2UID = GetChild<KaxTrackUID>(MyTrack2);
		*(static_cast<EbmlUInteger *>(&MyTrack2UID)) = 13;

		*(static_cast<EbmlUInteger *>(&GetChild<KaxTrackType>(MyTrack2))) = track_video;

		KaxCodecID & MyTrack2CodecID = GetChild<KaxCodecID>(MyTrack2);
		*static_cast<EbmlString *>(&MyTrack2CodecID) = "Dummy Video Codec";

		MyTrack2.EnableLacing(false);

		// video specific params
		KaxTrackVideo & MyTrack2Video = GetChild<KaxTrackVideo>(MyTrack2);

		KaxVideoPixelHeight & MyTrack2PHeight = GetChild<KaxVideoPixelHeight>(MyTrack2Video);
		*(static_cast<EbmlUInteger *>(&MyTrack2PHeight)) = 200;

		KaxVideoPixelWidth & MyTrack2PWidth = GetChild<KaxVideoPixelWidth>(MyTrack2Video);
		*(static_cast<EbmlUInteger *>(&MyTrack2PWidth)) = 320;

		uint64 TrackSize = MyTracks.Render(out_file, bWriteDefaultValues);

		KaxTracks * pMyTracks2 = static_cast<KaxTracks *>(MyTracks.Clone());
//		KaxTracks * pMyTracks2 = new KaxTracks(MyTracks);

		MetaSeek.IndexThis(MyTracks, FileSegment);


		// "manual" filling of a cluster"
		/// \todo whenever a BlockGroup is created, we should memorize it's position
		KaxCues AllCues;
		AllCues.SetGlobalTimecodeScale(TIMECODE_SCALE);

		KaxCluster Clust1;
		Clust1.SetParent(FileSegment); // mandatory to store references in this Cluster
		Clust1.SetPreviousTimecode(0, TIMECODE_SCALE); // the first timecode here
		Clust1.EnableChecksum();

		// automatic filling of a Cluster
		// simple frame
		KaxBlockGroup *MyNewBlock, *MyLastBlockTrk1 = NULL, *MyLastBlockTrk2 = NULL, *MyNewBlock2;
		DataBuffer *data7 = new DataBuffer((binary *)"tototototo", countof("tototototo"));
		Clust1.AddFrame(MyTrack1, 250 * TIMECODE_SCALE, *data7, MyNewBlock, LACING_EBML);
		if (MyNewBlock != NULL)
			MyLastBlockTrk1 = MyNewBlock;
		DataBuffer *data0 = new DataBuffer((binary *)"TOTOTOTO", countof("TOTOTOTO"));
		Clust1.AddFrame(MyTrack1, 260 * TIMECODE_SCALE, *data0, MyNewBlock); // to test EBML lacing
		if (MyNewBlock != NULL)
			MyLastBlockTrk1 = MyNewBlock;
		DataBuffer *data6 = new DataBuffer((binary *)"tototototo", countof("tototototo"));
		Clust1.AddFrame(MyTrack1, 270 * TIMECODE_SCALE, *data6, MyNewBlock); // to test lacing
		if (MyNewBlock != NULL) {
			MyLastBlockTrk1 = MyNewBlock;
		} else {
			MyLastBlockTrk1->SetBlockDuration(50 * TIMECODE_SCALE);
		}

		DataBuffer *data5 = new DataBuffer((binary *)"tototototo", countof("tototototo"));
		Clust1.AddFrame(MyTrack2, 23 * TIMECODE_SCALE, *data5, MyNewBlock); // to test with another track

		// add the "real" block to the cue entries
        KaxBlockBlob *Blob1 = new KaxBlockBlob(BLOCK_BLOB_NO_SIMPLE);
        Blob1->SetBlockGroup(*MyLastBlockTrk1);
		AllCues.AddBlockBlob(*Blob1);

		// frame for Track 2
		DataBuffer *data8 = new DataBuffer((binary *)"tttyyy", countof("tttyyy"));
		Clust1.AddFrame(MyTrack2, 107 * TIMECODE_SCALE, *data8, MyNewBlock, *MyLastBlockTrk2);

        KaxBlockBlob *Blob2 = new KaxBlockBlob(BLOCK_BLOB_NO_SIMPLE);
        Blob2->SetBlockGroup(*MyNewBlock);
		AllCues.AddBlockBlob(*Blob2);

		// frame with a past reference
		DataBuffer *data4 = new DataBuffer((binary *)"tttyyy", countof("tttyyy"));
		Clust1.AddFrame(MyTrack1, 300 * TIMECODE_SCALE, *data4, MyNewBlock, *MyLastBlockTrk1);

		// frame with a past & future reference
		if (MyNewBlock != NULL) {
			DataBuffer *data3 = new DataBuffer((binary *)"tttyyy", countof("tttyyy"));
			if (Clust1.AddFrame(MyTrack1, 280 * TIMECODE_SCALE, *data3, MyNewBlock2, *MyLastBlockTrk1, *MyNewBlock)) {
				MyNewBlock2->SetBlockDuration(20 * TIMECODE_SCALE);
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

		uint64 ClusterSize = Clust1.Render(out_file, AllCues, bWriteDefaultValues);
		Clust1.ReleaseFrames();
		MetaSeek.IndexThis(Clust1, FileSegment);

		KaxCluster Clust2;
		Clust2.SetParent(FileSegment); // mandatory to store references in this Cluster
		Clust2.SetPreviousTimecode(300 * TIMECODE_SCALE, TIMECODE_SCALE); // the first timecode here
		Clust2.EnableChecksum();

		DataBuffer *data2 = new DataBuffer((binary *)"tttyyy", countof("tttyyy"));
		Clust2.AddFrame(MyTrack1, 350 * TIMECODE_SCALE, *data2, MyNewBlock, *MyLastBlockTrk1);
		
        KaxBlockBlob *Blob4 = new KaxBlockBlob(BLOCK_BLOB_NO_SIMPLE);
        Blob4->SetBlockGroup(*MyNewBlock);
		AllCues.AddBlockBlob(*Blob4);

		ClusterSize += Clust2.Render(out_file, AllCues, bWriteDefaultValues);
		Clust2.ReleaseFrames();

// older version, write at the end		AllCues.Render(out_file);
		filepos_t CueSize = AllCues.Render(out_file, bWriteDefaultValues);
		MetaSeek.IndexThis(AllCues, FileSegment);

		// Chapters
		KaxChapters Chapters;
		Chapters.EnableChecksum();
		KaxEditionEntry & aEdition = GetChild<KaxEditionEntry>(Chapters);
		KaxChapterAtom & aAtom = GetChild<KaxChapterAtom>(aEdition);
		KaxChapterUID & aUID = GetChild<KaxChapterUID>(aAtom);
		*static_cast<EbmlUInteger *>(&aUID) = 0x67890;

		KaxChapterTimeStart & aChapStart = GetChild<KaxChapterTimeStart>(aAtom);
		*static_cast<EbmlUInteger *>(&aChapStart) = 0;

		KaxChapterTimeEnd & aChapEnd = GetChild<KaxChapterTimeEnd>(aAtom);
		*static_cast<EbmlUInteger *>(&aChapEnd) = 300 * TIMECODE_SCALE;

		KaxChapterDisplay & aDisplay = GetChild<KaxChapterDisplay>(aAtom);
		KaxChapterString & aChapString = GetChild<KaxChapterString>(aDisplay);
		*static_cast<EbmlUnicodeString *>(&aChapString) = L"Le film rÈduit ‡ un chapitre";

		KaxChapterLanguage & aChapLang = GetChild<KaxChapterLanguage>(aDisplay);
		*static_cast<EbmlString *>(&aChapLang) = "fra";

		KaxChapterDisplay & aDisplay2 = GetNextChild<KaxChapterDisplay>(aAtom, aDisplay);
		KaxChapterString & aChapString2 = GetChild<KaxChapterString>(aDisplay2);
		*static_cast<EbmlUnicodeString *>(&aChapString2) = L"The movie in one chapter";

		KaxChapterLanguage & aChapLang2 = GetChild<KaxChapterLanguage>(aDisplay2);
		*static_cast<EbmlString *>(&aChapLang2) = "eng";

		filepos_t ChapterSize = Chapters.Render(out_file, bWriteDefaultValues);
		MetaSeek.IndexThis(Chapters, FileSegment);

		// Write some tags
		KaxTags AllTags;
		AllTags.EnableChecksum();
		KaxTag & aTag = GetChild<KaxTag>(AllTags);
		KaxTagTargets & Targets = GetChild<KaxTagTargets>(aTag);
		KaxTagSimple & TagSimple = GetChild<KaxTagSimple>(aTag);

		KaxTagTrackUID & TrackUID = GetChild<KaxTagTrackUID>(Targets);
		*static_cast<EbmlUInteger *>(&TrackUID) = 0x12345;

		KaxTagChapterUID & ChapterUID = GetChild<KaxTagChapterUID>(Targets);
		*static_cast<EbmlUInteger *>(&ChapterUID) = 0x67890;

        KaxTagName & aTagName = GetChild<KaxTagName>(TagSimple);
        *static_cast<EbmlUnicodeString *>(&aTagName) = L"NAME";

        KaxTagString & aTagtring = GetChild<KaxTagString>(TagSimple);
        *static_cast<EbmlUnicodeString *>(&aTagtring) = L"TestÈ123";

		filepos_t TagsSize = AllTags.Render(out_file, bWriteDefaultValues);
		MetaSeek.IndexThis(AllTags, FileSegment);

		TrackSize += pMyTracks2->Render(out_file, bWriteDefaultValues);
		MetaSeek.IndexThis(*pMyTracks2, FileSegment);

		// \todo put it just before the Cue Entries
		filepos_t MetaSeekSize = Dummy.ReplaceWith(MetaSeek, out_file, bWriteDefaultValues);

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

#ifdef OLD
		MuxedFile.Close(1000); // 1000 ms
#endif // OLD
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
