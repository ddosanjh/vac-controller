
#define VALVE_TOGGLE_STEPS 4600
#define STEPS_PER_REV 2038         // specific to 28BYJ-48
#define STEPPER_SPEED 15
#define STEPPER_IN1_PIN 8
#define STEPPER_IN2_PIN 9
#define STEPPER_IN3_PIN 10
#define STEPPER_IN4_PIN 11

namespace Valve {
    void setup();
    void open();
    void close();
};
