/*
   File main.cpp

   Test program for Node and List classes.

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 8 de outubro de 2015.

*/

// #include "List.cpp"
#include "List_temp_fixa.cpp"


int main()
{

  List lista1, lista2; // aqui já inicia os construtores das listas, que estão definidos para zerar os Nodos
  int saida;

  lista1.insertBeforeFirst(5); // inclui '5' antes do primeiro -> 5,head
  //   void List::insertBeforeFirst(int dat = 5)
  // {
  //   head = new Node(dat = 5, head= 0); // ?? pq o 'new' aloca espaço de forma dinâmica??
  // } // ?? o 'new' retorna o endereço de onde o novo 'nodo' foi criado
  // ----
  //   Node::Node(int dat = 5, Node *nxt = head = 0)
  // {
  //   val = dat = 5;
  //   next = nxt = 0 (aponta para 0);
  // }
  lista1.insertBeforeFirst(0); // inclui '0' antes do '5' -> 0,5,head
  lista1.insertAfterLast(10);  // inclui '10' após o '5'  -> 0,5,head,10

  cout << "Primeiro nodo contem: " << lista1.readFirst() << endl;

  lista1.insertionSort(4); // inclui '4' entre 0 e 5  -> 0,4,5,10

  lista1.listAll();

  cout << "Digite F para finalizar o programa" << endl;

  cin >> saida;

  return 0;
}

// --------------------
// #include <iostream>  // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
// #include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
// using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

// #include <string.h> // Para trabalhar com strings
// // #include <cstring>
// // #include <list>

// #include "Clock.cpp"
// #include "Calendar.cpp"

// using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

// class ClockCalendar : public Clock, public Calendar
// {
// private:
//   bool was_pm;

// public:
//   // Construtor: inicia classe
//   // ClockCalendar(int h, int s, int m, bool pm, int d, int mo, int a);
//   // ClockCalendar(int h, int m, int s, bool pm, string date_buffer);
//   // ClockCalendar(string hour_buffer, int pm, string date_buffer);
//   ClockCalendar();
//   void setClock_timelib();

//   void advance();
// };
