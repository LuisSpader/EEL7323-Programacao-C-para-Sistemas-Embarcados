/* File cadastro_Temperatura.cpp

  Luis Antonio Spader Simon <luisspaders@gmail.com>
  Curso: Engenharia Eletrônica - Graduação - CTC - UFSC
  2021

  Descricao: Definicao das funcoes membro para os "headers" declarados na classe.h

*/

//---------------------------- LIBRARIES ------------------------ //
#include <string.h> // Para trabalhar com strings
#include <iostream> // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
// #include <string.h>  // Para trabalhar com strings
#include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

//---------------------------- MY LIBRARIES ------------------------ //
#include "Temperatura.cpp"

//---------------------------- CONSTANTS ------------------------ //
#define N_TEMPERATURA 3

class cadastro_Temperatura
{
private:
  // bool temp_valida;

public:
  int vagas;
  Temperatura temperatura[N_TEMPERATURA];
  cadastro_Temperatura(); // Construtor: inicia objeto
                          // ~cadastro_Temperatura(); // Destrutor: destroi objeto

  void set_ID(int NewID);

  void set_NewLeitura(int check_id);

  void get_Consulta_temperatura(int temp1, int temp2);
  void get_Listagem_temperaturas();
  void Altera_temperatura(int check_id, float temp1, float temp2); // o número de matrícula não pode ser alterado
  void Exclui_temperatura(int check_id, float check_temp, bool apaga_todos);
};