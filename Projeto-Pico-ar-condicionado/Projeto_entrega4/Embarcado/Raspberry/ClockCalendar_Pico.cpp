// #include <iostream>  // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
// #include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
// using namespace std; // Esse comando é utilizado de forma a evitar a isndicação std:: antes de usar o comando cout, etc...

// #include "hardware/rtc.h"
// #include "pico/stdlib.h"
// #include "pico/util/datetime.h"
// Raspberry

#include <string.h>
// #include <cstring>
// #include <list>
#include <ctime> // para usar time()
//-----------------
#include "ClockCalendar_base.cpp"

#include <math.h>
#include <cmath>

using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

class ClockCalendar_Pico : public ClockCalendar_base
{
private:

public:

  ClockCalendar_Pico();
};

ClockCalendar_Pico::ClockCalendar_Pico()
{
  Clock();    // iniciamos com 'default'
  Calendar(); // iniciamos com 'default'

  // abaixo pegamos a hora (construtor já salva hora de construção)
  time_t now = time(0);
  tm *ltm = localtime(&now);

  hr = ltm->tm_hour;
  min = ltm->tm_min;
  sec = ltm->tm_sec;

  dia = ltm->tm_mday;
  mes = ltm->tm_mon + 1;
  ano = (ltm->tm_year) + 1900;

  Calendar::setCalendarString();  // salva data atual
  Clock::setClockString();        // salva hora atual
  set_fixo_ClockCalendarString(); // salva hora e data numa string só
}
