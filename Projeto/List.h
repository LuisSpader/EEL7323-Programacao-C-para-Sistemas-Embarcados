/*
   File List.h

   Header file for class list

   Class List stores Nodes (class Node) in a linked list.

   This file has the List's interface (header file).

   Class list is definition for a linked list, having the following operations:

   1. Initialize the list to an empty list.
   2. Free the nodes of a list.
   3. Determine whether a list is empty.
   4. (NOT YET!) Add a node with a given value into the list following
      the first node with another given value.
   5. Add a node with a given value to the front of the list.
   6. Add a node with a given value to the end of the list.
   7. Delete the first node from the list.

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 8 de outubro de 2015.

*/
// Fila: 2 eventos:
// •O ar-condicionado foi ajustado devido à variações na temperatura externa.
// •Um dos botões de ajuste foi pressionado, quando o usuário informou que não estava satisfeito com a temperatura atual.
// Na ocorrência de cada um desses eventos, deverá ser incluído um novo nodo na fila contendo:
// ID do controlador (cada equipamento possui um ID único);
// data/hora do evento (usar o clock/calendar desenvolvido anteriormente).

#include "Node.cpp"

class List
{

  Node *head;

public:
  List(); // construtor -> ao construir cria objeto 'Node': head = 0;
  ~List();

  void create_first_Node(int new_ID, int new_temp, bool new_automatico_ou_botao);

  void insertBeforeFirst(int new_ID, int new_temp, bool new_automatico_ou_botao);
  void insertAfterLast(int new_ID, int new_temp, bool new_automatico_ou_botao);

  int readFirst();
  int removeFirst();

  void insertionSort(int new_ID, int new_temp, bool new_automatico_ou_botao);
  int removeNode(int temp);
  void listAll();

  void List::setID(int newID);
};