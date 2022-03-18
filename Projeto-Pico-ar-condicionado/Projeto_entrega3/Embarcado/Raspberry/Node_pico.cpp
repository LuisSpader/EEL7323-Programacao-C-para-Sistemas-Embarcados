/*
   File Node_pico.cpp

   Class Node_pico

   Class Node_pico stores integer values for a linked list.

   This file has the implementation for the Node_pico's interface.

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 8 de outubro de 2015.

*/

#include <string.h>
// #include "Node_pico.h"
#include "headers.h"
#include "ClockCalendar_Pico.cpp"
// #include "Sensor_Temperatura_DHT11.cpp"

class Node_pico : protected Node_base, public ClockCalendar_Pico
{
public:
  Node_pico(int new_ID, int new_temp, bool new_automatico_ou_botao, Node_pico *nxt); // construtor do Nodo

  string getClockCalendar();
  void get_All_Data();
  void changeNode_manual(string new_data, string new_hr, int new_ID, int new_temp_int, bool new_automatico_ou_botao, Node_pico *nxt);
};

// Constructor - initializes the node
Node_pico::Node_pico(int new_ID, int new_temp_int, bool new_automatico_ou_botao, Node_pico *nxt)
{ // externos
  ID = new_ID;
  temp_int = new_temp_int;
  automatico_ou_botao = new_automatico_ou_botao;
  next = nxt;

  // internos ao nó
  temp_ext = 30;
}

// --------- SET ---------
void Node_pico::changeNode_manual(string new_data, string new_hr, int new_ID, int new_temp_int, bool new_automatico_ou_botao, Node_pico *nxt)
{
  data = new_data;
  hora = new_hr;

  // externos
  ID = new_ID;
  temp_int = new_temp_int;
  automatico_ou_botao = new_automatico_ou_botao;
  next = nxt;

  // internos ao nó
  temp_ext = 30;
}

// --------- GET ---------
void Node_pico::get_All_Data()
{
  // get_DataHora();
  ClockCalendar_Pico::getCalendarString();
  ClockCalendar_Pico::getClockString();
  get_ID();
  get_temp_ext();
  get_new_temp_int();
  get_automatico_ou_botao();
}

// string Node_pico::get_All_DataString()
// {
//   stringstream buffer;
//   string buffer_string;
//   buffer << data_hora << " | " << ID << " | " << temp_ext << " | " << automatico_ou_botao << " | " << endl;
//   buffer_string = buffer.str();
//   return buffer_string;
// }
