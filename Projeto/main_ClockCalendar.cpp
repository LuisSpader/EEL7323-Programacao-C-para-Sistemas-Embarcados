#include <iostream>  // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
#include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

#include <string.h> // Para trabalhar com strings
// #include <cstring>
// #include <list>

#include "ClockCalendar.cpp"

int main()
{
  bool b_pm;
  string buffer_data_hora;

  ClockCalendar obj_data_horario;

  cout << obj_data_horario.str_data_hora;
};