#!/usr/bin/sh
# you should have "doxygen" in your path
# http://www.doxygen.org/

echo make Documentation

doxygen Doxyfile > Doxygen.log.txt 2> Doxygen.err.txt
