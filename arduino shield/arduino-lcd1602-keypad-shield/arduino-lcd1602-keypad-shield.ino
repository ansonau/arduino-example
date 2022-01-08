#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int lcdButton = A0;

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
}


void loop()
{
    lcd.setCursor(0, 0);
    lcd.print("Hello World!");
    lcdButton = analogRead(A0);
    if (lcdButton >= 500 && lcdButton <= 750) {
      lcd.setCursor(5, 1);
      lcd.print("Select");

    } else if (lcdButton >= 50 && lcdButton <= 150) {
      lcd.setCursor(5, 1);
      lcd.print("Up");
    } else if (lcdButton >= 150 && lcdButton <= 300) {
      lcd.setCursor(5, 1);
      lcd.print("Down");
    } else if (lcdButton >= 300 && lcdButton <= 500) {
      lcd.setCursor(5, 1);
      lcd.print("Left");
    } else if (lcdButton >= 0 && lcdButton <= 50) {
      lcd.setCursor(5, 1);
      lcd.print("Right");
    }
}