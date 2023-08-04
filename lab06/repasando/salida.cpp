#include <iostream>
#include <fstream>
#include<string>
using namespace std;

int main(){
  cout<<"Entre naem of ouput file:";
  string name;
  cin >>name;
  ofstream ist{name};
  auto* objeto = &ist;
  if(!ist) cerr<<"no puedo abrir";
  else cout<<"se abrio"<<endl;
  char points[5]={'a','b','c','d','e'};
  int num[3]={1,2,3};
  for(char p:points ){
    ist<<"("<<p<<")"<<"\n";
  }
  for(int n:num){
    ist<<"("<<n<<")"<<"\n";
  }
  cout<<objeto;

  return 0;
}
