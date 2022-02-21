// #include <iostream>  // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
// #include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
// using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

// #include <string.h>  // Para trabalhar com strings
// #include <cstring>
// #include <list>
#include <ctime> // para usar time()
#include "ClockCalendar.h"

#include "hardware/rtc.h"
#include "pico/stdlib.h"
#include "pico/util/datetime.h"

ClockCalendar::ClockCalendar()
{

  Clock();    // assim já iniciamos com um valor dado de hora
  Calendar(); // assim já iniciamos com um valor dado de data
}

void ClockCalendar::setClockCalendar_timelib()
{

  time_t now = time(0);
  tm *ltm = localtime(&now);

  hr = ltm->tm_hour;
  min = ltm->tm_min;
  sec = ltm->tm_sec;

  dia = ltm->tm_mday;
  mes = ltm->tm_mon;
  ano = ltm->tm_year;

  Calendar::setStringToDate("15/12/2021");
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