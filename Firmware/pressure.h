#ifndef PRESSURE_H
#define PRESSURE_H

#define PRESSURE_PIN 35

void setupPressure()
{
}

float getPressureValue()
{
  int adc = analogRead(PRESSURE_PIN);

  return (adc * 10.0) / 4095.0;
}

#endif
