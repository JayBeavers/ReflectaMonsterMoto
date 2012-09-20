#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>
#include <Reflecta.h>

void setup()
{
  reflecta::setup(57200);
  monsterMotoSetup();
}

void loop()
{
  reflecta::loop();
}