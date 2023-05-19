#include <vector>
#include "atleta.h"

class Carrera{
  int distancia;
  std::vector<Atleta> atletas;
  public:
  Carrera(int distancia){
    this->distancia=distancia;
  }
  void addAtletas(Atleta a){
    atletas.push_back(a);
  }
  Atleta fastest(){
    Atleta max=atletas[0];
    for(int i=0;i<atletas.size();i++){
      cout<<"i"<<i<<endl;
      if(atletas[0]>max){
        max=atletas[i];
      }
    }
    return max;
  }
};
