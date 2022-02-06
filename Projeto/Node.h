/*
   File Node.h

   Class Node

   Class Node stores integer values for a linked list.

   This file has the Node's interface (header file).

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 8 de outubro de 2015.

*/

#include "headers.h"
#include <string.h> // Para trabalhar com strings

class Node
{
  int ID;                   // nodo armazenará ID do aparelho para log de eventos
  int temp;                 // valor que o nodo armazena -> temperatura
  bool automatico_ou_botao; // para sabermos se a mudanca foi automatica ou devido à requisição do usuario (pressionou botão): 1 = automatico | 0= botão

  Node *next; // ponteiro para próximo Nodo

public:
  Node(int new_ID, int new_temp, bool new_automatico_ou_botao, Node *nxt); // construtor do Nodo

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