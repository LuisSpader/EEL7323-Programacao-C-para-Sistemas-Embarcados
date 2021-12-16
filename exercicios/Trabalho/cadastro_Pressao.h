/* File cadastro_Pressao.cpp

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
#include "Pressao.cpp"

//---------------------------- CONSTANTS ------------------------ //
#define N_PRESSAO 2

class cadastro_Pressao
{
private:
  // bool temp_valida;

public:
  int vagas;
  Pressao vpressao[N_PRESSAO];
  cadastro_Pressao(); // Construtor: inicia objeto
                      // ~cadastro_Pressao(); // Destrutor: destroi objeto

  void set_new_ID(int NewID);

  void set_NewLeitura(int check_id);

  void get_Consulta_pressao(int temp1, int temp2);
  void get_Lista_IDs();
  void get_Listagem_pressao();
  void Altera_pressao(int check_id, float temp1, float temp2); // o número de matrícula não pode ser alterado
  void Exclui_pressao(int check_id, float check_pressao, bool apaga_todos);
};