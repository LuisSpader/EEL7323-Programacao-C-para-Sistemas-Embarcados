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

#include <string.h>
// #include "Node.h"
#include "headers.h"
#include "ClockCalendar.cpp"
#include "Sensor_Temperatura_DHT11.cpp"

class Node
{
  int ID;                   // nodo armazenará ID do aparelho para log de eventos
  int temp_ext, temp_int;   // valor que o nodo armazena -> temperatura
  bool automatico_ou_botao; // para sabermos se a mudanca foi automatica ou devido à requisição do usuario (pressionou botão): 1 = automatico | 0= botão

  string data_hora; // aqui será armazenada toda a informação de data e hora;
  // ClockCalendar horario_data; // INSERIR CLOCK CALENDAR -> analisar como a hora será inicializada/sincronizada // salvar objetos com dados já dentro do nó (para o acesso ao ClockCalendar ser só durante o evento, mas não durante a transmissão dos logs)
  ClockCalendar clock_calendar;

  Node *next; // ponteiro para próximo Nodo

public:
  Node(int new_ID, int new_temp, bool new_automatico_ou_botao, Node *nxt); // construtor do Nodo

  string getClockCalendar();

  // --------- SET ---------
  void set_ID(int new_ID); // atualiza ID do Nodo
  void set_temp_ext(int new_temp);
  void set_automatico_ou_botao(bool new_automatico_ou_botao);
  void setNext(Node *nxt); // atualiza ponteiro

  // --------- GET ---------
  int get_ID(); // Retorna valor salvo no Nodo
  // temperatura
  int get_temp_ext();
  int get_new_temp_int();

  int get_automatico_ou_botao(); // acionamento pelo tensorflow ou botao
  string get_DataHora();
  void get_All_Data();
  string get_All_DataString();
  Node *getNext(); // retorna valor do ponteiro
};

// Constructor - initializes the node
Node::Node(int new_ID, int new_temp_int, bool new_automatico_ou_botao, Node *nxt)
{ // externos
  ID = new_ID;
  temp_int = new_temp_int;
  automatico_ou_botao = new_automatico_ou_botao;
  next = nxt;
  // internos ao nó
  set_temp_ext();
  data_hora = clock_calendar.str_data_hora;
}

// --------- SET ---------
void Node::set_ID(int new_ID)
{
  ID = new_ID;
}

void Node::set_temp_ext()
{
  // temp_ext = new_temp;
  temp_ext = Sensor_Temperatura_DHT11.getTemp();
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
// --------- GET ---------

int Node::get_ID()
{
  return ID;
}

int Node::get_temp_ext()
{
  return temp_ext;
}

int Node::get_new_temp_int()
{
  return temp_int;
}

string Node::get_DataHora()
{
  return data_hora;
}

int Node::get_automatico_ou_botao()
{
  return automatico_ou_botao;
}

void Node::get_All_Data()
{
  get_DataHora();
  get_ID();
  get_temp_ext();
  get_new_temp_int();
  get_automatico_ou_botao();
}

string Node::get_All_DataString()
{
  stringstream buffer;
  string buffer_string;
  buffer << data_hora << " | " << ID << " | " << temp_ext << " | " << automatico_ou_botao << " | " << endl;
  buffer_string = buffer.str();
  return buffer_string;
}

// getNext returns a pointer for the next node in the linked list
Node *Node::getNext()
{
  return next;
}
