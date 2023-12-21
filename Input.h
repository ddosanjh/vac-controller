#ifndef Input_h
#define Input_h

/*

  Pot wired like so, looking down at dial,
  to emit 0 to 1024 as dial turned clockwise.

              ________________

              [GND]  [S]  [5V] 

                  (dial)
              ________________

*/

#include "Arduino.h"

const int CUT_ON_PIN = A0;
const int CUT_OFF_PIN = A1;
const int RANGE_MIN = 30;
const int RANGE_MAX = 90;

namespace Input {

  struct Threshold {
    int cutOn, cutOff;
  };

  Input::Threshold senseUserCutOnOff();
}

#endif