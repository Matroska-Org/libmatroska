// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
*/
#ifndef LIBMATROSKA_TYPES_H
#define LIBMATROSKA_TYPES_H

#include "matroska/KaxConfig.h"

/*!
    \enum track_type
*/
typedef enum track_type {
    track_video       = 0x01, ///< Rectangle-shaped non-transparent pictures aka video
    track_audio       = 0x02, ///< Anything you can hear
    track_complex     = 0x03, ///< Audio and video in same track, used by DV

    track_logo        = 0x10, ///< Overlay-pictures, displayed over video
    track_subtitle    = 0x11, ///< Text-subtitles. One track contains one language and only one track can be active (player-side configuration)
    track_buttons     = 0x12, ///< Buttons meta-infos.

    track_control     = 0x20  ///< Control-codes for menus and other stuff
} track_type;


namespace libmatroska {

enum LacingType {
  LACING_NONE = 0,
  LACING_XIPH,
  LACING_FIXED,
  LACING_EBML,
  LACING_AUTO
};

enum BlockBlobType {
  BLOCK_BLOB_NO_SIMPLE = 0,
  BLOCK_BLOB_SIMPLE_AUTO,
  BLOCK_BLOB_ALWAYS_SIMPLE,
};

} // namespace libmatroska

#endif // LIBMATROSKA_TYPES_H
