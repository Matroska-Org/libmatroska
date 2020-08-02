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
  \version \$Id: KaxVersion.cpp 640 2004-07-09 21:05:36Z mosu $
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/

#include "matroska/KaxVersion.h"

START_LIBMATROSKA_NAMESPACE

const std::string KaxCodeVersion = "1.6.2";

// Up to version 1.4.4 this library exported a build date string. As
// this made the build non-reproducible, replace it by a placeholder to
// remain binary compatible.
const std::string KaxCodeDate = "Unknown";

END_LIBMATROSKA_NAMESPACE
