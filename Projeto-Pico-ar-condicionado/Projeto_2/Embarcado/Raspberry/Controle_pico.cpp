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
#include "List_pico.cpp"
#include "IA_temperatura.cpp"
#include "UART_pico.cpp"

#include "pico/stdlib.h"
#include "hardware/gpio.h"



class Controle_pico : 
    protected botoes, 
    protected Sensor_Temperatura_DHT11, 
    protected IA_Temperatura
    protected UART_pico
{
private:
    List_pico lista(18250065); // ID fixo
    int state = 0;
public:
    Controle_pico();
    ~Controle_pico();
    void interface_Controle();
    void Inicializacao();
    void Controle_ativo();
    void Log();
};

Controle_pico::Controle_pico()
{
    interface_Controle();
}

Controle_pico::~Controle_pico()
{
}

void Controle_pico::Inicializacao(){ // state 0
    stdio_init_all();
    botoes();
    

    if (sensor_OK == true){
        cout << "Sensor DHT11: OK ..." << endl;
        if (IA_OK == true){
                cout << "Algoritmo IA: OK ..." << endl;
                state = 1;
        }
    }
        
}

void Controle_pico::Controle_ativo(){ // state 1
    while(!(aumenta && diminui)){
        Monitora_temp_externa(temp_celsius); //from sensor

        if (aumenta == true){ // aumenta temperatura manualmente
            Aumenta_manualmente();
        }else if (diminui == true){ // diminui temperatura manualmente
            Diminui_manualmente();
        }
    }
    state = 2;

}

void Controle_pico::Log(){ // state 2
    cout << "Iniciando UART ..." << endl;
    
    SendLog();
    sleep_ms(1000);
    if (end_log = true){
        state = 1;
        end_log = false;}

}

void Controle_pico::interface_Controle(){
    while(1){
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