#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


//datos
struct Tdato{
  int b;
  char s[100];
};

int x,n,a[10]= {1,2,3,4,5,6,7,8,9,0};
double f;
char nombre[]="Ejercicios ficheros binarios";
Tdato p;
//Objetos de flujos de salida y entrada
ifstream f1;
ofstream f2;

int main(){
  f=1.5555;
  double leer;
  //Creo el archivo entrada.dat
  f2.open("entrada.dat",ios::binary);
  //Escribo el valor de x en el
  f2.write(reinterpret_cast<char *>(&f),sizeof(f));
  f2.close();
  //abro el archivo entrada.dat
  f1.open("entrada.dat",ios::binary);
  //Leo el archivo entrada.dat
  f1.read(reinterpret_cast<char *>(&leer),sizeof(leer));
  //Imprimo el valor leido
  cout<<leer<<endl;
  f1.close();
}
