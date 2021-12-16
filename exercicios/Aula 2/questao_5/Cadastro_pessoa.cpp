/* File cadastro_pessoa.cpp

  Luis Antonio Spader Simon <luisspaders@gmail.com> 
  Curso: Engenharia Eletrônica - Graduação - CTC - UFSC 
  2021

  5. Adapte o programa anterior criando uma nova estrutura Data que contém os dados: dia, mês e ano. Acrescente o tipo Data à estrutura Pessoa, correspondente à data de nascimento. Adapte também a função que imprime os dados para que seja impressa também a data de nascimento.

  Descricao: Definicao das funcoes membro para os "headers" declarados na classe.h

*/
//---------------------------- LIBRARIES ------------------------ //
#include <string.h> // Para trabalhar com strings
#include <iostream> // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
// #include <string.h>  // Para trabalhar com strings
#include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

//---------------------------- MY LIBRARIES ------------------------ //
// #include "Data_nascimento.h"
#include "Cadastro_pessoa.h"

// Construtor: inicia classe -> para quê? Para quando vc quer inicializar coisas da classe
Cadastro_pessoa::Cadastro_pessoa()
{
  nome = "";
  idade = 0;
  peso = 0;
}

// Métodos SET -> Classe::método(tipo_var identificacão_qualquer)
void Cadastro_pessoa::setNome(string newName)
{
  // cout << "Digite seu nome: " << endl;
  nome = newName;

  // cin >> buffer_nome;
  // pessoa1.setNome(buffer_nome);
}

void Cadastro_pessoa::setIdade(int newIdade)
{
  idade = newIdade;
}

void Cadastro_pessoa::setPeso(int newPeso)
{
  peso = newPeso;
  // dob.setDate
}

// Métodos GET
string Cadastro_pessoa::getNome()
{
  return nome;
}

int Cadastro_pessoa::getIdade()
{
  return idade;
}

int Cadastro_pessoa::getPeso()
{
  return peso;
}
