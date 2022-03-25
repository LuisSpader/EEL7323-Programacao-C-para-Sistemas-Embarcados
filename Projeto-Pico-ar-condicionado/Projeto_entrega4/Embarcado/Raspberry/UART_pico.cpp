#include <stdio.h>
// #include "headers.h"

// #include <string.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"

#include "List_pico.cpp"

#define UART_ID uart0
#define BAUD_RATE 9600

#define UART_TX_PIN 0
#define UART_RX_PIN 1

#define DATA_BITS 8
#define STOP_BITS 1
#define PARITY UART_PARITY_NONE

class UART_pico : virtual protected List_pico
{
private:
    /* data */
    bool end_log = false;
    // Node_pico *head; // ponteiro com tamanho de endereço de um 'Node_pico'

public:
    UART_pico();
    ~UART_pico();
    void SendCommand(char *char_serial);
    void SendLog();
};

UART_pico::UART_pico()
{
    // head = 0;
    // Initialise UART 0
    uart_init(UART_ID, BAUD_RATE);

    // Set the GPIO pin mux to the UART - 0 is TX, 1 is RX
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    // Set our data format
    uart_set_format(UART_ID, DATA_BITS, STOP_BITS, PARITY);
}

UART_pico::~UART_pico()
{
}

void UART_pico::SendCommand(char *char_serial)
{
    uart_puts(UART_ID, char_serial);

    // // Send out a character without any conversions
    // uart_putc_raw(UART_ID, 'A');

    // // Send out a character but do CR/LF conversions
    // uart_putc(UART_ID, 'B');
}

void UART_pico::SendLog()
{
    end_log = false;

    Node_pico *aux = head;

    while (aux != 0) // enquanto não chega no último nodo (que aponta para '0')
    {
        // SendNode(aux);
        // uart_puts(UART_ID, char_serial);
        uart_get_instance();

        uart_puts(UART_ID, SendNode(aux));

        aux = aux->getNext();
    }

    uart_puts(UART_ID, "Envio de log finalizado");
    sleep_ms(50);
    uart_puts(UART_ID, "Stop");
    end_log = true;
}
