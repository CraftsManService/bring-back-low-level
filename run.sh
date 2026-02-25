#!/bin/bash

rm -f sakura
echo "cleaning up"



echo "Compiling Sakura AI..."
g++ light-tutorial.cpp -o sakura

g++ src/light-tutorial.cpp src/glad.c -I./include -o sakura -lglfw -lGL -ldl -lpthread -lX11

if [ $? -eq 0 ]; then 
    echo "Compiled Sakura AI!"
    sleep 1
    clear
    xvfb-run ./sakura
else
    echo "Failed to compile!"
fi