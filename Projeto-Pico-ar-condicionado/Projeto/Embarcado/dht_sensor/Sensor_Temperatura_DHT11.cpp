#include <stdio.h>
#include <iostream>
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

#include <math.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"



#ifdef PICO_DEFAULT_LED_PIN
#define LED_PIN PICO_DEFAULT_LED_PIN
#endif

const uint DHT_PIN = 28;
const uint MAX_TIMINGS = 85;

class Sensor_Temperatura_DHT11
{
private:
  typedef struct {
      float humidity;
      float temp_celsius;
  } dht_reading;
bool sensor_OK;

public:
    Sensor_Temperatura_DHT11();
    void ReadingLoop();
    void read_from_dht(dht_reading *result);

};

Sensor_Temperatura_DHT11::Sensor_Temperatura_DHT11() // construtor
{
  stdio_init_all();
  gpio_init(DHT_PIN);
  #ifdef LED_PIN
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
  #endif
//   sensor_OK = true;
}

void Sensor_Temperatura_DHT11::ReadingLoop(){
  while (1) {
        dht_reading reading;
        read_from_dht(&reading);
        // float fahrenheit = (reading.temp_celsius * 9 / 5) + 32;
        // printf("Humidity = %.1f%%, Temperature = %.1fC (%.1fF)\n",
        //        reading.humidity, reading.temp_celsius, fahrenheit);

        sleep_ms(2000);
    }
}

void Sensor_Temperatura_DHT11::read_from_dht(dht_reading *result) {
    int data[5] = {0, 0, 0, 0, 0};
    uint last = 1;
    uint j = 0;

    gpio_set_dir(DHT_PIN, GPIO_OUT);
    gpio_put(DHT_PIN, 0);
    sleep_ms(20);
    gpio_set_dir(DHT_PIN, GPIO_IN);

#ifdef LED_PIN
    gpio_put(LED_PIN, 1);
#endif
    for (uint i = 0; i < MAX_TIMINGS; i++) {
        uint count = 0;
        while (gpio_get(DHT_PIN) == last) {
            count++;
            sleep_us(1);
            if (count == 255) break;
        }
        last = gpio_get(DHT_PIN);
        if (count == 255) break;

        if ((i >= 4) && (i % 2 == 0)) {
            data[j / 8] <<= 1;
            if (count >46) data[j / 8] |= 1;
            //https://electronics.stackexchange.com/questions/552924/raspberry-pico-and-dht11-not-working-c-c
            j++;
        }
    }
#ifdef LED_PIN
    gpio_put(LED_PIN, 0);
#endif

    if ((j >= 40) && (data[4] == ((data[0] + data[1] + data[2] + data[3]) & 0xFF))) {
        result->humidity = (float) ((data[0] << 8) + data[1]) / 10;
        if (result->humidity > 100) {
            result->humidity = data[0];
        }
        result->temp_celsius = (float) (((data[2] & 0x7F) << 8) + data[3]) / 10;
        if (result->temp_celsius > 125) {
            result->temp_celsius = data[2];
        }
        if (data[2] & 0x80) {
            result->temp_celsius = -result->temp_celsius;
        }
    sensor_OK = true;
    } else {
        // printf("Bad data\n");
        cout << "DHT11: Bad data\n";
        sensor_OK = false;

    }
}
