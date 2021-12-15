/*
 * file: Pressao.h
 *
 * Descricao: Classe Pressao utilizada para realizar a leitura do sensor de temperatura, e data data/hora da leitura realizada.
 *
 * Autor: Eduardo Augusto Bezerra
 * Data: 09/12/2021
 *
 * Ultima Alteracao: Eduardo Augusto Bezerra
 * Data da ultima alteracao: 09/12/2021
 *
 */

#include "Sensor.cpp"
#include "ClockCalendar.cpp"

class Pressao : public Sensor
{
  ClockCalendar dataHora;

protected:
  void readSensor();
};