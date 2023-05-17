#!/bin/bash
if [ $# -lt 1 ]
then
  echo "Al menos un parametro"
else
  echo $*
fi

