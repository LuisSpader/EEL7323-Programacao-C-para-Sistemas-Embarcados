/*
 * file: Sensor.cpp
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

#include "Sensor.h"

int Sensor::getID()
{
  return identificacao;
}

void Sensor::setID(int newID)
{
  identificacao = newID;
}

float Sensor::getValor()
{
  return valor;
}

void Sensor::setValor(float newValor)
{
  valor = newValor;
}
