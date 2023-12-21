/*

XGZP6847A CHIP LAYOUT AS FOLLOWS


---------------------------------
  [4 - VDD] [5 - VOUT] [6 - GND]

[C2]                         
                          [PROD NO]
[C1]

  [1 - N/C] [2 - VDD] [3 - GND]
-----------------------------------

Vout ranges from ~ 900 at astmospheric pressure
to ~ 160 @ -90kPA

*/

#include "Arduino.h"

const int PRESSURE_PIN = A3;

namespace PressureSensor {
  int senseCurrentPressure();
}