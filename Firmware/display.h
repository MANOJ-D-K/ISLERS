#ifndef DISPLAY_H
#define DISPLAY_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &Wire);

void setupDisplay()
{
  display.begin(0x3C, true);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);

  display.setCursor(20,25);
  display.println("ISLERS");
  display.display();

  delay(1000);
}

void updateDisplay(
      int mic,
      float pressure,
      float temp,
      int leak,
      String status)
{
  display.clearDisplay();

  display.setTextSize(1);

  display.setCursor(0,0);
  display.print("MIC:");
  display.println(mic);

  display.setCursor(0,12);
  display.print("P:");
  display.print(pressure,1);
  display.println(" bar");

  display.setCursor(0,24);
  display.print("T:");
  display.print(temp,1);
  display.println(" C");

  display.setCursor(0,36);
  display.print("LEAK:");
  display.print(leak);
  display.println("%");

  display.setCursor(0,52);
  display.print(status);

  display.display();
}

#endif
