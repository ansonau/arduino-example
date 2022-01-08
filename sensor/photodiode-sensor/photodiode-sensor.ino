int sensorPin = A0;
int sensorValue = 0;

void setup(void) {
   Serial.begin(9600);
   pinMode(sensorPin, INPUT); 
}
 
void loop(void) {
   sensorValue = analogRead(sensorPin);
   Serial.println(sensorValue);
}