/****************************************************************************
** libmatroska : parse Matroska files, see http://www.matroska.org/
**
** <file/class description>
**
** Copyright (C) 2002-2010 Steve Lhomme.  All rights reserved.
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
  \version \$Id: FileKax.h,v 1.5 2004/04/14 23:26:17 robux4 Exp $
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_FILE_H
#define LIBMATROSKA_FILE_H

//#include <vector>

#include "matroska/KaxTypes.h"
#include <ebml/IOCallback.h>
//#include "MainHeader.h"
//#include "TrackType.h"
//#include "StreamInfo.h"
//#include "Cluster.h"
//#include "CodecHeader.h"

using namespace libebml;

namespace libmatroska {

//class Track;
//class Frame;

/*!
    \class MATROSKA_DLL_API FileMatroska
    \brief General container of all the parameters and data of an Matroska file
    \todo Handle the filename and next filename
    \todo Handle the IOCallback selection/type
*/
class MATROSKA_DLL_API FileMatroska {
    public:
    FileMatroska(IOCallback & output);
    ~FileMatroska() = default;
#ifdef OLD
  filepos_t RenderHead(const std::string & aEncoderApp);
  std::uint32_t ReadHead();
  std::uint32_t ReadTracks();
  std::uint32_t ReadCodec();
  void Close(const std::uint32_t aTimeLength);

  inline void type_SetInfo(const std::string & aStr) {myMainHeader.type_SetInfo(aStr);}
  inline void type_SetAds(const std::string & aStr) {myMainHeader.type_SetAds(aStr);}
  inline void type_SetSize(const std::string & aStr) {myMainHeader.type_SetSize(aStr);}
  inline void type_SetSize(std::uint64_t aSize) {myMainHeader.type_SetSize(aSize);}

  inline std::uint8_t GetTrackNumber() const { return myTracks.size(); }

  void track_SetName(Track * aTrack, const std::string & aName);
  void track_SetLaced(Track * aTrack, bool bLaced = true);

  Track * CreateTrack(const track_type aType);
  inline Track * GetTrack(const std::uint8_t aTrackNb) const
  {
      if (aTrackNb > myTracks.size())
    return NULL;
      else
    return myTracks[aTrackNb-1];
  }

  void Track_GetInfo(const Track * aTrack, TrackInfo & aTrackInfo) const;

  void Track_SetInfo_Audio(Track * aTrack, const TrackInfoAudio & aTrackInfo);
  void Track_GetInfo_Audio(const Track * aTrack, TrackInfoAudio & aTrackInfo) const;

  void Track_SetInfo_Video(Track * aTrack, const TrackInfoVideo & aTrackInfo);
  void Track_GetInfo_Video(const Track * aTrack, TrackInfoVideo & aTrackInfo) const;

  void SelectReadingTrack(Track * aTrack, bool select = true);

  /*!
      \return wether the frame has been added or not
  */
  bool AddFrame(Track * aTrack, const std::uint32_t aTimecode, const binary *aFrame, const std::uint32_t aFrameSize,
         bool aKeyFrame = true, bool aBFrame = false);

  /*!
      \return wether the frame has been read or not
  */
  bool ReadFrame(Track * & aTrack, std::uint32_t & aTimecode, const binary * & aFrame, std::uint32_t & aFrameSize,
         bool & aKeyFrame, bool & aBFrame);

  /*
      Render the pending cluster to file
  */
  void Flush();

  void SetMaxClusterSize(const std::uint32_t value);
  void SetMinClusterSize(const std::uint32_t value) {myMinClusterSize = value;}

    protected:
  MainHeader myMainHeader;

  std::vector<Track *> myTracks;
  std::vector<std::uint8_t> mySelectedTracks;

//  Track *findTrack(Track * aTrack) const;

  Cluster  myCurrWriteCluster; /// \todo merge with the write one ?
  std::uint32_t myReadBlockNumber;
  Cluster  myCurrReadCluster;
  binary * myCurrReadBlock;      ///< The buffer containing the current read block
  std::uint32_t myCurrReadBlockSize;  ///< The size of the buffer containing the current read block
  std::uint8_t    myCurrReadBlockTrack; ///< The track number of the current track to read

  std::uint32_t myMaxClusterSize;
  std::uint32_t myMinClusterSize;

  StreamInfo myStreamInfo;

  CodecHeader myCodecHeader;

  inline bool IsMyTrack(const Track * aTrack) const;
  inline bool IsReadingTrack(const std::uint8_t aTrackNum) const;
#endif // OLD
  IOCallback & myFile;

};

} // namespace libmatroska

#ifdef __cplusplus
extern "C" {
#endif

MATROSKA_DLL_API void matroska_init();
MATROSKA_DLL_API void matroska_done();

#ifdef __cplusplus
}
#endif

#endif // FILE_KAX_HPP
