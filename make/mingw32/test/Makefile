# Project: test6
# Makefile created by Dev-C++ 4.9.7.0

CPP  = g++.exe
CC   = gcc.exe
WINDRES = windres.exe
RES  = 
OBJ  = ../../../test/mux/test6.o $(RES)
LIBS =  -L"D:/DEV-CPP/lib" "../libmatroska.a" "../../../../libebml/make/mingw32/libebml.a"
INCS =  -I"D:/DEV-CPP/include"  -I"D:/DEV-CPP/include/c++"  -I"D:/DEV-CPP/include"  -I"D:/Dev-Cpp/include/c++/mingw32"  -I"../../../../libebml/src"  -I"../../../src" 
BIN  = test6.exe
CXXFLAGS = $(INCS) 
CFLAGS = $(INCS) 

.PHONY: all all-before all-after clean clean-custom

all: all-before test6.exe all-after


clean: clean-custom
	rm -f $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(OBJ) -o "test6.exe" $(LIBS) $(CXXFLAGS)

../../../test/mux/test6.o: ../../../test/mux/test6.cpp
	$(CPP) -c ../../../test/mux/test6.cpp -o ../../../test/mux/test6.o $(CXXFLAGS)
