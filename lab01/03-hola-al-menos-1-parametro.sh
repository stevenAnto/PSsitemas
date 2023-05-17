#!/bin/bash
string=""
for param in $@
do
  string+="$param, "
done
echo ${string:0:-2}
