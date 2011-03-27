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
		Test the EBML write possibilities
		\see http://www.cl.cam.ac.uk/~mgk25/unicode.html
		\see http://www-106.ibm.com/developerworks/unicode/library/u-encode.html
*/

#include <stdio.h>

#include "ebml/StdIOCallback.h"

#include "ebml/EbmlUInteger.h"
#include "ebml/EbmlSInteger.h"
#include "ebml/EbmlBinary.h"
#include "ebml/EbmlString.h"
#include "ebml/EbmlUnicodeString.h"
#include "ebml/EbmlMaster.h"
#include "ebml/EbmlFloat.h"
#include "ebml/EbmlStream.h"
#include "ebml/StdIOCallback.h"

using namespace LIBEBML_NAMESPACE;

const char RW_FILENAME[] = "test.kax";

enum SemanticType {
	EBML_U_INTEGER,
	EBML_S_INTEGER,
	EBML_BINARY,
	EBML_STRING,
	EBML_STRING_UNICODE,
	EBML_FLOAT,
	EBML_MASTER,
};

typedef binary EBMLID[4];
struct Semantic {
	EBMLID Id;
	int IdLength;
	SemanticType Type;
};

struct Semantic SemanticList[] = 
{
	{{0x42, 0x45},             2, EBML_U_INTEGER},
	{{0x1A, 0x45, 0x33, 0x80}, 4, EBML_S_INTEGER},
	{{0x87},                   1, EBML_BINARY},
	{{0x22, 0x33, 0x44},       3, EBML_STRING},
	{{0x44, 0x33},             2, EBML_STRING_UNICODE},
	{{0x50, 0x50},             2, EBML_FLOAT},
	{{0x36, 0x47, 0x58},       3, EBML_MASTER},
};

/*!
    \test Some test on the Cluster use
    \todo render the Cluster to a file
*/
int main(void)
{
	StdIOCallback Ebml_file(RW_FILENAME, ::MODE_CREATE);
	
	///// Writing test

	///////////////////////////////
	//   Unsigned integer
	///////////////////////////////
	
	EbmlUInteger testUInt(4); // supposed to hold a 4*8 bits value
	
	testUInt.SetID(SemanticList[0].Id, SemanticList[0].IdLength);
	testUInt = 52;
	testUInt.SetSizeLength(3); // size should be coded on at least 3 octets
	testUInt.Render(Ebml_file);

	///////////////////////////////
	//   Signed integer
	///////////////////////////////
	
	EbmlSInteger testSInt(4); // supposed to hold a 4*8 bits value

	testSInt.SetID(SemanticList[1].Id, SemanticList[1].IdLength);
	testSInt = -20;
	testSInt.Render(Ebml_file);

	///////////////////////////////
	//   Binary data
	///////////////////////////////
	const int BINARY_SIZE=3000;
	
	binary *bin = new binary[BINARY_SIZE];
	memset(bin, 0x61, BINARY_SIZE);
	EbmlBinary testBin;

	testBin.SetID(SemanticList[2].Id, SemanticList[2].IdLength);
	testBin.SetBuffer(bin, BINARY_SIZE);
	testBin.Render(Ebml_file);

	///////////////////////////////
	//   String data
	///////////////////////////////
	std::string aString = "Hello World !";
	EbmlString testStr(200);

	testStr.SetID(SemanticList[3].Id, SemanticList[3].IdLength);
	testStr = aString;
	testStr.Render(Ebml_file);

	///////////////////////////////
	//   Master element
	///////////////////////////////
	EbmlMaster testMaster;

	testMaster.SetID(SemanticList[6].Id, SemanticList[6].IdLength);
	testMaster.PushElement(testStr);
	testMaster.PushElement(testUInt);
	testMaster.Render(Ebml_file);

	///////////////////////////////
	//   Unicode String data
	///////////////////////////////
	UTFstring bString = L"Stève Lhomm€";
	EbmlUnicodeString testUStr(200);

	testUStr.SetID(SemanticList[4].Id, SemanticList[4].IdLength);
	testUStr = bString;
	testUStr.Render(Ebml_file);

	///////////////////////////////
	//   Float data
	///////////////////////////////
	EbmlFloat testFloat(EbmlFloat::FLOAT_32);

	testFloat.SetID(SemanticList[5].Id, SemanticList[5].IdLength);
	testFloat.SetPrecision(EbmlFloat::FLOAT_32);
	testFloat = 1.01234567890123456;
	testFloat.Render(Ebml_file);
	
	testFloat.SetPrecision(EbmlFloat::FLOAT_64);
	testFloat = -1.01234567890123456L;
	testFloat.Render(Ebml_file);
	
	Ebml_file.close();

	///// Reading test
	StdIOCallback Ebml_Wfile(RW_FILENAME, ::MODE_READ);
	
	// example 1 skip all the elements found
	EbmlStream aStream(Ebml_Wfile);
	EbmlElement * ElementLevel0;
	
	// read the data until a possible element is found (valid ID + size combination)
	ElementLevel0 = aStream.FindNextID(0xFFFFFFFFL, false);
	printf("Read EBML elements & skip data\n");
	while (ElementLevel0 != NULL)
	{
		printf("ID : ");
		for (int i=0; i<ElementLevel0->GetIDLength(); i++)
		{
			printf("[%02X]", ElementLevel0->GetID()[i]);
		}
		printf("\n");

		ElementLevel0->SkipData(Ebml_Wfile);
		if (ElementLevel0 != NULL)
			delete ElementLevel0;
	
		ElementLevel0 = aStream.FindNextID(0xFFFFFFFFL, false);
	}
	
	// example 2 evaluation of all elements found
	EbmlStream bStream(Ebml_Wfile);
	EbmlElement * EvaledElementLevel0;
//	EbmlElement * EvaledElementLevel1;
	
	// reset the stream to the beggining
	Ebml_Wfile.setFilePointer(0);
	
	// list of all IDs and their semantic type
//	std::list<struct Semantic> SemanticList;
//	SemanticList.push_back();
	
	ElementLevel0 = aStream.FindNextID(0xFFFFFFFFL, false);
	printf("Read EBML elements & evaluate data\n");
	while (ElementLevel0 != NULL)
	{
		int i;
		printf("ID : ");
		for (i=0; i<ElementLevel0->GetIDLength(); i++)
		{
			printf("[%02X]", ElementLevel0->GetID()[i]);
		}

		// check if the element is known
		for (i=0; i<countof(SemanticList); i++) {
			if (ElementLevel0->GetIDLength() != SemanticList[i].IdLength)
				continue;
			if (memcmp(SemanticList[i].Id, ElementLevel0->GetID(), SemanticList[i].IdLength) == 0)
				break;
		}
		/// \todo check if it is known in the context
		// handle the data inside the element
		if (i < countof(SemanticList)) {
			switch (SemanticList[i].Type)
			{
				case EBML_U_INTEGER:
					EvaledElementLevel0 = new EbmlUInteger(*ElementLevel0);
					break;
				case EBML_S_INTEGER:
					EvaledElementLevel0 = new EbmlSInteger(*ElementLevel0);
					break;
				case EBML_BINARY:
					EvaledElementLevel0 = new EbmlBinary(*ElementLevel0);
					break;
				case EBML_STRING:
					EvaledElementLevel0 = new EbmlString(*ElementLevel0);
					break;
				case EBML_STRING_UNICODE:
					EvaledElementLevel0 = new EbmlUnicodeString(*ElementLevel0);
					break;
				case EBML_FLOAT:
					EvaledElementLevel0 = new EbmlFloat(*ElementLevel0);
					break;
				case EBML_MASTER:
					EvaledElementLevel0 = new EbmlMaster(*ElementLevel0);
					break;
			}

			EvaledElementLevel0->ReadData(Ebml_Wfile);

			switch (SemanticList[i].Type)
			{
				case EBML_U_INTEGER:
					printf(" : %d", uint32(*(EbmlUInteger*)EvaledElementLevel0));
					break;
				case EBML_S_INTEGER:
					printf(" : %d", int32(*(EbmlSInteger*)EvaledElementLevel0));
					break;
				case EBML_BINARY:
					printf(" : binary data, size = %ld", (*(EbmlBinary*)EvaledElementLevel0).GetSize());
					printf(" [%02X]", binary(*(EbmlBinary*)EvaledElementLevel0));
					break;
				case EBML_STRING:
					printf(" : %s", std::string(*(EbmlString*)EvaledElementLevel0).data());
					break;
				case EBML_STRING_UNICODE:
					printf(" : (wide chars) %ls", UTFstring(*(EbmlUnicodeString*)EvaledElementLevel0).data());
					break;
				case EBML_FLOAT:
					printf(" : %f / %.15lf", float(*(EbmlFloat*)EvaledElementLevel0), double(*(EbmlFloat*)EvaledElementLevel0));
					break;
				case EBML_MASTER:
					printf(" : unsupported format 'Master'");
					break;
			}
			delete EvaledElementLevel0;
		} else {
			ElementLevel0->SkipData(Ebml_Wfile);
		}
		if (ElementLevel0 != NULL)
			delete ElementLevel0;

		printf("\n");
	
		ElementLevel0 = aStream.FindNextID(0xFFFFFFFFL, false);
	}
	
	Ebml_Wfile.close();

	return 0;
}
