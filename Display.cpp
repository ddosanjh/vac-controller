#include "Display.h"
#include "Arduino.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4

Adafruit_SSD1306 display(OLED_RESET);

void Display::setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void Display::refresh(int currentPressure, Input::Threshold threshold, bool isOn) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("PRESSURE: " + String(currentPressure));
  display.println("CUT ON:   " + String(threshold.cutOn));
  display.println("CUT OFF:  " + String(threshold.cutOff));
  display.println("VAC:      " + String(isOn? "ON" : "OFF"));
  display.display();
}
