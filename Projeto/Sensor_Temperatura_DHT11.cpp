#include "headers.h"
#include <string.h>
#include "dhc.c"

class Sensor_Temperatura_DHT11
{
private:
  // float temperatura;

public:
};

Sensor_Temperatura_DHT11::Sensor_Temperatura_DHT11() // construtor
{
  // setTemp();
}

// void Sensor_Temperatura_DHT11::setTemp()
// {
//   temperatura = dht_reading.temp_celsius;
// }

int Sensor_Temperatura_DHT11::getTemp()
{
  int buffer;
  buffer = static_cast<int>(temperatura);
  return buffer;
}