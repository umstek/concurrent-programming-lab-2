#!/usr/bin/env bash

if [ -d "./build" ]; then
    rm -rf ./build
fi

mkdir build
cd build
cmake ..
make

./LinkedList

cat /proc/cpuinfo > systeminfo.txt
cat /proc/meminfo >> systeminfo.txt
