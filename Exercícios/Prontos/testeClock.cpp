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
#include <iomanip>
using namespace std;

#include "Clock.cpp"

int main()
{

   int hora, segundo, minuto;
   bool ampm;

   Clock relogio(6, 0, 35, true);

   cout << "Teste para a hora atual!" << endl;

   for (int i = 0; i < 5; i++)
   {
      relogio.advance();
      relogio.readClock(hora, segundo, minuto, ampm);
      //      cout << hora << ":" << minuto << ":" << segundo << (ampm ? " pm" : " am") << endl;
      cout << setw(2) << setfill('0') << hora << ":"
           << setw(2) << setfill('0') << minuto << ":"
           << setw(2) << setfill('0') << segundo
           << (ampm ? " pm" : " am") << endl;
   }

   cout << "Teste iniciando as 11:59:56 AM" << endl;
   relogio.setClock(11, 56, 59, false);
   for (int i = 0; i < 5; i++)
   {
      relogio.advance();
      relogio.readClock(hora, segundo, minuto, ampm);
      cout << setw(2) << setfill('0') << hora << ":"
           << setw(2) << setfill('0') << minuto << ":"
           << setw(2) << setfill('0') << segundo
           << (ampm ? " pm" : " am") << endl;
   }

   cout << "Teste iniciando as 12:59:56 PM" << endl;
   relogio.setClock(12, 56, 59, true);
   for (int i = 0; i < 5; i++)
   {
      relogio.advance();
      relogio.readClock(hora, segundo, minuto, ampm);
      cout << setw(2) << setfill('0') << hora << ":"
           << setw(2) << setfill('0') << minuto << ":"
           << setw(2) << setfill('0') << segundo
           << (ampm ? " pm" : " am") << endl;
   }

   cout << "Teste iniciando as 11:59:56 PM" << endl;
   relogio.setClock(11, 56, 59, true);
   for (int i = 0; i < 5; i++)
   {
      relogio.advance();
      relogio.readClock(hora, segundo, minuto, ampm);
      cout << setw(2) << setfill('0') << hora << ":"
           << setw(2) << setfill('0') << minuto << ":"
           << setw(2) << setfill('0') << segundo
           << (ampm ? " pm" : " am") << endl;
   }

   return 0;
}
