#!/usr/bin/env bash

cd src
c++ --std=c++98 -g -Wall -Wextra -O3 mainpt2.cpp -o day06
./day06 ../input/input.txt
rm day06
