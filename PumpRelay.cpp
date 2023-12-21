  #include "Arduino.h"
  #include "Log.h"
  #include "PumpRelay.h"

  void PumpRelay::setup() {
    Log::out("pump relay controlled w/ pin %d", PUMP_RELAY_PIN);
    pinMode(PUMP_RELAY_PIN, OUTPUT);
  }

  void PumpRelay::on() {
    digitalWrite(PUMP_RELAY_PIN, HIGH);
  }
  
  void PumpRelay::off() {
    digitalWrite(PUMP_RELAY_PIN, LOW);
  }