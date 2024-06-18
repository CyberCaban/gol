#!/bin/sh

if [[ "$1" = "clean" || "$1" = "-c" ]]; then 
    rm -f *.o
    rm -f *.exe
    echo "Clean successful"
    exit
fi

CC=gcc
LIBS="-lraylib -lgdi32 -lwinmm"
OBJ="window.o elements.o"

$CC -c ./lib/elements.c
$CC -I ./lib -c window.c
$CC -L ./lib -o w.exe $OBJ $LIBS

echo "$CC $OBJ $LIBS"
echo "Build successful"

if [[ "$1" = "run" || "$1" = "-r" ]]; then 
    ./w.exe
fi