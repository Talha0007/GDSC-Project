#include <Wire.h>
#include "MAX30105.h"
#include "heartRate.h"

MAX30105 particleSensor;
volatile int bpm;

void setup()
{
  Serial.begin(115200);

  // Initialize the MAX30102 pulse sensor
  particleSensor.begin(Wire, I2C_SPEED_FAST);

  // Configure the pulse sensor
  particleSensor.setup();

  // Set up the interrupt pin
  attachInterrupt(27, beat, RISING);
}

void loop()
{
  // Read the pulse rate
  if (particleSensor.getFIFOAvailable() >= 500)
  {
    uint32_t ir, red;
    while (particleSensor.getFIFOAvailable())
    {
      particleSensor.nextSample();
      ir = particleSensor.getIR();
      red = particleSensor.getRed();
    }

    bpm = getHeartRate();
    Serial.println(bpm);
  }
}

void beat()
{
  static unsigned long lastBeatTime = 0;
  unsigned long thisBeatTime = millis();
  static unsigned int beatCount = 0;

  if ((thisBeatTime - lastBeatTime) < 1000)
  {
    beatCount++;
  }
  else
  {
    bpm = beatCount;
    beatCount = 0;
    lastBeatTime = thisBeatTime;
  }
}
