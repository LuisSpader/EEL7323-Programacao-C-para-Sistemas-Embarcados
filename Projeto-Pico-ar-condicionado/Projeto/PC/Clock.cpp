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
#include <string>
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
      Clock(string new_hora); // construtor
      void setTime(int hour, int minute, int second);
      tuple<int, int, int> setStringToTime(string hour_buffer, bool pm);
      void readClock(); //
      void setClockString();
      void advance();

      tuple<int, int, int> ClockInterval(string h1, string h2);

      bool Hora1EhMAIORqueHora2(string hora1, string hora2);
      bool Hora1EhMENORqueHora2(string hora1, string hora2);
      friend bool operator>=(string hora1, string hora2);
      friend bool operator<=(string hora1, string hora2);
};

Clock::Clock(string new_hora = "00:00:00")
{
      tuple<int, int, int> buffer;
      buffer = setStringToTime(new_hora, 0);
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

tuple<int, int, int> Clock::ClockInterval(string h1, string h2)
{
      tuple<int, int, int> buffer1, buffer2;
      buffer1 = setStringToTime(h1, false);
      buffer2 = setStringToTime(h2, false);
      int h, m, s, total;
      h = get<0>(buffer1) - get<0>(buffer2);
      m = get<1>(buffer1) - get<1>(buffer2);
      s = get<2>(buffer1) - get<2>(buffer2);

      // h = abs(h);
      // m = abs(m);
      // s = abs(s);
      total = (h * 360) + (m * 60) + s; // total em segundos

      h = static_cast<int>(total / 360);
      m = static_cast<int>(total / 360);
      s = total - h;

      return make_tuple(h, m, s);
      // stringstream str;
      // str << h << ":" << m << ":" << s;
      // // return str.str();
      // string retorno = str.str();
      // return retorno;
}

bool Clock::Hora1EhMAIORqueHora2(string hora1, string hora2)
{
      Clock obj_clock;
      tuple<int, int, int> buffer1, buffer2;             // tupla com os valores: hora, min, seg
      buffer1 = obj_clock.setStringToTime(hora1, false); // recebendo os valores
      buffer2 = obj_clock.setStringToTime(hora2, false);
      // get<0>: hora,  get<1>: minuto,  get<2>: segundo

      if (get<0>(buffer1) > get<0>(buffer2))
      {
            return true; // se hora eh maior, data ja eh maior
      }
      else // se hora eh igual ou menor, iremos analisar qual dos dois eh
      {
            // hora = (get2), minuto = (get1), segundo = (get0)
            if (get<0>(buffer1) == get<0>(buffer2)) // se hora eh igual, iremos analisar pelo minuto e segundo
            {
                  if (get<1>(buffer1) > get<1>(buffer2)) // hora igual, minuto maior
                  {
                        return true; // se minuto eh maior, data ja eh maior
                  }
                  else // minuto igual ou menor
                  {
                        if (get<1>(buffer1) == get<1>(buffer2)) // hora igual, minuto igual
                        {
                              if (get<2>(buffer1) >= get<2>(buffer2)) // hora igual, minuto igual, segundo maior ou igual
                              {
                                    return true;
                              }
                              else
                              { // hora igual, minuto igual, segundo menor
                                    return false;
                              }
                        }
                        else // hora igual, minuto menor
                        {
                              return false; // se minuto eh maior, data ja eh maior
                        }
                  }
            }
            else // se hora eh menor, data ja eh menor
            {
                  return false;
            }
      }
}

bool Clock::Hora1EhMENORqueHora2(string hora1, string hora2)
{
      Clock obj_clock;
      tuple<int, int, int> buffer1, buffer2;             // tupla com os valores: segundo, minuto, hora
      buffer1 = obj_clock.setStringToTime(hora1, false); // recebendo os valores
      buffer2 = obj_clock.setStringToTime(hora2, false);
      // get<0>: hora,  get<1>: minuto,  get<2>: segundo

      if (get<0>(buffer1) < get<0>(buffer2))
      {
            return true; // se hora eh menor, data ja eh menor
      }
      else // se hora eh igual ou maior, iremos analisar qual dos dois eh
      {
            // hora = (get2), minuto = (get1), segundo = (get0)
            if (get<0>(buffer1) == get<0>(buffer2)) // se hora eh igual, iremos analisar pelo minuto e segundo
            {
                  if (get<1>(buffer1) < get<1>(buffer2)) // hora igual, minuto menor
                  {
                        return true; // se minuto eh menor, data ja eh menor
                  }
                  else // minuto igual ou maior
                  {
                        if (get<1>(buffer1) == get<1>(buffer2)) // hora igual, minuto igual
                        {
                              if (get<2>(buffer1) <= get<2>(buffer2)) // hora igual, minuto igual, segundo menor ou igual
                              {
                                    return true;
                              }
                              else
                              { // hora igual, minuto igual, segundo maior
                                    return false;
                              }
                        }
                        else // hora igual, minuto maior
                        {
                              return false; // se minuto eh maior, data ja eh maior
                        }
                  }
            }
            else // se hora eh maior, data ja eh maior
            {
                  return false;
            }
      }
}

// -------------- Operadores para hora --------------
bool operator>=(Clock &c1, string c2)
{
      return c1.Hora1EhMAIORqueHora2(c1.str_hora.str(), c2);
}

bool operator<=(Clock &c1, string c2)
{
      return c1.Hora1EhMENORqueHora2(c1.str_hora.str(), c2);
}
