
#include <iostream>
#include <stdlib.h>

using namespace std;

class Aluno
{
  int matr;
  float n1;
  float n2;

public:
  void setMatr(int matr);
  void setN1(float nota1);
  void setN2(float nota2);
  int getMatr();
  float getN1();
  float getN2();
  float calcMedia();
};