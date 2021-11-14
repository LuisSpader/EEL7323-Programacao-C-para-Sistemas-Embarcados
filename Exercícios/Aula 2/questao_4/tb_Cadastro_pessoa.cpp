/* File Cadastro_pessoa.h

  Luis Antonio Spader Simon <luisspaders@gmail.com> 

  Curso: Engenharia Eletrônica - Graduação - CTC - UFSC 
  
  2021

  4. Desenvolver um programa que contenha uma estrutura (struct) Pessoa com os seguintes dados: nome, idade, peso. Crie uma função que recebe essa estrutura por parâmetro e imprima na tela os dados contidos nela.

  Descricao: Definicao dos "headers" (interface) para a classe.cpp

*/

using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...
#include <string>
#include "Cadastro_pessoa.cpp"

// void setNome(string newName);
// void setIdade(int newIdade);
// void setPeso(int newPeso);

// // GET
// string getNome();
// int getIdade();
// int getPeso();

void main()
{
  // BUFFERS
  string buffer_nome;
  int buffer_peso, buffer_idade;

  Cadastro_pessoa pessoa1;

  cout << "Digite seu nome: " << endl;

  pessoa1.setNome(cin);
  // cin >> Cadastro_pessoa.nome;

  // cout << "Digite seu nome: " << endl;
  // cin >> Cadastro_pessoa.nome;

  cout << "Nome: " << pessoa1.getNome() << endl;
}