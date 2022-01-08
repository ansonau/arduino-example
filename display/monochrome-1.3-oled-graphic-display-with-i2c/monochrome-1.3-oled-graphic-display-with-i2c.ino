#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SH1106 display(OLED_RESET);

void setup()
{
  display.begin(SH1106_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C
  display.clearDisplay(); // Clear the buffer

  Serial.begin(9600);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.drawRect(0, 15, 60, 40, WHITE);
  display.println("Hello World");
  display.display();
  delay(1000);
  display.clearDisplay();
}


void loop()
{

}