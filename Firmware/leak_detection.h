#ifndef LEAK_DETECTION_H
#define LEAK_DETECTION_H

#define GREEN_LED 25
#define YELLOW_LED 26
#define RED_LED 27
#define BUZZER 14

void setupLeakDetection()
{
  pinMode(GREEN_LED,OUTPUT);
  pinMode(YELLOW_LED,OUTPUT);
  pinMode(RED_LED,OUTPUT);
  pinMode(BUZZER,OUTPUT);
}

int calculateLeakPercent(int mic)
{
  int leak =
      map(mic,1000,3000,0,100);

  leak = constrain(leak,0,100);

  return leak;
}

String getLeakStatus(
      int leak,
      float pressure)
{
  digitalWrite(GREEN_LED,LOW);
  digitalWrite(YELLOW_LED,LOW);
  digitalWrite(RED_LED,LOW);
  digitalWrite(BUZZER,LOW);

  if(leak > 75 && pressure < 1.0)
  {
    digitalWrite(RED_LED,HIGH);
    digitalWrite(BUZZER,HIGH);

    return "CRITICAL";
  }

  if(leak > 40 || pressure < 2.0)
  {
    digitalWrite(YELLOW_LED,HIGH);

    return "WARNING";
  }

  digitalWrite(GREEN_LED,HIGH);

  return "NORMAL";
}

#endif
