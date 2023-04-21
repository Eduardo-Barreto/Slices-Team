#include <Preferences.h>

Preferences preferences;

void showCalibration()
{
    com.writeln("Calibração:");
    com.write("tLeftSensor: ");
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

    com.write("tRightSensor: ");
    com.write(String(turnRightSensor.calibration.min));
    com.write(" ~ ");
    com.write(String(turnRightSensor.calibration.max));

    com.writeln("----------------");
}

void saveCalibration()
{
    preferences.begin("bololo", false);

    preferences.putShort("tLeftSensorMin", turnLeftSensor.calibration.min);
    preferences.putShort("tLeftSensorMax", turnLeftSensor.calibration.max);

    preferences.putShort("leftSensorMin", leftSensor.calibration.min);
    preferences.putShort("leftSensorMax", leftSensor.calibration.max);

    preferences.putShort("rightSensorMin", rightSensor.calibration.min);
    preferences.putShort("rightSensorMax", rightSensor.calibration.max);

    preferences.putShort("tRightSensorMin", turnRightSensor.calibration.min);
    preferences.putShort("tRightSensorMax", turnRightSensor.calibration.max);

    preferences.end();
}

void loadCalibration()
{
    preferences.begin("bololo", false);

    turnLeftSensor.calibration.min = preferences.getShort("tLeftSensorMin", 0);
    turnLeftSensor.calibration.max = preferences.getShort("tLeftSensorMax", 4095);

    leftSensor.calibration.min = preferences.getShort("leftSensorMin", 0);
    leftSensor.calibration.max = preferences.getShort("leftSensorMax", 4095);

    rightSensor.calibration.min = preferences.getShort("rightSensorMin", 0);
    rightSensor.calibration.max = preferences.getShort("rightSensorMax", 4095);

    turnRightSensor.calibration.min = preferences.getShort("tRightSensorMin", 0);
    turnRightSensor.calibration.max = preferences.getShort("tRightSensorMax", 4095);

    preferences.end();
}

void calibrateSensors()
{
    robot.on();

    com.writeln("Calibrando...");

    long timeout = millis() + 2500;
    while (millis() < timeout)
    {
        robot.move(-50, 50);
        turnLeftSensor.calibrate();
        leftSensor.calibrate();
        rightSensor.calibrate();
        turnRightSensor.calibrate();
    }
    robot.stop();
    delay(500);

    timeout = millis() + 2500;
    while (millis() < timeout)
    {
        robot.move(50, -50);
        turnLeftSensor.calibrate();
        leftSensor.calibrate();
        rightSensor.calibrate();
        turnRightSensor.calibrate();
    }
    robot.stop();
    delay(500);
    com.writeln("Calibrado!");
    saveCalibration();
}
