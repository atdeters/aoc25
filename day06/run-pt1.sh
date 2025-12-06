#!/usr/bin/env bash

cd src
c++ --std=c++98 -Wall -Wextra -O3 mainpt1.cpp -o day06
./day06 ../input/input.txt
rm day06
