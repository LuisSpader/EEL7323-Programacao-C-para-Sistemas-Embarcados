/* File Calculadora.h

  Luis Antonio Spader Simon <luisspaders@gmail.com> 

  Curso: Engenharia Eletrônica - Graduação - CTC - UFSC 
  
  2021

  1. Desenvolver um programa que leia um caracter (char) e dois números inteiros. Se o caracter for ‘a’, faça a soma dos números; se for ‘s’, a subtração; se for ‘m’, a multiplicação e se for ‘d’, divisão. Mostre o resultado na tela. Utilize a estrutura de seleção switch.

  Descricao: Definicao dos "headers" (interface) para a classe Calculadora

*/

#include <string>
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

class Calculadora
{
  char op;
  // int n1, n2;
  float n1, n2, resultado;

public:
  Calculadora(); // inicia classe
  // ~Calculadora(); // ??????

  //SET
  void setOp(char operacao);
  void setN1(float number);
  void setN2(float number);

  //GET
  char getOp();
  float getN1();
  float getN2();

  //RESULTADO
  float getResult();
};