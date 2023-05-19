#include <string>
using namespace std;

class Atleta{
  public:
    Atleta(string,int,string,double);
    string getName();
    int getNumero();
    double getTiempo();
    bool operator<(Atleta);
  private:
    string nombre;
    int numero;
    string nacionalidad;
    double tiempo;
};
