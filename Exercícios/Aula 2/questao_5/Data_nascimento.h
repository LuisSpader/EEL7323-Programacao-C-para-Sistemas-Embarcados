/* File Data_nascimento.h
  Luis Antonio Spader Simon <luisspaders@gmail.com> 
  Curso: Engenharia Eletrônica - Graduação - CTC - UFSC 
  2021

  Descricao: Definicao dos "headers" (interface) para a classe.cpp

  Questão: 5. Adapte o programa anterior criando uma nova estrutura Data que contém os dados: dia, mês e ano. Acrescente o tipo Data à estrutura Pessoa, correspondente à data de nascimento. Adapte também a função que imprime os dados para que seja impressa também a data de nascimento.

  dia, mês, ano

  classe Pessoa > classe Data_nascimento 
*/
#include <list>
#include <string>
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

class Data_nascimento
{
  int dia, mes, ano;
  // string dia, mes, ano;
  string date;

public:
  Data_nascimento(); // inicia classe

  // ------------------- Write -------------------
  // void Data_nascimento::AskDate();

  // ------------------- SET -------------------
  void setDate(string buffer);

  void getDate();
};