// #include <iostream>  // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
// #include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
// using namespace std; // Esse comando é utilizado de forma a evitar a isndicação std:: antes de usar o comando cout, etc...

// #include "hardware/rtc.h"
// #include "pico/stdlib.h"
// #include "pico/util/datetime.h"

#include <string.h>
// #include <cstring>
// #include <list>
#include <ctime> // para usar time()
//-----------------
#include "Clock.cpp"
#include "Calendar.cpp"

using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

class ClockCalendar : public Clock, public Calendar
{
private:
  bool was_pm;

public:
  // string str_data_hora
  string data, hora;

  void advance();

  ClockCalendar();
  void setClockCalendar_timelib();
  void set_fixo_ClockCalendarString();

  string getClockString();
  string getCalendarString();
  bool Data1EhMAIORqueData2(string data1, string data2);
  bool Data1EhMENORqueData2(string data1, string data2);

  bool Hora1EhMAIORqueHora2(string hora1, string hora2);
  bool Hora1EhMENORqueHora2(string hora1, string hora2);
};

ClockCalendar::ClockCalendar()
{
  Clock();    // assim já iniciamos com um valor dado de hora
  Calendar(); // assim já iniciamos com um valor dado de data

  time_t now = time(0);
  tm *ltm = localtime(&now);

  hr = ltm->tm_hour;
  min = ltm->tm_min;
  sec = ltm->tm_sec;

  dia = ltm->tm_mday;
  mes = ltm->tm_mon;
  ano = (ltm->tm_year) + 1900;

  Calendar::setCalendarString();  // salva data atual
  Clock::setClockString();        // salva hora atual
  set_fixo_ClockCalendarString(); // salva hora e data numa string só
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

void ClockCalendar::setClockCalendar_timelib()
{
  Calendar::setStringToDate("15/12/2021");
}

void ClockCalendar::set_fixo_ClockCalendarString()
{
  // stringstream buffer;
  // buffer << str_data.str() << " - " << str_hora.str();
  // str_data_hora = buffer.str();
  // // return str_data_hora.str();
  // stringstream buffer;
  // buffer << str_data.str();
  // data = buffer.str();

  // buffer << str_hora.str();
  // hora = buffer.str();

  data = str_data.str(); // aqui deixamos uma data fixa (momento de aquisição)
  hora = str_hora.str(); // aqui deixamos uma hora fixa (momento de aquisição)
}

string ClockCalendar::getClockString()
{
  return hora;
}

string ClockCalendar::getCalendarString()
{
  return data;
}

bool ClockCalendar::Data1EhMAIORqueData2(string data1, string data2)
{
  tuple<int, int, int> buffer1, buffer2; // tupla com os valores: dia, mes, ano
  buffer1 = setStringToDate(data1);      // recebendo os valores
  buffer2 = setStringToDate(data2);

  if (get<2>(buffer1) > get<2>(buffer2))
  {
    return true; // se ano eh maior, data ja eh maior
  }
  else // se ano eh igual ou menor, iremos analisar qual dos dois eh
  {
    // ano = (get2), mes = (get1), dia = (get0)
    if (get<2>(buffer1) == get<2>(buffer2)) // se ano eh igual, iremos analisar pelo mes e dia
    {
      if (get<1>(buffer1) > get<1>(buffer2)) // ano igual, mes maior
      {
        return true; // se mes eh maior, data ja eh maior
      }
      else // mes igual ou menor
      {
        if (get<1>(buffer1) == get<1>(buffer2)) // ano igual, mes igual
        {
          if (get<0>(buffer1) >= get<0>(buffer2)) // ano igual, mes igual, dia maior ou igual
          {
            return true;
          }
          else
          { // ano igual, mes igual, dia menor
            return false;
          }
        }
        else // ano igual, mes menor
        {
          return false; // se mes eh maior, data ja eh maior
        }
      }
    }
    else // se ano eh menor, data ja eh menor
    {
      return false;
    }
  }
}

bool ClockCalendar::Data1EhMENORqueData2(string data1, string data2)
{
  tuple<int, int, int> buffer1, buffer2; // tupla com os valores: dia, mes, ano
  buffer1 = setStringToDate(data1);      // recebendo os valores
  buffer2 = setStringToDate(data2);

  if (get<2>(buffer1) < get<2>(buffer2))
  {
    return true; // se ano eh menor, data ja eh menor
  }
  else // se ano eh igual ou maior, iremos analisar qual dos dois eh
  {
    // ano = (get2), mes = (get1), dia = (get0)
    if (get<2>(buffer1) == get<2>(buffer2)) // se ano eh igual, iremos analisar pelo mes e dia
    {
      if (get<1>(buffer1) < get<1>(buffer2)) // ano igual, mes menor
      {
        return true; // se mes eh menor, data ja eh menor
      }
      else // mes igual ou maior
      {
        if (get<1>(buffer1) == get<1>(buffer2)) // ano igual, mes igual
        {
          if (get<0>(buffer1) <= get<0>(buffer2)) // ano igual, mes igual, dia menor ou igual
          {
            return true;
          }
          else
          { // ano igual, mes igual, dia maior
            return false;
          }
        }
        else // ano igual, mes maior
        {
          return false; // se mes eh maior, data ja eh maior
        }
      }
    }
    else // se ano eh maior, data ja eh maior
    {
      return false;
    }
  }
}

bool ClockCalendar::Hora1EhMAIORqueHora2(string hora1, string hora2)
{
  tuple<int, int, int> buffer1, buffer2;   // tupla com os valores: hora, min, seg
  buffer1 = setStringToTime(hora1, false); // recebendo os valores
  buffer2 = setStringToTime(hora2, false);

  if (get<0>(buffer1) > get<0>(buffer2))
  {
    return true; // se ano eh maior, data ja eh maior
  }
  else // se ano eh igual ou menor, iremos analisar qual dos dois eh
  {
    // ano = (get2), mes = (get1), dia = (get0)
    if (get<0>(buffer1) == get<0>(buffer2)) // se ano eh igual, iremos analisar pelo mes e dia
    {
      if (get<1>(buffer1) > get<1>(buffer2)) // ano igual, mes maior
      {
        return true; // se mes eh maior, data ja eh maior
      }
      else // mes igual ou menor
      {
        if (get<1>(buffer1) == get<1>(buffer2)) // ano igual, mes igual
        {
          if (get<2>(buffer1) >= get<2>(buffer2)) // ano igual, mes igual, dia maior ou igual
          {
            return true;
          }
          else
          { // ano igual, mes igual, dia menor
            return false;
          }
        }
        else // ano igual, mes menor
        {
          return false; // se mes eh maior, data ja eh maior
        }
      }
    }
    else // se ano eh menor, data ja eh menor
    {
      return false;
    }
  }
}

bool ClockCalendar::Hora1EhMENORqueHora2(string hora1, string hora2)
{
  tuple<int, int, int> buffer1, buffer2;   // tupla com os valores: dia, mes, ano
  buffer1 = setStringToTime(hora1, false); // recebendo os valores
  buffer2 = setStringToTime(hora2, false);

  if (get<0>(buffer1) < get<0>(buffer2))
  {
    return true; // se ano eh menor, data ja eh menor
  }
  else // se ano eh igual ou maior, iremos analisar qual dos dois eh
  {
    // ano = (get2), mes = (get1), dia = (get0)
    if (get<0>(buffer1) == get<0>(buffer2)) // se ano eh igual, iremos analisar pelo mes e dia
    {
      if (get<1>(buffer1) < get<1>(buffer2)) // ano igual, mes menor
      {
        return true; // se mes eh menor, data ja eh menor
      }
      else // mes igual ou maior
      {
        if (get<1>(buffer1) == get<1>(buffer2)) // ano igual, mes igual
        {
          if (get<2>(buffer1) <= get<2>(buffer2)) // ano igual, mes igual, dia menor ou igual
          {
            return true;
          }
          else
          { // ano igual, mes igual, dia maior
            return false;
          }
        }
        else // ano igual, mes maior
        {
          return false; // se mes eh maior, data ja eh maior
        }
      }
    }
    else // se ano eh maior, data ja eh maior
    {
      return false;
    }
  }
}