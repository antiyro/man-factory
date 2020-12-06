#!/bin/bash

# myman
function myman() 
{
  if [ $1 = "--new" ] 
  then
    gcc ~/Documents/man_factory/*.c
    ./a.out
  else
    cat ~/Documents/man_factory/$1
  fi
}