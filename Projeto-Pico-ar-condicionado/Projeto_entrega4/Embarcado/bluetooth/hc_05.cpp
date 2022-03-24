// Example script of USB serial

#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/uart.h"

#define BAUD_RATE = 9600

class hc_05
{
private:
  /* data */
public:
  hc_05(BAUD_RATE);
  ~hc_05();
};

hc_05::hc_05(BAUD_RATE)
{
  // Initialise UART 0
  uart_init(uart0, BAUD_RATE);
  // Set the GPIO pin mux to the UART - 0 is TX, 1 is RX
  gpio_set_function(0, GPIO_FUNC_UART);
  gpio_set_function(1, GPIO_FUNC_UART);
}

hc_05::~hc_05()
{
}

hc_05::test(BAUD_RATE)
{

  uart_puts(uart0, "Pico: Hello world!\n\r");
  // sleep_ms(1000);

  // while (true) {
  //     uart_puts(uart0, "Hello world!\n\r");
  //     sleep_ms(1000);
  // }
}
