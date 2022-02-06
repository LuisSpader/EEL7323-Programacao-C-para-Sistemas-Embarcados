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

class Node
{

  int val;    // valor que o nodo armazena
  Node *next; // ponteiro para próximo Nodo

public:
  Node(int dat, Node *nxt); // construtor do Nodo
  int getVal();             // Retorna valor salvo no Nodo
  Node *getNext();          // retorna valor do ponteiro
  void setVal(int dat);     // atualiza valor do Nodo
  void setNext(Node *nxt);  // atualiza ponteiro
};