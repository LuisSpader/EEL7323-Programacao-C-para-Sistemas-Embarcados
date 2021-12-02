
#include <iostream>
#include <stdlib.h> // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
#include <string.h> // Para trabalhar com strings
#include "Cadastro_pessoa.cpp"
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

int main()
{
  // BUFFERS
  string buffer_string;
  int buffer_num;

  Cadastro_pessoa pessoa1;

  cout << "Digite seu nome: " << endl;
  cin >> buffer_string;
  pessoa1.setNome(buffer_string);

  cout << "Digite sua idade: " << endl;
  cin >> buffer_num;
  pessoa1.setIdade(buffer_num);

  cout << "Digite seu peso: " << endl;
  cin >> buffer_num;
  pessoa1.setPeso(buffer_num);

  // pessoa1

  cout << "Digite sua data de nascimento (xx/xx/xxxx): ";
  cin >> buffer_string;
  pessoa1.setDate(buffer_string);

  pessoa1.GetInfo();
  pessoa1.getDate();

  // dob.
  // cout << "Nome: " << pessoa1.getNome() << endl;
  // cout << "Idade: " << pessoa1.getIdade() << endl;
  // cout << "Peso: " << pessoa1.getPeso() << endl;

  return 0;
}
