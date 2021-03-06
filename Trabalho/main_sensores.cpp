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
#include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
#include <string.h>  // Para trabalhar com strings
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...
#include "cadastro_Temperatura.cpp"
#include "cadastro_Pressao.cpp"

int main()
{
  int b_switch_sensor;
  while (true)
  {
    cout << " =================== Programa de Sensores =================== " << endl;
    cout << " Selecione o tipo de sensor com que deseja trabalhar" << endl;

    cout << " 1 - Temperatura" << endl;
    cout << " 2 - Pressao" << endl;
    cin >> b_switch_sensor;

    switch (b_switch_sensor)
    {
    case 1: // TEMPERATURA
      /* code */
      interface_temp();
      break;
    case 2: // PRESSAO
      interface_pressao();
      break;

    default:
      cout << "Opcao invalida, tente novamente" << endl;

      break;
    }
  }
  return 0;
}