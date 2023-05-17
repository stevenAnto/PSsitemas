#!/bin/bash
#verificamos el numero de parametros
if [ $# -le 0 ] ; then
  echo "Hay que introducir por lo menso un parametro"
  exit 1 #error
fi


for i in $@
do
  echo $i
  #con grep busco al usuario ingresado como parametro
  #  en la lista producidad por who  y lo almaceno en usuarioConetado
  usuarioConetado=$(who|grep "$i")
  echo "$usuarioConetado"
  # si el length  de  usuarioConetado <=0, entonces no esta
  #conectado, caso contrario si esta conectado
  if [ ${#usuarioConetado} -le 0 ]; then 
    echo "El usuario $i no  esta conectado"
  else
    echo "El usuario $i esta conectado"
  fi
done

