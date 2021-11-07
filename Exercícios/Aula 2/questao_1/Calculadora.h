/* File Calculadora.h

  Luis Antonio Spader Simon <luisspaders@gmail.com> 

  Curso: Engenharia Eletrônica - Graduação - CTC - UFSC 
  
  2021

  1. Desenvolver um programa que leia um caracter (char) e dois números inteiros. Se o caracter for ‘a’, faça a soma dos números; se for ‘s’, a subtração; se for ‘m’, a multiplicação e se for ‘d’, divisão. Mostre o resultado na tela. Utilize a estrutura de seleção switch.

  Descricao: Definicao dos "headers" (interface) para a classe Calculadora

*/

#include <string>
using namespace std;

class Calculadora
{
  char op;
  int n1, n2;
  float resultado;

public:
  Calculadora(); // inicia classe
  // ~Calculadora(); // ??????

  //SET
  void setOp(char operacao);
  void setN1(int number);
  void setN2(int number);

  //GET
  char getOp();
  int getN1();
  int getN2();

  //RESULTADO
  float getResult();
};