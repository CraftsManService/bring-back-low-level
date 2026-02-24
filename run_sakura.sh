#!/bin/bash

rm -f sakura
echo "cleaning up"



echo "Compiling Sakura AI..."
g++ light-tutorial.cpp -o sakura

if [ $? -eq 0 ]; then 
    echo "Compiled Sakura AI!"
    sleep 1
    clear
    ./sakura
else
    echo "Failed to compile!"
fi