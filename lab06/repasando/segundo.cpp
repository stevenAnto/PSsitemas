#include <iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
struct Reading{
  int hour;
  double temperature;
};
void mostrarVector(vector<Reading> a){
  cout<<"entro a mostrarVector"<<endl;
  for(Reading element : a){
    cout<<element.hour<<":"<<element.temperature<<"\n";
  }
  cout<<endl;
};

int main(){
  cout<<"ingrese el nombre de tabla que desea ingresar"<<endl;
  string name;
  cin>>name;
  fstream ist{name};
  if(!ist) return 1;
  else cout<<"Se abrio"<<endl;
  int hour;
  double temperature;
  for(int i = 0;i<3; i++){
    cin>>hour>>temperature;
    ist<<hour<<" "<<temperature<<"\n";
  }
  vector<Reading> temps;
  ist.close();
  //aglo mal
  ifstream lec{name};
  int hourf;
  double temperaturef;
  while(lec>>hourf>>temperaturef){
    cout<<"entro while"<<endl;
    temps.push_back(Reading{hourf,temperaturef});
  }
  mostrarVector(temps);

  return 0;
}
