#!/bin/sh
#Build singleton
cd Singleton
echo "I am in folder Singleton."
pwd
./build.sh
#Gtest singleton
./build/tst/testSingleton_tst

#generate UT test report