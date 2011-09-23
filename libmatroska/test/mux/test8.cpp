/****************************************************************************
** libmatroska : parse Matroska files, see http://www.matroska.org/
**
** <file/class description>
**
** Copyright (C) 2002-2004 Steve Lhomme.  All rights reserved.
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
    \brief Test reading of the Header
    \author Steve Lhomme     <robux4 @ users.sf.net>
*/

#include <iostream>
#include <cassert>

#if __GNUC__ == 2
#include <wchar.h>
#endif

#include "ebml/EbmlHead.h"
#include "ebml/EbmlSubHead.h"
#include "ebml/EbmlStream.h"
#include "ebml/EbmlContexts.h"
#include "ebml/EbmlVoid.h"
#include "ebml/EbmlCrc32.h"
#include "matroska/FileKax.h"
#include "matroska/KaxSegment.h"
#include "matroska/KaxContexts.h"
#include "matroska/KaxTracks.h"
#include "matroska/KaxInfoData.h"
#include "matroska/KaxCluster.h"
#include "matroska/KaxBlockData.h"
#include "matroska/KaxSeekHead.h"
#include "matroska/KaxCuesData.h"
#include "ebml/StdIOCallback.h"

using namespace LIBMATROSKA_NAMESPACE;
using namespace std;

#define NO_DISPLAY_DATA
//#define JUMP_TEST

/*!
    \note you can generate the file used in this example using test6.cpp
	\todo the blocks with "titi" and "tetetete" don't seem to be read !
*/
int main(int argc, char **argv)
{
    try {
	StdIOCallback Cluster_file((argc>=2 ? argv[1] : "muxed.mkv"), MODE_READ);

	// create the Matroska file
///	FileKax MuxedFile(Cluster_file);
//	bool bAllowDummy = false; // don't read elements we don't know
	bool bAllowDummy = true; // even read elements we don't know (needed for CRC checking)

	// read the EBML head
	EbmlStream aStream(Cluster_file);
	EbmlElement * ElementLevel0;
	EbmlElement * ElementLevel1;
	EbmlElement * ElementLevel2;
	EbmlElement * ElementLevel3 = NULL;
	EbmlElement * ElementLevel4 = NULL;

///	MuxedFile.ReadHead();
	// find the EBML head in the file
	ElementLevel0 = aStream.FindNextID(EbmlHead::ClassInfos, 0xFFFFFFFFL);
	if (ElementLevel0 != NULL)
	{
		printf("EBML : ");
		for (unsigned int i=0; i<EbmlId(*ElementLevel0).Length; i++)
		{
			printf("[%02X]", (EbmlId(*ElementLevel0).Value >> (8*(3-i))) & 0xFF);
		}
		printf("\n");

		ElementLevel0->SkipData(aStream, EbmlHead_Context);
		if (ElementLevel0 != NULL)
			delete ElementLevel0;
	}

	int UpperElementLevel = 0;
	KaxSegment * Segment;
	KaxInfo * SegmentInfo;
	KaxTrackEntry * TrackAudio;
	KaxTrackEntry * TrackVideo;
	KaxCluster *SegmentCluster;
	KaxCues *CuesEntry;
	KaxSeekHead *MetaSeek;
	KaxChapters *Chapters;
	KaxTags *AllTags;
	uint64 TimecodeScale = 1000000;

	// find the segment to read
	ElementLevel0 = aStream.FindNextID(KaxSegment::ClassInfos, 0xFFFFFFFFL);
	if (ElementLevel0 != NULL)
	{
		if (EbmlId(*ElementLevel0) == KaxSegment::ClassInfos.GlobalId) {
			Segment = static_cast<KaxSegment*>(ElementLevel0);
//			MuxedFile.ReadTracks();
//			MuxedFile.ReadCodec();
			// scan the file for a Tracks element (all previous Level1 elements are discarded)
			ElementLevel1 = aStream.FindNextElement(ElementLevel0->Generic().Context, UpperElementLevel, 0, bAllowDummy);

			while (ElementLevel1 != NULL) {
				if (UpperElementLevel > 0) {
					break;
				}
				if (UpperElementLevel < 0) {
					UpperElementLevel = 0;
				}

				/// \todo switch the type of the element to check if it's one we want to handle, like attachements
				if (EbmlId(*ElementLevel1) == EbmlVoid::ClassInfos.GlobalId) {
					printf("\n- Void found\n");
				} else if (EbmlId(*ElementLevel1) == KaxTracks::ClassInfos.GlobalId) {
					// found the Tracks element
					printf("\n- Segment Tracks found\n");
					// handle the data in Tracks here.
					// poll for new tracks and handle them
					ElementLevel2 = aStream.FindNextElement(ElementLevel1->Generic().Context, UpperElementLevel, 0, bAllowDummy);

					while (ElementLevel2 != NULL) {
						if (UpperElementLevel > 0) {
							break;
						}
						if (UpperElementLevel < 0) {
							UpperElementLevel = 0;
						}
						/// \todo switch the type of the element to check if it's one we want to handle, like attachements
						if (EbmlId(*ElementLevel2) == KaxTrackEntry::ClassInfos.GlobalId) {
							printf("* Found a track\n");

							ElementLevel3 = aStream.FindNextElement(ElementLevel2->Generic().Context, UpperElementLevel, 0, bAllowDummy);
							while (ElementLevel3 != NULL) {
								if (UpperElementLevel > 0) {
									break;
								}
								if (UpperElementLevel < 0) {
									UpperElementLevel = 0;
								}
								// read the data we care about in a track
								// Track number
								if (EbmlId(*ElementLevel3) == KaxTrackNumber::ClassInfos.GlobalId) {
									KaxTrackNumber & TrackNum = *static_cast<KaxTrackNumber*>(ElementLevel3);
									TrackNum.ReadData(aStream.I_O());
									printf("Track # %d\n", uint8(TrackNum));
								}

								// Track type
								else if (EbmlId(*ElementLevel3) == KaxTrackType::ClassInfos.GlobalId) {
									KaxTrackType & TrackType = *static_cast<KaxTrackType*>(ElementLevel3);
									TrackType.ReadData(aStream.I_O());
									printf("Track type : ");
									switch(uint8(TrackType))
									{
									case track_audio:
										printf("Audio");
										TrackAudio = static_cast<KaxTrackEntry *>(ElementLevel2);
										TrackAudio->SetGlobalTimecodeScale(TimecodeScale);
										break;
									case track_video:
										printf("Video");
										TrackVideo = static_cast<KaxTrackEntry *>(ElementLevel2);
										TrackVideo->SetGlobalTimecodeScale(TimecodeScale);
										break;
									default:
										printf("unknown");
									}
									printf("\n");
								}

								else if (EbmlId(*ElementLevel3) == KaxTrackFlagLacing::ClassInfos.GlobalId) {
									printf("Flag Lacing\n");
								}
								else if (EbmlId(*ElementLevel3) == KaxCodecID::ClassInfos.GlobalId) {
									KaxCodecID & CodecID = *static_cast<KaxCodecID*>(ElementLevel3);
									CodecID.ReadData(aStream.I_O());
									printf("Codec ID   : %s\n", string(CodecID).c_str());
								}

								if (UpperElementLevel > 0) {
									assert(0 == 1); // impossible to be here ?
									UpperElementLevel--;
									delete ElementLevel2;
									ElementLevel2 = ElementLevel3;
									if (UpperElementLevel > 0)
										break;
								} else {
									ElementLevel3->SkipData(aStream, ElementLevel3->Generic().Context);
									delete ElementLevel3;

									ElementLevel3 = aStream.FindNextElement(ElementLevel2->Generic().Context, UpperElementLevel, 0, bAllowDummy);
								}
							}
						}
						if (UpperElementLevel > 0) {
							UpperElementLevel--;
							delete ElementLevel2;
							ElementLevel2 = ElementLevel3;
							if (UpperElementLevel > 0)
								break;
						} else {
							ElementLevel2->SkipData(aStream, ElementLevel2->Generic().Context);
							delete ElementLevel2;
					
							ElementLevel2 = aStream.FindNextElement(ElementLevel1->Generic().Context, UpperElementLevel, 0, bAllowDummy);
						}
					}
				}

				else if (EbmlId(*ElementLevel1) == KaxInfo::ClassInfos.GlobalId) {
					printf("\n- Segment Informations found\n");
					SegmentInfo = static_cast<KaxInfo *>(ElementLevel1);

#ifdef JUMP_TEST
					// test jumping to a random location and find the next Level 0 / Level 1 element
					aStream.I_O().setFilePointer(79, seek_current);
					printf("Seeked at position 0x%X in the file", aStream.I_O().getFilePointer());
					int LowLevel = 1;
					ElementLevel2 = aStream.FindNextElement(KaxSegment::ClassInfos.Context, LowLevel, 0, false); // search up to one level lower
					UpperElementLevel = LowLevel;
#else // JUMP_TEST
					// read the data we care about in matroska
					/// \todo There should be a way to get the default values of the elements not defined
					ElementLevel2 = aStream.FindNextElement(ElementLevel1->Generic().Context, UpperElementLevel, 0, bAllowDummy);
					while (ElementLevel2 != NULL) {
						if (UpperElementLevel > 0) {
							break;
						}
						if (UpperElementLevel < 0) {
							UpperElementLevel = 0;
						}
						if (EbmlId(*ElementLevel2) == KaxTimecodeScale::ClassInfos.GlobalId) {
							KaxTimecodeScale *TimeScale = static_cast<KaxTimecodeScale*>(ElementLevel2);
							TimeScale->ReadData(aStream.I_O());
							printf("Timecode Scale %d\n", uint32(*TimeScale));
							TimecodeScale = uint64(*TimeScale);
						} else if (EbmlId(*ElementLevel2) == KaxDuration::ClassInfos.GlobalId) {
							printf("Segment duration\n");
						} else if (EbmlId(*ElementLevel2) == KaxDateUTC::ClassInfos.GlobalId) {
							printf("Date UTC\n");
						} else if (EbmlId(*ElementLevel2) == KaxTitle::ClassInfos.GlobalId) {
							printf("Title\n");
						} else if (EbmlId(*ElementLevel2) == KaxMuxingApp::ClassInfos.GlobalId) {
							KaxMuxingApp *pApp = static_cast<KaxMuxingApp*>(ElementLevel2);
							pApp->ReadData(aStream.I_O());
#if !defined(__CYGWIN__) && !defined(__APPLE__) && !defined(__BEOS__) && !defined(__NetBSD__)
							wprintf(L"Muxing App : %ls\n", UTFstring(*pApp).c_str());
#else
							printf("Muxing App : %s\n", UTFstring(*pApp).c_str());
#endif
						} else if (EbmlId(*ElementLevel2) == KaxWritingApp::ClassInfos.GlobalId) {
							KaxWritingApp *pApp = static_cast<KaxWritingApp*>(ElementLevel2);
							pApp->ReadData(aStream.I_O());
#if !defined(__CYGWIN__) && !defined(__APPLE__) && !defined(__BEOS__) && !defined(__NetBSD__)
							wprintf(L"Writing App : %ls (יאפן)\n", UTFstring(*pApp).c_str());
#else
							printf("Writing App : %s (יאפן)\n", UTFstring(*pApp).c_str());
#endif
						}

						if (UpperElementLevel > 0) {
							UpperElementLevel--;
							delete ElementLevel2;
							ElementLevel2 = ElementLevel3;
							if (UpperElementLevel > 0)
								break;
						} else {
							ElementLevel2->SkipData(aStream, ElementLevel2->Generic().Context);
							delete ElementLevel2;

							ElementLevel2 = aStream.FindNextElement(ElementLevel1->Generic().Context, UpperElementLevel, 0, bAllowDummy);
						}
					}
#endif // JUMP_TEST
				}

				else if (EbmlId(*ElementLevel1) == KaxCluster::ClassInfos.GlobalId) {
					printf("\n- Segment Clusters found\n");
					SegmentCluster = static_cast<KaxCluster *>(ElementLevel1);
//					SegmentCluster->ClearElement();
					uint32 ClusterTimecode;
					EbmlCrc32 *pChecksum = NULL;
					uint32 SizeInCrc;
					uint64 CrcPositionStart = 0;

#ifdef MEMORY_READ // read the Cluster in memory and then extract elements from memory
					SegmentCluster->Read(aStream, KaxCluster::ClassInfos.Context, UpperElementLevel, ElementLevel2, bAllowDummy);
					if (SegmentCluster->CheckMandatory()) {
						printf("  * All mandatory elements found *\n");
					} else {
						printf("  * Some mandatory elements ar missing !!! *\n");
					}
					
					// display the elements read
					unsigned int Index0;
					for (Index0 = 0; Index0<SegmentCluster->ListSize() ;Index0++) {
						printf(" - found %s\n", (*SegmentCluster)[Index0]->Generic().DebugName);
					}
#else // not MEMORY_READ
					// read blocks and discard the ones we don't care about
					ElementLevel2 = aStream.FindNextElement(ElementLevel1->Generic().Context, UpperElementLevel, 0, bAllowDummy);
					while (ElementLevel2 != NULL) {
						if (UpperElementLevel > 0) {
							break;
						}
						if (UpperElementLevel < 0) {
							UpperElementLevel = 0;
						}
						if (EbmlId(*ElementLevel2) == KaxClusterTimecode::ClassInfos.GlobalId) {
							printf("Cluster timecode found\n");
							KaxClusterTimecode & ClusterTime = *static_cast<KaxClusterTimecode*>(ElementLevel2);
							ClusterTime.ReadData(aStream.I_O());
							ClusterTimecode = uint32(ClusterTime);
							SegmentCluster->InitTimecode(ClusterTimecode, TimecodeScale);
						} else  if (EbmlId(*ElementLevel2) == KaxBlockGroup::ClassInfos.GlobalId) {
							printf("Block Group found\n");
#ifdef TEST_BLOCKGROUP_READ
							KaxBlockGroup & aBlockGroup = *static_cast<KaxBlockGroup*>(ElementLevel2);
//							aBlockGroup.ClearElement();
							// Extract the valuable data from the Block

							aBlockGroup.Read(aStream, KaxBlockGroup::ClassInfos.Context, UpperElementLevel, ElementLevel3, bAllowDummy);
							KaxBlock * DataBlock = static_cast<KaxBlock *>(aBlockGroup.FindElt(KaxBlock::ClassInfos));
							if (DataBlock != NULL) {
//								DataBlock->ReadData(aStream.I_O());
								DataBlock->SetParent(*SegmentCluster);
								printf("   Track # %d / %d frame%s / Timecode %I64d\n",DataBlock->TrackNum(), DataBlock->NumberFrames(), (DataBlock->NumberFrames() > 1)?"s":"", DataBlock->GlobalTimecode());
							} else {
								printf("   A BlockGroup without a Block !!!");
							}
							KaxBlockDuration * BlockDuration = static_cast<KaxBlockDuration *>(aBlockGroup.FindElt(KaxBlockDuration::ClassInfos));
							if (BlockDuration != NULL) {
								printf("  Block Duration %d scaled ticks : %ld ns\n", uint32(*BlockDuration), uint32(*BlockDuration) * TimecodeScale);
							}
							KaxReferenceBlock * RefTime = static_cast<KaxReferenceBlock *>(aBlockGroup.FindElt(KaxReferenceBlock::ClassInfos));
							if (RefTime != NULL) {
								printf("  Reference frame at scaled (%d) timecode %ld\n", int32(*RefTime), int32(int64(*RefTime) * TimecodeScale));
							}
#else // TEST_BLOCKGROUP_READ
							// read the data we care about in matroska
							/// \todo There should be a way to get the default values of the elements not defined
							ElementLevel3 = aStream.FindNextElement(ElementLevel2->Generic().Context, UpperElementLevel, 0, bAllowDummy);
							while (ElementLevel3 != NULL) {
								if (UpperElementLevel > 0) {
									break;
								}
								if (UpperElementLevel < 0) {
									UpperElementLevel = 0;
								}
								if (EbmlId(*ElementLevel3) == KaxBlock::ClassInfos.GlobalId) {
									printf(" Block Data\n");
									KaxBlock & DataBlock = *static_cast<KaxBlock*>(ElementLevel3);
#ifdef NO_DISPLAY_DATA
									DataBlock.ReadData(aStream.I_O(), SCOPE_PARTIAL_DATA);
#else // NO_DISPLAY_DATA
									DataBlock.ReadData(aStream.I_O(), SCOPE_ALL_DATA);
#endif // NO_DISPLAY_DATA
									DataBlock.SetParent(*SegmentCluster);
									printf("   Track # %d / %d frame%s / Timecode %I64d\n",DataBlock.TrackNum(), DataBlock.NumberFrames(), (DataBlock.NumberFrames() > 1)?"s":"", DataBlock.GlobalTimecode());
#ifndef NO_DISPLAY_DATA
									for (unsigned int i=0; i< DataBlock.NumberFrames(); i++) {
										printf("   [%s]\n",DataBlock.GetBuffer(i).Buffer()); // STRING ONLY POSSIBLE WITH THIS PARTICULAR EXAMPLE (the binary data is a string)
									}
#endif // NO_DISPLAY_DATA
//									printf("Codec ID   : %s\n", &binary(CodecID)); // strings for the moment (example)
#if MATROSKA_VERSION >= 2
								} else if (EbmlId(*ElementLevel3) == KaxBlockVirtual::ClassInfos.GlobalId) {
									printf(" Virtual Block\n");
								} else if (EbmlId(*ElementLevel3) == KaxReferenceVirtual::ClassInfos.GlobalId) {
									printf("  virtual Reference\n");
#endif // MATROSKA_VERSION
								} else if (EbmlId(*ElementLevel3) == KaxReferencePriority::ClassInfos.GlobalId) {
									printf("  Reference priority\n");
								} else if (EbmlId(*ElementLevel3) == KaxReferenceBlock::ClassInfos.GlobalId) {
									KaxReferenceBlock & RefTime = *static_cast<KaxReferenceBlock*>(ElementLevel3);
									RefTime.ReadData(aStream.I_O());
									printf("  Reference frame at scaled (%d) timecode %ld\n", int32(RefTime), int32(int64(RefTime) * TimecodeScale));
								} else if (EbmlId(*ElementLevel3) == KaxBlockDuration::ClassInfos.GlobalId) {
									KaxBlockDuration & BlockDuration = *static_cast<KaxBlockDuration*>(ElementLevel3);
									BlockDuration.ReadData(aStream.I_O());
									printf("  Block Duration %d scaled ticks : %ld ns\n", uint32(BlockDuration), uint32(BlockDuration) * TimecodeScale);
								}
								if (UpperElementLevel > 0) {
									UpperElementLevel--;
									delete ElementLevel3;
									ElementLevel3 = ElementLevel4;
									if (UpperElementLevel > 0)
										break;
								} else {
									ElementLevel3->SkipData(aStream, ElementLevel3->Generic().Context);

									ElementLevel3 = aStream.FindNextElement(ElementLevel2->Generic().Context, UpperElementLevel, 0, bAllowDummy);
								}
							}
#endif // TEST_BLOCKGROUP_READ
						} else if (EbmlId(*ElementLevel2) == EbmlCrc32::ClassInfos.GlobalId) {
							printf("Cluster CheckSum !\n");
							pChecksum = static_cast<EbmlCrc32*>(ElementLevel2);
							pChecksum->ReadData(aStream.I_O());
							SegmentCluster->ForceChecksum( pChecksum->GetCrc32() ); // not use later
							SizeInCrc = 0;
							CrcPositionStart = aStream.I_O().getFilePointer();
						}

						if (UpperElementLevel > 0) {
							UpperElementLevel--;
							delete ElementLevel2;
							ElementLevel2 = ElementLevel3;
							if (UpperElementLevel > 0)
								break;
						} else {
							ElementLevel2->SkipData(aStream, ElementLevel2->Generic().Context);
							if (ElementLevel2 != pChecksum)
								delete ElementLevel2;

							ElementLevel2 = aStream.FindNextElement(ElementLevel1->Generic().Context, UpperElementLevel, 0, bAllowDummy);
						}
					}
#endif // not MEMORY_READ
					if (pChecksum != NULL) {
						EbmlCrc32 ComputedChecksum;
						uint64 CurrPosition = aStream.I_O().getFilePointer();
						uint64 CrcPositionEnd = ElementLevel2->GetElementPosition();
						binary *SupposedBufferInCrc = new binary [CrcPositionEnd - CrcPositionStart];
						aStream.I_O().setFilePointer(CrcPositionStart);
						aStream.I_O().readFully(SupposedBufferInCrc, CrcPositionEnd - CrcPositionStart);
						aStream.I_O().setFilePointer(CurrPosition);
						ComputedChecksum.FillCRC32(SupposedBufferInCrc, CrcPositionEnd - CrcPositionStart);
						delete [] SupposedBufferInCrc;
						if (pChecksum->GetCrc32() == ComputedChecksum.GetCrc32()) {
							printf(" ++ CheckSum verification succeeded ++");
						} else {
							printf(" ++ CheckSum verification FAILED !!! ++");
						}
						delete pChecksum;
						pChecksum = NULL;
					}
				}
				else if (EbmlId(*ElementLevel1) == KaxCues::ClassInfos.GlobalId) {
					printf("\n- Cue entries found\n");
					CuesEntry = static_cast<KaxCues *>(ElementLevel1);
					CuesEntry->SetGlobalTimecodeScale(TimecodeScale);
					// read everything in memory
					CuesEntry->Read(aStream, KaxCues::ClassInfos.Context, UpperElementLevel, ElementLevel2, bAllowDummy); // build the entries in memory
					if (CuesEntry->CheckMandatory()) {
						printf("  * All mandatory elements found *\n");
					} else {
						printf("  * Some mandatory elements ar missing !!! *\n");
					}
					CuesEntry->Sort();
					// display the elements read
					unsigned int Index0;
					for (Index0 = 0; Index0<CuesEntry->ListSize() ;Index0++) {
						if ((*CuesEntry)[Index0]->Generic().GlobalId == KaxCuePoint::ClassInfos.GlobalId) {
							printf(" Cue Point\n");

							KaxCuePoint & CuePoint = *static_cast<KaxCuePoint *>((*CuesEntry)[Index0]);
							unsigned int Index1;
							for (Index1 = 0; Index1<CuePoint.ListSize() ;Index1++) {
								if (CuePoint[Index1]->Generic().GlobalId == KaxCueTime::ClassInfos.GlobalId) {
									KaxCueTime & CueTime = *static_cast<KaxCueTime *>(CuePoint[Index1]);
									printf("  Time %ld\n", uint64(CueTime) * TimecodeScale);
								} else if (CuePoint[Index1]->Generic().GlobalId == KaxCueTrackPositions::ClassInfos.GlobalId) {
									KaxCueTrackPositions & CuePos = *static_cast<KaxCueTrackPositions *>(CuePoint[Index1]);
									printf("  Positions\n");

									unsigned int Index2;
									for (Index2 = 0; Index2<CuePos.ListSize() ;Index2++) {
										if (CuePos[Index2]->Generic().GlobalId == KaxCueTrack::ClassInfos.GlobalId) {
											KaxCueTrack & CueTrack = *static_cast<KaxCueTrack *>(CuePos[Index2]);
											printf("   Track %d\n", uint16(CueTrack));
										} else if (CuePos[Index2]->Generic().GlobalId == KaxCueClusterPosition::ClassInfos.GlobalId) {
											KaxCueClusterPosition & CuePoss = *static_cast<KaxCueClusterPosition *>(CuePos[Index2]);
											printf("   Cluster position %d\n", uint64(CuePoss));
#if MATROSKA_VERSION >= 2
										} else if (CuePos[Index2]->Generic().GlobalId == KaxCueReference::ClassInfos.GlobalId) {
											KaxCueReference & CueRefs = *static_cast<KaxCueReference *>(CuePos[Index2]);
											printf("   Reference\n");

											unsigned int Index3;
											for (Index3 = 0; Index3<CueRefs.ListSize() ;Index3++) {
												if (CueRefs[Index3]->Generic().GlobalId == KaxCueRefTime::ClassInfos.GlobalId) {
													KaxCueRefTime & CueTime = *static_cast<KaxCueRefTime *>(CueRefs[Index3]);
													printf("    Time %d\n", uint32(CueTime));
												} else if (CueRefs[Index3]->Generic().GlobalId == KaxCueRefCluster::ClassInfos.GlobalId) {
													KaxCueRefCluster & CueClust = *static_cast<KaxCueRefCluster *>(CueRefs[Index3]);
													printf("    Cluster position %d\n", uint64(CueClust));
												} else {
													printf("    - found %s\n", CueRefs[Index3]->Generic().DebugName);
												}
											}
#endif // MATROSKA_VERSION
										} else {
											printf("   - found %s\n", CuePos[Index2]->Generic().DebugName);
										}
									}
								} else {
									printf("  - found %s\n", CuePoint[Index1]->Generic().DebugName);
								}
							}
						} else {
							printf(" - found %s\n", (*CuesEntry)[Index0]->Generic().DebugName);
						}
					}
				}
				else if (EbmlId(*ElementLevel1) == KaxSeekHead::ClassInfos.GlobalId) {
					printf("\n- Meta Seek found\n");
					MetaSeek = static_cast<KaxSeekHead *>(ElementLevel1);
					// read it in memory
					MetaSeek->Read(aStream, KaxSeekHead::ClassInfos.Context, UpperElementLevel, ElementLevel2, bAllowDummy);
					if (MetaSeek->CheckMandatory()) {
						printf("  * All mandatory elements found *\n");
					} else {
						printf("  * Some mandatory elements ar missing !!! *\n");
					}
					unsigned int Index0;
					for (Index0 = 0; Index0<MetaSeek->ListSize() ;Index0++) {
						if ((*MetaSeek)[Index0]->Generic().GlobalId == KaxSeek::ClassInfos.GlobalId) {
							printf("   Seek Point\n");
							KaxSeek & SeekPoint = *static_cast<KaxSeek *>((*MetaSeek)[Index0]);
							unsigned int Index1;
							for (Index1 = 0; Index1<SeekPoint.ListSize() ;Index1++) {
								if (SeekPoint[Index1]->Generic().GlobalId == KaxSeekID::ClassInfos.GlobalId) {
									KaxSeekID * SeekID = static_cast<KaxSeekID *>(SeekPoint[Index1]);
									printf("    Seek ID ", SeekID->GetBuffer());
									for (unsigned int i=0; i<SeekID->GetSize(); i++) {
										printf("%02X", SeekID->GetBuffer()[i]);
									}
									printf("\n");
								} else if (SeekPoint[Index1]->Generic().GlobalId == KaxSeekPosition::ClassInfos.GlobalId) {
									KaxSeekPosition * SeekPos = static_cast<KaxSeekPosition *>(SeekPoint[Index1]);
									printf("    Seek position %d\n", uint32(*SeekPos));
								}
							}
						}
					}
				} else if (EbmlId(*ElementLevel1) == KaxChapters::ClassInfos.GlobalId) {
					printf("\n- Chapters found\n");
					Chapters = static_cast<KaxChapters *>(ElementLevel1);
					// read it in memory
					Chapters->Read(aStream, KaxChapters::ClassInfos.Context, UpperElementLevel, ElementLevel2, bAllowDummy);
					if (Chapters->CheckMandatory()) {
						printf("  * All mandatory elements found *\n");
					} else {
						printf("  * Some mandatory elements ar missing !!! *\n");
					}
					unsigned int Index0;
					for (Index0 = 0; Index0<Chapters->ListSize() ;Index0++) {
						if ((*Chapters)[Index0]->Generic().GlobalId == KaxEditionEntry::ClassInfos.GlobalId) {
							printf("   Edition\n");
							KaxEditionEntry & Edition = *static_cast<KaxEditionEntry *>((*Chapters)[Index0]);
							unsigned int Index2;
							for (Index2 = 0; Index2<Edition.ListSize() ;Index2++) {
								if (Edition[Index2]->Generic().GlobalId == KaxChapterAtom::ClassInfos.GlobalId) {
									printf("     Chapter Atom\n");
									KaxChapterAtom & aChapterAtom = *static_cast<KaxChapterAtom *>(Edition[Index2]);
									unsigned int Index3;
									for (Index3 = 0; Index3<aChapterAtom.ListSize() ;Index3++) {
										if (aChapterAtom[Index3]->Generic().GlobalId == KaxChapterUID::ClassInfos.GlobalId) {
											printf("      Chapter UID 0x%08x\n", uint32(*static_cast<EbmlUInteger *>(aChapterAtom[Index3])) );
										} else if (aChapterAtom[Index3]->Generic().GlobalId == KaxChapterTimeStart::ClassInfos.GlobalId) {
											printf("      Time Start %d\n", uint32(*static_cast<EbmlUInteger *>(aChapterAtom[Index3])) );
										} else if (aChapterAtom[Index3]->Generic().GlobalId == KaxChapterTimeEnd::ClassInfos.GlobalId) {
											printf("      Time End %d ns\n", uint32(*static_cast<EbmlUInteger *>(aChapterAtom[Index3])) );
										} else if (aChapterAtom[Index3]->Generic().GlobalId == KaxChapterTrack::ClassInfos.GlobalId) {
											printf("      Track list\n");
										} else if (aChapterAtom[Index3]->Generic().GlobalId == KaxChapterDisplay::ClassInfos.GlobalId) {
											printf("      Display info\n");
											KaxChapterDisplay & aDisplay = *static_cast<KaxChapterDisplay *>(aChapterAtom[Index3]);
											unsigned int Index4;
											for (Index4 = 0; Index4<aDisplay.ListSize() ;Index4++) {
												if (aDisplay[Index4]->Generic().GlobalId == KaxChapterString::ClassInfos.GlobalId) {
#if !defined(__CYGWIN__) && !defined(__APPLE__) && !defined(__BEOS__) && !defined(__NetBSD__)
													wprintf(L"       Display \"%s\"\n", UTFstring(*static_cast<EbmlUnicodeString *>(aDisplay[Index4])).c_str() );
#else
													printf("       Display \"%s\"\n", UTFstring(*static_cast<EbmlUnicodeString *>(aDisplay[Index4])).c_str() );
#endif
												} else if (aDisplay[Index4]->Generic().GlobalId == KaxChapterLanguage::ClassInfos.GlobalId) {
													printf("       For language \"%s\"\n", std::string(*static_cast<EbmlString *>(aDisplay[Index4])).c_str() );
												} else if (aDisplay[Index4]->Generic().GlobalId == KaxChapterCountry::ClassInfos.GlobalId) {
													printf("       For country \"%s\"\n", std::string(*static_cast<EbmlString *>(aDisplay[Index4])).c_str() );
												} else if (aDisplay[Index4]->IsDummy()) {
													printf("       Dummy !!!\n");
												}
											}
										}
									}
								}
							}
						}
					}
				} else if (EbmlId(*ElementLevel1) == KaxTags::ClassInfos.GlobalId) {
					printf("\n- Tags found\n");
					AllTags = static_cast<KaxTags *>(ElementLevel1);
					// read it in memory
					AllTags->Read(aStream, KaxTags::ClassInfos.Context, UpperElementLevel, ElementLevel2, bAllowDummy);
					if (AllTags->CheckMandatory()) {
						printf("  * All mandatory elements found *\n");
					} else {
						printf("  * Some mandatory elements ar missing !!! *\n");
					}
					unsigned int Index0;
					for (Index0 = 0; Index0<AllTags->ListSize() ;Index0++) {
						if ((*AllTags)[Index0]->Generic().GlobalId == KaxTag::ClassInfos.GlobalId) {
							printf("   Tag\n");
							KaxTag & TagElt = *static_cast<KaxTag *>((*AllTags)[Index0]);
							unsigned int Index1;
							for (Index1 = 0; Index1<TagElt.ListSize() ;Index1++) {
// 								bool bRemoved = false, bRemovedDone = true;
								if (TagElt[Index1]->Generic().GlobalId == KaxTagTargets::ClassInfos.GlobalId) {
									printf("    Targets\n");
									KaxTagTargets & Targets = *static_cast<KaxTagTargets *>(TagElt[Index1]);
									unsigned int Index2;
									for (Index2 = 0; Index2<Targets.ListSize() ;Index2++) {
										if (Targets[Index2]->Generic().GlobalId == KaxTagTrackUID::ClassInfos.GlobalId) {
#ifndef TEST_REMOVE
											printf("     Track UID\n");
#else // TEST_REMOVE
											printf("     Track UID (will be removed)\n");
											/*************** Test to remove an element ***************/
											Targets.Remove(Index2);
											bRemoved = true;
											bRemovedDone = false;
											Index2--;
											Index1--;
#endif // TEST_REMOVE
										} else if (Targets[Index2]->Generic().GlobalId == KaxTagChapterUID::ClassInfos.GlobalId) {
											printf("     Chapter UID\n");
#if 0
										} else if (Targets[Index2]->Generic().GlobalId == KaxTagMultiComment::ClassInfos.GlobalId) {
											printf("     Comment\n");
											KaxTagMultiComment & Comment = *static_cast<KaxTagMultiComment *>(Targets[Index2]);
											unsigned int Index3;
											for (Index3 = 0; Index3<Comment.ListSize() ;Index3++) {
												if (Comment[Index3]->Generic().GlobalId == KaxTagMultiCommentName::ClassInfos.GlobalId) {
													KaxTagMultiCommentName & CommentName = *static_cast<KaxTagMultiCommentName *>(Comment[Index3]);
													printf("      Comment Name \"%s\"\n", std::string(CommentName).c_str());
												}	
											}
//										} else if (Targets[Index2]->Generic().GlobalId == DummyRawElement::ClassInfos.GlobalId) {
#endif
										}
									}
#ifdef TEST_REMOVE
									if (bRemoved) {
										printf("    -- Again After Deletion --\n");
										bRemoved = false;
									} else if (bRemovedDone) {
										printf("    -- Done --\n");
									}
#endif // TEST_REMOVE
#if 0
								} else if (TagElt[Index1]->Generic().GlobalId == KaxTagGeneral::ClassInfos.GlobalId) {
									printf("    General\n");
									KaxTagGeneral & General = *static_cast<KaxTagGeneral *>(TagElt[Index1]);
									unsigned int Index2;
									for (Index2 = 0; Index2<General.ListSize() ;Index2++) {
										if (General[Index2]->Generic().GlobalId == KaxTagSubject::ClassInfos.GlobalId) {
											printf("     Subject\n");
										} else if (General[Index2]->Generic().GlobalId == KaxTagBibliography::ClassInfos.GlobalId) {
											printf("     Bibliography\n");
										} else if (General[Index2]->Generic().GlobalId == KaxTagLanguage::ClassInfos.GlobalId) {
											printf("     Language\n");
										}	
									}
								} else if (TagElt[Index1]->Generic().GlobalId == KaxTagMultiCommercial::ClassInfos.GlobalId) {
									printf("    MultiCommercial\n");
									KaxTagMultiCommercial & Commercials = *static_cast<KaxTagMultiCommercial *>(TagElt[Index1]);
									unsigned int Index2;
									for (Index2 = 0; Index2<Commercials.ListSize() ;Index2++) {
										if (Commercials[Index2]->Generic().GlobalId == KaxTagCommercial::ClassInfos.GlobalId) {
											printf("     Commercial\n");
											KaxTagCommercial & Commercial = *static_cast<KaxTagCommercial *>(Commercials[Index2]);
											unsigned int Index3;
											for (Index3 = 0; Index3<Commercial.ListSize() ;Index3++) {
												if (Commercial[Index3]->Generic().GlobalId == KaxTagMultiCommercialType::ClassInfos.GlobalId) {
													printf("      Type\n");
												} else if (Commercial[Index3]->Generic().GlobalId == KaxTagMultiPrice::ClassInfos.GlobalId) {
													printf("      Prices\n");
													KaxTagMultiPrice & Prices = *static_cast<KaxTagMultiPrice *>(Commercial[Index3]);
													unsigned int Index4;
													for (Index4 = 0; Index4<Prices.ListSize(); Index4++) {
														if (Prices[Index4]->Generic().GlobalId == KaxTagMultiPriceCurrency::ClassInfos.GlobalId) {
															printf("       Currency\n");
														} else if (Prices[Index4]->Generic().GlobalId == KaxTagMultiPriceAmount::ClassInfos.GlobalId) {
															printf("       Amount\n");
														}	
													}
												}	
											}
										}	
									}
								} else if (TagElt[Index1]->Generic().GlobalId == KaxTagMultiDate::ClassInfos.GlobalId) {
									printf("    MultiDate\n");
								} else if (TagElt[Index1]->Generic().GlobalId == KaxTagMultiComment::ClassInfos.GlobalId) {
									printf("    Comment\n");
									KaxTagMultiComment & Comment = *static_cast<KaxTagMultiComment *>(TagElt[Index1]);
									unsigned int Index2;
									for (Index2 = 0; Index2<Comment.ListSize() ;Index2++) {
										if (Comment[Index2]->Generic().GlobalId == KaxTagMultiCommentName::ClassInfos.GlobalId) {
											KaxTagMultiCommentName & CommentName = *static_cast<KaxTagMultiCommentName *>(Comment[Index2]);
											printf("     Comment Name \"%s\"\n", std::string(CommentName).c_str());
										}	
									}
#endif
								}
							}
						}
					}
					if (AllTags->HasChecksum()) {
						if (AllTags->VerifyChecksum()) {
							printf(" ++ CheckSum verification succeeded ++\n");
						} else {
							printf(" ++ CheckSum verification FAILED !!! ++\n");
						}
					}
				}

				if (UpperElementLevel > 0) {
					UpperElementLevel--;
					delete ElementLevel1;
					ElementLevel1 = ElementLevel2;
					if (UpperElementLevel > 0)
						break;
				} else {
					ElementLevel1->SkipData(aStream, ElementLevel1->Generic().Context);
					delete ElementLevel1;
			
					ElementLevel1 = aStream.FindNextElement(ElementLevel0->Generic().Context, UpperElementLevel, 0, bAllowDummy);
				}
			}
		}
	}

#ifdef OLD
	uint8 TrackNumber = MuxedFile.GetTrackNumber();

	TrackInfo *Tracks = new TrackInfo[TrackNumber];
	TrackInfoAudio aAudioTrack;
	TrackInfoVideo aVideoTrack;

	Track * track1 = MuxedFile.GetTrack(1);
	Track * track2 = MuxedFile.GetTrack(2);
	Track * track3 = MuxedFile.GetTrack(3); // should be 0
	// get information about the 1st track

	MuxedFile.Track_GetInfo(track1, Tracks[0]);
	displayTrackInfo(Tracks[0]);

	if (Tracks[0].TrackType == track_audio) {
	    MuxedFile.Track_GetInfo_Audio(track1, aAudioTrack);
	    displayAudioInfo(aAudioTrack);
	}
	else
	    cout << "the expected audio track is not an audio one :(" << endl;

	MuxedFile.Track_GetInfo(track3, Tracks[2]);
	displayTrackInfo(Tracks[2]);

	if (Tracks[2].TrackType == track_video) {
	    MuxedFile.Track_GetInfo_Video(track3, aVideoTrack);
	    displayVideoInfo(aVideoTrack);
	}
	else
	    cout << "the expected video track is not an video one :(" << endl;

	// let's read only track1 (audio)
	MuxedFile.SelectReadingTrack(track1);
	MuxedFile.SelectReadingTrack(track2);
	MuxedFile.SelectReadingTrack(track1,false);
	MuxedFile.SelectReadingTrack(track1);
	MuxedFile.SelectReadingTrack(track2,false);
	MuxedFile.SelectReadingTrack(track2);
	MuxedFile.SelectReadingTrack(track3);

	// read the frames from the selected tracks and put them in an output file
	StdIOCallback Output_file1("out-binr.bin", MODE_CREATE);
	StdIOCallback Output_file2("out-text.bin", MODE_CREATE);
	StdIOCallback Output_file3("out-vide.bin", MODE_CREATE);

	Track * TrackRead;
	uint32 timecode; // not used yet
	binary *aFrame;
	uint32 aFrameSize;
	while (MuxedFile.ReadFrame(TrackRead, timecode, aFrame, aFrameSize))
	{
	    if (TrackRead == track1)
	    {
		Output_file1.write(aFrame, aFrameSize);
	    }
	    else if (TrackRead == track2)
	    {
		Output_file2.write(aFrame, aFrameSize);
	    }
	    else if (TrackRead == track3)
	    {
		Output_file3.write(aFrame, aFrameSize);
	    }
	    else cout << "received a frame from an unwanted track" << endl;
	}
#endif // OLD
    }
    catch (exception & Ex)
    {
		cout << Ex.what() << endl;
		return -1;
    }

    return 0;
}
