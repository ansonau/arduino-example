#include <Adafruit_GFX.h>      // Adafruit graphics library
#include <Adafruit_ILI9481.h>  // Adafruit ILI9481 library

#define TFT_CS   10
#define TFT_RST  9
#define TFT_DC   8

// Create an instance of the library for the display
Adafruit_ILI9481 tft = Adafruit_ILI9481(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  // Initialize the display
  tft.begin();
  
  // Clear the screen to black
  tft.fillScreen(ILI9481_BLACK);
  
  // Draw some text
  tft.setCursor(0, 0);
  tft.setTextColor(ILI9481_WHITE);
  tft.setTextSize(2);
  tft.println("Hello, world!");
}

void loop() {
  // Do nothing here
}
