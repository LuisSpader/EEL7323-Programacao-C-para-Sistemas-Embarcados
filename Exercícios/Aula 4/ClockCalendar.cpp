// #include <iostream>  // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
// #include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
// using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

// #include <string.h>  // Para trabalhar com strings
// #include <cstring>
// #include <list>

#include "ClockCalendar.h"

// ClockCalendar::ClockCalendar(int h, int m, int s, bool pm, string date_buffer) : Clock(h, m, s, pm), Calendar(date_buffer)
ClockCalendar::ClockCalendar(string hour_buffer, int pm, string date_buffer) : Clock(hour_buffer, pm), Calendar(date_buffer)

{
  // was_pm = false;
  // o jeito abaixo também funcionaria, porém aí temos que tirar do cabeçalho deste construtor a parte a seguir: ": Clock(h, s, m, pm), Calendar(d, mo, a)"
  // Clock::Clock(int h, int s, int m, bool pm); // assim já iniciamos com um valor dado de hora
  // Calendar::Calendar(int d, int mo, int a);   // assim já iniciamos com um valor dado de data
}

void ClockCalendar::advance()
{
  int was_pm = is_pm; // variável 'is_pm' herdamos da classe Clock
  // note que pegamos a variável antes de avançar o clock
  // quando passamos da meia noite, fazemos is_pm: 1 -> 0
  // logo teremos: was_pm = 1 e is_pm = 0
  Clock::advance();
  if (was_pm && !is_pm)
  {
    Calendar::advance();
  }
}