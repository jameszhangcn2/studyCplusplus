#!/bin/sh
#Build singleton
cd Singleton
echo "I am in folder Singleton."
pwd
./build.sh
#Gtest singleton
./build/tst/testSingleton_tst

#generate UT test report

#generate coverage
gcov -o ~/Singleton/build/src/CMakeFiles/testSingleton_lib.dir/ -s ~/Singleton/src/GameConfig.cpp 