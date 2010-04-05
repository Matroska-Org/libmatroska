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
** Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
**
** See http://www.matroska.org/license/lgpl/ for LGPL licensing information.**
** Contact license@matroska.org if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

/*!
	\file
	\version \$Id: KaxClusterData.cpp 955 2004-11-28 15:24:37Z robux4 $
	\author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include "matroska/KaxClusterData.h"
#include "matroska/KaxContexts.h"
#include "matroska/KaxDefines.h"

START_LIBMATROSKA_NAMESPACE

static const EbmlSemantic ContextList_KaxClusterSilentTracks[1] =
{
	EbmlSemantic(false,  false, EBML_INFO(KaxClusterSilentTrackNumber)),
};

DEFINE_MKX_UINTEGER(KaxClusterTimecode,            0xE7, 1, KaxCluster, "ClusterTimecode");
DEFINE_MKX_MASTER  (KaxClusterSilentTracks,      0x5854, 2, KaxCluster, "ClusterSilentTracks")
DEFINE_MKX_UINTEGER(KaxClusterSilentTrackNumber, 0x58D7, 2, KaxClusterSilentTracks, "ClusterSilentTrackNumber");
DEFINE_MKX_UINTEGER(KaxClusterPosition,            0xA7, 1, KaxCluster, "ClusterPosition");
DEFINE_MKX_UINTEGER(KaxClusterPrevSize,            0xAB, 1, KaxCluster, "ClusterPrevSize");

KaxClusterSilentTracks::KaxClusterSilentTracks()
:EbmlMaster(Context_KaxClusterSilentTracks)
{}

END_LIBMATROSKA_NAMESPACE
