// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
  \author Julien Coloos    <suiryc @ users.sf.net>
  \author Moritz Bunkus <moritz@bunkus.org>
*/
#include <cassert>

//#include <streams.h>

#include <ebml/MemReadIOCallback.h>
#include <ebml/SafeReadIOCallback.h>
#include "matroska/KaxBlock.h"
#include "matroska/KaxContexts.h"
#include "matroska/KaxBlockData.h"
#include "matroska/KaxCluster.h"
#include "matroska/KaxDefines.h"

namespace libmatroska {

DataBuffer * DataBuffer::Clone()
{
  auto ClonedData = static_cast<binary *>(malloc(mySize * sizeof(binary)));
  assert(ClonedData);
  memcpy(ClonedData, myBuffer ,mySize );

  auto result = new SimpleDataBuffer(ClonedData, mySize, 0);
  result->bValidValue = bValidValue;
  return result;
}

SimpleDataBuffer::SimpleDataBuffer(const SimpleDataBuffer & ToClone)
  :DataBuffer(static_cast<binary *>(malloc(ToClone.mySize * sizeof(binary))), ToClone.mySize, myFreeBuffer)
{
  assert(myBuffer);
  memcpy(myBuffer, ToClone.myBuffer ,mySize );
  bValidValue = ToClone.bValidValue;
}

bool KaxInternalBlock::ValidateSize() const
{
  return (GetSize() >= 4); /// for the moment
}

KaxInternalBlock::~KaxInternalBlock()
{
  ReleaseFrames();
}

KaxInternalBlock::KaxInternalBlock(const KaxInternalBlock & ElementToClone)
  :EbmlBinary(ElementToClone)
  ,Timecode(ElementToClone.Timecode)
  ,LocalTimecode(ElementToClone.LocalTimecode)
  ,bLocalTimecodeUsed(ElementToClone.bLocalTimecodeUsed)
  ,TrackNumber(ElementToClone.TrackNumber)
  ,ParentCluster(ElementToClone.ParentCluster) ///< \todo not exactly
{
  // add a clone of the list
  myBuffers.reserve(ElementToClone.myBuffers.size());
  for (const auto& buffer : ElementToClone.myBuffers)
    myBuffers.push_back(buffer->Clone());
}


/* KaxBlockGroup::~KaxBlockGroup()
{
  //NOTE("KaxBlockGroup::~KaxBlockGroup");
} */

KaxBlockGroup::KaxBlockGroup()
  :EbmlMaster(EBML_CLASS_SEMCONTEXT(KaxBlockGroup))
{}

static constexpr std::int64_t SignedVINT_Shift1 = (1 << ((7*1) - 1)) - 1;
static constexpr std::int64_t SignedVINT_Shift2 = (1 << ((7*2) - 1)) - 1;
static constexpr std::int64_t SignedVINT_Shift3 = (1 << ((7*3) - 1)) - 1;
static constexpr std::int64_t SignedVINT_Shift4 = (1 << ((7*4) - 1)) - 1;

#define SignedVINT_MAX(n) ((SignedVINT_Shift ##n) + 1)
#define SignedVINT_MIN(n) (-(SignedVINT_Shift ##n) - 1)

static std::int64_t SignedVINTSizeToShift(int CodedSize)
{
  switch (CodedSize) {
    case 1:
      return SignedVINT_Shift1;
    case 2:
      return SignedVINT_Shift2;
    case 3:
      return SignedVINT_Shift3;
    case 4:
      return SignedVINT_Shift4;
    default:
      return 0; // should never happen
  }
}

/*!
  \brief The size of the EBML-coded signed integer
  \param Value value to encode as EBML integer
  \todo handle more than CodedSize of 5
*/
static int SignedVINTLength(std::int64_t Value)
{
  // prepare the head of the size (000...01xxxxxx)
  // optimal size
  if (Value > SignedVINT_MIN(1) && Value <= SignedVINT_MAX(1)) // 2^6
    return 1;
  if (Value > SignedVINT_MIN(2) && Value <= SignedVINT_MAX(2)) // 2^13
    return 2;
  if (Value > SignedVINT_MIN(3) && Value <= SignedVINT_MAX(3)) // 2^20
    return 3;
  if (Value > SignedVINT_MIN(4) && Value <= SignedVINT_MAX(4)) // 2^27
    return 4;
  return 5; // not really handled
}

/*!
  \brief The coded value of the EBML-coded signed integer
  \param Value value to encode as EBML signed integer
  \param CodedSize amount of octets to use to write the integer
  \param OutBuffer buffer to write the EBML-coded signed integer
  \note The size of OutBuffer must be at least CodedSize octets big
*/
static int SignedVINTValue(std::int64_t Value, int CodedSize, binary * OutBuffer)
{
  Value += SignedVINTSizeToShift(SignedVINTLength(Value));

  return CodedValueLength(Value, CodedSize, OutBuffer);
}

/*!
  \brief Read a signed EBML-coded value from a buffer
  \return the value read
*/
static std::int64_t ReadSignedVINT(const binary * InBuffer, std::uint32_t & BufferSize)
{
  std::uint64_t SizeUnknown = 0;
  assert(BufferSize != 0);
  std::int64_t Result = ReadCodedSizeValue(InBuffer, BufferSize, SizeUnknown);
  assert(BufferSize != 0);

  return Result - SignedVINTSizeToShift(BufferSize);
}

/*!
  \todo handle flags
  \todo hardcoded limit of the number of frames in a lace should be a parameter
  \return true if more frames can be added to this Block
*/
bool KaxInternalBlock::AddFrame(const KaxTrackEntry & track, std::uint64_t timecode, DataBuffer & buffer, LacingType lacing, bool invisible)
{
  SetValueIsSet();
  if (myBuffers.empty()) {
    // first frame
    Timecode = timecode;
    TrackNumber = static_cast<std::uint64_t>(track.TrackNumber());
    mInvisible = invisible;
    mLacing = lacing;
  }
  myBuffers.push_back(&buffer);

  // we don't allow more than 8 frames in a Block because the overhead improvement is minimal
  if (myBuffers.size() >= 8 || lacing == LACING_NONE)
    return false;

  if (lacing == LACING_XIPH)
    // decide wether a new frame can be added or not
    // a frame in a lace is not efficient when the place necessary to code it in a lace is bigger
    // than the size of a simple Block. That means more than 6 bytes (4 in struct + 2 for EBML) to code the size
    return (buffer.Size() < 6*0xFF);

  return true;
}

/*!
  \return Returns the lacing type that produces the smallest footprint.
*/
LacingType KaxInternalBlock::GetBestLacingType() const {
  int XiphLacingSize, EbmlLacingSize, i;
  bool SameSize = true;

  if (myBuffers.size() <= 1)
    return LACING_NONE;

  XiphLacingSize = 1; // Number of laces is stored in 1 byte.
  EbmlLacingSize = 1;
  for (i = 0; i < static_cast<int>(myBuffers.size()) - 1; i++) {
    if (myBuffers[i]->Size() != myBuffers[i + 1]->Size())
      SameSize = false;
    XiphLacingSize += myBuffers[i]->Size() / 255 + 1;
  }
  EbmlLacingSize += CodedSizeLength(myBuffers[0]->Size(), 0, IsFiniteSize());
  for (i = 1; i < static_cast<int>(myBuffers.size()) - 1; i++)
    EbmlLacingSize += SignedVINTLength(static_cast<std::int64_t>(myBuffers[i]->Size()) - static_cast<std::int64_t>(myBuffers[i - 1]->Size()));
  if (SameSize)
    return LACING_FIXED;
  if (XiphLacingSize < EbmlLacingSize)
    return LACING_XIPH;

  return LACING_EBML;
}

filepos_t KaxInternalBlock::UpdateSize(bool /* bSaveDefault */, bool /* bForceRender */)
{
  LacingType LacingHere;
  assert(!EbmlBinary::GetBuffer()); // Data is not used for KaxInternalBlock
  assert(TrackNumber < 0x4000); // no more allowed for the moment
  unsigned int i;

  // compute the final size of the data
  switch (myBuffers.size()) {
    case 0:
      SetSize_(0);
      break;
    case 1:
      SetSize_(4 + myBuffers[0]->Size());
      break;
    default:
      SetSize_(4 + 1); // 1 for the lacing head
      if (mLacing == LACING_AUTO)
        LacingHere = GetBestLacingType();
      else
        LacingHere = mLacing;
      switch (LacingHere) {
        case LACING_XIPH:
          for (i=0; i<myBuffers.size()-1; i++) {
            SetSize_(GetSize() + myBuffers[i]->Size() + (myBuffers[i]->Size() / 0xFF + 1));
          }
          break;
        case LACING_EBML:
          SetSize_(GetSize() + myBuffers[0]->Size() + CodedSizeLength(myBuffers[0]->Size(), 0, IsFiniteSize()));
          for (i=1; i<myBuffers.size()-1; i++) {
            SetSize_(GetSize() + myBuffers[i]->Size() + SignedVINTLength(static_cast<std::int64_t>(myBuffers[i]->Size()) - static_cast<std::int64_t>(myBuffers[i-1]->Size())));
          }
          break;
        case LACING_FIXED:
          for (i=0; i<myBuffers.size()-1; i++) {
            SetSize_(GetSize() + myBuffers[i]->Size());
          }
          break;
        default:
          i = 0;
          assert(0);
      }
      // Size of the last frame (not in lace)
      SetSize_(GetSize() + myBuffers[i]->Size());
      break;
  }

  if (TrackNumber >= 0x80)
    SetSize_(GetSize() + 1); // the size will be coded with one more octet

  return GetSize();
}

KaxBlockVirtual::KaxBlockVirtual(const KaxBlockVirtual & ElementToClone)
  :EbmlBinary(ElementToClone)
  ,Timecode(ElementToClone.Timecode)
  ,TrackNumber(ElementToClone.TrackNumber)
  ,ParentCluster(ElementToClone.ParentCluster) ///< \todo not exactly
{
  SetBuffer(DataBlock,sizeof(DataBlock));
  SetValueIsSet(false);
}

KaxBlockVirtual::KaxBlockVirtual()
{
  SetBuffer(DataBlock,sizeof(DataBlock));
  SetValueIsSet(false);
}

KaxBlockVirtual::~KaxBlockVirtual()
{
  if(GetBuffer() == DataBlock)
    SetBuffer( nullptr, 0 );
}

filepos_t KaxBlockVirtual::UpdateSize(bool /* bSaveDefault */, bool /* bForceRender */)
{
  assert(TrackNumber < 0x4000);
  binary *cursor = EbmlBinary::GetBuffer();
  // fill data
  if (TrackNumber < 0x80) {
    assert(GetSize() >= 4);
    *cursor++ = TrackNumber | 0x80; // set the first bit to 1
  } else {
    assert(GetSize() >= 5);
    *cursor++ = (TrackNumber >> 8) | 0x40; // set the second bit to 1
    *cursor++ = TrackNumber & 0xFF;
  }

  assert(ParentCluster);
  const std::int16_t ActualTimecode = ParentCluster->GetBlockLocalTimecode(Timecode);
  endian::to_big16(ActualTimecode, cursor);
  cursor += 2;

  *cursor++ = 0; // flags

  return GetSize();
}

/*!
  \todo more optimisation is possible (render the Block head and don't copy the buffer in memory, care should be taken with the allocation of Data)
  \todo the actual timecode to write should be retrieved from the Cluster from here
*/
filepos_t KaxInternalBlock::RenderData(IOCallback & output, bool /* bForceRender */, bool /* bSaveDefault */)
{
  if (myBuffers.empty())
    return 0;

  assert(TrackNumber < 0x4000);
  binary BlockHead[5];
  auto cursor = BlockHead;
  unsigned int i;

  if (myBuffers.size() == 1) {
    SetSize_(4);
    mLacing = LACING_NONE;
  } else {
    if (mLacing == LACING_NONE)
      mLacing = LACING_EBML; // supposedly the best of all
    SetSize_(4 + 1); // 1 for the lacing head (number of laced elements)
  }
  if (TrackNumber >= 0x80)
    SetSize_(GetSize() + 1);

  // write Block Head
  if (TrackNumber < 0x80) {
    *cursor++ = TrackNumber | 0x80; // set the first bit to 1
  } else {
    *cursor++ = (TrackNumber >> 8) | 0x40; // set the second bit to 1
    *cursor++ = TrackNumber & 0xFF;
  }

  assert(ParentCluster);
  const std::int16_t ActualTimecode = ParentCluster->GetBlockLocalTimecode(Timecode);
  endian::to_big16(ActualTimecode, cursor);
  cursor += 2;

  *cursor = 0; // flags

  if (mLacing == LACING_AUTO) {
    mLacing = GetBestLacingType();
  }

  // invisible flag
  if (mInvisible)
    *cursor = 0x08;

  if (bIsSimple) {
    if (bIsKeyframe)
      *cursor |= 0x80;
    if (bIsDiscardable)
      *cursor |= 0x01;
  }

  // lacing flag
  switch (mLacing) {
    case LACING_XIPH:
      *cursor++ |= 0x02;
      break;
    case LACING_EBML:
      *cursor++ |= 0x06;
      break;
    case LACING_FIXED:
      *cursor++ |= 0x04;
      break;
    case LACING_NONE:
      break;
    default:
      assert(0);
  }

  output.writeFully(BlockHead, 4 + ((TrackNumber >= 0x80) ? 1 : 0));

  binary tmpValue;
  switch (mLacing) {
    case LACING_XIPH:
      // number of laces
      tmpValue = myBuffers.size()-1;
      output.writeFully(&tmpValue, 1);

      // set the size of each member in the lace
      for (i=0; i<myBuffers.size()-1; i++) {
        tmpValue = 0xFF;
        std::uint16_t tmpSize = myBuffers[i]->Size();
        while (tmpSize >= 0xFF) {
          output.writeFully(&tmpValue, 1);
          SetSize_(GetSize() + 1);
          tmpSize -= 0xFF;
        }
        tmpValue = static_cast<binary>(tmpSize);
        output.writeFully(&tmpValue, 1);
        SetSize_(GetSize() + 1);
      }
      break;
    case LACING_EBML:
      // number of laces
      tmpValue = myBuffers.size()-1;
      output.writeFully(&tmpValue, 1);
      {
        std::int64_t _Size;
        int _CodedSize;
        binary _FinalHead[8]; // 64 bits max coded size

        _Size = myBuffers[0]->Size();

        _CodedSize = CodedSizeLength(_Size, 0, IsFiniteSize());

        // first size in the lace is not a signed
        CodedValueLength(_Size, _CodedSize, _FinalHead);
        output.writeFully(_FinalHead, _CodedSize);
        SetSize_(GetSize() + _CodedSize);

        // set the size of each member in the lace
        for (i=1; i<myBuffers.size()-1; i++) {
          _Size = static_cast<std::int64_t>(myBuffers[i]->Size()) - static_cast<std::int64_t>(myBuffers[i-1]->Size());
          _CodedSize = SignedVINTLength(_Size);
          SignedVINTValue(_Size, _CodedSize, _FinalHead);
          output.writeFully(_FinalHead, _CodedSize);
          SetSize_(GetSize() + _CodedSize);
        }
      }
      break;
    case LACING_FIXED:
      // number of laces
      tmpValue = myBuffers.size()-1;
      output.writeFully(&tmpValue, 1);
      break;
    case LACING_NONE:
      break;
    default:
      assert(0);
  }

  // put the data of each frame
  for (const auto& myBuf : myBuffers) {
    output.writeFully(myBuf->Buffer(), myBuf->Size());
    SetSize_(GetSize() + myBuf->Size());
  }

  return GetSize();
}

std::uint64_t KaxInternalBlock::ReadInternalHead(IOCallback & input)
{
  binary Buffer[5], *cursor = Buffer;
  std::uint64_t Result = input.read(cursor, 4);
  if (Result != 4)
    return Result;

  // update internal values
  TrackNumber = *cursor++;
  if ((TrackNumber & 0x80) == 0) {
    // there is extra data
    if ((TrackNumber & 0x40) == 0) {
      // We don't support track numbers that large !
      return Result;
    }
    Result += input.read(&Buffer[4], 1);
    TrackNumber = (TrackNumber & 0x3F) << 8;
    TrackNumber += *cursor++;
  } else {
    TrackNumber &= 0x7F;
  }

  assert(ParentCluster);
  std::int16_t stamp = endian::from_big16(cursor);
  Timecode = ParentCluster->GetBlockGlobalTimecode(stamp);
  bLocalTimecodeUsed = false;
  cursor += 2;

  return Result;
}

/*!
  \todo better zero copy handling
*/
filepos_t KaxInternalBlock::ReadData(IOCallback & input, ScopeMode ReadFully)
{
  filepos_t Result;

  FirstFrameLocation = input.getFilePointer(); // will be updated accordingly below

  SetValueIsSet(false);

  try {
    if (ReadFully == SCOPE_ALL_DATA) {
      Result = EbmlBinary::ReadData(input, ReadFully);
      if (Result != GetSize())
        throw SafeReadIOCallback::EndOfStreamX(GetSize() - Result);

      binary *const BufferStart = EbmlBinary::GetBuffer();

      SafeReadIOCallback Mem(*this);
      std::uint8_t BlockHeadSize = 4;

      // update internal values
      TrackNumber = Mem.GetUInt8();
      if ((TrackNumber & 0x80) == 0) {
        // there is extra data
        if ((TrackNumber & 0x40) == 0) {
          // We don't support track numbers that large !
          throw SafeReadIOCallback::EndOfStreamX(0);
        }
        TrackNumber = (TrackNumber & 0x3F) << 8;
        TrackNumber += Mem.GetUInt8();
        BlockHeadSize++;
      } else {
        TrackNumber &= 0x7F;
      }

      LocalTimecode = static_cast<std::int16_t>(Mem.GetUInt16BE());
      bLocalTimecodeUsed = true;

      const std::uint8_t Flags = Mem.GetUInt8();
      if (EbmlId(*this) == EBML_ID(KaxSimpleBlock)) {
        bIsKeyframe = (Flags & 0x80) != 0;
        bIsDiscardable = (Flags & 0x01) != 0;
      }
      mInvisible = (Flags & 0x08) >> 3;
      mLacing = static_cast<LacingType>((Flags & 0x06) >> 1);

      // put all Frames in the list
      if (mLacing == LACING_NONE) {
        FirstFrameLocation += Mem.GetPosition();
        auto soloFrame = new DataBuffer(BufferStart + Mem.GetPosition(), GetSize() - BlockHeadSize);
        myBuffers.push_back(soloFrame);
        SizeList.resize(1);
        SizeList[0] = GetSize() - BlockHeadSize;
      } else {
        // read the number of frames in the lace
        std::uint32_t LastBufferSize = GetSize() - BlockHeadSize - 1; // 1 for number of frame
        const std::uint8_t FrameNum = Mem.GetUInt8(); // number of frames in the lace - 1
        // read the list of frame sizes
        std::uint8_t Index;
        std::int32_t FrameSize;
        std::uint32_t SizeRead;
        std::uint64_t SizeUnknown;

        SizeList.resize(FrameNum + 1);

        switch (mLacing) {
          case LACING_XIPH:
            for (Index=0; Index<FrameNum; Index++) {
              // get the size of the frame
              FrameSize = 0;
              std::uint8_t Value;
              do {
                Value = Mem.GetUInt8();
                FrameSize += Value;
                LastBufferSize--;
              } while (Value == 0xFF);
              SizeList[Index] = FrameSize;
              LastBufferSize -= FrameSize;
            }
            SizeList[Index] = LastBufferSize;
            break;
          case LACING_EBML:
            SizeRead = LastBufferSize;
            FrameSize = ReadCodedSizeValue(BufferStart + Mem.GetPosition(), SizeRead, SizeUnknown);
            if (!FrameSize || (static_cast<std::uint32_t>(FrameSize + SizeRead) > LastBufferSize))
              throw SafeReadIOCallback::EndOfStreamX(SizeRead);
            SizeList[0] = FrameSize;
            Mem.Skip(SizeRead);
            LastBufferSize -= FrameSize + SizeRead;

            for (Index=1; Index<FrameNum; Index++) {
              // get the size of the frame
              SizeRead = LastBufferSize;
              FrameSize += ReadSignedVINT(BufferStart + Mem.GetPosition(), SizeRead);
              if (!FrameSize || (static_cast<std::uint32_t>(FrameSize + SizeRead) > LastBufferSize))
                throw SafeReadIOCallback::EndOfStreamX(SizeRead);
              SizeList[Index] = FrameSize;
              Mem.Skip(SizeRead);
              LastBufferSize -= FrameSize + SizeRead;
            }
            if (Index <= FrameNum) // Safety check if FrameNum == 0
              SizeList[Index] = LastBufferSize;
            break;
          case LACING_FIXED:
            for (Index=0; Index<=FrameNum; Index++) {
              // get the size of the frame
              SizeList[Index] = LastBufferSize / (FrameNum + 1);
            }
            break;
          default: // other lacing not supported
            assert(0);
        }

        FirstFrameLocation += Mem.GetPosition();

        for (Index=0; Index<=FrameNum; Index++) {
          auto lacedFrame = new DataBuffer(BufferStart + Mem.GetPosition(), SizeList[Index]);
          myBuffers.push_back(lacedFrame);
          Mem.Skip(SizeList[Index]);
        }
      }

      const auto BufferEnd = BufferStart + GetSize();
      const std::size_t NumFrames  = myBuffers.size();

      // Sanity checks for frame pointers and boundaries.
      for (std::size_t Index = 0; Index < NumFrames; ++Index) {
        const auto FrameStart  = myBuffers[Index]->Buffer();
        const auto FrameEnd    = FrameStart + myBuffers[Index]->Size();
        const auto ExpectedEnd = (Index + 1) < NumFrames ? myBuffers[Index + 1]->Buffer() : BufferEnd;

        if ((FrameStart < BufferStart) || (FrameEnd > BufferEnd) || (FrameEnd != ExpectedEnd))
          throw SafeReadIOCallback::EndOfStreamX(0);
      }

      SetValueIsSet();
    } else if (ReadFully == SCOPE_PARTIAL_DATA) {
      binary _TempHead[5];
      Result = input.read(_TempHead, 5);
      if (Result != 5)
        throw SafeReadIOCallback::EndOfStreamX(0);
      binary *cursor = _TempHead;
      binary *_tmpBuf;
      std::uint8_t BlockHeadSize = 4;

      // update internal values
      TrackNumber = *cursor++;
      if ((TrackNumber & 0x80) == 0) {
        // there is extra data
        if ((TrackNumber & 0x40) == 0) {
          // We don't support track numbers that large !
          return Result;
        }
        TrackNumber = (TrackNumber & 0x3F) << 8;
        TrackNumber += *cursor++;
        BlockHeadSize++;
      } else {
        TrackNumber &= 0x7F;
      }

      LocalTimecode = endian::from_big16(cursor);
      bLocalTimecodeUsed = true;
      cursor += 2;

      if (EbmlId(*this) == EBML_ID(KaxSimpleBlock)) {
        bIsKeyframe = (*cursor & 0x80) != 0;
        bIsDiscardable = (*cursor & 0x01) != 0;
      }
      mInvisible = (*cursor & 0x08) >> 3;
      mLacing = static_cast<LacingType>((*cursor++ & 0x06) >> 1);
      if (cursor == &_TempHead[4]) {
        _TempHead[0] = _TempHead[4];
      } else {
        Result += input.read(_TempHead, 1);
      }

      FirstFrameLocation += cursor - _TempHead;

      // put all Frames in the list
      if (mLacing != LACING_NONE) {
        // read the number of frames in the lace
        const std::uint32_t TotalLacedSize = GetSize() - BlockHeadSize - 1; // 1 for number of frame
        std::uint32_t LastBufferSize = TotalLacedSize;
        const std::uint8_t FrameNum = _TempHead[0]; // number of frames in the lace - 1
        // read the list of frame sizes
        std::uint8_t Index;
        std::uint32_t FrameSize;
        std::uint32_t SizeRead;
        std::uint64_t SizeUnknown;

        SizeList.resize(FrameNum + 1);

        switch (mLacing) {
          case LACING_XIPH:
            for (Index=0; Index<FrameNum; Index++) {
              // get the size of the frame
              FrameSize = 0;
              do {
                Result += input.read(_TempHead, 1);
                FrameSize += static_cast<std::uint8_t>(_TempHead[0]);
                if (FrameSize > TotalLacedSize)
                  throw SafeReadIOCallback::EndOfStreamX(0);
                LastBufferSize--;

                FirstFrameLocation++;
              } while (_TempHead[0] == 0xFF);

              FirstFrameLocation++;
              SizeList[Index] = FrameSize;
              LastBufferSize -= FrameSize;
            }
            SizeList[Index] = LastBufferSize;
            break;
          case LACING_EBML:
            SizeRead = LastBufferSize;
            cursor = _tmpBuf = new binary[FrameNum*4]; /// \warning assume the mean size will be coded in less than 4 bytes
            Result += input.read(cursor, FrameNum*4);
            FrameSize = ReadCodedSizeValue(cursor, SizeRead, SizeUnknown);
            if (FrameSize > TotalLacedSize)
              throw SafeReadIOCallback::EndOfStreamX(0);
            SizeList[0] = FrameSize;
            cursor += SizeRead;
            LastBufferSize -= FrameSize + SizeRead;

            for (Index=1; Index<FrameNum; Index++) {
              // get the size of the frame
              SizeRead = LastBufferSize;
              FrameSize += ReadSignedVINT(cursor, SizeRead);
              if (FrameSize > TotalLacedSize)
                throw SafeReadIOCallback::EndOfStreamX(0);
              SizeList[Index] = FrameSize;
              cursor += SizeRead;
              LastBufferSize -= FrameSize + SizeRead;
            }

            FirstFrameLocation += cursor - _tmpBuf;

            SizeList[Index] = LastBufferSize;
            delete [] _tmpBuf;
            break;
          case LACING_FIXED:
            for (Index=0; Index<=FrameNum; Index++) {
              // get the size of the frame
              SizeList[Index] = LastBufferSize / (FrameNum + 1);
            }
            break;
          default: // other lacing not supported
            assert(0);
        }
      } else {
        SizeList.resize(1);
        SizeList[0] = GetSize() - BlockHeadSize;
      }
      SetValueIsSet(false);
      Result = GetSize();
    } else {
      SetValueIsSet(false);
      Result = GetSize();
    }

  } catch (const SafeReadIOCallback::EndOfStreamX&) {
    SetValueIsSet(false);

    myBuffers.clear();
    SizeList.clear();
    Timecode           = 0;
    LocalTimecode      = 0;
    TrackNumber        = 0;
    bLocalTimecodeUsed = false;
    FirstFrameLocation = 0;

    return 0;
  }

  return Result;
}

bool KaxBlockGroup::AddFrame(const KaxTrackEntry & track, std::uint64_t timecode, DataBuffer & buffer, LacingType lacing)
{
  auto & theBlock = GetChild<KaxBlock>(*this);
  assert(ParentCluster);
  theBlock.SetParent(*ParentCluster);
  ParentTrack = &track;
  return theBlock.AddFrame(track, timecode, buffer, lacing);
}

bool KaxBlockGroup::AddFrame(const KaxTrackEntry & track, std::uint64_t timecode, DataBuffer & buffer, const KaxBlockGroup & PastBlock, LacingType lacing)
{
  //  assert(past_timecode < 0);

  auto & theBlock = GetChild<KaxBlock>(*this);
  assert(ParentCluster);
  theBlock.SetParent(*ParentCluster);
  ParentTrack = &track;
  const bool bRes = theBlock.AddFrame(track, timecode, buffer, lacing);

  auto & thePastRef = GetChild<KaxReferenceBlock>(*this);
  thePastRef.SetReferencedBlock(PastBlock);
  thePastRef.SetParentBlock(*this);

  return bRes;
}

bool KaxBlockGroup::AddFrame(const KaxTrackEntry & track, std::uint64_t timecode, DataBuffer & buffer, const KaxBlockGroup & PastBlock, const KaxBlockGroup & ForwBlock, LacingType lacing)
{
  //  assert(past_timecode < 0);

  //  assert(forw_timecode > 0);

  auto & theBlock = GetChild<KaxBlock>(*this);
  assert(ParentCluster);
  theBlock.SetParent(*ParentCluster);
  ParentTrack = &track;
  bool const bRes = theBlock.AddFrame(track, timecode, buffer, lacing);

  auto & thePastRef = GetChild<KaxReferenceBlock>(*this);
  thePastRef.SetReferencedBlock(PastBlock);
  thePastRef.SetParentBlock(*this);

  auto & theFutureRef = AddNewChild<KaxReferenceBlock>(*this);
  theFutureRef.SetReferencedBlock(ForwBlock);
  theFutureRef.SetParentBlock(*this);

  return bRes;
}

bool KaxBlockGroup::AddFrame(const KaxTrackEntry & track, std::uint64_t timecode, DataBuffer & buffer, const KaxBlockBlob * PastBlock, const KaxBlockBlob * ForwBlock, LacingType lacing)
{
  auto & theBlock = GetChild<KaxBlock>(*this);
  assert(ParentCluster);
  theBlock.SetParent(*ParentCluster);
  ParentTrack = &track;
  const bool bRes = theBlock.AddFrame(track, timecode, buffer, lacing);

  if (PastBlock) {
    auto & thePastRef = GetChild<KaxReferenceBlock>(*this);
    thePastRef.SetReferencedBlock(PastBlock);
    thePastRef.SetParentBlock(*this);
  }

  if (ForwBlock) {
    auto & theFutureRef = AddNewChild<KaxReferenceBlock>(*this);
    theFutureRef.SetReferencedBlock(ForwBlock);
    theFutureRef.SetParentBlock(*this);
  }

  return bRes;
}

/*!
  \todo we may cache the reference to the timecode block
*/
std::uint64_t KaxBlockGroup::GlobalTimecode() const
{
  assert(ParentCluster); // impossible otherwise
  auto MyBlock = static_cast<KaxBlock *>(this->FindElt(EBML_INFO(KaxBlock)));
  return MyBlock->GlobalTimecode();
}

std::uint16_t KaxBlockGroup::TrackNumber() const
{
  auto MyBlock = static_cast<KaxBlock *>(this->FindElt(EBML_INFO(KaxBlock)));
  return MyBlock->TrackNum();
}

std::uint64_t KaxBlockGroup::ClusterPosition() const
{
  assert(ParentCluster); // impossible otherwise
  return ParentCluster->GetPosition();
}

std::uint64_t KaxInternalBlock::ClusterPosition() const
{
  assert(ParentCluster); // impossible otherwise
  return ParentCluster->GetPosition();
}

unsigned int KaxBlockGroup::ReferenceCount() const
{
  unsigned int Result = 0;
  auto MyBlockAdds = static_cast<KaxReferenceBlock *>(FindFirstElt(EBML_INFO(KaxReferenceBlock)));
  if (MyBlockAdds) {
    Result++;
    while ((MyBlockAdds = static_cast<KaxReferenceBlock *>(FindNextElt(*MyBlockAdds)))) {
      Result++;
    }
  }
  return Result;
}

const KaxReferenceBlock & KaxBlockGroup::Reference(unsigned int Index) const
{
  auto MyBlockAdds = static_cast<KaxReferenceBlock *>(FindFirstElt(EBML_INFO(KaxReferenceBlock)));
  assert(MyBlockAdds); // call of a non existing reference

  while (Index != 0) {
    MyBlockAdds = static_cast<KaxReferenceBlock *>(FindNextElt(*MyBlockAdds));
    assert(MyBlockAdds);
    Index--;
  }
  return *MyBlockAdds;
}

void KaxBlockGroup::ReleaseFrames()
{
  auto MyBlock = static_cast<KaxBlock *>(this->FindElt(EBML_INFO(KaxBlock)));
  MyBlock->ReleaseFrames();
}

void KaxInternalBlock::ReleaseFrames()
{
  // free the allocated Frames
  for (int i=myBuffers.size()-1; i>=0; i--) {
    if (myBuffers[i]) {
      myBuffers[i]->FreeBuffer(*myBuffers[i]);
      delete myBuffers[i];
      myBuffers[i] = nullptr;
    }
  }
}

void KaxBlockGroup::SetBlockDuration(std::uint64_t TimeLength)
{
  assert(ParentTrack);
  const std::int64_t scale = ParentTrack->GlobalTimecodeScale();
  const auto myDuration = static_cast<KaxBlockDuration *>(FindFirstElt(EBML_INFO(KaxBlockDuration), true));
  *(static_cast<EbmlUInteger *>(myDuration)) = TimeLength / static_cast<std::uint64_t>(scale);
}

bool KaxBlockGroup::GetBlockDuration(std::uint64_t &TheTimecode) const
{
  const auto myDuration = static_cast<KaxBlockDuration *>(FindElt(EBML_INFO(KaxBlockDuration)));
  if (!myDuration) {
    return false;
  }

  assert(ParentTrack);
  TheTimecode = static_cast<std::uint64_t>(*myDuration) * ParentTrack->GlobalTimecodeScale();
  return true;
}

KaxBlockGroup::operator KaxInternalBlock &() {
  auto & theBlock = GetChild<KaxBlock>(*this);
  return theBlock;
}

void KaxBlockGroup::SetParent(KaxCluster & aParentCluster) {
  ParentCluster = &aParentCluster;
  auto & theBlock = GetChild<KaxBlock>(*this);
  theBlock.SetParent( aParentCluster );
}

void KaxSimpleBlock::SetParent(KaxCluster & aParentCluster) {
  KaxInternalBlock::SetParent( aParentCluster );
}

void KaxInternalBlock::SetParent(KaxCluster & aParentCluster)
{
  ParentCluster = &aParentCluster;
  if (bLocalTimecodeUsed) {
    Timecode = aParentCluster.GetBlockGlobalTimecode(LocalTimecode);
    bLocalTimecodeUsed = false;
  }
}

std::int64_t KaxInternalBlock::GetDataPosition(std::size_t FrameNumber)
{
  std::int64_t _Result = -1;

  if (ValueIsSet() && FrameNumber < SizeList.size()) {
    _Result = FirstFrameLocation;

    std::size_t _Idx = 0;
    while(FrameNumber--) {
      _Result += SizeList[_Idx++];
    }
  }

  return _Result;
}

std::int64_t KaxInternalBlock::GetFrameSize(std::size_t FrameNumber)
{
  std::int64_t _Result = -1;

  if (/*bValueIsSet &&*/ FrameNumber < SizeList.size()) {
    _Result = SizeList[FrameNumber];
  }

  return _Result;
}

KaxBlockBlob::operator KaxBlockGroup &() const
{
  assert(!bUseSimpleBlock);
  assert(Block.group);
  return *Block.group;
}

KaxBlockBlob::operator KaxInternalBlock &() const
{
  assert(Block.group);
  if (bUseSimpleBlock)
    return *Block.simpleblock;
  return *Block.group;
}

KaxBlockBlob::operator KaxSimpleBlock &() const
{
  assert(bUseSimpleBlock);
  assert(Block.simpleblock);
  return *Block.simpleblock;
}

bool KaxBlockBlob::AddFrameAuto(const KaxTrackEntry & track, std::uint64_t timecode, DataBuffer & buffer, LacingType lacing, const KaxBlockBlob * PastBlock, const KaxBlockBlob * ForwBlock)
{
  bool bResult = false;
  if ((SimpleBlockMode == BLOCK_BLOB_ALWAYS_SIMPLE) || (SimpleBlockMode == BLOCK_BLOB_SIMPLE_AUTO && !PastBlock && !ForwBlock)) {
    assert(bUseSimpleBlock == true);
    if (!Block.simpleblock) {
      Block.simpleblock = new KaxSimpleBlock();
      Block.simpleblock->SetParent(*ParentCluster);
    }

    bResult = Block.simpleblock->AddFrame(track, timecode, buffer, lacing);
    if (!PastBlock && !ForwBlock) {
      Block.simpleblock->SetKeyframe(true);
      Block.simpleblock->SetDiscardable(false);
    } else {
      Block.simpleblock->SetKeyframe(false);
      if ((!ForwBlock || static_cast<KaxInternalBlock &>(*ForwBlock).GlobalTimecode() <= timecode) &&
          (!PastBlock || static_cast<KaxInternalBlock &>(*PastBlock).GlobalTimecode() <= timecode))
        Block.simpleblock->SetDiscardable(false);
      else
        Block.simpleblock->SetDiscardable(true);
    }
  }
  else
    if (ReplaceSimpleByGroup())
      bResult = Block.group->AddFrame(track, timecode, buffer, PastBlock, ForwBlock, lacing);

  return bResult;
}

void KaxBlockBlob::SetParent(KaxCluster & aParentCluster)
{
  ParentCluster = &aParentCluster;
}

void KaxBlockBlob::SetBlockDuration(std::uint64_t TimeLength)
{
  if (ReplaceSimpleByGroup())
    Block.group->SetBlockDuration(TimeLength);
}

bool KaxBlockBlob::ReplaceSimpleByGroup()
{
  if (SimpleBlockMode== BLOCK_BLOB_ALWAYS_SIMPLE)
    return false;

  if (!bUseSimpleBlock) {
    if (!Block.group) {
      Block.group = new KaxBlockGroup();
    }
  }
  else {

    if (Block.simpleblock) {
      auto old_simpleblock = Block.simpleblock;
      Block.group = new KaxBlockGroup();
      // _TODO_ : move all the data to the blockgroup
      assert(false);
      // -> while(frame) AddFrame(myBuffer)
      delete old_simpleblock;
    } else {
      Block.group = new KaxBlockGroup();
    }
  }
  if (ParentCluster)
    Block.group->SetParent(*ParentCluster);

  bUseSimpleBlock = false;
  return true;
}

void KaxBlockBlob::SetBlockGroup( KaxBlockGroup &BlockRef )
{
  assert(!bUseSimpleBlock);
  Block.group = &BlockRef;
}

filepos_t KaxBlockVirtual::ReadData(IOCallback & input, ScopeMode /* ReadFully */)
{
  input.setFilePointer(GetEndPosition(), seek_beginning);
  return GetSize();
}

} // namespace libmatroska
