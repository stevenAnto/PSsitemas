#include <iostream>
#include <string>
#include "carrera.cpp"

/*string whoIsFastest(Atleta a,Atleta b){
  if(a.getTiempo()>b.getTiempo()){
    return a.getName();
  }
  else if(a.getTiempo()==b.getTiempo()){
    return "iguales";
  }
  else{
    return b.getName();
  }
}*/

int main(){
  Carrera c1(10);
  Atleta a1("Henry",290,"peruano",10.80);
  Atleta a2("Kevin El Veloz",291,"Mexicano",10.55);
  Atleta a3("Stv  ",292,"Arequipenio",10.02);
  c1.addAtletas(a1);
  c1.addAtletas(a2);
  c1.addAtletas(a3);
  cout<<c1.fastest().getName()<<endl;
  /*bool c=a1<a2;
  cout<<c<<endl;*/
}

