# Project: libmatroska
# Makefile to use the Free Visual C++ 2003 compiler from Microsoft with GNU Make

# Compile with debug information?
#DEBUG = yes

# Where libebml resides
EBML_DIR = ../../../libebml

#
# Don't change anything below this line.
#
CXX  = cl /Tp
CC   = cl /Tc
SRC  = $(wildcard ../../src/*.cpp)
OBJ  = $(patsubst %.cpp,%.obj,$(SRC))
INCS = /I../.. /I$(EBML_DIR)
LDFLAGS = /NOLOGO /DLL /MAP:libmatroska.map /LIBPATH:$(EBML_DIR)/make/vc7 /VERSION:0.7
OPTMIZ = /G6 /O2 /Oi /GL /Wp64
CXXFLAGS = $(INCS) /DWIN32 /nologo /DEBML_DLL 


ifeq (yes,$(DEBUG))
CXXFLAGS += /Zi /DDEBUG /D_DEBUG /MTd /RTC1
LDFLAGS += /DEBUG
else
CXXFLAGS += /MT
LDFLAGS += /OPT:REF
endif

LIBS = libmatroska.dll

.PHONY: all all-before all-after clean clean-custom

%.obj : %.cpp
	$(CXX) $< /c $(CXXFLAGS) /Fo$@

all: lib

lib: $(LIBS)

clean:
	$(RM) $(OBJ) libmatroska.lib libmatroska.dll

libmatroska.lib: $(OBJ)
	lib /OUT:$@ /NODEFAULTLIB $(OBJ)

libmatroska.dll: $(OBJ)
	link $(LDFLAGS) /OUT:$@ $(OBJ) libebml.lib
#	user32.lib

depend:
	$(CXX) $(CXXFLAGS) -MM $(SRC) > .depend

#
# include dependency files if they exist
#
ifneq ($(wildcard .depend),)
include .depend
endif
