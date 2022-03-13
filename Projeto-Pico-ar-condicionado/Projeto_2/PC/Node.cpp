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
//
Node::Node(int dat, Node* nxt){
       ID = dat;
       next = nxt;
}

// getTemp_ext returns the integer value stored in the node
//
int Node::getTemp_ext(){
     return ID;
}

// getNext returns a pointer for the next node in the linked list
//
Node* Node::getNext(){
     return next;
}

// setTemp_ext stores the integer value in the node
//
void Node::setTemp_ext(int dat){
     ID = dat;
}

// setNext stores the pointer to the next node in the list in the "next" field
//
void Node::setNext(Node* nxt){
       next = nxt;
}
