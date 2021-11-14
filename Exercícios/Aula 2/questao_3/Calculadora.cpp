/* File Calculadora.cpp

  Luis Antonio Spader Simon <luisspaders@gmail.com> 

  Curso: Engenharia Eletrônica - Graduação - CTC - UFSC 
  
  2021

  1. Desenvolver um programa que leia um caracter (char) e dois números inteiros. Se o caracter for ‘a’, faça a soma dos números; se for ‘s’, a subtração; se for ‘m’, a multiplicação e se for ‘d’, divisão. Mostre o resultado na tela. Utilize a estrutura de seleção switch.

  Descricao: Definicao das funcoes membro para os "headers" declarados na classe Calculadora

*/

#include <iostream> // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
// #include <string.h>  // Para trabalhar com strings
#include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

#include "Calculadora.h" // incluindo headers

// INICIALIZA CLASSE COM VALORES RESET -> para quê?
Calculadora::Calculadora()
{
  op = 'X';
  n1 = 0;
  n2 = 0;
  resultado = 0;
}

// Calculadora::~Calculadora()
// {
//   op = 'X';
//   n1 = 0;
//   n2 = 0;
//   resultado = 0;
// }

void Calculadora::setOp(char operacao)
{
  op = operacao;
}
void Calculadora::setN1(float number)
{
  n1 = number;
}
void Calculadora::setN2(float number)
{
  n2 = number;
}

char Calculadora::getOp()
{
  return op;
}
float Calculadora::getN1()
{
  return n1;
}
float Calculadora::getN2()
{
  return n2;
}

float Calculadora::getResult()
{
  switch (op)
  {
  case '+':
    resultado = n1 + n2;
    break;

  case '-':
    resultado = n1 - n2;
    break;

  case '*':
    resultado = n1 * n2;
    break;

  case '/':
    resultado = n1 / n2;
    break;

  default:
    cout << "Erro: Operacao invalida";
    break;
  }
  return resultado;
}
