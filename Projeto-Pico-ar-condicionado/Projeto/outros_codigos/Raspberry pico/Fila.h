/*
   File Fila.h

*/

#include "Nodo.cpp"
#include <stdio.h>

class Fila{

  Node* head; //aponta para o primeiro elemento da lista

public:
  Fila();
  ~Fila();
  //void insertBeforeFirst(int dat);
  void insertAfterLast(string newID, string newDate, string newHour); //Add new at row
  string readFirstID();
  string readFirstDate();
  string readFirstHour();
  string removeFirst(); //Remove first at row
  //void insertionSort(int value);
  //int removeNode(int dat);
  //void listAll();
};