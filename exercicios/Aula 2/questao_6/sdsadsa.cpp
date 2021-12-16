// soma e multiplica 2 vetores
const SIZE = 10;
class Vector
{
  double c[SIZE]; // armazena o vetor
public:
  Vector(); // cria vetor vazio

  // para atribuir as novas funcionalidades nos operadores (sobrecarga) à nossa classe, devemos incluir as classes de implementação dos operadores como 'friend'
  friend Vector operator+(const Vector &v, const Vector &w);
  friend double operator*(const Vector &v, const Vector &w);
};
Vector::Vector()
{
  for (int i = 0; i < SIZE; i++)
    c[i] = 0.0;
}

// ==================== SOBRECARGA DE OPERADORES ====================== //
// As funções abaixo (sobrecarga de operadores) não pertencem à nenhuma classe
Vector operator+(const Vector &v, const Vector &w)
{
  Vector u;
  for (int i = 0; i < SIZE; i++)
    u.c[i] = v.c[i] + w.c[i];
  return u;
}
double operator*(const Vector &v, const Vector &w)
{
  double sum = 0.0;
  for (int i = 0; i < SIZE; i++)
    sum += v.c[i] * w.c[i];
  return sum;
}