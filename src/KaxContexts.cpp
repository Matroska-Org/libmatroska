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
  \version \$Id: KaxContexts.cpp 640 2004-07-09 21:05:36Z mosu $
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include "ebml/EbmlContexts.h"
#include "ebml/EbmlHead.h"
#include "matroska/KaxContexts.h"
#include "matroska/KaxBlock.h"
#include "matroska/KaxCluster.h"
#include "matroska/KaxSegment.h"
#include "matroska/KaxTracks.h"

using namespace LIBEBML_NAMESPACE;

START_LIBMATROSKA_NAMESPACE

DEFINE_START_SEMANTIC(KaxMatroska)
DEFINE_SEMANTIC_ITEM(true, true, EbmlHead)
DEFINE_SEMANTIC_ITEM(false, false, KaxSegment)
DEFINE_END_SEMANTIC(KaxMatroska)

DEFINE_MKX_CONTEXT(KaxMatroska)

DEFINE_SEMANTIC_CONTEXT(KaxSegment)
DEFINE_SEMANTIC_CONTEXT(KaxAttached)
DEFINE_SEMANTIC_CONTEXT(KaxAttachments)
DEFINE_SEMANTIC_CONTEXT(KaxBlockGroup)
DEFINE_SEMANTIC_CONTEXT(KaxCluster)
DEFINE_SEMANTIC_CONTEXT(KaxTrackEntry)

// for the moment
const EbmlSemanticContext & GetKaxGlobal_Context()
{
  return GetEbmlGlobal_Context();
}

END_LIBMATROSKA_NAMESPACE
