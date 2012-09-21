#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>
#include <Reflecta.h>

void adjustPwmFrequency()
{
  // Adjust the timer prescaler to move the motor pwm frequency outside of human hearing
  // AKA get rid of the whine.
  
  int prescaler = 0x07;
  TCCR0B &= ~prescaler; // Set the lower three bits (prescaler value) to 000 to remove previous setting (generally 011)
  prescaler = 0x01;
  TCCR1B |= prescaler;  // Set the lower three bits to 001
}

void setup()
{
  adjustPwmFrequency();
  reflecta::setup(57200);
  monsterMotoSetup();
}

void loop()
{
  reflecta::loop();
}
