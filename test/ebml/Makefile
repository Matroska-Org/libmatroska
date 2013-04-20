# libmatroska core Makefile (used in cygwin)
# $Id: Makefile 640 2004-07-09 21:05:36Z mosu $

# Options
EXTENSION=.cpp
CXXFLAGS=-g -DDEBUG -Wall -Wno-unknown-pragmas -DWIN32 -I../../src/
LDFLAGS=

SRC_DIR=../../src/

# Programs
CXX=g++ -c
LD=g++
DEP=$(CXX) -MM
DEPEND = makedepend
AR = ar rcvu
RANLIB = ranlib

# Librarires
INCLUDE=
LIBS=

# Names
PROGRAM=test00

# source-files
sources:=$(wildcard ${SRC_DIR}*$(EXTENSION))

# header files; replace .cxx extension with .h
headers:=$(patsubst %$(EXTENSION),%.hpp,$(sources))

# files holding dependency information; replace .cxx extension with .dep
dependencies:=$(patsubst %$(EXTENSION),%.dep,$(sources))

# object files; replace .cxx extension with .o
objects:=$(patsubst %$(EXTENSION),%.o,$(sources))

OBJ=$(objects) test00.o

DEPENDFLAGS  = ${CXXFLAGS} ${INCLUDE}

# Build rules
%.o: %$(EXTENSION)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ $<

$(PROGRAM): $(OBJ)
#	$(AR) $@ $(objects)
#	$(RANLIB) $@
	$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)
	${LD} -o $@ ${LDFLAGS} ${OBJ} ${LIBS} ${EXTRA_LIBS}

clean:
	rm -f $(OBJ)
	rm -f $(dependencies)
	rm -f $(PROGRAM)
	rm -f CORE

# what are the source dependencies
depend: $(sources)
	$(DEPEND) $(DEPENDFLAGS) $(sources)

# DO NOT DELETE
