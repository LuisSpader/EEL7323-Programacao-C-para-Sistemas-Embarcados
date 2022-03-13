/*
   File Node_base.cpp

   Class Node_base

   Class Node_base stores integer values for a linked list.

   This file has the implementation for the Node_base's interface.

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 8 de outubro de 2015.

*/

#include <string.h>
// #include "Node_base.h"
#include "headers.h"

class Node_base :
{
  int ID; // nodo armazenará ID do aparelho para log de eventos
  int temp_ext, temp_int; //temperaturas
  bool automatico_ou_botao; // para sabermos se a mudanca foi automatica ou devido à requisição do usuario (pressionou botão): 1 = automatico | 0= botão

  Node_base *next; // ponteiro para próximo Nodo

public:
  Node_base(int new_ID, int new_temp_ext, int new_temp_int, bool new_automatico_ou_botao, Node_PC *nxt); // construtor do Nodo

  // --------- SET ---------
  void set_ID(int new_ID); // atualiza ID do Nodo
  void set_temp_ext(int new_temp_ext);
  void set_temp_int(int new_temp_int);
  void set_automatico_ou_botao(bool new_automatico_ou_botao);
  void setNext(Node_base *nxt); // atualiza ponteiro

  // --------- GET ---------
  int get_ID(); // Retorna valor salvo no Nodo

  // temperatura
  int get_temp_int();
  int get_temp_ext();
  int get_new_temp_int();
  int get_automatico_ou_botao(); // acionamento pelo tensorflow ou botao

  virtual void get_All_Data();
  Node_base *getNext(); // retorna valor do ponteiro
  void changeNode_manual() = 0; //virtual pura
};

Node_base::Node_base(int new_ID, int new_temp_ext, int new_temp_int, bool new_automatico_ou_botao, Node_PC *nxt)
{ // externos
  ID = new_ID;
  temp_int = new_temp_int;
  automatico_ou_botao = new_automatico_ou_botao;
  next = nxt;

  // internos ao nó
  temp_ext = new_temp_ext;
  
//   ClockCalendar(new_data, new_hora);
}

// --------- SET ---------
void Node_base::set_ID(int new_ID)
{
  ID = new_ID;
}

void Node_base::set_temp_ext(int new_temp_ext)
{
    temp_ext = new_temp_ext;
}

void Node_base::set_temp_int(int new_temp_int)
{
  temp_int = new_temp_int;
}


void Node_base::set_automatico_ou_botao(bool new_automatico_ou_botao)
{
  automatico_ou_botao = new_automatico_ou_botao;
}

// setNext stores the pointer to the next node in the list in the "next" field
void Node_base::setNext(Node_base *nxt)
{
  next = nxt;
}

void Node_base::changeNode_manual(string new_data, string new_hr, int new_ID, int new_temp_ext, int new_temp_int, bool new_automatico_ou_botao, Node_base *nxt)
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

int Node_base::get_ID()
{
  return ID;
}

int Node_base::get_temp_ext()
{
  return temp_ext;
}

int Node_base::get_temp_int()
{
  return temp_int;
}

int Node_base::get_automatico_ou_botao()
{
  return automatico_ou_botao;
}

void Node_base::get_All_Data()
{
//   ClockCalendar::getCalendarString();
//   ClockCalendar::getClockString();
  get_ID();
  get_temp_ext();
  get_temp_int();
  get_automatico_ou_botao();
}