/****************************************************************************
** libmatroska : parse Matroska files, see http://www.matroska.org/
**
** <file/class description>
**
** Copyright (C) 2002-2005 Steve Lhomme.  All rights reserved.
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
	\version \$Id: KaxInfo.cpp 1078 2005-03-03 13:13:04Z robux4 $
	\author Steve Lhomme     <robux4 @ users.sf.net>
*/
#include "matroska/KaxInfo.h"
#include "matroska/KaxInfoData.h"

#include "matroska/KaxContexts.h"

// sub elements
START_LIBMATROSKA_NAMESPACE

const EbmlSemantic KaxInfo_ContextList[14] =
{
	EbmlSemantic(false, true,  EBML_INFO(KaxSegmentUID)),
	EbmlSemantic(false, true,  EBML_INFO(KaxSegmentFilename)),
	EbmlSemantic(false, true,  EBML_INFO(KaxPrevUID)),
	EbmlSemantic(false, true,  EBML_INFO(KaxPrevFilename)),
	EbmlSemantic(false, true,  EBML_INFO(KaxNextUID)),
	EbmlSemantic(false, true,  EBML_INFO(KaxNextFilename)),
	EbmlSemantic(false, false, EBML_INFO(KaxSegmentFamily)),
	EbmlSemantic(false, false, EBML_INFO(KaxChapterTranslate)),
	EbmlSemantic(true,  true,  EBML_INFO(KaxTimecodeScale)),
	EbmlSemantic(false, true,  EBML_INFO(KaxDuration)),
	EbmlSemantic(false, true,  EBML_INFO(KaxDateUTC)),
	EbmlSemantic(false, true,  EBML_INFO(KaxTitle)),
	EbmlSemantic(true,  true,  EBML_INFO(KaxMuxingApp)),
	EbmlSemantic(true,  true,  EBML_INFO(KaxWritingApp)),
};

const EbmlSemanticContext KaxInfo_Context = EbmlSemanticContext(countof(KaxInfo_ContextList), KaxInfo_ContextList, &KaxSegment_Context, *GetKaxGlobal_Context, &EBML_INFO(KaxInfo));
const EbmlSemanticContext KaxMuxingApp_Context = EbmlSemanticContext(0, NULL, &KaxInfo_Context, *GetKaxGlobal_Context, &EBML_INFO(KaxMuxingApp));
const EbmlSemanticContext KaxWritingApp_Context = EbmlSemanticContext(0, NULL, &KaxInfo_Context, *GetKaxGlobal_Context, &EBML_INFO(KaxWritingApp));

EbmlId KaxInfo_TheId      (0x1549A966, 4);
EbmlId KaxMuxingApp_TheId (0x4D80, 2);
EbmlId KaxWritingApp_TheId(0x5741, 2);

const EbmlCallbacks KaxInfo::ClassInfos(KaxInfo::Create, KaxInfo_TheId, "Info", KaxInfo_Context);
const EbmlCallbacks KaxMuxingApp::ClassInfos(KaxMuxingApp::Create, KaxMuxingApp_TheId, "MuxingApp", KaxMuxingApp_Context);
const EbmlCallbacks KaxWritingApp::ClassInfos(KaxWritingApp::Create, KaxWritingApp_TheId, "WritingApp", KaxWritingApp_Context);

KaxInfo::KaxInfo()
	:EbmlMaster(KaxInfo_Context)
{}

END_LIBMATROSKA_NAMESPACE
