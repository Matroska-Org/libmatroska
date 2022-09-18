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
  \version \$Id: KaxConfig.h,v 1.7 2004/04/14 23:26:17 robux4 Exp $
  \author Steve Lhomme     <robux4 @ users.sf.net>
  \author Moritz Bunkus <moritz @ bunkus.org>
*/
#ifndef LIBMATROSKA_CONFIG_H
#define LIBMATROSKA_CONFIG_H

#define LIBMATROSKA_NAMESPACE       libmatroska
#define START_LIBMATROSKA_NAMESPACE namespace LIBMATROSKA_NAMESPACE {
#define END_LIBMATROSKA_NAMESPACE   }

#include "matroska_export.h"

#if defined(MATROSKA_VERSION) && MATROSKA_VERSION < 2
#error MATROSKA_VERSION <= 2 no longer supported, update your code accordingly
#endif // MATROSKA_VERSION


#endif // LIBMATROSKA_CONFIG_H
