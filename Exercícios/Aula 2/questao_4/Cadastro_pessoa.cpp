/* File cadastro_pessoa.cpp

  Luis Antonio Spader Simon <luisspaders@gmail.com> 

  Curso: Engenharia Eletrônica - Graduação - CTC - UFSC 
  
  2021

  4. Desenvolver um programa que contenha uma estrutura (struct) Pessoa com os seguintes dados: nome, idade, peso. Crie uma função que recebe essa estrutura por parâmetro e imprima na tela os dados contidos nela.

  Descricao: Definicao das funcoes membro para os "headers" declarados na classe.h

*/

#include <iostream> // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
// #include <string.h>  // Para trabalhar com strings
#include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

#include "Cadastro_pessoa.h"

// inicia classe -> para quê?
Cadastro_pessoa()
{
  nome = "";
  idade = 0;
  peso = 0;
};

// SET
void Cadastro_pessoa::setNome(string newName)
{
  nome = newName;
}

void Cadastro_pessoa::setIdade(int newIdade)
{
  idade = newIdade;
}

void Cadastro_pessoa::setPeso(int newPeso)
{
  peso = newPeso;
}

// GET
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
