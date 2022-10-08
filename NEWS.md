# Version 1.7.1 2022-10-08

* Fix ABI compatibility: unfortunately release 1.7.0 broke ABI
  compatibility. This release restores the compatibility with release
  1.6.3. Please use it instead of release 1.7.0. In other words: 1.6.3
  & 1.7.1 are compatible, while 1.7.0 is compatible with neither 1.6.3
  nor 1.7.1. Fixes #81.

# Version 1.7.0 2022-09-30

* A C++14 compliant C++ compiler is now required.
* libEBML v1.4.3 is now required.
* Remove Coremake project files
* Add `KaxInternalBlock::GetRelativeTimestamp()` to access unscaled
  block timestamps.
* Fixed problems with the generated `pkg-config` files if any of the
  installation paths are absolute.
* Added several enums in `namespace libmatroska` for the various
  elements that are constrained to a set of options:
  `MatroskaTrackType`, `MatroskaTrackEncodingCompAlgo`,
  `MatroskaChapterTranslateCodec`, `MatroskaTrackTranslateCodec`,
  `MatroskaVideoFlagInterlaced`, `MatroskaVideoFieldOrder`,
  `MatroskaVideoStereoMode`, `MatroskaVideoAlphaMode`,
  `MatroskaVideoOldStereoMode`, `MatroskaVideoDisplayUnit`,
  `MatroskaVideoAspectRatioType`, `MatroskaVideoMatrixCoefficients`,
  `MatroskaColourChromaSitingHorz`, `MatroskaColourChromaSitingVert`,
  `MatroskaVideoRange`, `MatroskaVideoTransferCharacteristics`,
  `MatroskaVideoPrimaries`, `MatroskaVideoProjectionType`,
  `MatroskaAudioEmphasis`, `MatroskaTrackPlaneType`,
  `MatroskaContentEncodingScope`, `MatroskaContentEncodingType`,
  `MatroskaContentEncodingAlgo`, `MatroskaAESSettingsCipherMode`,
  `MatroskaContentSignatureAlgo`, `MatroskaContentSigHashAlgo`,
  `MatroskaChapterSkipType`, `MatroskaChapterProcessTime` and
  `MatroskaTargetTypeValue`.
* Updated the semantics to the latest specifications, deprecating the
  following elements by preventing code to write them:
  `KaxClusterSilentTracks`, `KaxClusterSilentTrackNumber`,
  `KaxSlices`, `KaxReferenceFrame`, `KaxReferenceOffset`,
  `KaxReferenceTimeCode`, `KaxTrackTimecodeScale`,
  `KaxCodecDecodeAll`, `KaxVideoAspectRatio`, `KaxTrickTrackUID`,
  `KaxTrickTrackSegmentUID`, `KaxTrickTrackFlag`,
  `KaxTrickMasterTrackUID`, `KaxTrickMasterTrackSegmentUID`,
  `KaxContentSignature`, `KaxContentSigKeyID`, `KaxContentSigAlgo` and
  `KaxContentSigHashAlgo`.
* Updated the semantics to the latest specifications, making the
  following elements mandatory (but having default values):
  `KaxCodecDelay`, `KaxVideoPixelCropBottom`, `KaxVideoPixelCropTop`,
  `KaxVideoPixelCropLeft`, `KaxVideoPixelCropRight`,
  `KaxVideoBitsPerChannel`, `KaxCueCodecState`,
  `KaxTagTargetTypeValue`, `KaxTrackLanguage`, `KaxVideoStereoMode`,
  `KaxVideoAlphaMode`, `KaxEditionFlagOrdered`,
  `KaxVideoChromaSitHorz`, `KaxVideoChromaSitVert`,
  `KaxVideoColourRange`, `KaxVideoColourMatrix`,
  `KaxVideoColourTransferCharacter`, `KaxVideoColourPrimaries` and
  `KaxVideoDisplayUnit`.
* Updated the semantics to the latest specifications, removing the
  default values from the following elements: `KaxCueBlockNumber`,
  `KaxFlagHearingImpaired`, `KaxFlagVisualImpaired`,
  `KaxFlagTextDescriptions`, and `KaxFlagOriginal`.
* Updated the semantics to the latest specifications, adding the
  following new elements: `TagDefaultBogus` (as a placeholder for
  accidentally used but wrong EBML ID 0x44b4), `KaxEmphasis`,
  `KaxChapterSkipType`, `KaxEditionDisplay`, `KaxEditionString` and
  `KaxEditionLanguageIETF`.

# Version 1.6.3 2021-02-18

* libEBML v1.4.2 is now required.
* Added classes for new track header elements:
  `KaxFlagHearingImpaired`, `KaxFlagVisualImpaired`,
  `KaxFlagTextDescriptions`, `KaxFlagOriginal` and
  `KaxFlagCommentary`.

# Version 1.6.2 2020-08-02

* In release 1.6.1 the version number in `CMakeLists.txt` wasn't
  updated, affecting the installed `cmake` and `pkg-config` files. The
  version number has been bumped to 1.6.2 in all relevant files now.

# Version 1.6.1 2020-08-02

* `KaxBlockAddIDValue` class: this class is no longer marked as
  "mandatory" in order to coincide with the latest specification.

# Version 1.6.0 2020-06-27

* libEBML v1.4.0 is now required.
* Due to breaking ABI the soname version has been bumped to 7.0.0.
* Default symbol visibility is now "hidden", reducing binary size.
* Converted some things pointed out by `cppcheck` & `clang-tidy` to
  C++11.
* Fixed a lot of issues pointed out by `clang-tidy`.
* A C++11 compliant compiler is now required. Several of its features
  are now used in the source.
* `KaxCueData` class: added `PositionSet` overrides taking
  `KaxSimpleBlock` arguments.
* `KaxSeekHead` class: the `IndexThis` function now returns a pointer
  to the newly allocated `KaxSeek` instance.
* `KaxBlockData` class: the `SetReferencedTimecode` function is now
  public.
* Fixed classes for updates in the current specification:
  `KaxTrackTimecodeScale` (can be written again), `TimeSlice`,
  `SliceLaceNumber`, `TrackAttachmentLink` (these cannot be written
  anymore), `KaxContentEncAlgo` (it's mandatory),
  `KaxChapLanguageIETF` (can occur multiple times),
  `KaxFileUsedStartTime`, `KaxFileUsedEndTime` (DivX-related elements,
  cannot be written anymore)
* Added classes for new elements from the current specification:
  `KaxBlockAdditionMapping`, `KaxBlockAddIDValue`,
  `KaxBlockAddIDName`, `KaxBlockAddIDType`, `KaxBlockAddIDExtraData`,
  `KaxContentEncAESSettings`, `KaxContentEncAESSettings`.
* The `MATROSKA_VERSION` pre-processor definition has been
  removed. You used to be able toe restrict compiling with only those
  classes for elements contained in Matroska v1, but that hasn't
  worked since 2010, so… yeah.
* Build system: more fixes for building libMatroska as a DLL on
  Windows wrt. symbol visibility.

# Version 1.5.2 2019-05-27

* Build system: fixed symbol visibility issue causing linker failures
  since 1.5.1.

# Version 1.5.1 2019-05-25

* Build system: libEBML 1.3.8 is now required.
* Build system: various fixes to the cmake rules regarding visibility,
  naming and building DLLs on Windows.
* `KaxBlock`: fixed a potential access to invalid memory due to
  invalid lace sizes read from invalid data.
* `KaxBlock`: fixed a potential null pointer dereference triggerable
  by reading invalid data.

# Version 1.5.0 2019-03-12

* Build system: libEBML 1.3.7 is now required.
* Build system: fixed a problem that prevented libMatroska from being
  embedded in other builds.

# Version 1.4.9 2018-04-20

* Converted the build system from `autoconf`/`automake` to
  `cmake`. Patches by Github user "evpobr" with fixes by myself.
* Added a code of conduct to the project.

# Version 1.4.8 2017-09-25

* `KaxBlockGroup`, `KaxSimpleBlock`: fixed writing the block header if
  the track number is 128.

# Version 1.4.7 2017-03-10

* Released v1.4.7 with the single change of setting the version number
  in the `KaxCodeVersion` variable correctly.

# Version 1.4.6 2017-03-10

* `KaxSemantic`: add new elements dealing with 360°/VR content and for
  language descriptors based on IETF BPC 47.

# Version 1.4.5 2016-07-02

* `KaxSemantic`: add new colour-related elements.
* `KaxSemantic`: add the new FieldOrder element.
* `KaxVersion.cpp`: in order to enable deterministic builds the
  `KaxCodeDate` variable has been set to `"Unknown"` instead of the
  date and time of compilation. Patch by Ed Schouten <ed@nuxi.nl>.

# Version 1.4.4 2015-10-20

* `KaxInternalBlock::ReadData()`: Fixed an invalid memory access. When
  reading a block group or a simple block that uses EBML lacing the
  frame sizes indicated in the lacing weren't checked against the
  available number of bytes. If the indicated frame size was bigger
  than the whole block's size the parser would read beyond the end of
  the buffer resulting in a heap information leak.

# Version 1.4.3 2015-10-17

* all: a couple of optimizations in the main library and a memory leak
  fix in the tests
* build system: fix linking against libEBML

# Version 1.4.2 2015-01-04

* build system: switched the build system from hand-crafted
  `Makefiles` to an `autoconf`/`automake`-based system. A `pkg-config`
  file will be installed as well; its name is `libmatroska`. Based on
  a similar patch for libEBML by Jan Engelhardt <jengelh@inai.de>.
* `KaxBlock::ReadData()`: fixed several instances of unchecked memory
  access leading to invalid memory access/segmentation faults with
  invalid or broken data inside block groups/simple blocks.
* `KaxBlock::ReadInternalHead()`: fixed a off-by-one buffer overflow
  if with EBML lacing and exactly one frame in the lace.

# Version 1.4.1 2013-09-17

* Added new elements/classes `DiscardPadding`, `CodecDelay` and
  `SeekPreRoll`
* The licensing information has been cleared up/unified.
* The Makefile now contain options for specifying the destination base
  directory during installation (`DESTDIR`) and for specifying which
  library types to build (`link`).
* The libraries are built without the `-ansi` and `-fno-gnu-keywords`
  flags on Linux
* Code cleanup

# Version 1.4.0 2013-03-19

* Note that this release is not binary compatible to 1.3.0 due to the
  dependancy on libEBML 1.3.0 which is not binary compatible to its
  predecessor.
* Added new elements `CueDuration`, `CueRelativePosition`,
  `ChapterStringUID`, `VideoAlphaMode` and
  `DefaultDecodedFieldDuration`
* Removed the Debian build files from our package.

# Version 1.3.0 2011-09-23

* initialize all data members
* The `KaxCodeVersion` variable now resides in the library instead of
  being declared static in the header file.
* make `KaxChapterSegmentEditionUID` an unsigned integer to match the
  `KaxChapterEditionUID` it's supposed to target
* This release is not binary compatible to 1.2.x.

# Version 1.2.0 2011-06-26

* skip data from `KaxBlockVirtual` as it should not be used
* use semantic generated from the specs so there is no more possible
  mismatch
* trunk/libmatroska/test/test9.cpp
* also remove no longer needed tests for old/outdated/previous tag
  system

# Version 1.1.0 2011-01-30

* give access to the `SetParent` to `KaxSimpleBlock` as well
* change the placement of a `MATROSKA_DLL_API` so that it actually
  works
* remove all references to the old/outdated/previous tag system
* add the possibility for a `DataBuffer` class to use its own internal
  memory
* `KaxCues::AddBlockGroup()` was removed as it's broken beyond repair
* add `KaxTrackOperation` and related elements for combined stereo/3D
  tracks or joined virtual tracks
* fix a memory leak in `KaxReferenceBlock` when an internal
  `KaxBlockBlob` was created
* Increased library `.so` name due to binary incompatible changes in
  libebml

# Version 1.0.0 2010-06-04

* rename the library `.so` name as it's backward incompatible

# Version 0.9.0 2010-04-30

* fix a memory freeing issue in `KaxBlock`
* use the macros from the new libebml 0.8.0 to simplify the element
  definitions and avoid possible typo bugs
* fix some building issues on Linux and MinGW
* add `matroska_init()` and `matroska_done()` functions, necessary
  when used with libebml v2
* use the new libebml iterators of `EbmlMaster` where possible
