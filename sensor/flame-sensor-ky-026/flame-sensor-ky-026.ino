const int buzzerPin = 12;
const int flamePin = 2;
int Flame = HIGH;

void setup() 
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(flamePin, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  Flame = digitalRead(flamePin);
  if (Flame== LOW)
  {
    Serial.println("Fire!!!");
    digitalWrite(buzzerPin, HIGH);
  }
  else
  {
    Serial.println("No worries");
    digitalWrite(buzzerPin, LOW);
  }
}