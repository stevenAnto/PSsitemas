#include <cstring>
#include "ejercicio2.h"
#include <iostream>
using namespace std;
void generarClientes(Cliente []);
void mostrarClientes(Cliente []);
int main(){
  Cliente clientes[3];
  generarClientes(clientes);
  mostrarClientes(clientes);
}

void generarClientes(Cliente clientes[3]){
  Estado estado=morosos;
  for(int i = 0;i<3; i++){
    strcpy(clientes[i].nombre,"Cliente"+char(i));
    //clientes[i].nombre= "Cliente" ;
    clientes[i].unidadesSolicitadas = i;
    clientes[i].precio = i*4;
  }
  clientes[0].estado = morosos;
  clientes[1].estado = atrasado;
  clientes[2].estado = pagado;
}
void mostrarClientes(Cliente clientes[3]){
  for(int i = 0;i<3; i++){
    cout<<clientes[i].nombre<<";"<<clientes[i].unidadesSolicitadas<<
      ";"<<clientes[i].precio<<";"<<clientes[i].estado<<"\n";

  }
  cout<<endl;
}
