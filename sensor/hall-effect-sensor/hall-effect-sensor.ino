int hallEffectSensor = 2;
int hallEffectVal;

int led = 13;
bool ledState;

void setup()
{
  pinMode(hallEffectSensor, INPUT);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{
    hallEffectVal = digitalRead(hallEffectSensor);
    if (hallEffectVal == HIGH) {
      digitalWrite(led, LOW);
    } else {
      digitalWrite(led, HIGH);
    }
}
