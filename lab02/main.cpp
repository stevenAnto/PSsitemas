#include <iostream>
#include <string>
#include "atleta.h"

string whoIsFastest(Atleta a,Atleta b){
  if(a.getTiempo()>b.getTiempo()){
    return a.getName();
  }
  else if(a.getTiempo()==b.getTiempo()){
    return "iguales";
  }
  else{
    return b.getName();
  }
}

int main(){
  Atleta a1("Henry",290,"peruano",10.80);
  Atleta a2("Kevin El Veloz",291,"Mexicano",10.55);
  bool c=a1<a2;
  cout<<c<<endl;
}

