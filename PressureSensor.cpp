#include "PressureSensor.h"
#include "Arduino.h"



/**
 * Return current pressure in -kPA.
 * Calculated as a linear approximation between observed votages for various
 * pressure readings of an analog guage attached to same vessel.
 */
int PressureSensor::senseCurrentPressure() {

  int v = analogRead(PRESSURE_PIN);

  // Observations (analog reading, output voltage)
  const int N_OBS = 10;
  int obs[N_OBS][2] = {
    {0, 925},
    {10, 813},
    {20, 726},
    {30, 641},
    {40, 553},
    {50, 474},
    {60, 398},
    {70, 320},
    {80, 239},  // <-- highest vacuum observed 
    {90, 0}     // <-- last data point fabricated to catch outlier readings
  };

  if (v >= 900) {
    return 0;
  }

  for (int i = 0, j = 1; j < N_OBS; i++, j++) {

    // Check if voltage falls within observations (i, j)
    if(v > obs[j][1]) {

      // Calculate fractional position between i and j
      float interval_p_delta = (float)(obs[j][0] - obs[i][0]);
      float interval_v_delta = (float)(obs[i][1] - obs[j][1]);
      float r = (float)(v - obs[j][1]) / (float)(interval_v_delta);

      return obs[j][0] - (int)(r * interval_p_delta);
    }

  }

  return -1;
}