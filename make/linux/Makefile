# libmatroska core Makefile (used in cygwin)
# $Id: Makefile 1254 2006-06-02 14:32:52Z mosu $
# Author: Steve Lhomme <robux4 @ users.sf.net>
# Author: Moritz Bunkus <moritz @ bunkus.org>

#
# The library is built without debug information. If you want
# debug information to be included then compile with
# 'make DEBUG=yes'.
#

# Paths
# BeOS wants the libs and headers in /boot/home/config
ifeq (BeOS,$(shell uname -s))
prefix=/boot/home/config
else
prefix=/usr/local
endif
libdir=$(prefix)/lib
includedir=$(prefix)/include/matroska

# Programs
CROSS =
CXX = $(CROSS)g++
LD = $(CXX)
AR = $(CROSS)ar
RANLIB = $(CROSS)ranlib
INSTALL = install
INSTALL_OPTS = -m 644
INSTALL_OPTS_LIB = -m 644
INSTALL_DIR_OPTS = -m 755

CWD=$(shell pwd)

# Options
LIBEBML_INCLUDE_DIR=$(CWD)/../../../libebml
LIBEBML_LIB_DIR=$(CWD)/../../../libebml/make/linux
EXTENSION=.cpp

ifeq (yes,$(DEBUG))
DEBUGFLAGS=-g -DDEBUG
endif

SRC_DIR=$(CWD)/../../src/
INCLUDE_DIR=$(CWD)/../../matroska
MUX_SRC_DIR=$(CWD)/../../test/mux/
TAG_SRC_DIR=$(CWD)/../../test/tags/

# Librarires
INCLUDE=-I$(CWD)/../.. -I$(LIBEBML_INCLUDE_DIR)
LIBS=
MUX_LIBS=-lmatroska -lebml $(LIBICONV)

# Names
LIBRARY=libmatroska.a
LIBRARY_SO=libmatroska.so
LIBRARY_SO_VER=libmatroska.so.4

# source-files
sources:=$(wildcard ${SRC_DIR}*$(EXTENSION))

# header files; replace .cxx extension with .h
headers:=$(patsubst %$(EXTENSION),%.h,$(sources))

# object files; replace .cxx extension with .o
objects:=$(patsubst %$(EXTENSION),%.o,$(sources))

objects_so:=$(patsubst %$(EXTENSION),%.lo,$(sources))

WARNINGFLAGS=-Wall -Wno-unknown-pragmas -ansi -fno-gnu-keywords -D_GNU_SOURCE \
		-Wshadow
COMPILEFLAGS=$(DEBUGFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(WARNINGFLAGS) $(INCLUDE)
LINKFLAGS=-L. -L$(LIBEBML_LIB_DIR) $(LDFLAGS)
DEPENDFLAGS  = $(CXXFLAGS) $(INCLUDE)

ifeq (Darwin,$(shell uname -s))
all: staticlib
else
all: staticlib sharedlib
endif

staticlib: $(LIBRARY)

sharedlib: $(LIBRARY_SO)

lib:
	@echo "Use the 'staticlib', 'sharedlib' or 'all' targets."
	@false

# Build rules
%.o: %$(EXTENSION)
	$(CXX) -c $(COMPILEFLAGS) -o $@ $<

%.lo: %$(EXTENSION)
	$(CXX) -c $(COMPILEFLAGS) -fPIC -o $@ $<

$(LIBRARY): $(objects)
	$(AR) rcvu $@ $(objects)
	$(RANLIB) $@

$(LIBRARY_SO): $(objects_so)
	$(CXX) -shared -Wl,-soname,$(LIBRARY_SO_VER) -o $(LIBRARY_SO_VER) $(objects_so) -lebml
	rm -f $(LIBRARY_SO)
	ln -s $(LIBRARY_SO_VER) $(LIBRARY_SO)

clean:	cleantest
	rm -f $(objects) $(objects_so)
	rm -f $(LIBRARY)
	rm -f $(LIBRARY_SO)
	rm -f $(LIBRARY_SO_VER)
	rm -f CORE

cleantest:
	rm -f test6 test8 test9 test6.o test8.o test9.o

distclean dist-clean: clean
	rm -f .depend

depend:
	@echo Calculating dependecies:
	@rm -f .depend
	@touch .depend
	@for i in $(sources); do \
		o="`echo $$i | sed -e 's/\.c$$/.o/' -e 's/\.cpp$$/.o/'`" ; \
		echo '  ' $$i: $$o ; \
		$(CXX) $(DEPENDFLAGS) -MM -MT $$o $$i >> .depend ; \
	done

test: test6 test9

test6:	test6.o $(LIBRARY) $(LIBRARY_SO)
	$(LD) -o $@ $(LINKFLAGS) $< $(MUX_LIBS)

test6.o: $(MUX_SRC_DIR)test6.cpp
	$(CXX) -c $(COMPILEFLAGS) -o $@ $<

test8:	test8.o $(LIBRARY) $(LIBRARY_SO)
	$(LD) -o $@ $(LINKFLAGS) $< $(MUX_LIBS)

test8.o: $(MUX_SRC_DIR)test8.cpp
	$(CXX) -c $(COMPILEFLAGS) -o $@ $<

test9:	test9.o $(LIBRARY) $(LIBRARY_SO)
	$(LD) -o $@ $(LINKFLAGS) $< $(MUX_LIBS)

test9.o: $(TAG_SRC_DIR)test9.cpp
	$(CXX) -c $(COMPILEFLAGS) -o $@ $<

ifeq (Darwin,$(shell uname -s))
install: install_staticlib install_headers
else
install: install_staticlib install_sharedlib install_headers
endif

install_headers:
	$(INSTALL) $(INSTALL_DIR_OPTS) -d $(includedir)
	for i in $(INCLUDE_DIR)/*.h; do \
		$(INSTALL) $(INSTALL_OPTS) $$i $(includedir) ; \
	done
	$(INSTALL) $(INSTALL_DIR_OPTS) -d $(includedir)/c
	for i in $(INCLUDE_DIR)/c/*.h; do \
		$(INSTALL) $(INSTALL_OPTS) $$i $(includedir)/c ; \
	done

install_staticlib: $(LIBRARY)
	$(INSTALL) $(INSTALL_DIR_OPTS) -d $(libdir)
	$(INSTALL) $(INSTALL_OPTS_LIB) $(LIBRARY) $(libdir)

install_sharedlib: $(LIBRARY_SO)
	$(INSTALL) $(INSTALL_DIR_OPTS) -d $(libdir)
	$(INSTALL) $(INSTALL_OPTS_LIB) $(LIBRARY_SO_VER) $(libdir)
	ln -fs $(LIBRARY_SO_VER) $(libdir)/$(LIBRARY_SO)

ifneq ($(wildcard .depend),)
include .depend
endif

# DO NOT DELETE
