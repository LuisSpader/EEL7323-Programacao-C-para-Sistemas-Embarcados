/*
   File Node.cpp

   Class Node

   Class Node stores integer values for a linked list.

   This file has the implementation for the Node's interface.

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 8 de outubro de 2015.

*/

#include "Node.h"

// Constructor - initializes the node
Node::Node(int new_ID,
           int new_temp,
           bool new_automatico_ou_botao,
           Node *nxt)
{
  ID = new_ID;
  temp = new_temp;
  automatico_ou_botao = new_automatico_ou_botao;
  next = nxt;

  // data_hora = getClockCalendar();
  // data_hora = clock_calendar.getClockCalendarString();
}

// --------- GET ---------
string Node::getClockCalendar()
// string Node::getClockCalendar(Controle *p)
// string Node::getClockCalendar()
{
  // Controle *p;
  int h, m, s, d, m, a;
  // h = p->hr;
  // m = p->min;
  // s = p->sec;

  // d = p->dia;
  // m = p->mes;
  // a = p->ano;

  h = hr;
  m = min;
  s = sec;

  d = dia;
  m = mes;
  a = ano;

  // obj_data_horario.readClock();
}

int Node::get_ID()
{
  return ID;
}

int Node::get_temp()
{
  return temp;
}

int Node::get_automatico_ou_botao()
{
  return automatico_ou_botao;
}

int Node::get_All_Data()
{
  get_ID();
  get_temp();
  get_automatico_ou_botao();
}

// getNext returns a pointer for the next node in the linked list
Node *Node::getNext()
{
  return next;
}

// --------- SET ---------
void Node::set_ID(int new_ID)
{
  ID = new_ID;
}

void Node::set_temp(int new_temp)
{
  temp = new_temp;
}

void Node::set_automatico_ou_botao(bool new_automatico_ou_botao)
{
  automatico_ou_botao = new_automatico_ou_botao;
}

// setNext stores the pointer to the next node in the list in the "next" field
void Node::setNext(Node *nxt)
{
  next = nxt;
}