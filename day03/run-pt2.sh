#!/usr/bin/env bash

cd src
cc main.c -D DIGITS=12 -o day03 --std=c99 -Wall -Werror -Wextra
./day03 ../input/input.txt
rm day03
