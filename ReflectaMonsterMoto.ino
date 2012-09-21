#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>
#include <Reflecta.h>

void adjustPwmFrequency()
{
  // Adjust the timer prescaler to move the motor pwm frequency outside of human hearing
  // AKA get rid of the whine.
  
  TCCR0B &= ~0x07; // Set the lower three bits (prescaler value) to 000 to remove previous setting (generally 011)
  TCCR0B |= 0x01;  // Set the lower three bits to 001
}

void setup()
{
  reflecta::setup(57200);
  monsterMotoSetup();
}

void loop()
{
  reflecta::loop();
}
