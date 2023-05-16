#!/bin/bash
total=1
for var in "$*";do
  echo "\$*======>#$total=$var"
  total=$(($total+1))
done
#total =1
for var in "$@"; do
  echo "\$@======>#$total=$var"
  total=$(($total+1))
done
  
