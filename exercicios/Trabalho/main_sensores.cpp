/* File main.cpp

  Luis Antonio Spader Simon <luisspaders@gmail.com>
  Curso: Engenharia Eletrônica - Graduação - CTC - UFSC
  2021
- [ ]  O menu do programa deverá possuir, no mínimo, as seguintes opções:
    - [ ]  Leitura de sensor de temperatura (que inclui o armazenamento do valor lido no vetor)
    - [ ]  Excluir temperatura
    - [ ]  Consultar determinada temperatura
    - [ ]  Listar todas as temperaturas
    - [ ]  Leitura de sensor de pressao (que inclui o armazenamento do valor lido no vetor)
    - [ ]  Excluir pressao
    - [ ]  Consultar determinada pressao
    - [ ]  Listar todas as pressões
*/
#include <iostream>
#include <stdlib.h> // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
#include <string.h> // Para trabalhar com strings
#include "cadastro_Temperatura.cpp"
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

int main()
{
  interface_temp();

  return 0;
}