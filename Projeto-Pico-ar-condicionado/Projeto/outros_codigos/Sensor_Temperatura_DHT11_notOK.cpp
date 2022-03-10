#include "headers.h"
#include <string.h>
// #include "dhc.c"
#include <stdbool.h>
#include <stdint.h>

class Sensor_Temperatura_DHT11
{
private:
  uint8_t DATA_PIN;

  double last_temp;
  double last_humidity;

  double temp_measurements[30];
  double humidity_measurements[30];


public:
  void ActivateSensor();
  // int getTemp();
};

Sensor_Temperatura_DHT11::Sensor_Temperatura_DHT11() // construtor
{

}

// void Sensor_Temperatura_DHT11::setTemp()
// {
//   temperatura = dht_reading.temp_celsius;
// }

// int Sensor_Temperatura_DHT11::getTemp()
// {
//   int buffer;
//   buffer = static_cast<int>(temperatura);
//   return buffer;
// }


// https://dev.to/admantium/dht1-temperature-sensor-library-for-the-raspberry-pico-53ac

// I Activate DHT
void Sensor_Temperatura_DHT11::ActivateSensor()
{
  gpio_put(pin, 0);              // LOW
  sleep_ms(18);              // 18us

  gpio_put(pin, 1);              // HIGH
  sleep_us(20);              // 20us

// II Read DHT Confirmation
  gpio_set_dir(pin, GPIO_IN);
  bool init_state = 0;

  int count = 0;
  while(init_state = !gpio_get(pin)) {          // EXPECT LOW 80us
    count++;
    sleep_us(1);
  };

  printf("DHT Confirmation LOW: %d\n", count);

  count = 0;
  while(init_state = gpio_get(pin)) {
    count++;
    sleep_us(1);
  };
  printf("DHT Confirmation HIGH: %d\n", count);  // EXPECT HIGH 80us
}

