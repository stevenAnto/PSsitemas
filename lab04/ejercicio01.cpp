#include <iostream>
#include <string>
using namespace std;

void genPascal(string*,int);
void mostrar(string*,int);

int main(){
  cout<<"Ingre el numero de filas que desea que se muestren";
  int size;
  cin>>size;
  string *arreglo = new string[size];
  //mostrar(arreglo, size);
  genPascal(arreglo,size);
  mostrar(arreglo, size);
}

void genPascal(string *arreglo, int size){
  for(int i = 1;i<=size; i++){
    int c=1;
    string fila="";
    for(int j = 1;j<=i; j++){
      //cout<<c<<" ";
      fila = fila +to_string(c);
      c=c*(i-j)/j;
    }
    arreglo[i-1]=fila;
    //cout<<"\n";
  }
}
void mostrar(string* array,int size ){
  cout<<"{";
  for(int i = 0;i<size; i++){
    cout<<array[i]<<endl;
  }
  cout<<"}"<<endl;
}
