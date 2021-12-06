#include <iostream>  // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
#include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

#include <string.h> // Para trabalhar com strings
// #include <cstring>
// #include <list>

#include "Calendar.cpp"

int main()
{
  string buffer_data;

  cout << "Digite a data atual XX/XX/XXXX (dia/mes/ano): " << endl;
  cin >> buffer_data;

  Calendar data(buffer_data);

  data.readCalendar();

  // Calendar::advance(); // chama advance do ClockCalendar

  return 0;
}