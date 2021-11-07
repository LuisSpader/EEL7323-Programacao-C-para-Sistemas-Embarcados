/* File teste_Calculadora.cpp

  Luis Antonio Spader Simon <luisspaders@gmail.com> 

  Curso: Engenharia Eletrônica - Graduação - CTC - UFSC 
  
  2021

  1. Desenvolver um programa que leia um caracter (char) e dois números inteiros. Se o caracter for ‘a’, faça a soma dos números; se for ‘s’, a subtração; se for ‘m’, a multiplicação e se for ‘d’, divisão. Mostre o resultado na tela. Utilize a estrutura de seleção switch.

  Descricao: Teste classe Calculadora

*/

// void setOp();
// void setN1();
// void setN2();

// string getOp(char op);
// int getN1(int n1);
// int getN2(int n2);

#include "Calculadora.cpp"

int main()
{
  Calculadora calc;
  char op;
  float number;

  cout << "Escolha a operacao matematica (+, -, *, /): " << endl;
  cin >> op;
  calc.setOp(op);

  cout << "Digite o primeiro numero: " << endl;
  cin >> number;
  calc.setN1(number);

  cout << "Digite o segundo numero: " << endl;
  cin >> number;
  calc.setN2(number);

  cout << calc.getN1() << " " << calc.getOp() << " " << calc.getN2() << " = " << calc.getResult() << endl;

  return 0; // A instrução return faz com que a função main termine e retorne o código seguido pela instrução, nesse caso, 0.
}
