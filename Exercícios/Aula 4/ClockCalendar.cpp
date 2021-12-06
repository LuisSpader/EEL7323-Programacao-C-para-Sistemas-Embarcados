

#include "ClockCalendar.h"

ClockCalendar::ClockCalendar(int h, int s, int min, bool pm, int d, int m, int a)
{
  Clock::Clock(int h, int s, int min, bool pm); // assim já iniciamos com um valor dado de hora
  Calendar::Calendar(int d, int m, int a);      // assim já iniciamos com um valor dado de data
}

ClockCalendar::advance()
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