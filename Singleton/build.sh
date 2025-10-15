#!/bin/sh
rm -rf lib build
mkdir lib build
cp -f ../gtestLib/googletest-1.17.0.zip ./lib
unzip ./lib/googletest-1.17.0.zip -d ./lib

cd build
ls -lrt
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_GCOV=1 ..
make