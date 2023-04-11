#include "createObjetcs.h"
#include <Preferences.h>

Preferences preferences;

void calibrateSensors()
{
    com.writeln("Calibrando...");

    robot.move(-50, 50);

    long timeout = millis() + 2000;
    while (millis() < timeout)
    {
        turnLeftSensor.calibrate();
        leftSensor.calibrate();
        rightSensor.calibrate();
        turnRightSensor.calibrate();
    }
    robot.stop();
    delay(500);

    robot.move(50, -50);

    timeout = millis() + 2000;
    while (millis() < timeout)
    {
        turnLeftSensor.calibrate();
        leftSensor.calibrate();
        rightSensor.calibrate();
        turnRightSensor.calibrate();
    }
    robot.stop();
    delay(500);
    com.writeln("Calibrado!");
}

void showCalibration()
{
    com.writeln("Calibração:");
    com.write("turnLeftSensor: ");
    com.write(String(turnLeftSensor.calibration.min));
    com.write(" ~ ");
    com.writeln(String(turnLeftSensor.calibration.max));

    com.write("leftSensor: ");
    com.write(String(leftSensor.calibration.min));
    com.write(" ~ ");
    com.writeln(String(leftSensor.calibration.max));

    com.write("rightSensor: ");
    com.write(String(rightSensor.calibration.min));
    com.write(" ~ ");
    com.writeln(String(rightSensor.calibration.max));

    com.write("turnRightSensor: ");
    com.write(String(turnRightSensor.calibration.min));
    com.write(" ~ ");
    com.writeln(String(turnRightSensor.calibration.max));
}

void saveCalibration()
{
    preferences.begin("bololo", false);
    preferences.clear();

    preferences.putShort("turnLeftSensorMin", turnLeftSensor.calibration.min);
    preferences.putShort("turnLeftSensorMax", turnLeftSensor.calibration.max);

    preferences.putShort("leftSensorMin", leftSensor.calibration.min);
    preferences.putShort("leftSensorMax", leftSensor.calibration.max);

    preferences.putShort("rightSensorMin", rightSensor.calibration.min);
    preferences.putShort("rightSensorMax", rightSensor.calibration.max);

    preferences.putShort("turnRightSensorMin", turnRightSensor.calibration.min);
    preferences.putShort("turnRightSensorMax", turnRightSensor.calibration.max);

    preferences.end();
}

void loadCalibration()
{
    preferences.begin("bololo", false);

    turnLeftSensor.calibration.min = preferences.getShort("turnLeftSensorMin", 0);
    turnLeftSensor.calibration.max = preferences.getShort("turnLeftSensorMax", 4095);

    leftSensor.calibration.min = preferences.getShort("leftSensorMin", 0);
    leftSensor.calibration.max = preferences.getShort("leftSensorMax", 4095);

    rightSensor.calibration.min = preferences.getShort("rightSensorMin", 0);
    rightSensor.calibration.max = preferences.getShort("rightSensorMax", 4095);

    turnRightSensor.calibration.min = preferences.getShort("turnRightSensorMin", 0);
    turnRightSensor.calibration.max = preferences.getShort("turnRightSensorMax", 4095);

    preferences.end();
}
