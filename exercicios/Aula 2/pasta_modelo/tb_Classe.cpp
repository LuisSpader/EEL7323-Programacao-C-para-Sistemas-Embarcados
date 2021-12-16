/* File tb_Classe.h

  Luis Antonio Spader Simon <luisspaders@gmail.com> 

  Curso: Engenharia Eletrônica - Graduação - CTC - UFSC 
  
  2021

  Descricao: Definicao dos "headers" (interface) para a classe.cpp

  Questão:

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

int main()
{
  // BUFFERS
  string buffer_nome;
  int buffer_num;

  Cadastro_pessoa pessoa1;

  cout << "Digite seu nome: " << endl;
  cin >> buffer_nome;
  pessoa1.setNome(buffer_nome);

  cout << "Digite sua idade: " << endl;
  cin >> buffer_num;
  pessoa1.setIdade(buffer_num);

  cout << "Digite seu peso: " << endl;
  cin >> buffer_num;
  pessoa1.setPeso(buffer_num);

  cout << "Nome: " << pessoa1.getNome() << endl;
  cout << "Idade: " << pessoa1.getIdade() << endl;
  cout << "Peso: " << pessoa1.getPeso() << endl;

  return 0;
}