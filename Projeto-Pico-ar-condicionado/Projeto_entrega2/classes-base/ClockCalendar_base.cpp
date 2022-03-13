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
//-----------------
#include "Clock.cpp"
#include "Calendar.cpp"
#include <math.h>
#include <cmath>

using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

class ClockCalendar_base : public Clock, public Calendar
{
private:

public:
  string data, hora;

  ClockCalendar_base();
  void setClockCalendar_timelib();
  void set_fixo_ClockCalendarString();

  string getClockString();
  string getCalendarString();
  friend tuple<int, int> IntervaloData_emhoras(string data1, string data2, string hora1, string hora2);

};

ClockCalendar_base::ClockCalendar_base()
{
}

void ClockCalendar_base::setClockCalendar_timelib()
{
  Calendar::setStringToDate("15/12/2021");
}

void ClockCalendar_base::set_fixo_ClockCalendarString()
{
  data = str_data.str(); // aqui deixamos uma data fixa (momento de aquisição)
  hora = str_hora.str(); // aqui deixamos uma hora fixa (momento de aquisição)
}

string ClockCalendar_base::getClockString()
{
  return hora;
}

string ClockCalendar_base::getCalendarString()
{
  return data;
}

// -----------------------------------------------------
tuple<int, int> IntervaloData_emhoras(string data1, string data2, string hora1, string hora2)
{
  // IntervaloData_emhoras(): De acordo com 2 datas e 2 horarios retorna a diferença em horas
  Calendar obj_calendar;
  tuple<int, int, int> buffer1, buffer2, bf3;    // tupla com os valores: dia, mes, ano
  buffer1 = obj_calendar.setStringToDate(data1); // recebendo os valores
  buffer2 = obj_calendar.setStringToDate(data2);
  // get<0>(buffer): ano,  get<1>(buffer): mes,  get<2>(buffer): dia

  double intervalo = (get<0>(buffer2) - get<0>(buffer1)) * 365; // dif em dias de 1 ano para outro

  intervalo = intervalo + (get<1>(buffer2) - get<1>(buffer1)) * 30; // dif em dias de 1 mes para outro

  intervalo = intervalo + (get<2>(buffer2) - get<2>(buffer1)); // dif em dias de 1 para outro

  // agora que temos os dias totais, multiplicando por 24 para obter as horas totais

  intervalo = intervalo * 24; // intervalo em horas
  intervalo = intervalo * 60; // intervalo em minutos

  // intervalo = intervalo * 60; // intervalo em segundos

  Clock obj_clock;

  // get<0>: hora,  get<1>: minuto,  get<2>: segundo
  buffer1 = obj_clock.ClockInterval(hora2, hora1); // hora2 - hora1
  double minutos, horas;

  minutos = get<0>(buffer1) * 60 + get<0>(buffer1) + (get<0>(buffer1) / 60); // unindo minutos totais em uma variavel

  intervalo = intervalo + minutos; // total_minutos + minutos(hora2 - hora1) = total minutos (final)

  horas = intervalo / 60;

  minutos = std::modf(horas, &horas); // decimal = minutos, inteiros = horas
  minutos = minutos * 60;             // tinhamos os decimais de horas (que sao os minutos em formato de horas), logo devemos passar para formato de minutos (*60)

  return make_tuple(horas, minutos);
}
