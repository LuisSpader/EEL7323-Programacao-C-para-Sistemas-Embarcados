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
#include <string.h>
#include <iomanip>
#include <stdlib.h> // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
#include <iostream> // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
#include <tuple>

using namespace std;
// #include <iostream>  // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++

class Clock
{
protected:
      int hr, min, sec;
      bool is_pm;

public:
      stringstream str_hora;
      Clock(); // construtor
      void setTime(int hour, int minute, int second);
      tuple<int, int, int> setStringToTime(string hour_buffer, bool pm);
      void readClock(); //
      void setClockString();
      void advance();
      string ClockInterval(string h1, string h2);
};

Clock::Clock()
{
      tuple<int, int, int> buffer;
      buffer = setStringToTime("00:00:00", 0);
      setTime(get<0>(buffer), get<1>(buffer), get<2>(buffer));
      // setStringToTime("00:00:00", 0);
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

void Clock::setTime(int hour, int minute, int second)
{
      hr = hour;
      min = minute;
      sec = second;
}

tuple<int, int, int> Clock::setStringToTime(string hour_buffer, bool pm = 0)
{
      string temp;
      int b_seg, b_min, b_hora;

      if (hour_buffer.length() > 8)
      {
            cout << "Digits limit exceeded! \n";
            exit(EXIT_FAILURE);
      }

      // HORA
      temp = hour_buffer.substr(0, 2);
      if (isNumber(temp) == true)
      {
            b_hora = std::stoi(temp);
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
            b_min = std::stoi(temp);
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
            b_seg = std::stoi(temp);
      }
      else
      {
            cout << "Invalid second \n";
            exit(EXIT_FAILURE);
      }

      is_pm = (pm ? true : false);
      return make_tuple(b_hora, b_min, b_seg);
}

void Clock::readClock()
{
      cout << setw(2) << setfill('0') << hr << ":"
           << setw(2) << setfill('0') << min << ":"
           << setw(2) << setfill('0') << sec;
}

void Clock::setClockString()
{
      str_hora << setw(2) << setfill('0') << hr << ":"
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

string Clock::ClockInterval(string h1, string h2)
{
      tuple<int, int, int> buffer1, buffer2;
      buffer1 = setStringToTime(h1, false);
      buffer2 = setStringToTime(h2, false);
      int h, m, s;
      h = get<0>(buffer1) - get<0>(buffer2);
      m = get<1>(buffer1) - get<1>(buffer2);
      s = get<2>(buffer1) - get<2>(buffer2);

      h = abs(h);
      m = abs(m);
      s = abs(s);

      stringstream str;
      str << h << ":" << m << ":" << s;
      // return str.str();
      string retorno = str.str();

      // cout << get<0>(buffer1) << " - " << get<0>(buffer2) << endl;
      // cout << get<1>(buffer1) << " - " << get<1>(buffer2) << endl;
      // cout << get<2>(buffer1) << " - " << get<2>(buffer2) << endl;

      // cout << h << ":" << m << ":" << s << endl;
      // cout << retorno << endl;
      return retorno;
}