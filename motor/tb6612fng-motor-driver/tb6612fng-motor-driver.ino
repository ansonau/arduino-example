int PWM1 = 5;
int DIR1 = 4;
int PWM2 = 6;
int DIR2 = 7;

void setup()
{
  pinMode(DIR1, OUTPUT);
  pinMode(DIR2, OUTPUT);
}

void loop()
{
  int value;
  for(value = 0 ; value <= 255; value =5)
  {
    digitalWrite(DIR1,HIGH);
    digitalWrite(DIR2, HIGH);
    analogWrite(PWM1, value);   //PWM Speed Control
    analogWrite(PWM2, value);   //PWM Speed Control
    delay(30);
  }
}