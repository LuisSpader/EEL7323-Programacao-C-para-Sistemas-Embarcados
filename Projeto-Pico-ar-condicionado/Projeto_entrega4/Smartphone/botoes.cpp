#include <stdlib.h>
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

#include <stdio.h>
// #include "hardware/sync.h"
// #include "hardware/structs/ioqspi.h"
// #include "hardware/structs/sio.h"
// #define BUTTON_PIN_aumenta 15
// #define BUTTON_PIN_diminui 16

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
}

botoes::~botoes()
{
}

void botoes::MonitoramentoBotoes()
{
    while (true)
    {
        if ((BUTTON_PIN_aumenta))
        {
            Aumenta_flag();
        }
        if ((BUTTON_PIN_diminui))
        {
            Diminui_flag();
        }
        sleep_ms(250);
    }
}

void botoes::Aumenta_flag()
{
    aumenta <= true;
    sleep_ms(50);
    aumenta <= false;
}

void botoes::Diminui_flag()
{
    diminui <= true;
    sleep_ms(50);
    diminui <= false;
}