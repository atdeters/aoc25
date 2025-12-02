#!/usr/bin/env bash

g++ -D PART=1 src/day01.cpp -o day01pt1
./day01pt1 src/input.txt
rm day01pt1
