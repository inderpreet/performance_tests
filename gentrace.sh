#!/bin/sh

rm -rf build
mkdir build
cd build
cmake ..
make
uftrace record ./test_app
uftrace dump --chrome threads.json
echo "run chrome to 'chrome://tracking' and load the file threads.json in this folder"
