# Project: libmatroska
# Makefile created by Dev-C++ 4.9.7.0

# Normally libmatroska is built as a static library.
# Uncomment this if you want a shared library instead.
# ATTENTION: Your app has to define MATROSKA_DLL !
SHARED = yes

# Compile with debug information?
#DEBUG = yes

# Where libebml resides
EBML_DIR = ../../../libebml

# Has libebml been compiled as a DLL?
EBML_DLL = yes

#
# Don't change anything below this line.
#
ifeq (yes,$(DEBUG))
DEBUGFLAGS=-g -DDEBUG
endif
CROSS   =
CXX     = $(CROSS)g++
CC      = $(CROSS)gcc
WINDRES = $(CROSS)windres
RANLIB  = $(CROSS)ranlib
AR      = $(CROSS)ar
RES  =
SRC  = $(wildcard ../../src/*.cpp)
OBJ  = $(patsubst %.cpp,%.o,$(SRC))
ifeq (yes,$(SHARED))
LIBS = libmatroska.dll
FLAGS = -DMATROSKA_DLL
DLLFLAGS = -DMATROSKA_DLL_EXPORT
else
LIBS = libmatroska.a
endif
ifeq (yes,$(SHARED))
ifeq (yes,$(EBML_DLL))
FLAGS += -DEBML_DLL
endif
endif
CWD = $(shell pwd)
INCS = -I"$(CWD)/../.." -I$(EBML_DIR)
LDFLAGS = -L. -L$(EBML_DIR)/make/mingw32
COMPILEFLAGS = $(DEBUGFLAGS) $(INCS) $(FLAGS) $(CXXFLAGS)
TESTS = test6 test8 test9

.PHONY: all all-before all-after clean clean-custom

.cpp.o:
	$(CXX) $(DLLFLAGS) $(COMPILEFLAGS) -c -o $@ $<

all: lib

lib: $(LIBS)

tests: $(TESTS)

clean:
	rm -f $(OBJ) libmatroska.a libmatroska.dll.a libmatroska.dll *.exe \
		../../test/mux/*.o ../../test/tags/*.o

distclean dist-clean: clean
	rm -f .depend

libmatroska.a: $(OBJ)
	$(AR) rcvu $@ $(OBJ)
	$(RANLIB) $@

libmatroska.dll: $(OBJ)
	$(CXX) -shared -Wl,--export-all -Wl,--out-implib=$@.a -o $@ $(OBJ) \
		$(LDFLAGS) -lebml

# Explicitely list these object files because for them
# MATROSKA_DLL_EXPORT must NOT be defined.
../../test/mux/test6.o: ../../test/mux/test6.cpp
	$(CXX) $(COMPILEFLAGS) -c -o $@ $<

test6:	../../test/mux/test6.o $(LIBS)
	$(LD) -o $@ $(LDFLAGS) $< -lmatroska -lebml

../../test/mux/test8.o: ../../test/mux/test8.cpp
	$(CXX) $(COMPILEFLAGS) -c -o $@ $<

test8:	../../test/mux/test8.o $(LIBS)
	$(LD) -o $@ $(LDFLAGS) $< -lmatroska -lebml

../../test/tags/test9.o: ../../test/tags/test9.cpp
	$(CXX) $(COMPILEFLAGS) -c -o $@ $<

test9:	../../test/tags/test9.o $(LIBS)
	$(LD) -o $@ $(LDFLAGS) $< -lmatroska -lebml

depend:
	@echo Calculating dependecies:
	@rm -f .depend
	@touch .depend
	@for i in $(SRC); do \
		o="`echo $$i | sed -e 's/\.c$$/.o/' -e 's/\.cpp$$/.o/'`" ; \
		echo '  ' $$i: $$o ; \
		$(CXX) $(COMPILEFLAGS) -MM -MT $$o $$i >> .depend ; \
	done

#
# include dependency files if they exist
#
ifneq ($(wildcard .depend),)
include .depend
endif
