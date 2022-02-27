//---------------------------- LIBRARIES ------------------------ //
#include <string.h>
#include <iostream>
// #include <string.h>  // Para trabalhar com strings
#include <stdlib.h>
using namespace std;
#include <iomanip>

class Calendar
{
protected:
  int dia, mes, ano;

public:
  stringstream str_data;

  Calendar(); // construtor
  void setStringToDate(string date_buffer);
  void setCalendar(int d, int mo, int a);
  void readCalendar();
  void setCalendarString();
  void advance();
};

// ------------------- Construtor ------------------- //
Calendar::Calendar()
{
  setStringToDate("00/00/0000");
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
void Calendar::setStringToDate(string date_buffer)
{
  string temp;

  if (date_buffer.length() > 10)
  {
    cout << "Digits limit exceeded! \n";
    exit(EXIT_FAILURE);
  }

  // DIA
  temp = date_buffer.substr(0, 2);
  if (isNumber(temp) == true)
  {
    dia = std::stoi(temp);
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
    mes = std::stoi(temp);
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
    ano = std::stoi(temp);
  }
  else
  {
    cout << "Invalid year \n";
    exit(EXIT_FAILURE);
  }
  // date = date_buffer.substr(0, 2) + "/" + date_buffer.substr(3, 2) + "/" + date_buffer.substr(6, 4);

  setCalendar(dia, mes, ano);
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