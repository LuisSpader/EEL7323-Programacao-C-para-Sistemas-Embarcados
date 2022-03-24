#include <stdlib.h>
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
// #include "hardware/sync.h"
// #include "hardware/structs/ioqspi.h"
// #include "hardware/structs/sio.h"
#define BUTTON_PIN_aumenta 15
#define BUTTON_PIN_diminui 16


class botoes
{
private:
    /* data */
public:
    bool aumenta, diminui;
    botoes();
    ~botoes();

    void MonitoramentoBotoes();
    void Aumenta_flag();
    void Diminui_flag();
};

botoes::botoes()
{
    gpio_init(BUTTON_PIN_aumenta); // inicializa botão 1
    gpio_init(BUTTON_PIN_diminui);  // inicializa botão 2
    gpio_set_dir(BUTTON_PIN_aumenta, GPIO_IN); //define Pino como entrada
    gpio_set_dir(BUTTON_PIN_diminui, GPIO_IN); //define Pino como entrada
    gpio_pull_up(BUTTON_PIN_aumenta); //define como Pull Down (Normalmente fechado)
    gpio_pull_up(BUTTON_PIN_diminui); //define como Pull Down (Normalmente fechado)
}

botoes::~botoes()
{
}

void botoes::MonitoramentoBotoes(){
    while(true){
        if(!gpio_get(BUTTON_PIN_aumenta)){
            Aumenta_flag();

        }
        if (!gpio_get(BUTTON_PIN_diminui)){
            Diminui_flag();
    }
    sleep_ms(250);
}
}


void botoes::Aumenta_flag(){
    aumenta <= true;
    sleep_ms(50);
    aumenta <= false;
}

void botoes::Diminui_flag(){
    diminui <= true;
    sleep_ms(50);
    diminui <= false;
}