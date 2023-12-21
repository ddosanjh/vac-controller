#include "Log.h"
#include "Valve.h"
#include "PumpRelay.h"
#include "Input.h"
#include "Display.h"
#include "PressureSensor.h"

bool vacIsOn = false;

void setup() {
  Log::setup();
  PumpRelay::setup();
  Valve::setup();
  Display::setup();
}


void loop() {

  int currentPressure = PressureSensor::senseCurrentPressure();

  Input::Threshold threshold = Input::senseUserCutOnOff();

  if (vacIsOn) {
    if (currentPressure >= threshold.cutOff) {
      
      // CUT OFF
      Valve::close();
      PumpRelay::off();
      vacIsOn = false;
    }
  } else {
    if (currentPressure <= threshold.cutOn) {
      
      // CUT ON
      PumpRelay::on();
      Valve::open();
      vacIsOn = true;
    }
  }

  Display::refresh(currentPressure, threshold, vacIsOn);

}

