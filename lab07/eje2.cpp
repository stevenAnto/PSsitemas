#include <iostream>
using namespace std;

int main(){
  int *x;
  long int y=10000000000;
  try{
    x=new int[y];
    x[0]=10;
    //convierte a x en un Puntero de tipo void
    cout<<"Puntero: "<<(void *)x<<endl;
    delete[] x;
  }
  catch(bad_alloc& e){
    cout<<"Memoria insuficiente"<<
      e.what()<<endl;
  }
  return 0;
}
