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
#include <cstdlib> // para usar srand() e rand()
#include <ctime>   // para usar time()

// Temperatura::Temperatura():ClockCalendar(string hour_buffer, int pm, string date_buffer)
// Temperatura::Temperatura() : ClockCalendar("00:00:00", 0, "00/00/0000")
Temperatura::Temperatura()
{
  // ClockCalendar("00:00:00", 0, "00/00/0000");
  // ClockCalendar();
  setValor(0);
  setID(0);
}

// Aqui está a implementação para a Função Virtual Pura (função sem declaração) herdada da classe 'Sensor'
// void Temperatura::readSensor(int ID, float leitura)
void Temperatura::readSensor()
{
  //--------------------------------------------------------------------------------------------------
  // Data/hora da leitura do sensor - substituir os parametros do construtor do ClockCalendar por time()
  // dataHora = ClockCalendar(2021, 6, 30, 11, 59, 55, true);
  // dataHora = ClockCalendar("11:59:55", 1, "30/06/2021"); //(buffer_hora, b_pm, buffer_data)
  dataHora.setClock();

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

  setValor(static_cast<float>(rand()) / static_cast<float>(RAND_MAX));
}

// SET
void Temperatura::setID(int newID)
{
  setID(newID);
}

void Temperatura::setValor(float newValor)
{
  setValor(newValor);
}

// GET
int Temperatura::getID()
{
  return getID();
}

float Temperatura::getValor_temp()
{
  return getValor();
}
