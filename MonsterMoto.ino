using namespace reflectaFunctions;

byte MOTOR_0_A          = 7;
byte MOTOR_0_B          = 8;
byte MOTOR_0_PWM        = 5;
byte MOTOR_0_CURRENT    = 2;
byte MOTOR_0_ENABLED    = 0;

byte MOTOR_1_A          = 4;
byte MOTOR_1_B          = 9;
byte MOTOR_1_PWM        = 6;
byte MOTOR_1_CURRENT    = 3;
byte MOTOR_1_ENABLED    = 1;

void BrakeVcc()
{
  digitalWrite(MOTOR_0_A, HIGH);
  digitalWrite(MOTOR_0_B, HIGH);
  digitalWrite(MOTOR_1_A, HIGH);
  digitalWrite(MOTOR_1_B, HIGH);
  analogWrite(MOTOR_0_PWM, 0);
  analogWrite(MOTOR_1_PWM, 0);
}

void BrakeGround()
{
  digitalWrite(MOTOR_0_A, LOW);
  digitalWrite(MOTOR_0_B, LOW);
  digitalWrite(MOTOR_1_A, LOW);
  digitalWrite(MOTOR_1_B, LOW);
  analogWrite(MOTOR_0_PWM, 0);
  analogWrite(MOTOR_1_PWM, 0);
}

void Drive()
{
  int16_t power0 = reflectaFunctions::pop16();
  int16_t power1 = reflectaFunctions::pop16();
  
  if (power0 < 0)
  {
    digitalWrite(MOTOR_0_A, LOW);
    digitalWrite(MOTOR_0_B, HIGH);
  }
  else
  {
    digitalWrite(MOTOR_0_A, HIGH);
    digitalWrite(MOTOR_0_B, LOW);
  }
  analogWrite(MOTOR_0_PWM, (uint8_t)abs(power0));
  
  if (power1 < 0)
  {
    digitalWrite(MOTOR_1_A, LOW);
    digitalWrite(MOTOR_1_B, HIGH);
  }
  else
  {
    digitalWrite(MOTOR_1_A, HIGH);
    digitalWrite(MOTOR_1_B, LOW);
  }
  analogWrite(MOTOR_1_PWM, (uint8_t)abs(power1));    
}

void ReadCurrent()
{
  reflectaFunctions::push16(analogRead(MOTOR_0_CURRENT));
  reflectaFunctions::push16(analogRead(MOTOR_1_CURRENT));
}

void Initialize()
{
  pinMode(MOTOR_0_A, OUTPUT);
  pinMode(MOTOR_0_B, OUTPUT);
  pinMode(MOTOR_0_PWM, OUTPUT);
  pinMode(MOTOR_0_ENABLED, OUTPUT);
  pinMode(MOTOR_1_A, OUTPUT);
  pinMode(MOTOR_1_B, OUTPUT);
  pinMode(MOTOR_1_PWM, OUTPUT);
  pinMode(MOTOR_1_ENABLED, OUTPUT);
  
  BrakeGround();

  digitalWrite(MOTOR_0_ENABLED, HIGH);
  digitalWrite(MOTOR_1_ENABLED, HIGH);
}

void Configure()
{
  MOTOR_0_A         = pop();
  MOTOR_0_B         = pop();
  MOTOR_0_PWM       = pop();
  MOTOR_0_CURRENT   = pop();
  MOTOR_0_ENABLED   = pop();

  MOTOR_1_A         = pop();
  MOTOR_1_B         = pop();
  MOTOR_1_PWM       = pop();
  MOTOR_1_CURRENT   = pop();
  MOTOR_1_ENABLED   = pop();
}

void monsterMotoSetup()
{
  bind("MOTO1", BrakeGround);
  bind("MOTO1", BrakeVcc);
  bind("MOTO1", Drive);
  bind("MOTO1", ReadCurrent);
  bind("MOTO1", Configure);
  bind("MOTO1", Initialize);
}