#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <stdint.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// 16x16 Battery with Tick (Horizontal format)
const unsigned char battery_tick_16x16[] PROGMEM = {

  // Page 0
  0x00,0x00,0xFC,0xFE,0x06,0x03,0x03,0x63,
  0x73,0x3B,0x1F,0x0F,0x03,0x06,0xFE,0xFC,

  // Page 1
  0x00,0x00,0x3F,0x7F,0x60,0xC0,0xC0,0xCC,
  0xDC,0xF8,0xF0,0xE0,0xC0,0x60,0x7F,0x3F
};

void setup() {

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while(true); // Stop if display not found
  }

  display.clearDisplay();

  // Draw bitmap at x=56, y=24
  display.drawBitmap(56, 24, battery_tick_16x16, 16, 16, WHITE);

  display.display();
}

void loop() {
}