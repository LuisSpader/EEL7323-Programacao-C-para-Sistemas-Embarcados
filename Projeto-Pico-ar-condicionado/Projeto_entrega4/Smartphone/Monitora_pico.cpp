/*
Estados:
    0 - Inicialização: inicializa parâmetros e checa
    1 - Controle ativo:
        Função loop -> while(!(botão1 && botão2)):
        - checagem das entradas: temp_externa, botões
        - Ajuste da temperatura do dispositivo AR (Ar-condicionado)
    2 - Log: -> (botão1 && botão2):
        - status para envio de log
    **--Desliga:
*/
// #include <string>
#include <iostream>
// #include <string.h>  // Para trabalhar com strings
#include <stdlib.h>
using namespace std;

#include "botoes.cpp"
#include "Sensor_Temperatura_DHT11.cpp"
#include "List_Smartphone.cpp"
#include "IA_temperatura.cpp"
#include "UART_pico.cpp"

#include "pico/stdlib.h"
#include "hardware/gpio.h"

class Monitora_pico : protected botoes,
                      protected Bluetooth_Smartphone
{
private:
    List_Smartphone lista(18250065); // ID fixo
    int state = 0;

public:
    Monitora_pico();
    ~Monitora_pico();
    void interface_Controle();
    void Inicializacao();
    void Controle_ativo();
    void Log();
};

Monitora_pico::Monitora_pico()
{
    interface_Controle();
}

Monitora_pico::~Monitora_pico()
{
}

void Monitora_pico::Inicializacao()
{ // state 0
    stdio_init_all();
    botoes();

    if (sensor_OK == true)
    {
        cout << "Sensor DHT11: OK ..." << endl;
        if (IA_OK == true)
        {
            cout << "Algoritmo IA: OK ..." << endl;
            state = 1;
        }
    }
}

void Monitora_pico::Controle_ativo()
{ // state 1
    while (!(aumenta && diminui))
    {
        Monitora_temp_externa(temp_celsius); // from sensor

        if (aumenta == true)
        { // aumenta temperatura manualmente
            Aumenta_manualmente();
        }
        else if (diminui == true)
        { // diminui temperatura manualmente
            Diminui_manualmente();
        }
    }
    state = 2;
}

void Monitora_pico::Log()
{ // state 2
    cout << "Iniciando UART ..." << endl;

    SendLog();
    sleep_ms(1000);
    if (end_log = true)
    {
        state = 1;
        end_log = false;
    }
}

void Monitora_pico::interface_Controle()
{
    while (1)
    {
        switch (state)
        {
        case 0:
            Inicializacao();
            break;
        case 1:
            Controle_ativo();
            break;
        case 2:
            Log();
            break;
        default:
            break;
        }
    }
}