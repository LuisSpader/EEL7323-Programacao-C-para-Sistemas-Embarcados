/*
 * file: Pressao.cpp
 *
 * Descricao: Implementacao da Classe Pressao utilizada para realizar a leitura do sensor de temperatura, e data data/hora da leitura realizada.
 *
 * Autor: Eduardo Augusto Bezerra
 * Data: 09/12/2021
 *
 * Ultima Alteracao: Eduardo Augusto Bezerra
 * Data da ultima alteracao: 09/12/2021
 *
 */
#include "Pressao.h"
#include <cstdlib> // para usar srand() e rand()
#include <ctime>   // para usar time()

void Pressao::readSensor()
{
  // Data/hora da leitura do sensor - substituir os parametros do construtor do ClockCalendar por time()

  // dataHora = ClockCalendar(2021, 6, 30, 11, 59, 55, true);

  dataHora = ClockCalendar("11:59:55", 1, "30/06/2021"); //(buffer_hora, b_pm, buffer_data)
  // nesta versão aprimorada passamos 3 dados:
  //      horário = horas:minutos:segundos
  //      se é 'pm' = 1, se for 'am' = 0
  //      data = dia/mes/ano (XX/XX/XXXX)

  // Simulacao de leitura de sensor
  srand(static_cast<unsigned>(time(0)));
  setValor(static_cast<float>(rand()) / static_cast<float>(RAND_MAX));
}
