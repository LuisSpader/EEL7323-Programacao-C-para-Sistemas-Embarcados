/* File Cadastro_pessoa.h

  Luis Antonio Spader Simon <luisspaders@gmail.com>

  Curso: Engenharia Eletrônica - Graduação - CTC - UFSC

  2021

  5. Adapte o programa anterior criando uma nova estrutura Data que contém os dados: dia, mês e ano. Acrescente o tipo Data à estrutura Pessoa, correspondente à data de nascimento. Adapte também a função que imprime os dados para que seja impressa também a data de nascimento.

  Descricao: Definicao dos "headers" (interface) para a classe.cpp

*/
#include "Data_nascimento.cpp"

#include <string>
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

class Cadastro_pessoa : public Data_nascimento
{
  string nome;
  int idade, peso;
  Data_nascimento dob; // date of birth

public:
  Cadastro_pessoa(); // inicia classe

  void setNome(string newName);
  void setIdade(int newIdade);
  void setPeso(int newPeso);
  string getNome();
  int getIdade();
  int getPeso();

  void GetInfo()
  {
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
    cout << "Peso: " << peso << endl;
  }
};