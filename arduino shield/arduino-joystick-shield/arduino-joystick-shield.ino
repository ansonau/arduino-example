#define BUTTON_UP 2
#define BUTTON_RIGHT 3
#define BUTTON_DOWN 4
#define BUTTON_LEFT 5
#define BUTTON_E 6
#define BUTTON_F 7
#define DELAY 500

void setup() {

  Serial.begin(9600);

  // to enable pull up resistors first write pin mode
  // and then make that pin HIGH
  pinMode(BUTTON_UP, INPUT);
  digitalWrite(BUTTON_UP, HIGH);

  pinMode(BUTTON_RIGHT, INPUT);
  digitalWrite(BUTTON_RIGHT, HIGH);

  pinMode(BUTTON_DOWN, INPUT);
  digitalWrite(BUTTON_DOWN, HIGH);

  pinMode(BUTTON_LEFT, INPUT);
  digitalWrite(BUTTON_LEFT, HIGH);

  pinMode(BUTTON_E, INPUT);
  digitalWrite(BUTTON_E, HIGH);

  pinMode(BUTTON_F, INPUT);
  digitalWrite(BUTTON_F, HIGH);
}

void loop() {

  if(digitalRead(BUTTON_UP) == LOW) {
    Serial.println(“Button A is pressed”);
    delay(DELAY);
  }

  else if(digitalRead(BUTTON_RIGHT) == LOW) {
    Serial.println(“Button B is pressed”);
    delay(DELAY);
  }

  else if(digitalRead(BUTTON_DOWN) == LOW) {
    Serial.println(“Button C is pressed”);
    delay(DELAY);
  }

  else if(digitalRead(BUTTON_LEFT) == LOW) {
    Serial.println(“Button D is pressed”);
    delay(DELAY);
  }

  else if(digitalRead(BUTTON_E) == LOW) {
    Serial.println(“Button E is pressed”);
    delay(DELAY);
  }

  else if(digitalRead(BUTTON_F) == LOW) {
    Serial.println(“Button F is pressed”);
    delay(DELAY);
  }

}
