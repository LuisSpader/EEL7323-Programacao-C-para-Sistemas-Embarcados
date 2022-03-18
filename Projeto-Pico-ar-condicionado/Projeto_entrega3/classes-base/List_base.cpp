/*
   File List_base.cpp

   Class List_base stores Nodes (class Node) in a linked list.
   
   This file has the implementation for class List_base

   Class list is definition for a linked list, having the following operations:

   1. Initialize the list to an empty list.
   2. Free the nodes of a list.
   3. Determine whether a list is empty.
   4. Add a node with a given value into the list following
      the first node with another given value.
   5. Add a node with a given value to the front of the list.
   6. Add a node with a given value to the end of the list.
   7. Delete the first node from the list.

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 8 de outubro de 2015.

*/

#include "List_base.h"

List_base::List_base() {
   head = 0;
}

List_base::~List_base() {
  Node* cursor = head;
  while(head) {
    cursor = cursor->getNext();
    delete head;
    head = cursor;
  }
  head = 0; // Officially empty
}

// void List_base::insertBeforeFirst(int temp) {
//   head = new Node(temp, head);
// }

// void List_base::insertAfterLast(int temp) {
//   Node* p = head;
//   Node* q = head;
//   if (head == 0)
//      head = new Node(temp, head);
//   else {
//      while (q != 0) {
//         p = q;
//         q = p->getNext();
//      }
//      p->setNext(new Node(temp,0));
//   }
// }

void List_base::readFirst() {
   cout << head->get_temp_int(); 
}

int List_base::removeFirst() {
  int retval = 0;
  if (head != 0){
     retval = head->get_temp_int();
     Node* oldHead = head;
     head = head->getNext();
     delete oldHead;
  }
  return retval;
}

// void List_base::insertionSort(int value) {
//   Node* p = head;
//   Node* q = head;
//   if (head == 0)
//   {
//      head = new Node(value,head);
// 	 int i;
// 	 i = head->get_temp_int();
//   }
//   else
//   {
// 	  int pint;
// 	  int auxint;
// 	  pint = q->get_temp_int();
// 	  auxint = pint;
// 	  while ((q != 0) && (auxint < value))
// 	  {
// 		  p = q;
// 		  q = p->getNext();
// 		  if (q != 0)
// 		  {
// 			pint = q->get_temp_int();
// 			auxint = pint;
// 		  }
// 	  }
// 	  if (p == q)
// 		  head = new Node(value,head);
// 	  else
// 			p->setNext(new Node(value,q));
//   }
// }

int List_base::removeNode(int temp) {
  Node* p = head;
  Node* q = head;
  int result;

  if (head == 0)
     result = 0;
  else {
	  while ((q != 0) && (q->get_temp_int() != temp)){  // Error!! the addresses will always be different!
		  p = q;
		  q = p->getNext();
	  }
	  if (q != 0) {
		  if (q == head){	// it is the first node
			  result = q->get_temp_int();
			  head = q->getNext();
			  delete q;
		  }
		  else{				// the node is in the middle
			  result = q->get_temp_int();
			  p->setNext(q->getNext());
			  delete q;
		  }
	  }
	  else
		  result = 0;		// node not found!
  }

  return result;
}

void List_base::listAll() {
  Node* aux = head;
  while (aux != 0){
     cout << aux->get_temp_int() << endl;
     aux = aux->getNext();
  }
}

void List_base::RemoveAll(){
  Node_pico *aux = head;
  while (aux != 0){ // enquanto não chega no último nodo (que aponta para '0')
    delete aux;
    aux = aux->getNext(); 
  }
}