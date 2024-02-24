// Copyright © 2002-2004 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
    \file
    \author Steve Lhomme     <robux4 @ users.sf.net>
    Test the writing a basic EBML file
*/

#include "matroska/KaxSegment.h"
#include "matroska/KaxContexts.h"
#include "matroska/KaxSemantic.h"
#include "matroska/KaxVersion.h"

#include <ebml/StdIOCallback.h>
#include <ebml/EbmlHead.h>
#include <ebml/EbmlStream.h>
#include <ebml/EbmlVoid.h>
#include <ebml/EbmlContexts.h>
#include <ebml/EbmlVersion.h>

#include <cstdio>
#include <string>

using namespace libebml;
using namespace libmatroska;

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
  MyDocType.SetValue("matroska");

  EDocTypeVersion & MyDocTypeVer = GetChild<EDocTypeVersion>(TestHead);
  MyDocTypeVer.SetValue(1);

  EDocTypeReadVersion & MyDocTypeReadVer = GetChild<EDocTypeReadVersion>(TestHead);
  MyDocTypeReadVer.SetValue(1);

  TestHead.Render(Ebml_file);

  KaxSegment FirstSegment;
  // size is unknown and will always be, we can render it right away
  FirstSegment.Render(Ebml_file);

  KaxAttachments * pAllAttachments = static_cast<KaxAttachments *>(FirstSegment.FindFirstElt(EBML_INFO(KaxAttachments), true));
  if (pAllAttachments == NULL)
    return -1;
  pAllAttachments->SetSizeInfinite();
  // size is unknown and will always be, we can render it right away
  pAllAttachments->Render(Ebml_file);

  KaxAttached * pAttachment1 = static_cast<KaxAttached *>(pAllAttachments->FindFirstElt(EBML_INFO(KaxAttached), true));
  if (pAttachment1 == NULL)
    return -1;
  KaxFileName * pFileName1 = static_cast<KaxFileName *>(pAttachment1->FindFirstElt(EBML_INFO(KaxFileName), true));
  if (pFileName1 == NULL)
    return -1;
  pFileName1->SetValue(UTFstring{L"file1.txt"});
  KaxFileData * pFileData1 = static_cast<KaxFileData *>(pAttachment1->FindFirstElt(EBML_INFO(KaxFileData), true));
  if (pFileData1 == NULL)
    return -1;
  char Buffer1[] = "Ah ah ah !";
  static_cast<EbmlBinary *>(pFileData1)->SetBuffer((const binary*) Buffer1, countof(Buffer1));
  // should produce an error if the size is not infinite and the data has been rendered
  pAttachment1->Render(Ebml_file);

  KaxAttached * pAttachment2 = static_cast<KaxAttached *>(pAllAttachments->AddNewElt(EBML_INFO(KaxAttached)));
  if (pAttachment2 == NULL)
    return -1;
  KaxFileName * pFileName2 = static_cast<KaxFileName *>(pAttachment2->FindFirstElt(EBML_INFO(KaxFileName), true));
  if (pFileName2 == NULL)
    return -1;
  pFileName2->SetValue(UTFstring{L"file2.txt"});
  // Add a void element (data is discarded)
  EbmlVoid * pVoid = static_cast<EbmlVoid *>(pAttachment2->FindFirstElt(EBML_INFO(EbmlVoid), true));
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
  ElementLevel0 = aStream.FindNextID(EBML_INFO(EbmlHead), 0xFFFFFFFFL);
  if (ElementLevel0 != NULL)
  {
    printf("ID : ");
    for (unsigned int i=EbmlId(*ElementLevel0).GetLength(); i; i++)
    {
      printf("[%02X]", (EbmlId(*ElementLevel0).GetValue() >> ((i-1)*8)) & 0xFF);
    }
    printf("\n");

    ElementLevel0->SkipData(aStream, EBML_CLASS_CONTEXT(EbmlHead));
    if (ElementLevel0 != NULL)
      delete ElementLevel0;
  }

  // example to read attachements in the file
  ElementLevel0 = aStream.FindNextID(EBML_INFO(KaxSegment), 0xFFFFFFFFL);
  while (ElementLevel0 != NULL)
  {
    printf("ID : ");
    for (unsigned int i=EbmlId(*ElementLevel0).GetLength(); i; i++)
    {
      printf("[%02X]", (EbmlId(*ElementLevel0).GetValue() >> ((i-1)*8)) & 0xFF);
    }
    printf("\n");

    int bUpperElement = 0;

    ElementLevel1 = aStream.FindNextElement(EBML_CLASS_CONTEXT(KaxSegment), bUpperElement, 0xFFFFFFFFL, true);

    while (ElementLevel1 != NULL) {
      /// \todo switch the type of the element to check if it's one we want to handle, like attachements
      if (EbmlId(*ElementLevel1) == EBML_ID(KaxAttachments)) {
        printf("Attachments detected\n");

        ElementLevel2 = aStream.FindNextElement(EBML_CLASS_CONTEXT(KaxAttachments), bUpperElement, 0xFFFFFFFFL, true);
        while (ElementLevel2 != NULL) {
          /// \todo switch the type of the element to check if it's one we want to handle, like attachements
          if (EbmlId(*ElementLevel2) == EBML_ID(KaxAttached)) {
            printf("Attached file detected\n");
          }
#ifdef SKIP_ATTACHED
          ElementLevel2 = ElementLevel2->SkipData(aStream, EBML_CLASS_CONTEXT(KaxAttached));
          if (ElementLevel2 == NULL) {
            ElementLevel2 = aStream.FindNextID(EBML_CLASS_CONTEXT(KaxAttachments), bUpperElement, 0xFFFFFFFFL, true);

            if (bUpperElement) {
              printf("Upper level1 element found\n");
              delete ElementLevel1;
              ElementLevel1 = ElementLevel2;
              ElementLevel2 = NULL;
            }
          }
#else // SKIP_ATTACHED
          // Display the filename (if it exists)
          ElementLevel3 = aStream.FindNextElement(EBML_CLASS_CONTEXT(KaxAttached), bUpperElement, 0xFFFFFFFFL, false);
          while (ElementLevel3 != NULL) {
            /// \todo switch the type of the element to check if it's one we want to handle, like attachements
            if (EbmlId(*ElementLevel3) == EBML_ID(KaxFileName)) {
              KaxFileName & tmp = *static_cast<KaxFileName*>(ElementLevel3);
              tmp.ReadData(aStream.I_O());
              printf("File Name = %s\n", UTFstring(tmp).GetUTF8().c_str());
            } else {
              ElementLevel3->SkipData(aStream, EBML_CLASS_CONTEXT(KaxAttached));
            }
            delete ElementLevel3;
            ElementLevel3 = aStream.FindNextElement(EBML_CLASS_CONTEXT(KaxAttached), bUpperElement, 0xFFFFFFFFL, false);
            if (bUpperElement)
              break;
          }

          if (bUpperElement) {
            delete ElementLevel2;
            ElementLevel2 = ElementLevel3;
          } else {
            ElementLevel2->SkipData(aStream, EBML_CLASS_CONTEXT(KaxAttached));
            delete ElementLevel2;

            ElementLevel2 = aStream.FindNextElement(EBML_CLASS_CONTEXT(KaxAttachments), bUpperElement, 0xFFFFFFFFL, true);
          }
#endif // SKIP_ATTACHED
        }
      }
      ElementLevel1->SkipData(aStream, EBML_CLASS_CONTEXT(KaxAttachments));
      delete ElementLevel1;

      ElementLevel1 = aStream.FindNextElement(EBML_CLASS_CONTEXT(KaxSegment), bUpperElement, 0xFFFFFFFFL, true);
    }

    ElementLevel0->SkipData(aStream, EBML_CLASS_CONTEXT(KaxSegment));
    if (ElementLevel0 != NULL)
      delete ElementLevel0;

    ElementLevel0 = aStream.FindNextElement(EBML_CLASS_CONTEXT(KaxSegment), bUpperElement, 0xFFFFFFFFL, true);
  }

  Ebml_Wfile.close();

  return 0;
}
