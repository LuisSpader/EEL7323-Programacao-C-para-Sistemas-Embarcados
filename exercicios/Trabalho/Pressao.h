/*
 * file: Pressao.h
 *
 * Descricao: Classe Pressao utilizada para realizar a leitura do sensor de Pressao, e data data/hora da leitura realizada.
 *
 * Autor: Eduardo Augusto Bezerra
 * Data: 09/12/2021
 *
 * Ultima Alteracao: Eduardo Augusto Bezerra
 * Data da ultima alteracao: 09/12/2021
 *
 */

// #include "Sensor.cpp"
// #include "ClockCalendar.cpp"

class Pressao : virtual public Sensor
{

protected:
public:
  int getID_pressao();
  void setID_pressao(int);
  float getValor_pressao();
  void setValor_pressao(float);
  void readSensor(); // funcao virtual pura

  Pressao();
  ClockCalendar dataHora;
};
