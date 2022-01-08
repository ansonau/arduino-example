#define touchPin 2

int ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(touchPin, INPUT);
}

void loop() {
  int touchValue = digitalRead(touchPin);
  if (touchValue == HIGH) {
    Serial.println("TOUCHED");
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  delay(350);
}