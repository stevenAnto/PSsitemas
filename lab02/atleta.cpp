#include "atleta.h"

Atleta::Atleta(string nombre,int numero,string nacionalidad, double tiempo){
  this->nombre=nombre;
  this->numero=numero;
  this->nacionalidad=nacionalidad;
  this->tiempo=tiempo;
}
bool Atleta::operator<(Atleta otro){
//  cout<<"algo"<<endl;
  return tiempo<otro.getTiempo();

}
string Atleta::getName (){
  return nombre;
}
string Atleta::getNacionalidad(){
  return nacionalidad;
}
int Atleta::getNumero (){
  return numero;
}
double Atleta::getTiempo (){
  return tiempo;
}
ostream& operator<<(ostream& output,Atleta& a){
  string aaa=a.getName()+"Tiempo: "+to_string(a.getTiempo())+"Nacionalidad: "+a.getNacionalidad();
  output<<aaa;
  return output;
}
