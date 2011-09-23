# Microsoft Developer Studio Project File - Name="libmatroska" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=libmatroska - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "libmatroska.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "libmatroska.mak" CFG="libmatroska - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "libmatroska - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "libmatroska - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "libmatroska - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "../../../../../libebml" /I "../../../.." /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x40c /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "libmatroska - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GR /GX /ZI /Od /I "../../../../../libebml" /I "../../../.." /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD BASE RSC /l 0x40c /d "_DEBUG"
# ADD RSC /l 0x809 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "libmatroska - Win32 Release"
# Name "libmatroska - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\..\..\src\FileKax.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\KaxAttached.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\KaxAttachments.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\KaxBlock.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\KaxBlockData.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\KaxChapters.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\KaxCluster.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\KaxClusterData.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\KaxContentEncoding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\KaxContexts.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\KaxCues.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\KaxCuesData.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\KaxInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\KaxInfoData.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\KaxSeekHead.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\KaxSegment.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\KaxTag.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\KaxTags.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\KaxTrackAudio.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\KaxTrackEntryData.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\KaxTracks.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\KaxTrackVideo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\KaxVersion.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\..\..\matroska\FileKax.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxAttached.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxAttachments.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxBlock.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxBlockData.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxChapters.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxCluster.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxClusterData.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxConfig.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxContentEncoding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxContexts.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxCues.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxCuesData.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxInfoData.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxSeekHead.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxSegment.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxTag.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxTags.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxTrackAudio.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxTrackEntryData.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxTracks.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxTrackVideo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxTypes.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\matroska\KaxVersion.h
# End Source File
# End Group
# End Target
# End Project
