#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10,11); /* Pin 10 -->  TX, Pin 11 -->  RX */

char bluetoothData;

int led = 13;
bool ledState;

void setup()
{
    Serial.begin(9600);

    BTSerial.begin(9600);

  pinMode(led, OUTPUT);
    Serial.println("Bluetooth is ready");

}


void loop()
{
    if (BTSerial.available()) {
      bluetoothData = BTSerial.read();
      Serial.print(bluetoothData);
      if (bluetoothData == '1') {
        digitalWrite(led, HIGH);
        Serial.println("LED is On");

      }
      if (bluetoothData == '2') {
        digitalWrite(led, LOW);
        Serial.println("LED is Off");

      }

    }
    delay(100);

}