//---------------------------- LIBRARIES ------------------------ //
#include <string.h>
#include <iostream>
// #include <string.h>  // Para trabalhar com strings
#include <stdlib.h>
using namespace std;
#include <iomanip>
#include <tuple>

class Calendar
{
protected:
  int dia, mes, ano;

public:
  stringstream str_data;

  Calendar(); // construtor
  tuple<int, int, int> setStringToDate(string date_buffer);
  void setCalendar(int d, int mo, int a);
  void readCalendar();
  void setCalendarString();
  void advance();
  bool Data1EhMAIORqueData2(string data1, string data2);
  bool Data1EhMENORqueData2(string data1, string data2);

  friend bool operator>=(string data1, string data2);
  friend bool operator<=(string data1, string data2);
};

// ------------------- Construtor ------------------- //
Calendar::Calendar()
{
  tuple<int, int, int> buffer;
  buffer = setStringToDate("00/00/0000");
  // setCalendar(b_dia, b_mes, b_ano);
  setCalendar(get<0>(buffer), get<1>(buffer), get<2>(buffer));
}

// ------------------- Logic Functions ------------------- //

// Função: Verifica se é número
// bool isNumber(const string &str)
// {
//   for (char const &c : str)
//   {
//     if (std::isdigit(c) == 0)
//       return false;
//   }
//   return true;
// }

// ------------------- SET -------------------
tuple<int, int, int> Calendar::setStringToDate(string date_buffer)
{
  string temp;
  int b_dia, b_mes, b_ano;

  if (date_buffer.length() > 10)
  {
    cout << "Digits limit exceeded! \n";
    exit(EXIT_FAILURE);
  }

  // DIA
  temp = date_buffer.substr(0, 2);
  if (isNumber(temp) == true)
  {
    b_dia = std::stoi(temp);
  }
  else
  {
    cout << "Invalid day\n";
    exit(EXIT_FAILURE);
  }

  // MÊS
  temp = date_buffer.substr(3, 2);
  if (isNumber(temp) == true)
  {
    b_mes = std::stoi(temp);
  }
  else
  {
    cout << "Invalid month \n";
    exit(EXIT_FAILURE);
  }

  // ANO
  temp = date_buffer.substr(6, 4);
  if (isNumber(temp) == true)
  {
    b_ano = std::stoi(temp);
  }
  else
  {
    cout << "Invalid year \n";
    exit(EXIT_FAILURE);
  }
  // date = date_buffer.substr(0, 2) + "/" + date_buffer.substr(3, 2) + "/" + date_buffer.substr(6, 4);
  return make_tuple(b_dia, b_mes, b_ano);
}

void Calendar::setCalendar(int d, int mo, int a)
{
  if (d > 30)
  {
    cout << "Invalid day" << endl;
  }
  else if (mo > 12)
  {
    cout << "Invalid month" << endl;
  }
  else
  {
    dia = d;
    mes = mo;
    ano = a;
  }
}

void Calendar::readCalendar()
{
  cout //<< "Data (dia/mes/ano): "
      << setw(2) << setfill('0') << dia << "/"
      << setw(2) << setfill('0') << mes << "/"
      << setw(4) << setfill('0') << ano;
}

void Calendar::setCalendarString()
{
  str_data //<< "Data (dia/mes/ano): "
      << setw(2) << setfill('0') << dia << "/"
      << setw(2) << setfill('0') << mes << "/"
      << setw(4) << setfill('0') << ano;
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

bool Calendar::Data1EhMAIORqueData2(string data1, string data2)
{
  Calendar obj_calendar;
  tuple<int, int, int> buffer1, buffer2;         // tupla com os valores: dia, mes, ano
  buffer1 = obj_calendar.setStringToDate(data1); // recebendo os valores
  buffer2 = obj_calendar.setStringToDate(data2);
  // get<0>: ano,  get<1>: mes,  get<2>: dia

  // cout << "get0: " << get<0>(buffer1) << endl;
  // cout << "get1: " << get<1>(buffer1) << endl;
  // cout << "get2: " << get<2>(buffer1) << endl;

  if (get<2>(buffer1) > get<2>(buffer2))
  {
    return true; // se ano eh maior, data ja eh maior
  }
  else // se ano eh igual ou menor, iremos analisar qual dos dois eh
  {
    // ano = (get2), mes = (get1), dia = (get0)
    if (get<2>(buffer1) == get<2>(buffer2)) // se ano eh igual, iremos analisar pelo mes e dia
    {
      if (get<1>(buffer1) > get<1>(buffer2)) // ano igual, mes maior
      {
        return true; // se mes eh maior, data ja eh maior
      }
      else // mes igual ou menor
      {
        if (get<1>(buffer1) == get<1>(buffer2)) // ano igual, mes igual
        {
          if (get<0>(buffer1) > get<0>(buffer2)) // ano igual, mes igual, dia maior
          {
            return true;
          }
          else
          { // ano igual, mes igual, dia menor ou igual
            return false;
          }
        }
        else // ano igual, mes menor
        {
          return false; // se mes eh maior, data ja eh maior
        }
      }
    }
    else // se ano eh menor, data ja eh menor
    {
      return false;
    }
  }
}

bool Calendar::Data1EhMENORqueData2(string data1, string data2)
{
  Calendar obj_calendar;
  tuple<int, int, int> buffer1, buffer2;         // tupla com os valores: dia, mes, ano
  buffer1 = obj_calendar.setStringToDate(data1); // recebendo os valores
  buffer2 = obj_calendar.setStringToDate(data2);
  // get<0>(buffer): ano,  get<1>(buffer): mes,  get<2>(buffer): dia

  if (get<2>(buffer1) < get<2>(buffer2))
  {
    return true; // se ano eh menor, data ja eh menor
  }
  else // se ano eh igual ou maior, iremos analisar qual dos dois eh
  {
    // ano = (get2), mes = (get1), dia = (get0)
    if (get<2>(buffer1) == get<2>(buffer2)) // se ano eh igual, iremos analisar pelo mes e dia
    {
      if (get<1>(buffer1) < get<1>(buffer2)) // ano igual, mes menor
      {
        return true; // se mes eh menor, data ja eh menor
      }
      else // mes igual ou maior
      {
        if (get<1>(buffer1) == get<1>(buffer2)) // ano igual, mes igual
        {
          if (get<0>(buffer1) < get<0>(buffer2)) // ano igual, mes igual, dia menor
          {
            return true;
          }
          else
          { // ano igual, mes igual, dia maior
            return false;
          }
        }
        else // ano igual, mes maior
        {
          return false; // se mes eh maior, data ja eh maior
        }
      }
    }
    else // se ano eh maior, data ja eh maior
    {
      return false;
    }
  }
  // else { return false; }
}

// -------------- Operadores para data --------------
bool operator>(Calendar &c1, string c2)
{
  return c1.Data1EhMAIORqueData2(c1.str_data.str(), c2);
}

bool operator<(Calendar &c1, string c2)
{
  return c1.Data1EhMENORqueData2(c1.str_data.str(), c2);
}

// if (data > limit_inf)
//   &&(data < limite_sup)
//   {
//     do
//       1 ...
//   }
// else if (data == limite_inf)
// {
//   if (hora >= hora_init)
//   {
//     do
//       1 ...
//   }
// }
// else if (data == limite_sup)
// {
//   if (hora <= hora_end)
//   {
//     do
//       1 ...
//   }
// }