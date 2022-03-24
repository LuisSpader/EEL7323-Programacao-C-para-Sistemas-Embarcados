// #include <iostream>  // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
// #include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
// using namespace std; // Esse comando é utilizado de forma a evitar a isndicação std:: antes de usar o comando cout, etc...

// #include "hardware/rtc.h"
// #include "pico/stdlib.h"
// #include "pico/util/datetime.h"

using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

class ClockCalendar_PC : public ClockCalendar_base
{
private:

public:
  ClockCalendar_PC(string new_data, string new_hora);

};

ClockCalendar_PC::ClockCalendar_PC(string new_data, string new_hora)
{
  Clock(new_hora);    // assim já iniciamos com um valor dado de hora
  Calendar(new_data); // assim já iniciamos com um valor dado de data

  Calendar::setCalendarString();  // salva data atual em formato "xx/xx/xxxx"
  Clock::setClockString();        // salva hora atual em formato "xx:xx:xx"
  set_fixo_ClockCalendarString(); // salva hora e data numa string só
}
