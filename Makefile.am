# -*- Makefile -*-

ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = -I${top_srcdir}
AM_CXXFLAGS = -Wall -Wextra -Wno-unknown-pragmas -Wshadow $(EBML_CFLAGS)
if ENABLE_DEBUG
AM_CPPFLAGS += -DDEBUG
AM_CXXFLAGS += -g
endif

lib_LTLIBRARIES = libmatroska.la
libmatroska_la_SOURCES = \
	src/FileKax.cpp \
	src/KaxAttached.cpp \
	src/KaxAttachments.cpp \
	src/KaxBlock.cpp \
	src/KaxBlockData.cpp \
	src/KaxCluster.cpp \
	src/KaxContexts.cpp \
	src/KaxCues.cpp \
	src/KaxCuesData.cpp \
	src/KaxInfoData.cpp \
	src/KaxSeekHead.cpp \
	src/KaxSegment.cpp \
	src/KaxSemantic.cpp \
	src/KaxTracks.cpp \
	src/KaxVersion.cpp
libmatroska_la_LDFLAGS = -version-info 6:0:0 -no-undefined

nobase_include_HEADERS = \
	matroska/c/libmatroska.h \
	matroska/c/libmatroska_t.h \
	matroska/FileKax.h \
	matroska/KaxAttached.h \
	matroska/KaxAttachments.h \
	matroska/KaxBlockData.h \
	matroska/KaxBlock.h \
	matroska/KaxChapters.h \
	matroska/KaxClusterData.h \
	matroska/KaxCluster.h \
	matroska/KaxConfig.h \
	matroska/KaxContentEncoding.h \
	matroska/KaxContexts.h \
	matroska/KaxCuesData.h \
	matroska/KaxCues.h \
	matroska/KaxDefines.h \
	matroska/KaxInfoData.h \
	matroska/KaxInfo.h \
	matroska/KaxSeekHead.h \
	matroska/KaxSegment.h \
	matroska/KaxSemantic.h \
	matroska/KaxTag.h \
	matroska/KaxTags.h \
	matroska/KaxTrackAudio.h \
	matroska/KaxTrackEntryData.h \
	matroska/KaxTracks.h \
	matroska/KaxTrackVideo.h \
	matroska/KaxTypes.h \
	matroska/KaxVersion.h

pkgconfigdir = ${libdir}/pkgconfig
pkgconfig_DATA = libmatroska.pc

${pkgconfig_DATA}: config.status
