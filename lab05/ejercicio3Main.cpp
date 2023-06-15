#include <cstring>
#include "ejercicio2.h"
#include <iostream>
#include <random>
#include <ctime>

using namespace std;
void generarClientes(Cliente []);
void mostrarClientes(Cliente []);
void mostrarMorosos(Cliente []);

int main(){

  srand(time(NULL));
  cout<<random;

  Cliente clientes[3];
  generarClientes(clientes);
  mostrarClientes(clientes);
  mostrarMorosos(clientes);
  return 0;
}

void mostrarMorosos(Cliente clientes[3]){
  cout<<"Clientes moroso : \n";
  for(int i = 0;i < 3; i++){
    if(clientes[i].estado==morosos){
      cout<<clientes[i].nombre<<i<<
        ", Unidades solicitadas: "<<clientes[i].unidadesSolicitadas<<
        ", Precio: "<<clientes[i].precio<<", Estado: "<<
        clientes[i].estado<<"\n";
    }
  }
}
void generarClientes(Cliente clientes[3]){
  //semilla para el numero random
  srand(time(NULL));
  for(int i = 0;i<3; i++){
    strcpy(clientes[i].nombre,"Cliente");
    clientes[i].unidadesSolicitadas = rand()%500;
    clientes[i].precio = rand()%100;
    //Cast el entero i a Estado:morosos,atrasado o pagado
    clientes[i].estado = Estado(rand()%3);
  }
}
void mostrarClientes(Cliente clientes[3]){
  cout<<"{"<<"\n";
  for(int i = 0;i<3; i++){
    cout<<clientes[i].nombre<<i<<
      ", Unidades solicitadas: "<<clientes[i].unidadesSolicitadas<<
      ", Precio: "<<clientes[i].precio<<", Estado: "<<
      clientes[i].estado<<"\n";
  }

  cout<<"}"<<endl;
}
