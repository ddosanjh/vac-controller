#include "Input.h"
#include "Arduino.h"
#include "Log.h"

Input::Threshold Input::senseUserCutOnOff() {
  Input::Threshold t;
  t.cutOn = map(analogRead(CUT_ON_PIN), 0, 1023, RANGE_MIN, RANGE_MAX + 1);
  t.cutOff = map(analogRead(CUT_OFF_PIN), 0, 1023, RANGE_MIN, RANGE_MAX + 1);
  return t;
}

