/* File Data_nascimento.cpp

  Luis Antonio Spader Simon <luisspaders@gmail.com> 

  Curso: Engenharia Eletrônica - Graduação - CTC - UFSC 
  
  2021

  Descricao: Definicao das funcoes membro para os "headers" declarados na classe.h

  Questão: 5. Adapte o programa anterior criando uma nova estrutura Data que contém os dados: dia, mês e ano. Acrescente o tipo Data à estrutura Pessoa, correspondente à data de nascimento. Adapte também a função que imprime os dados para que seja impressa também a data de nascimento.

  dia, mês, ano

  classe Pessoa > classe Data_nascimento 

*/
// TO-DO:
// limite ano (actual date), tem que pegar ano do sistema ou internet
// limite mês <= 12
// limite dia (depende do mês)

#include <cstring>
#include <list>
#include <iostream>  // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
#include <string.h>  // Para trabalhar com strings
#include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

#include "Data_nascimento.h"

// Construtor: inicia classe
Data_nascimento::Data_nascimento()
{
  dia, mes, ano = 0;
  date = "";

  // cout << "Digite sua data de nascimento (xx/xx/xxxx): ";
};

// ------------------- Logic Functions -------------------

// Função: Verifica se é número
bool isNumber(const string &str)
{
  for (char const &c : str)
  {
    if (std::isdigit(c) == 0)
      return false;
  }
  return true;
}

// ------------------- SET -------------------
void Data_nascimento::setDate(string buffer)
{
  if (buffer.length() > 10)
  {
    cout << "Digits limit exceeded! \n";
    exit(EXIT_FAILURE);
  }
  string temp;

  date = buffer.substr(0, 2) + "/" + buffer.substr(3, 2) + "/" + buffer.substr(6, 4);

  // DIA
  temp = buffer.substr(0, 2);
  if (isNumber(temp) == true)
  {
    dia = std::stoi(temp);
  }
  else
  {
    cout << "Invalid Date\n";
    exit(EXIT_FAILURE);
  }

  // MÊS
  temp = buffer.substr(3, 2);
  if (isNumber(temp) == true)
  {
    mes = std::stoi(temp);
  }
  else
  {
    cout << "Invalid Date\n";
    exit(EXIT_FAILURE);
  }

  //ANO
  temp = buffer.substr(6, 4);
  if (isNumber(temp) == true)
  {
    ano = std::stoi(temp);
  }
  else
  {
    cout << "Invalid Date\n";
    exit(EXIT_FAILURE);
  }
};

void Data_nascimento::getDate()
{
  cout << "Sua data de nascimento eh: " << date << endl;
  // cout << "Sua data de nascimento eh: " << dia << "/" << mes << "/" << ano << endl;
}

// int main()
// {
//   // BUFFERS
//   string string_buffer;

//   Data_nascimento pessoa1; //declara objeto

//   cin >> string_buffer;
//   pessoa1.setDate(string_buffer);

//   pessoa1.getDate();

//   return 0;
// }