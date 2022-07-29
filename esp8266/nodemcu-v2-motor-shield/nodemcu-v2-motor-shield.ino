#define pwmMotorA D1
#define pwmMotorB D2
#define dirMotorA D3
#define dirMotorB D4

int motorSpeed = 500;

void setup() {
 Serial.begin(115200);
 Serial.println();
 pinMode(pwmMotorA , OUTPUT);
 pinMode(pwmMotorB, OUTPUT);
 pinMode(dirMotorA, OUTPUT);
 pinMode(dirMotorB, OUTPUT);
 Serial.println("Motor SHield 12E Initialized");
 delay(1000);
}

void loop() {
  Serial.println("Forward");
  digitalWrite(pwmMotorA, motorSpeed);
  digitalWrite(dirMotorA, LOW);
  digitalWrite(pwmMotorB, motorSpeed);
  digitalWrite(dirMotorB, HIGH);
  delay(1500);
  
  Serial.println("Backward");
  digitalWrite(pwmMotorA, motorSpeed); 
  digitalWrite(dirMotorA, HIGH);
  digitalWrite(pwmMotorB, motorSpeed);
  digitalWrite(dirMotorB, LOW);
  delay(1500);
  
  Serial.println("Left");
  digitalWrite(pwmMotorA, motorSpeed);
  digitalWrite(dirMotorA, HIGH);
  digitalWrite(pwmMotorB, motorSpeed);
  digitalWrite(dirMotorB, HIGH);
  delay(1500);
  
  Serial.println("Right");
  digitalWrite(pwmMotorA, motorSpeed);
  digitalWrite(dirMotorA, LOW);
  digitalWrite(pwmMotorB, motorSpeed);
  digitalWrite(dirMotorB, LOW);
  delay(1500);
}