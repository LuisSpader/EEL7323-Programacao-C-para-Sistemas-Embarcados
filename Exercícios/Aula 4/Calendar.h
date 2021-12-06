//---------------------------- LIBRARIES ------------------------ //
#include <string.h> // Para trabalhar com strings
#include <iostream> // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
// #include <string.h>  // Para trabalhar com strings
#include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

class Calendar
{
private:
  int dia, mes, ano;

public:
  Calendar(int d, int m, int a); // construtor

  void Calendar::setCalendar(int d, int m, int a);
  void Calendar::readCalendar();
  void Calendar::advance();
};