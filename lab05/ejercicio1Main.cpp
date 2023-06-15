#include <iostream>
#include "ejercicio1.h"
using namespace std;


//se usa const  y & por una cuestion de eficiencia
int calDifDiasAnios(const Fecha& fecha1, const Fecha& fecha2){
  int difAnios =fecha2.anio-fecha1.anio;
  //si es cero, solo se retorna
  if (!difAnios) return 0;
  //diasPorAnioBisiesto son los dias de mas por anio bisiestos , es decir +1
  int diasPorAnioBisiesto = 0;
  for(int i = fecha1.anio ;i<fecha2.anio ; i++){
    if(i % 4 == 0)  diasPorAnioBisiesto++;
  }
  return 365*difAnios+diasPorAnioBisiesto;
}
int calDiasMes(const Fecha& fecha) {
  int diasDeMeses=0;
  int diasPorMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  diasPorMes[1]= fecha.anio % 4 == 0 ? 29:28;
  for(int i = 0;i<fecha.mes; i++){
    diasDeMeses += diasPorMes[i];
  }
  return diasDeMeses;
}

int contarDias(const Fecha& fecha1, const Fecha& fecha2) {
  //Calculamos las diferencias todo en dias
  int diferenciaDias;
  int difAniosDias = calDifDiasAnios(fecha1,fecha2);
  int difMesesDias =calDiasMes(fecha2)-calDiasMes(fecha1);
  int difDias = fecha2.dia -fecha1.dia;
  return difAniosDias+difMesesDias+difDias;
}
int main(){
  Fecha f1 = {23,6,1990};
  Fecha f2 = {5,3,1992};
  cout<<"f1: "<<f1.dia<<"/"<<f1.mes<<"/"<<f1.anio<<endl;
  cout<<"f2: "<<f2.dia<<"/"<<f2.mes<<"/"<<f2.anio<<endl;
  int diferenciaDias = (f2.anio>=f1.anio)? contarDias(f1,f2):contarDias(f2,f1);
  cout<<"la diferencia en dias es:"<< diferenciaDias <<endl;

  return 0;
}
