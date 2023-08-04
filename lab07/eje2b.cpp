#include <iostream>
#include<string>
using namespace std;

void error(string s){
  throw runtime_error(s);
}
double some_function(){
  double d=0;
  cin>>d;
  if(!cin) error("No se pudo leer dato de tipo double");
  return d;

}
int main(){
  try{
    some_function();
  }
  catch(runtime_error& e){
    cout<<e.what()<<endl;

  }
  return 0;
}
