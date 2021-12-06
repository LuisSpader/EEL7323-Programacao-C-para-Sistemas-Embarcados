//---------------------------- LIBRARIES ------------------------ //
#include <string.h> // Para trabalhar com strings
#include <iostream> // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
// #include <string.h>  // Para trabalhar com strings
#include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

//---------------------------- Functions ------------------------ //
// mes, dia, ano
#include "Calendar.h"

void Calendar::Calendar(int d, int m, int a)
{ // construtor da classe
  dia = d;
  mes = m;
  ano = a;
}
void Calendar::setCalendar(int d, int m, int a)
{
  if (d > 30)
  {
    cout << "dia invalido" << endl;
  }
  else if (m > 12)
  {
    cout << "mes invalido" << endl;
  }
  else
  {
    dia = d;
    mes = m;
    ano = a;
  }
}
void Calendar::readCalendar()
{
  cout << "Dia/Mes/Ano: " << dia << "/" << mes << "/" << ano << endl;
}
void Calendar::advance()
{
  if (dia >= 30)
  {
    if (mes >= 12)
    {
      ano++;
      mes = 0;
      dia = 0;
    }
    else
      (dia >= 30)
      {
        mes++;
        dia = 0;
      }
  }
  else
  {
    dia++;
  }
}