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
  // class_Turma temperatura;
  // float b_n1, b_n2;

  bool continuar = true;
  int b_id, b_switch;
  float b_temp1, b_temp2;
  cadastro_Temperatura temperatura;

  while (continuar == true)
  {
    // cout << "--------------------------------------- \n \n " << endl;
    cout << " =================== Programa de Sensores =================== " << endl;
    cout << "Capacidade: " << N_TEMPERATURA << " alunos; Vagas: " << temperatura.vagas << endl;
    cout << "Digite a operacao desejada:" << endl;

    cout << " --------------- Temperatura --------------- " << endl;
    cout << "1 - Cadastro de Sensor" << endl;
    cout << "2 - Registo Leitura do Sensor" << endl;
    cout << "3 - Consultar " << endl;
    cout << "4 - Listar todas as leituras" << endl;
    cout << "5 - Excluir " << endl;
    cout << " " << endl;

    // cout << " --------------- Pressão --------------- " << endl;
    // cout << "5 - Cadastro Leitura do Sensor" << endl;
    // cout << "6 - Consultar " << endl;
    // cout << "7 - Listar todas as leituras" << endl;
    // cout << "8 - Excluir " << endl;

    // cout << "2 - Consulta Aluno" << endl;
    // cout << "3 - Listagem Alunos" << endl;
    // cout << "4 - Alterar dados Aluno" << endl;
    // cout << "5 - Excluir Aluno" << endl;
    // cout << "6 - Encerra Programa" << endl;
    cin >> b_switch;

    switch (b_switch)
    {
      // --------------- Temperatura ---------------
    case 1: // 1 - Cadastro de Sensor
    {
      cout << "Digite o ID do sensor de Temperatura: " << endl;
      cin >> b_id;
      temperatura.set_ID(b_id);
      break;
    }

    case 2: // 2 - Registo Leitura do Sensor
    {
      cout << "Digite o ID do sensor de Temperatura: " << endl;
      cin >> b_id;
      temperatura.set_NewLeitura(b_id);
      break;
      // o valor de leitura já é realizado na classe 'Temperatura' que fornece um rand para o método setValor da classe 'Sensor'
      // a data tbm gera automatico -> pega do sistema operacional
    }

    case 3: // 3 - Consultar
    {
      cout << "Digite o ID do sensor de Temperatura: " << endl;
      cin >> b_id;

      cout << "Digite os limites do intervalo de temperatura (temp1 a temp2) em graus Celsius" << endl;
      cout << "Temperatura 1: ";
      cin >> b_temp1;
      cout << "Temperatura 2: ";
      cin >> b_temp2;

      temperatura.get_Consulta_temperatura(b_temp1, b_temp2);
      break;
    }

    case 4: // 4 - Listar todas as leituras de 1 ID
    {
      temperatura.get_Listagem_temperaturas();
    }
    break;

    case 5: // Excluir
    {

      cout << "Digite o numero de identificacao (ID): ";
      cin >> b_id;

      cout << "Voce deseja excluir um ou todos os registros?";
      cout << "1 - Apenas um registro do sensor" << endl;
      cout << "2 - Todos os registros do sensor" << endl;
      cin >> b_temp2;

      if (b_temp2 == 2)
      {
        temperatura.Exclui_temperatura(b_temp1, 0, true);
        break;
      }
      else
      {
        cout << "Digite a temperatura que deseja excluir: ";
        cin >> b_temp1;
        temperatura.Exclui_temperatura(b_temp1, b_temp1, false);
        break;
      }
    }
      // --------------- Pressão ---------------
    }
  }
  return 0;
}