#include <iostream>  // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
#include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

// #include <string.h> // Para trabalhar com strings
// #include <cstring>
// #include <list>
#include "Controle.h"

#include "ClockCalendar.cpp"

#include <string.h> // Para trabalhar com strings
// #include <cstring>
// #include <list>

#include "ClockCalendar.cpp"

class Controle
{
private:
  bool was_pm;
  // ClockCalendar data_horario;

public:
  friend class Node; // assim 'Node' acessa este único objeto que está
  // friend string getClockCalendar();

  // dentro da classe 'Controle' Controle();
};

Controle::Controle()
{
  data_horario.setClock_timelib(); // tem que trocar pra pegar de algum outro jeito
}

// ------------------------------------------------------
// int main()
// {
//   // int minuto, hora;
//   // int dia, mes, ano;
//   bool b_pm;
//   string buffer_hora, buffer_data;
//   cout << "Digite a data atual XX/XX/XXXX (dia/mes/ano): " << endl;
//   cin >> buffer_data;
//   cout << "Digite o am-pm: \n se for am, digite '0'; \n se for pm digite '1'; " << endl;
//   cin >> b_pm;
//   cout << "Digite o horario (hora:min:segundo): \n **valor de hora de 0 a 12" << endl;
//   cin >> buffer_hora;
//   ClockCalendar obj_data_horario(buffer_hora, b_pm, buffer_data); // nesta versão aprimorada passamos 3 dados:
//   obj_data_horario.readCalendar();
//   obj_data_horario.readClock();
//   // obj_data_horario.advance(); // chama advance do ClockCalendar
// };