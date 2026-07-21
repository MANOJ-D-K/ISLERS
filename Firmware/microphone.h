#ifndef MICROPHONE_H
#define MICROPHONE_H

#define MIC_PIN 34

void setupMicrophone()
{
}

int getMicrophoneValue()
{
  return analogRead(MIC_PIN);
}

#endif
