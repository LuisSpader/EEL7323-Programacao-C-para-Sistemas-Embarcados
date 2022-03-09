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
#include "ClockCalendar.cpp"
#include <iostream>
#include <stdio.h>
#include <string>

//#include "headers.h"
using namespace std;
class Node {

    string ID;
    string Date;
    string Hour;
    Node* next;

  public:
         
    Node(string newID, string newDate, string newHour, Node* nxt);
    string getID();
    string getDate();
    string getHour();
    Node* getNext();
    void setID(string newID);
    void setDate(string newDate);
    void setHour(string newHour);
    void setNext(Node* nxt);
};