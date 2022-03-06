/*
   File Node_temp_fixa.cpp

   Class Node_temp_fixa

   Class Node_temp_fixa stores integer values for a linked list.

   This file has the implementation for the Node_temp_fixa's interface.

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 8 de outubro de 2015.

*/

#include <string.h>
// #include "Node_temp_fixa.h"
#include "headers.h"
#include "ClockCalendar.cpp"
// #include "Sensor_Temperatura_DHT11.cpp"

class Node_temp_fixa : public ClockCalendar
{
  int ID; // nodo armazenará ID do aparelho para log de eventos
  int temp_ext, temp_int;
  bool automatico_ou_botao; // para sabermos se a mudanca foi automatica ou devido à requisição do usuario (pressionou botão): 1 = automatico | 0= botão

  // string data_hora;

  // ClockCalendar clock_calendar;

  Node_temp_fixa *next; // ponteiro para próximo Nodo

public:
  Node_temp_fixa(int new_ID, int new_temp, bool new_automatico_ou_botao, Node_temp_fixa *nxt); // construtor do Nodo

  string getClockCalendar();

  // --------- SET ---------
  void set_ID(int new_ID); // atualiza ID do Nodo
  void set_temp_ext(int new_temp);
  void set_automatico_ou_botao(bool new_automatico_ou_botao);
  void setNext(Node_temp_fixa *nxt); // atualiza ponteiro

  // --------- GET ---------
  int get_ID(); // Retorna valor salvo no Nodo
  // temperatura
  int get_temp_int();
  int get_temp_ext();
  int get_new_temp_int();

  int get_automatico_ou_botao(); // acionamento pelo tensorflow ou botao
  // string get_DataHora();
  void get_All_Data();
  // string get_All_DataString();
  Node_temp_fixa *getNext(); // retorna valor do ponteiro
  void changeNode_manual(string new_data, string new_hr, int new_ID, int new_temp_int, bool new_automatico_ou_botao, Node_temp_fixa *nxt);
};

// Constructor - initializes the node
Node_temp_fixa::Node_temp_fixa(int new_ID, int new_temp_int, bool new_automatico_ou_botao, Node_temp_fixa *nxt)
{ // externos
  ID = new_ID;
  temp_int = new_temp_int;
  automatico_ou_botao = new_automatico_ou_botao;
  next = nxt;

  // internos ao nó
  temp_ext = 30;
  // data_hora = clock_calendar.str_data_hora;
}

// --------- SET ---------
void Node_temp_fixa::set_ID(int new_ID)
{
  ID = new_ID;
}

void Node_temp_fixa::set_automatico_ou_botao(bool new_automatico_ou_botao)
{
  automatico_ou_botao = new_automatico_ou_botao;
}

// setNext stores the pointer to the next node in the list in the "next" field
void Node_temp_fixa::setNext(Node_temp_fixa *nxt)
{
  next = nxt;
}

void Node_temp_fixa::changeNode_manual(string new_data, string new_hr, int new_ID, int new_temp_int, bool new_automatico_ou_botao, Node_temp_fixa *nxt)
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

int Node_temp_fixa::get_ID()
{
  return ID;
}

int Node_temp_fixa::get_temp_ext()
{
  return temp_ext;
}

int Node_temp_fixa::get_temp_int()
{
  return temp_int;
}

int Node_temp_fixa::get_new_temp_int() // APAGAR
{
  return temp_int;
}

int Node_temp_fixa::get_automatico_ou_botao()
{
  return automatico_ou_botao;
}

void Node_temp_fixa::get_All_Data()
{
  // get_DataHora();
  ClockCalendar::getCalendarString();
  ClockCalendar::getClockString();
  get_ID();
  get_temp_ext();
  get_new_temp_int();
  get_automatico_ou_botao();
}

// string Node_temp_fixa::get_All_DataString()
// {
//   stringstream buffer;
//   string buffer_string;
//   buffer << data_hora << " | " << ID << " | " << temp_ext << " | " << automatico_ou_botao << " | " << endl;
//   buffer_string = buffer.str();
//   return buffer_string;
// }

// getNext returns a pointer for the next node in the linked list
Node_temp_fixa *Node_temp_fixa::getNext()
{
  return next;
}
