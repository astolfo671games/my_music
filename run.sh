#!/bin/bash

clear

chmod 700 bb.py
./bb.py $1

gcc -std=c2x temp.c -o t
./t $1 $2 $3 > $1.wav
rm temp.c t
