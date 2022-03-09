#include <iomanip>
#include <stdlib.h> // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
#include <iostream> // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
#include <string.h>


// Função: Verifica se é número
bool isNumber(const string &str)
{
      for (char const &c : str)
      {
            if (std::isdigit(c) == 0)
                  return false;
      }
      return true;
}
