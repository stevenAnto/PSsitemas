#include <iostream>
#include <fstream>
using namespace std;

int main(){
  char cadena[128];

  ofstream fs("nombre.txt");

  fs<<"Hola, Mundo"<<endl;

  fs.close();

  ifstream fe("nombre.txt");

  fe.getline(cadena,128);

  cout <<cadena<<endl;
  return 0;
}
