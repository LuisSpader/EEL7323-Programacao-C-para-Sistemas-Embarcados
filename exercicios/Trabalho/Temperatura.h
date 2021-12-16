/*
 * file: Temperatura.h
 *
 * Descricao: Classe Temperatura utilizada para realizar a leitura do sensor de temperatura, e data data/hora da leitura realizada.
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

class Temperatura : public Sensor
// class Temperatura
{
  // int ID;
  // float leitura;

protected:
  // void readSensor(int ID, float leitura);

public:
  int getID_temp();
  void setID_temp(int);
  float getValor_temp();
  void setValor_temp(float);
  void readSensor(); // funcao virtual pura

  Temperatura();
  ClockCalendar dataHora;
};
// ----------------------
