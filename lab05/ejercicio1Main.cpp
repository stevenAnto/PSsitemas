#include <iostream>
#include "ejercicio1.h"
using namespace std;



int contarDias(const Fecha& fecha1, const Fecha& fecha2) {
  //Calculamos las diferencias todo en dias
  int diferenciaDias;
  int difAnios = (fecha2.anio-fecha1.anio)*365;
  int difMeses = (fecha2.mes-fecha1.mes)*30;
  int difDias = fecha2.dia -fecha1.dia;
  cout <<" difAnios"<<difAnios<<endl;
  cout <<" difmeses"<<difMeses<<endl;
  cout <<" difdias"<<difDias<<endl;
  //static const int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return difAnios+difMeses+difDias;
  //  diferenciaDias = (difMeses < 0) ? (difAnios - difMeses) : (difAnios + difMeses);
  // diferenciaDias = (difDias < 0) ? (diferenciaDias - difDias) : (diferenciaDias + difDias);
}
int main(){
  Fecha f1 = {23,6,1990};
  Fecha f2 = {5,3,1992};
  cout<<"la diferencia en dias es"<< contarDias(f1,f2);

  return 0;
}
