#include "Aluno.cpp"

class VetAluno
{
  Aluno vAlunos[20];
  bool valido[20];

public:
  VetAluno();
  void listaVet();
  void inclui(int matr, float n1, float n2);
  void exclui(int matr);
  void consulta(int matr);
  void altera(int matr);
};