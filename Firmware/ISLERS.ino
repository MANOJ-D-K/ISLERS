#include "blynk_config.h"

#include "microphone.h"
#include "pressure.h"
#include "temperature.h"
#include "display.h"
#include "leak_detection.h"
#include "blynk_handler.h"

void setup()
{
  Serial.begin(115200);

  setupMicrophone();
  setupPressure();
  setupTemperature();
  setupDisplay();
  setupLeakDetection();

  setupBlynk();
}

void loop()
{
  Blynk.run();

  int micValue =
      getMicrophoneValue();

  float pressure =
      getPressureValue();

  float temperature =
      getTemperature();

  int leakPercent =
      calculateLeakPercent(
          micValue);

  String status =
      getLeakStatus(
          leakPercent,
          pressure);

  int health = 100;

  if(temperature < -50 ||
     temperature > 150)
      health -= 34;

  if(pressure < 0 ||
     pressure > 10)
      health -= 33;

  updateDisplay(
      micValue,
      pressure,
      temperature,
      leakPercent,
      status);

  updateBlynk(
      temperature,
      pressure,
      micValue,
      leakPercent,
      health,
      status);

  delay(1000);
}
