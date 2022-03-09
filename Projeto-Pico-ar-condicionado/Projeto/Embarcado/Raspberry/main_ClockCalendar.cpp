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
  tuple<int, int> bf1;

  ClockCalendar obj_data_horario;

  cout << "Data: " << obj_data_horario.data << endl;
  if (obj_data_horario.Data1EhMENORqueData2(obj_data_horario.data, "02/02/2022") == true)
  {
    cout << "true";
  }
  else
  {
    cout << "false";
  }
  cout << "-----" << endl;
  // ----------------------------------------------
  string hora_teste = "22:24:37";
  cout << "Hora: " << obj_data_horario.hora << " eh menor que " << hora_teste << endl;
  if (obj_data_horario.Hora1EhMENORqueHora2(obj_data_horario.hora, hora_teste) == true)
  {
    cout << "true";
  }
  else
  {
    cout << "false";
  }
  cout << "-----" << endl;
  // ----------------------------------------------
  // obj_data_horario.ClockInterval(obj_data_horario.hora, hora_teste);
  bf1 = IntervaloData_emhoras("01/01/2021", obj_data_horario.data, "08:00:00", obj_data_horario.hora);

  cout << "Intervalo: " << get<0>(bf1) << " horas e " << get<1>(bf1) << " minutos" << endl;
};