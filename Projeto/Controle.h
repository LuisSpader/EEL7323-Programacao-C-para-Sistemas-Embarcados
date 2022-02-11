#include <iostream>  // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
#include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

#include <string.h> // Para trabalhar com strings
// #include <cstring>
// #include <list>

#include "ClockCalendar.cpp"

class Controle
{
private:
  bool was_pm;
  ClockCalendar data_horario;

public:
  friend class Node; // assim 'Node' acessa este único objeto que está
  friend string getClockCalendar();

  // dentro da classe 'Controle' Controle();
};
