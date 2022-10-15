/****************************************************************************
** libmatroska : parse Matroska files, see http://www.matroska.org/
**
** <file/class description>
**
** Copyright (C) 2002-2010 Steve Lhomme.  All rights reserved.
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
  \todo add a PureBlock class to group functionalities between Block and BlockVirtual
  \version \$Id: KaxBlock.h,v 1.24 2004/04/14 23:26:17 robux4 Exp $
  \author Steve Lhomme     <robux4 @ users.sf.net>
  \author Julien Coloos    <suiryc @ users.sf.net>
*/
#ifndef LIBMATROSKA_BLOCK_H
#define LIBMATROSKA_BLOCK_H

#include <vector>

#include "matroska/KaxTypes.h"
#include <ebml/EbmlBinary.h>
#include <ebml/EbmlMaster.h>
#include "matroska/KaxTracks.h"
#include "matroska/KaxDefines.h"

using namespace libebml;

namespace libmatroska {

class KaxCluster;
class KaxReferenceBlock;
class KaxInternalBlock;
class KaxBlockBlob;

class MATROSKA_DLL_API DataBuffer {
  protected:
    binary  *myBuffer{nullptr};
    std::uint32_t mySize;
    bool     bValidValue{true};
    bool     (*myFreeBuffer)(const DataBuffer & aBuffer); // method to free the internal buffer
    bool     bInternalBuffer;

  public:
    DataBuffer(binary * aBuffer, std::uint32_t aSize, bool (*aFreeBuffer)(const DataBuffer & aBuffer) = nullptr, bool _bInternalBuffer = false)
      :mySize(aSize)
      ,myFreeBuffer(aFreeBuffer)
      ,bInternalBuffer(_bInternalBuffer)
    {
      if (bInternalBuffer)
      {
        myBuffer = new (std::nothrow) binary[mySize];
        if (!myBuffer)
          bValidValue = false;
        else
          memcpy(myBuffer, aBuffer, mySize);
      }
      else
        myBuffer = aBuffer;
    }

    virtual ~DataBuffer() = default;
    virtual binary * Buffer() {assert(bValidValue); return myBuffer;}
    virtual std::uint32_t & Size() {return mySize;};
    virtual const binary * Buffer() const {assert(bValidValue); return myBuffer;}
    virtual std::uint32_t Size()   const {return mySize;};
    bool    FreeBuffer(const DataBuffer & aBuffer) {
      bool bResult = true;
      if (myBuffer && bValidValue) {
        if (myFreeBuffer)
          bResult = myFreeBuffer(aBuffer);
        if (bInternalBuffer)
          delete [] myBuffer;
        myBuffer = nullptr;
        mySize = 0;
        bValidValue = false;
      }
      return bResult;
    }

    virtual DataBuffer * Clone();
};

class MATROSKA_DLL_API SimpleDataBuffer : public DataBuffer {
  public:
    SimpleDataBuffer(binary * aBuffer, std::uint32_t aSize, std::uint32_t aOffset, bool (*aFreeBuffer)(const DataBuffer & aBuffer) = myFreeBuffer)
      :DataBuffer(aBuffer + aOffset, aSize, aFreeBuffer)
      ,Offset(aOffset)
      ,BaseBuffer(aBuffer)
    {}
    ~SimpleDataBuffer() override = default;

    DataBuffer * Clone() override {return new SimpleDataBuffer(*this);}

  protected:
    std::uint32_t Offset;
    binary * BaseBuffer;

    static bool myFreeBuffer(const DataBuffer & aBuffer)
    {
      auto _Buffer = static_cast<const SimpleDataBuffer*>(&aBuffer)->BaseBuffer;
      if (_Buffer)
        free(_Buffer);
      return true;
    }

    SimpleDataBuffer(const SimpleDataBuffer & ToClone);
};

/*!
  \note the data is copied locally, it can be freed right away
* /
class MATROSKA_DLL_API NotSoSimpleDataBuffer : public SimpleDataBuffer {
  public:
    NotSoSimpleDataBuffer(binary * aBuffer, std::uint32_t aSize, std::uint32_t aOffset)
      :SimpleDataBuffer(new binary[aSize - aOffset], aSize, 0)
    {
      memcpy(BaseBuffer, aBuffer + aOffset, aSize - aOffset);
    }
};
*/

DECLARE_MKX_MASTER(KaxBlockGroup)
  public:
    ~KaxBlockGroup() override = default;

    /*!
      \brief Addition of a frame without references
    */
    bool AddFrame(const KaxTrackEntry & track, std::uint64_t timecode, DataBuffer & buffer, LacingType lacing = LACING_AUTO);
    /*!
      \brief Addition of a frame with a backward reference (P frame)
    */
    bool AddFrame(const KaxTrackEntry & track, std::uint64_t timecode, DataBuffer & buffer, const KaxBlockGroup & PastBlock, LacingType lacing = LACING_AUTO);

    /*!
      \brief Addition of a frame with a backward+forward reference (B frame)
    */
    bool AddFrame(const KaxTrackEntry & track, std::uint64_t timecode, DataBuffer & buffer, const KaxBlockGroup & PastBlock, const KaxBlockGroup & ForwBlock, LacingType lacing = LACING_AUTO);
    bool AddFrame(const KaxTrackEntry & track, std::uint64_t timecode, DataBuffer & buffer, const KaxBlockBlob * PastBlock, const KaxBlockBlob * ForwBlock, LacingType lacing = LACING_AUTO);

    void SetParent(KaxCluster & aParentCluster);

    void SetParentTrack(const KaxTrackEntry & aParentTrack) {
      ParentTrack = &aParentTrack;
    }

    /*!
      \brief Set the duration of the contained frame(s) (for the total number of frames)
    */
    void SetBlockDuration(std::uint64_t TimeLength);
    bool GetBlockDuration(std::uint64_t &TheTimecode) const;

    /*!
      \return the global timecode of this Block (not just the delta to the Cluster)
    */
    std::uint64_t GlobalTimecode() const;
    std::uint64_t GlobalTimecodeScale() const {
      assert(ParentTrack);
      return ParentTrack->GlobalTimecodeScale();
    }

    std::uint16_t TrackNumber() const;

    std::uint64_t ClusterPosition() const;

    /*!
      \return the number of references to other frames
    */
    unsigned int ReferenceCount() const;
    const KaxReferenceBlock & Reference(unsigned int Index) const;

    /*!
      \brief release all the frames of all Blocks
    */
    void ReleaseFrames();

    operator KaxInternalBlock &();

    const KaxCluster *GetParentCluster() const { return ParentCluster; }

  protected:
    KaxCluster * ParentCluster{nullptr};
    const KaxTrackEntry * ParentTrack{nullptr};
};

class MATROSKA_DLL_API KaxInternalBlock : public EbmlBinary {
  public:
    KaxInternalBlock(EBML_DEF_CONS EBML_DEF_SEP bool bSimple EBML_DEF_SEP EBML_EXTRA_PARAM) :EBML_DEF_BINARY_INIT EBML_DEF_SEP bIsSimple(bSimple)
    {}
    KaxInternalBlock(const KaxInternalBlock & ElementToClone);
    ~KaxInternalBlock() override;
    bool ValidateSize() const override;

    std::uint16_t TrackNum() const {return TrackNumber;}
    /*!
      \todo !!!! This method needs to be changes !
    */
    std::uint64_t GlobalTimecode() const {return Timecode;}

    /*!
      \note override this function to generate the Data/Size on the fly, unlike the usual binary elements
    */
    filepos_t UpdateSize(bool bSaveDefault = false, bool bForceRender = false) override;
    filepos_t ReadData(IOCallback & input, ScopeMode ReadFully = SCOPE_ALL_DATA) override;

    /*!
      \brief Only read the head of the Block (not internal data)
      \note convenient when you are parsing the file quickly
    */
    std::uint64_t ReadInternalHead(IOCallback & input);

    unsigned int NumberFrames() const { return SizeList.size();}
    DataBuffer & GetBuffer(unsigned int iIndex) {return *myBuffers[iIndex];}

    bool AddFrame(const KaxTrackEntry & track, std::uint64_t timecode, DataBuffer & buffer, LacingType lacing = LACING_AUTO, bool invisible = false);

    /*!
      \brief release all the frames of all Blocks
    */
    void ReleaseFrames();

    void SetParent(KaxCluster & aParentCluster);

    /*!
      \return Returns the lacing type that produces the smallest footprint.
    */
    LacingType GetBestLacingType() const;

    /*!
      \param FrameNumber 0 for the first frame
      \return the position in the stream for a given frame
      \note return -1 if the position doesn't exist
    */
    std::int64_t GetDataPosition(size_t FrameNumber = 0);

    /*!
      \param FrameNumber 0 for the first frame
      \return the size of a given frame
      \note return -1 if the position doesn't exist
    */
    std::int64_t GetFrameSize(size_t FrameNumber = 0);

    bool IsInvisible() const { return mInvisible; }

    std::uint64_t ClusterPosition() const;

    /*!
     * \return Get the timestamp as written in the Block (not scaled).
     * \since LIBMATROSKA_VERSION >= 0x010700
     */
    std::int16_t GetRelativeTimestamp() const { return LocalTimecode; }

  protected:
    std::vector<DataBuffer *> myBuffers;
    std::vector<std::int32_t> SizeList;
    std::uint64_t             Timecode; // temporary timecode of the first frame, non scaled
    std::int16_t              LocalTimecode;
    bool                      bLocalTimecodeUsed{false};
    std::uint16_t               TrackNumber;
    LacingType                mLacing{LACING_AUTO};
    bool                      mInvisible{false};
    std::uint64_t             FirstFrameLocation;

    KaxCluster               *ParentCluster{nullptr};
    bool                      bIsSimple;
    bool                      bIsKeyframe{true};
    bool                      bIsDiscardable{false};

    filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault = false) override;
};

DECLARE_MKX_CONTEXT(KaxBlock)
class MATROSKA_DLL_API KaxBlock : public KaxInternalBlock {
  public:
    KaxBlock(EBML_EXTRA_PARAM) :KaxInternalBlock(EBML_DEF_BINARY_CTX(KaxBlock)EBML_DEF_SEP false EBML_DEF_SEP EBML_EXTRA_CALL) {}
        EBML_CONCRETE_CLASS(KaxBlock)
};

DECLARE_MKX_CONTEXT(KaxSimpleBlock)
class MATROSKA_DLL_API KaxSimpleBlock : public KaxInternalBlock {
  public:
    KaxSimpleBlock(EBML_EXTRA_PARAM) :KaxInternalBlock(EBML_DEF_BINARY_CTX(KaxSimpleBlock)EBML_DEF_SEP true EBML_DEF_SEP EBML_EXTRA_CALL) {}

    void SetKeyframe(bool b_keyframe) { bIsKeyframe = b_keyframe; }
    void SetDiscardable(bool b_discard) { bIsDiscardable = b_discard; }

    bool IsKeyframe() const    { return bIsKeyframe; }
    bool IsDiscardable() const { return bIsDiscardable; }

    void SetParent(KaxCluster & aParentCluster);

        EBML_CONCRETE_CLASS(KaxSimpleBlock)
};

/// Placeholder class for either a BlockGroup or a SimpleBlock
class MATROSKA_DLL_API KaxBlockBlob {
public:
  KaxBlockBlob(BlockBlobType sblock_mode) : SimpleBlockMode(sblock_mode) {
    bUseSimpleBlock = (sblock_mode != BLOCK_BLOB_NO_SIMPLE);
    Block.group = nullptr;
  }

  ~KaxBlockBlob() {
    if (bUseSimpleBlock)
      delete Block.simpleblock;
    else
      delete Block.group;
  }

  operator KaxBlockGroup &();
  operator const KaxBlockGroup &() const;
  operator KaxSimpleBlock &();
  operator KaxInternalBlock &();
  operator const KaxInternalBlock &() const;

  void SetBlockGroup( KaxBlockGroup &BlockRef );

  void SetBlockDuration(std::uint64_t TimeLength);

  void SetParent(KaxCluster & aParentCluster);
  bool AddFrameAuto(const KaxTrackEntry & track, std::uint64_t timecode, DataBuffer & buffer, LacingType lacing = LACING_AUTO, const KaxBlockBlob * PastBlock = nullptr, const KaxBlockBlob * ForwBlock = nullptr);

  bool IsSimpleBlock() const {return bUseSimpleBlock;}

  bool ReplaceSimpleByGroup();
protected:
  KaxCluster *ParentCluster{nullptr};
  union {
    KaxBlockGroup *group;
    KaxSimpleBlock *simpleblock;
  } Block;
  bool bUseSimpleBlock;
  BlockBlobType SimpleBlockMode;
};

DECLARE_MKX_BINARY_CONS(KaxBlockVirtual)
  public:
    ~KaxBlockVirtual() override;

    /*!
      \note override this function to generate the Data/Size on the fly, unlike the usual binary elements
    */
    filepos_t UpdateSize(bool bSaveDefault = false, bool bForceRender = false) override;

    void SetParent(const KaxCluster & aParentCluster) {ParentCluster = &aParentCluster;}

    filepos_t RenderData(IOCallback & output, bool bForceRender, bool bSaveDefault) override;

    filepos_t ReadData(IOCallback & input, ScopeMode ReadFully = SCOPE_ALL_DATA) override;

  protected:
    std::uint64_t Timecode; // temporary timecode of the first frame if there are more than one
    std::uint16_t TrackNumber;
    binary DataBlock[5];

    const KaxCluster * ParentCluster{nullptr};
};

} // namespace libmatroska

#endif // LIBMATROSKA_BLOCK_H
