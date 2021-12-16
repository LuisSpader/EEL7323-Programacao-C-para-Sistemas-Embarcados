#include <iostream>  // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
#include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

#include <string.h> // Para trabalhar com strings
// #include <cstring>
// #include <list>

#include "ClockCalendar.cpp"

int main()
{
  // int minuto, hora;
  // int dia, mes, ano;

  bool b_pm;
  string buffer_hora, buffer_data;

  cout << "Digite a data atual XX/XX/XXXX (dia/mes/ano): " << endl;
  cin >> buffer_data;

  cout << "Digite o am-pm: \n se for am, digite '0'; \n se for pm digite '1'; " << endl;
  cin >> b_pm;

  cout << "Digite o horario (hora min segundo): \n **valor de hora de 0 a 12" << endl;
  cin >> buffer_hora;

  ClockCalendar obj_data_horario(buffer_hora, b_pm, buffer_data); //(int h, int m, int s, bool pm, int d, int mo, int a) : Clock(h, m, s, pm), Calendar(d, mo, a)

  // obj_data_horario.setStringToDate(buffer_data);
  // obj_data_horario.setClock(hora, minuto, 0, b_pm); //(int h, int m, int s, bool pm)

  // cout << "Data (dia/mes/ano): " << obj_data_horario.dia << "/" << obj_data_horario.mes << "/" << obj_data_horario.ano << endl;
  // cout << "Hora (hora:min:segundo): " << obj_data_horario.hr << "/" << obj_data_horario.min << "/" << obj_data_horario.sec << endl;

  obj_data_horario.readCalendar();
  obj_data_horario.readClock();

  // obj_data_horario.advance(); // chama advance do ClockCalendar
};