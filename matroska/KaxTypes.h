// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
*/
#ifndef LIBMATROSKA_TYPES_H
#define LIBMATROSKA_TYPES_H

#include "matroska/KaxConfig.h"
#include <ebml/EbmlTypes.h>

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

/*!
    \enum matroska_error_t
    \brief a callback that the library use to inform of errors happening
    \note this should be used by the libmatroska internals
*/
typedef enum {
  error_null_pointer  ///< NULL pointer where something else is expected
} matroska_error_t;

typedef void *matroska_stream;

/*!
    \var void* matroska_id
    \brief UID used to access an Matroska file instance
*/
typedef void* matroska_id;
/*!
    \var void* matroska_track
    \brief UID used to access a track
*/
typedef void* matroska_track;
/*!
    \var char* c_string
    \brief C-String, ie a buffer with characters terminated by \0
*/
typedef char* c_string;
/*!
    \var unsigned int matroska_file_mode
    \brief A bit buffer, each bit representing a value for the file opening
    \todo replace the unsigned int by a sized type (8 or 16 bits)
*/
typedef char * matroska_file_mode;
/*!
    \var void (*matroska_error_callback)(matroska_error_t error_code, char* error_message)
    \brief a callback that the library use to inform of errors happening
*/
typedef void (*matroska_error_callback)(matroska_error_t error_code, char* error_message);

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
