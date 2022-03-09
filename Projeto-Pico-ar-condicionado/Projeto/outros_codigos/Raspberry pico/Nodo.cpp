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

#include "Nodo.h"
#include <iostream>

// Constructor - initializes the node
//
Node::Node(string newID, string newDate, string newHour, Node* nxt){
       ID = newID;
       Date = newDate;
       Hour  = newHour;
       next = nxt;
}

// getID returns the integer value stored in the node
//
string Node::getID(){
     return ID;
}
// getDate returns the string stored in the node
//

string Node::getDate(){
    return Date;
}

string Node::getHour(){
    return Hour;
}
// getNext returns a pointer for the next node in the linked list
//
Node* Node::getNext(){
     return next;
}

// setID stores the integer value in the node
//
void Node::setID(string newID){
     ID = newID;
}
// setDate stores the string in the node
//
void Node::setDate(string newDate){
    Date = newDate;
}

void Node::setHour(string newHour){
     Hour = newHour;
}

// setNext stores the pointer to the next node in the list in the "next" field
//
void Node::setNext(Node* nxt){
       next = nxt;
}