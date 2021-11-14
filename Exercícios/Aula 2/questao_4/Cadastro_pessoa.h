/* File Cadastro_pessoa.h

  Luis Antonio Spader Simon <luisspaders@gmail.com> 

  Curso: Engenharia Eletrônica - Graduação - CTC - UFSC 
  
  2021

  4. Desenvolver um programa que contenha uma estrutura (struct) Pessoa com os seguintes dados: nome, idade, peso. Crie uma função que recebe essa estrutura por parâmetro e imprima na tela os dados contidos nela.

  Descricao: Definicao dos "headers" (interface) para a classe.cpp

*/

#include <string>
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

class Cadastro_pessoa
{
  string nome;
  int idade, peso;

public:
  Cadastro_pessoa(); // inicia classe

  // SET
  void setNome(string newName);
  void setIdade(int newIdade);
  void setPeso(int newPeso);

  // GET
  string getNome();
  int getIdade();
  int getPeso();
};