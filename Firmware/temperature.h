#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <SPI.h>
#include <Adafruit_MAX31865.h>

Adafruit_MAX31865 thermo(5);

void setupTemperature()
{
  thermo.begin(MAX31865_2WIRE);
}

float getTemperature()
{
  return thermo.temperature(100.0,430.0);
}

#endif
