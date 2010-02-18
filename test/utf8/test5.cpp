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
    \version \$Id: test5.cpp 1078 2005-03-03 13:13:04Z robux4 $
    \brief Test encoding and decoding UTF8 characters
    \author Steve Lhomme     <robux4 @ users.sf.net>
*/

#include <cstdio>

#include <string>
#include "TruncString.hpp"
#include "FileName.hpp"
#include "StdIOCallback.hpp"

using namespace LIBMATROSKA_NAMESPACE;
using namespace std;

/*!
	\see http://www.unicode.org/charts/
	\see http://www-106.ibm.com/developerworks/linux/library/l-linuni.html
	\see http://www.cl.cam.ac.uk/~mgk25/unicode.html#libs
	\see ftp://ftp.ilog.fr/pub/Users/haible/utf8/Unicode-HOWTO-6.html#ss6.1
*/
int main(void)
{
    string test1 = "lhomme";
    string test2 = "Stève"; // Supposed to be a UTF8 string
//    test2[2] = 0x0152; // oe mixed in one, upper case

//    const wchar_t *toto = test2.c_str();

    printf("%lc  = 0x%04X\n",test2[2],test2[2]);
//    wprintf(L"0x%04X\n",toto[2]);

    StdIOCallback Test_file("test.utf8",StdIOCallback::MODE_CREATE);
//    Test_file.write(toto, test2.size()*sizeof(wchar_t));
    Test_file.write(test2.c_str(), test2.size());

    TruncString8 testUTF8_1(10);
    testUTF8_1 = test1.c_str();

    TruncString8 testUTF8_2(10);
    testUTF8_2 = test2.c_str(); 
    // in UTF8 0xE8=1110-1000 should become 110.00110-10.001000=0xC6 0x88

    FileName test01(64);
    std::string str="..toto..txt  éhé";
    test01 = str;
    FileName::name_level bType = test01.Test();
    test01.MakeRelaxed();
    bType = test01.Test();
    test01.MakeSafe();
    bType = test01.Test();

    const char *tst = (char*)test01.buffer();

    return 0;
}
