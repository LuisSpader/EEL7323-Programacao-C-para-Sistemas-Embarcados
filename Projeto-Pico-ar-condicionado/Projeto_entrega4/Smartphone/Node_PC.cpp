/*
   File Node_PC.cpp

   Class Node_PC

   Class Node_PC stores integer values for a linked list.

   This file has the implementation for the Node_PC's interface.

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 8 de outubro de 2015.

*/

#include <string.h>
#include "Node_base.cpp"
#include "headers.h"
#include "ClockCalendar_PC.cpp"
// #include "Sensor_Temperatura_DHT11.cpp"

class Node_PC : public Node_base, public ClockCalendar_PC
{
public:
  Node_PC(string new_data, string new_hora, int new_ID, int new_temp_ext, int new_temp_int, bool new_automatico_ou_botao, Node_PC *nxt); // construtor do Nodo

  void get_All_Data();
  void changeNode_manual(string new_data, string new_hr, int new_ID, int new_temp_int, bool new_automatico_ou_botao, Node_PC *nxt);
};

// Constructor - initializes the node
Node_PC::Node_PC(string new_data, string new_hora, int new_ID, int new_temp_ext, int new_temp_int, bool new_automatico_ou_botao, Node_PC *nxt): ClockCalendar_PC(new_data, new_hora)
{ // externos
  ID = new_ID;
  temp_int = new_temp_int;
  automatico_ou_botao = new_automatico_ou_botao;
  next = nxt;

  // internos ao nó
  temp_ext = new_temp_ext;
  
  ClockCalendar_PC(new_data, new_hora);

}

// --------- SET ---------
void Node_PC::changeNode_manual(string new_data, string new_hr, int new_ID, int new_temp_ext, int new_temp_int, bool new_automatico_ou_botao, Node_PC *nxt)
{
  data = new_data;
  hora = new_hr;

  // externos
  ID = new_ID;
  temp_int = new_temp_int;
  automatico_ou_botao = new_automatico_ou_botao;
  next = nxt;

  // internos ao nó
  temp_ext = new_temp_ext;
}

// --------- GET ---------
void Node_PC::get_All_Data()
{
  // get_DataHora();
  ClockCalendar_PC::getCalendarString();
  ClockCalendar_PC::getClockString();
  get_ID();
  get_temp_ext();
  get_new_temp_int();
  get_automatico_ou_botao();
}