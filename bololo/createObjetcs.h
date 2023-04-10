#include "motor.h"
#include "sensor.h"

motor leftMotor(
    4,  // standByPin
    2,  // IN1Pin
    15, // IN2Pin
    32, // pwmPin
    1   // pwmChannel
);

motor rightMotor(
    4,  // standByPin
    16, // IN1Pin
    25, // IN2Pin
    33, // pwmPin
    0   // pwmChannel
);

sensor turnLeftSensor(13);
sensor leftSensor(34);
sensor rightSensor(35);
sensor turnRightSensor(27);
