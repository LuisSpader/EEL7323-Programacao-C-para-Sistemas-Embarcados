#include <iostream>  // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
#include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

#include <string.h> // Para trabalhar com strings
// #include <cstring>
// #include <list>

// #include "classe_para_herdar.cpp"
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

class ClockCalendar : public Clock, public Calendar
{
public:
  ClockCalendar(); // Construtor: inicia classe
  void advance();
};
