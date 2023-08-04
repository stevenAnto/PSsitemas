#include<iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

int main(){
  pid_t hijo =fork();
  if(hijo==0){
    pid_t nieto = fork();
    if(nieto==0){
      cout<<"Proceso nieto"<<endl;
    }
    else{
      wait(NULL);
      cout<<"termino Proceso nieto"<<endl;
      cout<<"Proceso hijo"<<endl;
    }
  }
  else{
    wait(NULL);
    cout<<"termino proceso hijo"<<endl;
    cout<<"El proceso padre"<<endl;
  }
  return 0;
}
