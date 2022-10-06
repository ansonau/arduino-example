#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
 
//Arduino Uno/Nano Pins:
//GND = GND
//VCC = 5v
//DC = 8
//RES = 9
//CS = 10
//SDA = 11
//SCL = 13
 
#define TFT_CS     10
#define TFT_RST    9
#define TFT_DC     8
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
 
void setup(void)
{ 
  tft.initR(INITR_BLACKTAB); //Initializes ST7735.
  //Use GREENTAB rather than BLACKTAB if static is seen at the edges of the illuminated display.
  //Available Colours: BLACK, BLUE (Sometimes Displays Red), RED (Sometimes Displays Blue), GREEN, CYAN (Displays Yellow), MAGENTA, YELLOW (Displays Cyan) and WHITE.
 
  tft.fillScreen(ST7735_BLACK);
  tft.setCursor(5, 10);
  tft.setTextColor(ST7735_RED); 
  tft.setTextSize(1);
  tft.println("Hello");
  tft.setCursor(5, 20);
  tft.setTextColor(ST7735_GREEN);
  tft.setTextSize(2);
  tft.println("BotSheet");
  tft.setCursor(5, 38);
  tft.setTextColor(ST7735_BLUE);
  tft.setTextSize(3);
  tft.print("www.botsheet.com");
 
  tft.drawLine(0, 140, 127, 140, ST7735_WHITE);
  tft.drawCircle(40, 140, 5, ST7735_CYAN);
  tft.fillTriangle(64, 135, 59, 145, 69, 145, ST7735_MAGENTA);
  tft.drawTriangle(64, 135, 59, 145, 69, 145, ST7735_WHITE);
  tft.fillCircle(88, 140, 5, ST7735_YELLOW);
}
 
void loop() 
{
  
}