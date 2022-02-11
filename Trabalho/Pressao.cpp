/*
 * file: Pressao.cpp
 *
 * Descricao: Implementacao da Classe Pressao utilizada para realizar a leitura do sensor de Pressao, e data data/hora da leitura realizada.
 *
 * Autor: Eduardo Augusto Bezerra
 * Data: 09/12/2021
 *
 * Ultima Alteracao: Eduardo Augusto Bezerra
 * Data da ultima alteracao: 09/12/2021
 *
 */
#include "Pressao.h"
#include <cstdlib>   // para usar srand() e rand()
#include <ctime>     // para usar time()
#include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...
#include <iomanip>   // para usar setfill() e setw()

Pressao::Pressao()
{
  setValor_pressao(-300);
  setID_pressao(0);
}

// Aqui está a implementação para a Função Virtual Pura (função sem declaração) herdada da classe 'Sensor'
// void Pressao::readSensor(int ID, float leitura)
void Pressao::readSensor()
{

  dataHora.setClock_timelib();

  // Simulacao de leitura de sensor
  setValor_pressao(static_cast<float>(rand()) / static_cast<float>(RAND_MAX));
}

// SET
void Pressao::setID_pressao(int newID)
{
  setID_pressao(newID);
}

void Pressao::setValor_pressao(float newValor)
{
  setValor_pressao(newValor);
}

// GET
int Pressao::getID_pressao()
{
  return getID_pressao();
}

float Pressao::getValor_pressao()
{
  return getValor_pressao();
}
