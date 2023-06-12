enum Estado{
  morosos,
  atrasado,
  pagado,
};
struct Cliente{
  char nombre[100];
  int unidadesSolicitadas;
  int precio;
  Estado estado;
};
