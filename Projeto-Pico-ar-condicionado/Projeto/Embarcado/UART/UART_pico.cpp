#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <string.h>

class UART_pico
{
private:
    /* data */
public:
    UART_pico(/* args */);
    ~UART_pico();
};

UART_pico::UART_pico(/* args */)
{
    // Initialise UART 0
    uart_init(uart0, 115200);
 
    // Set the GPIO pin mux to the UART - 0 is TX, 1 is RX
    gpio_set_function(0, GPIO_FUNC_UART);
    gpio_set_function(1, GPIO_FUNC_UART);
    void SendCommand(string serial);

}

UART_pico::~UART_pico()
{
}

void UART_pico::SendCommand(string serial){
    uart_puts(uart0, serial);
}

int main() {

 
    // uart_puts(uart0, "Hello world!");
}
