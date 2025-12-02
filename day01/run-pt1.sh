#!/usr/bin/env bash

g++ -D PART=1 src/day01.cpp -std=c++98 -o day01pt1
./day01pt1 input/input.txt
rm day01pt1
