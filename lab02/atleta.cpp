#include "atleta.h"

Atleta::Atleta(string nombre,int numero,string nacionalidad, double tiempo){
  this->nombre=nombre;
  this->numero=numero;
  this->nacionalidad=nacionalidad;
  this->tiempo=tiempo;
}
bool Atleta::operator<(Atleta otro){
  return tiempo<otro.getTiempo();

}
string Atleta::getName (){
  return nombre;
}
int Atleta::getNumero (){
  return numero;
}
double Atleta::getTiempo (){
  return tiempo;
}
