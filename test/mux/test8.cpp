// Copyright © 2002-2004 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
    \file
    \brief Test reading of the Header
    \author Steve Lhomme     <robux4 @ users.sf.net>
*/

#include <iostream>
#include <cassert>
#include <cinttypes>

#include <ebml/EbmlHead.h>
#include <ebml/EbmlSubHead.h>
#include <ebml/EbmlStream.h>
#include <ebml/EbmlContexts.h>
#include <ebml/EbmlVoid.h>
#include <ebml/EbmlCrc32.h>
#include "matroska/FileKax.h"
#include "matroska/KaxSegment.h"
#include "matroska/KaxContexts.h"
#include "matroska/KaxTracks.h"
#include "matroska/KaxCluster.h"
#include "matroska/KaxBlockData.h"
#include "matroska/KaxSeekHead.h"
#include "matroska/KaxCuesData.h"
#include <ebml/StdIOCallback.h>

using namespace libmatroska;
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
///  FileKax MuxedFile(Cluster_file);
//  bool bAllowDummy = false; // don't read elements we don't know
  bool bAllowDummy = true; // even read elements we don't know (needed for CRC checking)

  // read the EBML head
  EbmlStream aStream(Cluster_file);
  EbmlElement * ElementLevel0 = nullptr;
  EbmlElement * ElementLevel1 = nullptr;
  EbmlElement * ElementLevel2 = nullptr;
  EbmlElement * ElementLevel3 = nullptr;
  EbmlElement * ElementLevel4 = nullptr;

///  MuxedFile.ReadHead();
  // find the EBML head in the file
  ElementLevel0 = aStream.FindNextID(EBML_INFO(EbmlHead), 0xFFFFFFFFL);
  if (ElementLevel0 != NULL)
  {
    printf("EBML : ");
    for (unsigned int i=EbmlId(*ElementLevel0).GetLength(); i; i++)
    {
      printf("[%02X]", (EbmlId(*ElementLevel0).GetValue() >> ((i-1)*8)) & 0xFF);
    }
    printf("\n");

    ElementLevel0->SkipData(aStream, EBML_CLASS_SEMCONTEXT(EbmlHead));
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
  std::uint64_t TimecodeScale = 1000000;

  // find the segment to read
  ElementLevel0 = aStream.FindNextID(EBML_INFO(KaxSegment), 0xFFFFFFFFL);
  if (ElementLevel0 != NULL)
  {
    if (EbmlId(*ElementLevel0) == EBML_ID(KaxSegment)) {
      Segment = static_cast<KaxSegment*>(ElementLevel0);
//      MuxedFile.ReadTracks();
//      MuxedFile.ReadCodec();
      // scan the file for a Tracks element (all previous Level1 elements are discarded)
      ElementLevel1 = aStream.FindNextElement(EBML_CONTEXT(ElementLevel0), UpperElementLevel, 0, bAllowDummy);

      while (ElementLevel1 != NULL) {
        if (UpperElementLevel > 0) {
          break;
        }
        if (UpperElementLevel < 0) {
          UpperElementLevel = 0;
        }

        /// \todo switch the type of the element to check if it's one we want to handle, like attachements
        if (EbmlId(*ElementLevel1) == EBML_ID(EbmlVoid)) {
          printf("\n- Void found\n");
        } else if (EbmlId(*ElementLevel1) == EBML_ID(KaxTracks)) {
          // found the Tracks element
          printf("\n- Segment Tracks found\n");
          // handle the data in Tracks here.
          // poll for new tracks and handle them
          ElementLevel2 = aStream.FindNextElement(EBML_CONTEXT(ElementLevel1), UpperElementLevel, 0, bAllowDummy);

          while (ElementLevel2 != NULL) {
            if (UpperElementLevel > 0) {
              break;
            }
            if (UpperElementLevel < 0) {
              UpperElementLevel = 0;
            }
            /// \todo switch the type of the element to check if it's one we want to handle, like attachements
            if (EbmlId(*ElementLevel2) == EBML_ID(KaxTrackEntry)) {
              printf("* Found a track\n");

              ElementLevel3 = aStream.FindNextElement(EBML_CONTEXT(ElementLevel2), UpperElementLevel, 0, bAllowDummy);
              while (ElementLevel3 != NULL) {
                if (UpperElementLevel > 0) {
                  break;
                }
                if (UpperElementLevel < 0) {
                  UpperElementLevel = 0;
                }
                // read the data we care about in a track
                // Track number
                if (EbmlId(*ElementLevel3) == EBML_ID(KaxTrackNumber)) {
                  KaxTrackNumber & TrackNum = *static_cast<KaxTrackNumber*>(ElementLevel3);
                  TrackNum.ReadData(aStream.I_O());
                  printf("Track # %d\n", std::uint8_t(TrackNum));
                }

                // Track type
                else if (EbmlId(*ElementLevel3) == EBML_ID(KaxTrackType)) {
                  KaxTrackType & TrackType = *static_cast<KaxTrackType*>(ElementLevel3);
                  TrackType.ReadData(aStream.I_O());
                  printf("Track type : ");
                  switch(std::uint8_t(TrackType))
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

                else if (EbmlId(*ElementLevel3) == EBML_ID(KaxTrackFlagLacing)) {
                  printf("Flag Lacing\n");
                }
                else if (EbmlId(*ElementLevel3) == EBML_ID(KaxCodecID)) {
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
                  ElementLevel3->SkipData(aStream, EBML_CONTEXT(ElementLevel3));
                  delete ElementLevel3;

                  ElementLevel3 = aStream.FindNextElement(EBML_CONTEXT(ElementLevel2), UpperElementLevel, 0, bAllowDummy);
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
              ElementLevel2->SkipData(aStream, EBML_CONTEXT(ElementLevel2));
              delete ElementLevel2;

              ElementLevel2 = aStream.FindNextElement(EBML_CONTEXT(ElementLevel1), UpperElementLevel, 0, bAllowDummy);
            }
          }
        }

        else if (EbmlId(*ElementLevel1) == EBML_ID(KaxInfo)) {
          printf("\n- Segment Informations found\n");
          SegmentInfo = static_cast<KaxInfo *>(ElementLevel1);

#ifdef JUMP_TEST
          // test jumping to a random location and find the next Level 0 / Level 1 element
          aStream.I_O().setFilePointer(79, seek_current);
          printf("Seeked at position 0x%X in the file", aStream.I_O().getFilePointer());
          int LowLevel = 1;
          ElementLevel2 = aStream.FindNextElement(EBML_CLASS_CONTEXT(KaxSegment), LowLevel, 0, false); // search up to one level lower
          UpperElementLevel = LowLevel;
#else // JUMP_TEST
          // read the data we care about in matroska
          /// \todo There should be a way to get the default values of the elements not defined
          ElementLevel2 = aStream.FindNextElement(EBML_CONTEXT(ElementLevel1), UpperElementLevel, 0, bAllowDummy);
          while (ElementLevel2 != NULL) {
            if (UpperElementLevel > 0) {
              break;
            }
            if (UpperElementLevel < 0) {
              UpperElementLevel = 0;
            }
            if (EbmlId(*ElementLevel2) == EBML_ID(KaxTimecodeScale)) {
              KaxTimecodeScale *TimeScale = static_cast<KaxTimecodeScale*>(ElementLevel2);
              TimeScale->ReadData(aStream.I_O());
              printf("Timecode Scale %d\n", std::uint32_t(*TimeScale));
              TimecodeScale = std::uint64_t(*TimeScale);
            } else if (EbmlId(*ElementLevel2) == EBML_ID(KaxDuration)) {
              printf("Segment duration\n");
            } else if (EbmlId(*ElementLevel2) == EBML_ID(KaxDateUTC)) {
              printf("Date UTC\n");
            } else if (EbmlId(*ElementLevel2) == EBML_ID(KaxTitle)) {
              printf("Title\n");
            } else if (EbmlId(*ElementLevel2) == EBML_ID(KaxMuxingApp)) {
              KaxMuxingApp *pApp = static_cast<KaxMuxingApp*>(ElementLevel2);
              pApp->ReadData(aStream.I_O());
              printf("Muxing App : %s\n", UTFstring(*pApp).GetUTF8().c_str());
            } else if (EbmlId(*ElementLevel2) == EBML_ID(KaxWritingApp)) {
              KaxWritingApp *pApp = static_cast<KaxWritingApp*>(ElementLevel2);
              pApp->ReadData(aStream.I_O());
              printf("Writing App : %s (����)\n", UTFstring(*pApp).GetUTF8().c_str());
            }

            if (UpperElementLevel > 0) {
              UpperElementLevel--;
              delete ElementLevel2;
              ElementLevel2 = ElementLevel3;
              if (UpperElementLevel > 0)
                break;
            } else {
              ElementLevel2->SkipData(aStream, EBML_CONTEXT(ElementLevel2));
              delete ElementLevel2;

              ElementLevel2 = aStream.FindNextElement(EBML_CONTEXT(ElementLevel1), UpperElementLevel, 0, bAllowDummy);
            }
          }
#endif // JUMP_TEST
        }

        else if (EbmlId(*ElementLevel1) == EBML_ID(KaxCluster)) {
          printf("\n- Segment Clusters found\n");
          SegmentCluster = static_cast<KaxCluster *>(ElementLevel1);
//          SegmentCluster->ClearElement();
          std::uint32_t ClusterTimecode;
          EbmlCrc32 *pChecksum = NULL;
          std::uint64_t CrcPositionStart = 0;

#ifdef MEMORY_READ // read the Cluster in memory and then extract elements from memory
          SegmentCluster->Read(aStream, EBML_CLASS_CONTEXT(KaxCluster), UpperElementLevel, ElementLevel2, bAllowDummy);
          if (SegmentCluster->CheckMandatory()) {
            printf("  * All mandatory elements found *\n");
          } else {
            printf("  * Some mandatory elements ar missing !!! *\n");
          }

          // display the elements read
          unsigned int Index0;
          for (Index0 = 0; Index0<SegmentCluster->ListSize() ;Index0++) {
            printf(" - found %s\n", EBML_NAME((*SegmentCluster)[Index0]));
          }
#else // not MEMORY_READ
          // read blocks and discard the ones we don't care about
          ElementLevel2 = aStream.FindNextElement(EBML_CONTEXT(ElementLevel1), UpperElementLevel, 0, bAllowDummy);
          while (ElementLevel2 != NULL) {
            if (UpperElementLevel > 0) {
              break;
            }
            if (UpperElementLevel < 0) {
              UpperElementLevel = 0;
            }
            if (EbmlId(*ElementLevel2) == EBML_ID(KaxClusterTimecode)) {
              printf("Cluster timecode found\n");
              KaxClusterTimecode & ClusterTime = *static_cast<KaxClusterTimecode*>(ElementLevel2);
              ClusterTime.ReadData(aStream.I_O());
              ClusterTimecode = std::uint32_t(ClusterTime);
              SegmentCluster->InitTimecode(ClusterTimecode, TimecodeScale);
            } else  if (EbmlId(*ElementLevel2) == EBML_ID(KaxBlockGroup)) {
              printf("Block Group found\n");
#ifdef TEST_BLOCKGROUP_READ
              KaxBlockGroup & aBlockGroup = *static_cast<KaxBlockGroup*>(ElementLevel2);
//              aBlockGroup.ClearElement();
              // Extract the valuable data from the Block

              aBlockGroup.Read(aStream, EBML_CLASS_CONTEXT(KaxBlockGroup), UpperElementLevel, ElementLevel3, bAllowDummy);
              KaxBlock * DataBlock = static_cast<KaxBlock *>(aBlockGroup.FindElt(EBML_INFO(KaxBlock)));
              if (DataBlock != NULL) {
//                DataBlock->ReadData(aStream.I_O());
                DataBlock->SetParent(*SegmentCluster);
                printf("   Track # %d / %d frame%s / Timecode %I64d\n",DataBlock->TrackNum(), DataBlock->NumberFrames(), (DataBlock->NumberFrames() > 1)?"s":"", DataBlock->GlobalTimecode());
              } else {
                printf("   A BlockGroup without a Block !!!");
              }
              KaxBlockDuration * BlockDuration = static_cast<KaxBlockDuration *>(aBlockGroup.FindElt(EBML_INFO(KaxBlockDuration)));
              if (BlockDuration != NULL) {
                printf("  Block Duration %d scaled ticks : %ld ns\n", std::uint32_t(*BlockDuration), std::uint32_t(*BlockDuration) * TimecodeScale);
              }
              KaxReferenceBlock * RefTime = static_cast<KaxReferenceBlock *>(aBlockGroup.FindElt(EBML_INFO(KaxReferenceBlock)));
              if (RefTime != NULL) {
                printf("  Reference frame at scaled (%d) timecode %ld\n", std::int32_t(*RefTime), std::int32_t(std::int64_t(*RefTime) * TimecodeScale));
              }
#else // TEST_BLOCKGROUP_READ
              // read the data we care about in matroska
              /// \todo There should be a way to get the default values of the elements not defined
              ElementLevel3 = aStream.FindNextElement(EBML_CONTEXT(ElementLevel2), UpperElementLevel, 0, bAllowDummy);
              while (ElementLevel3 != NULL) {
                if (UpperElementLevel > 0) {
                  break;
                }
                if (UpperElementLevel < 0) {
                  UpperElementLevel = 0;
                }
                if (EbmlId(*ElementLevel3) == EBML_ID(KaxBlock)) {
                  printf(" Block Data\n");
                  KaxBlock & DataBlock = *static_cast<KaxBlock*>(ElementLevel3);
#ifdef NO_DISPLAY_DATA
                  DataBlock.ReadData(aStream.I_O(), SCOPE_PARTIAL_DATA);
#else // NO_DISPLAY_DATA
                  DataBlock.ReadData(aStream.I_O(), SCOPE_ALL_DATA);
#endif // NO_DISPLAY_DATA
                  DataBlock.SetParent(*SegmentCluster);
                  printf("   Track # %d / %d frame%s / Timecode %" PRId64 "\n",DataBlock.TrackNum(), DataBlock.NumberFrames(), (DataBlock.NumberFrames() > 1)?"s":"", DataBlock.GlobalTimecode());
#ifndef NO_DISPLAY_DATA
                  for (unsigned int i=0; i< DataBlock.NumberFrames(); i++) {
                    printf("   [%s]\n",DataBlock.GetBuffer(i).Buffer()); // STRING ONLY POSSIBLE WITH THIS PARTICULAR EXAMPLE (the binary data is a string)
                  }
#endif // NO_DISPLAY_DATA
//                  printf("Codec ID   : %s\n", &binary(CodecID)); // strings for the moment (example)
                } else if (EbmlId(*ElementLevel3) == EBML_ID(KaxBlockVirtual)) {
                  printf(" Virtual Block\n");
                } else if (EbmlId(*ElementLevel3) == EBML_ID(KaxReferenceVirtual)) {
                  printf("  virtual Reference\n");
                } else if (EbmlId(*ElementLevel3) == EBML_ID(KaxReferencePriority)) {
                  printf("  Reference priority\n");
                } else if (EbmlId(*ElementLevel3) == EBML_ID(KaxReferenceBlock)) {
                  KaxReferenceBlock & RefTime = *static_cast<KaxReferenceBlock*>(ElementLevel3);
                  RefTime.ReadData(aStream.I_O());
                  printf("  Reference frame at scaled (%d) timecode %" PRId32 "\n", std::int32_t(RefTime), std::int32_t(std::int64_t(RefTime) * TimecodeScale));
                } else if (EbmlId(*ElementLevel3) == EBML_ID(KaxBlockDuration)) {
                  KaxBlockDuration & BlockDuration = *static_cast<KaxBlockDuration*>(ElementLevel3);
                  BlockDuration.ReadData(aStream.I_O());
                  printf("  Block Duration %" PRIu32 " scaled ticks : %" PRIu64 " ns\n", std::uint32_t(BlockDuration), std::uint32_t(BlockDuration) * TimecodeScale);
                }
                if (UpperElementLevel > 0) {
                  UpperElementLevel--;
                  delete ElementLevel3;
                  ElementLevel3 = ElementLevel4;
                  if (UpperElementLevel > 0)
                    break;
                } else {
                  ElementLevel3->SkipData(aStream, EBML_CONTEXT(ElementLevel3));

                  ElementLevel3 = aStream.FindNextElement(EBML_CONTEXT(ElementLevel2), UpperElementLevel, 0, bAllowDummy);
                }
              }
#endif // TEST_BLOCKGROUP_READ
            } else if (EbmlId(*ElementLevel2) == EBML_ID(EbmlCrc32)) {
              printf("Cluster CheckSum !\n");
              pChecksum = static_cast<EbmlCrc32*>(ElementLevel2);
              pChecksum->ReadData(aStream.I_O());
              SegmentCluster->ForceChecksum( pChecksum->GetCrc32() ); // not use later
              CrcPositionStart = aStream.I_O().getFilePointer();
            }

            if (UpperElementLevel > 0) {
              UpperElementLevel--;
              delete ElementLevel2;
              ElementLevel2 = ElementLevel3;
              if (UpperElementLevel > 0)
                break;
            } else {
              ElementLevel2->SkipData(aStream, EBML_CONTEXT(ElementLevel2));
              if (ElementLevel2 != pChecksum)
                delete ElementLevel2;

              ElementLevel2 = aStream.FindNextElement(EBML_CONTEXT(ElementLevel1), UpperElementLevel, 0, bAllowDummy);
            }
          }
#endif // not MEMORY_READ
          if (pChecksum != NULL) {
            EbmlCrc32 ComputedChecksum;
            std::uint64_t CurrPosition = aStream.I_O().getFilePointer();
            std::uint64_t CrcPositionEnd = ElementLevel2->GetElementPosition();
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
        else if (EbmlId(*ElementLevel1) == EBML_ID(KaxCues)) {
          printf("\n- Cue entries found\n");
          CuesEntry = static_cast<KaxCues *>(ElementLevel1);
          CuesEntry->SetGlobalTimecodeScale(TimecodeScale);
          // read everything in memory
          CuesEntry->Read(aStream, EBML_CLASS_CONTEXT(KaxCues), UpperElementLevel, ElementLevel2, bAllowDummy); // build the entries in memory
          if (CuesEntry->CheckMandatory()) {
            printf("  * All mandatory elements found *\n");
          } else {
            printf("  * Some mandatory elements ar missing !!! *\n");
          }
          CuesEntry->Sort();
          // display the elements read
          unsigned int Index0;
          for (Index0 = 0; Index0<CuesEntry->ListSize() ;Index0++) {
            if (EbmlId(*(*CuesEntry)[Index0]) == EBML_ID(KaxCuePoint)) {
              printf(" Cue Point\n");

              KaxCuePoint & CuePoint = *static_cast<KaxCuePoint *>((*CuesEntry)[Index0]);
              unsigned int Index1;
              for (Index1 = 0; Index1<CuePoint.ListSize() ;Index1++) {
                if (EbmlId(*CuePoint[Index1]) == EBML_ID(KaxCueTime)) {
                  KaxCueTime & CueTime = *static_cast<KaxCueTime *>(CuePoint[Index1]);
                  printf("  Time %" PRIu64 "\n", std::uint64_t(CueTime) * TimecodeScale);
                } else if (EbmlId(*(CuePoint[Index1])) == EBML_ID(KaxCueTrackPositions)) {
                  KaxCueTrackPositions & CuePos = *static_cast<KaxCueTrackPositions *>(CuePoint[Index1]);
                  printf("  Positions\n");

                  unsigned int Index2;
                  for (Index2 = 0; Index2<CuePos.ListSize() ;Index2++) {
                    if (EbmlId(*(CuePos[Index2])) == EBML_ID(KaxCueTrack)) {
                      KaxCueTrack & CueTrack = *static_cast<KaxCueTrack *>(CuePos[Index2]);
                      printf("   Track %d\n", std::uint16_t(CueTrack));
                    } else if (EbmlId(*(CuePos[Index2])) == EBML_ID(KaxCueClusterPosition)) {
                      KaxCueClusterPosition & CuePoss = *static_cast<KaxCueClusterPosition *>(CuePos[Index2]);
                      printf("   Cluster position %" PRIu64 "\n", std::uint64_t(CuePoss));
                    } else if (EbmlId(*(CuePos[Index2])) == EBML_ID(KaxCueReference)) {
                      KaxCueReference & CueRefs = *static_cast<KaxCueReference *>(CuePos[Index2]);
                      printf("   Reference\n");

                      unsigned int Index3;
                      for (Index3 = 0; Index3<CueRefs.ListSize() ;Index3++) {
                        if (EbmlId(*(CueRefs[Index3])) == EBML_ID(KaxCueRefTime)) {
                          KaxCueRefTime & CueTime = *static_cast<KaxCueRefTime *>(CueRefs[Index3]);
                          printf("    Time %d\n", std::uint32_t(CueTime));
                        } else if (EbmlId(*(CueRefs[Index3])) == EBML_ID(KaxCueRefCluster)) {
                          KaxCueRefCluster & CueClust = *static_cast<KaxCueRefCluster *>(CueRefs[Index3]);
                          printf("    Cluster position %" PRId64 "\n", std::uint64_t(CueClust));
                        } else {
                          printf("    - found %s\n", EBML_NAME(CueRefs[Index3]));
                        }
                      }
                    } else {
                      printf("   - found %s\n", EBML_NAME(CuePos[Index2]));
                    }
                  }
                } else {
                  printf("  - found %s\n", EBML_NAME(CuePoint[Index1]));
                }
              }
            } else {
              printf(" - found %s\n", EBML_NAME((*CuesEntry)[Index0]));
            }
          }
        }
        else if (EbmlId(*ElementLevel1) == EBML_ID(KaxSeekHead)) {
          printf("\n- Meta Seek found\n");
          MetaSeek = static_cast<KaxSeekHead *>(ElementLevel1);
          // read it in memory
          MetaSeek->Read(aStream, EBML_CLASS_CONTEXT(KaxSeekHead), UpperElementLevel, ElementLevel2, bAllowDummy);
          if (MetaSeek->CheckMandatory()) {
            printf("  * All mandatory elements found *\n");
          } else {
            printf("  * Some mandatory elements ar missing !!! *\n");
          }
          unsigned int Index0;
          for (Index0 = 0; Index0<MetaSeek->ListSize() ;Index0++) {
            if (EbmlId(*(*MetaSeek)[Index0]) == EBML_ID(KaxSeek)) {
              printf("   Seek Point\n");
              KaxSeek & SeekPoint = *static_cast<KaxSeek *>((*MetaSeek)[Index0]);
              unsigned int Index1;
              for (Index1 = 0; Index1<SeekPoint.ListSize() ;Index1++) {
                if (EbmlId(*(SeekPoint[Index1])) == EBML_ID(KaxSeekID)) {
                  KaxSeekID * SeekID = static_cast<KaxSeekID *>(SeekPoint[Index1]);
                  printf("    Seek ID ");
                  for (unsigned int i=0; i<SeekID->GetSize(); i++) {
                    printf("%02X", SeekID->GetBuffer()[i]);
                  }
                  printf("\n");
                } else if (EbmlId(*(SeekPoint[Index1])) == EBML_ID(KaxSeekPosition)) {
                  KaxSeekPosition * SeekPos = static_cast<KaxSeekPosition *>(SeekPoint[Index1]);
                  printf("    Seek position %d\n", std::uint32_t(*SeekPos));
                }
              }
            }
          }
        } else if (EbmlId(*ElementLevel1) == EBML_ID(KaxChapters)) {
          printf("\n- Chapters found\n");
          Chapters = static_cast<KaxChapters *>(ElementLevel1);
          // read it in memory
          Chapters->Read(aStream, EBML_CLASS_CONTEXT(KaxChapters), UpperElementLevel, ElementLevel2, bAllowDummy);
          if (Chapters->CheckMandatory()) {
            printf("  * All mandatory elements found *\n");
          } else {
            printf("  * Some mandatory elements ar missing !!! *\n");
          }
          unsigned int Index0;
          for (Index0 = 0; Index0<Chapters->ListSize() ;Index0++) {
            if (EbmlId(*(*Chapters)[Index0]) == EBML_ID(KaxEditionEntry)) {
              printf("   Edition\n");
              KaxEditionEntry & Edition = *static_cast<KaxEditionEntry *>((*Chapters)[Index0]);
              unsigned int Index2;
              for (Index2 = 0; Index2<Edition.ListSize() ;Index2++) {
                if (EbmlId(*(Edition[Index2])) == EBML_ID(KaxChapterAtom)) {
                  printf("     Chapter Atom\n");
                  KaxChapterAtom & aChapterAtom = *static_cast<KaxChapterAtom *>(Edition[Index2]);
                  unsigned int Index3;
                  for (Index3 = 0; Index3<aChapterAtom.ListSize() ;Index3++) {
                    if (EbmlId(*(aChapterAtom[Index3])) == EBML_ID(KaxChapterUID)) {
                      printf("      Chapter UID 0x%08x\n", std::uint32_t(*static_cast<EbmlUInteger *>(aChapterAtom[Index3])) );
                    } else if (EbmlId(*(aChapterAtom[Index3])) == EBML_ID(KaxChapterTimeStart)) {
                      printf("      Time Start %d\n", std::uint32_t(*static_cast<EbmlUInteger *>(aChapterAtom[Index3])) );
                    } else if (EbmlId(*(aChapterAtom[Index3])) == EBML_ID(KaxChapterTimeEnd)) {
                      printf("      Time End %d ns\n", std::uint32_t(*static_cast<EbmlUInteger *>(aChapterAtom[Index3])) );
                    } else if (EbmlId(*(aChapterAtom[Index3])) == EBML_ID(KaxChapterTrack)) {
                      printf("      Track list\n");
                    } else if (EbmlId(*(aChapterAtom[Index3])) == EBML_ID(KaxChapterDisplay)) {
                      printf("      Display info\n");
                      KaxChapterDisplay & aDisplay = *static_cast<KaxChapterDisplay *>(aChapterAtom[Index3]);
                      unsigned int Index4;
                      for (Index4 = 0; Index4<aDisplay.ListSize() ;Index4++) {
                        if (EbmlId(*(aDisplay[Index4])) == EBML_ID(KaxChapterString)) {
                          printf("       Display \"%s\"\n", UTFstring(*static_cast<EbmlUnicodeString *>(aDisplay[Index4])).GetUTF8().c_str() );
                        } else if (EbmlId(*(aDisplay[Index4])) == EBML_ID(KaxChapterLanguage)) {
                          printf("       For language \"%s\"\n", std::string(*static_cast<EbmlString *>(aDisplay[Index4])).c_str() );
                        } else if (EbmlId(*(aDisplay[Index4])) == EBML_ID(KaxChapterCountry)) {
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
        } else if (EbmlId(*ElementLevel1) == EBML_ID(KaxTags)) {
          printf("\n- Tags found\n");
          AllTags = static_cast<KaxTags *>(ElementLevel1);
          // read it in memory
          AllTags->Read(aStream, EBML_CLASS_CONTEXT(KaxTags), UpperElementLevel, ElementLevel2, bAllowDummy);
          if (AllTags->CheckMandatory()) {
            printf("  * All mandatory elements found *\n");
          } else {
            printf("  * Some mandatory elements ar missing !!! *\n");
          }
          unsigned int Index0;
          for (Index0 = 0; Index0<AllTags->ListSize() ;Index0++) {
            if (EbmlId(*(*AllTags)[Index0]) == EBML_ID(KaxTag)) {
              printf("   Tag\n");
              KaxTag & TagElt = *static_cast<KaxTag *>((*AllTags)[Index0]);
              unsigned int Index1;
              for (Index1 = 0; Index1<TagElt.ListSize() ;Index1++) {
//                 bool bRemoved = false, bRemovedDone = true;
                if (EbmlId(*(TagElt[Index1])) == EBML_ID(KaxTagTargets)) {
                  printf("    Targets\n");
                  KaxTagTargets & Targets = *static_cast<KaxTagTargets *>(TagElt[Index1]);
                  unsigned int Index2;
                  for (Index2 = 0; Index2<Targets.ListSize() ;Index2++) {
                    if (EbmlId(*(Targets[Index2])) == EBML_ID(KaxTagTrackUID)) {
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
                    } else if (EbmlId(*(Targets[Index2])) == EBML_ID(KaxTagChapterUID)) {
                      printf("     Chapter UID\n");
#if 0
                    } else if (EbmlId(*(Targets[Index2])) == EBML_ID(KaxTagMultiComment)) {
                      printf("     Comment\n");
                      KaxTagMultiComment & Comment = *static_cast<KaxTagMultiComment *>(Targets[Index2]);
                      unsigned int Index3;
                      for (Index3 = 0; Index3<Comment.ListSize() ;Index3++) {
                        if (EbmlId(*(Comment[Index3])) == EBML_ID(KaxTagMultiCommentName)) {
                          KaxTagMultiCommentName & CommentName = *static_cast<KaxTagMultiCommentName *>(Comment[Index3]);
                          printf("      Comment Name \"%s\"\n", std::string(CommentName).c_str());
                        }
                      }
//                    } else if (EbmlId(*(Targets[Index2])) == EBML_ID(DummyRawElement)) {
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
                } else if (EbmlId(*(TagElt[Index1])) == EBML_ID(KaxTagGeneral)) {
                  printf("    General\n");
                  KaxTagGeneral & General = *static_cast<KaxTagGeneral *>(TagElt[Index1]);
                  unsigned int Index2;
                  for (Index2 = 0; Index2<General.ListSize() ;Index2++) {
                    if (EbmlId(*(General[Index2])) == EBML_ID(KaxTagSubject)) {
                      printf("     Subject\n");
                    } else if (EbmlId(*(General[Index2])) == EBML_ID(KaxTagBibliography)) {
                      printf("     Bibliography\n");
                    } else if (EbmlId(*(General[Index2])) == EBML_ID(KaxTagLanguage)) {
                      printf("     Language\n");
                    }
                  }
                } else if (EbmlId(*(TagElt[Index1])) == EBML_ID(KaxTagMultiCommercial)) {
                  printf("    MultiCommercial\n");
                  KaxTagMultiCommercial & Commercials = *static_cast<KaxTagMultiCommercial *>(TagElt[Index1]);
                  unsigned int Index2;
                  for (Index2 = 0; Index2<Commercials.ListSize() ;Index2++) {
                    if (EbmlId(*(Commercials[Index2])) == EBML_ID(KaxTagCommercial)) {
                      printf("     Commercial\n");
                      KaxTagCommercial & Commercial = *static_cast<KaxTagCommercial *>(Commercials[Index2]);
                      unsigned int Index3;
                      for (Index3 = 0; Index3<Commercial.ListSize() ;Index3++) {
                        if (EbmlId(*(Commercial[Index3])) == EBML_ID(KaxTagMultiCommercialType)) {
                          printf("      Type\n");
                        } else if (EbmlId(*(Commercial[Index3])) == EBML_ID(KaxTagMultiPrice)) {
                          printf("      Prices\n");
                          KaxTagMultiPrice & Prices = *static_cast<KaxTagMultiPrice *>(Commercial[Index3]);
                          unsigned int Index4;
                          for (Index4 = 0; Index4<Prices.ListSize(); Index4++) {
                            if (EbmlId(*(Prices[Index4])) == EBML_ID(KaxTagMultiPriceCurrency)) {
                              printf("       Currency\n");
                            } else if (EbmlId(*(Prices[Index4])) == EBML_ID(KaxTagMultiPriceAmount)) {
                              printf("       Amount\n");
                            }
                          }
                        }
                      }
                    }
                  }
                } else if (EbmlId(*(TagElt[Index1])) == EBML_ID(KaxTagMultiDate)) {
                  printf("    MultiDate\n");
                } else if (EbmlId(*(TagElt[Index1])) == EBML_ID(KaxTagMultiComment)) {
                  printf("    Comment\n");
                  KaxTagMultiComment & Comment = *static_cast<KaxTagMultiComment *>(TagElt[Index1]);
                  unsigned int Index2;
                  for (Index2 = 0; Index2<Comment.ListSize() ;Index2++) {
                    if (EbmlId(*(Comment[Index2])) == EBML_ID(KaxTagMultiCommentName)) {
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
          ElementLevel1->SkipData(aStream, EBML_CONTEXT(ElementLevel1));
          delete ElementLevel1;

          ElementLevel1 = aStream.FindNextElement(EBML_CONTEXT(ElementLevel0), UpperElementLevel, 0, bAllowDummy);
        }
      }
    }
  }
    }
    catch (exception & Ex)
    {
    cout << Ex.what() << endl;
    return -1;
    }

    return 0;
}
