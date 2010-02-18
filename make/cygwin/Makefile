# libmatroska core Makefile (used in cygwin)
# $Id: Makefile 640 2004-07-09 21:05:36Z mosu $

# Options
EXTENSION=.cpp
CXXFLAGS=-g -DDEBUG -Wall -Wno-unknown-pragmas -DWIN32 -DNO_NAMESPACE
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
PROGRAM=libmatroska.a

# source-files
sources:=$(wildcard ${SRC_DIR}*$(EXTENSION))

# header files; replace .cxx extension with .h
headers:=$(patsubst %$(EXTENSION),%.hpp,$(sources))

# files holding dependency information; replace .cxx extension with .dep
dependencies:=$(patsubst %$(EXTENSION),%.dep,$(sources))

# object files; replace .cxx extension with .o
objects:=$(patsubst %$(EXTENSION),%.o,$(sources))

DEPENDFLAGS  = ${CXXFLAGS} ${INCLUDE}

# Build rules
%.o: %$(EXTENSION)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ $<

$(PROGRAM): $(objects)
	$(AR) $@ $(objects)
	$(RANLIB) $@
#	$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)
#	${LD} -o $@ ${LDFLAGS} ${OBJS} ${LIBS} ${EXTRA_LIBS}

clean:
	rm -f ${SRC_DIR}$(objects)
	rm -f ${SRC_DIR}$(dependencies)
	rm -f ${SRC_DIR}$(PROGRAM)
	rm -f CORE

# what are the source dependencies
depend: $(sources)
	$(DEPEND) $(DEPENDFLAGS) $(sources)

# DO NOT DELETE
