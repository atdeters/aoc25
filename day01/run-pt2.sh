#!/usr/bin/env bash

g++ -D PART=2 src/day01.cpp -std=c++98 -o day01pt2
./day01pt2 input/input.txt
rm day01pt2
