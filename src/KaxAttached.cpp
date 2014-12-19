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
  \version \$Id: KaxAttached.cpp 1202 2005-08-30 14:39:01Z robux4 $
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include "matroska/KaxContexts.h"
#include "matroska/KaxDefines.h"
#include "matroska/KaxSemantic.h"

// sub elements

using namespace LIBEBML_NAMESPACE;

START_LIBMATROSKA_NAMESPACE

KaxAttached::KaxAttached(EBML_EXTRA_DEF)
  :EbmlMaster(EBML_CLASS_SEMCONTEXT(KaxAttached) EBML_DEF_SEP EBML_EXTRA_CALL)
{
  SetSizeLength(2); // mandatory min size support (for easier updating) (2^(7*2)-2 = 16Ko)
}

END_LIBMATROSKA_NAMESPACE
