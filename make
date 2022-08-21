#!/bin/bash

if [[ "$1" == "clean" ]]; then
  echo "clean"
  rm *.o game
else
  g++ main.cpp test.cpp -o game -lsfml-graphics -lsfml-window -lsfml-system
  ./game
fi
