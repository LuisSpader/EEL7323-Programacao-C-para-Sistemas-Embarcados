// #include <iostream>  // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
// #include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
// using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

// #include <string.h>  // Para trabalhar com strings
// #include <cstring>
// #include <list>
#include <ctime> // para usar time()
#include "ClockCalendar.h"

// ClockCalendar::ClockCalendar(int h, int m, int s, bool pm, string date_buffer) : Clock(h, m, s, pm), Calendar(date_buffer)
// ClockCalendar::ClockCalendar(string hour_buffer, int pm, string date_buffer) : Clock(hour_buffer, pm), Calendar(date_buffer)
// ClockCalendar::ClockCalendar(string buffer_time)
ClockCalendar::ClockCalendar()
{
  // // Www Mmm dd hh:mm:ss yyyy
  // string buffer_d, buffer_h;
  // buffer_d = (buffer_time.substr(4, 2));
  // buffer_h = (buffer_time.substr(0, 2));

  Clock();    // assim já iniciamos com um valor dado de hora
  Calendar(); // assim já iniciamos com um valor dado de data
}

void ClockCalendar::setClock_timelib()
{
  // string buffer;
  // buffer = time(0); // Www Mmm dd hh:mm:ss yyyy
  // Calendar::setStringToDate(buffer.substr(0, 2));

  time_t now = time(0);
  // struct tm *horariolocal;
  tm *ltm = localtime(&now);
  // time(&t);
  // horariolocal = localtime(&t);

  hr = ltm->tm_hour;
  min = ltm->tm_min;
  sec = ltm->tm_sec;

  dia = ltm->tm_mday;
  mes = ltm->tm_mon;
  ano = ltm->tm_year;

  Calendar::setStringToDate("15/12/2021");
  // Clock::setStringToTime("18:15:00", 0);
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