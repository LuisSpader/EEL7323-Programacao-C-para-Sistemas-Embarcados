/*
   File List_base.h

   Header file for class list

   Class List_base stores Nodes (class Node) in a linked list.
   
   This file has the List_base's interface (header file).

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

#include "Node_base.cpp"

class List_base {

  Node_base* head;

public:
  List_base();
  ~List_base();
  void create_first_Node() = 0; //virtual pura
  virtual void insertBeforeFirst() = 0; //virtual pura: força implementação em cada classe 'filho'
  virtual void insertAfterLast() = 0;   //virtual pura
  virtual void readFirst();              
  int removeFirst();           
  virtual void insertionSort() = 0;     //virtual pura
  virtual int removeNode(int temp);     //herdada e utilizada
  virtual void listAll();  //utilizada no embarcado | nova implementação no List_PC
  void RemoveAll();                     //herdada e utilizada
  void printNode() = 0;

};
