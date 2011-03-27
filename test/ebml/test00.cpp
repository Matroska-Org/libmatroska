/****************************************************************************
** libmatroska : parse Matroska files, see http://www.matroska.org/
**
** <file/class description>
**
** Copyright (C) 2002-2004 Steve Lhomme.  All rights reserved.
**
** This file is part of libmatroska.
**
** This file may be distributed under the terms of the Q Public License
** as defined by Trolltech AS of Norway and appearing in the file
** LICENSE.QPL included in the packaging of this file.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** Licensees holding an other license may use this file in accordance with 
** the Agreement provided with the Software.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.matroska.org/license/qpl/ for QPL licensing information.
** See http://www.matroska.org/license/gpl/ for GPL licensing information.
**
** Contact license@matroska.org if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

/*!
    \file
    \version \$Id$
    \author Steve Lhomme     <robux4 @ users.sf.net>
		Test the writing a basic EBML file
*/

#include <stdio.h>
#include <string>

#include "ebml/StdIOCallback.h"

#include "ebml/EbmlHead.h"
#include "ebml/EbmlSubHead.h"
#include "ebml/EbmlStream.h"
#include "ebml/EbmlVoid.h"
#include "ebml/EbmlContexts.h"
#include "matroska/KaxSegment.h"
#include "matroska/KaxContexts.h"
#include "matroska/KaxSemantic.h"

#include "ebml/EbmlVersion.h"
#include "matroska/KaxVersion.h"

using namespace LIBMATROSKA_NAMESPACE;

const char RW_FILENAME[] = "test.kax";

#undef SKIP_ATTACHED

/*!
    \test Some test on the Cluster use
		\todo each Master element should have a context !
		\todo move the base EBML classes to a template of each type ? (defining the default value and the ID)
		\todo find another way than using all those static_cast (using a template ?)
*/
int main(void)
{
	printf("Test00 :\nEBML %s %s / Matroska %s %s\n", EbmlCodeVersion.c_str(), EbmlCodeDate.c_str(), KaxCodeVersion.c_str(), KaxCodeDate.c_str());
	StdIOCallback Ebml_file(RW_FILENAME, ::MODE_CREATE);
	
	///// Writing test
	EbmlHead TestHead;

	printf("Write EBML + Matroska elements\n");
	EDocType & MyDocType = GetChild<EDocType>(TestHead);
	*static_cast<EbmlString *>(&MyDocType) = "matroska";

	EDocTypeVersion & MyDocTypeVer = GetChild<EDocTypeVersion>(TestHead);
	*(static_cast<EbmlUInteger *>(&MyDocTypeVer)) = 1;

	EDocTypeReadVersion & MyDocTypeReadVer = GetChild<EDocTypeReadVersion>(TestHead);
	*(static_cast<EbmlUInteger *>(&MyDocTypeReadVer)) = 1;

	TestHead.Render(Ebml_file);

	KaxSegment FirstSegment;
	// size is unknown and will always be, we can render it right away
	FirstSegment.Render(Ebml_file);

	KaxAttachments * pAllAttachments = static_cast<KaxAttachments *>(FirstSegment.FindFirstElt(KaxAttachments::ClassInfos, true));
	if (pAllAttachments == NULL)
		return -1;
	pAllAttachments->SetSizeInfinite();
	// size is unknown and will always be, we can render it right away
	pAllAttachments->Render(Ebml_file);
	
	KaxAttached * pAttachment1 = static_cast<KaxAttached *>(pAllAttachments->FindFirstElt(KaxAttached::ClassInfos, true));
	if (pAttachment1 == NULL)
		return -1;
	KaxFileName * pFileName1 = static_cast<KaxFileName *>(pAttachment1->FindFirstElt(KaxFileName::ClassInfos, true));
	if (pFileName1 == NULL)
		return -1;
	*static_cast<EbmlUnicodeString *>(pFileName1) = "file1.txt";
	KaxFileData * pFileData1 = static_cast<KaxFileData *>(pAttachment1->FindFirstElt(KaxFileData::ClassInfos, true));
	if (pFileData1 == NULL)
		return -1;
	char Buffer1[] = "Ah ah ah !";
	static_cast<EbmlBinary *>(pFileData1)->SetBuffer((const binary*) Buffer1, countof(Buffer1));
	// should produce an error if the size is not infinite and the data has been rendered
	pAttachment1->Render(Ebml_file);
	
	KaxAttached * pAttachment2 = static_cast<KaxAttached *>(pAllAttachments->AddNewElt(KaxAttached::ClassInfos));
	if (pAttachment2 == NULL)
		return -1;
	KaxFileName * pFileName2 = static_cast<KaxFileName *>(pAttachment2->FindFirstElt(KaxFileName::ClassInfos, true));
	if (pFileName2 == NULL)
		return -1;
	*static_cast<EbmlUnicodeString *>(pFileName2) = "file2.txt";
	// Add a void element (data is discarded)
	EbmlVoid * pVoid = static_cast<EbmlVoid *>(pAttachment2->FindFirstElt(EbmlVoid::ClassInfos, true));
	if (pVoid == NULL)
		return -1;
	static_cast<EbmlBinary *>(pVoid)->SetBuffer((const binary*) Buffer1, countof(Buffer1));
	pAttachment2->Render(Ebml_file);

#ifdef SKIP_ATTACHED
	KaxSegment SecondSegment;
	// size is unknown and will always be, we can render it right away
	SecondSegment.Render(Ebml_file);
#endif // SKIP_ATTACHED

	Ebml_file.close();

	///// Reading test
	StdIOCallback Ebml_Wfile(RW_FILENAME, ::MODE_READ);
	
	// example 1 skip all the elements found
	EbmlStream aStream(Ebml_Wfile);
	EbmlElement * ElementLevel0;
	EbmlElement * ElementLevel1;
	EbmlElement * ElementLevel2;
	EbmlElement * ElementLevel3;
	
	// read the data until a possible element is found (valid ID + size combination)
	printf("Read EBML elements & skip data\n");
	// find the EBML head in the file
	ElementLevel0 = aStream.FindNextID(EbmlHead::ClassInfos, 0xFFFFFFFFL, false);
	if (ElementLevel0 != NULL)
	{
		printf("ID : ");
		for (unsigned int i=0; i<EbmlId(*ElementLevel0).Length; i++)
		{
			printf("[%02X]", EbmlId(*ElementLevel0).Value[i]);
		}
		printf("\n");

		ElementLevel0->SkipData(aStream, EbmlHead_Context);
		if (ElementLevel0 != NULL)
			delete ElementLevel0;
	}

	// example to read attachements in the file
	ElementLevel0 = aStream.FindNextID(KaxSegment::ClassInfos, 0xFFFFFFFFL, false);
	while (ElementLevel0 != NULL)
	{
		printf("ID : ");
		for (unsigned int i=0; i<EbmlId(*ElementLevel0).Length; i++)
		{
			printf("[%02X]", EbmlId(*ElementLevel0).Value[i]);
		}
		printf("\n");

		int bUpperElement = 0;

		ElementLevel1 = aStream.FindNextID(KaxSegment_Context, bUpperElement, 0xFFFFFFFFL, true);

		while (ElementLevel1 != NULL) {
			/// \todo switch the type of the element to check if it's one we want to handle, like attachements
			if (EbmlId(*ElementLevel1) == KaxAttachments::ClassInfos.GlobalId) {
				printf("Attachments detected\n");

				ElementLevel2 = aStream.FindNextID(KaxAttachments_Context, bUpperElement, 0xFFFFFFFFL, true);
				while (ElementLevel2 != NULL) {
					/// \todo switch the type of the element to check if it's one we want to handle, like attachements
					if (EbmlId(*ElementLevel2) == KaxAttached::ClassInfos.GlobalId) {
						printf("Attached file detected\n");
					}
#ifdef SKIP_ATTACHED
					ElementLevel2 = ElementLevel2->SkipData(aStream, KaxAttached_Context);
					if (ElementLevel2 == NULL) {
						ElementLevel2 = aStream.FindNextID(KaxAttachments_Context, bUpperElement, 0xFFFFFFFFL, true);

						if (bUpperElement) {
							printf("Upper level1 element found\n");
							delete ElementLevel1;
							ElementLevel1 = ElementLevel2;
							ElementLevel2 = NULL;
						}
					}
#else // SKIP_ATTACHED
					// Display the filename (if it exists)
					ElementLevel3 = aStream.FindNextID(KaxAttached_Context, bUpperElement, 0xFFFFFFFFL, false);
					while (ElementLevel3 != NULL) {
						/// \todo switch the type of the element to check if it's one we want to handle, like attachements
						if (EbmlId(*ElementLevel3) == KaxFileName::ClassInfos.GlobalId) {
							KaxFileName & tmp = *static_cast<KaxFileName*>(ElementLevel3);
							tmp.ReadData(aStream.I_O());
							printf("File Name = %ls\n", UTFstring(tmp).c_str());
						} else {
							ElementLevel3->SkipData(aStream, KaxAttached_Context);
						}
						delete ElementLevel3;
						ElementLevel3 = aStream.FindNextID(KaxAttached_Context, bUpperElement, 0xFFFFFFFFL, false);
						if (bUpperElement)
							break;
					}

					if (bUpperElement) {
						delete ElementLevel2;
						ElementLevel2 = ElementLevel3;
					} else {
						ElementLevel2->SkipData(aStream, KaxAttached_Context);
						delete ElementLevel2;

						ElementLevel2 = aStream.FindNextID(KaxAttachments_Context, bUpperElement, 0xFFFFFFFFL, true);
					}
#endif // SKIP_ATTACHED
				}
			}
			ElementLevel1->SkipData(aStream, KaxAttachments_Context);
			delete ElementLevel1;
	
			ElementLevel1 = aStream.FindNextID(KaxSegment_Context, bUpperElement, 0xFFFFFFFFL, true);
		}

		ElementLevel0->SkipData(aStream, KaxSegment_Context);
		if (ElementLevel0 != NULL)
			delete ElementLevel0;
	
		ElementLevel0 = aStream.FindNextID(KaxSegment_Context, bUpperElement, 0xFFFFFFFFL, true);
	}

	Ebml_Wfile.close();

	return 0;
}
