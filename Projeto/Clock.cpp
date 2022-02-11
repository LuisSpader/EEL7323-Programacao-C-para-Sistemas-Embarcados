/*
 * Autor: Eduardo Augusto Bezerra
 * Instituicao: UFSC
 * Data: 18/11/2021
 * Arquivo: Clock.cpp
 * Descricao: Classe Clock a ser usada no exemplo ClockCalendar (heranca multipla)
 *
 * Compilado no Linux Ubuntu 20.04.3 LTS
 *
 * Linha de comando: g++ -o xxx xxx.cpp
 *
 */
#include <iomanip>
#include <stdlib.h> // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
#include <iostream> // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++

using namespace std;
// #include <iostream>  // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++

class Clock
{
protected:
      int hr, min, sec;
      bool is_pm;

public:
      // Clock(int h, int m, int s, int pm); // construtor
      // Clock(string hour_buffer, int pm); // construtor
      // Clock(string buffer_h); // construtor
      Clock(); // construtor

      // void setClock(int h, int m, int s, int pm);
      void setStringToTime(string hour_buffer, int pm);
      void readClock(); //
      void advance();
};

// Clock::Clock(int h, int m, int s, int pm)
// Clock::Clock(string buffer_h)
Clock::Clock()
{
      // setClock(h, m, s, pm);
      setStringToTime("00:00:00", 0);
}

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
void Clock::setStringToTime(string hour_buffer, int pm)
{
      string temp;

      if (hour_buffer.length() > 8)
      {
            cout << "Digits limit exceeded! \n";
            exit(EXIT_FAILURE);
      }

      // HORA
      temp = hour_buffer.substr(0, 2);
      if (isNumber(temp) == true)
      {
            hr = std::stoi(temp);
      }
      else
      {
            cout << "Invalid hour\n";
            exit(EXIT_FAILURE);
      }

      // MINUTO
      temp = hour_buffer.substr(3, 2);
      if (isNumber(temp) == true)
      {
            min = std::stoi(temp);
      }
      else
      {
            cout << "Invalid min \n";
            exit(EXIT_FAILURE);
      }

      // SEGUNDO
      temp = hour_buffer.substr(6, 4);
      if (isNumber(temp) == true)
      {
            sec = std::stoi(temp);
      }
      else
      {
            cout << "Invalid second \n";
            exit(EXIT_FAILURE);
      }

      is_pm = (pm ? true : false);

      // setClock(hr, min, sec);
}

// void Clock::setClock(int h, int m, int s, int pm)
// {
//       hr = h;
//       min = m;
//       sec = s;
//       is_pm = (pm ? true : false);
//       // switch (pm)
//       // {
//       // case 0:
//       //       is_pm = false;
//       //       break;

//       // case 'pm':
//       //       is_pm = true;
//       //       break;

//       // default:
//       //       cout << "Invalid am-pm";
//       //       break;
//       // }
// }

void Clock::readClock()
{
      cout << setw(2) << setfill('0') << hr << ":"
           << setw(2) << setfill('0') << min << ":"
           << setw(2) << setfill('0') << sec;
}

void Clock::advance()
{
      sec++;
      if (sec >= 60)
      {
            sec = 0;
            min++;
            if (min >= 60)
            {
                  min = 0;
                  hr++;
                  if (hr >= 13)
                        hr = 1; // hr = 01:00 PM
                  else if (hr >= 12)
                  {
                        if (is_pm)      // passou da meia-noite?
                              hr = 0;   // hr = 00:00 AM
                        is_pm = !is_pm; // muda para AM ou PM, dependendo do horario
                  }
            }
      }
}
