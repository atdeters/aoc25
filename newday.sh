#!/usr/bin/env bash

name=$1

if [[ $# -eq 2 ]]; then
	lang=$2
elif [[ $# -gt 2 ]]; then
	echo Illegal amount of input to the script
	exit 1
fi

echo $#

mkdir $name
cd $name
mkdir input
mkdir src
touch input.txt example.txt
touch run-pt1.sh run-pt2.sh
chmod +x run*
mv *.txt ./input
