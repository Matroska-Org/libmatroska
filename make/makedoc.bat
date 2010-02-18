@echo off
rem you should have DOXYGEN.EXE in your path
rem http://www.doxygen.org/

echo make Documentation


doxygen Doxyfile > Doxygen.log.txt 2> Doxygen.err.txt