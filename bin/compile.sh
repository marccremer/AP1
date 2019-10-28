#!/bin/sh
for file in ../src/*.c
do
	cc -o "$(basename "$file" .c)" "$file"  
  done
