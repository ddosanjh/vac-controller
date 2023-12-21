#include "Valve.h"
#include "Log.h"
#include <Stepper.h>

Stepper valveStepper = Stepper(STEPS_PER_REV,
  STEPPER_IN1_PIN,
  STEPPER_IN3_PIN,
  STEPPER_IN2_PIN,
  STEPPER_IN4_PIN
);

void Valve::setup() {
  Log::out(
    "initializing stepper w/ speed %d on pins %d, %d, %d, %d",
    STEPPER_SPEED,
    STEPPER_IN1_PIN,
    STEPPER_IN3_PIN,
    STEPPER_IN2_PIN,
    STEPPER_IN4_PIN
    );

    valveStepper.setSpeed(STEPPER_SPEED);
}

void Valve::open() {
  valveStepper.step(-VALVE_TOGGLE_STEPS);
}

void Valve::close() {
  valveStepper.step(VALVE_TOGGLE_STEPS);
}