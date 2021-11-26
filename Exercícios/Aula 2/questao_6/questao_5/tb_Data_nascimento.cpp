/* File tb_Data_nascimento.h

  Luis Antonio Spader Simon <luisspaders@gmail.com> 

  Curso: Engenharia Eletrônica - Graduação - CTC - UFSC 
  
  2021

  Descricao: Definicao dos "headers" (interface) para a classe.cpp

  Questão: 5. Adapte o programa anterior criando uma nova estrutura Data que contém os dados: dia, mês e ano. Acrescente o tipo Data à estrutura Pessoa, correspondente à data de nascimento. Adapte também a função que imprime os dados para que seja impressa também a data de nascimento.


  dia, mês, ano

  classe Pessoa > classe Data_nascimento 
*/

using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...
#include <list>
#include <string>
#include "Data_nascimento.cpp"

// void setDia(int newDay);
// void setIdade(int newIdade);
// void setPeso(int newPeso);

// // GET
// string getDay();
// int getMonth();
// int getYear();

int main()
{
  // BUFFERS
  string string_buffer;
  int buffer_num;

  Data_nascimento pessoa1;
  // Data_nascimento pessoa1();

  // pessoa1();
  // cout << "" << endl;
  cin >> string_buffer;
  pessoa1.setDate(string_buffer);

  // cout << "Dia: " << pessoa1.getDay() << endl;
  // cout << "Mês: " << pessoa1.getMonth() << endl;
  // cout << "Ano: " << pessoa1.getYear() << endl;
  
  pessoa1.getDate();
  
  return 0;
}