/*
 * Autor: Eduardo Augusto Bezerra
 * Instituicao: UFSC
 * Data: 18/11/2021
 * Arquivo: testeClock.cpp
 * Descricao: Programa usado para testar o funcionamento da Classe Clock
 *
 * Compilado no Linux Ubuntu 20.04.3 LTS
 *
 * Linha de comando: g++ -o teste testeClock.cpp
 *
 */

#include <iostream>
using namespace std;

#include "Clock.cpp"

int main()
{

   // int hora, segundo, minuto;
   // bool ampm;

   // Clock relogio(6, 0, 35, true);
   Clock relogio("06:00:35", true);

   cout << "Teste para a hora atual!" << endl;

   for (int i = 0; i < 5; i++)
   {
      relogio.advance();
      relogio.readClock();
   }

   cout << "Teste iniciando as 11:59:56 AM" << endl;
   // relogio.setClock(11, 59, 56, false);
   relogio.setStringToTime("11:59:56", false);
   for (int i = 0; i < 5; i++)
   {
      relogio.advance();
      relogio.readClock();
   }

   cout << "Teste iniciando as 12:59:56 PM" << endl;
   // relogio.setClock(12, 59, 56, true);
   relogio.setStringToTime("12:59:56", true);
   for (int i = 0; i < 5; i++)
   {
      relogio.advance();
      relogio.readClock();
   }

   cout << "Teste iniciando as 11:59:56 PM" << endl;
   // relogio.setClock(11, 59, 56, true);
   relogio.setStringToTime("11:59:56", true);
   for (int i = 0; i < 5; i++)
   {
      relogio.advance();
      relogio.readClock();
   }

   return 0;
}
