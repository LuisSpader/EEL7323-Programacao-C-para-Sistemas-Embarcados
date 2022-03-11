/*
   File main.cpp

   Test program for Node and List_PC classes.

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 8 de outubro de 2015.

*/

#include "List_PC.cpp"

int main()
{

  List_PC lista1(18250065), lista2(18250066);
  int saida;

  lista1.insertAfterLast("10/03/2021", "20:42:00", 27, false);

  // In Unix you can use usleep. In Windows there is Sleep.
  // #include <unistd.h>
  // unsigned int microseconds;
  // usleep(microseconds);

  lista1.insertAfterLast("10/03/2021", "20:45:00",26, false);
  lista1.insertBeforeFirst("10/03/2021", "20:47:00",28, false);

  cout << "Primeiro nodo contem: " << lista1.readFirst() << endl;

  lista1.listAll();
  string hora1_t, hora2_t, data1_t, data2_t;

// teste 'listInterval()
  hora1_t = "08:00:00";
  hora2_t = "22:00:00";
  while (true)
  {
    cout << "-----" << endl;
    // cout << "hora init: ";
    // cin >> hora1_t;
    // cout << "hora end: ";
    // cin >> hora2_t;
    cout << "data init: ";
    cin >> data1_t;
    cout << "data end: ";
    cin >> data2_t;
    lista1.listInterval(data1_t, data2_t, hora1_t, hora2_t);
    // lista1.listInterval(data1_t, data2_t);

  }
  // lista1.listInterval(data_fixa, "02/04/2022");

  // cout << "Tempo ligado: " << lista1.TempoLigado() << endl;

  // ----------
  // lista1.
  string data_fixa = "10/03/2022";
  string data_t, hora_t;
  cout << data_fixa << endl;
  while (true) // data
  {
    cout << "-----" << endl;
    cout << "data: ";
    cin >> data_t;
    if (data_t < data_fixa)
    {
      cout << data_t << " < " << data_fixa << endl;
    }
    else
    {
      cout << data_t << " > " << data_fixa << endl;
    }

    // ------
    // if (data_t > data_fixa)
    // {
    //   cout << data_t << " > " << data_fixa << endl;
    // }
    // else
    // {
    //   cout << data_t << " < " << data_fixa << endl;
    // }
  }

  // while (true) // hora
  // {
  //   cout << lista1.ClockCalendar::hora << endl;
  //   cout << "hora:";
  //   cin >> hora_t;

  //   if (lista1.ClockCalendar::hora > hora_t)
  //   {
  //     cout << "true" << endl;
  //   }
  //   else
  //   {
  //     cout << "false" << endl;
  //   }
  // }

  cin >> saida;
  cout << "Digite F para finalizar o programa" << endl;
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
