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
#include "headers.h"
#include <string.h>
#include "ClockCalendar.h"

class Node : virtual public ClockCalendar
{
  int ID;                   // nodo armazenará ID do aparelho para log de eventos
  int temp;                 // valor que o nodo armazena -> temperatura
  bool automatico_ou_botao; // para sabermos se a mudanca foi automatica ou devido à requisição do usuario (pressionou botão): 1 = automatico | 0= botão

  string data_hora; // aqui será armazenada toda a informação de data e hora;
  // ClockCalendar horario_data; // INSERIR CLOCK CALENDAR -> analisar como a hora será inicializada/sincronizada // salvar objetos com dados já dentro do nó (para o acesso ao ClockCalendar ser só durante o evento, mas não durante a transmissão dos logs)
  ClockCalendar clock_calendar;

  Node *next; // ponteiro para próximo Nodo

public:
  Node(int new_ID, int new_temp, bool new_automatico_ou_botao, Node *nxt); // construtor do Nodo

  string getClockCalendar();

  // --------- GET ---------
  int get_ID(); // Retorna valor salvo no Nodo
  int get_temp();
  int get_automatico_ou_botao();
  int get_All_Data();
  Node *getNext(); // retorna valor do ponteiro

  // --------- SET ---------
  void set_ID(int new_ID); // atualiza ID do Nodo
  void set_temp(int new_temp);
  void set_automatico_ou_botao(bool new_automatico_ou_botao);

  void setNext(Node *nxt); // atualiza ponteiro
};

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
  data_hora = clock_calendar.str_data_hora;
}

// --------- GET ---------
string Node::getClockCalendar()
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