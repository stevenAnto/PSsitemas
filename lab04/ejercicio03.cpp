#include <iostream>
using namespace std;
void mostrarVector(int*, int);
void mostrarMatriz(int**,int, int);
void buscarIndices(int*,int* ,int ,int );
void findSilla(int ,int ,int );


void findSilla(int **punteroMatriz,int nfil,int ncol){
  int *menoresFilas = new int[nfil];
  int *menoresCol = new int[ncol];
  for(int i = 0;i<ncol; i++){
    menoresCol[i]=punteroMatriz[0][i];
  }
  //mostrarVector(menoresCol,ncol);
  for(int i = 0;i<nfil; i++){
    int menorF=punteroMatriz[i][0];
    for(int j = 0;j<ncol; j++){
      //guardo en los vectores indices y no valores
      if(punteroMatriz[i][j]<menorF) menorF=punteroMatriz[i][j];
      if(i!=0&&(punteroMatriz[i][j]>punteroMatriz[i-1][j]))
        menoresCol[j]=punteroMatriz[i][j];
      //if(punteroMatriz[i][j]<menorF) menorF=j;
      //if(i!=0&&(punteroMatriz[i][j]>punteroMatriz[i-1][j])) menoresCol[j]=i;
    }
    menoresFilas[i]=menorF;
  }
  cout<<"mostrando "<<endl;
  mostrarVector(menoresFilas,nfil);
  mostrarVector(menoresCol,ncol);
  buscarIndices(menoresFilas,menoresCol,nfil,ncol);

}
void buscarIndices(int *vector1,int *vector2,int n1,int n2){
  for(int i = 0;i<n1; i++){
    for(int j = 0;j<n2; j++){
      if(vector1[i]==vector2[j]){
        cout<<" Hay silla"<<": "<<"fila:"<<i<<"columna"<<j<<endl;
        return;
      }
    }
  }
  cout<<"No hay silla"<<endl;
}
void pedirDate(int **punteroMatriz,int nfil, int ncol){
  cout<<"Ingresando datos a la matriz"<<endl;
  for(int i = 0;i<nfil; i++){
    for(int j = 0;j<ncol; j++){
      cout<<"ingrese para "<<i<<j<<endl;
      cin>>punteroMatriz[i][j];
    }
    cout<<"\n";
  }
}
void mostrarMatriz(int **punteroMatriz,int nfil, int ncol){
  cout<<"La matriz ingresada es la sigueinte:"<<endl;
  for(int i = 0;i<nfil; i++){
    for(int j = 0;j<ncol; j++){
      cout<<punteroMatriz[i][j]<<" ";
    }
    cout<<"\n";
  }
}
void mostrarVector(int *vector,int n){
  for(int i = 0;i<n; i++){
    cout<< vector[i]<<"\t";
  }
  cout<<endl;
}
int main(){
  int nfil,ncol;
  cout<<"Ingrese el numero de filas y coluymnar"<<endl;
  cin>>nfil;
  cin>>ncol;
  int **punteroMatriz;
  punteroMatriz = new int*[nfil];
  for(int i = 0;i<nfil; i++){
    punteroMatriz[i] = new int[ncol];
  }
  pedirDate(punteroMatriz,nfil,ncol);
  mostrarMatriz(punteroMatriz,nfil,ncol);
  findSilla(punteroMatriz,nfil,ncol);
}
