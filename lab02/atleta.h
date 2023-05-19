#include <string>
using namespace std;

class Atleta{
  friend ostream& operator<<(ostream&, Atleta&);
  public:
  Atleta(string,int,string,double);
  string getName();
  string getNacionalidad();
  int getNumero();
  double getTiempo();
  bool operator<(Atleta);
  private:
  string nombre;
  int numero;
  string nacionalidad;
  double tiempo;
};
