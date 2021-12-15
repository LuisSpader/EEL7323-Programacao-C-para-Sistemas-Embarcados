#include "Aluno.h"

void Aluno::setMatr(int matricula)
{
  matr = matricula;
}
void Aluno::setN1(float nota1)
{
  n1 = nota1;
}
void Aluno::setN2(float nota2)
{
  n2 = nota2;
}
int Aluno::getMatr()
{
  return matr;
}
float Aluno::getN1()
{
  return n1;
}
float Aluno::getN2()
{
  return n2;
}
float Aluno::calcMedia()
{
  return (n1 + n2) / 2;
}
