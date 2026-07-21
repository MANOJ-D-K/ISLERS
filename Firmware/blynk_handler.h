#ifndef BLYNK_HANDLER_H
#define BLYNK_HANDLER_H

BlynkTimer timer;

void setupBlynk()
{
  Blynk.begin(
      BLYNK_AUTH_TOKEN,
      ssid,
      pass);
}

void updateBlynk(
      float temperature,
      float pressure,
      int micValue,
      int leakPercent,
      int health,
      String status)
{
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, pressure);
  Blynk.virtualWrite(V2, micValue);
  Blynk.virtualWrite(V3, leakPercent);
  Blynk.virtualWrite(V4, health);
  Blynk.virtualWrite(V5, status);

  static bool notificationSent = false;

  if(status == "CRITICAL")
  {
    if(!notificationSent)
    {
      Blynk.logEvent(
          "critical_leak",
          "Critical Leak Detected!");

      notificationSent = true;
    }
  }
  else
  {
    notificationSent = false;
  }
}

#endif
