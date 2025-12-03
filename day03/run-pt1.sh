#!/usr/bin/env bash

cd src
cc main.c helpers.c -D DIGITS=2 -o day03
./day03 ../input/input.txt
rm day03
