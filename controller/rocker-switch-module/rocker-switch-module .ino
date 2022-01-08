#define switchPin 2

int ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop() {
  int touchValue = digitalRead(switchPin);
  if (touchValue == HIGH) {
    Serial.println("switched");
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  delay(350);
}