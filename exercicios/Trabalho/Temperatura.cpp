/*
 * file: Temperatura.cpp
 *
 * Descricao: Implementacao da Classe Temperatura utilizada para realizar a leitura do sensor de temperatura, e data data/hora da leitura realizada.
 *
 * Autor: Eduardo Augusto Bezerra
 * Data: 09/12/2021
 *
 * Ultima Alteracao: Eduardo Augusto Bezerra
 * Data da ultima alteracao: 09/12/2021
 *
 */
#include "Temperatura.h"
#include <cstdlib>  // para usar srand() e rand()
#include <ctime>    // para usar time()
#include <stdlib.h> // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
// #include <format>
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...
#include <iomanip>   // para usar setfill() e setw()

// Temperatura::Temperatura():ClockCalendar(string hour_buffer, int pm, string date_buffer)
// Temperatura::Temperatura() : ClockCalendar("00:00:00", 0, "00/00/0000")
Temperatura::Temperatura()
{
  // ClockCalendar("00:00:00", 0, "00/00/0000");
  // ClockCalendar();
  setValor(-300);
  setID(0);
  cout << getID() << getValor();
}

// Aqui está a implementação para a Função Virtual Pura (função sem declaração) herdada da classe 'Sensor'
// void Temperatura::readSensor(int ID, float leitura)
void Temperatura::readSensor()
{
  float buffer;
  // std::stringstream buffer;

  //--------------------------------------------------------------------------------------------------
  // Data/hora da leitura do sensor - substituir os parametros do construtor do ClockCalendar por time()
  // dataHora = ClockCalendar(2021, 6, 30, 11, 59, 55, true);
  // dataHora = ClockCalendar("11:59:55", 1, "30/06/2021"); //(buffer_hora, b_pm, buffer_data)
  dataHora.setClock_timelib();

  // nesta versão aprimorada passamos 3 dados:
  //      horário = horas:minutos:segundos
  //      se é 'pm' = 1, se for 'am' = 0
  //      data = dia/mes/ano (XX/XX/XXXX)
  //--------------------------------------------------------------------------------------------------

  // Sempre que a função 'readSensor' for chamada, ela chamará 2 funções:
  //      Sensor::setValor();
  //      obj_horario = ClockCalendar(...)
  //                já inicializando valores com construtor buscando do sistema com <ctime> -> para usar time()

  // Simulacao de leitura de sensor
  srand(static_cast<unsigned>(time(0))); // srand(semente)= gera valor aleatório usando a semente aleatória (time(0)) que é a hora do S.O
                                         // https://stackoverflow.com/questions/42138421 why-the-static-cast-on-time0-on-this-code
                                         // https: // www.programiz.com/cpp-programming/library-function/ctime/time
                                         //  https://www.cplusplus.com/reference/cstdlib/

  // (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) >> setprecision(2) >> buffer;

  // buffer = std::format("{:.2f}", (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)));
  // buffer << std::fixed << std::setprecision(2) << (static_cast<float>(rand()) / static_cast<float>(RAND_MAX));
  buffer = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX));
  setprecision(2);
  setValor(buffer);

  // setValor(std::stoi(buffer));
  // setValor(1.25);
}

// SET
void Temperatura::setID_temp(int newID)
{
  setID(newID);
}

void Temperatura::setValor_temp(float newValor)
{
  setValor(newValor);
}

// GET
int Temperatura::getID_temp()
{
  return getID();
}

float Temperatura::getValor_temp()
{
  return getValor();
}
