#include "createObjetcs.h"

void setup()
{
}

void loop()
{
    if (leftSensor.isBlack())
    {
        leftMotor.run(100);
        rightMotor.run(0);
    }
    else if (rightSensor.isBlack())
    {
        rightMotor.run(100);
        leftMotor.run(0);
    }
    else
    {
        leftMotor.run(30);
        rightMotor.run(30);
    }
}
