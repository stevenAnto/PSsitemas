#!/bin/bash

#verificamos el numero de parametros
if [ $# -le 0 ] ; then
  echo "Hay que introducir por lo menos un parametro"
  exit 1 #error
fi


contador=0
for i in $@
do
  echo $i
  usuarioConetado=$(who|grep "$i")
  echo "$usuarioConetado"
  if [ ${#usuarioConetado} -gt 0 ] && [ $contador -eq 0 ]; then 
    echo "SI"
    exit 0
  else
    echo "NO"
    exit 0
  fi
  #aumento el contador
  ((contador++))
done

