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
#include <cstdlib>   // para usar srand() e rand()
#include <ctime>     // para usar time()
#include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...
#include <iomanip>   // para usar setfill() e setw()

Temperatura::Temperatura()
{

  setValor(-300);
  setID(0);
}

// Aqui está a implementação para a Função Virtual Pura (função sem declaração) herdada da classe 'Sensor'
// void Temperatura::readSensor(int ID, float leitura)
void Temperatura::readSensor()
{

  dataHora.setClock_timelib();

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
