#!/bin/sh

rm -rf build
mkdir build
cd build
cmake ..
make
perf stats ./test_app
echo "These are the stats. Running profile in 5 seconds"

perf record -g ./test_app
perf report -g "graph,0.5,caller"
