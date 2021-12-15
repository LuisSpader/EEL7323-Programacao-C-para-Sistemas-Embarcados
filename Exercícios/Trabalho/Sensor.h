/*
 * file: Sensor.h
 *
 * Descricao: Classe base Sensor a ser utilizada na P1.
 *
 * Autor: Eduardo Augusto Bezerra
 * Data: 09/12/2021
 *
 * Ultima Alteracao: Eduardo Augusto Bezerra
 * Data da ultima alteracao: 09/12/2021
 *
 */

///////////////////////////////////////////////////////
// Class Sensor - e' uma classe abstrata, pois possui
//                  pelo menos uma funcao virtual pura.
//

class Sensor
{
  int identificacao;
  float valor;

protected:
  int getID();
  void setID(int);
  float getValor();
  void setValor(float);
  virtual void readSensor() = 0; // funcao virtual pura
};
